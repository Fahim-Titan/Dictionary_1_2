#include<stdio.h>
#include<stdlib.h>

char* readWord(char* buff, long i, long* retNewPos);
long long getFileSize(FILE* fp);
void print(char* ch);

int main() {
    FILE *fp;
    fp = fopen("dic2.txt", "rb");
    long fileSize = getFileSize(fp);

    //create a buffer to read entire file into memory, cause it is very small
    char *buff = (char*)malloc(fileSize);// think of it an  char array
    fread(buff, 1, fileSize, fp);
    //puts(buff);
    puts("\n\n\n");
    char *word;
    char meaning[1000];
    long i=0;
    while(buff[i]==0x0d && buff[i+1]==0x0a && buff[i+2]==0x0d && buff[i+3]==0x0a) {
        i +=4;
        word = readWord(buff, i, &i);
            printf("%s\n", word);
      //  print(word);
        putchar('\n');
        int m=0;
        i++; //to pass the space after the word
        while(buff[i]!=0x0d && buff[i+1]!=0x0a && buff[i+2]!=0x0d && buff[i+3]!=0x0a){
            meaning[m++]=buff[i++];
        }
        meaning[m++]=buff[i++];
        meaning[m++]=buff[i++];
        meaning[m] = '\0';
        printf("%s\n", meaning);
     //   print(meaning);
        putchar('\n');

        //i+=3;
    }









    /* char word[40];
     bool newLineFound = false;
     char ch = getchar();
     while(true) {

         if(ch == '\n') {
             scanf("%s", word);
             printf("%s", word);
         }
         char m; //= getchar();
         while( m=getchar() && m!='\n'){


         }


     }*/
}
void print(char* ch)
{
    int i=0;
    while(ch[i]!='\0')
        putchar(ch[i++]);
}



char word[40];

char* readWord(char* buff, long i, long* retNewPos) {

    int n=0;
    while(buff[i]!=0x20) {
        word[n++] = buff[i++];
    }
    word[n] = '\0';
    *retNewPos = *retNewPos + n;//return the position where the word ends
    return word;
}

long long getFileSize(FILE* fp) {
    long long bytes, prev;
    prev = ftell(fp); // backed up the original position where the cursor was before
    fseek(fp,0, SEEK_END);
    bytes = ftell(fp);
    fseek(fp, prev, SEEK_SET);
    // fseek()
    return bytes;
}
