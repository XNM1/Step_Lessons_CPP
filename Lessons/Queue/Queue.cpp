// Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

template<typename T>
struct NodeList {
    T value;
    NodeList<T>* next;
    NodeList<T>* prev;

    NodeList(T value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template<typename T>
class QueueList {
private:
    NodeList<T>* head;
    NodeList<T>* tail;
    int count;
private:
    void create_first(T value);
public:
    QueueList();
    QueueList(T value);
    ~QueueList();
    T& peek();
    int get_count();
    bool is_empty();
    void enqueue(T value);
    T dequeue();
};

template<typename T>
QueueList<T>::QueueList() : head{ nullptr }, tail{ nullptr }, count{ 0 } {}

template<typename T>
QueueList<T>::QueueList(T value) : count{ 0 } {
    create_first(value);
}

template<typename T>
void QueueList<T>::create_first(T value) {
    head = tail = new NodeList<T>(value);
    count++;
}

template<typename T>
QueueList<T>::~QueueList() {
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
int QueueList<T>::get_count() {
    return count;
}

template<typename T>
bool QueueList<T>::is_empty() {
    return count == 0;
}

template<typename T>
T& QueueList<T>::peek() {
    return head->value;
}

template<typename T>
void QueueList<T>::enqueue(T value) {
    if (is_empty()) {
        create_first(value);
    }
    else {
        NodeList<T>* new_node = new NodeList<T>(value);
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        count++;
    }
}

template<typename T>
T QueueList<T>::dequeue() {
    if (!is_empty()) {
        T value = head->value;
        NodeList<T>* tmp = head;
        if (count > 1) {
            head = head->next;
            head->prev = nullptr;
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

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
class QueueVector {
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
    void shift();
public:
    QueueVector();
    QueueVector(int);
    ~QueueVector();
    T& peek();
    int get_count();
    bool is_empty();
    void enqueue(T);
    T dequeue();
};

template<typename T>
void QueueVector<T>::check_capacity() {
    if (capacity < size + 3) {
        reserve();
    }
    else if (capacity - (rate + 20) > size) {
        shrink_to_fit();
    }
}

template<typename T>
void QueueVector<T>::reserve() {
    capacity += rate;
    reall();
}

template<typename T>
void QueueVector<T>::shrink_to_fit() {
    capacity = size < capacity - rate ? capacity - rate : capacity;
    reall();
}

template<typename T>
void QueueVector<T>::reall() {
    T* new_arr = new T[capacity];
    copy(new_arr, arr);
    delete[] arr;
    arr = new_arr;
}

template<typename T>
void QueueVector<T>::copy(T new_array[], T old_array[]) {
    for (int i = 0; i < size; ++i) {
        new_array[i] = old_array[i];
    }
}


template<typename T>
void QueueVector<T>::shift() {
    for (int i = 0; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0;
}

template<typename T>
QueueVector<T>::QueueVector() : size{ 0 }, rate{ 15 }
{
    capacity = rate;
    arr = new T[capacity];
}

template<typename T>
QueueVector<T>::QueueVector(int _size) : size{ 0 }, rate{ 15 }
{
    capacity = _size + rate;
    arr = new T[capacity];
}

template<typename T>
QueueVector<T>::~QueueVector() {
    delete[] arr;
}

template<typename T>
T& QueueVector<T>::peek() {
    return arr[0];
}

template<typename T>
int QueueVector<T>::get_count() {
    return size;
}

template<typename T>
bool QueueVector<T>::is_empty() {
    return size == 0;
}

template<typename T>
void QueueVector<T>::enqueue(T value) {
    size++;
    check_capacity();
    arr[size - 1] = value;
}

template<typename T>
T QueueVector<T>::dequeue() {
    if (!is_empty()) {
        T value = arr[0];
        shift();
        size--;
        check_capacity();
        return value;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
class QueueArray {
private:
    int size;
    int max_size;
    T* arr;
private:
    void shift();
public:
    QueueArray();
    QueueArray(int);
    ~QueueArray();
    T& peek();
    int get_count();
    bool is_empty();
    bool is_full();
    void enqueue(T);
    T dequeue();
};

template<typename T>
QueueArray<T>::QueueArray(int max_size) : max_size{ max_size }, size{ 0 }
{
    arr = new T[max_size];
}

template<typename T>
QueueArray<T>::QueueArray() : QueueArray{ 20 } {}

template<typename T>
QueueArray<T>::~QueueArray() {
    delete[] arr;
}

template<typename T>
void QueueArray<T>::shift() {
    for (int i = 0; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = 0;
}

template<typename T>
T& QueueArray<T>::peek() {
    return arr[0];
}

template<typename T>
int QueueArray<T>::get_count() {
    return size;
}

template<typename T>
bool QueueArray<T>::is_empty() {
    return size == 0;
}

template<typename T>
bool QueueArray<T>::is_full() {
    return size == max_size;
}

template<typename T>
void QueueArray<T>::enqueue(T value) {
    if (!is_full()) {
        size++;
        arr[size - 1] = value;
    }
}

template<typename T>
T QueueArray<T>::dequeue() {
    if (!is_empty()) {
        T value = arr[0];
        shift();
        size--;
        return value;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<typename T>
struct NodeListStack {
    T value;
    NodeListStack<T>* next;

    NodeListStack(T value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

template<typename T>
class StackList {
private:
    NodeListStack<T>* head;
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
    head = new NodeListStack<T>(value);
    count++;
}

template<typename T>
StackList<T>::~StackList() {
    NodeListStack<T>* elm = head;
    while (elm != nullptr)
    {
        NodeListStack<T>* next = elm->next;
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
        NodeListStack<T>* new_node = new NodeListStack<T>(value);
        new_node->next = head;
        head = new_node;
        count++;
    }
}

template<typename T>
T StackList<T>::pop() {
    if (!is_empty()) {
        T value = head->value;
        NodeListStack<T>* tmp = head;
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

template<typename T>
class QueueStack {
private:
    StackList<T> s1;
    StackList<T> s2;
public:
    void enqueue(T);
    T dequeue();
};

template<typename T>
void QueueStack<T>::enqueue(T value) {
    s1.push(value);
}

template<typename T>
T QueueStack<T>::dequeue() {
    while (!s1.is_empty())
    {
        s2.push(s1.pop());
    }
    return s2.pop();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    QueueList<int> que;
    //QueueVector<int> que;
    //QueueArray<int> que;
    //QueueStack<int> que;
    que.enqueue(5);
    que.enqueue(6);
    que.enqueue(7);
    que.enqueue(8);
    que.enqueue(9);
    que.enqueue(10);
    que.enqueue(11);
    std::cout << "Peek: " << que.peek() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    int size = que.get_count();
    std::cout << "Size: " << size << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Element: " << que.dequeue() << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Try dequeue empty: " << que.dequeue() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    que.enqueue(12);
    que.enqueue(13);
    que.enqueue(14);
    que.enqueue(15);
    std::cout << "Peek: " << que.peek() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    size = que.get_count();
    std::cout << "Size: " << size << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "Element: " << que.dequeue() << std::endl;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "Try dequeue empty: " << que.dequeue() << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;

    //que.enqueue(5);
    //que.enqueue(6);
    //que.enqueue(7);
    //que.enqueue(8);
    //que.enqueue(9);
    //que.enqueue(10);
    //que.enqueue(11);
    //int v;
    //do
    //{
    //    v = que.dequeue();
    //    std::cout << "Element: " << v << std::endl;
    //} while (v != 1);
    //std::cout << "---------------------------------------------" << std::endl;
    //std::cout << "Try dequeue empty: " << que.dequeue() << std::endl;
    //std::cout << "---------------------------------------------" << std::endl;
    //std::cout << "---------------------------------------------" << std::endl;
    //que.enqueue(12);
    //que.enqueue(13);
    //que.enqueue(14);
    //que.enqueue(15);
    //do
    //{
    //    v = que.dequeue();
    //    std::cout << "Element: " << v << std::endl;
    //} while (v != 1);
    //std::cout << "---------------------------------------------" << std::endl;
    //std::cout << "Try dequeue empty: " << que.dequeue() << std::endl;
    //std::cout << "---------------------------------------------" << std::endl;
    //std::cout << "---------------------------------------------" << std::endl;
}
