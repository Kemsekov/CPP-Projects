#include <iostream>
#define DEBUG ;
#include "header.hpp"
#include "Graph.hpp"

class XYNodeState{
    public:
    XYNodeState(int roadKm, NodeState state) : state{state},RoadKm{roadKm}{};
    int RoadKm;
    NodeState state;
};

class CityNode{
    public:
    CityNode(std::string && name,int population,int xCoordinate,int yCoordinate) : 
    Name{name},
    Population{population},
    X{xCoordinate},
    Y{yCoordinate}
    {};
    std::string Name;
    int Population;
    int X;
    int Y;
};

int main(){
    using namespace std;
    Graph<CityNode,XYNodeState> g;
    g.emplace_back(CityNode("Kazan",500002,300,500),CityNode("Arnama",450000,6000,20),XYNodeState(9000,NodeState::Both));
    /*
        Kazan city(population = 500002)(300;500)
                   *<-----looong-both-road---------------> Arnama city(population=450000)(6000;20)
    */
    //and so on...   
}


void GraphExplained(){
    using namespace std;
    Graph<string,NodeState> g;    
    //now we have a node1 that connected to node2 : (node1)-->(node2)
    g.emplace_back("node1","node2",NodeState::Forward);
    //now node2 is connected to node3 as well as node3 connected to node2 : (node2)<->(node3)
    g.emplace_back("node2","node3",NodeState::Both);
    //now node1 is connected to node3 : (node3)<--(node1)
    g.emplace_back("node3","node1",NodeState::Backward);
    //if to put it simple now we have following graph
    /*
        node1-->node2<->node3
          *--------------^
    it's like cycle i gusses.
    */
}