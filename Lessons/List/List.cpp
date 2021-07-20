// List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T>
struct NodeList {
    T value;
    NodeList<T>* next;

    NodeList(T value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

template<typename T>
class List {
private:
    NodeList<T>* head;
    NodeList<T>* tail;
    int count;
private:
    NodeList<T>* get_node(int);
    void create_first(T value);
public:
    List();
    List(T value);
    ~List();
    int get_index(T);
    void insert(T, int);
    void del(int);
    T& operator[](int);
    int get_count();
    bool is_empty();
    void shift(T value);
    void push(T value);
    T unshift();
    T pop();
};

template<typename T>
List<T>::List() : head{ nullptr }, tail{ nullptr }, count{ 0 } {}

template<typename T>
List<T>::List(T value) : count{ 0 } {
    create_first(value);
}

template<typename T>
void List<T>::create_first(T value) {
    head = tail = new NodeList<T>(value);
    count++;
}

template<typename T>
List<T>::~List() {
    NodeList<T>* elm = head;
    while (elm != nullptr)
    {
        NodeList<T>* next = elm->next;
        delete elm;
        elm = next;
        count--;
    }
    head = tail = nullptr;
}

template<typename T>
int List<T>::get_index(T value) {
    NodeList<T>* inc = head;
    int i = 0;
    while (inc->value != value)
    {
        inc = inc->next;
        i++;
        if (inc == nullptr)
            return -1;
    }
    return i;
}

template<typename T>
int List<T>::get_count() {
    return count;
}

template<typename T>
bool List<T>::is_empty() {
    return count == 0;
}

template<typename T>
void List<T>::shift(T value) {
    if (is_empty()) {
        create_first(value);
    }
    else {
        NodeList<T>* new_node = new NodeList<T>(value);
        new_node->next = head;
        head = new_node;
        count++;
    }
}

template<typename T>
void List<T>::push(T value) {
    if (is_empty()) {
        create_first(value);
    }
    else {
        NodeList<T>* new_node = new NodeList<T>(value);
        tail->next = new_node;
        tail = new_node;
        count++;
    }
}

template<typename T>
T List<T>::unshift() {
    if (!is_empty()) {
        T value = head->value;
        NodeList<T>* tmp = head;
        if (count > 1) {
            head = head->next;
            delete tmp;
        }
        else {
            delete tmp;
            head = tail = nullptr;
        }
        count--;
        return value;
    }
}

template<typename T>
T List<T>::pop() {
    if (!is_empty()) {
        T value = tail->value;
        delete tail;
        count--;
        if (!is_empty()) {
            tail = get_node(count - 1);
            tail->next = nullptr;
        }
        else
            head = tail = nullptr;
        return value;
    }
}

template<typename T>
void List<T>::insert(T value, int pos) {
    if (is_empty()) {
        create_first(value);
    }
    else if (pos == 0) {
        shift(value);
    }
    else if (pos == count - 1) {
        push(value);
    }
    else if (pos >= 0 && pos < count) {
        NodeList<T>* prev = get_node(pos - 1);
        NodeList<T>* next = prev->next;
        NodeList<T>* cur = new NodeList<T>(value);
        prev->next = cur;
        cur->next = next;
        count++;
    }
}

template<typename T>
void List<T>::del(int pos) {
    if (is_empty() || pos < 0 || pos >= count) {
        return;
    }
    else if (pos == 0) {
        unshift();
    }
    else if (pos == count - 1) {
        pop();
    }
    else {
        NodeList<T>* prev = get_node(pos - 1);
        NodeList<T>* cur = prev->next;
        NodeList<T>* next = cur->next;
        prev->next = next;
        delete cur;
        count--;
    }
}

template<typename T>
T& List<T>::operator[](int i) {
    if (i >= 0 && i < count) {
        NodeList<T>* inc = head;
        while (i)
        {
            inc = inc->next;
            --i;
        }
        return inc->value;
    }
}

template<typename T>
NodeList<T>* List<T>::get_node(int i) {
    if (i >= 0 && i < count) {
        NodeList<T>* inc = head;
        while (i)
        {
            inc = inc->next;
            --i;
        }
        return inc;
    }
    return nullptr;
}


int main()
{
    List<int> lst;
    lst.shift(13);
    lst.shift(14);
    lst.shift(15);
    lst.shift(16);
    //lst.insert(22, 1);
    //lst.insert(77, 3);
    //lst.del(2);
    //lst.del(1);
    /*std::cout << lst.get_count() << std::endl;
    std::cout << lst[0] << std::endl;
    std::cout << lst[lst.get_count() - 1] << std::endl;
    std::cout << lst[2] << std::endl;*/
    std::cout << "Index 14 = " << lst.get_index(14) << std::endl;
    int size = lst.get_count();
    std::cout << lst.get_count() << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << lst.unshift() << std::endl;
    }
    std::cout << lst.get_count() << std::endl;
}
