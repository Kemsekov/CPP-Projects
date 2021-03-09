#include <iostream>

using namespace std;

void* operator new (size_t size, const char* filename, int line) {
    void* ptr = new char[size];
    cout << "size = " << size << " filename = " << filename << " line = " << line << endl;
    return ptr;
}

#define new new(__FILE__, __LINE__)

int main() {
    int* x = new int;
    delete x;
}