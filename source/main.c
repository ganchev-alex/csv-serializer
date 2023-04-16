#include <stdio.h>
#include "../headers/file-managment.h"

int main(){
    FILE *inputFile = fopen("../data/sales.csv", "r");
    FILE *outputFile = fopen("../data/sales.bin", "wb");
    
    if(inputFile == NULL || outputFile == NULL){
        printf("Error");
        exit(1);
    }

    Serialize(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

