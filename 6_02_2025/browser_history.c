#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char* str;
    struct node* next;
}node;

typedef struct stack{
    node* head;
}stack;

node* create(char str[]){
    node* new=malloc(sizeof(node));
    new->str=malloc(sizeof(strlen(str)+1));
    strcpy(new->str, str);
    new->next=NULL;
    return new;
}
void push(stack* s,char str[]){
    node* new=create(str);
    if(s->head==NULL){
        s->head=new;
        return;
    }
    new->next=s->head;
    s->head=new;
}

void read(stack s){
    if(s.head==NULL){
        printf("Empty!\n");
        return;
    }
    printf("%s\n",s.head->str);
}

void pop(stack* s){
    if(s->head==NULL){
        printf("Empty!\n");
        return;
    }
    node* temp=s->head;
    s->head=s->head->next;
    free(temp->str);
    free(temp);
}

void edit(stack* s,char* str){
    stack temp;
    temp.head=NULL;
    node* current=s->head;

    if (s->head == NULL) {
        printf("Empty!\n");
        return;
    }

    if (strcmp(s->head->str, str) == 0) {
        printf("Enter new url: ");
        scanf("%s", s->head->str); 
        return;
    }
    while(current!=NULL&&(strcmp(current->str,str)!=0)){
        push(&temp,current->str);
        current=current->next;
    }

    if(current!=NULL){
        printf("Enter new url:");
        scanf("%s",current->str);
    }
    else{
        printf("Provided url doesnt exists!\n");
    }
    while(temp.head!=NULL){
        char* str1=temp.head->str;
        push(s,str1);
        pop(&temp);
    }
}

int main(){
    char str[100];
    int choice=0;

    stack s;
    s.head=NULL;

    while(choice!=5){

        scanf("%d",&choice);
        switch(choice){
            case 1:scanf("%s",str);
            push(&s,str);
            break;
            case 2:read(s);
            break;
            case 3:
            printf("Enter the url:");
            scanf("%s",str);
            edit(&s,str);
            break;
            case 4:pop(&s);
            break;
            case 5:
            return 0;
            default:
            printf("invalid!\n");
        }
    }
    return 0;
}