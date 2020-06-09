#include <stdio.h>
#include "../src/bacteria_linked_list.h"

typedef enum {
    TERMINATE,
    INSERT_FRONT,
    INSERT_REAR,
    POP_FRONT,
    POP_BACK,
    REMOVE_CURRENT,
    SEARCH,
    PRINT_CURRENT,
    PRINT_ALL,
    CLEAR
} Menu;

Menu SelectMenu(void) {
    int i, ch = 1;
    char *menu_description[] = {
            "Insert at Head", "Insert at Tail", "Pop from Front", "Pop from Back",
            "Remove at Current Node", "Search", "Print Current Node", "Print All Nodes", "Clear All Nodes"
    };

    while (ch < TERMINATE || ch > CLEAR){
        for (i = TERMINATE; i < CLEAR; i++) {
            printf("(%2d) %-18.18s", i+1, menu_description[i]);
            if ((i % 3) == 2) putchar('\n');
        }
        printf("(0) Terminate");
        scanf("%d", &ch);
    }
    return (Menu) ch;
}

int main(void) {
    Menu menu;
    LList llist;
    Initialize(&llist);

    while (menue != TERMINATE) {
        Bacteria data;
        switch(menu = SelectMenu()) {
            case INSERT_FRONT:
                data =
                break;
        }
    }


    return 0;
}

