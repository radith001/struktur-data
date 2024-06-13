#include <iostream>
#include <stack>
#include <string>

using namespace std;

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Push (Tambah Buku)\n";
    cout << "2. Pop (Hapus Buku Teratas)\n";
    cout << "3. Peek (Lihat Buku Teratas)\n";
    cout << "4. isEmpty (Cek Apakah Tumpukan Kosong)\n";
    cout << "5. Size (Lihat Jumlah Buku dalam Tumpukan)\n";
    cout << "6. Exit (Keluar)\n";
    cout << "Pilih operasi yang ingin dilakukan: ";
}

int main() {
    stack<string> bookStack;
    int choice;
    string book;

    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Masukkan judul buku yang ingin ditambahkan: ";
                cin.ignore(); 
                getline(cin, book);
                bookStack.push(book);
                cout << "Buku \"" << book << "\" telah ditambahkan ke tumpukan.\n";
                break;
            case 2:
                if (bookStack.empty()) {
                    cout << "Tumpukan kosong, tidak ada buku yang bisa dihapus.\n";
                } else {
                    cout << "Buku \"" << bookStack.top() << "\" telah dihapus dari tumpukan.\n";
                    bookStack.pop();
                }
                break;
            case 3:
                if (bookStack.empty()) {
                    cout << "Tumpukan kosong, tidak ada buku yang bisa dilihat.\n";
                } else {
                    cout << "Buku teratas di tumpukan: \"" << bookStack.top() << "\"\n";
                }
                break;
            case 4:
                if (bookStack.empty()) {
                    cout << "Tumpukan kosong.\n";
                } else {
                    cout << "Tumpukan tidak kosong.\n";
                }
                break;
            case 5:
                cout << "Jumlah buku dalam tumpukan: " << bookStack.size() << "\n";
                break;
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
