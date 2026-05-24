#include "header.h"

int main() {
    LinkedList dataBarang;
    HashTable hashBarang;
    Stack riwayat;
    Queue antreanRestock;

    int pilihan;

    initLinkedList(&dataBarang);
    initHashTable(&hashBarang);
    initStack(&riwayat);
    initQueue(&antreanRestock);

    printf("=============================================\n");
    printf(" SISTEM MANAJEMEN INVENTORI TOKO\n");
    printf("=============================================\n");
    printf("Semua struktur data berhasil diinisialisasi.\n");

    do {
        printf("\n=============== MENU UTAMA ===================\n");
        printf("1. Manajemen Barang\n");
        printf("2. Transaksi Penjualan\n");
        printf("3. Analisis & Ranking\n");
        printf("4. Pencarian Barang\n");
        printf("5. Restock Barang\n");
        printf("6. Laporan Inventori\n");
        printf("0. Keluar\n");
        printf("=============================================\n");
        printf("Pilih menu: ");

        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid! Harus berupa angka.\n");

            while (getchar() != '\n');
            pilihan = -1;
            continue;
        }

        switch (pilihan) {

            case 1:{
                int sub;

                printf("\n=== MANAJEMEN BARANG ===\n");
                printf("1. Tambah Barang\n");
                printf("2. Edit Barang\n");
                printf("3. Hapus Barang\n");
                printf("4. Tampilkan Barang\n");
                printf("Pilih: ");
                scanf("%d",&sub);
                while(getchar()!='\n');

                switch(sub){

                    case 1:
                        tambahBarang(&dataBarang,&antreanRestock, &hashBarang);
                        break;

                    case 2:
                        editBarang(&dataBarang,&antreanRestock);
                        break;

                    case 3:
                        hapusBarang(&dataBarang);
                        break;

                    case 4:
                        tampilBarang(&dataBarang);
                        break;

                    default:
                        printf("Pilihan tidak valid.\n");
                }

                break;
            }

            case 2:{
                int sub;

                printf("\n=== TRANSAKSI ===\n");
                printf("1. Penjualan\n");
                printf("2. Undo Transaksi\n");
                printf("3. Riwayat Transaksi\n");
                printf("Pilih: ");
                scanf("%d",&sub);
                while(getchar()!='\n');

                switch(sub){

                    case 1:
                        transaksiPenjualan(
                            &dataBarang,
                            &riwayat,
                            &antreanRestock
                        );
                        break;

                    case 2:
                        undoTransaksi(
                            &dataBarang,
                            &riwayat
                        );
                        break;

                    case 3:
                        tampilRiwayatTransaksi(&riwayat);
                        break;

                    default:
                        printf("Pilihan tidak valid.\n");
                }

                break;
            }

            case 3:
                printf("\n=== ANALISIS & RANKING ===\n");
                tampilRanking(&dataBarang);
                identifikasiProduk(&dataBarang);
                break;

            case 4:{
                int sub;

                printf("\n=== PENCARIAN ===\n");
                printf("1. Cari ID\n");
                printf("2. Cari Nama\n");
                printf("Pilih: ");
                scanf("%d",&sub);
                while(getchar()!='\n');

                if(sub==1){

                    int id;

                    printf("Masukkan ID: ");
                    scanf("%d",&id);

                    Node *hasil =
                        cariBarangByID(
                            &hashBarang,
                            id
                        );

                    if(hasil)
                        printf("Ditemukan: %s\n",
                                hasil->data.nama);
                    else
                        printf("Barang tidak ditemukan.\n");
                }

                else if(sub==2){

                    char nama[50];

                    printf("Masukkan nama: ");
                    scanf(" %[^\n]",nama);

                    Node *hasil =
                        cariBarangByNama(
                            &dataBarang,
                            nama
                        );

                    if(hasil)
                        printf("Ditemukan: %s\n",
                                hasil->data.nama);
                    else
                        printf("Barang tidak ditemukan.\n");
                }

                break;
            }

            case 5:
                printf("\n=== RESTOCK ===\n");
                tampilQueueRestock(&antreanRestock);
                prosesRestock(
                    &dataBarang,
                    &antreanRestock
                );
                break;

            case 6:
                tampilkanLaporanInventori(
                    &dataBarang
                );
                break;

            case 0:
                printf("\nProgram selesai.\n");
                break;

            default:
                printf("Pilihan tidak tersedia.\n");
            }

    } while (pilihan != 0);

    freeLinkedList(&dataBarang);
    freeHashTable(&hashBarang);
    freeStack(&riwayat);
    freeQueue(&antreanRestock);

    printf("Semua memori berhasil dibebaskan.\n");
    printf("Terima kasih telah menggunakan program ini.\n");

    return 0;
}