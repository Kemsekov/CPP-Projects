#pragma once
#include <memory>
#include <list>
#include <functional>
#include <variant>
#include <iterator>

template<typename T>
using shared_weak_ptr = std::variant<std::shared_ptr<T>,std::weak_ptr<T>>;

template<typename T>
class Node{
    public:
    Node(){};
    Node(T && value){
        Value = value;
    }
    T Value;
};



template<typename T>
class Graph
{
    class iterator;
    public:
    Node<T> Current;
    std::vector<shared_weak_ptr<Graph<T>>> Nodes;
    Graph(T && value);
    Graph(){};
    void AddNewNode(T && value);
    void AddExistingNode(std::weak_ptr<Graph<T>> && node);
    iterator begin();
    iterator end();
};
template<typename T>
Graph<T>::Graph(T && value) 
{
    Current.Value = value;
}

template<typename T>
void Graph<T>::AddNewNode(T && value) 
{
    using namespace std;
    Nodes.push_back(make_shared<Graph<T>>(forward<T>(value)));
};

template<typename T>
void Graph<T>::AddExistingNode(std::weak_ptr<Graph<T>> && node) 
{
    using namespace std;
    Nodes.push_back(forward<weak_ptr<Graph<T>>>(node));
}

template<typename T>
typename Graph<T>::iterator Graph<T>::begin() 
{
    return Graph<T>::iterator(Nodes.begin());
}

template<typename T>
typename Graph<T>::iterator Graph<T>::end() 
{
    return Graph<T>::iterator(Nodes.end());
}


template<typename T>
class Graph<T>::iterator {
    public:
    typedef typename std::vector<shared_weak_ptr<Graph<T>>>::iterator iter;
    iter it;
    iterator(iter && it);
    iterator operator++(){++it;return *this;}
    iterator operator--(){--it;return *this;}
    iterator operator+(int n){it+=n;return *this;}
    iterator operator-(int n){it-=n;return *this;}
    bool operator!=(Graph<T>::iterator n){return this->it!=n.it;}
    std::weak_ptr<Graph<T>> operator*();
};

template<typename T>
Graph<T>::iterator::iterator(iter && it) 
{
    this->it=it;
};
template<typename T>
std::weak_ptr<Graph<T>> Graph<T>::iterator::operator*() 
{
    using namespace std;
    if(auto c = get_if<std::shared_ptr<Graph<T>>>(&(it.operator*())))
        return *c;
    if(auto c = get_if<std::weak_ptr<Graph<T>>>(&(it.operator*())))
        return *c;
};



