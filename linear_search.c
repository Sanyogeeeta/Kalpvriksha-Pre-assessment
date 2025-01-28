#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
/*
You are given a singly linked list containing n nodes, where each node has an integer value. Your task is to implement a function that finds all occurrences of a given target element in the list, but with specific constraints. These constraints are:

Return all positions (0-based indices) where the target element occurs, but only those that are even-indexed.
If the target element does not exist in the list, return "Element not found".
If the target element only appears at odd indices, return "Target found only at odd indices".
The list is sorted in ascending order, but elements in the list can still be repeated.
Your function should not return the positions that are odd-indexed.
*/
typedef struct node{
    int value;
    struct node* next;
}node;

node* create_node(int value){
    node* new_node=malloc(sizeof(node));
    new_node->next=NULL;
    new_node->value=value;
    return new_node;
}

void insertion(node** head,int value){
    node* new_node=create_node(value);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    node* temp=*head;
    while(temp->next!=NULL){
       temp=temp->next;
    }
    temp->next=new_node;
}

int LinearSearch(node* head,int* target_index,int target){
    node* current=head;
    int current_index=0,index=-1,target_count=0,odd_index=0;
    while(current!=NULL){
        if(current->value==target){
            target_count+=1;
            if(current_index%2==0){
                index+=1;
                target_index[index]=current_index;
            }
            else
                odd_index++;
        }
        current=current->next;
        current_index++;
    }

    if(odd_index==target_count && target_count!=0)
        index=-2;//value representing target present at all odd indices
    return index;
}

int main(){

    int value;
    node* head=NULL;
    char str[100];
    fgets(str,sizeof(str),stdin);
    int sign=1;

    char*ptr=str;
    while(*ptr){
        if(*ptr=='-'&&isdigit(*(ptr+1)))
        {
            ptr++;
            sign*=-1;
        }
        if(isdigit(*ptr)){
            sscanf(ptr,"%d",&value);
            value*=sign;
            insertion(&head,value);
            if(sign==-1)sign=1;
            while(isdigit(*ptr))ptr++;
        }else{
            ptr++;
        }
    }

    node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;
    }
    
    int target_index[100],target;
    scanf("%d",&target);

    int result=LinearSearch(head,target_index,target);
    if(result==-1)
        printf("Element not found\n");
    else if(result==-2)
        printf("Target found only at odd indices");
    else{
        printf("[");
        for(int i=0;i<=result;i++){
            if(i!=result)printf("%d ",target_index[i]);
            else printf("%d",target_index[i]);
        }
        printf("]\n");
    }
    return 0;
}