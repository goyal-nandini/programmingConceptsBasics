// Create a menu-driven program to construct and manage a Binary Search Tree (BST). 
// The program should support insertion, deletion, and search operations while 
// maintaining tree properties, with users choosing the desired operation


#include<stdio.h>
#include<stdlib.h>

struct node *create(int);
struct node *insert(struct node *, int);
struct node *deleteNode(struct node *, int);
struct node *findMin(struct node *);
struct node *search(struct node *, int);
void inOrder(struct node *);

struct node {
    int data;
    struct node *left, *right;
};

int main(){
    struct node *root = NULL;
    int choice, value;
    while (1) {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display(In-Order)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                    printf("Enter values to insert into the BST (enter -1 to stop):\n");
                    while (1) {
                        printf("Enter value: ");
                        scanf("%d", &value);
                        if (value == -1) break;
                        root = insert(root, value);
                        printf("Inserted %d into BST.\n", value);
                    }
                    break;
            case 2:
                    printf("Enter value to delete: ");
                    scanf("%d", &value);
                    if (search(root, value)) {
                    root = deleteNode(root, value);
                    printf("Deleted %d from the BST.\n", value);
                    } else {
                        printf("Value %d not found in the BST.\n", value);
                    }
                    break;
            case 3:
                    printf("Enter value to search: ");
                    scanf("%d", &value);
                    if (search(root, value)) {
                        printf("Value %d found in the BST.\n", value);
                    } else {
                        printf("Value %d not found in the BST.\n", value);
                    }
                    break;
            case 4:
                    printf("In-Order traversal of BST is: ");
                    inOrder(root);
                    printf("\n");
                    break;        
            case 5:
                    printf("Exiting the program.\n");
                    break;
            default:
                    printf("Invalid choice! Please try again.\n");
                    break;
        }
        if(choice == 5){
            break;
        }
    }    
    return 0;
}
// to create new node
struct node *create(int item){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = item;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return newnode;
}
// to insert new node
struct node *insert(struct node *root, int data){
    if(root == NULL){
        return create(data);
    }

    if(data < root -> data){
        root -> left = insert(root -> left, data);
    } else if(data > root -> data){
        root -> right = insert(root -> right, data);
    }
    return root;
}

struct node *deleteNode(struct node *root, int data){
    if(root == NULL){
        return root;
    }
    // traverse
    if(data < root -> data){
        root -> left = deleteNode(root -> left, data);
    } else if(data > root -> data){
        root -> right = deleteNode(root -> right, data);
    } else{

        // case 1 node with no children
        if(root -> left == NULL && root -> right == NULL){
            free(root);
            return NULL;
        } 

        // case 2 node with only one child
        else if(root -> left == NULL){
            struct node *temp = root -> right;
            free(root);
            return temp; 
        } else if(root -> right == NULL){
            struct node *temp = root -> left;
            free(root);
            return temp;
        }

        //case 3 node with two children(inorder predecessor, smallest from right subtree)
        else{
            struct node *temp = findMin(root->right);
            root -> data = temp -> data;
            root -> right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

struct node *findMin(struct node *root){
    while (root != NULL && root -> left != NULL){
        root = root -> left;
    }
    return root;
}

void inOrder(struct node *root){
    if(root == NULL){
        return;
    } else {
        inOrder(root -> left);
        printf("%d ",root -> data);
        inOrder(root -> right);
    }
}

struct node *search(struct node *root, int data){
    if(root == NULL || root -> data == data){
        return root;
    } 

    if(data < root -> data){
        return search(root->left, data);
    } else{
        return search(root->right, data);
    }
}