// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
class StackList {
private:
    NodeList<T>* head;
    int count;
private:
    void create_first(T value);
public:
    StackList();
    StackList(T value);
    ~StackList();
    T& top();
    int get_count();
    bool is_empty();
    void push(T value);
    T pop();
};

template<typename T>
StackList<T>::StackList() : head{ nullptr }, count{ 0 } {}

template<typename T>
StackList<T>::StackList(T value) : count{ 0 } {
    create_first(value);
}

template<typename T>
void StackList<T>::create_first(T value) {
    head = new NodeList<T>(value);
    count++;
}

template<typename T>
StackList<T>::~StackList() {
    NodeList<T>* elm = head;
    while (elm != nullptr)
    {
        NodeList<T>* next = elm->next;
        delete elm;
        elm = next;
        count--;
    }
    head = nullptr;
}

template<typename T>
int StackList<T>::get_count() {
    return count;
}

template<typename T>
bool StackList<T>::is_empty() {
    return count == 0;
}

template<typename T>
void StackList<T>::push(T value) {
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
T StackList<T>::pop() {
    if (!is_empty()) {
        T value = head->value;
        NodeList<T>* tmp = head;
        head = head->next;
        delete tmp;
        count--;
        return value;
    }
}

template<typename T>
T& StackList<T>::top() {
    return head->value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
class StackVector {
private:
    int capacity;
    int size;
    int rate;
    T* arr;
private:
    void check_capacity();
    void reserve();
    void shrink_to_fit();
    void reall();
    void copy(T[], T[]);
public:
    StackVector();
    StackVector(int);
    ~StackVector();
    T& top();
    int get_count();
    bool is_empty();
    void push(T);
    T pop();
};

template<typename T>
void StackVector<T>::check_capacity() {
    if (capacity < size + 3) {
        reserve();
    }
    else if (capacity - (rate + 20) > size) {
        shrink_to_fit();
    }
}

template<typename T>
void StackVector<T>::reserve() {
    capacity += rate;
    reall();
}

template<typename T>
void StackVector<T>::shrink_to_fit() {
    capacity = size < capacity - rate ? capacity - rate : capacity;
    reall();
}

template<typename T>
void StackVector<T>::reall() {
    T* new_arr = new T[capacity];
    copy(new_arr, arr);
    delete[] arr;
    arr = new_arr;
}

template<typename T>
void StackVector<T>::copy(T new_array[], T old_array[]) {
    for (int i = 0; i < size; ++i) {
        new_array[i] = old_array[i];
    }
}

template<typename T>
StackVector<T>::StackVector() : size{ 0 }, rate{ 15 }
{
    capacity = rate;
    arr = new T[capacity];
}

template<typename T>
StackVector<T>::StackVector(int _size) : size{ 0 }, rate{ 15 }
{
    capacity = _size + rate;
    arr = new T[capacity];
}

template<typename T>
StackVector<T>::~StackVector() {
    delete[] arr;
}

template<typename T>
T& StackVector<T>::top() {
    return arr[size - 1];
}

template<typename T>
int StackVector<T>::get_count() {
    return size;
}

template<typename T>
bool StackVector<T>::is_empty() {
    return size == 0;
}

template<typename T>
void StackVector<T>::push(T value) {
    size++;
    check_capacity();
    arr[size - 1] = value;
}

template<typename T>
T StackVector<T>::pop() {
    if (!is_empty()) {
        size--;
        check_capacity();
        T value = arr[size];
        arr[size] = 0;
        return value;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
class StackArray {
private:
    int size;
    int max_size;
    T* arr;
public:
    StackArray();
    StackArray(int);
    ~StackArray();
    T& top();
    int get_count();
    bool is_empty();
    bool is_full();
    void push(T);
    T pop();
};

template<typename T>
StackArray<T>::StackArray(int max_size) : max_size{ max_size }, size{ 0 }
{
    arr = new T[max_size];
}

template<typename T>
StackArray<T>::StackArray() : StackArray{ 20 } {}

template<typename T>
StackArray<T>::~StackArray() {
    delete[] arr;
}

template<typename T>
T& StackArray<T>::top() {
    return arr[size - 1];
}

template<typename T>
int StackArray<T>::get_count() {
    return size;
}

template<typename T>
bool StackArray<T>::is_empty() {
    return size == 0;
}

template<typename T>
bool StackArray<T>::is_full() {
    return size == max_size;
}

template<typename T>
void StackArray<T>::push(T value) {
    if (!is_full()) {
        size++;
        arr[size - 1] = value;
    }
}

template<typename T>
T StackArray<T>::pop() {
    if (!is_empty()) {
        size--;
        T value = arr[size];
        arr[size] = 0;
        return value;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //StackList<int> stk;
    StackVector<int> stk;
    //StackArray<int> stk;
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    stk.push(9);
    stk.push(10);
    stk.push(11);
    std::cout << "Top: " << stk.top() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    int size = stk.get_count();
    std::cout << "Size: " << size << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Element: " << stk.pop() << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Try pop empty: " << stk.pop() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    stk.push(12);
    stk.push(13);
    stk.push(14);
    stk.push(15);
    std::cout << "Top: " << stk.top() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    size = stk.get_count();
    std::cout << "Size: " << size << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Element: " << stk.pop() << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Try pop empty: " << stk.pop() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}
