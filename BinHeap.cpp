#include "BinHeap.h"

void MinHeap::swap_nodes(long long index1, long long index2) {
	//cout << "index1 " << index1 << " index2 " << index2 << endl;
	//cout << heap[index1].row << " " << heap[index2].row << endl;
	long long temp_row = heap[index1].row;
	long long temp_col = heap[index1].col;
	double temp_key = heap[index1].key;
	int temp_parent = heap[index1].parent;
	bool temp_is_extracted = heap[index1].n_is_extracted;
	//long long temp_index = heap[index1].index;
	heap[index1].row = heap[index2].row;
	heap[index1].col = heap[index2].col;
	heap[index1].key = heap[index2].key;
	heap[index1].parent = heap[index2].parent;
	heap[index1].n_is_extracted = heap[index2].n_is_extracted;
	//heap[index1].index = heap[index2].index;
	heap[index2].row = temp_row;
	heap[index2].col = temp_col;
	heap[index2].key = temp_key;
	heap[index2].parent = temp_parent;
	heap[index2].n_is_extracted = temp_is_extracted;
	//heap[index2].index = temp_index;
	long long& keep_index1 = heap_to_keep[index1];
	long long& keep_index2 = heap_to_keep[index2];
	node* temp = keep[keep_index1];
	keep[keep_index1] = keep[keep_index2]; //nooooooooooooooooooooooooooooooooooooooo
	keep[keep_index2] = temp;
	long long temp1 = keep_index1;
	keep_index1 = keep_index2;
	keep_index2 = temp1;

}
void MinHeap::adjust_down() {
	long long index = 0;
	while ((2 * index + 1 < num_element && heap[index].key > heap[2 * index + 1].key) || (2 * index + 2 < num_element && heap[index].key > heap[2 * index + 2].key)) {
		if (2 * index + 2 < num_element) {
			long long min_index = (heap[2 * index + 1].key < heap[2 * index + 2].key) ? (2 * index + 1) : (2 * index + 2);
			swap_nodes(index, min_index);
			index = min_index;
		}
		else {
			swap_nodes(index, 2 * index + 1);
			index = 2 * index + 1;
		}
	}
}
void MinHeap::adjust_up(long long index) {
	if (index == 0) return;
	while ((index + 1) / 2 - 1 >= 0 && heap[(index + 1) / 2 - 1].key > heap[index].key) {
		swap_nodes(index, (index + 1) / 2 - 1);
		index = (index + 1) / 2 - 1;
	}
}
void MinHeap::heap_insert(long long row, long long col, double key) {
	long long index = num_element;
	heap[index].row = row;
	heap[index].col = col;
	heap[index].key = key;
	heap[index].parent = -2;
	heap[index].n_is_extracted = false;
	heap[index].index = index;
	++num_element;
	adjust_up(index);
}

MinHeap::MinHeap(long long size) : keep(new node* [size]), heap(new node[size]), size(size), num_element(0), num_element_keep(0), heap_to_keep(new long long[size]) {}
void MinHeap::insert(long long row, long long col, double key) {
	long long index = num_element;
	if (num_element_keep == size) return;
	++num_element_keep;
	keep[num_element_keep - 1] = &heap[index];
	heap_to_keep[index] = num_element_keep - 1;
	heap_insert(row, col, key);
}
bool MinHeap::decrease_key(long long index, double key) {
	//cout << "index " << index << " key " << key << endl;
	if (is_extracted(index)) return false;
	if (keep[index]->key <= key) return false;
	keep[index]->key = key; //?
	adjust_up(keep[index]->index);
	return true;
}
void MinHeap::extract_min(long long& row, long long& col, double& key) {
	if (num_element_keep != size) return;
	row = heap[0].row;
	col = heap[0].col;
	key = heap[0].key;
	heap[0].n_is_extracted = true;
	swap_nodes(0, num_element - 1);
	//keep[heap_to_keep[num_element - 1]] = nullptr; // no need?
	--num_element;
	adjust_down();
}

void MinHeap::set_parent(long long index, int parent) {
	if (is_extracted(index)) return;
	keep[index]->parent = parent;
	//cout << index << endl;
}