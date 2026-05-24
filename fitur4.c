#include "header.h"

int hashFunction(int id) {
    return id % SIZE;
}

void insertHash(HashTable *ht, int id, Node *barangPtr) {
    if (ht == NULL || barangPtr == NULL) {
        printf("Error: Hash Table atau pointer barang NULL!\n");
        return;
    }

    int index = hashFunction(id);
    HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
    
    if (newNode == NULL) {
        printf("Error: Gagal alokasi memori untuk Hash Node!\n");
        return;
    }

    newNode->id = id;
    newNode->barangPtr = barangPtr;  
    newNode->next = ht->table[index];  
    ht->table[index] = newNode;
}

// Pencarian by ID menggunakan Hash Table - O(1) rata-rata
Node* cariBarangByID(HashTable *ht, int id) {
    if (ht == NULL) {
        printf("Error: Hash Table NULL!\n");
        return NULL;
    }

    int index = hashFunction(id);
    HashNode *temp = ht->table[index];

    // Telusuri chain di indeks tersebut
    while (temp != NULL) {
        if (temp->id == id) {
            return temp->barangPtr;  // Kembalikan pointer ke barang
        }
        temp = temp->next;
    }
    return NULL;  // Tidak ditemukan
}

// Pencarian by Nama menggunakan Linear Search - O(n)
// Mendukung partial match (substring search)
Node* cariBarangByNama(LinkedList *list, const char *namaDicari) {
    if (list == NULL || namaDicari == NULL) {
        printf("Error: Linked List atau nama pencarian NULL!\n");
        return NULL;
    }

    Node *temp = list->head;

    while (temp != NULL) {
        // Menggunakan strstr untuk partial match (case-insensitive)
        if (strstr(temp->data.nama, namaDicari) != NULL) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;  // Tidak ditemukan
}

// Fungsi tambahan: tampilkan hasil pencarian
void tampilHasilPencarian(Node *hasil) {
    if (hasil == NULL) {
        printf("\n Barang tidak ditemukan.\n");
        return;
    }

    printf("\n Barang ditemukan!\n");
    printf("ID         : %d\n", hasil->data.id);
    printf("Nama       : %s\n", hasil->data.nama);
    printf("Kategori   : %s\n", hasil->data.kategori);
    printf("Stok       : %d\n", hasil->data.stok);
    printf("Harga      : %.2f\n", hasil->data.harga);
    printf("Stok Min   : %d\n", hasil->data.stokMinimum);
    printf("Terjual    : %d\n", hasil->data.totalTerjual);
    printf("----------------------\n");
}