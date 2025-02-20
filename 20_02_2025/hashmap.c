#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct node{
    int value;
    int key;
    struct node* next;
}node;

enum menu{
    INSERT=1,
    DELETE,
    SEARCH,
    EXIT
};

node* create_node(int key,int value){
    node* new_node=malloc(sizeof(node));
    new_node->key=key;
    new_node->value=value;
    new_node->next=NULL;
    return new_node;
}

int hash_function(int key){
    return key%MAX;
}

void insert(node* hashmap[],int key,int value){
    node* new_node=create_node(key,value);
    int index=hash_function(key);
    if(hashmap[index]==NULL){
        hashmap[index]=new_node;
        return;
    }
    node* current=hashmap[index];
    new_node->next=hashmap[index];
    hashmap[index]=new_node;
}

void delete(node* hashmap[],int key){
    int index=hash_function(key);
    node* current=hashmap[index],*prev=NULL;
    while(current!=NULL){
        if(current->key==key){
            if (prev == NULL) {  // Deleting the first node in the chain
                hashmap[index] = current->next;
            } else {
                prev->next = current->next;
            }
            printf("Key %d deleted\n", key);
            free(current);
            return;
        }
        prev=current;
        current=current->next;
    }
    printf("key %d not found\n",key);
}

void search(node* hashmap[],int key){
    int index=hash_function(key);
    if(hashmap[index]==NULL){
        printf("key %d not found\n",key);
        return;
    }
    
    node* current=hashmap[index],*prev=NULL;
    while(current!=NULL){
        if(current->key==key){
            printf("key %d found\n",key);
            return;
        }
        current=current->next;
    }
    printf("key %d not found\n",key);
}

void display(node* hashmap[]){
    for(int i=0;i<MAX;i++){
        if(hashmap[i]!=NULL){
            node* current=hashmap[i];
            while(current!=NULL){
                printf("%d ",current->value);
                current=current->next;
            }
            printf("\n");
        }
    }
}

int main(){
    node* hashmap[MAX]={NULL};
    int choice=0,key,value;
    while(choice!=4){
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case INSERT:
                printf("Enter Key:");
                scanf("%d",&key);
                printf("Enter value:");
                scanf("%d",&value);
                insert(hashmap,key,value);
                display(hashmap);
                break;
            case DELETE:
                printf("Enter Key:");
                scanf("%d",&key);
                delete(hashmap,key);
                display(hashmap);
                break;
            case SEARCH:
                printf("Enter Key:");
                scanf("%d",&key);
                search(hashmap,key);
                display(hashmap);
                break;
            case EXIT:
            printf("Exit program");
            return 0;
        }
    }
    return 0;
}