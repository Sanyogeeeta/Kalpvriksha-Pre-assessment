#include <stdio.h>
#include <string.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char sentence[100];
    char words[100][100];
    int word_count=0;

    scanf("%99[^\n]s",sentence);
    char* ptr=sentence;
   
    while(*ptr){
        while(*ptr==' ')
            ptr++;
        if(sscanf(ptr,"%s",words[word_count])){
            ptr+=(strlen(words[word_count]));
            word_count++;
        }
    }


    for(int i=word_count-1;i>=0;i--){
        if(i==0)
            printf("%s\n",words[i]);
        else 
            printf("%s ",words[i]);
    }
    
    return 0;
}
