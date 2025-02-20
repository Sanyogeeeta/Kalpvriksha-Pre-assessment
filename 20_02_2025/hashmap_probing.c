#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct hashmap{
    int key;
    int value;
}hashmap;

enum menu{
    INSERT=1,
    DELETE,
    SEARCH,
    DISPLAY,
    EXIT
};

int hash_function(int key){
    return key%MAX;
}

void insert(hashmap h[],int key,int value){
    int original_index=hash_function(key);
    int index=original_index;
    while(h[index].key!=0 && h[index].key != -1){
        index=(index+1)%MAX;
    }
    h[index].key=key;
    h[index].value=value;
}

void delete(hashmap h[],int key){
    int index=hash_function(key);
    
    int original=index;
    while(h[index].key!=key){
        index=(index+1)%MAX;
        if(index==original){
            printf("Not fourn");
            return;
        }
    }
    printf("Key %d found\n",key);
    h[index].key==-1;
}

void search(hashmap h[],int key){
    int index=hash_function(key);

    int original=index;
    while(h[index].key!=key && index!=original){
        index=(index+1)%MAX;
    }
    if(h[index].key==key){
        printf("Key %d found\n",key);
    }
    else{
        printf("Key not found\n");
    }
}

int get_menu(char str[]){
    int result=0;
    if(strcmp(str,"INSERT")==0)
        result=1;
    else if(strcmp(str,"DELETE")==0)
        result=2;
    else if(strcmp(str,"SEARCH")==0)
        result=3;
    else if(strcmp(str,"DISPLAY")==0)
        result=4;
    else if(strcmp(str,"EXIT")==0)
        result=5;
    return result;
}

void display(hashmap h[]){
    for(int i=0;i<MAX;i++){
        if(h[i].key!=0){
            printf("%d %d\n",h[i].key,h[i].value);
        }
    }
}
// char* set_menu(enum menu s){
//     if(s==1)
//         return "INSERT";
//     else if(s==2)
//         return "DELETE";
//     return ;
// }

int main(){
    char choice[20];
    int key,value;
    hashmap h[MAX]={0};
    enum menu s=0;
    while(s!=5){
        printf("Enter choice:\n");
        scanf("%s",choice);
        s=get_menu(choice);
        switch(s){
            case INSERT:
            printf("Enter Key:");
            scanf("%d",&key);
            printf("Enter value:");
            scanf("%d",&value);
            insert(h,key,value);
            break;
            case DELETE:
            printf("Enter Key:");
            scanf("%d",&key);
            delete(h,key);
            break;
            case SEARCH:
            printf("Enter Key:");
            scanf("%d",&key);
            search(h,key);
            break;
            case DISPLAY:
            display(h);
            break;
            case EXIT:
            break;
            default:
            printf("Invalid\n");
        }
    }
}