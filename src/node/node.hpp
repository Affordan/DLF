#ifndef NODE
#define NODE
#include <xtensor/xarray.hpp>
#include "./datatype.h"
using namespace xt;

//template class or abstract class(all class that can't be instantiated directly)
//are suggested surrounded by "__"
template<typename T>
class __DATA_NODE__;

template<typename T>
class __CAL_NODE__;


template<typename T>
class __DATA_NODE__		
{
	//for debugging
public:
	__CAL_NODE__<T>* pre_node;
	std::vector<__CAL_NODE<T>*> back_node;
	xt::xarray<T> data;
	xt::xarray<T> grad;

	__DATA_NODE__();
	__DATA_NODE__(xt::xarray<T>&data);
	__DATA_NODE__(const xt::xarray<T>&data);	//Anonymous objects
	void SetPreNode(__CAL_NODE__<T>* pre_node);
	void AddBackNode(__CAL_NODE__<T>* back_node);

};

template<typename T>
class __CAL_NODE__
{

};

//__DATA_NODE__
template<typename T>
inline __DATA_NODE__<T>::__DATA_NODE__():pre_node(nullptr)
{
	this->data = DEFAULT_TENSOR_FLOAT32;
	this->grad = DEFAULT_TENSOR_FLOAT32;
}

template<typename T>
inline __DATA_NODE__<T>::__DATA_NODE__(xt::xarray<T>& data):pre_node(nullptr)
{
	this->data = data;
	this->grad = DEFAULT_TENSOR_FLOAT32;
}

template<typename T>
inline __DATA_NODE__<T>::__DATA_NODE__(const xt::xarray<T>& data)
{
	this->data = data;
	this->grad = DEFAULT_TENSOR_FLOAT32;
}

template<typename T>
inline void __DATA_NODE__<T>::SetPreNode(__CAL_NODE__<T>* pre_node)
{
	this->pre_node = pre_node;
}

template<typename T>
inline void __DATA_NODE__<T>::AddBackNode(__CAL_NODE__<T>* back_node)
{
	this->back_node.push_back(back_node);
}



//__CAL_NODE__


#endif // !NODE


