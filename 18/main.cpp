/*
#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;


class Student
{
private:

    struct message
    {
        std::string name;
        int math;
        int chinese;
        int english;
        int number;
    };


public:

    void store();
    void alter();
    void del();
    void sort();
    void show();
    void add();
    message *mes= new  message[10];
    friend void ma(Student&);

};

Student cs;
void ma(Student &cs);




void Student::store() {
    using std::cin;
    using std::cout;


    int i = 0;
    char x;
    do {
        cout << "姓名\n";
        cin >> (mes[i].name);
        cout << "学号\n";
        cin >> (mes[i].number);
        cout << "语文\n";
        cin >> (mes[i].chinese);
        cout << "英语\n";
        cin >> (mes[i].english);
        cout << "数学\n";
        cin >> (mes[i].math);

        i++;
        cout << "q退出\n";
        cin >> x;
    } while (x != 'q');
    std::cout << "结束";

}

void Student::show()
{
    using std::endl;
    for(int i=0;i<10;i++) {
        std::cout << mes[i].name << endl << mes[i].number << endl << mes[i].chinese << endl << mes[i].english << endl
                  << mes[i].math << endl;
    }
}

void Student::add()
{
    int i=-1;
    do {
        i++;
    } while(mes[i].number!=0);
    {
        cout << "姓名\n";
        cin >> (mes[i].name);
        cout << "学号\n";
        cin >> (mes[i].number);
        cout << "语文\n";
        cin >> (mes[i].chinese);
        cout << "英语\n";
        cin >> (mes[i].english);
        cout << "数学\n";
        cin >> (mes[i].math);
        cout << "9退出\n";
        char ch = (char) getchar();
        switch (ch) {
            case 57: {

                ma(cs);
            }
                break;
            default:
                break;
        }

    }
}

void Student::del() {
    using std::endl;using std::cout;using std::cin;
    for (int i = 0; i < 10; i++) {
        std::cout << mes[i].name << endl << mes[i].number << endl << mes[i].chinese << endl << mes[i].english << endl
                  << mes[i].math << endl << endl << endl << endl << endl;
    }
    int x;
    cout << "请输入删除第几个学生信息:\n\n";
    cin >> x;
    mes[x - 1].name = ' ';
    mes[x - 1].number = 0;
    mes[x - 1].chinese = 0;
    mes[x - 1].math = 0;
    mes[x - 1].english = 0;
}

void ma(Student &cs) {
    using std::cout;
    cout << "\n\n\n          |======================================|\n\n\n\n";
    cout << "          欢迎使用学生信息管理系统\n\n";
    cout << "          1.查看信息\n";
    cout << "          2.增加初始信息\n";
    cout << "          3.新增信息\n";
    cout << "          4.修改信息\n";
    cout << "          5.删除信息\n";
    cout << "          6.返回菜单\n";
    cout << "          7.退出系统\n";
    cout << "          |======================================|\n\n\n\n";
    char ch;
    getchar();
    ch = (char) getchar();

    switch (ch) {
        case 49: {

            cs.show();
            getchar();
            ch = (char) getchar();
            switch (ch) {
                case 57: {

                    ma(cs);
                }
                    break;
                default:
                    break;
            }

        }
            break;
        case 50: {

            cs.store();
            getchar();
            ch = (char) getchar();
            switch (ch) {
                case 57: {

                    ma(cs);
                }
                    break;
                default:
                    break;
            }

        }
            break;
        case 51: {

            cs.add();
            getchar();
            ch = (char) getchar();
            switch (ch) {
                case 57: {

                    ma(cs);
                }
                    break;
                default:
                    break;
            }

        }
            break;
        case 52: {

            std::cout << "r";
            getchar();
            ch = (char) getchar();

            switch (ch) {
                case 57: {

                    ma(cs);
                }
                    break;
                default:
                    break;
            }

        }
            break;
        case 53: {

            cs.del();
            getchar();
            ch = (char) getchar();
            switch (ch) {
                case 57: {

                    ma(cs);
                }
                    break;
                default:
                    break;
            }

        }
            break;
        default: {

            std::cout << "666";
        }
    }

}






int main () {
    Student student1;

    cout << "\n\n\n          |======================================|\n\n\n\n";
    cout << "          欢迎使用学生信息管理系统\n\n";
    cout << "          请输入服务密码登入此系统\n          初始密码为123456\n          你有三次输入机会\n          如果三次输入均不正确，将退出系统\n\n\n";
    cout << "          |======================================|\n\n\n\n";
    std::string x;
    cin >> x;
    int i = 1;

    do {
        if (x != "123456" && i < 3) {
            cout << "第" << i << "次输入错误\n";
            i++;
           getline(cin,x);
        } else if (i > 3) {

            cout << "第三次输入错误，退出系统！！！！";
        }
    } while (x != "123456");
    {
        cin.sync();
        ma(student1);
    }




    return 0;
}*/
