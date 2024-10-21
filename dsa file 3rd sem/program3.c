// Implement a menu-driven program to manage a singly linked list. The program 
// should support operations such as insertion, deletion, reversal, and traversal and 
// allow the user to interactively perform these tasks

// createList;
// traverseList;(or print, display)
// insertNode;
// deleteNode;
// reverseList;

#include<stdio.h>
#include<stdlib.h>

void createList();
void traverseList();
void insertBeg();
void insertEnd();
void insertAfter();
void insertBefore();
void deleteBeg();
void deleteEnd();
void deleteFromPos();
void reverseList();
void countNode();

struct node{
    int data;
    struct node *next;
};
    struct node *head = NULL, *newnode, *temp;
    int choice = 1, entry, count = 0;

int main(){
    char restart;
    do{
        printf("Welcome to the menu driven program!\nYou have to set values to get started.\n");
        createList();
        printf("Instructions:\nPress 1 for traversing the Linked List,\n2 for inerting node in the list,\n3 for deleting node from the list,\n4 to know the number of nodes in the linked list and\n0 to exit the program.");
    
        do{

            printf("\n-----------------------------\n-----------------------------");
            printf("\nEnter your choice: ");  // Prompt user to enter a choice
            scanf("%d", &entry);           // Read the input
            switch (entry)
            {
            case 1: 
                printf("The list is: ");
                traverseList();
                break;
            case 2:
                printf("Instructions:\nYou can insert node at three different positions,\nPress 1 for inserting at beginning,\n2 for inserting at end,\n3 for inserting after a specific position and\n4 for inserting before a specific position.");
                int choose1;
                printf("\n-----------------------------");
                printf("\nEnter choice(for inserting node): ");
                scanf("%d", &choose1);
                switch (choose1)
                {
                    case 1:
                        insertBeg();
                        printf("The new linked list is:\n");
                        traverseList();
                        break;
                    case 2:
                        insertEnd();
                        printf("The new linked list is:\n");
                        traverseList();
                        break;
                    case 3:
                        insertAfter();
                        // printf("The new linked list is(after inserting node next to another node):\n");
                        // traverseList();
                        break;
                    case 4:
                        insertBefore();
                        // printf("The new linked list is(after inserting node before another node):\n");
                        // traverseList();
                        break;            
                    default:
                        printf("Invalid Choice! Please enter valid number.");
                        break;
                }
                break;
            case 3: 
                printf("Instructions:\nYou can delete node from three different positions,\nPress 1 for deleting from beginning,\n2 for deleting from end,\n3 for deleting from any specific position.");
                int choose;
                printf("\n-----------------------------");
                printf("\nEnter choice(for deleting node): ");
                scanf("%d", &choose);
                switch (choose)
                {
                    case 1:
                        deleteBeg();
                        printf("The new linked list is:\n");
                        traverseList();
                        break;
                    case 2:
                        deleteEnd();
                        printf("The new linked list is:\n");
                        traverseList();
                        break;
                    case 3:
                        deleteFromPos();
                        printf("The new linked list is:\n");
                        traverseList();
                        break;
                    default:
                        printf("Invalid Choice! Please enter a valid number.");
                        break; 
                }           
                break;
            case 4:
                printf("The new list after reversing the list is: ");
                reverseList();
                traverseList();
                break; 
            case 5:
                countNode();
                break;       
            case 0:
                printf("\nExiting the program.");  
                break;  
            default:
                printf("Invalid Choice! Please enter valid number.");
                break;
            }
    } while (entry != 0);
    printf("Do you want to restart the program? (Y/N): ");
    scanf(" %c", &restart);
    } while(restart == 'y' || restart == 'Y');
    printf("\nThank you for using the program.");  
    
    return 0;
}

void createList(){ 
    // this is also correct but ot make it more user-friendly lest do it othe rway!!
    // while(choice){
    //     newnode = (struct node*)malloc(sizeof(struct node)); 
    //     printf("Enter data: ");
    //     scanf("%d", &newnode -> data);
    //     newnode -> next = NULL;
    //     if(head == NULL){
    //         head = temp = newnode;
    //     } else{
    //         temp -> next = newnode;
    //         temp = newnode;
    //     }
    //     printf("Do you want to continue?(0/1)\n");
    //     scanf("%d", &choice);
    // }
    printf("Enter values to create the linked list (enter -1 to stop):\n");
    
    while (1) {
        newnode = (struct node*)malloc(sizeof(struct node)); 
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        if (newnode->data == -1) {  // Exit condition
            free(newnode);  // No need to add this node
            break;
        }
        newnode->next = NULL;
        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void traverseList(){
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    temp = head;
    while(temp != NULL){
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

void countNode(){
    temp = head;
    count = 0;
    while(temp != NULL){
        // printf("%d ", temp -> data);
        count ++;
        temp = temp -> next;
    }
    printf("The number of nodes are: %d\n", count);
}

void insertBeg(){
    newnode = (struct node*)malloc(sizeof(struct node)); 
    printf("Enter data you want to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = head;
    head = newnode;
}

void insertEnd(){
    newnode = (struct node*)malloc(sizeof(struct node)); 
    printf("Enter data you want to insert: ");
    scanf("%d", &newnode -> data);
    newnode -> next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    // temp = head;
    // while(temp -> next != NULL){
    //     temp = temp -> next;
    // }
    // temp -> next = newnode;
}

void insertAfter(){
    int pos, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if(pos > count || pos < 1){
        printf("Invalid Position!\n");
        return;
    } else {
        temp = head;
        while(i < pos){
            temp = temp -> next;
            i++;
        }
        newnode = (struct node*)malloc(sizeof(struct node)); 
        printf("Enter data you want to insert: ");
        scanf("%d", &newnode -> data);
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
    printf("The new linked list is(after inserting node after position %d):\n", pos);
    traverseList();
}

void insertBefore(){
    int pos, i = 1;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    if(pos > count+1 || pos <= 1){
        printf("Invalid Position!\n");
        return;
    } else {
        temp = head;
        while(i < pos-1){
            temp = temp -> next;
            i++;
        }
        newnode = (struct node*)malloc(sizeof(struct node)); 
        printf("Enter data you want to insert: ");
        scanf("%d", &newnode -> data);
        newnode -> next = temp -> next;
        temp -> next = newnode;
    }
    printf("The new linked list is(after inserting node before postion %d):\n", pos);
    traverseList();
}

void deleteBeg(){
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr;
    ptr = head;
    head = head -> next;
    free(ptr);
    count--;
}

void deleteEnd(){
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr, *prevnode;
    ptr = head;
    while(ptr -> next != NULL){
        prevnode = ptr;
        ptr = ptr -> next;
    }
    if(ptr == head){
        head = NULL;
    } else {
        prevnode -> next = NULL;
    }
    free(ptr);
    count--;
}

void deleteFromPos(){
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *ptr, *nextnode;
    int pos, i = 1;
    
    printf("Enter position: ");
    scanf("%d",&pos);
    // Check if the position is valid
    if (pos < 1 || pos > count) {
        printf("Invalid position!\n");
        return;
    } else {
        ptr = head;
        while(i < pos-1){
            ptr = ptr -> next;
            i++;
        }
    }
    
    nextnode = ptr -> next;
    ptr -> next = nextnode -> next;
    free(nextnode);
    // Decrease the node count after deletion
    count--;
}

void reverseList(){
    struct node *prevnode, *currentnode, *nextnode;
    prevnode = NULL;
    currentnode = nextnode = head;
    while(nextnode != NULL){
        nextnode = nextnode -> next;
        currentnode -> next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}
