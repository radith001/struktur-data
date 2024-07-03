#include <iostream>
using namespace std;

// Fungsi untuk menukar dua elemen
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Fungsi untuk melakukan Bubble Sort pada array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Bendera untuk memeriksa apakah ada penukaran dalam satu iterasi
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Jika tidak ada elemen yang ditukar, array sudah terurut
        if (!swapped) break;
    }
}

int main() {
    int n;

    // Meminta pengguna untuk memasukkan panjang array
    cout << "Masukkan panjang array: ";
    cin >> n;

    // Mendefinisikan array dengan panjang n
    int arr[n];

    // Meminta pengguna untuk memasukkan elemen-elemen array
    cout << "Masukkan elemen-elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Mengurutkan array menggunakan Bubble Sort
    bubbleSort(arr, n);

    // Mencetak array yang sudah diurutkan
    cout << "Array yang sudah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
