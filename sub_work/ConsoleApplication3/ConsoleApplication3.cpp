#include <iostream>
using namespace std;


void ShowArray(const int* const arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
    }
}
void push_forward(int*& arr, int& size, int value) {
    size++;
    int* newArray = new int[size + 1];
    newArray[0] = value;
    for (int i = 1; i < size; i++) {
        newArray[i] = arr[i - 1];
    }
    delete[] arr;
    arr = newArray;
}

int main()
{
    setlocale(LC_ALL, "RU");
    

    return 0;
}
