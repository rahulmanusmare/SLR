//
//  main.c
//  SLR Parser
//
//  Created by eRrOr on 22/03/19.
//  Copyright © 2019 eRrOr. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "tree.h"
#include "csvr.h"


int main (int argc, const char * argv[]) {
    
    char str [20];
    char parseTable [100][100];
    printf("Enter Any String (Ending with \'$\') : ");
    gets(str);
    struct Stack* stack = createStack(100);
    push(stack, 0);
    
    readcsv ("assignment2-sample parsetable2.csv", parseTable);
    
    for (int i=0;i<20;i++) {
        for (int j=0;j<20;j++) {
            printf(" %c ", parseTable [i][j]);
        }
        printf("\n");
    }
    
    for (int i=0;str[i]!='\0';i++) {
        if (str[i] == '$') {
            
        } else {
            
        }
    }
    return 0;
}
