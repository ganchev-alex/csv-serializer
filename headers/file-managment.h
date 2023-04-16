#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "firm-structure.h"

#define MAX_LINE_LENGTH 1024

void Tokenization(Firm pFirm, char *pLine){
    char *token;

    token = strtok(pLine, ",");
    pFirm.rowID = atoi(token);

    token = strtok(NULL, ",");
    strcpy(pFirm.orderID, token);

    token = strtok(NULL, ",");
    strcpy(pFirm.orderDate, token);

    token = strtok(NULL, ",");
    strcpy(pFirm.customer, token);

    token = strtok(NULL, ",");
    strcpy(pFirm.city, token);

    token = strtok(NULL, ",");
    strcpy(pFirm.state, token);

    token = strtok(NULL, ",");
    pFirm.postalCode = atoi(token);

    token = strtok(NULL, ",");
    strcpy(pFirm.region, token);

    token = strtok(NULL, ",");
    strcpy(pFirm.productID, token);

    token = strtok(NULL, ",");
    strcpy(pFirm.category, token);

    token = strtok(NULL, ",");
    strcpy(pFirm.subCategory, token);

    token = strtok(NULL, ",");
    pFirm.price = atof(token);
}


void Serialize(FILE *csvFileHolder, FILE *binaryFileHolder){
    char currentLine[MAX_LINE_LENGTH];

    fgets(currentLine, MAX_LINE_LENGTH, csvFileHolder);
    fwrite(currentLine, strlen(currentLine), 1, binaryFileHolder);

    while(fgets(currentLine, MAX_LINE_LENGTH, csvFileHolder) != NULL){
        Firm firm; 

    }
}