#ifndef COMPUTATION_GRAPH_HFLOW
#define COMPUTATION_GRAPH_HFLOW

#include "datatype.h"
#include "node/node.hpp"
#include <xtensor/xview.hpp>
#include <queue>

template <typename T>
class __COMPUTATION_GRAPH_
{
	std::vector<__DATA_NODE__<T>*> begin_node_list;
	std::vector<__DATA_NODE__<T>*> end_node_list;
	std::vector<__DATA_NODE__<T>*> data_node_list;
	std::vector<__DATA_NODE__<T>*> para_node_list;
	
	__COMPUTATION_GRAPH_();

	void AddBeginNode(__DATA_NODE__<T>* begin_node);
	void AddEndNode(__DATA_NODE__<T>* end_node);
	void AddDataNode(__DATA_NODE__<T>* data_node);
	void AddParaNode(__DATA_NODE__<T>* para_node);

	void Forward();
	void Backward();

};

//__COMPUTATION_GRAPH__
template<typename T>
inline void __COMPUTATION_GRAPH_<T>::AddBeginNode(__DATA_NODE__<T>* begin_node)
{
	this->begin_node_list.push_back(begin_node);
}

template<typename T>
inline void __COMPUTATION_GRAPH_<T>::AddEndNode(__DATA_NODE__<T>* end_node)
{
	this->end_node_list.push_back(end_node);
}

template<typename T>
inline void __COMPUTATION_GRAPH_<T>::AddDataNode(__DATA_NODE__<T>* data_node)
{
	this->data_node_list.push_back(data_node);
}

template<typename T>
inline void __COMPUTATION_GRAPH_<T>::AddParaNode(__DATA_NODE__<T>* para_node)
{
	this->para_node_list.push_back(para_node);
}

template<typename T>
inline void __COMPUTATION_GRAPH_<T>::Forward()
{
	try
	{
		if (this->begin_node_list.empty()||this->end_node_list.empty())
		{
			throw("WARNING: __COMPUTAION_GRAPH__::Forward() begin_node_list or end_node_list is empty! Please add at least one node!");
		}
		
	}
	catch (const char* s)
	{
		std::cout << s << std::endl;
	}

	
	std::queue<__DATA_NODE__<T>*> q_data;
	std::queue<__CAL_NODE__<T>*> q_cal;
	
	for (auto iter = data_node_list.begin(); iter != data_node_list.end(); iter++)
	{
		q_data.push(*iter);
	}
	while (!q_data.empty() || !q_cal.empty())
	{
		if (!q_data.empty())
		{
			auto tmp_node = q_data.front();
			q_data.pop();

			if (tmp_node->back_node.size() == 0)
				continue;
			else
			{
				for (auto iter = tmp_node->back_node.begin(); iter != tmp_node->back_node.end(); iter++)
				{
					(*iter)->if_forward.insert(tmp_node);

					std::set<__DATA_NODE__<T>*> s;
					for (auto pre_node = (*iter)->pre_node.begin(); pre_node != (*iter)->pre_node.end(); pre_node++)
						s.insert(*pre_node);

					if ((*iter)->if_forward.size() == s.size())
					{
						q_cal.push(*iter);
					}
				}
			}
		}
		else
		{
			auto tmp_node = q_cal.front();
			q_cal.pop();

			tmp_node->Forward();
			q_data.push(tmp_node->back_node);
		}
	}


}




#endif // !COMPUTATION_FLOW_GRAPH

