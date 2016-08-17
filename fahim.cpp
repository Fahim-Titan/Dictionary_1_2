#include<string.h>
#include<stdio.h>
#include<stdlib.h>

FILE *dic;
char *searchWord(char w[]);
void getMeaning(char *m);

int main(void) {
    //dic = fopen("D:\\new.txt", "r");
    dic = fopen("new.txt", "r");

    char word[50];
    printf("\n\nEnter word: ");
    gets(word);

    printf("\n");
    searchWord(word);

    main();// this will take input and search again and again. for testing purpose
}

char *searchWord(char w[]) {
    int count=0;

    char ch;
    char word[50], meaning[8000];
    long int i=0;
    bool record = false, found = false;
    while(!feof(dic)) {
//        printf("%d\n", count++);
        ch = fgetc(dic);
        if(record && ch!='@')
            word[i++] = ch;
        if(ch=='@' && record == false)
            record = true;
        else if(ch=='@' && record == true) {
            record = false;
            word[i] = '\0';
         //   printf("%s\n", word);
            i=0;
            if(!strcmp(w, word)){
                printf("%s\n", word);
                found  = true;
                getMeaning(meaning);
                printf("\nMeaning : %s", meaning);
                break;
            }
        }



    }
    if(!found)
        printf("\n\nNo match found\n\n");

    return " ";
}

void getMeaning(char *m)
{
//    char m[1000];
    int i=0;
    while(true)
    {
        char ch = fgetc(dic);
        if(ch!='#')
            m[i++] = ch;
        else {
            m[i] = '\0';
            break;
        }
    }
//    return m;
}
