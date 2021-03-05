/**
* JEREMIAH HECK
* dynamic array Class
*/


#ifndef DYNAMICARRAY_HPP_
#define DYNAMICARRAY_HPP_

#include <iostream>
#include <fstream>

template <typename T>
class dynamicArray {
private:
    int size_;
    T *array = nullptr;
public: 
    dynamicArray();
    dynamicArray(int&);//size and type of arrray?
    dynamicArray(const int&);//size and type of arrray?
    //dynamicArray(const T[]&);//sizeof?

    ~dynamicArray();//destructor
    dynamicArray<T>& operator=(dynamicArray<T>&); //assignment operator
    dynamicArray(const dynamicArray<T>&); // copy constructor
    dynamicArray(const dynamicArray&& ) noexcept; // move constructor

    void print();
    T get(int&) const; //accessor
    int getSize() const; //accessor
    void set(int&, T); //mutator
    T change(const int&); //change size of array

};


template <typename T>
dynamicArray<T>::dynamicArray() {
    size_ = 0;
    array = nullptr;
}

template <typename T>
dynamicArray<T>::dynamicArray(int &size) {
    size_ = size;
    array = new T[size_] {0};
}

template <typename T>
dynamicArray<T>::dynamicArray(const int &size) {
    size_ = size;
    array = new T[size_] {0};
}


template <typename T>
dynamicArray<T>::dynamicArray(const dynamicArray<T>& copy) {
    //protect against self assignment
    if (this != &copy) {
        size_ = copy.size_;
        array = new T[size_] {0};
        std::cout << "Copy Constructor.";
    }
}

template <typename T>
dynamicArray<T>::dynamicArray(const dynamicArray<T>&& copy) noexcept {
    //protect against self assignment
    if (this != &copy) {
        size_ = copy.size_;
        array = copy.array; //move constructor, just move the pointer

        //since you stole the "copies" pointer, here we must set to mullptr
        copy.array = nullptr;

        std::cout << "Move Constructor.";
    }
}

template <typename T>
dynamicArray<T>::~dynamicArray() {
    delete [] array;
    array = nullptr;
    std::cout << "Destructor, array!";
}

template <typename T>
T dynamicArray<T>::change(const int &size) {
    delete [] array;
    array = nullptr;

    size_ = size;
    array = new T[size_] {0};
    return array;
}

template <typename T>
dynamicArray<T>& dynamicArray<T>::operator=(dynamicArray<T>& copy) {
    //protect against self assignment
    if (this != &copy) {
        delete [] array;
        array = nullptr;

        size_ = copy.size_;
        this(size_);
        return *this;
    } else return *this;
}


template <typename T>
T dynamicArray<T>::get(int& index) const {
    if (size_ >= index) {
        auto value = array[index];
        return value;
    }
}

template <typename T>
int dynamicArray<T>::getSize() const {
    return size_;
}

template <typename T>
void dynamicArray<T>::print() {
    for (int i = 0; i < size_; ++i) {
        std::cout << get(i) << std::endl;
    }
}

template <typename T>
void dynamicArray<T>::set(int& index, T elementToChange) {
    if (size_ >= index) {
       array[index] = elementToChange;
    }
}
#endif