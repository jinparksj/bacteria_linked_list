#ifndef BACTERIA_LINKED_LIST_BACTERIA_CIRCLE_DOUBLE_LIST_H
#define BACTERIA_LINKED_LIST_BACTERIA_CIRCLE_DOUBLE_LIST_H

#include "bacteriaData.h"

#define DATA_NAME       1
#define DATA_AST        2
#define DATA_PID        4
#define DATA_SNUMBER    8

typedef struct __node {
    Bacteria data;
    struct __node *prev;
    struct __node *next;
} DNode;

typedef struct {
    DNode *head;
    DNode *current;
} DList;

void Initialize(DList *dlist);
DNode *Search(DList *dlist, const Bacteria *comp_data, int compare(const Bacteria *data1, const Bacteria *data2));
void InsertFront(DList *dlist, const Bacteria *data);
void InsertRear(DList *dlist, const Bacteria *data);
void InsertAfter(DList *dlist, DNode *p, const Bacteria *data);
void PopFront(DList *dlist);
void PopBack(DList *dlist);
void RemoveCurrent(DList *dlist);
void Remove(DList *dlist, DNode *p);
void Clear(DList *dlist);
void PrintBacteria(const Bacteria *data);
void PrintCurrent(const DList *dlist);
void Print(const DList *dlist);
void PrintReverse(const DList *dlist);
int Next(DList *dlist);
int Prev(DList *dlist);

void Terminate(DList *dlist);
Bacteria ScanData(const char *message, int data_selection);
int DataNameCmp(const Bacteria *data1, const Bacteria *data2);
int DataPIDCmp(const Bacteria *data1, const Bacteria *data2);
int DataASTCmp(const Bacteria *data1, const Bacteria *data2);
int DataSNumberCmp(const Bacteria *data1, const Bacteria *data2);

#endif //BACTERIA_LINKED_LIST_BACTERIA_CIRCLE_DOUBLE_LIST_H
