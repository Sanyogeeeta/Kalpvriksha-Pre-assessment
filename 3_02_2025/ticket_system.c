#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum status{
    PENDING,APPROVED
};

typedef struct node{
    char movie[50];
    int screen_no,seat_no,amount;
    enum status s;
    struct node* next;
}node;

typedef struct queue{
    node* front,*rear;
}queue;

node* create_node(char movie[],int screen_no,int seat_no,int amount){
    node* new_node=malloc(sizeof(node));
    new_node->next=NULL;
    strcpy(new_node->movie,movie);
    new_node->screen_no=screen_no;
    new_node->seat_no=seat_no;
    new_node->amount=amount;
    new_node->s=0;
    return new_node;
}

int isEmpty(queue* q){
    return q->front==NULL;
}

void enqueue(queue* q,char movie[],int screen_no,int seat_no,int amount){
    node* new_node=create_node(movie,screen_no,seat_no,amount);
    if(q->front==NULL){
    q->front=new_node;
    q->rear=new_node;
    return;
    }
    q->rear->next=new_node;
    q->rear=new_node;
}

node* dequeue(queue* q){
    if(isEmpty(q)){
        printf("Empty Queue!");
        return NULL;
    }
    if(q->front->next==NULL){
        q->front=q->rear=NULL;
        return q->front;
    }
    node* temp=q->front;
    q->front=q->front->next;
    return temp;
}

void display(queue* q){
    if(q->front==NULL)return;
    node* current=q->front;
    while(current!=q->rear){
        printf("%s %d %d %d %d\n",current->movie,current->screen_no,current->seat_no,current->amount,current->s);
        current=current->next;
    }
    printf("%s %d %d %d %d\n",current->movie,current->screen_no,current->seat_no,current->amount,current->s);
}

int main(){
    int choice=0;
    char movie[50];
    int seat_no,screen_no,amount;

    queue* q1=malloc(sizeof(queue));
    queue *q2=malloc(sizeof(queue));
    q1->front=NULL;
    q1->rear=NULL;

    q2->front=NULL;
    q2->rear=NULL;
    while(choice!=5){
    printf("1.Book 2.Approve 3.Booked 4. Approved\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter Movie:");
        scanf("%s",movie);
        printf("Enter screen number:");
        scanf("%d",&screen_no);
        printf("Enter seat number:");
        scanf("%d",&seat_no);
        printf("Enter Amount:");
        scanf("%d",&amount);
        enqueue(q1,movie,screen_no,seat_no,amount);
        break;

        case 2:
        node* new=dequeue(q1);
        if(new!=NULL){
        enqueue(q2,new->movie,new->screen_no,new->seat_no,new->amount);
        q2->rear->s=1;
        }
        else
        printf("No Booking available\n");
        break;

        case 3:
        display(q1);
        break;
        case 4:
        display(q2);
        break;

        case 5:
        printf("Exit\n");
        return 0;

        default:
        printf("Enter Valid Data\n");
    }
    }
}