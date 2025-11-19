#include <iostream>
using namespace std;

void reverseArray(int* arr, int size) {
    // TODO
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter size: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter " << size << " numbers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal: ";
    printArray(arr, size);

    reverseArray(arr, size);

    cout << "Reversed: ";
    printArray(arr, size);

    delete[] arr;
    return 0;
}
