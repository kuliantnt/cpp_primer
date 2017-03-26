//
// Created by lianlian on 16-9-27.
//
#include <memory>
#include <vector>
using namespace std;


using std::vector;
using std::string;
class StrBlobPtr;
class StrBlob {
    friend bool operator== (const StrBlob &, const StrBlob &);
    friend bool operator!= (const StrBlob &, const StrBlob &);
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    /**
     * @brief 构造函数
     * @param
     * @return
     */
    StrBlob() : data(make_shared<vector<string>>()){};
    StrBlob(std::initializer_list<string> il):
            data(std::make_shared<vector<string>> (il)){};
    /**
     * @brief 拷贝构造函数
     * @return
     */
    StrBlob(const StrBlob& sb) : data(std::make_shared<vector<string>>(*sb.data)) { }
    /**
     * @brief 拷贝赋值运算符
     * @param sb
     * @return
     */
    StrBlob& operator= (StrBlob& sb)
    {
        data = sb.data;
        return *this;
    }
    /**
     * @brief 函数起止点
     * @return begin end size empty push_back
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
    /**
     * @brief 返回函数第一个和最后的值
     * @return front and back
     */
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
    /**
     * @brief 检查下标是否溢出
     * @param i
     * @param msg
     */
    void check(size_type i, const string &msg) const{
        if(i >= data ->size())
            throw out_of_range(msg);
    }
};
class StrBlobPtr{
    friend class StrBlob;
    friend bool operator== (const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!= (const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr():curr(0) {}
    StrBlobPtr(StrBlob &a,size_t sz = 0) : wptr(a.data), curr(sz) {}
    /**
     * @brief 拷贝构造函数
     * @return
     */
    StrBlobPtr(const StrBlobPtr& sbp) : curr(sbp.curr) ,wptr(sbp.wptr){}
    /**
     * @brief 拷贝赋值运算符
     * @return
     */
    StrBlobPtr& operator= (StrBlobPtr& sbp){
        this -> curr = sbp.curr;
        this -> wptr = sbp.wptr;
        return *this;
    }
    //一大堆operator overload
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    std::string &operator*() const;
    std::string *operator->() const;


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
/**
 * @brief 检查函数是否存在或者溢出
 * @param i
 * @param msg
 * @return
 */
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

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

StrBlobPtr &StrBlobPtr::operator++() {
    check(curr,"end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
    check(curr,"begin of StrBlobPtr");
    --curr;
    return *this;
}

std::string &StrBlobPtr::operator*() const {
    auto p = check(curr,"dereference past end");
    return ((*p)[curr]);
}

std::string *StrBlobPtr::operator->() const {
    return & this -> operator*();
}

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end(){
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

bool operator==(const StrBlob &lhs,const StrBlob &rhs) {
    return lhs.data == lhs.data;
}
bool operator!=(const StrBlob &lhs,const StrBlob &rhs) {
    return !(lhs == rhs);
}
