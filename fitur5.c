#include "header.h"

Barang dequeueRestock(Queue *q) {
    if(q->front == NULL) {
        printf("\n Antrian restock kosong!\n");
        Barang kosong = {0};
        return kosong;
    }

    QueueNode *temp = q->front;
    Barang barang = temp->data;

    q->front = q->front->next;

    if(q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return barang;
}

void prosesRestock(LinkedList *list, Queue *q) {

    if(q->front == NULL) {
        printf("\n Antrian restock kosong! Tidak ada barang yang perlu di-restock.\n");
        return;
    }

    printf("\n=== PROSES RESTOCK ===\n");
    
    // Tampilkan antrian restock sebelum proses
    printf("\n ANTRIAN RESTOCK SAAT INI:\n");
    QueueNode *temp = q->front;
    int no = 1;
    while(temp != NULL) {
        printf("%d. ID: %d | %s | Stok: %d | Min: %d\n", 
            no++, 
            temp->data.id, 
            temp->data.nama, 
            temp->data.stok, 
            temp->data.stokMinimum);
        temp = temp->next;
    }

    // Dequeue barang pertama dari antrian
    Barang barangRestock = dequeueRestock(q);

    if(barangRestock.id == 0) {
        return;  // Antrian kosong
    }

    printf("\n➤ Barang yang akan di-restock:\n");
    printf("   ID: %d | Nama: %s | Stok Saat Ini: %d\n", 
        barangRestock.id, 
        barangRestock.nama, 
        barangRestock.stok);

    // Input jumlah restock
    int jumlahRestock;
    printf("\nMasukkan jumlah restock: ");
    scanf("%d", &jumlahRestock);

    if(jumlahRestock <= 0) {
        printf(" Jumlah restock tidak valid!\n");
        // Enqueue kembali barang yang belum diproses
        enqueueRestock(q, barangRestock);
        return;
    }

    // Cari barang di Linked List dan update stoknya
    Node *curr = list->head;
    int ditemukan = 0;

    while(curr != NULL) {
        if(curr->data.id == barangRestock.id) {
            ditemukan = 1;
            curr->data.stok += jumlahRestock;

            printf("\n Restock berhasil!\n");
            printf("   Barang        : %s\n", curr->data.nama);
            printf("   Stok Awal     : %d\n", barangRestock.stok);
            printf("   Jumlah Restock: +%d\n", jumlahRestock);
            printf("   Stok Akhir    : %d\n", curr->data.stok);
            printf("   Stok Minimum  : %d\n", curr->data.stokMinimum);

            if(curr->data.stok > curr->data.stokMinimum) {
                printf("   Status        : Aman (stok di atas minimum)\n");
            }

            break;
        }
        curr = curr->next;
    }

    if(!ditemukan) {
        printf(" Barang tidak ditemukan di data utama!\n");
        // Enqueue kembali barang yang belum diproses
        enqueueRestock(q, barangRestock);
    }
}

/* =========================
   TAMPIL SELURUH ANTRIAN RESTOCK
========================= */
void tampilSeluruhanAntrian(Queue *q) {

    QueueNode *temp = q->front;

    if(temp == NULL) {
        printf("\n Antrian restock kosong!\n");
        return;
    }

    printf("\n=== ANTRIAN RESTOCK LENGKAP ===\n");

    int no = 1;
    while(temp != NULL) {
        printf("%d. ID: %d\n", no++, temp->data.id);
        printf("   Nama  : %s\n", temp->data.nama);
        printf("   Stok  : %d\n", temp->data.stok);
        printf("   Min   : %d\n", temp->data.stokMinimum);
        printf("   ─────────────────────\n");

        temp = temp->next;
    }
}

/* =========================
   PROSES RESTOCK MULTIPLE (Optional)
   - Proses seluruh antrian sekaligus
========================= */
void restockMultiple(LinkedList *list, Queue *q) {

    int jumlahProses = 0;

    while(q->front != NULL) {
        printf("\n");
        prosesRestock(list, q);
        jumlahProses++;
    }

    if(jumlahProses > 0) {
        printf("\n Selesai! Total %d barang berhasil di-restock.\n", jumlahProses);
    }
}