#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/getopt.h"
#include "../headers/getopt.c"

#include "../headers/file-operation-managment.h"

FILE* GettingInputFile(){
    char directoryPath[1024];
    FILE *shallowFileCopy;
    bool binary = false; 
    
    printf("Please, provide the program with the directory path of the file you want to work with.\nDirectory path: ");   
    fgets(directoryPath, 1024, stdin);
    printf("%s", directoryPath);
    directoryPath[strcspn(directoryPath, "\n")] = '\0';
    
    if(strlen(directoryPath)<=4){
        printf("Error: Invalid file path format!");
        exit(1);
    }

    if(strcmp(directoryPath + strlen(directoryPath)-4, ".bin") == 0){
        shallowFileCopy = fopen(directoryPath, "rb");
        binary = true;
    } else{
        shallowFileCopy = fopen(directoryPath, "r");
    }

    shallowFileCopy = fopen(directoryPath, "r");

    if(shallowFileCopy == NULL){
        printf("Error: The directory path that you have provided is invalid or incorrect! Please, try again.");
        exit(1);
    }

    fclose(shallowFileCopy);
    if(binary){
        return fopen(directoryPath, "rb");
    } else {
        return fopen(directoryPath, "r");
    }
    
}

int main(int argc, char *argv[]){
    int indexOption = 0;
    FILE *inputFile;
    FILE *outputFile; 

    while((indexOption = getopt(argc, argv, "f")) != -1){
        switch(indexOption){
            case 'f': 
                inputFile = GettingInputFile();
                printf("Succesful operation!");
            ; break;   
        }
    }
}

