//
//  fileinput.h
//  SLR Parser
//
//  Created by eRrOr on 28/03/19.
//  Copyright © 2019 eRrOr. All rights reserved.
//

#ifndef fileinput_h
#define fileinput_h

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getlen (int l) {
    
    FILE * file;
    char ch;
    int characters, lines;
    file = fopen("/assignment2-sample-grammar2.txt", "r");
    if (file == NULL) {
        printf("\nUnable to open file.\n");
        printf("Please check if file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }
    
    characters = lines = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lines++;
            if (lines == l+1) {
                break;
            }
        }
    }
    while ((ch = fgetc(file)) != '\n') {
        characters++;
    }
    fclose(file);
    return lines;
}

char getpro () {
    return 'A';
}

#endif /* fileinput_h */
