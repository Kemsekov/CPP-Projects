#pragma once
#include <vector>
template<typename NodeT,typename StateT>
class Node{
    public:
    Node(NodeT && node1, NodeT && node2,StateT && state) : Node1{node1},Node2{node2},State{state} {};
    NodeT Node1;
    NodeT Node2;
    StateT State;
};

template<typename NodeT,typename StateT>
class Graph : public std::vector<Node<NodeT,StateT>>{
    public:
    Graph() {};
};

//I mean when some node connected to other node in which way?
//(Node1)-->(Node2) is Forward, i.e we can go to Node2 from Node1 but not to Node1 from Node2
//(Node1)<--(Node2) is Backward
//(Node1)<->(Node2) is Both
enum NodeState{
    Forward,
    Backward,
    Both
};