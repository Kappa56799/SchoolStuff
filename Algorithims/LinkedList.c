/* head_ref points to the start of the list */
#include <stdio.h>
#include <stdlib.h>

/*We use 2 structures, structure 1 defines the linked list and the structure 2 is a pointer to the nexct node of the list*/
struct Node //structure 1
{
    int data;
    struct Node* next; //structure 2 
};

//function signatures
void addNode(struct Node** head_ref, int new_data);
int countOccurences(struct Node* head, int num);

int main()
{
    struct Node *head = NULL; //we start with saying the node  head is empty (NULL)
    int data; //to store the values in the linked list
    int count; //to get the value returned from the functio 
    int CheckNum; 

    //for inputting data
    printf("\nPlease enter in 3 numbers\n");
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &data);
        addNode(&head, data); //inputs data into the function he gave us
    }

    printf("\nPick a number to check how many times it is in the list: ");
    scanf("%d", &CheckNum);
    
    struct Node *current = head; //assign the current value used in the structure as empty (NULL)
    while(current != NULL) //prints until current is  empty 
    {
        printf("%d ", current->data); //current pointer data
        current = current->next; //assigns current as the next value in the linked list
    }

    //we input the data values and the users input to check how many times it occurs in the list
    count = countOccurences(head,CheckNum);

    printf("\nThe number has been entered: %d times.", count);

    return 0;
}


void addNode(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
  
    struct Node *last = *head_ref;  /* used in step 5*/
   
    /* 2. put in the data  */
    new_node->data  = new_data;
  
    /* 3. This new node is going to be the last node, so make next 
          of it as NULL*/
    new_node->next = NULL;
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }  
       
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
   
    /* 6. Change the next of last node */
    last->next = new_node;
    return;    
}

//function to count occurences
int countOccurences(struct Node* head, int search_value)
{
    struct Node* current = head;  //assigns the values from earlier to current
    int count = 0;

    //while current is not empty (NULL)
    while(current != NULL)
    {
        //checks if current value is equal to user input
        if(current->data == search_value)
        {
            count++; //counter goes up
        }
        current = current->next; //else current moves to the next value
    }

    return count;
}