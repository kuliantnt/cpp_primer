//
// Created by lianlian on 16-9-27.
//

#ifndef CLINE_13_18_H
#define CLINE_13_18_H

#include <string>

class employee{
public:
    std::string& getName()
    {
        return this -> name;
    }
    unsigned int& getNo()
    {
        return this -> No;
    }
    /**
     * @brief 构造函数
     * @param name
     */
    employee() = default;
    employee(const std::string &n) : name(n), No(cosntnumber){
        cosntnumber++;
    }
    /**
     * @brief 拷贝控制
     * @param const employee&
     */
    employee(const employee& oldEmployee): name(oldEmployee.name),No(oldEmployee.No){}
    employee& operator= (const employee& oldEmployee)
    {
        this->name =  oldEmployee.name;
        this->No = oldEmployee.No;
        return *this;
    }
    /**
     * @brief 析构函数
     * @param N/A
     */
    ~employee() {
        delete name;
        delete No;
    }
private:
    std::string name;
    static int cosntnumber = 1;
    unsigned int No;
};
#endif //CLINE_13_18_H
