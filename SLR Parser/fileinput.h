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

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    
    fp = fopen("grammer1.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    
    char **data;
    data = (char **)malloc(20 * sizeof(char *));
    for (int i = 0; i < 20; ++i){
        data[i] = (char *)malloc(20 * sizeof(char));
    }
    
    while ((read = getline(&line, &len, fp)) != -1) {
        len = strlen(line);
        //printf("Retrieved line of length %zu:\n", read);
        //printf("%s\n", line);
        //rintf("%d\n", len);
        for (int i = 0; i < 1; i++){
            data[i] = line;
            printf("%s", data[i]);
        }
        
    }
    
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

#endif /* fileinput_h */
