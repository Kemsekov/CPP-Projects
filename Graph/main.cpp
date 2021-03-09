#define __cplusplus 201703L
#define DEBUG
#include <iostream>
#include "Graph.hpp"
#include <vector>
#include "header.hpp"
#include <variant>

//this is absolutely cringe and only god knows what the hell is happening here.
//just completely forget about, i'll let it be here just because of some thought...
class City{
    public:
    City(){};
    City(std::string && name, int population) : Name{name},Population{population}{};
    std::string Name;
    int Population;
};

int main(){
    using namespace std;
    Graph<City> g{};
    g.Current.Value = City("Samara",12000);
    g.AddNewNode(City("Piter",600000));
    g.AddNewNode(City("Teterev",400000));
    g.AddNewNode(City("Perm",350000));
    auto node1 = g.begin().operator*().lock().get();
    node1->AddExistingNode((g.end()-1).operator*());
    node1->AddNewNode(City("None",5813561));
    auto ptr = node1->Nodes[1];
    if(auto node2 = get_if<shared_ptr<Graph<City>>>(&ptr))
        node2->get()->AddExistingNode(move(g.Nodes[0]));

    for(auto node : g)
        cout<<node.lock().get()->Current.Value.Name<<endl;
}
