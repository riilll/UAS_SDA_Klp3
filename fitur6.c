#include "header.h"

double hitungTotalNilaiInventori(LinkedList *list) {
    double total = 0.0;
    Node *current = list->head;

    while (current != NULL) {
        total += current->data.stok * current->data.harga;
        current = current->next;
    }

    return total;
}

void tampilkanLaporanInventori(LinkedList *list) {
    Node *current = list->head;
    int nomor = 1;

    printf("\n=================================================\n");
    printf("              LAPORAN INVENTORI\n");
    printf("=================================================\n");

    if (list->head == NULL) {
        printf("Inventori masih kosong.\n");
        printf("=================================================\n");
        return;
    }

    printf("%-4s %-10s %-25s %-8s %-12s %-15s\n",
           "No", "Kode", "Nama Barang", "Stok", "Harga", "Total");

    printf("-------------------------------------------------\n");

    while (current != NULL) {
        double subtotal = current->data.stok * current->data.harga;

        printf("%-4d %-10d %-25s %-8d Rp%-10.2f Rp%-10.2f\n",
               nomor,
               current->data.id,
               current->data.nama,
               current->data.stok,
               current->data.harga,
               subtotal);

        nomor++;
        current = current->next;
    }

    printf("-------------------------------------------------\n");
    printf("TOTAL NILAI INVENTORI : Rp%.2f\n",
           hitungTotalNilaiInventori(list));
    printf("JUMLAH JENIS BARANG   : %d\n", nomor - 1);
    printf("=================================================\n");
}