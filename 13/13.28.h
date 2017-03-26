//
// Created by lianlian on 16-9-28.
//
#include <string>
#ifndef CLINE_13_28_H
#define CLINE_13_28_H
class TreeNode{
public:
    /**
     * @brief 构造函数
     * @return
     */
    TreeNode() : value(std::string()), count(new int(0)),left(nullptr), right(nullptr) {
        ++*count;
    };
    TreeNode(std::string val = std::string()) : value(val) , count(new int(0)) {
        ++*count;
    };
    /**
     * @brief 拷贝赋值函数
     * @param rhs
     * @return
     */
    TreeNode(const TreeNode& rhs) : value(rhs.value), count(rhs.count), left(rhs.left), right(rhs.right){
        ++ this -> count;
    }
    /**
     * @brief 传值拷贝函数
     * @return
     */
    TreeNode& operator= (const TreeNode& rhs){
        ++*count;
        if(--*count == 0)
        {
            if(left){
                delete left;
                left = nullptr;
            }
            if(right){
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
        }
        this->value = rhs.value;
        this->count = rhs.count;
        this->left = rhs.left;
        this->right = rhs.right;
        return *this;
    }
    /**
     * @brief 析构函数
     */
    ~TreeNode(){
        if(--*count == 0){
            if(left){
                delete left;
                left = nullptr;
            }
            if(right){
                delete right;
                right = nullptr;
            }
            delete count;
            count = nullptr;
        }
    }
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;
};
class BinStrTree{
public:
    /**
     * @brief 构造函数
     * @return
     */
    BinStrTree() : root(new TreeNode()){};
    /**
     * @brief 拷贝传值函数
     */
    BinStrTree(const BinStrTree& rhs) :root(rhs.root){}
    /**
     * @brief 拷贝赋值运算符
     */
    BinStrTree& operator= (BinStrTree& rhs){
        TreeNode *new_root = new(TreeNode(*rhs.root));
        delete root;
        root = new_root;
        return *this;
    };
private:
    TreeNode *root;
};
#endif //CLINE_13_28_H
