#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int coeff,pow;
    struct node* next;
}node;

node* create_node(int coefficient,int power){
    node* new=malloc(sizeof(node));
    new->next=NULL;
    new->coeff=coefficient;
    new->pow=power;
    return new;
}

void insertion(node** head,int coefficient,int power){        
    node* new_node=create_node(coefficient,power);
    if(*head==NULL){
        *head=new_node;
        return;
    }
    node* current=*head;
    while(current->next!=NULL)
        current=current->next;
    current->next=new_node;
    current=new_node;
    
}

node* addition_polynomial(node* p1,node* p2){
    node* p=NULL;
    node* temp1=p1;
    node* temp2=p2;
    while(temp1!=NULL && temp2!=NULL){
        if(p1==NULL)return p2;
        if(p2==NULL)return p1;
        if(temp1->pow>temp2->pow){
            insertion(&p,temp1->coeff,temp1->pow);
            temp1=temp1->next;
        }
        else if(temp1->pow==temp2->pow){
            int power=temp1->pow;
            int coeff=temp2->coeff+temp1->coeff;
            insertion(&p,coeff,power);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
            insertion(&p,temp2->coeff,temp2->pow);
            temp2=temp2->next;
        } 
    }
    while(temp1!=NULL){
        insertion(&p,temp1->coeff,temp1->pow);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        insertion(&p,temp2->coeff,temp2->pow);
        temp2=temp2->next;
    }
    return p;
}

void display(node* p){
    node* temp=p;
    if(temp==NULL)return;
    while(temp->next!=NULL){
        printf("%dX^%d+",temp->coeff,temp->pow);
        temp=temp->next;
    }
    printf("%dX^%d\n",temp->coeff,temp->pow);
}

int main(){

node* p1=NULL,*p2=NULL;
node* p3=NULL;
int n1,n2;
int coefficient,power;
printf("Enter number of terms for P1:\n");
scanf("%d",&n1);


printf("P1:\n");
for(int i=0;i<n1;i++){
    scanf("%d %d",&coefficient,&power);
    insertion(&p1,coefficient,power);
}
printf("Enter number of terms for P2:\n");
scanf("%d",&n2);

printf("P2:\n");
for(int i=0;i<n2;i++){
    scanf("%d %d",&coefficient,&power);
    insertion(&p2,coefficient,power);
}
printf("P3:\n");

p3=addition_polynomial(p1,p2);
display(p3);
return 0;
}