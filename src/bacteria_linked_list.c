#include <stdio.h>
#include <stdlib.h>
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
    Node *ptr = list -> head;

    while (ptr != NULL) {
        if (compare(&ptr -> data, x) == 0) {
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
    SetNode(list -> head, data, ptr);
}

void InsertRear(LList *llist, const Bacteria *data) {
    if (llist -> head == NULL) {
        InsertFront(llist, x);
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
    printf("%s - %d: %s , %s \n", data -> bacteria_name, data -> sample_number, data -> pid_result, data -> ast_result);
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
        while (ptr -> next != NULL) {
            PrintBacteria(&ptr -> data);
            ptr = ptr -> next;
        }
    }
}

void Terminate(LList *llist) {
    Clear(llist);
}

Bacteria ScanData(const char *message, int sw) {
    Bacteria temp;
    printf("%s ")
}