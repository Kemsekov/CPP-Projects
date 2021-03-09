#pragma once
#include <vector>
#include <memory>
template<typename T,typename Weight>
class Graph : public std::vector<std::shared_ptr<Graph<T,Weight>>> {
    public:
    std::vector<std::weak_ptr<Graph<T,Weight>>> ExistingNodes;
    T Value;
    Weight Weight_;
    Graph(T && value, Weight && weight) : Value(value),Weight_(weight) {};
    Graph(){};
    void AddExistingNode(std::weak_ptr<Graph<T,Weight>> && node);
    template<typename ...Args>
    void emplace_back(Args&&... args);
};


template<typename T, typename Weight>
void Graph<T, Weight>::AddExistingNode(std::weak_ptr<Graph<T,Weight>> && node) 
{
    ExistingNodes.push_back(std::forward<std::weak_ptr<Graph<T,Weight>>>(node));
}

template<typename T, typename Weight>
template<typename ...Args>
void Graph<T, Weight>::emplace_back(Args&&... args) 
{
    std::vector<std::shared_ptr<Graph<T,Weight>>>::emplace_back(std::make_shared<Graph<T,Weight>>(std::forward<Args>(args)...));
}
