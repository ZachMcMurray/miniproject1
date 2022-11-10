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

void decrypting(FILE *writeFile,FILE *readFile){
fprintf(writeFile, "coding can suck my dick");
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
    printf("%c", argv[1][1]);
    encrypting(fopen("temp.txt","w"), fopen(argv[1],"r"));
    swapper(fopen(argv[1],"w"), fopen("temp.txt","r"));
    }else if(strcmp(argv[1],"-E") == 0){
    encrypting(fopen(argv[2],"w"), fopen(argv[2],"r"));
    }else if(strcmp(argv[1],"-D") == 0){
    decrypting(fopen(argv[2],"w"), fopen(argv[2],"r"));
    }else{
    printf("not entered right");
    }

return 0;
}