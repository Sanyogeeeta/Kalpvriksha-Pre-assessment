#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 128

typedef struct node{
    char key;
    int count;
    struct node* next;
}node;

typedef struct hashmap{
    node* hashmap[MAX];
}hashmap;

void initialize_hashmap(hashmap* h){
    for(int i=0;i<MAX;i++){
        h->hashmap[i]=NULL;
    }
}

int hash_function(char c){
    return (int)c;
}

node* create_node(char key){
    node* new=malloc(sizeof(node));
    new->next=NULL;
    new->count=1;
    new->key=key;
    return new;
}

void insert(hashmap* h,int* last,int key){
    int index=hash_function(key);
    if(index>(*last))
       *last=index;
    if(h->hashmap[index]==NULL){
        node* new=create_node(key);
        h->hashmap[index]=new;
    }
    else{
        h->hashmap[index]->count+=1;
    }
}

void display(hashmap h,int last){
    
    printf("{");
    for(int i=0;i<last;i++){
        if(h.hashmap[i]!=NULL){
            printf("%c:%d, ",h.hashmap[i]->key,h.hashmap[i]->count);
        }
    }
    printf("%c:%d}",h.hashmap[last]->key,h.hashmap[last]->count);
}

void free_hashmap(hashmap* h){
    for(int i=0;i<MAX;i++){
        node* temp=h->hashmap[i];
         free(temp);        
    }
}

int main(){
    hashmap h;
    char str[100000];
    
    scanf("%[^\n]",str);
    initialize_hashmap(&h);
    int max=-1;
    
    for(int i=0;i<strlen(str);i++){
       insert(&h,&max,str[i]);
    }        
    if(strcmp(str,"")==0)
        printf("{}\n");
    else                 
       display(h,max);
    free_hashmap(&h);
    return 0;
}