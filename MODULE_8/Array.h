#pragma once
#include "NewExceptions.h"
template<typename T>
class Array
{
private:
    T* _arr = nullptr; //указатель для выделения памяти под массив
    int _size = 0; //размер массива
    int _count = 0; //фактическое кол-во элементов
public:
    // КОНСТРУКТОРЫ И ДЕСТРУКТОР
    Array(Array&);
    Array();
    Array(int size);
    Array(int size, T value);
    ~Array();

    bool isEmpty();
    bool isFull();

    int getSize() const;
    int getCount() const;

    void showSize() const;
    void showCount() const;

    void printArr();
    void resize(int size);
    void erase();
    //ФУНКЦИИ УДАЛЕНИЯ ЭЛЕМЕНТА
    void removeElement();
    void removeBeginElement();
    void removeByIndex(int index);
    //ФУНКЦИИ ДОБАВЛЕНМЯ ЭЛЕМЕНТА
    void addElement(T value);
    void addBeginElement(T value);
    void addByIndex(T value, int index);

    void copyContainer(T arr[], int arr_size);
    void copyContainer(Array& other);

    T& operator[](int index);
    Array& operator=(const Array& A);
};

