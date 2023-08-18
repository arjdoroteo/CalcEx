#include "stdio.h"
#include "string.h"
#include "history.h"
#include <stdlib.h>


const char* mathCase();
const char* converterCase();
const char* comparatorCase();
const char* bitwiseCase();
void clearHistory(struct node* head);

void showHistory(struct node* head);
node * add_end(struct node* head, const char* result);

int main ( void )
{
    char menuOps;
    const char* result;

    // creating the first node of linked list.
    node *head = malloc(sizeof(struct node));
    head->titleANDresult = "History: \n";
    head->next = NULL;


      
    do
    {
        printf("\nWelcome to Calculator! [M-MDAS+MODULO+POWER, H-DEC+HEX+BIN, C-COMPARATOR, B-BITWISE, D-CLEAR HISTORY, Q-EXIT]\n");
        printf("************************************************************************************************************\n\n");
        printf("Choose Menu: ");

        scanf(" %c", &menuOps);

        switch (menuOps)
        {
            
            // add end function adds a node at the end of the linked list using the returned value of chosen menu and operation

            case 'M':
            {
                add_end(head, mathCase());
                printf("Closing Submenu\n");
            }
            break;

            case 'H':
            {
                add_end(head, converterCase());
                printf("Closing Submenu\n"); 
            }
            break;
            case 'C':
            {
                add_end(head, comparatorCase());
                printf("Closing Submenu\n");
            }
            break;
            case 'B':
            {
                add_end(head, bitwiseCase());
                printf("Closing Submenu\n");
            }
            break;
            case 'D':
            {
                // Passes the value of head pointer to clearHistory to clear the history.
                clearHistory(head);
            }
            break;
            case 'S':
            {
                
                // Passes the value of head pointer as starting point for traversing and printing the history.
                printf("Showing History: \n\n");
                showHistory(head);
            }
        }


    } while (menuOps != 'Q');
    
    printf("Terminating Session");

    return 0;
}

//To run gcc -o app mDasMP.c dHb.c standardCalc.c comparator.c bitwise.c history.c -lm
// ./app