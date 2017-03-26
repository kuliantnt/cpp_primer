//
// Created by lianlian on 16-10-20.
//

#ifndef CLINE_13_44_H
#define CLINE_13_44_H

#include <memory>
#include <iostream>

class String{
    friend bool operator== (const String&, const String&);
    friend bool operator!= (const String&, const String&);
    friend std::ostream& operator<< (std::ostream&, const String&);
public:
    String():String("") {
        std::cout << "using default construct" << std::endl;
    };
    String(const char*);
    String(const String&);
    String(String&&);
    String& operator=(const String&);
    void push_back(const char &);
    void chk_n_alloc();
    const char* begin() const{
        return element;
    }
    size_t capacity(){
        return cap - element;
    }
    ~String();
    size_t size();
    String& operator=(String &&);
private:
    std::allocator<char> alloc;
    void reallocate();
    void free();
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    char* element;
    char* first_free;
    char* cap;

    void range_initializer(const char *first, const char *last);

};
#endif //CLINE_13_44_H
