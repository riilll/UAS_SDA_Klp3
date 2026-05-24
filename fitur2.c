#include "header.h"

// Fungsi untuk memasukkan riwayat transaksi ke stack
void pushStack(Stack *s, Barang data) {
    StackNode *baru = (StackNode*) malloc(sizeof(StackNode));
    
    if(baru == NULL) {
        printf("Gagal alokasi memori untuk Stack!\n");
        return;
    }
    
    baru->data = data;
    baru->next = s->top;
    s->top = baru;
}

// Fungsi untuk mengambil riwayat terakhir dari stack
int popStack(Stack *s, Barang *data) {
    if(s->top == NULL) {
        return 0; // Stack kosong
    }
    
    StackNode *temp = s->top;
    *data = temp->data;
    s->top = s->top->next;
    
    free(temp);
    return 1; // Berhasil pop
}


void transaksiPenjualan(LinkedList *list, Stack *riwayat, Queue *q) {
    int id, qty;
    int ditemukan = 0;

    printf("\n=== TRANSAKSI PENJUALAN ===\n");
    printf("Masukkan ID Barang yang dibeli : ");
    scanf("%d", &id);

    Node *temp = list->head;

    while(temp != NULL) {
        if(temp->data.id == id) {
            ditemukan = 1;
            
            printf("Barang ditemukan : %s\n", temp->data.nama);
            printf("Stok Tersedia    : %d\n", temp->data.stok);
            printf("Harga Satuan     : Rp%.2f\n", temp->data.harga);
            
            printf("Masukkan jumlah beli : ");
            scanf("%d", &qty);

            // Validasi stok cukup
            if(qty > 0 && qty <= temp->data.stok) {
                
                // 1. Siapkan data untuk direkam ke riwayat (Stack)
                Barang riwayatBarang = temp->data;
                // Simpan jumlah barang yang TERJUAL ke atribut stok untuk keperluan undo
                riwayatBarang.stok = qty; 
                
                // 2. Push ke Stack
                pushStack(riwayat, riwayatBarang);

                // 3. Update data asli di Linked List
                temp->data.stok -= qty;
                temp->data.totalTerjual += qty;

                printf("\nTransaksi Berhasil!\n");
                printf("Total Bayar : Rp%.2f\n", qty * temp->data.harga);

                // 4. Cek apakah stok menyentuh batas minimum setelah transaksi
                cekStokMinimum(temp->data, q);
                
            } else if (qty <= 0) {
                printf("Jumlah beli harus lebih dari 0!\n");
            } else {
                printf("Transaksi GAGAL! Stok tidak mencukupi.\n");
            }
            break;
        }
        temp = temp->next;
    }

    if(!ditemukan) {
        printf("Barang dengan ID %d tidak ditemukan di inventori!\n", id);
    }
}


void undoTransaksi(LinkedList *list, Stack *riwayat) {
    Barang dataUndo;
    
    printf("\n=== UNDO TRANSAKSI TERAKHIR ===\n");
    
    // Tarik data transaksi terakhir dari Stack
    if(popStack(riwayat, &dataUndo)) {
        
        Node *temp = list->head;
        int ditemukan = 0;
        
        // Cari barang tersebut di Linked List untuk dikembalikan datanya
        while(temp != NULL) {
            if(temp->data.id == dataUndo.id) {
                ditemukan = 1;
                
                // Kembalikan stok dan kurangi total terjual
                // Ingat: dataUndo.stok berisi jumlah (qty) yang ditransaksikan sebelumnya
                temp->data.stok += dataUndo.stok; 
                temp->data.totalTerjual -= dataUndo.stok;
                
                printf("Undo berhasil dilakukan!\n");
                printf("- Transaksi '%s' dibatalkan.\n", dataUndo.nama);
                printf("- %d unit dikembalikan ke stok inventori.\n", dataUndo.stok);
                break;
            }
            temp = temp->next;
        }
        
        if(!ditemukan) {
            printf("Peringatan: Barang '%s' sudah tidak ada di inventori (mungkin dihapus).\n", dataUndo.nama);
            printf("Stok tidak dapat dikembalikan.\n");
        }
        
    } else {
        printf("Tidak ada riwayat transaksi yang bisa di-undo!\n");
    }
}


void tampilRiwayatTransaksi(Stack *riwayat) {
    StackNode *temp = riwayat->top;

    printf("\n=== RIWAYAT TRANSAKSI TERAKHIR ===\n");
    
    if(temp == NULL) {
        printf("Belum ada transaksi.\n");
        return;
    }

    int i = 1;
    // Tampilkan isi stack dari top ke bawah
    while(temp != NULL) {
        printf("%d. Barang: %s | Qty Terjual: %d | Subtotal: Rp%.2f\n", 
               i, temp->data.nama, temp->data.stok, temp->data.stok * temp->data.harga);
        temp = temp->next;
        i++;
    }
}
