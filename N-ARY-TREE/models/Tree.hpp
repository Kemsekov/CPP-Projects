#pragma once
#include "header.hpp"
#include "TreeNode.hpp"

template<int degree,typename KeyT, typename ValueT>
class Tree{
    hash_func<KeyT&&> hash_fun;
    TreeNode<degree,KeyT,ValueT> *root = 0;
    public:
    Tree(hash_func<KeyT&&> & hash_fun){
        using namespace std;
        this->hash_fun = hash_fun;
    }
    ~Tree(){
        if(root!=0){
            root->~TreeNode();
            delete root;
        }
    }
    void Insert(KeyT && key, ValueT && value){
        using namespace std;
        if(root!=0){
            root->Insert(forward<KeyT>(key),forward<ValueT>(value));
        }
        else{
            root = 
            new TreeNode<degree,KeyT,ValueT>(this->hash_fun,forward<KeyT>(key),forward<ValueT>(value));
        }
    }
    bool Remove(KeyT && key, ValueT && value){
        using namespace std;
        if(root!=0){
            root->Remove(forward<KeyT>(key),forward<ValueT>(value));
            return true;
        }
        else{
            return false;
        }
    }
};