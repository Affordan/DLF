/*
* Add
* Sub
* Mul
* Div
*/
#ifndef ARITHMETIC
#define ARITHMETIC

#include "../node/node.hpp"
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <iostream>
#include <exception>



template<typename T>
class __ADD_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};

// back_node = pre_node( [0] - [1] )
template<typename T>
class __SUB_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};

// back_node = pre_node[0] * pre_node[1] 
template<typename T>
class __MUL_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};

// back_node = pre_node( [0] / [1])
template<typename T>
class __DIV_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};


// __ADD_NODE__
template<typename T>
inline void __ADD_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 2)
		{
			//Positioning exception thrown
			throw("WARNING:\t__ADD_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __ADD_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __ADD_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 2)
			throw("WARNING:\t__ADD_NODE__::Forward\t pre_node must be 2! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__ADD_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		//broadcasting
		this->back_node->data = this->pre_node[0]->data + this->pre_node[1]->data;

		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__ADD_NODE__::Forward\t " << e.what() << std::endl;
	}
}

template<typename T>
inline void __ADD_NODE__<T>::Backward()
{
	//partial L partial pre_node = partial L partial back_node because back_node = pre_node[0] +pre_node[1] 
	this->pre_node[0]->grad += this->back_node->grad;	//multiple grad needs to be added together.

	this->pre_node[1]->grad += this->back_node->grad;

}


//__SUB_NODE__
template<typename T>
inline void __SUB_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 2)
		{
			//Positioning exception thrown
			throw("WARNING:\t__SUB_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __SUB_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __SUB_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 2)
			throw("WARNING:\t__SUB_NODE__::Forward\t pre_node must be 2! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__SUB_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		this->back_node->data = this->pre_node[0]->data - this->pre_node[1]->data;

		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__SUB_NODE__::Forward\t " << e.what() << std::endl;
	}
}

template<typename T>
inline void __SUB_NODE__<T>::Backward()
{
	//partial L partial pre_node = partial L partial back_node because back_node = pre_node[0] - pre_node[1] 
	this->pre_node[0]->grad += this->back_node->grad;	//multiple grad needs to be added together.

	this->pre_node[1]->grad -= this->back_node->grad;

}

//__MUL_NODE__

template<typename T>
inline void __MUL_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 2)
		{
			//Positioning exception thrown
			throw("WARNING:\t__MUL_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __MUL_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __MUL_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 2)
			throw("WARNING:\t__MUL_NODE__::Forward\t pre_node must be 2! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__MUL_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		this->back_node->data = this->pre_node[0]->data * this->pre_node[1]->data;

		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__MUL_NODE__::Forward\t " << e.what() << std::endl;
	}
}

template<typename T>
inline void __MUL_NODE__<T>::Backward()
{
	
	//multiple grad needs to be added together.
	this->pre_node[0]->grad += (this->pre_node[1]->data) * (this->back_node->grad);

	this->pre_node[1]->grad += (this->pre_node[0]->data) * (this->back_node->grad);

}

// __DIV_NODE__
template<typename T>
inline void __DIV_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 2)
		{
			//Positioning exception thrown
			throw("WARNING:\t__DIV_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __DIV_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __DIV_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 2)
			throw("WARNING:\t__DIV_NODE__::Forward\t pre_node must be 2! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__DIV_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		this->back_node->data = this->pre_node[0]->data / this->pre_node[1]->data;

		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__DIV_NODE__::Forward\t " << e.what() << std::endl;
	}
}

template<typename T>
inline void __DIV_NODE__<T>::Backward()
{
	//back_node = pre_node[0] / pre_node[1] 
	//multiple grad needs to be added together.
	this->pre_node[0]->grad += ((xt::ones<T>(this->pre_node[1]->data.shape())) / this->pre_node[1]->data) * (this->back_node->grad);

	this->pre_node[1]->grad += -((xt::ones<T>(this->pre_node[1]->data.shape()))* (xt::ones<T>(this->pre_node[1]->data.shape()))) * (this->pre_node[0]->data) * (this->back_node->grad);

}

#endif // !ARITHMETIC


