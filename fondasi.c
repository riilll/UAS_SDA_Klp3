#include "header.h"

/* =========================
   INISIALISASI
========================= */
void initLinkedList(LinkedList *list) {
    list->head = NULL;
}

void initHashTable(HashTable *ht) {
    for(int i = 0; i < SIZE; i++) {
        ht->table[i] = NULL;
    }
}

void initStack(Stack *s) {
    s->top = NULL;
}

void initQueue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

/* =========================
   FREE MEMORY (Pencegah Leak)
========================= */
void freeLinkedList(LinkedList *list) {
    Node *temp;
    while(list->head != NULL) {
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

void freeHashTable(HashTable *ht) {
    HashNode *temp, *curr;
    for(int i = 0; i < SIZE; i++) {
        curr = ht->table[i];
        while(curr != NULL) {
            temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

void freeStack(Stack *s) {
    StackNode *temp;
    while(s->top != NULL) {
        temp = s->top;
        s->top = s->top->next;
        free(temp);
    }
}

void freeQueue(Queue *q) {
    QueueNode *temp;
    while(q->front != NULL) {
        temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
}

