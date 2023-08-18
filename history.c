#include "history.h"
#include <stdlib.h>
#include "stdio.h"


// adds new node to end of list with the received value of result
node * add_end(struct node* head,  char* result)
{
    node *ptr, *temp;
    ptr = head;
    temp = malloc(sizeof(struct node));
    temp->titleANDresult = result; 
    temp->next = NULL;

    while(ptr -> next != NULL)

    {
        ptr = ptr -> next;
    }

    ptr -> next = temp;
}

// show history checks the address pointing to the next node and if NULL it means there is only one node and list is empty
// otherwise traverses the link and prints the values
void showHistory(struct node* head)
{
    int count = 0;

    if ( head -> next == NULL )
    {
        printf("History is Empty");
    }
    
    else 
    {
        node *ptr = NULL;
        ptr = head;
        while (ptr != NULL)
        {
            printf("%d. %s\n\n",count, ptr->titleANDresult);
            count++;
            ptr = ptr->next;
        }
    }
    
    
}

// clear history function checks the address part of first node and if NULL, it means only the start node exist and list is empty
// if there is an address in the node it clears it and loops to clear the rest of the list, retaining only the first node.
void clearHistory(struct node* head)
{
    node *ptr, *next;

    
    ptr = head;

    ptr = ptr -> next;
    if ( ptr == NULL)
    {
        printf ("History is currently empty");
    }
    
    else if ( ptr != NULL)
    {
        while ( ptr != NULL )
        {
            next = ptr -> next;
            free(ptr);
            ptr = next;
        }      

        printf("History cleared! \n\n");
    }

    head -> next = NULL;
}

