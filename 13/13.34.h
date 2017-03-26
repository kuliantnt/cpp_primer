//
// Created by lianlian on 16-10-3.
//

#ifndef CLINE_13_34_H
#define CLINE_13_34_H

#include <string>
#include <set>

class Folder;
/**
 * @brief 消息类
 * @param constent 保存信息文本
 * @param folders 指向本Message所在的Folder的指针
 *
 */
class Message{
    friend class Folder;
    friend void swap(Folder&, Folder&);
    friend void swap (Message& , Message&);
public:
    //folders 被隐式初始化为空集合
    explicit Message (const std::string &str = ""): contents(str) { }
    //拷贝控制成员，用来管理指向本Message 的指针
    Message(const Message&); // 拷贝构造函数
    Message& operator= (const Message&);//拷贝赋值运算符
    ~Message();//构析函数
    //从给定Folder集合中添加/删除本Message;
    void save(Folder &);
    void remove(Folder &);

private:
    std::string contents; //实际消息文本
    std::set<Folder*>folders; //包含本Message的Folder
    //拷贝构造函数、拷贝赋值运算符和够细函数所使用的工具函数
    //将本Message添加到参数的Folder中
    void add_to_Folders(const Message&);
    //folders中每个Folder中删除本Message
    void remove_from_Folders();
    void addFldr(Folder* f) { folders.insert(f); }
    void remFldr(Folder* f) { folders.erase(f); }
};
/**
 * @brief 拷贝构造函数
 * @return
 */
Message::Message(const Message &m) : contents(m.contents), folders(m.folders){
    add_to_Folders(m);
}

/**
 * @brief 把message存放在指定folder文件中
 * @param f Folder文件
 */
void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMeg(this);
}

/**
 * @brief 从指定folder中删除message
 * @param f Folder
 */
void Message::remove(Folder &f) {
    folders.erase(&f);
    f.remMeg(this);
}

/**
 * @brief 在每个有folder 的文件中,copy一份message
 * @param m Message
 */
void Message::add_to_Folders(const Message &m) {
    for(auto f : m.folders)
        f -> addMeg(this);
}

/**
 * @brief 拷贝赋值运算
 * @param rhs 右值
 * @return a new message
 */
Message& operator= (const Message &rhs){
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}
/**
 * @biref 从每个文件夹中删除Message
 */
void Message::remove_from_Folders() {
    for (auto f : folders)
        f -> remMeg(this);
}

/**
 * @brief 析构函数
 */
Message::~Message() {
    remove_from_Folders();
}

class Folder{
    friend class Message;
    friend void swap(Message&,Message&);
    friend void swap(Folder&, Folder&);
public:
    Folder() = default;
    Folder(const Folder&); //拷贝构造函数
    Folder& operator=(const Folder&); //拷贝赋值函数
    ~Folder(); //析构函数
private:
    std::set<Message*> Messages;
    void addMeg(Message*); //添加Message
    void remMeg(Message*); //删除Message
    void add_to_message(const Folder&);
    void remove_from_message();
};

void swap(Message &lhs, Message &rhs) {
    using std::swap;
    for(auto f : lhs.folders)
        f -> remMeg(&lhs);
    for(auto f : rhs.folders)
        f -> remMeg(&rhs);
    swap(lhs.folders,rhs.folders); //使用swap(set&,set&)
    swap(lhs.contents,rhs.contents); //swap(string&, string&)
    for(auto f : lhs.folders)
        f -> addMeg(&lhs);
    for(auto f : rhs.folders)
        f -> addMeg(&rhs);
}

void Folder::addMeg(Message *m) {
    Messages.insert(m);
}

void Folder::remMeg(Message *m) {
    Messages.erase(m);
}

Folder::Folder(const Folder &f) : Messages(f.Messages){
    add_to_message(f);
}

Folder& Folder::operator=(const Folder &rhs) {
    remove_from_message();
    Messages = rhs.Messages;
    add_to_message(rhs);
    return *this;
}

Folder::~Folder() {
    remove_from_message();
}

void Folder::remove_from_message() {
    for(auto m : Messages)
        m -> remove(*this);
}

void Folder::add_to_message(const Folder &f) {
    for (auto m : Messages)
        m -> save(*this);
}

void swap(Folder &lhs , Folder &rhs) {
    for(auto m : lhs.Messages)
        m -> remFldr(&lhs);
    for(auto m : rhs.Messages)
        m -> remFldr(&rhs);
    using std::swap;
    swap(lhs.Messages,rhs.Messages);
    for (auto m : lhs.Messages)
        m -> addFldr(&lhs);
    for(auto m : rhs.Messages)
        m -> addFldr(&rhs);

}
