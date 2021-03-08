#define __cplusplus 201703L
#define DEBUG
#include <iostream>
#include "Graph.hpp"
#include <vector>
#include "header.hpp"
#include <variant>

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
    for(auto node : g)
        cout<<node.lock().get()->Current.Value.Name<<endl;
}
