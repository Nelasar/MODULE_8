#pragma once
#include "NewExceptions.h"
template<typename T>
class Array
{
private:
    T* _arr = nullptr; //��������� ��� ��������� ������ ��� ������
    int _size = 0; //������ �������
    int _count = 0; //����������� ���-�� ���������
public:
    // ������������ � ����������
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
    //������� �������� ��������
    void removeElement();
    void removeBeginElement();
    void removeByIndex(int index);
    //������� ���������� ��������
    void addElement(T value);
    void addBeginElement(T value);
    void addByIndex(T value, int index);

    void copyContainer(T arr[], int arr_size);
    void copyContainer(Array& other);

    T& operator[](int index);
    Array& operator=(const Array& A);
};

