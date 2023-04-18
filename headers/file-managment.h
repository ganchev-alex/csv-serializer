#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "firm-structure.h"

#define MAX_LINE_LENGTH 1024

void AssignStringValues(char **field, char *token){
    if (*field != NULL) {
        free(*field);
    }
    *field = (char*) malloc(strlen(token)+1);
    strcpy(*field, token);
}

void Tokenization(char *pLine, Firm *pFirm){
    char *token;

    token = strtok(pLine, ",");
    pFirm -> rowID = atoi(token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->orderID, token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->orderDate, token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->customer, token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->city, token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->state, token);

    token = strtok(NULL, ",");
    pFirm -> postalCode = atoi(token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->region, token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->productID, token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->category,token);

    token = strtok(NULL, ",");
    AssignStringValues(&pFirm->subCategory, token);

    token = strtok(NULL, ",");
    pFirm -> price = atof(token);
}

void Serialize(FILE *csvFileHolder, FILE *binaryFileHolder){
    char currentLine[MAX_LINE_LENGTH];

    fgets(currentLine, MAX_LINE_LENGTH, csvFileHolder);
    fwrite(currentLine, strlen(currentLine), 1, binaryFileHolder);

    while(fgets(currentLine, MAX_LINE_LENGTH, csvFileHolder) != NULL){
        Firm firm = {0};
        Tokenization(currentLine, &firm);
        fwrite(&firm, sizeof(Firm), 1, binaryFileHolder);
    }
}

void Deserialize(FILE *binaryFileHolder, FILE *csvFileHolder){
    char currentLine[MAX_LINE_LENGTH];

    fgets(currentLine, MAX_LINE_LENGTH, binaryFileHolder);
    fprintf(csvFileHolder, "%s", currentLine);

    Firm firm;
    while(fread(&firm, sizeof(Firm), 1, binaryFileHolder) == 1){
        fprintf(csvFileHolder, "%d,%s,%s,%s,%s,%s,%d,%s,%s,%s,%s,%.2f\n",firm.rowID, firm.orderID, firm.orderDate, firm.customer, firm.city, firm.state, firm.postalCode, firm.region, firm.productID, firm.category, firm.subCategory, firm.price);
    }
}