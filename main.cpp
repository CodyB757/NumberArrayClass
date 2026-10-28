#include <iostream>
#include "NumberArray.h"

using namespace std;

int main() {
    cout << "=== NUMBERARRAY CLASS TEST DRIVER ===" << endl << endl;

    cout << "-- Test 1: Construction & Default Values --" << endl;
    NumberArray arr1(5);
    cout << "arr1 initial values: ";
    arr1.print();

    cout << "\n-- Test 2: Populate Data & Compute Statistics --" << endl;
    arr1.setNumber(0, 10.5);
    arr1.setNumber(1, 20.0);
    arr1.setNumber(2, 5.5);
    arr1.setNumber(3, 40.0);
    arr1.setNumber(4, 24.0);

    cout << "arr1 populated: ";
    arr1.print();
    cout << "Minimum: " << arr1.getMin() << endl;
    cout << "Maximum: " << arr1.getMax() << endl;
    cout << "Average: " << arr1.getAverage() << endl;

    cout << "\n-- Test 3: Out-of-Bounds Index Protection --" << endl;
    arr1.setNumber(-1, 99.9);
    arr1.setNumber(5, 99.9);
    cout << "Get -1: " << arr1.getNumber(-1) << endl;
    cout << "Get 5:  " << arr1.getNumber(5) << endl;

    cout << "\n-- Test 4: Block-Scoped Destructor Verification --" << endl;
    {
        NumberArray temp(3);
        temp.setNumber(0, 7.5);
        cout << "Temp array created inside scope block." << endl;
    }
    cout << "Exited block scope." << endl;

    return 0;
}