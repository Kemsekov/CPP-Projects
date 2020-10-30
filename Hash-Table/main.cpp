#include "models/HashTable.hpp"
#include <iostream>

using namespace std;

int main(){
    try{
    
    //create hashTable with size of 60 and simple hash-function 
    auto hash = HashTable<int,string>(60,[](int && n){return n;});

    for(int i = 0;i<100;i++){
        hash[i] = to_string(i)+char(i%25+65);
    }

    hash[1234] = "I will added to hash table and deleted then!";
    
    if(hash.Remove(1234)){
        cout<<"Element with 1234 Key is deleted!\n";
    }

    hash[55]="because of element with 55 key already exist, this line will replace value of element with key = 55 to this string!";
    hash[101]; //this line will add empty element with key 101 in hash table

    for(auto a : hash){
        cout<<a.Key<<" "<<a.Value<<endl;
    }

    return 0;
    }
    catch(exception ex){
        cout<<ex.what()<<endl;
        return 1;
    }
}