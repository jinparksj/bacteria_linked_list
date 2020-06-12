#ifndef BACTERIA_LINKED_LIST_BACTERIA_ARRAY_LINKED_LIST_H
#define BACTERIA_LINKED_LIST_BACTERIA_ARRAY_LINKED_LIST_H

#include "bacteriaData.h"

#define Null -1

typedef int Index;

typedef struct {
    Bacteria data;
    Index next;
    Index Dnext;
} Node;

typedef struct {
    Node *n;
    Index head;
    Index max;
    Index deleted;
    Index current;
} LList;

void Initialize(LList *llist, int size);
Index Search(LList *llist, const Bacteria *data, int compare(const Bacteria *data1, const Bacteria *data2));
void InsertFront(LList *llist, const Bacteria *data);
void InsertRear(LList *llist, const Bacteria *data);
void PopFront(LList *llist);
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




#endif //BACTERIA_LINKED_LIST_BACTERIA_ARRAY_LINKED_LIST_H
