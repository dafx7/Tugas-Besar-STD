# Sistem Pengelolaan Mahasiswa dan Mata Kuliah
Proyek ini adalah implementasi sistem pengelolaan mahasiswa dan mata kuliah menggunakan
struktur data **Multilist** dalam bahasa C++. Sistem ini mencakup fitur-fitur seperti menambah,
menghapus, dan mencari data mahasiswa, serta mengelola relasi antara mahasiswa dan mata
kuliah.
## Fitur Utama
### 1. Pengelolaan Mahasiswa
- Menambahkan data mahasiswa (depan atau belakang).
- Menampilkan semua data mahasiswa.
- Mencari data mahasiswa berdasarkan NIM.
- Mengubah data mahasiswa.
- Menghapus mahasiswa (termasuk relasi mata kuliahnya).
### 2. Pengelolaan Mata Kuliah
- Inisialisasi daftar mata kuliah default.
- Menambahkan data mata kuliah ke mahasiswa tertentu.
- Menampilkan semua mata kuliah.
- Mengubah data mata kuliah.
- Menghapus mata kuliah dari mahasiswa tertentu.
### 3. Relasi Mahasiswa-Mata Kuliah
- Menampilkan semua data mahasiswa beserta daftar mata kuliahnya.
- Mencari mata kuliah tertentu pada mahasiswa tertentu.
- Menghitung total SKS yang diambil mahasiswa.
## Struktur Data
- **Parent**: Mahasiswa disimpan dalam bentuk Double Linked List (DLL).
- **Child**: Mata kuliah disimpan dalam bentuk Single Linked List (SLL).
- **Relasi**: Relasi antara mahasiswa dan mata kuliah disimpan dalam Single Linked List (SLL).
## Teknologi yang Digunakan
- **Bahasa Pemrograman**: C++
- **IDE**: Code::Blocks, Visual Studio Code, atau editor lainnya.
## File dan Struktur Direktori
- **`main.cpp`**: File utama untuk menjalankan program dan menu.
- **`MLL.h`**: Header file yang berisi definisi struktur data dan deklarasi fungsi.
- **`MLL.cpp`**: Implementasi fungsi-fungsi yang mendukung sistem.
- **`README.md`**: Dokumentasi proyek (file ini).
## Cara Menjalankan Program
1. Clone repository ini ke komputer Anda:
```bash
git clone <repository-url>
```
2. Buka project di IDE atau editor pilihan Anda.
3. Pastikan file `main.cpp`, `MLL.h`, dan `MLL.cpp` berada di direktori yang sama.
4. Compile dan jalankan program.
## Contoh Menu Program
Berikut adalah contoh menu yang ditampilkan saat program dijalankan:
```text
===== Menu Utama =====
1. Tambah Mahasiswa
2. Tampilkan Semua Mahasiswa
3. Cari Mahasiswa
4. Tambah Mata Kuliah ke Mahasiswa
5. Tampilkan Semua Data Mahasiswa dan Mata Kuliahnya
6. Cari Mata Kuliah pada Mahasiswa Tertentu
7. Hapus Mata Kuliah pada Mahasiswa Tertentu
8. Ubah Data Mahasiswa
9. Ubah Data Mata Kuliah
10. Hitung Total SKS Mahasiswa
11. Tambah Mata Kuliah (Insert Last)
12. Tampilkan Semua Mata Kuliah
0. Keluar
```
## Inisialisasi Data Mata Kuliah
Program secara otomatis menginisialisasi daftar mata kuliah berikut:
| Nama Mata Kuliah | Kode | SKS |
|------------------------------------|-------|-----|
| Algoritma dan Pemrograman | IF101 | 3 |
| Struktur Data | IF102 | 4 |
| Basis Data | IF103 | 3 |
| Jaringan Komputer | IF104 | 3 |
| Pemrograman Berorientasi Objek | IF105 | 3 |
| Sistem Operasi | IF106 | 4 |
| Kecerdasan Buatan | IF107 | 3 |
| Rekayasa Perangkat Lunak | IF108 | 3 |
| Pemrograman Mobile | IF109 | 3 |
| Manajemen Proyek TI | IF110 | 2 |
## Catatan
- Pastikan program dikompilasi dengan compiler C++ yang mendukung C++11 atau lebih baru.
- Struktur data dan relasi telah diuji untuk memastikan integritas data saat ditambah, dihapus, atau
dimodifikasi.
## Lisensi
Proyek ini tidak menggunakan lisensi khusus. Gunakan sesuai kebutuhan Anda.
