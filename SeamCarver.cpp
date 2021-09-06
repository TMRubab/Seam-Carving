#include "SeamCarver.h"

//const double inf = std::numeric_limits<double>::infinity();
template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::assign_energy_to_pixel(long long row, long long col) {
	if (infty_mode && (energy[row][col] == large || energy[row][col] == (0 - large))) return;
	double vert_en;
	double hor_en;
	//preparing an array of 0 in case this pixel is located in a side or corner
	pixel_eachChannel_type* t = new pixel_eachChannel_type[num_channels];
	for (int i = 0; i < num_channels; ++i) t[i] = (pixel_eachChannel_type)0;
	//preparing vectors to hold the neighbour pixel values
	vector<pixel_eachChannel_type> up;
	vector<pixel_eachChannel_type> down;
	vector<pixel_eachChannel_type> left;
	vector<pixel_eachChannel_type> right;
	//getting the neihbour pixels and copying them into corresponding vectors
	if (row - 1 >= 0) {
		pixel_type up1(original.at<pixel_type>(index[row - 1][col] / original.cols, index[row - 1][col] % original.cols));
		copy_Vec_to_vec(up1, up, num_channels);
	}
	else {
		pixel_type up1(t);
		copy_Vec_to_vec(up1, up, num_channels);
	}
	if (row + 1 < rows) {
		pixel_type down1(original.at<pixel_type>(index[row + 1][col] / original.cols, index[row + 1][col] % original.cols));
		copy_Vec_to_vec(down1, down, num_channels);
	}
	else {
		pixel_type down1(t);
		copy_Vec_to_vec(down1, down, num_channels);
	}
	if (col - 1 >= 0) {
		pixel_type left1(original.at<pixel_type>(index[row][col - 1] / original.cols, index[row][col - 1] % original.cols));
		copy_Vec_to_vec(left1, left, num_channels);
	}
	else {
		pixel_type left1(t);
		copy_Vec_to_vec(left1, left, num_channels);
	}
	if (col + 1 < cols) {
		pixel_type right1(original.at<pixel_type>(index[row][col + 1] / original.cols, index[row][col + 1] % original.cols));
		copy_Vec_to_vec(right1, right, num_channels);
	}
	else {
		pixel_type right1(t);
		copy_Vec_to_vec(right1, right, num_channels);
	}
	//calculating the energy
	vert_en = distance<pixel_eachChannel_type>(up, down);
	hor_en = distance<pixel_eachChannel_type>(left, right);
	double tot_en2 = vert_en * vert_en + hor_en * hor_en;
	double tot_en = sqrt(tot_en2);
	energy[row][col] = tot_en;
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::assign_infty_cell(long long row, long long col, bool plus) {
	infty_mode = true;
	energy[row][col] = (plus) ? large : (0 - large);
}

template <typename pixel_type, typename pixel_eachChannel_type>
SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::SeamCarver(string filename, ImreadModes x) {
	//cout << "constructing\n";
	original = imread(filename, x);
	rows = (long long)original.rows;
	cols = (long long)original.cols;
	type = original.type();
	num_channels = original.channels();
	index = new long long* [rows];
	for (long long i = 0; i < rows; ++i) {
		index[i] = new long long[cols];
		for (long long j = 0; j < cols; ++j) {
			index[i][j] = i * cols + j;
		}
	}
	energy = new double* [rows];
	for (long long i = 0; i < rows; ++i) {
		energy[i] = new double[cols];
		for (long long j = 0; j < cols; ++j) assign_energy_to_pixel(i, j);
	}
	detectFaces(original);
}

template <typename pixel_type, typename pixel_eachChannel_type>
SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::SeamCarver(const Mat& mat) {
	original = mat;
	rows = (long long)original.rows;
	cols = (long long)original.cols;
	type = original.type();
	num_channels = original.channels();
	index = new long long* [rows];
	for (long long i = 0; i < rows; ++i) {
		index[i] = new long long[cols];
		for (long long j = 0; j < cols; ++j) {
			index[i][j] = i * cols + j;
		}
	}
	energy = new double* [rows];
	for (long long i = 0; i < rows; ++i) {
		energy[i] = new double[cols];
		for (long long j = 0; j < cols; ++j) assign_energy_to_pixel(i, j);
	}
	detectFaces(original);
}

template <typename pixel_type, typename pixel_eachChannel_type>
long long* SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::vertical_path() {
	long long* cols_in_path = new long long[rows];
	MinHeap heap(rows * cols);
	for (long long j = 0; j < cols; ++j) {
		heap.insert(0, j, energy[0][j]);
	}
	for (long long i = 1; i < rows; ++i) {
		for (long long j = 0; j < cols; ++j) {
			heap.insert(i, j, inf);
		}
	}
	long long last_col = 0;
	while (!heap.is_empty()) {
		long long row, col = 0;
		double key;
		heap.extract_min(row, col, key);
		if (row == rows - 1) { last_col = col;  break; }
		if (col - 1 >= 0) {
			if (!heap.is_extracted((row + 1) * cols + (col - 1))) {
				bool b = heap.decrease_key((row + 1) * cols + (col - 1), key + energy[row + 1][col - 1]);
				if (b) {
					heap.set_parent((row + 1) * cols + (col - 1), 1);
				}
			}
		}
		if (col + 1 <= cols - 1) {
			if (!heap.is_extracted((row + 1) * cols + (col + 1))) {
				bool b = heap.decrease_key((row + 1) * cols + (col + 1), key + energy[row + 1][col + 1]);
				if (b) {
					heap.set_parent((row + 1) * cols + (col + 1), (0 - 1));
				}
			}
		}
		if (!heap.is_extracted((row + 1) * cols + (col))) {
			bool b = heap.decrease_key((row + 1) * cols + (col), key + energy[row + 1][col]);
			if (b) {
				heap.set_parent((row + 1) * cols + (col), 0);
			}
		}
	}
	cols_in_path[rows - 1] = last_col;
	for (long long i = rows - 2; i >= 0; --i) {
		long long p = heap.get_parent((i + 1) * cols + cols_in_path[i + 1]);
		cols_in_path[i] = p + cols_in_path[i + 1];
	}
	return cols_in_path;
}

template <typename pixel_type, typename pixel_eachChannel_type>
long long* SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::horizontal_path() {
	long long* rows_in_path = new long long[cols];
	MinHeap heap(rows * cols);

	for (long long i = 0; i < rows; ++i) {
		for (long long j = 0; j < cols; ++j) {
			if (j >= 1) heap.insert(i, j, inf);
			else heap.insert(i, j, energy[i][j]);
		}
	}
	long long last_row = 0;
	while (!heap.is_empty()) {
		long long row, col = 0;
		double key;
		heap.extract_min(row, col, key);
		if (col == cols - 1) { last_row = row;  break; }
		if (row - 1 >= 0) {
			if (!heap.is_extracted((row - 1) * cols + (col + 1))) {
				bool b = heap.decrease_key((row - 1) * cols + (col + 1), key + energy[row - 1][col + 1]);
				if (b) {
					heap.set_parent((row - 1) * cols + (col + 1), 1);
				}
			}
		}
		if (row + 1 <= rows - 1) {
			if (!heap.is_extracted((row + 1) * cols + (col + 1))) {
				bool b = heap.decrease_key((row + 1) * cols + (col + 1), key + energy[row + 1][col + 1]);
				if (b) {
					heap.set_parent((row + 1) * cols + (col + 1), (0 - 1));
				}
			}
		}
		if (!heap.is_extracted((row)*cols + (col + 1))) {
			bool b = heap.decrease_key((row)*cols + (col + 1), key + energy[row][col + 1]);
			if (b) {
				heap.set_parent((row)*cols + (col + 1), 0);
			}
		}
	}
	rows_in_path[cols - 1] = last_row;
	for (long long j = cols - 2; j >= 0; --j) {
		long long p = heap.get_parent(rows_in_path[j + 1] * cols + (j + 1));
		rows_in_path[j] = p + rows_in_path[j + 1];
	}
	return rows_in_path;
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::remove_vertical_path(long long* to_be_removed) {
	for (long long i = 0; i < rows; ++i) {
		for (long long j = to_be_removed[i]; j < cols - 1; ++j) {
			energy[i][j] = energy[i][j + 1];
			index[i][j] = index[i][j + 1];
		}
	}
	--cols;
	for (long long i = 0; i < rows; ++i) {
		if (to_be_removed[i] - 1 >= 0) assign_energy_to_pixel(i, to_be_removed[i] - 1); //?????
		assign_energy_to_pixel(i, to_be_removed[i]); //?????
	}
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::remove_vertical_paths(long long num_cols) {
	long long* a_vertical_path;
	for (int i = 0; i < num_cols; ++i) {
		a_vertical_path = vertical_path();
		remove_vertical_path(a_vertical_path);
	}
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::remove_horizontal_path(long long* to_be_removed) {
	//cout << "here in remove_horizontal_path\n";
	for (long long j = 0; j < cols; ++j) {
		for (long long i = to_be_removed[j]; i < rows - 1; ++i) {
			energy[i][j] = energy[i + 1][j];
			index[i][j] = index[i + 1][j];
		}
	}
	--rows;
	for (long long j = 0; j < cols; ++j) {
		if (to_be_removed[j] - 1 >= 0) assign_energy_to_pixel(to_be_removed[j] - 1, j); //?????
		assign_energy_to_pixel(to_be_removed[j], j); //?????
	}
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::remove_horizontal_paths(long long num_rows) {
	//cout << "here in remove_horizontal_paths\n";
	long long* a_horizontal_path;
	for (int i = 0; i < num_rows; ++i) {
		a_horizontal_path = horizontal_path();
		remove_horizontal_path(a_horizontal_path);
	}
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::add_vertical_path(long long* to_be_added) {
	for (long long i = 0; i < rows; ++i) {
		double* temp_en = energy[i];
		energy[i] = new double[cols + 1];
		long long* temp_in = index[i];
		index[i] = new long long[cols + 1];
		for (long long j = 0; j < cols + 1; ++j) {
			if (j <= to_be_added[i]) energy[i][j] = temp_en[j];
			else energy[i][j] = temp_en[j - 1];
			if (j <= to_be_added[i]) index[i][j] = temp_in[j];
			else index[i][j] = temp_in[j - 1];
		}
		delete temp_in;
		delete temp_en;
	}
	++cols;
	for (long long i = 0; i < rows; ++i) {
		if (to_be_added[i] + 1 <= cols - 1) assign_infty_cell(i, to_be_added[i] + 1, true); //?????
		assign_infty_cell(i, to_be_added[i], true); //?????
		//if (to_be_added[i] - 1 >= 0) assign_energy_to_pixel(i, to_be_added[i] - 1); //?????
	}
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::add_vertical_paths(long long num_cols) {
	long long* a_vertical_path;
	for (int i = 0; i < num_cols; ++i) {
		a_vertical_path = vertical_path();
		add_vertical_path(a_vertical_path);
	}
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::rescale(double width_ratio, double height_ratio) {
	long long num_cols = cols - (long long)round(cols * width_ratio);
	bool c = (num_cols != 0);
	if (num_cols > 0) {
		remove_vertical_paths(num_cols);
		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				for (int k = 0; k < num_channels; ++k) original.at<pixel_type>(i, j)[k] = original.at<pixel_type>(index[i][j] / original.cols, index[i][j] % original.cols)[k];
			}
		}
		Rect rect(0, 0, original.cols - num_cols, original.rows);
		original = original(rect);
	}
	else if (num_cols < 0) {
		num_cols = 0 - num_cols;
		add_vertical_paths(num_cols);
		Mat temp(original);
		original = Mat(rows, cols, temp.type());
		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				for (int k = 0; k < num_channels; ++k) original.at<pixel_type>(i, j)[k] = temp.at<pixel_type>(index[i][j] / temp.cols, index[i][j] % temp.cols)[k];
			}
		}
	}
	if (c) {
		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				index[i][j] = i * cols + j;
			}
		}
		infty_mode = false;
		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) assign_energy_to_pixel(i, j);
		}
		detectFaces(original);
	}
	long long num_rows = rows - (long long)round(rows * height_ratio);
	c = (num_rows != 0);
	if (num_rows > 0) {
		remove_horizontal_paths(num_rows);
		for (long long j = 0; j < cols; ++j) {
			for (long long i = 0; i < rows; ++i) {
				for (int k = 0; k < num_channels; ++k) original.at<pixel_type>(i, j)[k] = original.at<pixel_type>(index[i][j] / original.cols, index[i][j] % original.cols)[k];
			}
		}
		Rect rect(0, 0, original.cols, original.rows - num_rows);
		original = original(rect);
	}
	else if (num_rows < 0) {
		num_rows = 0 - num_rows;
		cv::rotate(original, original, cv::ROTATE_90_COUNTERCLOCKWISE);
		SeamCarver<pixel_type, pixel_eachChannel_type> s(original);
		s.rescale(height_ratio, 1.0);
		for (long long i = 0; i < rows; ++i) {
			delete[] index[i];
			delete[] energy[i];
		}
		delete[] index;
		delete[] energy;
		Mat temp3(s.get_pic());
		cv::rotate(temp3, temp3, cv::ROTATE_90_CLOCKWISE);
		original = Mat(temp3);
		rows = (long long)original.rows;
		cols = (long long)original.cols;
		type = original.type();
		num_channels = original.channels();
		index = new long long* [rows];
		for (long long i = 0; i < rows; ++i) {
			index[i] = new long long[cols];
			for (long long j = 0; j < cols; ++j) {
				index[i][j] = i * cols + j;
			}
		}
		energy = new double* [rows];
		for (long long i = 0; i < rows; ++i) {
			energy[i] = new double[cols];
			for (long long j = 0; j < cols; ++j) assign_energy_to_pixel(i, j);
		}
	}
	if (c) {
		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				index[i][j] = i * cols + j;
			}
		}
		infty_mode = false;
		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) assign_energy_to_pixel(i, j);
		}
		detectFaces(original);
	}
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::remove_object(bool** location) {

	long long max_rows = 0;
	long long max_cols = 0;

	for (long long i = 0; i < rows; i++) {
		long long max_row_this = 0;
		for (long long j = 0; j < cols; j++) {
			if (location[i][j]) {
				for (long long k = j + 1; k < cols; k++) {
					if (location[i][k]) {

						for (long long t = j; t <= k; t++) {
							assign_infty_cell(i, t, false);
						}

						max_row_this += k - j + 1;
						j = k + 1;
						break;
					}
				}
			}
		}
		max_rows = max(max_rows, max_row_this);
	}

	for (long long i = 0; i < cols; i++) {
		long long max_col_this = 0;
		for (long long j = 0; j < rows; j++) {
			if (location[i][j]) {
				for (long long k = j + 1; k < rows; k++) {
					if (location[i][k]) {
						max_col_this += k - j + 1;
						j = k + 1;
						break;
					}
				}
			}
		}
		max_cols = max(max_cols, max_col_this);
	}

	if (max_rows > max_cols) {
		remove_horizontal_paths(max_cols);
	}

	else {
		remove_vertical_paths(max_rows);
	}
	for (long long i = 0; i < rows; ++i) {
		for (long long j = 0; j < cols; ++j) {
			index[i][j] = i * cols + j;
		}
	}
	infty_mode = false;
	for (long long i = 0; i < rows; ++i) {
		for (long long j = 0; j < cols; ++j) assign_energy_to_pixel(i, j);
	}
	detectFaces(original);
}

template <typename pixel_type, typename pixel_eachChannel_type>
void SeamCarver<typename pixel_type, typename pixel_eachChannel_type>::detectFaces(Mat& img)
{
	CascadeClassifier cascade;
	cascade.load("haarcascade_frontalface_default.xml");
	vector<Rect> faces;
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	cascade.detectMultiScale(gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
	for (size_t i = 0; i < faces.size(); i++)
	{
		Rect r = faces[i];
		for (long long p = r.x; p < r.x + r.width; p++) {
			for (long long q = r.y; q < r.y + r.height; q++) {
				assign_infty_cell(q, p, true);
			}
		}
	}
}