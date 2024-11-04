// Design and implement a menu-driven program to perform binary tree traversals, 
// including in-order, pre-order, and post-order traversals. The program should allow 
// users to build a binary tree and select traversal methods to display the result.

// createBT
// in-order, 
// pre-order, 
// post-order

#include <stdio.h>
#include <stdlib.h>

struct node *create();
void inOrder(struct node *);
void preOrder(struct node *);
void postOrder(struct node *);

struct node{
    int data;
    struct node *left, *right;
};

int main(){
    int choice;
    struct node *root;
    root = NULL;
    printf("Binary Tree Construction Program\n");
    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Create a Binary Tree\n");
        printf("2. Traverse the tree\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                root = create();
                break;
            case 2:{
                if (root == NULL) {
                    printf("Please create the binary tree first.\n");
                } else {
                    while(1){
                        int pick;
                        printf("\n--- Traversal Menu ---\n");
                        printf("1. In-order Traversal\n");
                        printf("2. Pre-order Traversal\n");
                        printf("3. Post-order Traversal\n");
                        printf("4. Exit\n");
                        printf("Enter your choice(Traversing Options): ");
                        scanf("%d", &pick);
                        switch (pick) {
                            case 1:
                                printf("In-order Traversal: ");
                                inOrder(root);
                                printf("\n");
                                break;
                            case 2:
                                printf("Pre-order Traversal: ");
                                preOrder(root);
                                printf("\n");
                                break;
                            case 3:
                                printf("Post-order Traversal: ");
                                postOrder(root);
                                printf("\n");
                                break;
                            case 4:
                                printf("Exiting from Traversal Menu...\n");
                                break;
                            default:
                                printf("Invalid choice. Please try again.\n");
                                break;
                        }
                            if (pick == 4) {  
                                break;  
                            }    
                    }
                }            
                break;
            }    
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if (choice == 3) {  
            break;  
        }
    }
    return 0;
}

struct node *create(){
    struct node *newnode;
    int item;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data(press -1 for not to enter): ");
    scanf("%d", &item);

    if(item == -1){
        return NULL;
    }
    newnode -> data = item;
    printf("Enter left child of %d\n", item);
    newnode -> left = create();

    printf("Enter right child of %d\n", item);
    newnode -> right = create();

    return newnode;
}
// left root right
void inOrder(struct node *root){
    if(root == NULL){
        return;
    } else {
        inOrder(root -> left);
        printf("%d ",root -> data);
        inOrder(root -> right);
    }
}
// root left right
void preOrder(struct node *root){
    if(root == NULL){
        return;
    } else {
        printf("%d ",root -> data);
        preOrder(root -> left);
        preOrder(root -> right);
    }
}
// left right root
void postOrder(struct node *root){
    if(root == NULL){
        return;
    } else{
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d ",root -> data);
    }    
}





