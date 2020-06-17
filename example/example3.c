#include <stdio.h>
#include "../src/bacteriaData.h"
#include "../src/bacteria_circle_double_list.h"
#include "../src/bacteria_circle_double_list.c"

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
    NEXT,
    PREV,
    CLEAR
} Menu;

Menu SelectMenu(void) {
    int i, ch;
    char *menu_description[] = {
            "Insert at Head", "Insert at Tail", "Pop from Front", "Pop from Back",
            "Remove at Current Node", "Search by Name", "Search by PID", "Search by AST", "Search by Sample Number",
            "Print Current Node", "Print All Nodes", "Move to Next Node", "Move to Previous Node", "Clear All Nodes"
    };

    do {
        for (i = TERMINATE; i < CLEAR; i++) {
            printf("(%2d) %-22.22s  ", i+1, menu_description[i]);
            if ((i % 3) == 2) putchar('\n');
        }
        printf("(0) Terminate\n");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > CLEAR);

    return (Menu) ch;
}

int main(void) {
    Menu menu;
    DList dlist;
    Initialize(&dlist);

    while (1) {
        Bacteria data;
        menu = SelectMenu();
        if (menu == TERMINATE) break;
        switch((int) menu) {
            case INSERT_FRONT:
                data = ScanData("Insert at Head", DATA_NAME | DATA_PID | DATA_AST | DATA_SNUMBER);
                InsertFront(&dlist, &data);
                break;
            case INSERT_REAR:
                data = ScanData("Insert at Tail", DATA_NAME | DATA_PID | DATA_AST | DATA_SNUMBER);
                InsertRear(&dlist, &data);
                break;
            case POP_FRONT:
                PopFront(&dlist);
                break;
            case POP_BACK:
                PopBack(&dlist);
                break;
            case REMOVE_CURRENT:
                RemoveCurrent(&dlist);
                break;
            case SEARCH_NAME:
                data = ScanData("Search", DATA_NAME);
                if (Search(&dlist, &data, DataNameCmp) != NULL) {
                    PrintCurrent(&dlist);
                }
                else {
                    puts("There is no data with the name.");
                }
                break;
            case SEARCH_PID:
                data = ScanData("Search", DATA_PID);
                if (Search(&dlist, &data, DataPIDCmp) != NULL) {
                    PrintCurrent(&dlist);
                }
                else {
                    puts("There is no data with the PID result.");
                }
                break;
            case SEARCH_AST:
                data = ScanData("Search", DATA_AST);
                if (Search(&dlist, &data, DataASTCmp) != NULL) {
                    PrintCurrent(&dlist);
                }
                else {
                    puts("There is no data with the AST result.");
                }
                break;
            case SEARCH_SNUMBER:
                data = ScanData("Search", DATA_SNUMBER);
                if (Search(&dlist, &data, DataSNumberCmp) != NULL) {
                    PrintCurrent(&dlist);
                }
                else {
                    puts("There is no data with the sample number.");
                }
                break;
            case PRINT_CURRENT:
                PrintCurrent(&dlist);
                break;
            case PRINT_ALL:
                Print(&dlist);
                break;
            case NEXT:
                Next(&dlist);
                break;
            case PREV:
                Prev(&dlist);
                break;
            case CLEAR:
                Clear(&dlist);
                break;
            default:
                break;
        }
    }
    Terminate(&dlist);

    return 0;
}

