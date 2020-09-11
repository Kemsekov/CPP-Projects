#pragma once


template<class T>
class Tree{
	public:
	void AddElement(T* el){
		if((T)(*el)>(T)(*data)){
			if(right!=0)
			right->AddElement(el);
			else{
				right = new Tree(el);
			}
		}
		else{
			if(left!=0)
			left->AddElement(el);
			else{
				left = new Tree(el);
			}
		}
	}
	
	//iterate trough all tree in comparator's order
	template<typename func_type>
	void IterateTree(func_type func){
		if(left!=0)
		left->IterateTree(func);
		func(data);
		if(right!=0)
		right->IterateTree(func);
	}

	Tree(T* data){
		this->data = data;
	}
	~Tree(){
		if(left!=0)
		left->~Tree();
		delete data;
		if(right!=0)
		right->~Tree();
	}
	protected:
	
    bool (*T,*T) comp* = 0;
	Tree* left = 0;
	Tree* right = 0;
	T *data;
	
};
