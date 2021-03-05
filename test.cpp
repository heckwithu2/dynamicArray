#include <iostream>
#include <fstream>
#include "dynamicArray.hpp"

int main(int argc, char* argv[]) {

    int x = 100;

    dynamicArray<int> hundred(x);
    //hundred.print();

    for (int i = 0; hundred.getSize() > i; ++i) {
        hundred.set(i, i);
    } hundred.print();
}