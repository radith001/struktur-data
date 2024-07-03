#include <iostream>

using namespace std;

int main() {

    int arr[7] = {1, 2, 5, 7, 9, 11, 13};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    int i = 0;

    while (i < size && arr [i] != x) {
        i++;
    }

    if (i < size) {
        cout << "Elemen ditemukan di indeks: " << i << endl;
    } else {
        cout << "Elemen tidak ditemukan" << endl;
    }

    return 0;
}