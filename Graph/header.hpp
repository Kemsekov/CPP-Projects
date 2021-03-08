#pragma once
#include <iostream>
#include <fstream>

#ifdef DEBUG
static std::ofstream log{"log.txt"};
#endif

void* operator new(size_t count){
    void* ptr = malloc(count); 
    #ifdef DEBUG
    log<<ptr<<"\tAllocated\n";
    #endif
    return ptr;
}
void operator delete(void* ptr){
    #ifdef DEBUG
    log<<ptr<<"\tFree\n";
    #endif
    free(ptr);
}