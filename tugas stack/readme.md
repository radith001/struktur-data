## Penjelasan Program:

**1. Library yang Digunakan:**

- iostream: Untuk input dan output standar.
- stack: Untuk menggunakan struktur data stack.
- string: Untuk menangani operasi string.

**2. Fungsi displayMenu:**
Menampilkan menu operasi yang bisa dilakukan oleh pengguna.

**3. Fungsi main:**

- Membuat objek stack<string> untuk menyimpan tumpukan buku.
- Menampilkan menu dan meminta input pengguna untuk memilih operasi.
- Berdasarkan input, program melakukan operasi yang sesuai pada stack:

    - push: Menambahkan buku ke tumpukan.
    - pop: Menghapus buku teratas dari tumpukan.
    - peek: Melihat buku teratas tanpa menghapusnya.
    - isEmpty: Mengecek apakah tumpukan kosong.
    - size: Menampilkan jumlah buku dalam tumpukan.
    - exit: Keluar dari program.

Program ini akan terus meminta input pengguna sampai pengguna memilih untuk keluar (pilihan 6).