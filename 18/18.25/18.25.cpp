/*
//
// Created by lianlian on 17-3-2.
//

#include <iostream>

*/
/**
 * class D1 : public Base1 {...};
 * class D2 : public Base2 {...};
 * class MI : public 1, public D2{...};
 * Base *pd1 = new MI;
 * Base *pb2 = new MI;
 * D1 *pd1 = new MI;
 * D2 *pd2 = new MI;
 *//*



class Base1{
public:
    virtual void print(){
        std::cout << "base1" << std::endl;
    }
    virtual ~Base1(){
        std::cout << "delete base1" << std::endl;
    }
};

class Base2{
public:
    virtual void print(){
        std::cout << "base2" << std::endl;
    }
    virtual ~Base2(){
        std::cout << "delete base2" << std::endl;
    }
};

class D1 : public Base1{
public:
    void print(){
        std::cout << "D1" << std::endl;
    }
    ~D1(){
        std::cout << "delete D1" << std::endl;
    }
};

class D2 : public Base2{
public:
    void print(){
        std::cout << "D2" << std::endl;
    }
    ~D2(){
        std::cout << "delete D2" << std::endl;
    }
};

class MI : public D1, public D2{
public:
    void print(){
        std::cout << "MI" << std::endl;
    }
    ~MI(){
        std::cout << "delete MI" << std::endl;
    }
};

int main(int argc, char ** argv){
    Base1 *pb1 = new MI;
    Base2 *pb2 = new MI;
    D1 *pd1 = new MI;
    D2 *pd2 = new MI;

    std::cout << "a" << "\t";
    pb1 -> print();
    std::cout <<  std::endl;

    std::cout << "b" << "\t";
    pd1 -> print();
    std::cout <<  std::endl;

    std::cout << "c" << "\t";
    pd1 -> print();
    std::cout <<  std::endl;


    std::cout << "d" << "\t";
    delete pb2;
    std::cout <<  std::endl;

    std::cout << "e" << "\t";
    delete pd1;
    std::cout <<  std::endl;

    std::cout << "f" << "\t";
    delete pd2;
    std::cout <<  std::endl;
}
*/
