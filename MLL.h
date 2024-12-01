#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define lChild(P) P->lChild

typedef string infotype;
typedef struct elmList_parent *address_parent;
typedef struct elmList_child *address_child;

// Struktur Child: Single Linked List (SLL)
struct elmList_child {
    infotype courseName;
    int sks;
    address_child next;
};

struct ListChild {
    address_child first;
};

// Struktur Parent: Double Linked List (DLL)
struct elmList_parent {
    infotype studentName;
    ListChild lChild;
    address_parent next;
    address_parent prev;
};

struct ListParent {
    address_parent first;
    address_parent last;
};

// Fungsi-Fungsi untuk Child (SLL)
bool isEmptyChild(ListChild L);
void createListChild(ListChild &L);
address_child createNewElmtChild(infotype courseName, int sks);
void insertFirstChild(ListChild &L, address_child P);
void insertLastChild(ListChild &L, address_child P);
void deleteFirstChild(ListChild &L, address_child &P);
void deleteLastChild(ListChild &L, address_child &P);
void showChild(ListChild L);
address_child searchChild(ListChild L, infotype X);

// Fungsi-Fungsi untuk Parent (DLL)
bool isEmptyParent(ListParent L);
void createListParent(ListParent &L);
address_parent createNewElmtParent(infotype studentName);
void insertFirstParent(ListParent &L, address_parent P);
void insertLastParent(ListParent &L, address_parent P);
void deleteFirstParent(ListParent &L, address_parent &P);
void deleteLastParent(ListParent &L, address_parent &P);
void showParent(ListParent L);
address_parent searchParent(ListParent L, infotype X);

// Fungsi-Fungsi Operasi Gabungan
void showAllParentsWithChildren(ListParent L);
bool deleteChildFromParent(ListParent &L, infotype parentName, infotype courseName);
int calculateTotalSKS(ListParent L, infotype parentName);

#endif // MLL_H_INCLUDED
