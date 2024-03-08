#include <stdio.h>
#include "header.h"

int main() {
    User aUser1;
    catatKeuangan(&aUser1);
    saveToFileMasuk(&aUser1);
    readFromFileMasuk(&aUser1);
    displayDetailTransaksi(&aUser1);
}