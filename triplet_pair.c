#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/*
You are given a string that contains a mixture of alphabetic characters, digits, and special characters.
Your task is to extract all the integers (both positive and negative) from the string and sort them in 
ascending order as you extract them, without performing a separate sorting step later.
Once the integers are extracted and sorted, you need to find all triplets of integers 
where the sum of each triplet equals a given target sum.
The integers should be printed in ascending order, and all such triplets that satisfy the sum condition should be output.

Input:
A string containing a mixture of alphabetic characters, digits, and special characters.
A target integer that specifies the desired sum of the triplets.
*/
typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createNode(int value){
    Node* newElement=(Node*)malloc(sizeof(Node));
    newElement->data=value;
    newElement->next=NULL;
    return newElement;
}

void display(Node* Head){
   if(Head==NULL)
        printf("List is Empty\n");
    else{
         Node* current=Head;
        while(current->next!=NULL){
            printf("%d ",current->data);
            current=current->next;
        }
        printf("%d\n",current->data);
    }
}

void insertion_sort(Node** head,int value){
    Node* new_node=NULL,* current=*head;
    new_node=createNode(value);
    if(*head==NULL||(*head)->data>value){
        new_node->next=*head;
        *head=new_node;
    }
    else{
        while(current->next!=NULL && current->next->data<value)
            current=current->next;
        new_node->next=current->next;
        current->next=new_node; 
    }    
}

void freeList(Node* Head) {
    while (Head != NULL) {
        Node* temp = Head;
        Head = Head->next;
        free(temp);
    }
}

void triplet_pairs(Node* head,int target){
    Node* first=head,*second=NULL,*third=NULL;
    while(first!=NULL && first->next!=NULL && first->next->next!=NULL){
        second=first->next;
        while(second!=NULL && second->next!=NULL){
            int sum=first->data+second->data;
            third=second->next;
            while(third!=NULL){
            if(third->data==target-sum)printf("%d %d %d\n",first->data,second->data,third->data);
            third=third->next;
            }
            second=second->next;
        }
        first=first->next;
    }
}

int main(){
    char str[500];
    Node* Head=NULL;

    fgets(str,sizeof(str),stdin);
    char* ptr=str;

    int sign=1,value;
    while(*ptr){
        if(*ptr=='-'&&isdigit(*(ptr+1)))
        {
            ptr++;
            sign*=-1;
        }
        if(isdigit(*ptr)){
            sscanf(ptr,"%d",&value);
            value*=sign;
            insertion_sort(&Head,value);
            if(sign==-1)sign=1;
            while(isdigit(*ptr))ptr++;
        }else{
            ptr++;
        }
    }
    display(Head);

    int target;
    scanf("%d",&target);
    triplet_pairs(Head,target);
    return 0;
}



