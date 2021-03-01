#include <iostream>
#include <vector>
#ifndef DEBUG
#define DEBUG;
#endif // !DEBUG

#include "quickSort.hpp"

int main(){
    using namespace std;
    vector<int> vec{1,2,4,55,878,1,345,1,7,24,9,5};
    quickSort(vec.begin(),vec.end());
    cout << "\nResult is :\n";
    for(auto i = vec.begin();i<vec.end();i++){
        cout<<*i<<" ";
    }
}