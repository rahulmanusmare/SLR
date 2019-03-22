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

void readcsv (char * filename, char mat [100][100]) {
    
    char buffer[1024] ;
    char *record,*line;
    int i=0,j=0;
    FILE *fstream = fopen(filename, "r");
    if(fstream == NULL)
    {
        printf("\n file opening failed ");
    }
    while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
    {
        record = strtok(line,";");
        while(record != NULL)
        {
            printf("record : %s",record) ;  
            mat[i][j++] = atoi(record) ;
            record = strtok(NULL,";");
        }
        ++i ;
    }
}


#endif /* csvr_h */
