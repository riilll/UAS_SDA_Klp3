#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

//struct barang
typedef struct {
    int id;
    char nama[50];
    char kategori[30];
    int stok;
    float harga;
    int stokMinimum;
    int totalTerjual;
} Barang;

//linked list (datautama)
typedef struct Node {
    Barang data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

/* =========================
   HASH TABLE
========================= */
typedef struct HashNode {
    int id;
    Node *barangPtr;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode *table[SIZE];
} HashTable;

/* =========================
   STACK (RIWAYAT)
========================= */
typedef struct StackNode {
    Barang data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
} Stack;

/* =========================
   QUEUE (TRANSAKSI)
========================= */
typedef struct QueueNode {
    Barang data;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

/* =========================
   PROTOTIPE FUNGSI WAJIB
========================= */

// Inisialisasi
void initLinkedList(LinkedList *list);
void initHashTable(HashTable *ht);
void initStack(Stack *s);
void initQueue(Queue *q);
void mergeSort(Node **headRef);
void tampilRanking(LinkedList *list);
void identifikasiProduk(LinkedList *list);
void tambahBarang(LinkedList *list,Queue *q,HashTable *ht);
void tampilBarang(LinkedList *list);
void editBarang(LinkedList *list, Queue *q);
void hapusBarang(LinkedList *list);
void cekStokMinimum(Barang barang, Queue *q);
void enqueueRestock(Queue *q, Barang barang);
void tampilQueueRestock(Queue *q);
void pushStack(Stack *s, Barang data);
int popStack(Stack *s, Barang *data);
void transaksiPenjualan(LinkedList *list, Stack *riwayat, Queue *q);
void undoTransaksi(LinkedList *list, Stack *riwayat);
void tampilRiwayatTransaksi(Stack *riwayat);
double hitungTotalNilaiInventori(LinkedList *list);
void tampilkanLaporanInventori(LinkedList *list);

int hashFunction(int id);
void insertHash(HashTable *ht, int id, Node *barangPtr);
Node* cariBarangByID(HashTable *ht, int id);
Node* cariBarangByNama(LinkedList *list, const char *namaDicari);
Barang dequeueRestock(Queue *q);
void prosesRestock(LinkedList *list, Queue *q);
// Free Memory
void freeLinkedList(LinkedList *list);
void freeHashTable(HashTable *ht);
void freeStack(Stack *s);
void freeQueue(Queue *q);


#endif