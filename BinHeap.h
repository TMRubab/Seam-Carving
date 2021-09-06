#ifndef BINHEAP_H_
#define BINHEAP_H_

#include "BinHeap.h"
#include <opencv2/opencv.hpp>
using namespace cv;
#include <iostream>
using namespace std;
#include <typeinfo>
#include <math.h>
#include <vector>
#include <string>
#include <stdint.h>
#include <limits>


class MinHeap {
private:
	struct node {
		long long row;
		long long col;
		double key;
		int parent;
		bool n_is_extracted;
		long long index;
	};
	node** keep;
	node* heap;
	long long* heap_to_keep;
	long long size;
	long long num_element;
	long long num_element_keep;
	void swap_nodes(long long index1, long long index2);
	void adjust_down();
	void adjust_up(long long index);
	void heap_insert(long long row, long long col, double key);
public:
	MinHeap(long long size);
	void insert(long long row, long long col, double key);
	bool decrease_key(long long index, double key);
	void extract_min(long long& row, long long& col, double& key);
	void set_parent(long long index, int parent);
	//Accessors
	bool is_extracted(long long index) const {
		return keep[index]->n_is_extracted;
	}
	bool is_empty() const {
		return (num_element == 0);
	}
	int get_parent(long long index) const {
		if (index >= num_element_keep || index < 0) throw "no parent";
		return keep[index]->parent;
	}
	double get_key(long long index) const {
		return keep[index]->key;
	}
};

#endif /* BINHEAP_H_*/
