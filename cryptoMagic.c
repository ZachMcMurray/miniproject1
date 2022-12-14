#include <stdio.h>
#include <string.h>

void encrypting(FILE *writeFile,FILE *readFile){//function used to encrypt

    char text;

        do{
        text = fgetc(readFile);//Gets a character from the file
            if(text == EOF){//if its the end of the file end
            break;
            }else if(text == 9){//checks for tabs
            fprintf(writeFile, "TT");
            }else if(text == 10){//checks for enters
            fprintf(writeFile,"%c",text);
            }else{//will encrypt the files characters
            text = text-16;
                if(text<32){
                text = (text-32)+144;//encryption rules
               }
            fprintf(writeFile, "%2X", (unsigned char)text);//prints in new file
            }
        }while(1);

    //closes the files used
    fclose(writeFile);
    fclose(readFile);
}

void swapper(FILE *writeFile,FILE *readFile){//swap from temp to real file

    char text;

        do{
        text = fgetc(readFile);//get character from from file
            if(text == EOF){//check if it's the end of the file
            break;
            }else{//print character in file
            fprintf(writeFile, "%c", text);
            }
        }while(1);

    //closes the files used
    fclose(writeFile);
    fclose(readFile);  
}

void renamex(char** argv, int count){
        if(count == 2){//rename if .\cryptoMagic "file name"
        int i = 0;
            while(1){//count characters in file name
                if(argv[1][i]=='\0'){
                break;
                }else{
                i++;
                }
            }

        int x;
            for(x=0;x<=i;x++){//find where the file extension starts
                if(argv[1][x]=='.'){
                break;
                }
            }

        char fileName[i];

        strcpy(fileName, argv[1]);//copy file name in to an array

        //replace the extension with ".crp"
        argv[1][x] = '.';
        argv[1][x+1] = 'c';
        argv[1][x+2] = 'r';
        argv[1][x+3] = 'p';

        rename(fileName, argv[1]);//rename file

        }else if(strcmp(argv[1],"-E")==0){//rename if ".\cryptoMagic -E "file name"

         int i = 0;

            while(1){//count characters in file name
                if(argv[2][i]=='\0'){
                break;
                }else{
                i++;
                }
            }

        int x;

            for(x=0;x<=i;x++){//find where the file extension starts
                if(argv[2][x]=='.'){
                break;
                }
            }

        char fileName[i];

        strcpy(fileName, argv[2]);//copy file name in to an array

        //replace the extension with ".crp"
        argv[2][x] = '.';
        argv[2][x+1] = 'c';
        argv[2][x+2] = 'r';
        argv[2][x+3] = 'p';

        rename(fileName, argv[2]);//rename file

        }else if(strcmp(argv[1],"-D") == 0){//rename if ".\cryptoMagic -D "file name"

        int i = 0;

            while(1){//count characters in file name
                if(argv[2][i]=='\0'){
                break;
                }else{
                i++;
                }
            }

        int x;

            for(x=0;x<=i;x++){//find where the file extension starts
                if(argv[2][x]=='.'){
                break;
                }
            }

        char fileName[i];

        strcpy(fileName, argv[2]);//copy file name in to an array

        //replace the extension with ".txt"
        argv[2][x] = '.';
        argv[2][x+1] = 't';
        argv[2][x+2] = 'x';
        argv[2][x+3] = 't';

        rename(fileName, argv[2]);//rename file
        }
}

void decrypting(FILE *writeFile,FILE *readFile){//function to decrypt

    char text1;
    char text2;
    int text;

        do{
        
        int text1FV = 0;
        int text2FV = 0;
        text1 = fgetc(readFile);//get a character from file

            if(text1 == EOF){//check if at the end of the file
            break;
            }else if(text1 == 10){//check if it's an enter
            fprintf(writeFile, "%c", text1);
            }else{
            text2 = fgetc(readFile);//gets the next charater
    
                if(text1 == 'T' && text2 == 'T'){//checks if its a tab
                fprintf(writeFile, "%c", 9);
                }else{
                    
                    if (text1>=48&&text1<=57){
                    text1FV =text1-48;
                    }else if(text1>=65&&text1<=70){
                    text1FV = text1 - 55;
                    }

                    if (text2>=48&&text2<=57){
                    text2FV =text2-48;
                    }else if(text2>=65&&text2<=70){
                    text2FV = text2 - 55;
                    }

                text = (((text1FV*16)+text2FV)+16);//apply decryption key

                    if(text>127){//apply another decryption rule
                    text = (text-144)+32;
                    }

                fprintf(writeFile, "%c", text);}//print decrypted charater
                }
        }while(1);

    //close files 
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
        remove("temp.txt");
    }else if(strcmp(argv[1],"-E") == 0){
        encrypting(fopen("temp.txt","w"), fopen(argv[2],"r"));
        swapper(fopen(argv[2],"w"), fopen("temp.txt","r"));
        renamex(argv,argc);
        remove("temp.txt");
    }else if(strcmp(argv[1],"-D") == 0){
        decrypting(fopen("temp.txt","w"), fopen(argv[2],"r"));
        swapper(fopen(argv[2],"w"), fopen("temp.txt","r"));
        renamex(argv,argc);
        remove("temp.txt");
    }else{
        printf("not entered right");
    }

return 0;
}