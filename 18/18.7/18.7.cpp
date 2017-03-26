/*
#include <iostream>

//
// Created by lianlian on 17-1-22.
//
int count = 0;
int foo(int n ){
    if (n == 1 || n == 2){
        ::count ++;
        return 2 * n;
    }else{
        ::count ++;
        return foo(n - 1) - foo(n - 2);
    }

}
int main(int argc,char * argv[]) {
    int result = foo(6);
    std::cout << ::count;
}

*/
