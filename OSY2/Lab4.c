#include <stdio.h>
#include <stdlib.h>

struct listNode {
    int id;
    int status;
    int ValueProgram;
    int ValueAcc;
    struct listNode *nextPtr; // pointer to the next node
};

typedef struct listNode ListNode;

void Display(ListNode *node);
void GetData(ListNode **node);

int main(void) {
    ListNode *node = NULL;
    GetData(&node);
    Display(node);
    printf("End of Program\n");
    return 0;
}

void GetData(ListNode **node) {
    *node =(ListNode*)malloc(sizeof(ListNode));
    printf("PCB ID (1 to 3 digits, except 0) : ");
    scanf("%d", &((*node)->id));
    printf("PCB Status (1- ready, 2 - running, 3 - waiting) : ");
    scanf("%d", &((*node)->status));
    printf("Enter Process Counter: ");
    scanf("%d", &((*node)->ValueProgram));
    printf("Enter value of accumulator: ");
    scanf("%d", &((*node)->ValueAcc));
}

void Display(ListNode *node) {
    printf("the address of the node is: %p\n", node);
    printf("PCB ID: %d\n", node->id);
    printf("status (1:ready; 2: running; 3 finished) : %d\n", node->status);
    printf("the state of the process\n");
    printf("Value of Program Counter: %d\n", node->ValueProgram);
    printf("Value of accumulator: %d\n", node->ValueAcc);
}

