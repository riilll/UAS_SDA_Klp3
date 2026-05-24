#include "header.h"

int hashFunction(int id){
    return id % SIZE;
}

void insertHash(Hashtable *ht, int id, Node *barangPtr){
    int index = hashFunction(id);

    HashNode *newNode = (HashNode*) malloc(sizeof(HashNode));
    newNode->id = id;
    newNode->barangPtr = barangPtr = barangPtr;

    newNode->next = ht=>table[index];
    ht->table[index] = newNode;
}

Node* cariBarangByID(Hashtable *ht, int id){
    int index = hashFunction(id);
    //akses ke list di indeks tersebut
    HashNode *temp = ht->table[index];
    // 3. Telusuri chain (Linked List di dalam Hash Table)
    while (temp != NULL) {
        if (temp->id == id) {
            // Jika ID ketemu, kembalikan pointer ke barang di Linked List utama
            return temp->barangPtr; 
        }
        temp = temp->next;
    }
    return NULL; 
}

Node* cariBarangByNama(LinkedList *list, char *namaDicari) {
    Node *temp = list->head;

    while (temp != NULL) {
        // Menggunakan strcasecmp agar pencarian tidak sensitif terhadap huruf besar/kecil
        if (strcasecmp(temp->data.nama, namaDicari) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}