#include "header.h"

/* =========================
   SPLIT LINKED LIST
========================= */
void splitList(Node *head, Node **front, Node **back) {

    Node *fast;
    Node *slow;

    if(head == NULL || head->next == NULL) {

        *front = head;
        *back = NULL;

    } else {

        slow = head;
        fast = head->next;

        while(fast != NULL) {

            fast = fast->next;

            if(fast != NULL) {

                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = head;
        *back = slow->next;
        slow->next = NULL;
    }
}

/* =========================
   MERGE DATA
========================= */
Node* merge(Node *a, Node *b) {

    if(a == NULL)
        return b;

    if(b == NULL)
        return a;

    Node *result = NULL;

    if(a->data.totalTerjual >= b->data.totalTerjual) {

        result = a;
        result->next = merge(a->next, b);

    } else {

        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

/* =========================
   MERGE SORT
========================= */
void mergeSort(Node **headRef) {

    Node *head = *headRef;

    if(head == NULL || head->next == NULL)
        return;

    Node *a;
    Node *b;

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = merge(a, b);
}

/* =========================
   TAMPIL RANKING
========================= */
void tampilRanking(LinkedList *list) {

    Node *temp = list->head;

    int rank = 1;

    if(temp == NULL) {

        printf("\nData barang kosong!\n");
        return;
    }

    mergeSort(&list->head);

    temp = list->head;

    printf("\n=== RANKING PRODUK ===\n");

    while(temp != NULL) {

        printf("\nRank #%d\n", rank);

        printf("ID Barang      : %d\n",
               temp->data.id);

        printf("Nama Barang    : %s\n",
               temp->data.nama);

        printf("Kategori       : %s\n",
               temp->data.kategori);

        printf("Total Terjual  : %d\n",
               temp->data.totalTerjual);

        printf("---------------------------\n");

        temp = temp->next;
        rank++;
    }
}

/* =========================
   IDENTIFIKASI PRODUK
========================= */
void identifikasiProduk(LinkedList *list) {

    Node *temp = list->head;

    if(temp == NULL) {

        printf("\nData barang kosong!\n");
        return;
    }

    printf("\n=== FAST / SLOW MOVING ===\n");

    while(temp != NULL) {

        printf("\nNama Barang    : %s\n",
               temp->data.nama);

        printf("Total Terjual  : %d\n",
               temp->data.totalTerjual);

        if(temp->data.totalTerjual >= 50) {

            printf("Status         : Fast Moving\n");

        } else {

            printf("Status         : Slow Moving\n");
        }

        printf("---------------------------\n");

        temp = temp->next;
    }
}
