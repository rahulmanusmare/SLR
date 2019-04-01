//
//  csvReader.h
//  SLR-new
//
//  Created by eRrOr on 30/03/19.
//  Copyright © 2019 eRrOr. All rights reserved.
//

#ifndef csvReader_h
#define csvReader_h

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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

int readcsv() //two arguments namely text file and csv file
{
    
    int row,col;
    row = 0;
    col = 10;
    
    //char ***data;  //matrix to store parse table
    
    FILE * fp;
    char * line;
    size_t len = 40;
    size_t read;
    
    
    //reading file to count number of lines first to determine number of rows "data" matrix will have
    
    fp = fopen("assignment2-sample parsetable2.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    line = (char *)malloc(len*sizeof(char));
    if( line == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    while ((read = getline(&line, &len, fp)) != -1)
    {
        row++;
        //printf("%s\n", line);
    }
    
    fclose(fp);
    if (line)
        free(line);
    
    //counting done. reopening again
    
    fp = fopen("table1.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    line = (char *)malloc(len*sizeof(char));
    if( line == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    
    //initializing data
    
    FILE *f;
    f = fopen("table.txt","w");
    if (f == NULL)
        exit(EXIT_FAILURE);
    while ((read = getline(&line, &len, fp)) != -1)
    {
        for(int i=0; line[i]!='\0';i++)
        {
            if((i==0)&&(line[i]==','))
            {
                fprintf(f," ");
            }
            if((line[i]==',')&&(line[i+1]==','))
            {
                fprintf(f,", ");
            }
            else
            {
                fprintf(f,"%c",line[i]);
            }
        }
    }
    
    fclose(fp);
    if (line)
        free(line);
    fclose(f);
    char ***data;
    data = (char ***)malloc(row * sizeof(char **));
    for (int i = 0; i < row; ++i){
        data[i] = (char **)malloc(col * sizeof(char *));
    }
    
    read_csv(row, col, "table.txt", data);
    return 0;
    
}

#endif /* csvReader_h */
