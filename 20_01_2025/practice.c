
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(struct Node* Head){
    struct Node* temp=Head;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
    }
    printf("%d\n",temp->data);
}

int main(){
    // struct Node* Head=NULL;
    // insertAtEnd(&Head,12);
    // display(Head);
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 10;
    printf("%d",head->data);
    head->next = NULL;
    free(head);
    head->data = 20;
    printf("%d",head->data);
    return 0;
}