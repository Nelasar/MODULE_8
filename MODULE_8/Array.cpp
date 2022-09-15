#include "Array.h"
// ŒÕ—“–” “Œ–€ » ƒ≈—“–” “Œ–
template <typename T> Array<T>::Array() = default;
template <typename T> Array<T>::Array(int size) : _size(size), _count(0) {
    try {
        if (size < 0) {
            throw bad_length();
        }
        _arr = new T[size];
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
template <typename T> Array<T>::Array(int size, T value) : _size(size), _count(size) {
    try {
        if (size < 0) {
            throw bad_length();
        }

        _arr = new T[size];
        for (int i = 0; i < _size; i++) {
            _arr[i] = value;
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
template <typename T> Array<T>::~Array() {
    delete[] _arr;
}
template <typename T> Array<T>::Array(Array& obj) {
    _arr = new T[obj._size];

    for (int i = 0; i < obj._size; i++) {
        _arr[i] = obj._arr[i];
    }

    _size = obj._size;
    _count = obj._count;
}


template<typename T> bool Array<T>::isEmpty() { return _count == 0; } //œ–Œ¬≈–ﬂ≈Ã¡ œ”—“Œ… À»  ŒÕ“≈…Õ≈–
template<typename T> bool Array<T>::isFull() { return _count == _size; }//œ–Œ¬≈–ﬂ≈Ã, œŒÀÕ€… À»  ŒÕ“≈…Õ≈–

template<typename T> int Array<T>::getSize() const { return _size; }
template<typename T> int Array<T>::getCount() const { return _count; }

template<typename T> void Array<T>::showSize() const { std::cout << "Size of the container: " << _size << std::endl; }
template<typename T> void Array<T>::showCount() const { std::cout << "There are " << _count << " elements in the container" << std::endl << std::endl; }

template<typename T> void Array<T>::printArr() {
    for (int i = 0; i < _size; i++) {
        std::cout << _arr[i] << ' ';
    }
    std::cout << std::endl;
}
template<typename T> void Array<T>::resize(int size) {
    if (_size = size) {
        return;
    }
    try {
        if (size <= 0) {
            throw bad_length();
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    T* temp_arr = new T[size];

    if (_size > size) {
        for (int i = 0; i < size - size; i++) {
            temp_arr[i] = _arr[i];

            _arr = new T[size];

            for (int i = 0; i < size; i++) {
                _arr[i] = temp_arr[i];
            }
        }
    }
    else {
        for (int i = 0; i < _size; i++) {
            temp_arr[i] = _arr[i];
        }

        _arr = new T[size];

        for (int i = 0; i < _size; i++) {
            _arr[i] = temp_arr[i];
        }
        for (int i = _size; i < size; i++) {
            _arr[i] = 0;
        }
    }

    delete[] temp_arr;

    _size = size;
}
template<typename T> void Array<T>::erase() {
    delete[] _arr;
    _arr = nullptr;
    _size = 0;
    _count = 0;
}
//‘”Õ ÷»» ”ƒ¿À≈Õ»ﬂ ›À≈Ã≈Õ“¿
template<typename T> void Array<T>::removeElement() {
    try {
        if (isEmpty()) {
            throw bad_range();
        }
        if (_count == 1) {
            erase();
            return;
        }

        _arr[_count - 1] = 0;
        --_count;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
template<typename T> void Array<T>::removeBeginElement() {
    try {
        if (isEmpty()) {
            throw bad_range();
        }
        if (_count == 1) {
            _arr[0] = 0;
            --_count;
        }
        else {
            _arr[0] = 0;

            for (int i = 1; i < _count; i++) {
                _arr[i - 1] = _arr[i];
            }
            _arr[--_count] = 0;
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
template<typename T> void Array<T>::removeByIndex(int index) {
    try {
        if (isEmpty()) {
            throw bad_length();
        }
        if (_count > _size) {
            throw bad_range();
        }
        if (index > _size || index <= 0) {
            throw bad_index();
        }

        for (int i = index; i < _size; ++i) {
            _arr[i - 1] = _arr[i];
        }
        _arr[--_count] = 0;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
//‘”Õ ÷»» ƒŒ¡¿¬À≈ÕÃﬂ ›À≈Ã≈Õ“¿
template<typename T> void Array<T>::addElement(T value) {
    try {
        if (isFull()) {
            throw bad_range();

        }
        _arr[_count++] = value;

    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
template<typename T> void Array<T>::addBeginElement(T value) {
    try {
        if (isFull()) {
            throw bad_range();
        }
        for (int i = _size - 1; i >= 0; --i) {
            _arr[i] = _arr[i - 1];
        }

        _arr[0] = value;

        _count++;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
template<typename T> void Array<T>::addByIndex(T value, int index) {
    try {
        if (isFull()) {
            throw bad_range();
        }
        if (index > _size || index == 0) {
            throw bad_index();
        }

        T* temp = new T[_size];
        for (int i = 0; i < _size; i++) {
            temp[i] = _arr[i];
        }
        _arr = new T[_size];

        for (int i = 0; i < index - 1; i++) {
            _arr[i] = temp[i];
        }
        _arr[index - 1] = value;

        for (int i = index; i < _size; i++) {
            _arr[i] = temp[i - 1];
        }

        ++_count;

        delete[] temp;
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
//‘”Õ ÷»»  Œœ»–Œ¬¿Õ»ﬂ
template<typename T> void Array<T>::copyContainer(T arr[], int arr_size) {
    try {
        if (arr_size < _size) {
            throw bad_length();
        }
        for (int i = 0; i < _size; i++) {
            arr[i] = _arr[i];
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}
template<typename T> void Array<T>::copyContainer(Array& other) {
    try {
        if (other.getSize() < _size) {
            throw bad_length();
        }
        for (int i = 0; i < _size; i++) {
            other[i] = _arr[i];
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
//Œœ≈–¿“Œ– »Õƒ≈ —»–Œ¬¿Õ»ﬂ
template<typename T> T& Array<T>::operator[](int index) {
    try {
        if (index < 0 || index >= _size) {
            throw bad_index();
        }
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return _arr[index];
}
//Œœ≈–¿“Œ– œ–»—¬¿»¬¿Õ»ﬂ
template<typename T> Array<T>& Array<T>::operator=(const Array& A)
{
    // ÓÒ‚Ó·Ó‰ËÚ¸ ÔÂ‰‚‡ËÚÂÎ¸ÌÓ ‚˚‰ÂÎÂÌÌÛ˛ Ô‡ÏˇÚ¸
    if (_size > 0) {
        delete[] _arr;
    }

    _size = A._size;
    _arr = new T[_size];

    for (int i = 0; i < _size; i++)
        _arr[i] = A._arr[i];

    return *this;
}