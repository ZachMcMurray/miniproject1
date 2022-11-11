#include <stdio.h>
#include <string.h>

void encrypting(FILE *writeFile,FILE *readFile){
char text;
do{
text = fgetc(readFile);
    if(text == EOF){
    break;
    }else if(text == 9){
    fprintf(writeFile, "TT");
    }else if(text == 10){
    fprintf(writeFile,"%c",text);
    }else{
    text = text-16;
        if(text<32){
        text = (text-32)+144;
        }
    fprintf(writeFile, "%2X", (unsigned char)text);
    }
}while(1);
fclose(writeFile);
fclose(readFile);
}

void swapper(FILE *writeFile,FILE *readFile){
  char text;
do{
text = fgetc(readFile);
    if(text == EOF){
    break;
    }else{
    fprintf(writeFile, "%c", text);
    }
}while(1);
fclose(writeFile);
fclose(readFile);  
}

void renamex(char** argv, int count){
    if(count == 2){
    int i = 0;
        while(1){
        if(argv[1][i]=='\0'){
        break;
        }else{
        i++;
        }
        }

        int x;
        for(x=0;x<=i;x++){
        if(argv[1][x]=='.'){
        break;
        }
        }

        char fileName[i];

        strcpy(fileName, argv[1]);

        argv[1][x] = '.';
        argv[1][x+1] = 'c';
        argv[1][x+2] = 'r';
        argv[1][x+3] = 'p';

        rename(fileName, argv[1]);
        }else if(strcmp(argv[1],"-E")==0){
         int i = 0;
        while(1){
        if(argv[2][i]=='\0'){
        break;
        }else{
        i++;
        }
        }

        int x;
        for(x=0;x<=i;x++){
        if(argv[2][x]=='.'){
        break;
        }
        }

        char fileName[i];

        strcpy(fileName, argv[2]);

        argv[2][x] = '.';
        argv[2][x+1] = 'c';
        argv[2][x+2] = 'r';
        argv[2][x+3] = 'p';

        rename(fileName, argv[2]);
        }else if(strcmp(argv[1],"-D") == 0){
        int i = 0;
        while(1){
        if(argv[2][i]=='\0'){
        break;
        }else{
        i++;
        }
        }

        int x;
        for(x=0;x<=i;x++){
        if(argv[2][x]=='.'){
        break;
        }
        }

        char fileName[i];

        strcpy(fileName, argv[2]);

        argv[2][x] = '.';
        argv[2][x+1] = 't';
        argv[2][x+2] = 'x';
        argv[2][x+3] = 't';

        rename(fileName, argv[2]);
        }
 
}

void decrypting(FILE *writeFile,FILE *readFile){
fprintf(writeFile, "coding can suck my dick\nFor the love of god kill me\nPlease work this time");
char text1;
char text2;
char text;
do{
text1 = fgetc(readFile);
text2 = fgetc(readFile);
    if(text1 == EOF){
    break;
    }else if(text1 == 'T' && text2 == 'T'){
    fprintf(writeFile, "%c", 9);
    }else if(text1 == '0' && text2 == 'A'){
    fprintf(writeFile,"%c",10);
    }else{
        if(text1 == '8' && text2 == '0'){
            text = 32;
        }
        else{
            char text = text1 + text2 + 16;
        }
        if(text<32){
        text = (text-32)+144;
        }
    fprintf(writeFile, "%c", (unsigned char)text);
    }
}while(1);
fclose(writeFile);
fclose(readFile);
}

int main(int argc, char *argv[]){

    /*when running the code do it like .\"executable name" -E/-D "name of text file" 
    exsample .\cryptoMagic -E myText.txt
    argc is the number of strings in the enter line
    .\cryptoMagic -E myText.txt 
    here argc = 3
    .\cryptoMagic myText.txt
    here argc = 2
    argv[] takes the strings entered in the run line
    .\cryptoMagic -E myText.txt
    here argv[0] = "cryptoMagic", argv[1] = "-E", argv[2] = "myText.txt"*/


    if(argc == 2){
    encrypting(fopen("temp.txt","w"), fopen(argv[1],"r"));
    swapper(fopen(argv[1],"w"), fopen("temp.txt","r"));
    renamex(argv,argc);
    }else if(strcmp(argv[1],"-E") == 0){
    encrypting(fopen(argv[2],"w"), fopen(argv[2],"r"));
    swapper(fopen(argv[2],"w"), fopen("temp.txt","r"));
    renamex(argv,argc);
    }else if(strcmp(argv[1],"-D") == 0){
    decrypting(fopen(argv[2],"w"), fopen(argv[2],"r"));
    renamex(argv,argc);
    }else{
    printf("not entered right");
    }

return 0;
}