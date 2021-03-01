#pragma once
#include "Header.hpp"
#include <boost/smart_ptr/weak_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "IsHasable.hpp"
#include "vector"
#include <random>

template<typename T>
class HashTable{
    std::vector<T> vec;
    int _get_index(T && value){
        using namespace std;
        static int size = vec.size();
        return rand_r(hash<T>{}(forward<T>(value)))%size;
    }
    public:
    HashTable(int size=64){
        using namespace std;
        vec = vector<T>(size);
        static_assert(is_std_hashable_v<T>,"HashTable<T> : there is no implementation for hash<T>");
    }
    
};