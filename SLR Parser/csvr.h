//
//  csvr.h
//  SLR Parser
//
//  Created by eRrOr on 22/03/19.
//  Copyright © 2019 eRrOr. All rights reserved.
//

#ifndef csvr_h
#define csvr_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
void readcsv (char * filename, char mat [100][100][2] ) {
    
}

void read_csv(int row, int col, char *filename, char ***data){
    FILE *file;
    file = fopen(filename, "r");
    
    int i = 0;
    char line[4098];
    while (fgets(line, 4098, file) && (i < row))
    {
        // double row[ssParams->nreal + 1];
        char* tmp = strdup(line);
        
        int j = 0;
        const char* tok;
        for (tok = strtok(line, ","); tok && *tok; j++, tok = strtok(NULL, ","))
        {
            data[i][j] = tok;
            if (data[i][j] == NULL)
            {
                printf(" \t");
                
            }
            else
            {
                printf("%s\t", data[i][j]);
            }
            
        }
        printf("\n");
        
        free(tmp);
        i++;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    if (argc < 3){
        printf("Please specify the CSV file as an input.\n");
        exit(0);
    }
    
    int row     = atoi(argv[1]);
    int col     = atoi(argv[2]);
    char fname[256];    strcpy(fname, argv[3]);
    
    char ***data;
    data = (char ***)malloc(row * sizeof(char **));
    for (int i = 0; i < row; ++i){
        data[i] = (char **)malloc(col * sizeof(char *));
    }
    
    read_csv(row, col, fname, data);
    
    return 0;
}
*/

#endif /* csvr_h */
