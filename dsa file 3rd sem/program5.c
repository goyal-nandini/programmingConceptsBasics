// Create a menu-driven program that implements a stack using both array and linked 
// list data structures. The program should support stack operations such as push, pop,
// peek, and display, allowing the user to perform these operations interactively.

// array: createStack() displayStack() pushStack() popStack() peekStack()
// linked list: createStack() displayStack() pushStack() popStack() peekStack()
#include<stdio.h>
#include<stdlib.h>

void pushArray();
void popArray();
void peekArray();
void displayArray();

void pushLinkedList();
void popLinkedList();
void peekLinkedList();
void displayLinkedList();

int main() {
    int choice, stackType;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Use Stack with Array\n");
        printf("2. Use Stack with Linked List\n");
        printf("3. Exit\n");
        printf("Choose the stack implementation: ");
        scanf("%d", &stackType);

        if (stackType == 1) {
            do {
                printf("\n--- Stack using Array ---\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Peek\n");
                printf("4. Display\n");
                printf("5. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: pushArray(); break;
                    case 2: popArray(); break;
                    case 3: peekArray(); break;
                    case 4: displayArray(); break;
                    case 5: break;
                    default: printf("Invalid choice!\n");
                }
            } while (choice != 5);
        } else if (stackType == 2) {
            do {
                printf("\n--- Stack using Linked List ---\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Peek\n");
                printf("4. Display\n");
                printf("5. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: pushLinkedList(); break;
                    case 2: popLinkedList(); break;
                    case 3: peekLinkedList(); break;
                    case 4: displayLinkedList(); break;
                    case 5: break;
                    default: printf("Invalid choice!\n");
                }
            } while (choice != 5);
        } else if (stackType == 3) {
            printf("Exiting program.\n");
        } else {
            printf("Invalid choice! Please choose 1, 2, or 3.\n");
        }
    } while (stackType != 3);

    return 0;
}

#define MAX 5
int stack[MAX], top = -1;

// Push operation
void pushArray() {
    int value;
    // if (top == MAX - 1) {
    //     printf("Stack Overflow! Unable to push.\n");
    // } else {
    //     printf("Enter value to push: ");
    //     scanf("%d", &value);
    //     top++;
    //     stack[top] = value;
    //     printf("%d pushed to stack.\n", value);
    // }
    while(1) {
        printf("Enter value to push (-1 to stop): ");
        scanf("%d", &value);
        if (value == -1) {
            break;  // Exit the loop if user enters -1
        } 
        if (top == MAX - 1) {
                printf("Stack Overflow! Unable to push.\n");
        } else {
            top++;
            stack[top] = value;
            printf("%d pushed to stack.\n", value);
        }     
    }
}

// Pop operation
void popArray() {
    if (top == -1) {
        printf("Stack Underflow! Unable to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
}

// Peek operation
void peekArray() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element is %d\n", stack[top]);
    }
}

// Display stack
void displayArray() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

struct node{
    int data;
    struct node* next;
};

struct node *topLL = NULL;

void pushLinkedList(){
    // int value;
    // printf("Enter value: ");
    // scanf("%d",&value);
    // struct node *newnode;
    // newnode = (struct node*)malloc(sizeof(struct node));
    // if (newnode == NULL) {
    //     printf("Memory allocation failed.\n");
    //     return;
    // }
    // newnode -> data = value;
    // newnode -> next = topLL;
    // topLL = newnode;
    // printf("%d pushed to stack.\n", value);
// same logic but idea behind is different 
    int value;
    while (1) {  // Infinite loop to keep asking for input
        printf("Enter value to push (-1 to stop): ");
        scanf("%d", &value);

        if (value == -1) {
            break;  // Exit the loop if user enters -1
        }
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }
        newnode->data = value;
        newnode->next = topLL;
        topLL = newnode;
        printf("%d pushed to stack.\n", value);
    }
}
void popLinkedList(){
    struct node *ptr;
    ptr = topLL;
    if(topLL == NULL){
        printf("Stack Underflow! UNable to pop.");
    } else{
        printf("%d popped from stack.", topLL -> data);
        topLL = topLL -> next;
        free(ptr);
    }
}
void peekLinkedList(){
    if(topLL == NULL){
        printf("Stack is empty.");
    } else{
        printf("Top element is %d", topLL -> data);
    }
}
void displayLinkedList(){
    struct node *temp;
    temp = topLL;
    if(topLL == NULL){
        printf("Stack is empty.");
    } else{
        printf("Stack elements are: ");
        while(temp != NULL){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }

}