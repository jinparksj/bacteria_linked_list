#include <stdio.h>
#include <stdlib.h>
#include "bacteriaData.h"
#include "bacteria_circle_double_list.h"

static DNode *AllocateDNode(void) {
    return calloc(1, sizeof(DNode));
}

static void SetDNode(DNode *n, const Bacteria *data, const DNode *prev, const DNode *next) {
    n -> data = *data;
    n -> prev = prev;
    n -> next = next;
}

static int IsEmpty(const DList *dlist) {
    return dlist -> head -> next == dlist -> head;
}

void Initialize(DList *dlist) {
    DNode *dummyNode = AllocateDNode();
    dlist -> current = dummyNode;
    dlist -> head = dlist -> current;
    dummyNode -> next = dummyNode;
    dummyNode -> prev = dummyNode -> next;
}

void PrintCurrent(const DList *dlist) {
    if (IsEmpty(dlist)) {
        printf("There is no node.\n");
    }
    else {
        PrintBacteria(&dlist -> current -> data);
    }
}

DNode *Search(DList *dlist, const Bacteria *data, int compare(const Bacteria *data1, const Bacteria *data2)) {
    DNode *ptr = dlist -> head -> next;
    while (ptr !=  dlist -> head) {
        if (compare(&ptr -> data, data) == 0) {
            dlist -> current = ptr;
            return ptr;
        }
        ptr = ptr -> next;
    }
    return NULL;
}

void Print(const DList *dlist) {
    if (IsEmpty(dlist)) {
        puts("There is no node.");
    }
    else {
        DNode *ptr = dlist -> head -> next;
        puts("-- All Nodes --\n");
        while(ptr != dlist -> head) {
            PrintBacteria(&ptr -> data);
            ptr = ptr -> next;
        }
    }
}

void PrintReverse(const DList *dlist) {
    if (IsEmpty(dlist)) {
        puts("There is no node.\n");
    }
    else  {
        DNode *ptr = dlist -> head -> prev;
        puts("-- All Nodes Reversely --\n");
        while(ptr != dlist -> head) {
            PrintBacteria(&ptr -> data);
            ptr = ptr -> prev;
        }
    }
}

int Next(DList *dlist) {
    if (IsEmpty(dlist) || dlist -> current -> next == dlist -> head) {
        return 0;
    }
    dlist -> current = dlist -> current -> next;
    return 1;
}

int Prev(DList *dlist) {
    if (IsEmpty(dlist) || dlist -> current -> prev == dlist -> head) {
        return 0;
    }
    dlist -> current = dlist -> current -> prev;
    return 1;
}

void InsertAfter(DList *dlist, DNode *p, const Bacteria *data) {
    DNode *ptr = AllocateDNode();
    DNode *nxt = p -> next;
    p -> next -> prev = ptr;
    p -> next = p -> next -> prev;
    SetDNode(ptr, data, p, nxt);
    dlist -> current = ptr;
}

void InsertFront(DList *dlist, const Bacteria *data) {
    InsertAfter(dlist, dlist -> head, data);
}

void InsertRear(DList *dlist, const Bacteria *data) {
    InsertAfter(dlist, dlist -> head -> prev, data);
}

void Remove(DList *dlist, DNode *p) {
    p -> prev -> next = p -> next;
    p -> next -> prev = p -> prev;
    dlist -> current = p -> prev;
    free(p);
    if (dlist -> current == dlist -> head) {
        dlist -> current = dlist -> head -> next;
    }
}

void PopFront(DList *dlist) {
    if (!IsEmpty(dlist)) {
        Remove(dlist, dlist -> head -> next);
    }
}

void PopBack(DList *dlist) {
    if (!IsEmpty(dlist)) {
        Remove(dlist, dlist -> head -> prev);
    }
}

void RemoveCurrent(DList *dlist) {
    if (dlist -> current != dlist -> head) {
        Remove(dlist, dlist -> current);
    }
}

void Clear(DList *dlist) {
    while (!IsEmpty(dlist)) {
        PopFront(dlist);
    }
}

void Terminate(DList *dlist) {
    Clear(dlist);
    free(dlist -> head);
}

void PrintBacteria(const Bacteria *data) {
    printf("%s - sample %d: PID - %s , AST - %s \n", data -> bacteria_name, data -> sample_number, data -> pid_result, data -> ast_result);
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




