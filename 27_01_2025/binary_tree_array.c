#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree {
    int* array;
    int size;
} BinaryTree;

BinaryTree* create_tree(int n) {
    BinaryTree* tree = (BinaryTree*)malloc(sizeof(BinaryTree));
    tree->size = 0;
    tree->array = (int*)malloc(n* sizeof(int));
    return tree;
}

void insert(BinaryTree* tree, int value,int n) {
    if (tree->size == n) {
        printf("Full\n");
        return;
    }
    tree->array[tree->size] = value;
    tree->size++;
}

void delete_node(BinaryTree* tree, int value) {
    int index = -1;

    for (int i = 0; i < tree->size; i++) {
        if (tree->array[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Value not found\n");
        return;
    }

    tree->array[index] = tree->array[tree->size - 1];
    tree->size--;
}

void traversal(BinaryTree* tree) {
    if (tree->size == 0) return;
    
    for (int i = 0; i < tree->size; i++) {
        printf("%d ", tree->array[i]);
    }
    printf("\n");
}

int main() {
    int value;
    BinaryTree* tree = create_tree(10);

    while (scanf("%d", &value) == 1) {
        insert(tree, value,10);
        if (getchar() == '\n') break;
    }
    traversal(tree);

    delete_node(tree, 3);
    traversal(tree);

    free(tree->array);
    free(tree);
    return 0;
}
