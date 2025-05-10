#include <stdio.h>
#define CAPACITY 10

int hash(int value)
{
    return value % CAPACITY;
}

void insert(int arr[], int value)
{
    int index = hash(value);
    if(arr[index]==-1){
        arr[index]=value;
        return;
    }
    int org=index;
    while (arr[index] != -1){
        index = (index + 1) % CAPACITY;
        if(index==org){
            printf("collision occured\n");
            return;
        }
    }
    arr[index] = value;
}

int search(int arr[], int key)
{
    int index = hash(key);
    int original = index;
    
    while (arr[index] != -1)
    {
        if (arr[index] == key)
        return index;
        index=(index+1)%CAPACITY;
        if (index == original)
            break;
    }
    return -1;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++){
        if (arr[i] != -1)
            printf("%d ", arr[i]);
    }
    printf("\n");
}

void delete(int arr[], int value)
{
    int index = hash(value);
    int original = index;

    while (arr[index] != -1)
    {
        if (arr[index] == value){
            arr[index]=-1;
            return;
        }
        index=(index+1)%CAPACITY;
        if (index == original)
            break;
    }
    printf("Value not found to delete.\n");
}

int main()
{

    int arr[CAPACITY];
    int value, choice = 0;

    for(int i=0;i<CAPACITY;i++)
    arr[i]=-1;
    while (choice != 5)
    {
        printf("1.Insert 2.Search 3.Delete 4. Display 5.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &value);
            //display(arr,CAPACITY);
            insert(arr, value);
            break;

        case 2:
            scanf("%d", &value);
            int result = search(arr, value);
            if(result!=-1)printf("%d found at index %d",value,result);
            else printf("Enter not found!\n");
            break;

        case 3:
            scanf("%d", &value);
            delete (arr, value);
            break;

        case 4:
            display(arr, CAPACITY);
            break;

        case 5:
            return 0;

        default:
            printf("Enter Valid Data");
        }
    }
}