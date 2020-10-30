#include "models/HashTable.hpp"

int main(){
    using namespace std;
    try{

    exampleOfUsingHashTable();
    return 0;
    
    }
    catch(exception ex){
        cout<<ex.what()<<endl;
        return 1;
    }
}