#include <stdio.h>
#include <stdlib.h>
#include "bacteriaData.h"
#include "bacteria_array_linked_list.h"

static Index GetIndex(LList *llist) {
    if (llist -> deleted == Null) {
        return ++(llist -> max);
    }
    else {
        Index marked = llist -> deleted;
        llist -> deleted = llist -> n[marked].Dnext;
        return marked;
    }
}

static void DeleteIndex(LList *llist, Index idx) {
    if (llist -> deleted == Null) {
        llist -> deleted = idx;
        llist -> n[idx].Dnext = Null;
    }
    else {
        Index ptr = llist -> deleted;
        llist -> deleted = idx;
        llist -> n[idx].Dnext = ptr;
    }
}

static void SetNode(Node *n, const Bacteria *data, Index next) {
    n -> data = *data;
    n -> next = next;
}

void Initialize(LList *llist, int size) {
    llist -> n = calloc(size, sizeof(Node));
    llist -> head = Null;
    llist -> current = Null;
    llist -> max = Null;
    llist -> deleted = Null;
}

Index Search(LList *llist, const Bacteria *data, int compare(const Bacteria *data1, const Bacteria *data2)) {
    Index ptr = llist -> head;
    while(ptr != Null) {
        if (compare(&llist -> n[ptr].data, data) == 0) {
            llist -> current = ptr;
            return ptr;
        }
        ptr = llist -> n[ptr].next;
    }
    return Null;
}

void InsertFront(LList *llist, const Bacteria *data) {
    Index ptr = llist -> head;
    llist -> current = GetIndex(llist);
    llist -> head = llist -> current;
    SetNode(&llist -> n[llist -> head], x, ptr);
}

void InsertRear(LList *llist, const Bacteria *data) {
    if (llist -> head == Null) {
        InsertFront(llist, data);
    }
    else {
        Index ptr = llist -> head;
        while (llist -> n[ptr].next != Null) {
            ptr = llist -> n[ptr].next;
        }
        llist -> current = GetIndex(llist);
        llist -> n[ptr].next = llist -> current;
        SetNode(&llist -> n [llist -> n[ptr].next], data, Null);
    }
}

void PopFront(LList *llist) {
    if (llist -> head != Null) {
        Index ptr = llist -> n[llist -> head].next;

    }
}
void PopBack(LList *llist);
void RemoveCurrent(LList *llist);
void Clear(LList *list);
void PrintBacteria(const Bacteria *data);
void PrintCurrent(const LList *llist);
void Print(const LList *llist);
void Terminate(LList *llist);
Bacteria ScanData(const char *message, int data_selection);
int DataNameCmp(const Bacteria *data1, const Bacteria *data2);
int DataPIDCmp(const Bacteria *data1, const Bacteria *data2);
int DataASTCmp(const Bacteria *data1, const Bacteria *data2);
int DataSNumberCmp(const Bacteria *data1, const Bacteria *data2);




