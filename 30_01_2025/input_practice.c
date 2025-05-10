#include<stdio.h>
#include<string.h>

int main(){
    int n,index=0;
    scanf("%d",&n);
    int arr[n];
    char word[50];
    char words[50][50];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    while(scanf("%s",word)==1){
        strcpy(words[index],word);
        index++;
        if(getchar()=='\n')break;
    }

    for(int i=0;i<n;i++)
        printf("%d\n",arr[i]);
    
    for(int i=0;i<index;i++)
        printf("%s\n",words[i]);
}