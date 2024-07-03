#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int result = -1;

        for (int i = 0; i < n; i++){
            if (arr[i] == x){
                result = i;
                break;
            }
        }

        if ( result != -1){
            cout << "Angka ditemukan di indeks ke-" << result << endl;
        }else{
            cout << "Angka tidak ditemukan" << endl;
        }

    return 0;
}