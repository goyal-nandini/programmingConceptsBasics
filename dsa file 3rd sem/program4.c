// Develop a menu-driven program to handle a circular linked list, supporting 
// insertion, deletion, reversal and traversal operations. The program should enable 
// the user to select and execute various operations on the list

// createList;
// traverseList;(or print, display)
// insertNode;
// deleteNode;
// reverseList;

#include <stdio.h>
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
int countNode();

int main(){
        char restart;
        int entry;
    do{
        printf("Welcome to the menu driven program!\nYou have to set values to get started.\n");
        createList();
        printf("Instructions:\nPress 1 for traversing the Linked List,\n2 for inerting node in the list,\n3 for deleting node from the list,\n4 for reversing the linked list,\n5 to know the number of nodes in the linked list and\n0 to exit the program.");
    
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
                printf("Instructions:\nYou can insert node at three different positions,\nPress 1 for inserting at beginning,\n2 for inserting at end,\n3 for inserting at a specific position.");
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
                printf("The number of nodes are: %d\n", countNode());
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

struct node{
    int data;
    struct node *next;
};
    struct node *tail, *newnode, *temp;
    int choice = 1, count = 0;

void createList(){
    tail = NULL;
    printf("Enter data (press -1 to stop entering data):\n");
    while(1){
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode -> next = 0;
        if(newnode -> data == -1) break;
        if(tail == 0){
            tail = newnode;
            tail -> next = newnode;
        } else {
            newnode -> next = tail -> next;
            tail -> next = newnode;
            tail = newnode;
        }
    }
}
void traverseList(){
    struct node *temp;
    if(tail == NULL){
        printf("The list is empty.");
    } else {
        temp = tail->next;
        printf("The data inside the nodes are:\n");
        while(temp -> next != tail -> next){
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("%d ",temp -> data);
    }
}

int countNode(){
    temp = tail->next;
    count = 0;
    while(temp != tail){
        // printf("%d ", temp -> data);
        count ++;
        temp = temp -> next;
    }
    // printf("The number of nodes are: %d\n", count);
    return count+1;

}
void insertBeg(){

}
void insertEnd(){

}
void insertAtPos(){

}
void deleteBeg(){

}
void deleteEnd(){

}
void deleteFromPos(){

}
void reverseList(){

}
