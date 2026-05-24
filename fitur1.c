#include "header.h"


void enqueueRestock(Queue *q, Barang barang) {

    QueueNode *baru = (QueueNode*) malloc(sizeof(QueueNode));

    if(baru == NULL) {
        printf("Gagal alokasi memori!\n");
        return;
    }

    baru->data = barang;
    baru->next = NULL;

    if(q->rear == NULL) {
        q->front = baru;
        q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }

    printf("Barang masuk ke antrian restock!\n");
}

void cekStokMinimum(Barang barang, Queue *q) {

    if(barang.stok <= barang.stokMinimum) {

        printf("WARNING: Stok barang '%s' kritis!\n", barang.nama);

        enqueueRestock(q, barang);
    }
}

void tambahBarang(LinkedList *list, Queue *q) {

    Node *baru = (Node*) malloc(sizeof(Node));

    if(baru == NULL) {
        printf("Gagal alokasi memori!\n");
        return;
    }

    printf("\n=== Tambah Barang ===\n");

    printf("ID Barang            : ");
    scanf("%d", &baru->data.id);

    printf("Nama Barang          : ");
    scanf(" %[^\n]", baru->data.nama);

    printf("Kategori             : ");
    scanf(" %[^\n]", baru->data.kategori);

    printf("Stok                 : ");
    scanf("%d", &baru->data.stok);

    printf("Harga                : ");
    scanf("%f", &baru->data.harga);

    printf("Stok Minimum         : ");
    scanf("%d", &baru->data.stokMinimum);

    baru->data.totalTerjual = 0;
    baru->next = NULL;

    /* INSERT KE LINKED LIST */
    if(list->head == NULL) {

        list->head = baru;

    } else {

        Node *temp = list->head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = baru;
    }

    printf("Barang berhasil ditambahkan!\n");

    cekStokMinimum(baru->data, q);
}

void tampilBarang(LinkedList *list) {

    Node *temp = list->head;

    if(temp == NULL) {
        printf("\nData barang kosong!\n");
        return;
    }

    printf("\n=== DATA BARANG ===\n");

    while(temp != NULL) {

        printf("\nID              : %d\n", temp->data.id);
        printf("Nama            : %s\n", temp->data.nama);
        printf("Kategori        : %s\n", temp->data.kategori);
        printf("Stok            : %d\n", temp->data.stok);
        printf("Harga           : %.2f\n", temp->data.harga);
        printf("Stok Minimum    : %d\n", temp->data.stokMinimum);

        temp = temp->next;
    }
}

void editBarang(LinkedList *list, Queue *q) {

    int id;
    int ditemukan = 0;

    printf("\nMasukkan ID barang yang ingin diedit : ");
    scanf("%d", &id);

    Node *temp = list->head;

    while(temp != NULL) {

        if(temp->data.id == id) {

            ditemukan = 1;

            printf("\n=== Edit Barang ===\n");

            printf("Nama Baru            : ");
            scanf(" %[^\n]", temp->data.nama);

            printf("Kategori Baru        : ");
            scanf(" %[^\n]", temp->data.kategori);

            printf("Stok Baru            : ");
            scanf("%d", &temp->data.stok);

            printf("Harga Baru           : ");
            scanf("%f", &temp->data.harga);

            printf("Stok Minimum Baru    : ");
            scanf("%d", &temp->data.stokMinimum);

            cekStokMinimum(temp->data, q);

            printf("Data barang berhasil diupdate!\n");

            break;
        }

        temp = temp->next;
    }

    if(!ditemukan) {
        printf("Barang tidak ditemukan!\n");
    }
}

void hapusBarang(LinkedList *list) {

    int id;
    int ditemukan = 0;

    printf("\nMasukkan ID barang yang ingin dihapus : ");
    scanf("%d", &id);

    Node *temp = list->head;
    Node *prev = NULL;

    while(temp != NULL) {

        if(temp->data.id == id) {

            ditemukan = 1;

            if(prev == NULL) {

                list->head = temp->next;

            } else {

                prev->next = temp->next;
            }

            free(temp);

            printf("Barang berhasil dihapus!\n");

            break;
        }

        prev = temp;
        temp = temp->next;
    }

    if(!ditemukan) {
        printf("Barang tidak ditemukan!\n");
    }
}

/* =========================
   TAMPIL QUEUE RESTOCK
========================= */
void tampilQueueRestock(Queue *q) {

    QueueNode *temp = q->front;

    if(temp == NULL) {
        printf("\nAntrian restock kosong!\n");
        return;
    }

    printf("\n=== ANTRIAN RESTOCK ===\n");

    while(temp != NULL) {

        printf("ID Barang   : %d\n", temp->data.id);
        printf("Nama Barang : %s\n", temp->data.nama);
        printf("Stok        : %d\n", temp->data.stok);
        printf("---------------------------\n");

        temp = temp->next;
    }
}