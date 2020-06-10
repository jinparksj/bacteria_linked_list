#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <backtrace.h>
#include "bacteria_linked_list.h"

static Node *AllocateNode(void) {
    return calloc(1, sizeof(Node));
}

static void SetNode(Node *n, const Bacteria *data, const Node *next) {
    n -> data = *data;
    n -> next = next; //n->next is address
}

void Initialize(LList *llist) {
    llist -> head = NULL;
    llist -> current = NULL;
}

Node *search(LList *llist, const Bacteria *comp_data, int compare(const Bacteria *data1, const Bacteria *data2)) {
    Node *ptr = llist -> head;

    while (ptr != NULL) {
        if (compare(&ptr -> data, comp_data) == 0) {
            llist -> current = ptr;
            return ptr;
        }
        ptr = ptr -> next;
    }
    return NULL;
}

void InsertFront(LList *llist, const Bacteria *data) {
    Node *ptr = llist -> head;
    llist -> current = AllocateNode();
    llist -> head = llist -> current;
    SetNode(llist -> head, data, ptr);
}

void InsertRear(LList *llist, const Bacteria *data) {
    if (llist -> head == NULL) {
        InsertFront(llist, data);
    }
    else {
        Node *ptr = llist -> head;
        while (ptr -> next != NULL) {
            ptr = ptr -> next;
        }
        llist -> current = AllocateNode();
        ptr -> next = llist -> current;
        SetNode(ptr -> next, data, NULL);
    }
}

void PopFront(LList *llist) {
    if (llist -> head != NULL) {
        Node *ptr = llist -> head -> next;
        free(llist -> head);
        llist -> current = ptr;
        llist -> head = llist -> current;
    }
}

void PopBack(LList *llist) {
    if (llist -> head != NULL) {
        if ((llist -> head) -> next == NULL) {
            PopFront(llist);
        }
        else {
            Node *ptr = llist -> head;
            Node *pre;
            while (ptr -> next != NULL) {
                pre = ptr;
                ptr = ptr -> next;
            }
            pre -> next = NULL;
            free(ptr);
            llist -> current = pre;
        }
    }
}

void RemoveCurrent(LList *llist) {
    if (llist -> head != NULL) {
        if (llist -> current == llist -> head) {
            PopFront(llist);
        }
    }
    else {
        Node *ptr = llist -> head;
        while (ptr -> next != llist -> current) {
            ptr = ptr -> next;
        }
        ptr -> next = llist -> current -> next;
        free(llist -> current);
        llist -> current = ptr;
    }
}

void Clear(LList *llist) {
    while (llist -> head != NULL) {
        PopFront(llist);
    }
    llist -> current = NULL;
}

void PrintBacteria(const Bacteria *data) {
    printf("%s - sample %d: PID - %s , AST - %s \n", data -> bacteria_name, data -> sample_number, data -> pid_result, data -> ast_result);
}

void PrintCurrent(const LList *llist) {
    if (llist -> current == NULL){
        printf("There is no node.\n");
    }
    else {
        PrintBacteria(&llist -> current -> data);
    }
}

void Print(const LList *llist) {
    if (llist -> head == NULL) {
        puts("There is no node.");
    }
    else {
        Node *ptr = llist -> head;
        puts("-- Print All Nodes --");
        while (ptr != NULL) {
            PrintBacteria(&ptr -> data);
            ptr = ptr -> next;
        }
    }
}

void Terminate(LList *llist) {
    Clear(llist);
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