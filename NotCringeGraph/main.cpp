#include <iostream>
#define DEBUG ;
#include "header.hpp"
#include <vector>
#include "Graph.hpp"

template<typename T,typename B>
void PrintGraph(Graph<T,B>* graph){
    if(graph==0) return;
    if(graph->size()==0 && graph->ExistingNodes.size()==0) return;
    std::vector<Graph<T,B>*> Owning;
    std::vector<Graph<T,B>*> NonOwning;
    std::cout<<graph->Value<<std::endl;
    for(auto a : *graph)
        if(a){
            auto ptr = a.get();
            std::cout<<"\tOwning :\t"<<ptr->Value<<"\t"<<ptr->Weight_<<std::endl;
            Owning.push_back(ptr);
        }
    for(auto b : graph->ExistingNodes)
        if(b.lock()){
            auto ptr = b.lock().get();
            std::cout<<"\tNon-Owning :\t"<<ptr->Value<<"\t"<<ptr->Weight_<<std::endl;
            NonOwning.push_back(ptr);
        }
    for(auto a : Owning)
        PrintGraph(a);
    for(auto a : NonOwning)
        PrintGraph(a);
}

int main(){
    using namespace std;
    Graph<string,int> g("root",0);
    g.emplace_back("element1",10);
    g.emplace_back("element2",50);
    g.emplace_back("element3",15);
    auto first = g.front();
    first.get()->emplace_back("element4",94);
    g.back().get()->AddExistingNode(first.get()->front());
    PrintGraph(&g);
}
    