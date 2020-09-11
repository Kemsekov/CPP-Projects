#include <iostream>
#include <vector>

template<typename T>
class Matrix{
    public:
    Matrix(int size){
        values = std::vector<std::vector<T>>(size,std::vector<T>(size));
        
        
    }
    void operator<<(int a){
        static auto current = it(&values.begin());
        
    }
    void operator<<(char c){
        
    }
    ~Matrix(){
    }
    protected:
    typename std::vector<T>::iterator it(typename std::vector<T>::iterator *a = 0){
        static typename std::vector<T>::iterator current = values.begin();
        if(a==0)
        return current++;
        else
        current = *a;
        return current++;
    }
    std::vector<std::vector<T>> values;
};