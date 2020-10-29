#pragma once

//in my hash table there is two types:
//KeyT and ValueT
//I faced some troubles with using std::pair<>, so I wrote this class instead
template<typename KeyT, typename ValueT>
class Element{
    public:
    Element(KeyT && key, ValueT && value){
        this->Key = std::forward<KeyT>(key);
        this->Value = std::forward<ValueT>(value);
    }
    Element(KeyT && key){
        this->Key = std::forward<KeyT>(key);
    }
    mutable KeyT Key;
    mutable ValueT Value;
    friend bool operator<(Element & one,Element & other){
        return one.Key<other.Key;
    }
    friend bool operator<(Element one,Element other){
        return one.Key<other.Key;
    }
};