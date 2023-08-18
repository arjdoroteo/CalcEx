#include "history.h"
#include <stdlib.h>
#include "stdio.h"


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

    // printf("Address: %p\n", ptr-> next);
    // printf("Value: %s\n", temp->titleANDresult);
}


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

