#include "MLL.h"

// Insert data mata kuliah dari belakang
void insertLastMataKuliah(ListChild &childList, address_child P) {
    if (first(childList) == NULL) { // Jika list kosong
        first(childList) = P;
    } else { // Jika list tidak kosong
        address_child current = first(childList);
        while (next(current) != NULL) { // Cari elemen terakhir
            current = next(current);
        }
        next(current) = P;
    }
}

// Tampilkan semua data mata kuliah
void showAllMataKuliah(ListChild childList) {
    if (first(childList) == NULL) { // Jika list kosong
        cout << "Tidak ada data mata kuliah." << endl;
        return;
    }

    cout << "===== Data Mata Kuliah =====" << endl;
    address_child current = first(childList);
    int i = 1; // Nomor urut

    while (current != NULL) {
        cout << i << ". Nama: " << info(current).nama << endl;
        cout << "   Kode: " << info(current).kode << endl;
        cout << "   SKS : " << info(current).sks << endl;
        cout << "-----------------------------" << endl;
        current = next(current);
        i++;
    }
}


address_parent createNewElmMahasiswa(infotypeMahasiswa x) {
    address_parent newNode = new elmList_parent;
    info(newNode) = x; // Tidak ada error, tipe data cocok
    next(newNode) = NULL;
    prev(newNode) = NULL;

    return newNode;
}

address_child createNewElmMataKuliah(infotypemataKuliah x) {
    address_child matakuliah = new elmList_child;
    info(matakuliah) = x;
    next(matakuliah) = NULL;

    return matakuliah;
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
void showAllMahasiswa(ListParent L) {
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
address_parent searchMahasiswa(ListParent L, string nim){
    address_parent P = first(L);
    while (P != NULL) {
        if (info(P).nim == nim) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

// e. Insert data mata kuliah untuk mahasiswa tertentu
void insertMataKuliah(ListRelasi &relasi, ListChild &childList, ListParent &L, string nim, infotypemataKuliah dataMataKuliah) {
    address_parent mahasiswa = searchMahasiswa(L, nim);
    if (mahasiswa == NULL) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        return;
    }

    // Buat node mata kuliah baru jika belum ada di daftar child
    address_child matakuliah = first(childList);
    while (matakuliah != NULL && info(matakuliah).kode != dataMataKuliah.kode) {
        matakuliah = next(matakuliah);
    }
    if (matakuliah == NULL) { // Jika mata kuliah belum ada daftarnya
        matakuliah = createNewElmMataKuliah(dataMataKuliah);
        next(matakuliah) = first(childList);
        first(childList) = matakuliah;
    }

    // Buat node relasi untuk menghubungkan mahasiswa dengan matakuliah
    address_relasi newRelasi = new elmList_relasi;
    parent(newRelasi) = mahasiswa;
    child(newRelasi) = matakuliah;
    next(newRelasi) = first(relasi);
    first(relasi) = newRelasi;
}

// f. Ubah data mahasiswa atau mata kuliah
void updateMahasiswa(ListParent &L, string nim, infotypeMahasiswa newData) {
    address_parent mahasiswa = searchMahasiswa(L, nim);
    if (mahasiswa == NULL) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        return;
    }
    info(mahasiswa).nama = newData.nama;
    info(mahasiswa).kelas = newData.kelas;
    info(mahasiswa).gender = newData.gender;
    cout << "Data mahasiswa dengan NIM " << nim << " berhasil diperbarui." << endl;
}

void updateMataKuliah(ListChild &childList, string namaMataKuliah, infotypemataKuliah newData) {
    address_child matakuliah = first(childList);
    while (matakuliah != NULL && info(matakuliah).nama != namaMataKuliah) {
        matakuliah = next(matakuliah);
    }
    if (matakuliah == NULL) {
        cout << "Mata kuliah " << namaMataKuliah << " tidak ditemukan." << endl;
        return;
    }
    info(matakuliah).nama = newData.nama;
    info(matakuliah).kode = newData.kode;
    info(matakuliah).sks = newData.sks;
    cout << "Data mata kuliah " << namaMataKuliah << " berhasil diperbarui." << endl;
}

// g. Tampilkan semua data mahasiswa dengan mata kuliahnya
void showAllData(ListParent L, ListRelasi relasi) {
    address_parent M = first(L);
    if (M == NULL) {
        cout << "Tidak ada data mahasiswa." << endl;
        return;
    }

    while (M != NULL) {
        cout << "Nama Mahasiswa: " << info(M).nama << endl;
        cout << "NIM: " << info(M).nim << endl;
        cout << "Kelas: " << info(M).kelas << endl;
        cout << "Gender: " << info(M).gender << endl;

        cout << "List Mata Kuliah: " << endl;
        bool hasMataKuliah = false;

        address_relasi rel = first(relasi);
        while (rel != NULL) {
            if (parent(rel) == M) {  // Cek apakah relasi terkait dengan mahasiswa ini
                address_child matakuliah = child(rel); // Ambil child (mata kuliah)
                if (matakuliah != NULL) {
                    cout << "  - Nama: " << info(matakuliah).nama << endl;
                    cout << "    Kode: " << info(matakuliah).kode << endl;
                    cout << "    SKS: " << info(matakuliah).sks << endl;
                    hasMataKuliah = true;
                }
            }
            rel = next(rel);
        }

        if (!hasMataKuliah) {
            cout << "  Tidak ada mata kuliah yang diambil." << endl;
        }

        cout << "----------------------------------------" << endl;
        M = next(M);
    }
}


// h. Cari mata kuliah tertentu pada mahasiswa tertentu
address_child searchMataKuliahOnMahasiswa(ListRelasi relasi, ListParent L, string nim, string namaMataKuliah)
{
    address_parent mahasiswa = searchMahasiswa(L, nim);
    if (mahasiswa == NULL) {
        return NULL;
    }

    address_relasi rel = first(relasi);
    while (rel != NULL) {
        if (parent(rel) == mahasiswa && info(child(rel)).nama == namaMataKuliah) {
            return child(rel);
        }
        rel = next(rel);
    }

    return NULL;
}

// i. Hapus mata kuliah pada mahasiswa tertentu
void deleteMataKuliah(ListRelasi &relasi, ListChild &childList, ListParent &L, string nim, string namaMataKuliah) {
    // Cari mahasiswa berdasarkan NIM
    address_parent mahasiswa = searchMahasiswa(L, nim);
    if (mahasiswa == NULL) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        return;
    }

    // Iterasi pada daftar relasi untuk mencari relasi yang sesuai
    address_relasi prevRel = NULL;
    address_relasi currRel = first(relasi);
    while (currRel != NULL) {
        if (parent(currRel) == mahasiswa && info(child(currRel)).nama == namaMataKuliah) {
            // Hapus relasi dari daftar relasi
            if (prevRel == NULL) {
                first(relasi) = next(currRel);  // Jika node relasi pertama
            } else {
                next(prevRel) = next(currRel); // Jika node relasi di tengah atau akhir
            }
            delete currRel; // Hapus node relasi
            cout << "Relasi mata kuliah \"" << namaMataKuliah << "\" berhasil dihapus dari mahasiswa dengan NIM " << nim << "." << endl;
            return;
        }
        prevRel = currRel;
        currRel = next(currRel);
    }

    // Jika relasi tidak ditemukan
    cout << "Mata kuliah \"" << namaMataKuliah << "\" tidak ditemukan pada mahasiswa dengan NIM " << nim << "." << endl;
}


int totalSKS(ListRelasi relasi, ListParent L, string nim) {
    // Cari mahasiswa berdasarkan NIM
    address_parent mahasiswa = searchMahasiswa(L, nim);
    if (mahasiswa == NULL) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        return 0; // Total SKS = 0 jika mahasiswa tidak ditemukan
    }

    // Iterasi pada ListRelasi untuk menghitung total SKS
    int total = 0;
    address_relasi currRel = first(relasi);
    while (currRel != NULL) {
        if (parent(currRel) == mahasiswa) { // Relasi cocok dengan mahasiswa
            total += info(child(currRel)).sks; // Tambahkan SKS dari mata kuliah
        }
        currRel = next(currRel);
    }

    // Output total SKS
    return total;
}


// k. Main program untuk mengelola fitur-fitur
void mainMenu(ListParent &mahasiswaList, ListRelasi &relasiList, ListChild &mataKuliahList) {
    int pilihan;
    do {
        cout << "\n===== Menu Utama =====" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa" << endl;
        cout << "4. Tambah Mata Kuliah ke Mahasiswa" << endl;
        cout << "5. Tampilkan Semua Data Mahasiswa dan Mata Kuliahnya" << endl;
        cout << "6. Cari Mata Kuliah pada Mahasiswa Tertentu" << endl;
        cout << "7. Hapus Mata Kuliah pada Mahasiswa Tertentu" << endl;
        cout << "8. Ubah Data Mahasiswa" << endl;
        cout << "9. Ubah Data Mata Kuliah" << endl;
        cout << "10. Hitung Total SKS Mahasiswa" << endl;
        cout << "11. Tambah Mata Kuliah (Insert Last)" << endl;
        cout << "12. Tampilkan Semua Mata Kuliah" << endl; // Tambahkan menu baru
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                // Tambah Mahasiswa
                infotypeMahasiswa newMahasiswa;
                cout << "Masukkan Nama: ";
                cin.ignore();
                getline(cin, newMahasiswa.nama);
                cout << "Masukkan NIM: ";
                cin >> newMahasiswa.nim;
                cout << "Masukkan Kelas: ";
                cin >> newMahasiswa.kelas;
                cout << "Masukkan Gender: ";
                cin >> newMahasiswa.gender;

                address_parent newNode = createNewElmMahasiswa(newMahasiswa);
                insertMahasiswaDepan(mahasiswaList, newNode);

                cout << "Mahasiswa berhasil ditambahkan!" << endl;
                break;
            }
            case 2: {
                // Tampilkan Semua Mahasiswa
                showAllMahasiswa(mahasiswaList);
                break;
            }
            case 3: {
                // Cari Mahasiswa
                string nim;
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> nim;
                address_parent result = searchMahasiswa(mahasiswaList, nim);
                if (result != NULL) {
                    cout << "Mahasiswa ditemukan!" << endl;
                    cout << "Nama   : " << info(result).nama << endl;
                    cout << "NIM    : " << info(result).nim << endl;
                    cout << "Kelas  : " << info(result).kelas << endl;
                    cout << "Gender : " << info(result).gender << endl;
                } else {
                    cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
                }
                break;
            }
            case 4: {
                // Tambah Mata Kuliah ke Mahasiswa
                string nim;
                infotypemataKuliah mataKuliah;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Nama Mata Kuliah: ";
                cin.ignore();
                getline(cin, mataKuliah.nama);
                cout << "Masukkan Kode Mata Kuliah: ";
                cin >> mataKuliah.kode;
                cout << "Masukkan SKS Mata Kuliah: ";
                cin >> mataKuliah.sks;

                insertMataKuliah(relasiList, mataKuliahList, mahasiswaList, nim, mataKuliah);
                break;
            }
            case 5: {
                // Tampilkan Semua Data Mahasiswa dengan Mata Kuliahnya
                showAllData(mahasiswaList, relasiList);
                break;
            }
            case 6: {
                // Cari Mata Kuliah pada Mahasiswa Tertentu
                string nim, namaMataKuliah;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Nama Mata Kuliah: ";
                cin.ignore();
                getline(cin, namaMataKuliah);

                address_child result = searchMataKuliahOnMahasiswa(relasiList, mahasiswaList, nim, namaMataKuliah);
                if (result != NULL) {
                    cout << "Mata kuliah ditemukan!" << endl;
                    cout << "Nama: " << info(result).nama << endl;
                    cout << "Kode: " << info(result).kode << endl;
                    cout << "SKS : " << info(result).sks << endl;
                } else {
                    cout << "Mata kuliah \"" << namaMataKuliah << "\" tidak ditemukan pada mahasiswa dengan NIM " << nim << "." << endl;
                }
                break;
            }
            case 7: {
                // Hapus Mata Kuliah pada Mahasiswa Tertentu
                string nim, namaMataKuliah;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;
                cout << "Masukkan Nama Mata Kuliah: ";
                cin.ignore();
                getline(cin, namaMataKuliah);

                deleteMataKuliah(relasiList, mataKuliahList, mahasiswaList, nim, namaMataKuliah);
                break;
            }
            case 8: {
                // Ubah Data Mahasiswa
                string nim;
                infotypeMahasiswa newData;
                cout << "Masukkan NIM mahasiswa yang datanya ingin diubah: ";
                cin >> nim;
                cout << "Masukkan Nama Baru: ";
                cin.ignore();
                getline(cin, newData.nama);
                cout << "Masukkan Kelas Baru: ";
                cin >> newData.kelas;
                cout << "Masukkan Gender Baru: ";
                cin >> newData.gender;

                updateMahasiswa(mahasiswaList, nim, newData);
                break;
            }
            case 9: {
                // Ubah Data Mata Kuliah
                string namaMataKuliah;
                infotypemataKuliah newData;
                cout << "Masukkan Nama Mata Kuliah yang ingin diubah: ";
                cin.ignore();
                getline(cin, namaMataKuliah);
                cout << "Masukkan Nama Baru: ";
                getline(cin, newData.nama);
                cout << "Masukkan Kode Baru: ";
                cin >> newData.kode;
                cout << "Masukkan SKS Baru: ";
                cin >> newData.sks;

                updateMataKuliah(mataKuliahList, namaMataKuliah, newData);
                break;
            }
            case 10: {
                // Hitung Total SKS Mahasiswa
                string nim;
                cout << "Masukkan NIM mahasiswa: ";
                cin >> nim;

                int total = totalSKS(relasiList, mahasiswaList, nim);
                cout << "Total SKS yang diambil mahasiswa dengan NIM " << nim << ": " << total << endl;
                break;
            }
            case 11: { // Tambah Mata Kuliah (Insert Last)
                infotypemataKuliah mataKuliah;
                cout << "Masukkan Nama Mata Kuliah: ";
                cin.ignore(); // Membersihkan input buffer
                getline(cin, mataKuliah.nama); // Mendukung input dengan spasi
                cout << "Masukkan Kode Mata Kuliah: ";
                cin >> mataKuliah.kode;
                cout << "Masukkan SKS Mata Kuliah: ";
                cin >> mataKuliah.sks;

                address_child newMataKuliah = createNewElmMataKuliah(mataKuliah);
                insertLastMataKuliah(mataKuliahList, newMataKuliah);

                cout << "Mata kuliah berhasil ditambahkan ke belakang daftar!" << endl;
                break;
            }
            case 12: { // Tampilkan Semua Mata Kuliah
                showAllMataKuliah(mataKuliahList);
                break;
            }
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan != 0);
}

