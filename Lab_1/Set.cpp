#include "Set.h"

Set::Set() : _root(nullptr) {}

Set::Set(const Set& tree) : _root(copy_tree(tree._root)) {}

Set::~Set() {
    clear(_root);
}

Set& Set::operator=(const Set& tree) {
    if (this != &tree) {
        clear(_root);
        _root = copy_tree(tree._root);
    }
    return *this;
}

typename Set::TreeNode* Set::copy_tree(const TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* new_root = new TreeNode(root->value);
    new_root->left = copy_tree(root->left);
    new_root->right = copy_tree(root->right);
    return new_root;
}

std::pair<typename Set::TreeNode*, bool> Set::insert_(TreeNode*& root, int value) {
    if (!root) {
        root = new TreeNode(value);
        return { root, true };
    }
    else if (value < root->value) {
        return insert_(root->left, value);
    }
    else if (value > root->value) {
        return insert_(root->right, value);
    }
    else {
        return { root, false }; 
    }
}

bool Set::insert(const int& value) {
    pair<typename Set::TreeNode*, bool> result = insert_(_root, value);
    return result.second;
}

bool Set::contains_(const TreeNode* root, int value) {
    if (!root) return false;
    if (root->value == value) return true;
    if (value < root->value) return contains_(root->left, value);
    return contains_(root->right, value);
}

bool Set::contains(const int& value) const {
    return contains_(_root, value);
}

void Set::clear(TreeNode* root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

void Set::print_(const TreeNode* root) {
    if (root) {
        print_(root->left);
        std::cout << root->value << " ";
        print_(root->right);
    }
}


void Set::print() const {
    print_(_root);
    std::cout << std::endl;
}

bool Set::erase_(TreeNode*& root, int value) {
    if (!root) return false;
    if (value < root->value) {
        return erase_(root->left, value);
    }
    else if (value > root->value) {
        return erase_(root->right, value);
    }
    else {
        if (!root->left && !root->right) {
            delete root;
            root = nullptr;
        }
        else if (!root->left) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
        }
        else if (!root->right) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            TreeNode* min_right = root->right;
            while (min_right->left) {
                min_right = min_right->left;
            }
            root->value = min_right->value;
            erase_(root->right, min_right->value);
        }
        return true;
    }
}


void Set::erase(const int& value) {
    erase_(_root, value);
}


