/*
* Pow
* Log
* Sin
* Cos
* Tan
*/
#ifndef ELEMENTARY_FUNCTION
#define ELEMENTARY_FUNCTION
#include "../node/node.hpp"
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <iostream>
#include <exception>

template<typename T>
class __POW_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};

template<typename T>
class __LN_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};

template<typename T>
class __SIN_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};

template<typename T>
class __COS_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};

template<typename T>
class __TAN_NODE__ :public __CAL_NODE__<T>
{
public:
	void AddPreNode(__DATA_NODE__<T>* pre_node) override;
	void SetBackNode(__DATA_NODE__<T>* back_node) override;
	void Forward() override;
	void Backward() override;
};

//__POW_NODE__
template<typename T>
inline void __POW_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 2)
		{
			//Positioning exception thrown
			throw("WARNING:\t__POW_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __POW_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __POW_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 2)
			throw("WARNING:\t__POW_NODE__::Forward\t pre_node must be 2! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__POW_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		this->back_node->data = xt::pow(this->pre_node[0]->data, this->pre_node[1]->data);

		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__POW_NODE__::Forward\t " << e.what() << std::endl;
	}
}

template<typename T>
inline void __POW_NODE__<T>::Backward()
{
	
	this->pre_node[0]->grad += this->back_node->grad * this->pre_node[1]->data * pow(this->pre_node[0]->data, this->pre_node[1] - 1);

	this->pre_node[1]->grad -= this->back_node->grad * xt::log(this->pre_node[0]->data) * xt::pow(this->pre_node[0]->data, this->pre_node[1]->data);

}

//__LN_NODE__
template<typename T>
inline void __LN_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 1)
		{
			//Positioning exception thrown
			throw("WARNING:\t__LN_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __LN_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __LN_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 1)
			throw("WARNING:\t__LN_NODE__::Forward\t pre_node must be 1! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__LN_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		this->back_node->data = xt::log(this->pre_node[0]->data);

		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__LN_NODE__::Forward\t " << e.what() << std::endl;
	}
} 

template<typename T>
inline void __LN_NODE__<T>::Backward()
{

	this->pre_node[0]->grad += this->back_node->grad * (1 / this->pre_node[0]->data);
}


//__SIN_NODE__
template<typename T>
inline void __SIN_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 1)
		{
			//Positioning exception thrown
			throw("WARNING:\t__SIN_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __SIN_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __SIN_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 1)
			throw("WARNING:\t__SIN_NODE__::Forward\t pre_node must be 1! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__SIN_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		this->back_node->data = xt::sin(this->pre_node[0]->data);
		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__SIN_NODE__::Forward\t " << e.what() << std::endl;
	}
}

template<typename T>
inline void __SIN_NODE__<T>::Backward()
{

	this->pre_node[0]->grad += this->back_node->grad * xt::cos(this->pre_node[0]->data);

}

//__COS_NODE__
template<typename T>
inline void __COS_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 1)
		{
			//Positioning exception thrown
			throw("WARNING:\t__COS_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __COS_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __COS_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 1)
			throw("WARNING:\t__COS_NODE__::Forward\t pre_node must be 1! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__COS_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		this->back_node->data = xt::cos(this->pre_node[0]->data);
		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__COS_NODE__::Forward\t " << e.what() << std::endl;
	}
}

template<typename T>
inline void __COS_NODE__<T>::Backward()
{

	this->pre_node[0]->grad -= this->back_node->grad * xt::sin(this->pre_node[0]->data);

}

//__TAN_NODE__
template<typename T>
inline void __TAN_NODE__<T>::AddPreNode(__DATA_NODE__<T>* pre_node)
{
	try
	{
		if (this->pre_node.size() >= 1)
		{
			//Positioning exception thrown
			throw("WARNING:\t__TAN_NODE__::AddPreNode\t pre_node is full!  Stop adding pre_node!");
		}
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	this->pre_node.push_back(pre_node);

}

template<typename T>
inline void __TAN_NODE__<T>::SetBackNode(__DATA_NODE__<T>* back_node)
{

}

template<typename T>
inline void __TAN_NODE__<T>::Forward()
{
	try
	{
		if (this->pre_node.size() < 1)
			throw("WARNING:\t__TAN_NODE__::Forward\t pre_node must be 1! Check pre_node again!");
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		if (this->back_node == nullptr)
			throw("WARNING:\t__TAN_NODE__::Forward\t back_node must be 1! Add a back_node!")
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	try
	{
		this->back_node->data = xt::tan(this->pre_node[0]->data);
		this->if_forward.clear();	//why?
	}
	catch (const std::exception& e)
	{
		std::cout << "WARNING:\t__TAN_NODE__::Forward\t " << e.what() << std::endl;
	}
}

template<typename T>
inline void __TAN_NODE__<T>::Backward()
{

	this->pre_node[0]->grad += this->back_node->grad * (1/xt::pow(xt::cos(this->pre_node[0]->data),2);

}

#endif // !ELEMENTARY_FUNCTION
