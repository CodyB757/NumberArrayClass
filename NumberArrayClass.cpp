#include "NumberArray.h"
#include <iostream>
#include <iomanip>

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

double NumberArray::getMin() const {
    if (size == 0) return SAFE_DEFAULT;
    double minVal = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] < minVal) {
            minVal = data[i];
        }
    }
    return minVal;
}

double NumberArray::getMax() const {
    if (size == 0) return SAFE_DEFAULT;
    double maxVal = data[0];
    for (int i = 1; i < size; ++i) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    return maxVal;
}

double NumberArray::getAverage() const {
    if (size == 0) return SAFE_DEFAULT;
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum / size;
}

void NumberArray::print() const {
    cout << "[ ";
    for (int i = 0; i < size; ++i) {
        cout << fixed << setprecision(2) << data[i] << (i < size - 1 ? ", " : "");
    }
    cout << " ]" << endl;
}

int NumberArray::getSize() const {
    return size;
}