#pragma once
#include "header.hpp"
#include <vector>
template<int degree,typename KeyT, typename ValueT>
class TreeNode{

    std::vector<TreeNode<degree,KeyT,ValueT>*> vec;
    KeyT key;
    ValueT value;
    size_t cell_size;
    hash_func<KeyT&&>& hash_fun;

    int _get_index(KeyT && key){
        return (int)(hash_fun(std::forward<KeyT>(key))/cell_size)%degree;
    }

    public:
    TreeNode(hash_func<KeyT&&> & hash_fun, KeyT && key, ValueT && value)
    : hash_fun(hash_fun)
    {
        using namespace std;
        this->key = forward<KeyT>(key);
        this->value = forward<ValueT>(value);
        vec = vector<TreeNode<degree,KeyT,ValueT>*>(degree,0);
        cell_size = 2*hash_fun(forward<KeyT>(key))/(size_t)(degree);
    }

    ~TreeNode(){
        for(int a = 0;a<vec.size();++a){
            if(vec.at(a)!=0){
            delete vec[a];
            vec[a] = 0;
            }
        }
    }

    void Insert(KeyT && key, ValueT && value){
        using namespace std;
        int index = _get_index(forward<KeyT>(key));

        if(vec[index]==0)
        vec[index] = new
        TreeNode<degree,KeyT, ValueT>(hash_fun,forward<KeyT>(key),forward<ValueT>(value));
        else
        vec[index]->Insert(forward<KeyT>(key),forward<ValueT>(value));
    }

    bool Remove(KeyT && key){
        using namespace std;
        int index = _get_index(forward<KeyT>(key));
        if(vec[index]=0){
            vec[index]->Remove();
            delete vec[index];
            vec[index]=0;
            return true;
        }
        return false;
    }
    ValueT & get_value(){
        return value;
    }

    KeyT get_key(){
        return key;
    }

};
