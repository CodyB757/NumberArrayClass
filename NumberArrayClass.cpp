#include "NumberArray.h"
#include <iostream>

using namespace std;

const double NumberArray::SAFE_DEFAULT = 0.0;

void NumberArray::setNumber(int index, double value) {
    if (index >= 0 && index < size) {
        data[index] = value;
    }
    else {
        cout << "[Error] Index " << index << " out of bounds." << endl;
    }
}

double NumberArray::getNumber(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    cout << "[Error] Index " << index << " out of bounds. Returning safe default." << endl;
    return SAFE_DEFAULT;
}

int NumberArray::getSize() const {
    return size;
}

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

