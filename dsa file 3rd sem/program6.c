// Develop a menu-driven program to implement a queue using both array and linked 
// list data structures. The program should allow the user to perform enqueue, 
// dequeue, and display operations with appropriate error handling.

#include<stdio.h>
#include<stdlib.h>

void menu();
void enqueueArray();
void dequeueArray();
void displayArray();
void enqueueLinkedList();
void dequeueLinkedList();
void displayLinkedList();

int main(){
    int choice;
        do {
        menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                enqueueArray();
                break;
            case 2:
                dequeueArray();
                break;
            case 3:
                displayArray();
                break;
            case 4:
                enqueueLinkedList();
                break;
            case 5:
                dequeueLinkedList();
                break;
            case 6:
                displayLinkedList();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 7);
    return 0;
}

void menu() {
    printf("\n---- Queue Menu ----\n");
    printf("1. Enqueue (Array)\n");
    printf("2. Dequeue (Array)\n");
    printf("3. Display (Array)\n");
    printf("4. Enqueue (Linked List)\n");
    printf("5. Dequeue (Linked List)\n");
    printf("6. Display (Linked List)\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

#define N 5
int queue[N], front = -1, rear = -1;

void enqueueArray(){
    int value;
    printf("Enter values to enqueue (enter -1 to stop): ");
    while(1){
        if(rear == N-1){
            printf("Queue Overflow!");
        } else if(front == -1 && rear == -1){
            // printf("Enter value to enqueue: ");
            scanf("%d", &value);
            if (value == -1) break;  // Stop condition
            front = rear = 0;
            queue[rear] = value;
        } else{
            // printf("Enter value to enqueue: ");
            scanf("%d", &value);
            if (value == -1) break;  // Stop condition
            rear ++;
            queue[rear] = value;   
        }
        printf("Enqueued %d\n", value);
    }
    
}
void dequeueArray(){
    if(front == -1 && rear == -1){
        printf("Queue Underflow!");
    } else if(front == rear){
        front = rear -1;
    } else{
        front++;
        printf("%d value dequeued.", queue[front]);
    }
}
void displayArray(){
    if(front == -1 && rear == -1){
        printf("The queue is empty.");
    } else{
        printf("The elements of queue are: ");
        for(int i = front; i < rear +1; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }  
}

struct node{
    int data;
    struct node *next;
};
struct node *frontLL = NULL;
struct node *rearLL = NULL;

void enqueueLinkedList(){
    struct node *newnode;
    int item;
    printf("Enter values to enqueue (enter -1 to stop): ");
    while (1) {
        scanf("%d", &item);
        if (item == -1) break;  // Stop condition

        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        // printf("Enter value to enqueue: ");
        // scanf("%d", &item);
        newnode -> data = item;
        newnode -> next = NULL;
        if(frontLL == NULL || rearLL == NULL){
            frontLL = rearLL = newnode;
        } else{
            rearLL -> next = newnode;
            rearLL = newnode;
        }
        printf("Enqueued %d\n", item);
    }    
}

void dequeueLinkedList(){
    struct node *temp;
    temp = frontLL;
    if(frontLL == NULL && rearLL == NULL){
        printf("Queue is empty.");
    } else{
        printf("%d is dequeued from the queue.", frontLL -> data);
        frontLL = frontLL -> next;
        free(temp);
    }
}

void displayLinkedList(){
    struct node *temp;
    if(frontLL == NULL && rearLL == NULL){
        printf("Queue is empty.");
    } else{
        temp = frontLL;
        printf("The elemets of the queue are: ");
        while(temp != NULL){
            printf("%d ", temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}