#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next; 
};

typedef struct Node Node;
void addNode(Node** head_ref, int new_data);

int main()
{
    Node *head = NULL; 
    int data;
    int count;
    int CheckNum; 

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &data);
        addNode(&head, data); 
    }

    Node *current = head; 
    while(current != NULL) 
    {
        printf("%d ", current->data); 
        current = current->next; 
    }

    return 0;
}

void addNode(struct Node** head_ref, int new_data)
{
    Node* new_node = malloc(sizeof(Node));
    Node *last = *head_ref;  
   
    new_node->data  = new_data;
  
    new_node->next = NULL;
  
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }  
       
    while (last->next != NULL)
        last = last->next;
   
    last->next = new_node;
    return;    
}

