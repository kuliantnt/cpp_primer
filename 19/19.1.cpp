/*
//
// Created by lianlian on 17-3-22.
//

#include <new>
#include "cstdlib"

void* operator new(size_t size){
    if(void *men = malloc(size)){
        return men;
    }
    else{
        throw std::bad_alloc();
    }
}

void operator delete (void *men) noexcept{
    free(men);
}
*/
