#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>

class MyUnorderedMap {
private:
    struct Node {
        std::string key;
        int value;
        Node(const std::string& k, int v) : key(k), value(v) {}
    };

    std::vector<std::list<Node>> table;
    int size;

    int hash(const std::string& key) const;

public:
    MyUnorderedMap();
    MyUnorderedMap(int initialSize);

    MyUnorderedMap(const MyUnorderedMap& other);

    ~MyUnorderedMap();

    MyUnorderedMap& operator=(const MyUnorderedMap& other);

    void print() const;

    void insert(const std::string& key, int value);

    void insert_or_assign(const std::string& key, int value);

    bool contains(int value) const;

    int search(const std::string& key);

    bool erase(const std::string& key);

    int count(const std::string& key) const;

    void clear();
};
