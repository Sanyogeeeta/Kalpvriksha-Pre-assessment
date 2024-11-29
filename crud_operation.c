#include<stdio.h>
#include<stdlib.h>
//struct creation
struct user{
int UniqueId;
char Name[20];
int age;
}u;
//Add user Data
void AddDetails(){
    FILE *ptr=fopen("users.txt","a");
    printf("Enter user details\n");
    printf("Enter Name:");
    scanf("%s",&u.Name);
    printf("Enter Unique ID:");
    scanf("%d",&u.UniqueId);
    printf("Enter Age:");
    scanf("%d",&u.age);
    fprintf(ptr,"\n%d\t%s\t%d",u.UniqueId,u.Name,u.age);
    fclose(ptr);
}
//Read Details from File
void ReadDetails(){
    FILE *ptr=fopen("users.txt","r");
    while(!feof(ptr)){
        fscanf(ptr,"\n%d\t%s\t%d",&u.UniqueId,&u.Name,&u.age);
        printf("%d %s %d\n",u.UniqueId,u.Name,u.age);
    }
    fclose(ptr);
}
//write into File
void WriteDetails(){
    FILE *ptr=fopen("users.txt","w");
    FILE *ptr1=fopen("temp.txt","r");
    while(!feof(ptr1)){
        fscanf(ptr1,"\n%d\t%s\t%d",&u.UniqueId,&u.Name,&u.age);
        fprintf(ptr,"\n%d %s %d",u.UniqueId,u.Name,u.age);
    }
    fclose(ptr);
    fclose(ptr1);
}
//Update the File Data
void UpdateDetails(int id){
    int found=0;
    FILE *ptr=fopen("users.txt","r");
    FILE *ptr1=fopen("temp.txt","w");
    while(!feof(ptr)){     
        fscanf(ptr,"\n%d\t%s\t%d",&u.UniqueId,&u.Name,&u.age);
        if(u.UniqueId==id){
        found=1;
        printf("Enter correct details\n");
        printf("Enter Unique ID:");
        scanf("%d",&u.UniqueId);
        printf("Enter Name:");
        scanf("%s",&u.Name);
        printf("Enter Age:");
        scanf("%d",&u.age);
        printf("Successfully updated the user data....\n");
        }
        fprintf(ptr1,"\n%d\t%s\t%d",u.UniqueId,u.Name,u.age);
    }
    if(found==0){
        printf("User id doesnt exists..Either enter correct user-id");
    }
    fclose(ptr);
    fclose(ptr1);
    WriteDetails();
    remove("temp.txt");
}
//Delete the user Data
void DeleteDetails(int id){
    int found=0;
    FILE *ptr=fopen("users.txt","r");
    FILE *ptr1=fopen("temp.txt","w");
    while(!feof(ptr)){
        fscanf(ptr,"\n%d\t%s\t%d",&u.UniqueId,&u.Name,&u.age);
        if(u.UniqueId==id){
        found=1;
        printf("Successfully deleted the user data....\n");
        }
        else{
        fprintf(ptr1,"\n%d\t%s\t%d",u.UniqueId,u.Name,u.age);
        }
    }
    if(found==0){
        printf("User id doesnt exists..Either enter correct user-id");
    }    
    fclose(ptr);
    fclose(ptr1);
    WriteDetails();
    remove("temp.txt");
}
int main(){
    int id,choice;
    printf("---------Menu---------\n");
    printf("1.Add User Detail\n");
    printf("2.Read Details\n");
    printf("3.Update Details\n");
    printf("4.Delete Details\n");
    printf("5.Exit\n");
    do{
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:AddDetails();
                break;
            case 2:ReadDetails();
                break;
            case 3:
                printf("Enter user id to update the data\n");
                scanf("%d",&id);
                UpdateDetails(id);
                break;
            case 4:
                printf("Enter user id to delete the data\n");
                scanf("%d",&id);
                DeleteDetails(id);
                break;
            case 5:exit(0);
            default:
                printf("Enter Valid choice\n");
        }

    }while(choice!=5);
    return 0;
}