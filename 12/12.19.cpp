//
// Created by lianlian on 16-9-27.
//
#include <memory>
#include <vector>
#include <exception>
using namespace std;
class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    /**
     * @brief 构造函数
     */
    StrBlob() : data(make_shared<vector<string>>()){};
    StrBlob(initializer_list<string> il):
            data(make_shared<vector<string>> (il)){};
    /**
     * @brief 函数起止点
     * @return StrBlobPtr 指针
     */
    StrBlobPtr begin();
    StrBlobPtr end();
    size_t size() const {
        return data -> size();
    }
    bool empty() const {
        return data -> empty();
    }
    void push_back(const string &t){
        return data -> push_back(t);
    }
    string& front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string& back()
    {
        check(0, "");
        return data->back();
    }

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const{
        if(i >= data ->size())
            throw out_of_range(msg);
    }
};

/**
 * @brief StrBlob的指针
 */
class StrBlobPtr{
public:
    StrBlobPtr():curr(0) {};
    StrBlobPtr(StrBlob &a,size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t,const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
std::string& StrBlobPtr::deref() const {
    auto p = check(curr,"dereference past end");
    return (*p)[curr];
}
/**
 * @brief 前缀递增
 * @return
 */
StrBlobPtr& StrBlobPtr::incr(){
    check(curr,"increment past and of StrBlobPtr");
    ++curr;
    return *this;
}
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i,const std::string& msg) const{
    auto ret = wptr.lock();
    if(!ret) // 检查ret是不是还存在
    {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if(i >= ret ->size())
        throw std::out_of_range(msg);
    return ret;
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    return StrBlobPtr(*this, data->size());
}