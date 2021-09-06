#ifndef SEAMCARVER_H_
#define SEAMCARVER_H_

#include "BinHeap.h"
#include <opencv2/objdetect/objdetect.hpp>
/*#include <opencv2/opencv.hpp>
using namespace cv;
#include <iostream>
using namespace std;
#include <typeinfo>
#include <math.h>
#include <vector>
#include <string>
#include <stdint.h>
#include <limits>*/

template <typename pixel_type, typename pixel_eachChannel_type>
class SeamCarver {
private:
	const double inf = std::numeric_limits<double>::infinity();;
	Mat original;
	double** energy;
	long long rows, cols;
	int type;
	int num_channels;
	long long** index;
	bool infty_mode;
	double large = 1024 * 6 * 255 * 255.0;

	//helper functions
	void copy_Vec_to_vec(const pixel_type v1, vector<pixel_eachChannel_type>& v2, int num_elements) {
		v2.clear();
		for (int i = 0; i < num_elements; ++i) {
			v2.emplace_back(v1[i]);
		}
	}

	template <typename T>
	static double distance(vector<T> a, vector<T> b) {
		int a_num_elements = a.size();
		int b_num_elements = b.size();
		if (a_num_elements != b_num_elements) throw "distance cannot be measured";
		double d2 = 0;
		for (int i = 0; i < a_num_elements; ++i) {
			d2 += (double)((double)b[i] - (double)a[i]) * ((double)b[i] - (double)a[i]);
		}
		double dis = sqrt((double)d2);
		return dis;
	}

	void assign_energy_to_pixel(long long row, long long col);
	//void assign_fake_infty(bool** location, bool plus);
	void assign_infty_cell(long long row, long long col, bool plus);

public:
	//constructors
	SeamCarver() = delete;
	SeamCarver(const SeamCarver& s) = delete;
	SeamCarver(string filename, ImreadModes x);
	SeamCarver(const Mat& mat);

	long long* vertical_path();

	long long* horizontal_path();

	void remove_vertical_path(long long* to_be_removed);

	void remove_vertical_paths(long long num_cols);

	void remove_horizontal_path(long long* to_be_removed);

	void remove_horizontal_paths(long long num_rows);

	void add_vertical_path(long long* to_be_added);

	void add_vertical_paths(long long num_cols);

	//void add_horizontal_path(long long* to_be_added);

	//void add_horizontal_paths(long long num_rows);

	void rescale(double width_ratio, double height_ratio);

	void remove_object(bool** location);

	void detectFaces(Mat& img);

	Mat get_pic() const {
		return original;
	}
};

#endif /* SEAMCARVER_H_ */
