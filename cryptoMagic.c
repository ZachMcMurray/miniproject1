#include <stdio.h>
#include <string.h>

void encrypting(FILE *writeFile,FILE *readFile){
fprintf(writeFile, "for the love of god work");
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
    encrypting(fopen(argv[1],"w"), fopen(argv[1],"r"));
    }else if(strcmp(argv[1],"-E") == 0){
    encrypting(fopen(argv[2],"w"), fopen(argv[2],"r"));
    }else if(strcmp(argv[1],"-D") == 0){
    decrypting(fopen(argv[2],"w"), fopen(argv[2],"r"));
    }else{
    printf("not entered right");
    }

return 0;
}