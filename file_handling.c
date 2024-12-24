#include<stdio.h>

struct user{
    int UniqueId;
    char Name[50];
    int age;
}u;

//Check if user id is unique
int IdCheck(int id){
    FILE *ptr=fopen("users.txt","r");
    struct user temp;
    int flag=0;
    while(!feof(ptr)){
        fscanf(ptr,"\n%d\t%s\t%d",&temp.UniqueId,temp.Name,&temp.age);
        if(temp.UniqueId==id){
        flag=1;
        }
    }
    fclose(ptr);
    return flag;
}

int IsValidData(int* ptr){
    int flag=0;
    if(scanf("%d",ptr)!=1){
        while(getchar()!='\n');
        flag=1;
    }
    return flag;
}

void AddUser(){
    FILE *ptr=fopen("users.txt","a");
    printf("Enter user details\n");
    printf("Enter Unique ID:");
    if(IsValidData(&u.UniqueId))
        printf("Enter valid User-ID\n");
    else{
        if(!IdCheck(u.UniqueId)){
            printf("Enter Name:");
            scanf("%49s",u.Name);
            printf("Enter Age:");
            if(IsValidData(&u.age)==1 || (u.age<1 || u.age>100)){
                printf("Invalid value\n");
            }
            else{
                fprintf(ptr,"\n%d\t%s\t%d",u.UniqueId,u.Name,u.age);
                printf("Successfully added the user data...\n");
            }
        }
        else{
            printf("UserId already exists...\n");
        }
    }
    fclose(ptr);
    ptr=NULL;
}

//Check if File is empty
int IsEmpty(FILE* ptr){
    int flag=0;
    fseek (ptr, 0, SEEK_END);
    int size = ftell(ptr);
    if(size==0) {
        flag=1;
    }
    return flag;
}

void ReadDetails(){
    FILE *ptr=fopen("users.txt","r");
        if(IsEmpty(ptr)){
            printf("File is empty\n");
        }
        else{
        rewind(ptr);
            while(fscanf(ptr,"\n%d\t%s\t%d",&u.UniqueId,u.Name,&u.age)!=EOF){
                printf("%d\t%s\t%d\n",u.UniqueId,u.Name,u.age);
            }
        }
    fclose(ptr);
    ptr=NULL;
}

void UpdateDetails(int id){
    int found=0;
    FILE *ptr=fopen("users.txt","r");
    FILE *ptr1=fopen("temp.txt","w");
    if(IsEmpty(ptr)){
            printf("File is empty\n");
    }
    else{
        rewind(ptr);
        while(fscanf(ptr,"\n%d\t%s\t%d",&u.UniqueId,u.Name,&u.age)!=EOF){     
            if(u.UniqueId==id){
                found=1;
                printf("Enter correct details\n");
                printf("Enter Name:");
                scanf("%s",u.Name);
                printf("Enter Age:");
                if(IsValidData(&u.age)==1 || (u.age<1 || u.age>100)){
                    printf("Invalid value\n");
                    break;
                }
                printf("Successfully updated the user data....\n");
            }
            fprintf(ptr1,"\n%d\t%s\t%d",u.UniqueId,u.Name,u.age);
        }
    }
    if(found==0){
        printf("User id doesnt exists..Either enter correct user-id\n");
    }
    fclose(ptr);
    fclose(ptr1);
    ptr=NULL;
    ptr1=NULL;
    remove("users.txt");
    rename("temp.txt","users.txt");
}

void DeleteDetails(int id){
    int found=0;
    FILE *ptr=fopen("users.txt","r");
    FILE *ptr1=fopen("temp.txt","w");
    if(IsEmpty(ptr)){
            printf("File is empty\n");
    }
    else{
        rewind(ptr);
        while(!feof(ptr)){               
            fscanf(ptr,"\n%d\t%s\t%d",&u.UniqueId,u.Name,&u.age);
            if(u.UniqueId==id){
                found=1;
                printf("Successfully deleted the user data....\n");
            }
            else{
                fprintf(ptr1,"\n%d\t%s\t%d",u.UniqueId,u.Name,u.age);
            }
        }
    }
    if(found==0){
        printf("User id doesnt exists..Either enter correct user-id\n");
    }    
    fclose(ptr);
    fclose(ptr1);
    ptr=NULL;
    ptr1=NULL;
    remove("users.txt");
    rename("temp.txt","users.txt");
}

int main(){
    int id;
    int choice=0;
    enum Menu{
        ADDUSER=1,
        READDATA,
        UPDATEDATA,
        DELETEDATA,
        EXIT
    };
    printf("---------Menu---------\n");
    printf("1.Add User Detail\n");
    printf("2.Read Details\n");
    printf("3.Update Details\n");
    printf("4.Delete Details\n");
    printf("5.Exit\n");
    while(choice!=5){
        printf("Enter choice:");
        if(!IsValidData(&choice)){
            switch(choice){
                case ADDUSER:AddUser();
                    break;
                case READDATA:ReadDetails();
                    break;
                case UPDATEDATA:
                    printf("Enter user id to update the data\n");
                    scanf("%d",&id);
                    while(getchar()!='\n');
                    UpdateDetails(id);
                    break;
                case DELETEDATA:
                    printf("Enter user id to delete the data\n");
                    scanf("%d",&id);
                    while(getchar()!='\n');
                    DeleteDetails(id);
                    break;
                case EXIT:return 0;
                default:
                    printf("Enter Valid choice\n");
                    break;
            }
        }
        else
            printf("Enter valid input\n");
    }
    return 0;
}