#pragma once

template<typename iter>
void quickSort(iter begin, iter end){
    #ifdef DEBUG
    std::cout<<"\nInput is :\n";
    for (iter a = begin;a<end;a++)
    std::cout << *a<<" ";
    #endif
    if(begin==(end-1) || begin>end || begin==end){
        return;
    }
    auto last      = *(end-1);
    iter buf_begin = begin;
    iter buf_end   = end-1;
    
    if(buf_begin+1==buf_end){
        if(*buf_begin>*buf_end)
        iter_swap(buf_begin,buf_end);
        return;
    }

    while(buf_begin<buf_end){
        if(*buf_begin<=last){
            ++buf_begin;
            continue;
        }
        if(*buf_end>=last){
            --buf_end;
            continue;
        }
        if(*buf_end<*buf_begin)
            iter_swap(buf_begin,buf_end);
    }
    iter_swap(end-1,buf_begin);

    using namespace std;
    #ifdef DEBUG
    std::cout<<"\nOutput is :\n";
    for (iter a = begin;a<end;a++)
        std::cout << *a<<" ";
    #endif
    quickSort(begin,buf_begin);
    quickSort(buf_begin,end);
}