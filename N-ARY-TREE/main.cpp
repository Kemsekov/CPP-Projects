#include "models/Tree.hpp"

class Temp{
    public:
    Temp(int num) : n(num){};
    int n = 0;
};

int main(){
    using namespace std;
    try{
        hash_func<string&&> func = [](string&& str){
            return hash<string>()(forward<string>(str));
        };

        Tree<12,string,string> tree{func};
        for(int a = 0; a<100;a++){
            tree.Insert(to_string(a)+(char)(a%25+65),to_string(a));
        }

        return 0;
    }
    catch(exception ex){
        return 1;
    }
}