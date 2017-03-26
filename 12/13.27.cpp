//
// Created by lianlian on 16-9-25.
//
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <map>
#include <set>

using namespace std;
class QueryResult;
using line_no = std::vector<std::string>::size_type ;
class TextQuery{
public:
    TextQuery(std::ifstream&);
    QueryResult query (const std::string&);
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
class QueryResult{
    friend std::ostream& print(std::ostream&,const QueryResult);

public:
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f):
            sought(s), lines(p),file(f){}

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
QueryResult TextQuery::query (const std::string& sought)
{
    static shared_ptr<set<line_no >>nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
    {
        return QueryResult(sought,nodata,file);
    }
    else
    {
        return QueryResult(sought, loc->second, file);
    }
}
TextQuery::TextQuery(std::ifstream &is) :file(new std::vector<std::string>)
{
    string text;
    while (std::getline(is,text)){
        file -> push_back(text);
        int n = (int) (file -> size() - 1);
        istringstream line(text);
        string word;
        while(line >> word){
            auto &lines = wm [word];
            if(!lines)
            {
                lines.reset(new std::set<line_no>);
            }
            lines -> insert(n);
        }
    }
}
string  make_plural (size_t ctr,const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}
std::ostream& print(std::ostream& os,const QueryResult qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
    for(auto num : *qr.lines)
    {
        os << "\t(line " << num + 1 << ") " << *(qr.file -> begin() + num) << endl;
    }
    return os;
}
