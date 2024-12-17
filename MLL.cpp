#include "MLL.h"

address_parent createNewElmMahasiswa(infotypeMahasiswa x) {
    address_parent newNode = new elmList_parent;
    info(newNode) = x; // Tidak ada error, tipe data cocok
    next(newNode) = NULL;
    prev(newNode) = NULL;

    return newNode;
}


// a. Insert data mahasiswa dari depan
void insertMahasiswaDepan(ListParent &L, address_parent P) {
    if (first(L) == NULL) { // Jika list kosong
        first(L) = P;
        last(L) = P;
    } else { // Jika list tidak kosong
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

// a. Insert data mahasiswa dari belakang
void insertMahasiswaBelakang(ListParent &L, address_parent P) {
    if (first(L) == NULL) { // Jika list kosong
        first(L) = P;
        last(L) = P;
    } else { // Jika list tidak kosong
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}


// b. Show semua data mahasiswa
void showAllMahasiswa(const ListParent &L) {
    if (first(L) == NULL) {
        cout << "Tidak ada data mahasiswa." << endl;
        return;
    }

    cout << "===== Data Mahasiswa =====" << endl;
    address_parent current = first(L);
    int i = 1; // Untuk nomor urut

    while (current != NULL) {
        cout << i << ". Nama   : " << info(current).nama << endl;
        cout << "   NIM    : " << info(current).nim << endl;
        cout << "   Kelas  : " << info(current).kelas << endl;
        cout << "   Gender : " << info(current).gender << endl;
        cout << "--------------------------" << endl;

        current = next(current);
        i++;
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
