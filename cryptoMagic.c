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
char text1;
char text2;
int text;
do{
int text1FV = 0;
int text2FV = 0;
text1 = fgetc(readFile);

    if(text1 == EOF){
    break;
    }else if(text1 == 10){
    fprintf(writeFile, "%c", text1);
    }else{
    text2 = fgetc(readFile);
    
    if(text1 == 'T' && text2 == 'T'){
    fprintf(writeFile, "%c", 9);
    }else{
        switch(text1){
        case '0':
        text2FV = 0;
        break;
        case '1':
        text1FV = 1;
        break;
        case '2':
        text1FV = 2;
        break;
        case '3':
        text1FV = 3;
        break;
        case '4':
        text1FV = 4;
        break;
        case '5':
        text1FV = 5;
        break;
        case '6':
        text1FV = 6;
        break;
        case '7':
        text1FV = 7;
        break;
        case '8':
        text1FV = 8;
        break;
        case '9':
        text1FV = 9;
        break;
        case 'A':
        text1FV = 10;
        break;
        case 'B':
        text1FV = 11;
        break;
        case 'C':
        text1FV = 12;
        break;
        case 'D':
        text1FV = 13;
        break;
        case 'E':
        text1FV = 14;
        break;
        case 'F':
        text1FV = 15;
        break;
        default:
        printf("error");
        }

        switch(text2){
        case '0':
        text2FV = 0;
        break;
        case '1':
        text2FV = 1;
        break;
        case '2':
        text2FV = 2;
        break;
        case '3':
        text2FV = 3;
        break;
        case '4':
        text2FV = 4;
        break;
        case '5':
        text2FV = 5;
        break;
        case '6':
        text2FV = 6;
        break;
        case '7':
        text2FV = 7;
        break;
        case '8':
        text2FV = 8;
        break;
        case '9':
        text2FV = 9;
        break;
        case 'A':
        text2FV = 10;
        break;
        case 'B':
        text2FV = 11;
        break;
        case 'C':
        text2FV = 12;
        break;
        case 'D':
        text2FV = 13;
        break;
        case 'E':
        text2FV = 14;
        break;
        case 'F':
        text2FV = 15;
        break;
        default:
        printf("error");
        }

    text = (((text1FV*16)+text2FV)+16);

        if(text>127){
        text = (text-144)+32;
        }

    fprintf(writeFile, "%c", text);}
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
    encrypting(fopen("temp.txt","w"), fopen(argv[2],"r"));
    swapper(fopen(argv[2],"w"), fopen("temp.txt","r"));
    renamex(argv,argc);
    }else if(strcmp(argv[1],"-D") == 0){
    decrypting(fopen("temp.txt","w"), fopen(argv[2],"r"));
    swapper(fopen(argv[2],"w"), fopen("temp.txt","r"));
    renamex(argv,argc);
    }else{
    printf("not entered right");
    }

return 0;
}