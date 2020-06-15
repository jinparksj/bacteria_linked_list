#include <stdio.h>
#include "../src/bacteriaData.h"
#include "../src/bacteria_array_linked_list.h"
#include "../src/bacteria_array_linked_list.c"
#define ARRAY_SIZE 30


typedef enum {
    TERMINATE,
    INSERT_FRONT,
    INSERT_REAR,
    POP_FRONT,
    POP_BACK,
    REMOVE_CURRENT,
    SEARCH_NAME,
    SEARCH_PID,
    SEARCH_AST,
    SEARCH_SNUMBER,
    PRINT_CURRENT,
    PRINT_ALL,
    CLEAR
} Menu;

Menu SelectMenu(void) {
    int i, ch;
    char *menu_description[] = {
            "Insert at Head", "Insert at Tail", "Pop from Front", "Pop from Back",
            "Remove at Current Node", "Search by Name", "Search by PID", "Search by AST", "Search by Sample Number",
            "Print Current Node", "Print All Nodes", "Clear All Nodes"
    };
    do {
        for (i = TERMINATE; i < CLEAR; i++) {
            printf("(%2d) %-18.18s  ", i+1, menu_description[i]);
            if ((i % 3) == 2) putchar('\n');
        }
        printf("(0) Terminate\n");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > CLEAR);

    return (Menu) ch;
}

int main(void) {
    Menu menu;
    LList llist;
    Initialize(&llist, ARRAY_SIZE);

    while (1) {
        Bacteria data;
        menu = SelectMenu();
        if (menu == TERMINATE) break;
        switch((int) menu) {
            case INSERT_FRONT:
                data = ScanData("Insert at Head", DATA_NAME | DATA_PID | DATA_AST | DATA_SNUMBER);
                InsertFront(&llist, &data);
                break;
            case INSERT_REAR:
                data = ScanData("Insert at Tail", DATA_NAME | DATA_PID | DATA_AST | DATA_SNUMBER);
                InsertRear(&llist, &data);
                break;
            case POP_FRONT:
                PopFront(&llist);
                break;
            case POP_BACK:
                PopBack(&llist);
                break;
            case REMOVE_CURRENT:
                RemoveCurrent(&llist);
                break;
            case SEARCH_NAME:
                data = ScanData("Search", DATA_NAME);
                if (Search(&llist, &data, DataNameCmp) != NULL) {
                    PrintCurrent(&llist);
                }
                else {
                    puts("There is no data with the name.");
                }
                break;
            case SEARCH_PID:
                data = ScanData("Search", DATA_PID);
                if (Search(&llist, &data, DataPIDCmp) != NULL) {
                    PrintCurrent(&llist);
                }
                else {
                    puts("There is no data with the PID result.");
                }
                break;
            case SEARCH_AST:
                data = ScanData("Search", DATA_AST);
                if (Search(&llist, &data, DataASTCmp) != NULL) {
                    PrintCurrent(&llist);
                }
                else {
                    puts("There is no data with the AST result.");
                }
                break;
            case SEARCH_SNUMBER:
                data = ScanData("Search", DATA_SNUMBER);
                if (Search(&llist, &data, DataSNumberCmp) != NULL) {
                    PrintCurrent(&llist);
                }
                else {
                    puts("There is no data with the sample number.");
                }
                break;
            case PRINT_CURRENT:
                PrintCurrent(&llist);
                break;
            case PRINT_ALL:
                Print(&llist);
                break;
            case CLEAR:
                Clear(&llist);
                break;
            default:
                break;
        }
    }
    Terminate(&llist);
}