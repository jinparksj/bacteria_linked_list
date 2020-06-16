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
    SetNode(&llist -> n[llist -> head], data, ptr);
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
        DeleteIndex(llist, llist -> head);
        llist -> current = ptr;
        llist -> head = llist -> current;
    }
}

void PopBack(LList *llist){
    if (llist -> head != Null) {
        if (llist -> n[llist -> head].next == Null) {
            PopFront(llist);
        }
        else {
            Index ptr = llist -> head;
            Index pre;
            while( llist -> n[ptr].next != Null) {
                pre = ptr;
                ptr = llist -> n[ptr].next;
            }
            llist -> n[pre].next = Null;
            DeleteIndex(llist, ptr);
            llist -> current = pre;
        }
    }
}

void RemoveCurrent(LList *llist) {
    if (llist -> head != Null) {
        if (llist->current == llist->head) {
            PopFront(llist);
        }
        else {
            Index ptr = llist -> head;
            while(llist -> n[ptr].next != llist -> current) {
                ptr = llist -> n[ptr].next;
            }
            llist -> n[ptr].next = llist -> n[llist -> current].next;
            DeleteIndex(llist, llist -> current);
            llist -> current = ptr;
        }
    }
}

void Clear(LList *llist) {
    while(llist -> head != Null)
        PopFront(llist);
    llist -> current = Null;
}

void PrintBacteria(const Bacteria *data) {
    printf("%s - sample %d: PID - %s , AST - %s \n", data -> bacteria_name, data -> sample_number, data -> pid_result, data -> ast_result);
}

void PrintCurrent(const LList *llist) {
    if (llist -> current == Null) {
        printf("There is no node.\n");
    }
    else {
        PrintBacteria(&llist -> n[llist -> current].data);
    }
}

void Print(const LList *llist) {
    if (llist -> head == Null) {
        puts("There is no node.");
    }
    else {
        Index ptr = llist -> head;
        puts("-- All Nodes --\n");
        while (ptr != Null) {
            PrintBacteria(&llist -> n[ptr].data);
            ptr = llist -> n[ptr].next;
        }
    }
}

void Terminate(LList *llist) {
    Clear(llist);
    free(llist -> n);
}

Bacteria ScanData(const char *message, int data_selection) {
    Bacteria temp;
    printf("Input: Data %s.\n", message);

    if (data_selection & DATA_NAME) {
        printf("Bacteria Name : ");
        scanf("%s", &temp.bacteria_name);
    }


    if (data_selection & DATA_AST) {
        printf("Bacteria AST Result : ");
        scanf("%s", &temp.ast_result);
    }


    if (data_selection & DATA_PID) {
        printf("Bacteria PID Result : ");
        scanf("%s", &temp.pid_result);
    }

    if (data_selection & DATA_SNUMBER) {
        printf("Bacteria Sample Number : ");
        scanf("%d", &temp.sample_number);
    }

    return temp;
}


int DataNameCmp(const Bacteria *data1, const Bacteria *data2){
    return strcmp(data1 -> bacteria_name, data2 -> bacteria_name);
}

int DataPIDCmp(const Bacteria *data1, const Bacteria *data2){
    return strcmp(data1 -> pid_result, data2 -> pid_result);
}

int DataASTCmp(const Bacteria *data1, const Bacteria *data2){
    return strcmp(data1 -> ast_result, data2 -> ast_result);
}

int DataSNumberCmp(const Bacteria *data1, const Bacteria *data2){
    if (data1 -> sample_number < data2 -> sample_number) {
        return -1;
    }
    else {
        if (data1 -> sample_number > data2 -> sample_number) {
            return 1;
        }
        else {
            return 0;
        }
    }
}




