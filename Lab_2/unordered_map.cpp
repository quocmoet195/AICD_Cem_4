#include "unordered_map.h"

int MyUnorderedMap::hash(const std::string& key) const {
    if (table.empty()) {
        return 0; // или выбросить исключение, если вы предпочитаете
    }
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    return sum % table.size();
}


MyUnorderedMap::MyUnorderedMap() : table(10), size(0) {}

// Конструктор пустой хеш таблицы заданного размера
MyUnorderedMap::MyUnorderedMap(int initialSize) : table(initialSize=10), size(0) {}

// Конструктор копирования
MyUnorderedMap::MyUnorderedMap(const MyUnorderedMap& other) : table(other.table), size(other.size) {}

// Деструктор
MyUnorderedMap::~MyUnorderedMap() {
    clear();
}

// Оператор присваивания
MyUnorderedMap& MyUnorderedMap::operator=(const MyUnorderedMap& other) {
    if (this != &other) {
        table = other.table;
        size = other.size;
    }
    return *this;
}

// Печать содержимого
void MyUnorderedMap::print() const {
    for (const auto& it : table) {
        for (const auto& node : it) {
            std::cout << "{" << node.key << ": " << node.value << "} ";
        }
    }
    std::cout << std::endl;
}

// Вставка значения по ключу
void MyUnorderedMap::insert(const std::string& key, int value) {
    int index = hash(key);
    table[index].push_back(Node(key, value));
    size++;
}

// Вставка или присвоение значения по ключу
void MyUnorderedMap::insert_or_assign(const std::string& key, int value) {
    int index = hash(key);
    auto& bucket = table[index];
    for (auto& node : bucket) {
        if (node.key == key) {
            node.value = value;
            return;
        }
    }
    bucket.push_back(Node(key, value));
    size++;
}

// Проверка наличия элемента
bool MyUnorderedMap::contains(int value) const {
    for (const auto& bucket : table) {
        for (const auto& node : bucket) {
            if (node.value == value) {
                return true;
            }
        }
    }
    return false;
}

// Поиск элемента
int MyUnorderedMap::search(const std::string& key) {
    int index = hash(key);
    auto& bucket = table[index];
    for (auto& node : bucket) {
        if (node.key == key) {
            return node.value;
        }
    }
    throw std::invalid_argument("Key not defind");
    return 0;
}


// Удаление элемента по ключу
bool MyUnorderedMap::erase(const std::string& key) {
    int index = hash(key);
    auto& bucket = table[index];
    auto it = std::find_if(bucket.begin(), bucket.end(),
        [key](const Node& node) { return node.key == key; });
    if (it != bucket.end()) {
        bucket.erase(it);
        size--;
        return true;
    }
    return false;
}

// Возвращает количество элементов по соответствующему ключу
int MyUnorderedMap::count(const std::string& key) const {
    int index = hash(key);
    int count = 0;
    for (const auto& node : table[index]) {
        if (node.key == key) {
            count++;
        }
    }
    return count;
}

// Очистка хеш-таблицы
void MyUnorderedMap::clear() {
    for (auto& bucket : table) {
        bucket.clear();
    }
    size = 0;
}
