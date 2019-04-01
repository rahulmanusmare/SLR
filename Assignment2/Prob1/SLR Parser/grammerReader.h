//
//  grammerReader.h
//  SLR-new
//
//  Created by eRrOr on 30/03/19.
//  Copyright © 2019 eRrOr. All rights reserved.
//

#ifndef grammerReader_h
#define grammerReader_h
#define _GNU_SOURCE
#include <stdio.h>

char grammer [10][10] = {
    {"1 2"},
    {"A:aAbA"},
    {"A:a"}
};
void readFile () {
    FILE *file;
    file = fopen("assignment2-sample-grammar2.txt", "r");
    char chr = getc(file);
    int i=0,j=0;
    while (chr != EOF) {
        if (chr!='\n') {
            grammer[i][j] = chr;j++;
        } else {
            i++;
        }
        chr = getc(file);
    }
    for (int i=0;i<10;i++) {
        printf("%s", grammer [i]);
    }
    fclose(file);
}

int getlen (int l) {
    int count=0;
    while (grammer[l][count]!='\0') {
        count++;
    }
    return count-2;
}
char getpro (int l) {
    return grammer[l][0];
}

#endif /* grammerReader_h */
