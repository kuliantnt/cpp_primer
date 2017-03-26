#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>

using namespace std;
map<string, string> buildMap(ifstream &map_file);
const string & transform(const string &s, const map<string, string> &m);
void word_transfrom (ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string test;
    while(getline(input,test))
    {
        istringstream stream(test);
        string word;
        bool firstword = true;
        while(stream >> word)
        {
            if(firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while(map_file >> key && getline(map_file,value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error(key + "没有规则");
    }
    return trans_map;
}
const string & transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if(map_it != m.cend())
        return map_it -> second;
    else
        return s;
}
int main(int argc, char *argv[])
{
    ifstream mapfiles(argv[1]);
    ifstream input (argv[2]);
    word_transfrom(mapfiles, input);
    return 0;
}
