#ifndef BACTERIA_LINKED_LIST_BACTERIA_ARRAY_LINKED_LIST_H
#define BACTERIA_LINKED_LIST_BACTERIA_ARRAY_LINKED_LIST_H

#include "bacteriaData.h"

#define Null -1
#define DATA_NAME       1
#define DATA_AST        2
#define DATA_PID        4
#define DATA_SNUMBER    8

typedef int Index;

typedef struct {
    Bacteria data;  //data
    Index next;     //next node
    Index Dnext;    //prelist's next node
} Node;

typedef struct {
    Node *n;        //list array
    Index head;     //head node
    Index max;      //tail node
    Index deleted;  //prelist head node
    Index current;  //selected node
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
