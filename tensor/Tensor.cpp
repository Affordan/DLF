#include "Tensor.h"

std::mt19937* Tensor::gen = new std::mt19937(0);
std::uniform_real_distribution<float>* Tensor::fdist = new std::uniform_real_distribution<float>(0.0, 1.0);

void Tensor::init()
{
	for (int i = 0; i < size_; i++)
	{
		data_[i] = (*fdist)(*gen);
	}
}

Tensor::Tensor():size_(0),shape_({}),stride_({}),data_(nullptr)
{

}

Tensor::Tensor(std::vector<int> shape):shape_(shape), stride_ (shape2stride(shape))
{
	size_ = this->size();
	data_ = std::shared_ptr<float[]>(new float[size_]);
	init();
}



Tensor::Tensor(int index, const Tensor& t)
{
	//extract from the t's 1st dimension
	size_ = t.stride_[0];
	shape_.resize(t.shape_.size() - 1);
	//data_ = std::shared_ptr<float[]>(new float[size_]);
	data_ = t.data_;
	for (int i = 0; i < size_; i++)
	{
		data_[i] = t.data_[i + index*t.stride_[0]];
	}

}

Tensor::Tensor(std::vector<int> shape, std::vector<float> data):shape_(shape)
{
	stride_ = shape2stride(shape);
	size_ = size();
	data_ = std::shared_ptr<float[]>(new float[size_]);
	for (int i = 0; i < data.size(); i++)data_[i] = data[i];
}

Tensor::Tensor(std::vector<int> shape, std::shared_ptr<float[]> data):shape_(shape)
{
	size_ = size();
	data_ = data;
}

Tensor::Tensor(const Tensor& other):size_(other.size_),shape_(other.shape_),stride_(other.stride_)
{
	this->data_ = other.data_;
}

Tensor::~Tensor()
{
}

//hard work
Tensor Tensor::split(std::vector<int> start, std::vector<int> end)
{
	std::vector<int> newShape;
	assert(start.size() == end.size());

	for (int i = 0; i < start.size(); i++)
	{
		assert(start[i] < end[i]);
		newShape.push_back(end[i] - start[i]);
	}
	
	Tensor res(newShape);

	//iterate every elements in res
	for (int i = 0; i < res.size(); i++)
	{
		//convert id to multi-index in res
		std::vector<int> indexs = id2index(i, newShape);

		//calu correspond index in original tensor
		for (int j = 0; j < start.size(); j++)
		{
			indexs[j] += start[j];
		}

		int target_index = index2id(indexs, this->shape_);

		res.data_[i] = this->data_[target_index];
	}
	return res;
}

std::vector<int> Tensor::shape2stride(std::vector<int> shape)
{
	std::vector<int> stride(shape.size(), 1);

	//reverse calculate
	if(shape.size()>1)
	{
		std::partial_sum(shape.rbegin(), shape.rend() - 1, stride.rbegin() + 1, std::multiplies<int>());
	}

	return stride;
}

std::vector<int> Tensor::id2index(int id, std::vector<int> shape)
{
	std::vector<int> index(shape.size());
	int tmp = id;
	for (int i=index.size()-1;i>=0;i--)
	{
		index[i] = (tmp % shape[i]);
		tmp /= shape[i];
		
	}
	return index;

}

int Tensor::index2id(std::vector<int> index, std::vector<int> shape)
{
	int id = 0;
	int stride = 1;
	for (int i = shape.size() - 1; i >= 0; i--)
	{
		id += index[i]*stride;
		stride *= shape[i];
	}
	return id;
}

Tensor& Tensor::operator=(const Tensor& other)
{
	if (this != &other)
	{
		shape_ = other.shape_;
		stride_ = other.stride_;
		size_ = other.size_;
		data_ = other.data_;
	}

	return *this;
}

Tensor Tensor::deepcopy() const
{
	auto new_data = std::shared_ptr<float[]>(new float[size_]);
	std::copy(data_.get(), data_.get() + size_, new_data.get());
	return Tensor(shape_, new_data);
}

float* Tensor::get_data_ptr()
{
	return data_.get();		//return shared_ptr head pointer.
}

int* Tensor::get_shape()
{
	return shape_.data();

}

int Tensor::get_dims()
{
	return shape_.size();

}

int Tensor::size()
{
	int size = 1;
	size = std::accumulate(shape_.begin(), shape_.end(), 1, std::multiplies<int>());
	return size;
}

const Tensor Tensor::operator[](int index) const
{
	//simple demo to return 1D tensor 
	//we encourage you to implement this function

	if (index < 0 || index >= shape_[0])
	{
		std::cout << "error" << std::endl;
		return Tensor();	//an empty tensor
	}

	return Tensor(index, *this);
}

std::ostream& operator<<(std::ostream& os, const Tensor& other)
{
	// stride_[,..., last3,size()-3,size()-2,size()-1]
	//										1
	int rowSize = other.shape_[other.shape_.size() - 2];
	int colSize = other.shape_[other.shape_.size() - 1];

	int matrixSize = rowSize * colSize;
	//os << matrixSize << std::endl;
	//os << other.size_ << std::endl;
	int numMatrices = other.size_ / matrixSize;

	for (int i = 0; i < numMatrices; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			os << other.data_[i * numMatrices + j];
			if ((j + 1) % colSize == 0)
			{
				os << std::endl;
			}
			else
			{
				os << " ";
			}
		}

		if (i != numMatrices - 1)
			os << std::endl;
	}
	return os;
}
