// Develop a menu-driven program to handle a circular linked list, supporting 
// insertion, deletion, reversal and traversal operations. The program should enable 
// the user to select and execute various operations on the list

#include <stdio.h>
#include<stdlib.h>

void createList();
void traverseList();
void insertBeg();
void insertEnd();
void insertAtPos();
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
                        insertAtPos();
                        // printf("The new linked list is(after inserting node next to another node):\n");
                        // traverseList();
                        break;
                    // case 4:
                    //     insertBefore();
                    //     // printf("The new linked list is(after inserting node before another node):\n");
                    //     // traverseList();
                    //     break;            
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
    struct node *tail, *newnode;
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
    struct node *temp = tail->next;
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
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newnode->data);
    newnode -> next = 0;
    if(tail == 0){
        tail = newnode;
        tail -> next = newnode;
    } else {
        newnode -> next = tail -> next;
        tail -> next = newnode;
    }
    printf("The new list after inserting element %d at the beginning is:\n",newnode->data);
    traverseList();
}
void insertEnd(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert at end: ");
    scanf("%d", &newnode->data);
    newnode -> next = 0;
    if(tail == 0){
        tail = newnode;
        tail -> next = newnode;
    } else {
        newnode -> next = tail -> next;
        tail -> next = newnode;
        tail = newnode;
    }
    printf("The new list after inserting element %d at the end is:\n",newnode->data);
    traverseList();
}
void insertAtPos(){
    struct node *temp, *newnode;
    int pos, i=1;
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos < 0 || pos > countNode()){
        printf("Invalid Position!\n");
    } else if(pos == 1){
        insertBeg();
    } else{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert at position %d: ",pos);
        scanf("%d", &newnode->data);
        newnode -> next = 0;
        temp = tail -> next;
        while(i < pos - 1){
            temp = temp -> next;
            i++;
        }
        newnode -> next = temp -> next;
        temp -> next = newnode;
        printf("The new list after inserting element %d at the end is:\n",newnode->data);
        traverseList();
    }
}
void deleteBeg(){
    struct node *temp;
    temp = tail -> next;
    if(tail == 0){
        printf("The list is empty.");
    } else if(temp == tail){
        tail = 0;
        free(temp);
    } else{
        tail -> next = temp -> next;
        free(temp);
    }
}
void deleteEnd(){
    struct node *current, *previous;
    current = tail -> next;
    if(tail == 0){
        printf("The list is empty.");
    } else if (current -> next == current){
        tail = 0;
        free(current);
    } else{
        while(current -> next != tail -> next){
            previous = current;
            current = current -> next;
        }
        previous -> next = tail -> next;
        tail = previous;
        free(current);
    }
}
void deleteFromPos(){
    struct node *current, *nextnode;
    int pos, i=1;
    current = tail -> next;
    printf("Enter position from where you want to delete: ");
    scanf("%d", &pos);
    if(pos < 1 || pos > countNode()){
        printf("Invalid poistion!\n");
    } else if(pos == 1){
        deleteBeg();
        return;
    } else if(pos == countNode()){
        deleteEnd();
        return;
    }else{
        while(i < pos - 1){
            current = current -> next;
            i++;
        }
        nextnode = current -> next;
        current -> next = nextnode -> next;
        free(nextnode);
    }
}
void reverseList(){
    struct node *prev, *current, *nextnode;
    
    if(tail == 0){
        printf("The list is empty.");
        return;
    } 
    current = tail -> next;
    nextnode = current -> next;

    if(tail -> next == tail){
        traverseList();
    } else{
        while(current != tail){
            prev = current;
            current = nextnode;
            nextnode = current -> next;
            current -> next = prev;
        }
        nextnode -> next = tail;
        tail = nextnode;
    }
}
