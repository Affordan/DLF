#pragma once
#ifndef  TENSOR_H
#define TENSOR_H

#include <iostream>
#include <vector>
#include <random>
#include <cassert>
#include <numeric>
#include <functional>
#include <memory>


class Tensor
{
protected:

	int size_;
	std::shared_ptr<float[]> data_;
	std::vector<int> shape_;
	std::vector<int> stride_;
	

	static std::mt19937* gen;
	static std::uniform_real_distribution<float>*fdist;

	void init();

public:

	//empty constructor
	Tensor();

	//regular constructor
	Tensor(std::vector<int>shape);

	Tensor(int index,const Tensor& t);	//slice from another tensor
	//antother tensor
	Tensor(std::vector<int> shape, std::vector<float> data);	
	Tensor(std::vector<int> shape, std::shared_ptr<float[]> data);
	Tensor(const Tensor& other);

	//Destructor
	~Tensor();

	//Assignment operator
	Tensor& operator=(const Tensor& other);

	Tensor deepcopy() const;

	float* get_data_ptr();
	int* get_shape();
	int get_dims();
	int size();

	//[]	operator
	const Tensor operator[](int index)const;

	//convert shape to size

	//convert size to shape

	//slicing
	Tensor split(std::vector<int> start, std::vector<int> end);

	// shape2stride
	static std::vector<int> shape2stride(std::vector<int> shape);
	
	//Convert a linear index to multi-dimensional index based on the given shape
	static std::vector<int> id2index(int id, std::vector<int> shape);

	//Convert a multi-dimensional index to a linear index based on the given multi-dimensional index and shape
	static int index2id(std::vector<int> index, std::vector<int> shape);



	friend std::ostream& operator<<(std::ostream& os, const Tensor& other);

};
 std::ostream& operator<<(std::ostream& os, const Tensor& other);



#endif // ! TENSOR_H


