#pragma once
#include <set>
#include <functional>
#include <vector>
#include "Element.hpp"

template<typename KeyT, typename ValueT>
class HashTable{
    
    std::function<size_t (KeyT&&)> hash_func;

    std::vector<std::set<Element<KeyT,ValueT>>> vec;

    int _get_index(KeyT && key);

    ValueT* _get_value(KeyT && key);
    
    auto _add(KeyT && key,ValueT && value);

    public:

    HashTable(int size_of_Table,std::function<size_t (KeyT&&)>&& hash_funct) : hash_func(std::forward<std::function<size_t (KeyT&&)>>(hash_funct))
    {
        using namespace std;
        this->vec = vector<set<Element<KeyT,ValueT>>>(size_of_Table);
    }

    //forward iterator for this HashTable
    class iterator;

    //returns value that assigned to key, if there is no such a key in the table, then creates a new key / value element in table
    //Can be used as Add(key,value) function : hashTable[key] = value;
    ValueT & operator[](KeyT && key);

    //if successfully added, then return true. If element with this key already existing in table,
    //then return false
    bool Add(KeyT && key,ValueT && value);

    //if element with this key is found and successfuly removed,then return true - else false 
    bool Remove(KeyT && key);


    iterator begin(){
        return iterator(&vec,vec.begin(),vec.begin().operator*().begin());
    }

    iterator end(){
        return iterator(&vec,vec.end(),vec.end().operator*().begin());
    }

}; 
//----------------------------------------------------------------------------


template<typename KeyT, typename ValueT>
int HashTable<KeyT,ValueT>::_get_index(KeyT && key){
    return hash_func(std::forward<KeyT>(key))%vec.size();
}

template<typename KeyT, typename ValueT>
ValueT* HashTable<KeyT,ValueT>::_get_value(KeyT && key){
    using namespace std;
    int index = _get_index(forward<KeyT>(key));
    set<Element<KeyT,ValueT>> & buf = vec[index];
    typename set<Element<KeyT,ValueT>>::iterator it = buf.find(Element<KeyT,ValueT>(forward<KeyT>(key),ValueT()));
    if(it==buf.end())
    return 0;
    return &it.operator*().Value;
}

template<typename KeyT, typename ValueT>
auto HashTable<KeyT,ValueT>::_add(KeyT && key,ValueT && value){
    using namespace std;
    int index = _get_index(forward<KeyT>(key));
    set<Element<KeyT,ValueT>> & buf = vec[index];
    return buf.emplace(forward<KeyT>(key),forward<ValueT>(value));
}

template<typename KeyT, typename ValueT>
bool HashTable<KeyT,ValueT>::Add(KeyT && key,ValueT && value){
    using namespace std;
    auto it = _add(forward<KeyT>(key),forward<ValueT>(value));
    return it.second;
}

template<typename KeyT, typename ValueT>
ValueT & HashTable<KeyT,ValueT>::operator[](KeyT && key){
    ValueT* buf = _get_value(std::forward<KeyT>(key));
    if(buf==0){
        auto it = _add(std::forward<KeyT>(key),ValueT()).first;
        return it.operator*().Value;
    }
    else{
        return *_get_value(std::forward<KeyT>(key));
    }
}

template<typename KeyT, typename ValueT>
bool HashTable<KeyT,ValueT>::Remove(KeyT && key){
    using namespace std;
    int index = _get_index(forward<KeyT>(key));
    set<Element<KeyT,ValueT>> & buf = vec[index];
    auto it = buf.find(forward<KeyT>(key));
    if(it==buf.end())
        return false;
    buf.erase(it);
    return true;
}
//----------------------------------------------------------

template<typename KeyT, typename ValueT>
class HashTable<KeyT,ValueT>::iterator{
    std::vector<std::set<Element<KeyT,ValueT>>> &vec;
    typename std::vector<std::set<Element<KeyT,ValueT>>>::iterator vec_it;
    typename std::set<Element<KeyT,ValueT>>::iterator set_it;
    public:
    iterator(std::vector<std::set<Element<KeyT,ValueT>>>* vect,typename std::vector<std::set<Element<KeyT,ValueT>>>::iterator vec_iter,typename std::set<Element<KeyT,ValueT>>::iterator set_iter)
    : vec(*vect), vec_it(vec_iter), set_it(set_iter)
    {
        
    }
    const Element<KeyT,ValueT>& operator*(){
        return *(&set_it.operator*());
    }
    typename HashTable<KeyT,ValueT>::iterator operator++(){
        if(++set_it!=vec_it.operator*().end()){
            return *this;
        }
        else if(++vec_it!=vec.end()){
            set_it = vec_it.operator*().begin();
            return *this;
        }
        else{
            set_it = vec_it.operator*().begin();
            return *this;
        }
    }



    bool operator==(typename HashTable<KeyT,ValueT>::iterator it){
        return set_it==it.set_it;
    }
    bool operator!=(typename HashTable<KeyT,ValueT>::iterator it){
        return set_it!=it.set_it;
    }
};