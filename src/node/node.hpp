#ifndef NODE
#define NODE
#include "./datatype.h"
#include <set>
//using namespace xt;
//using namespace std;

#define DATA_NODE_FLOAT32 __DATA_NODE__<FLOAT32>
#define CAL_NODE_FLOAT32 __CAL_NODE__<FLOAT32>

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
	std::set<__DATA_NODE__<T>*> if_backward;

	__DATA_NODE__();
	__DATA_NODE__(xt::xarray<T>&data);
	__DATA_NODE__(const xt::xarray<T>&data);	//Anonymous objects
	void SetPreNode(__CAL_NODE__<T>* pre_node);
	void AddBackNode(__CAL_NODE__<T>* back_node);
	void SetData(xt::xarray<T>& data);
	void SetData(const xt::xarray<T>& data);
	void SetGrad(xt::xarray<T>& grad);
	void SetGrad(const xt::xarray<T>grad);

};

//abstract class 
template<typename T>
class __CAL_NODE__
{
public:
	std::vector<__DATA_NODE__<T>*> pre_node;
	__DATA_NODE__<T>* back_node;
	std::set<__DATA_NODE__<T>*> if_forward;

	__CAL_NODE__();
	virtual void AddPreNode(__DATA_NODE__<T>* pre_node);		//virtual better?		//yes
	virtual void SetBackNode(__DATA_NODE__<T>* back_node);

	virtual void Forward() = 0;
	virtual void Backward() = 0;
	virtual void ZeroGrad();
	virtual void UpdateParament(T eta);
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

template<typename T>
inline void __DATA_NODE__<T>::SetData(xt::xarray<T>& data)
{
	this->data = data;
}

template<typename T>
inline void __DATA_NODE__<T>::SetData(const xt::xarray<T>& data)
{
	this->data = data;
}

template<typename T>
inline void __DATA_NODE__<T>::SetGrad(xt::xarray<T>& grad)
{
	this->grad = grad;
}

template<typename T>
inline void __DATA_NODE__<T>::SetGrad(const xt::xarray<T> grad)
{
	this->grad = grad;
}

//__CAL_NODE__
template<typename T>
inline __CAL_NODE__<T>::__CAL_NODE__():back_node(nullptr)
{
}

template<typename T>
inline void __CAL_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	this->pre_node.push_back(pre_node);
	
}

template<typename T>
inline void __CAL_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{
	this->back_node = back_node;
}

template<typename T>
inline void __CAL_NODE__<T>::ZeroGrad()
{
}

template<typename T>
inline void __CAL_NODE__<T>::UpdateParament(T eta)
{
}


#endif // !NODE

