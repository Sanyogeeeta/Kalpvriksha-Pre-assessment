#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* left,*right;
}node;

void swap(node* n1,node* n2){
    int temp=n1->value;
    n1->value=n2->value;
    n2->value=temp;
}

node* create_node(int value){
    node* new_node=malloc(sizeof(node));
    new_node->left=NULL;
    new_node->right=NULL;
    new_node->value=value;
    return new_node;
}

void insertion(node** root,int value){
    node* new_node=create_node(value);
    
    if(*root==NULL){
        *root=new_node;
        return;
    }
    if((*root)->left==NULL){
        (*root)->left=new_node;
        return;
    }
    if((*root)->right==NULL){
        (*root)->right=new_node;
        return;
    }

    insertion(&(*root)->left, value);
    // if((*root)->left==NULL)insertion(&(*root)->left,value);
    // else insertion(&(*root)->right,value);
}

void heapify(node* root){
    if(root==NULL)return;
    node* largest=root;
    node* left=root->left;
    node* right=root->right;
    if(left && largest->value<left->value)
        largest=left;
    if(right && largest->value<right->value)
        largest=right;
    
    if(largest!=root){
        swap(largest,root);
        heapify(largest);
    }    
}

void infix(node* root){
    if(root==NULL)return;
    node* current=root;
    infix(root->left);
    printf("%d ",root->value);
    infix(root->right);
}

int main(){
    int n,value;
    scanf("%d",&n);

    node* root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        insertion(&root,value);
    }
    
    infix(root);
    heapify(root);
    infix(root);
    return 0;
}