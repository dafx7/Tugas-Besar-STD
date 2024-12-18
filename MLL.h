#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define child(P) P->child
#define parent(P) P->parent

struct mahasiswa {
    string nama, nim, kelas, gender;
};

struct mataKuliah {
    string nama, kode;
    int sks;
};

typedef mahasiswa infotypeMahasiswa;
typedef mataKuliah infotypemataKuliah;
typedef struct elmList_parent *address_parent;
typedef struct elmList_child *address_child;
typedef struct elmList_relasi *address_relasi;

// Struktur Child: Single Linked List (SLL)
struct elmList_child {
    infotypemataKuliah info;
    address_child next;
};

struct ListChild {
    address_child first;
};

// Struktur Parent: Double Linked List (DLL)
struct elmList_parent {
    infotypeMahasiswa info;
    address_parent next;
    address_parent prev;
};

struct ListParent {
    address_parent first;
    address_parent last;
};

// Struktur Relasi: Single Linked List (SLL)
struct elmList_relasi {
    address_relasi next;
    address_parent parent;
    address_child child;
};

struct ListRelasi {
    address_relasi first;
};


address_parent createNewElmMahasiswa(infotypeMahasiswa x);
address_child createNewElmMataKuliah(infotypemataKuliah x);

// a. Insert data mahasiswa dari depan/belakang
void insertMahasiswaDepan(ListParent &L, address_parent P);
void insertMahasiswaBelakang(ListParent &L, address_parent P);

// b. Show semua data mahasiswa
void showAllMahasiswa(ListParent L);

// c. Hapus mahasiswa beserta mata kuliahnya
void deleteMahasiswa(ListParent &L, ListRelasi &relasi, string nim);

// d. Cari data mahasiswa
address_parent searchMahasiswa(ListParent L, string nim);

// e. Insert data mata kuliah untuk mahasiswa tertentu
void insertMataKuliah(ListRelasi &relasi, ListChild &childList, ListParent &L, string nim, infotypemataKuliah dataMataKuliah);

// f. Ubah data mahasiswa atau mata kuliah
void updateMahasiswa(ListParent &L, string nim, infotypeMahasiswa newData);
void updateMataKuliah(ListChild &childList, string namaMataKuliah, infotypemataKuliah newData);

// g. Tampilkan semua data mahasiswa dengan mata kuliahnya
void showAllData(ListParent L, ListRelasi relasi);

// h. Cari mata kuliah tertentu pada mahasiswa tertentu
address_child searchMataKuliahOnMahasiswa(ListRelasi relasi, ListParent L, string nim, string namaMataKuliah);

// i. Hapus mata kuliah pada mahasiswa tertentu
void deleteMataKuliah(ListRelasi &relasi, ListChild &childList, ListParent &L, string nim, string namaMataKuliah);

// j. Hitung total SKS yang diambil mahasiswa
int totalSKS(ListRelasi relasi, ListParent L, string nim);

// k. Main program untuk mengelola fitur-fitur
void mainMenu();

#endif // MLL_H_INCLUDED
