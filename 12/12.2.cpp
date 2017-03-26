#include <string>
#include <vector>
#include <initializer_list>
#include <memory>

using namespace std;
class StrBlob {
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob() : data(make_shared<vector<string>>()){};
    StrBlob(initializer_list<string> il):
            data(make_shared<vector<string>> (il)){};
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
    }

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string &msg) const{
        if(i >= data ->size())
            throw out_of_range(msg);
    }
};

