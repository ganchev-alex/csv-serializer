#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "firm-structure.h"

#define MAX_LINE_LENGTH 1024

void Tokenization(char *pLine, Firm *pFirm){
    char *token;

    token = strtok(pLine, ",");
    pFirm -> rowID = atoi(token);

    token = strtok(NULL, ",");
    // strcpy(pFirm -> orderID, token);
    strncpy(pFirm->orderID, token, sizeof(pFirm->orderID) - 1);

    token = strtok(NULL, ",");
    //strcpy(pFirm -> orderDate, token);
    strncpy(pFirm->orderDate, token, sizeof(pFirm->orderDate) - 1);

    token = strtok(NULL, ",");
    //strcpy(pFirm -> customer, token);
    strncpy(pFirm->customer, token, sizeof(pFirm->customer) - 1);

    token = strtok(NULL, ",");
    //strcpy(pFirm -> city, token);
    strncpy(pFirm->city, token, sizeof(pFirm->city) - 1);

    token = strtok(NULL, ",");
    //strcpy(pFirm -> state, token);
    strncpy(pFirm->state, token, sizeof(pFirm->state) - 1);

    token = strtok(NULL, ",");
    pFirm -> postalCode = atoi(token);

    token = strtok(NULL, ",");
    //strcpy(pFirm -> region, token);
    strncpy(pFirm->region, token, sizeof(pFirm->region) - 1);

    token = strtok(NULL, ",");
    //strcpy(pFirm -> productID, token);
    strncpy(pFirm->productID, token, sizeof(pFirm->productID) - 1);

    token = strtok(NULL, ",");
    //strcpy(pFirm -> category, token);
    strncpy(pFirm->category, token, sizeof(pFirm->category) - 1);

    token = strtok(NULL, ",");
    //strcpy(pFirm -> subCategory, token);
    strncpy(pFirm->subCategory, token, sizeof(pFirm->subCategory) - 1);

    token = strtok(NULL, ",");
    pFirm -> price = atof(token);
}

void Serialize(FILE *csvFileHolder, FILE *binaryFileHolder){
    char currentLine[MAX_LINE_LENGTH];

    fgets(currentLine, MAX_LINE_LENGTH, csvFileHolder);
    fwrite(currentLine, strlen(currentLine), 1, binaryFileHolder);

    while(fgets(currentLine, MAX_LINE_LENGTH, csvFileHolder) != NULL){
        Firm firm;
        Tokenization(currentLine, &firm);
        fwrite(&firm, sizeof(firm), 1, binaryFileHolder);
    }
}

void Deserialize(FILE *binaryFileHolder, FILE *csvFileHolder){
    char currentLine[MAX_LINE_LENGTH];

    fgets(currentLine, MAX_LINE_LENGTH, binaryFileHolder);
    fprintf(csvFileHolder, "%s", currentLine);

    Firm firm;
    while(fread(&firm, sizeof(firm), 1, binaryFileHolder) == 1){
        fprintf(csvFileHolder, "%d, %s, %s, %s, %s, %s, %d, %s, %s, %s, %s, %.2f\n",firm.rowID, firm.orderID, firm.orderDate, firm.customer, firm.city, firm.state, firm.postalCode, firm.region, firm.productID, firm.category, firm.subCategory, firm.price);
    }
}