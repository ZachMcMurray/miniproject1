#include <stdio.h>

void encrypting(char argv[], int count){
    // %x in prints gives hexadecimal
   
}

void decrypting(char argv[]){
    
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
    here argv[0] = "cryptoMagic" argv[1] = "-E" argv[2] = "myText.txt"*/

    if(argc == 2){
    encrypting(argv, argc);
    }else if(argv[1]=='-E'){
    encrypting(argv, argc);
    }else if(argv[1]=='-D'){
    decrypting(argv);
    }else{
    printf("not entered right");
    }

return 0;
}