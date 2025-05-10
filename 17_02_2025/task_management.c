#include<stdio.h>
#include<string.h>
#define MAX 100
 
enum status{
PENDING=1,
COMPLETE
};

typedef struct task{
    char task[100];
    enum status status;
}task;

// char* get_status(enum status s){
//     if(s==1)
//         return "PENDING";
//     else if(s==2)
//         return "COMPLETE";
// }

enum status set_status(char str[]){
    if(strcmp(str,"PENDING")==0)
        return PENDING;
    else if(strcmp(str,"COMPLETE")==0)
        return COMPLETE;
    return PENDING;
}

enum MENU{
    ADD=1,
    CHANGE,
    LIST,
    EXIT
};

void list_pending(task* t,int index){
    for(int i=0;i<index;i++){
        if(t[i].status==PENDING){
            printf("%s\n",t[i].task);
        }
    }
}

int main(){
    int n,choice,index=0;
    char str[MAX];
    scanf("%d",&n);
    task t[MAX];
    while(n--){
        scanf("%d",&choice);
        switch(choice){
            case ADD:
            scanf("%99s",t[index].task);
            t[index++].status=set_status("PENDING");
            break;
            case CHANGE:
            scanf("%s",str);
            for(int i=0;i<index;i++){
                if(strcmp(t[i].task,str)==0){
                    t[i].status=set_status("COMPLETE");
                }
            }
            break;
            case LIST:
            list_pending(t,index);
            break;
            case EXIT:
            return 0;
            default:
            printf("Invalid\n");
        }
    }
    
    return 0;
}