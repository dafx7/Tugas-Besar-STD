#include "MLL.h"

// a. Insert data mahasiswa dari depan
void insertMahasiswaDepan(ListParent &L, infotypeMahasiswa dataMahasiswa) {
    address_parent newNode = new elmList_parent;
    info(newNode) = dataMahasiswa;
    next(newNode) = nullptr;
    prev(newNode) = nullptr;

    if (first(L) == nullptr) { // Jika list kosong
        first(L) = newNode;
        last(L) = newNode;
    } else { // Jika list tidak kosong
        next(newNode) = first(L);
        prev(first(L)) = newNode;
        first(L) = newNode;
    }
}

// a. Insert data mahasiswa dari belakang
void insertMahasiswaBelakang(ListParent &L, infotypeMahasiswa dataMahasiswa) {
    address_parent newNode = new elmList_parent;
    info(newNode) = dataMahasiswa;
    next(newNode) = nullptr;
    prev(newNode) = nullptr;

    if (first(L) == nullptr) { // Jika list kosong
        first(L) = newNode;
        last(L) = newNode;
    } else { // Jika list tidak kosong
        prev(newNode) = last(L);
        next(last(L)) = newNode;
        last(L) = newNode;
    }
}

// b. Show semua data mahasiswa
void showAllMahasiswa(ListParent L) {
    if (first(L) == nullptr) {
        cout << "Tidak ada data mahasiswa." << endl;
        return;
    }

    address_parent current = first(L);
    while (current != nullptr) {
        cout << "Nama: " << info(current).nama
             << " | NIM: " << info(current).nim << endl;
        current = next(current);
    }
}

// d. Cari data mahasiswa
address_parent searchMahasiswa(ListParent L, string nim);

// e. Insert data mata kuliah untuk mahasiswa tertentu
void insertMataKuliah(ListRelasi &relasi, ListChild &childList, ListParent &L, string nim, infotypemataKuliah dataMataKuliah);

// f. Ubah data mahasiswa atau mata kuliah
void updateMahasiswa(ListParent &L, string nim, infotypeMahasiswa newData);
void updateMataKuliah(ListChild &childList, string namaMataKuliah, infotypemataKuliah newData);

// g. Tampilkan semua data mahasiswa dengan mata kuliahnya
void showAllData(ListParent L, ListRelasi relasi, ListChild childList);

// h. Cari mata kuliah tertentu pada mahasiswa tertentu
address_child searchMataKuliahOnMahasiswa(ListRelasi relasi, ListParent L, string nim, string namaMataKuliah);

// i. Hapus mata kuliah pada mahasiswa tertentu
void deleteMataKuliah(ListRelasi &relasi, ListChild &childList, ListParent &L, string nim, string namaMataKuliah);

// j. Hitung total SKS yang diambil mahasiswa
int totalSKS(ListRelasi relasi, ListParent L, string nim);

// k. Main program untuk mengelola fitur-fitur
void mainMenu();
