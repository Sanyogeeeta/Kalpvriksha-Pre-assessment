#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} node;

node* create_node(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insertion(node** root, int value) {
    node* temp=*root;
    if(temp==NULL){
        *root=create_node(value);
        return;
    }
    if(temp->left==NULL){
        temp->left=create_node(value);
        return;
    }
    if(temp->right==NULL){
        temp->right=create_node(value);
        return;
    }
    insertion(&temp->left,value);
}

void deletion(node** root, int value) {
    node* temp=root;
    if(temp->value<value)
        deletion(&temp->left,value);
    else if(temp->value>value)
        deletion(&temp->right,value);
    else{
        if(temp->left==NULL&&temp->right==NULL){
            free(temp);
        }
        else if(temp->left==NULL){
            *root=temp->right;
            free(temp);
        }
        else if(temp->right==NULL){
            *root=temp->left;
            free(temp);
        }
        else{
            node* temp1=temp1->right;
            while(temp1->left!=NULL){
                temp1=temp1->left;
            }
            temp->value=temp1->value;
            deletion(&temp1->right,temp1->value);
        }

    }
}

void heapify(node* root){


}

void traversal(node* root) {
    if (root == NULL) return;
    printf("%d ", root->value);
    traversal(root->left);
    traversal(root->right);
}

int main() {
    int value;
    node* root = NULL;
    while (scanf("%d", &value) == 1) {
        insertion_end(&root, value);
        if (getchar() == '\n') break;
    }

    traversal(root);
    printf("\n");
    heapify(root);

    traversal(root);
    printf("\n");

    return 0;
}
