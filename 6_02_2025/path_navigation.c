/*File System Path Navigation
Problem: Given a list of file system commands (cd folder/, cd ../, cd ./), determine the current working directory.
 
Example:
Input: ["cd usr/", "cd local/", "cd ../", "cd bin/"]
Output: "/usr/bin/"
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char str[100];
    struct node* next;
}node;

typedef struct stack{
    node* top;
}stack;

void reverse(stack* s){
    node* current=s->top;
    node* next=NULL,*prev=NULL;
    if(s->top==NULL)return;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    s->top=prev;
}

node* create(char str[]){
    node* new=malloc(sizeof(node));
    new->next=NULL;
    strcpy(new->str,str);
    return new;
}

void push(stack* s,char str[]){
    node* new=create(str);
    if(s->top==NULL){
        s->top=new;
        return;
    }
    new->next=s->top;
    s->top=new;
}

void pop(stack* s){
    if(s->top==NULL){
        printf("Empty!\n");
        return;
    }
    node* temp=s->top;
    s->top=s->top->next;
    free(temp);
}

void display(stack s){
    node* current=s.top;
    while(current!=NULL){
        printf("/%s",current->str);
        current=current->next;
    }
}

int main(){
    stack s;
    s.top=NULL;
    char str[1000];
    fgets(str,sizeof(str),stdin);
    
    char* delim="[\" ,/\", \",/\"]";
    char * tok=strtok(str,delim);

    while(tok!=NULL){
        if(strcmp(tok,"..")==0 && s.top!=NULL){
            pop(&s);
            tok=strtok(NULL,delim);
            continue;
        }
        if(strcmp(tok,"cd")==0){ 
            tok=strtok(NULL,delim);
            continue;
        }
        push(&s,tok);
        tok=strtok(NULL,delim);
    }
    reverse(&s);
    display(s);
}