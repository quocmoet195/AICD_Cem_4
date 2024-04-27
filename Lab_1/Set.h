#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Set {
private:
    struct TreeNode {
        int value;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
    };
    TreeNode* _root;

    static TreeNode* copy_tree(const TreeNode* root);
    static std::pair<TreeNode*, bool> insert_(TreeNode*& root, int value);
    static bool contains_(const TreeNode* root, int value);
    static void clear(TreeNode* root);
    static void print_(const TreeNode* root);
    static bool erase_(TreeNode*& root, int value);

public:
    Set();
    Set(const Set& tree);
    ~Set();

    Set& operator=(const Set& tree);

    bool insert(const int& value);
    bool contains(const int& value) const;
    void print() const;
    void erase(const int& value);
};

