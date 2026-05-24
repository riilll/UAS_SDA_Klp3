SISTEM ANALISIS STOK BARANG TOKO ATK

Deskripsi Project
Project ini merupakan program berbasis bahasa C yang dibuat untuk membantu pengelolaan stok barang pada toko Alat Tulis Kantor (ATK). Program ini dapat digunakan untuk mengelola data barang, melakukan transaksi penjualan, menganalisis produk terlaris, melakukan pencarian barang, mengatur proses restock, serta menampilkan laporan inventori.

Dalam pembuatannya, program menerapkan beberapa konsep Struktur Data dan Algoritma seperti Linked List, Stack, Queue, Hash Table, Merge Sort, dan Linear Search.

Fitur Program
Program memiliki beberapa fitur utama, yaitu:
* Manajemen barang (tambah, edit, hapus, dan tampil barang)
* Transaksi penjualan
* Undo transaksi menggunakan Stack
* Analisis produk fast moving dan slow moving
* Ranking produk berdasarkan jumlah penjualan
* Pencarian barang berdasarkan ID dan nama
* Sistem antrian restock barang
* Laporan inventori dan total nilai barang

Struktur Data dan Algoritma
Linked List digunakan sebagai penyimpanan utama data barang karena bersifat dinamis dan memudahkan proses tambah maupun hapus data.

Stack digunakan untuk menyimpan riwayat transaksi sehingga program dapat melakukan fitur undo transaksi terakhir dengan konsep LIFO (Last In First Out).

Queue digunakan untuk mengatur antrian restock barang menggunakan konsep FIFO (First In First Out).

Hash Table digunakan untuk mempercepat pencarian barang berdasarkan ID.

Merge Sort digunakan untuk mengurutkan produk berdasarkan jumlah penjualan dengan kompleksitas waktu:

O(n\log n)

Sedangkan pencarian nama barang menggunakan Linear Search dengan kompleksitas:

O(n)

Struktur File
Program terdiri dari beberapa file:
* main.c sebagai program utama
* header.h sebagai deklarasi struktur data dan fungsi
* fondasi.c untuk inisialisasi dan free memory
* fitur1.c untuk manajemen barang
* fitur2.c untuk transaksi dan undo
* fitur3.c untuk analisis dan ranking produk
* fitur4.c untuk pencarian barang
* fitur5.c untuk proses restock
* fitur6.c untuk laporan inventori

Cara Compile Program
gcc *.c -o uas -Wall

Cara Menjalankan Program
Untuk Linux atau Git Bash:
./uas

Untuk Windows PowerShell:
.\uas.exe

Anggota Kelompok
Kelompok 3:
* Muhammad Fahril Khalifi (250810701100002)
* Muhammad Irfan (250810701100024)
* Nayli Itqiyana (250810701100025)
* Fitri Br Manik (250810701100032)
* Annisa Azzuhra Maghfirah (250810701100045)
* Raymond Venmart (250810701100066)
