// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T>
class HashTable {
private:
    T* arr;
    int max_size;
private:
    int hash(const char* str) {
        int sum = 0;
        for (size_t i = 0; i < strlen(str); i++)
        {
            sum += (int)str[i];
        }
        return sum % max_size;
    }
public:
    HashTable() {
        max_size = 10000;
        arr = new T[max_size];
    }
    void add(const char* key, T value) {
        arr[hash(key)] = value;
    }
    T& operator[](const char* key) {
        return arr[hash(key)];
    }
};

template<typename T>
struct NodeTree {
    T value;
    NodeTree<T>* left;
    NodeTree<T>* right;

    NodeTree(T value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template<typename T>
class Tree {
private:
    NodeTree<T>* root;
    int count;
public:
    Tree() : root{ nullptr }, count{ 0 } {}
    Tree(T root_value) : root{ new NodeTree<T>{root_value} }, count{ 1 } {}
    void add(T value, NodeTree<T>* node = this->root) {
        if (node == nullptr)
            node = new NodeTree<T>(value);
        else if (value >= node->value) {
            add(value, node->right);
        }
        else {
            add(value, node->left);
        }
    }

    T& search(T value, NodeTree<T>* node = this->root) {
        if (node == nullptr)
            return;
        else if (value > node->value) {
            search(value, node->right);
        }
        else if (value < node->value) {
            search(value, node->left);
        }
        else if (value == node->value) {
            return node;
        }
    }
};

int main()
{
    HashTable<char*> sht;
    sht.add("hello", (char*)"world");
    sht.add("cat", (char*)"dog");
    std::cout << sht["hello"] << std::endl;
    std::cout << sht["cat"] << std::endl;
    sht["hello"] = (char*)"aaaaa";
    std::cout << sht["hello"] << std::endl;
}
