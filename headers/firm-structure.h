#include <stdio.h>

typedef struct {

    unsigned int rowID;
    char orderID[14];
    char orderDate[10];
    char customer[8];
    char city[50];
    char state[50];
    unsigned int postalCode;
    char region[10];
    char productID[15];
    char category[35];
    char subCategory[25];
    float price; 

} Firm;

