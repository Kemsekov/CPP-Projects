#include "Header.hpp"
#include "HashTable.hpp"
int main(){
    using namespace std;
    float a[] = {1,2.2,3,4,5};
    cout <<"typeid : "<< typeid(remove_all_extents<decltype(a)>::type).name()<<endl;
}