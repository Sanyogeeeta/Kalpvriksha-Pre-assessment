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

void insertion_end(node** root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
        return;
    }
    if ((*root)->left == NULL) {
        (*root)->left = create_node(value);
        return;
    }
    if ((*root)->right == NULL) {
        (*root)->right = create_node(value);
        return;
    }
    insertion_end(&(*root)->left, value);
}

void delete_node(node** root, int value) {
    if (*root == NULL) return;

    node* temp = *root;
    if (temp->value == value) {
        if (temp->left == NULL && temp->right == NULL) {
            free(temp);
            *root = NULL;
        }
        else if (temp->left == NULL) {
            *root = temp->right;
            free(temp);
        } else if (temp->right == NULL) {
            *root = temp->left;
            free(temp);
        }
        else {
            node* successor = temp->right;
            while (successor && successor->left) {
                successor = successor->left;
            }
            temp->value = successor->value;
            delete_node(&temp->right, successor->value);
        }
        return;
    }

    if (value < temp->value) {
        delete_node(&temp->left, value);
    }
    
    else {
        delete_node(&temp->right, value);
    }
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
    delete_node(&root, 3);

    traversal(root);
    printf("\n");

    return 0;
}
