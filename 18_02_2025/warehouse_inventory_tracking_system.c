#include<stdio.h>
#include<string.h>
#define MAX 100
 
typedef struct cart{
    char item[20];
    int quantity;
}cart;
 
enum menu{
    ADD=1,
    UPDATE,
    QUERY,
    EXIT
};
 
int search(cart* item,char str[],int index){
    for(int i=0;i<index;i++){
        if(strcmp(item[i].item,str)==0){
            return i;
        }
    }
    return -1;
}
 
void add_item(cart* item,char str[],int* index,int quantity){
    int result=search(item,str,*index);
    if(result!=-1){
        item[result].quantity+=quantity;
        return;
    }
    strcpy(item[(*index)].item,str);
    item[(*index)++].quantity=quantity;
}
 
void update_item(cart* item,char str[],int index,int quantity){
    int result=search(item,str,index);
    if(result!=-1){
        item[result].quantity=quantity;
        return;
    }
}
int main(){
    int n,quantity;
    cart item[MAX];
    int index=0,choice=0;
    char str[20];
    scanf("%d",&n);
    while(n--){
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case ADD:
            scanf("%s %d",str,&quantity);
            add_item(item,str,&index,quantity);
            break;
            case UPDATE:
            scanf("%s %d",str,&quantity);
            update_item(item,str,index,quantity);
            break;
            case QUERY:
            scanf("%s",str);
            int query=search(item,str,index);
            printf("%d\n",item[query].quantity);
            break;
            case EXIT:
            printf("Exiting program\n");
            return 0;
            default:
            printf("Invalid\n");
        }
    }
    return 0;
}
 