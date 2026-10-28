#include "NumberArray.h"
#include <iostream>

using namespace std;

const double NumberArray::SAFE_DEFAULT = 0.0;

NumberArray::NumberArray(int s) {
    if (s <= 0) {
        size = MAX_SIZE;
    }
    else {
        size = s;
    }
    data = new double[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0.0;
    }
}

NumberArray::~NumberArray() {
    delete[] data;
    data = nullptr;
    cout << "[Destructor] Dynamic memory freed for NumberArray." << endl;
}

