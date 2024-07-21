#include <iostream>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

const char* hostname = "127.0.0.1";
const char* user = "root";
const char* pass = "123";
const char* dbname = "uas_strukdat";
unsigned int port = 31235;
const char* unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connect_db() {
    MYSQL* conn = mysql_init(0);
    if (conn) {
        conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
        if (conn) {
            cout << "Connected to the database successfully." << endl;
        } else {
            cerr << "Connection failed: " << mysql_error(conn) << endl;
        }
    } else {
        cerr << "mysql_init failed" << endl;
    }
    return conn;
}

void create_item(const string& nama_barang, const string& ukuran, const string& harga) {
    MYSQL* conn = connect_db();
    if (conn) {
        string query = "INSERT INTO toko_ikan (nama_barang, ukuran, harga) VALUES ('" + nama_barang + "', '" + ukuran + "', '" + harga + "')";
        if (mysql_query(conn, query.c_str())) {
            cerr << "INSERT failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Item successfully added." << endl;
        }
        mysql_close(conn);
    }
}

void get_items() {
    MYSQL* conn = connect_db();
    if (conn) {
        if (mysql_query(conn, "SELECT * FROM toko_ikan")) {
            cerr << "SELECT failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_RES* res = mysql_store_result(conn);
        if (res == nullptr) {
            cerr << "mysql_store_result failed: " << mysql_error(conn) << endl;
            mysql_close(conn);
            return;
        }

        MYSQL_ROW row;
        while ((row = mysql_fetch_row(res))) {
            cout << "ID: " << row[0] << ", nama_barang: " << row[1] << ", ukuran: " << row[2] << ", harga: " << row[3] << endl;
        }

        mysql_free_result(res);
        mysql_close(conn);
    }
}

void update_item(int item_id, const string& nama_barang, const string& ukuran, const string& harga) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "UPDATE toko_ikan SET nama_barang = '" << nama_barang << "', ukuran = '" << ukuran << "', harga = '" << harga << "' WHERE id = " << item_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "UPDATE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Item successfully updated." << endl;
        }
        mysql_close(conn);
    }
}

void delete_item(int item_id) {
    MYSQL* conn = connect_db();
    if (conn) {
        stringstream query;
        query << "DELETE FROM toko_ikan WHERE id = " << item_id;
        if (mysql_query(conn, query.str().c_str())) {
            cerr << "DELETE failed: " << mysql_error(conn) << endl;
        } else {
            cout << "Item successfully deleted." << endl;
        }
        mysql_close(conn);
    }
}

void show_admin_menu() {
    int choice;
    while (true) {
        cout << "\nAdmin Menu:\n";
        cout << "1. Tambah barang\n";
        cout << "2. Tampilkan semua barang\n";
        cout << "3. Perbarui barang\n";
        cout << "4. Hapus barang\n";
        cout << "5. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 1) {
            string nama_barang, ukuran, harga;
            cout << "Enter Nama Barang: ";
            cin.ignore();
            getline(cin, nama_barang);
            cout << "Enter Ukuran: ";
            getline(cin, ukuran);
            cout << "Enter Harga: ";
            getline(cin, harga);
            create_item(nama_barang, ukuran, harga);
        } else if (choice == 2) {
            get_items();
        } else if (choice == 3) {
            int item_id;
            string nama_barang, ukuran, harga;
            cout << "Enter item ID to update: ";
            cin >> item_id;
            cin.ignore();
            cout << "Enter new Nama Barang: ";
            getline(cin, nama_barang);
            cout << "Enter new Ukuran: ";
            getline(cin, ukuran);
            cout << "Enter new Harga: ";
            getline(cin, harga);
            update_item(item_id, nama_barang, ukuran, harga);
        } else if (choice == 4) {
            int item_id;
            cout << "Enter item ID to delete: ";
            cin >> item_id;
            delete_item(item_id);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

void show_user_menu() {
    int choice;
    while (true) {
        cout << "\nUser Menu:\n";
        cout << "1. Tampilkan semua barang\n";
        cout << "2. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        if (choice == 1) {
            get_items();
        } else if (choice == 2) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    int role_choice;
    cout << "Pilih peran:\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "Masukkan pilihan: ";
    cin >> role_choice;

    if (role_choice == 1) {
        show_admin_menu();
    } else if (role_choice == 2) {
        show_user_menu();
    } else {
        cout << "Invalid role choice." << endl;
    }

    return 0;
}
