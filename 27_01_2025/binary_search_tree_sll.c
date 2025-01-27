#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* left,*right;
}node;

node* create_node(int value){
    node* new_node=malloc(sizeof(node));
    new_node->value=value;
    new_node->right=NULL;
    new_node->left=NULL;
    return new_node;
}

void insertion_end(node** root,int value){
    node* new_node=create_node(value);
    if(*root==NULL){
        *root=new_node;
        return;
    }
    node* temp=*root;
    if(value<temp->value)    
        insertion_end(&temp->left,value);
    else 
        insertion_end(&temp->right,value);
}

void delete_node(node** root,int value){
    node* temp=*root;
    if(*root==NULL)return;
    if(temp->value>value)
        delete_node(&temp->left,value);
    else if(temp->value<value)
        delete_node(&temp->right,value);
    else{
        if(temp->left==NULL&&temp->right==NULL){
            free(temp);
            *root=NULL;
        }
        else if(temp->left==NULL){
                node* toFree=temp;
                *root=temp->right;
                free(toFree);
        }
        else if(temp->right==NULL){
                node* toFree=temp;
                *root=temp->left;
                free(toFree);
        }
        else{
            node* temp1=temp->right;
            while(temp1->left!=NULL){
                temp1=temp1->left;
            }
            temp->value=temp1->value;
            delete_node(&temp->right,temp1->value);
        }
    }
}

void traversal(node* root){
    if(root==NULL)return;
    printf("%d ",root->value);
    traversal(root->left); 
    traversal(root->right);
}

int main(){
    int value;
    node* root=NULL;

    while(scanf("%d",&value)==1){
        insertion_end(&root,value);
        if(getchar()=='\n')break;
    }
    
    traversal(root);
    delete_node(&root,3);
    traversal(root);
    return 0;
}