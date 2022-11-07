#include <stdio.h>

void encrypting(char argv[], int count){
    char text;
    int textNum;

    if(count == 2){

    FILE *textfile;

        if((textfile = fopen(argv[1],'w+')) == NULL){
        printf("file can not be opened");
        return 0;
        }

        textfile = fopen(argv[1],'w+');

        do{
        text = fgetc(textfile);
        }while(text != EOF);
    }

}

void decrypting(char argv[]){
    
}

int main(int argc, char *argv[]){

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