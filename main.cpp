#include "MLL.h"
#include <iostream>
using namespace std;

void initMataKuliah(ListChild &childList) {
    infotypemataKuliah mataKuliahData[10] = {
        {"Algoritma dan Pemrograman", "IF101", 3},
        {"Struktur Data", "IF102", 4},
        {"Basis Data", "IF103", 3},
        {"Jaringan Komputer", "IF104", 3},
        {"Pemrograman Berorientasi Objek", "IF105", 3},
        {"Sistem Operasi", "IF106", 4},
        {"Kecerdasan Buatan", "IF107", 3},
        {"Rekayasa Perangkat Lunak", "IF108", 3},
        {"Pemrograman Mobile", "IF109", 3},
        {"Manajemen Proyek TI", "IF110", 2}
    };

    for (int i = 0; i < 10; i++) {
        address_child newMataKuliah = createNewElmMataKuliah(mataKuliahData[i]);
        next(newMataKuliah) = first(childList);
        first(childList) = newMataKuliah;
    }
}

int main() {
    ListParent mahasiswaList;
    ListRelasi relasiList;
    ListChild mataKuliahList;

    // Inisialisasi list kosong
    first(mahasiswaList) = NULL;
    last(mahasiswaList) = NULL;
    first(relasiList) = NULL;
    first(mataKuliahList) = NULL;

    // Inisialisasi data awal mata kuliah
    initMataKuliah(mataKuliahList);

    // Panggil menu utama
    mainMenu();

    return 0;
}
