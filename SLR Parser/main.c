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
#include <ctype.h>
#include "stack.h"
#include "tree.h"
#include "csvr.h"
#define max 10


int getCol (char ele, char table[max][max][3]) {
    for (int i=0; i<max; i++) {
        if (ele == table [0][i][0]) {
            return i;
        }
    }
    return 0;
}

int main (int argc, const char * argv[]) {
    
    int s = 0;
    char str [20];
    char parseTable [max][max][3];
    
    // Input Production
    printf("Enter Any String (Ending with \'$\') : ");
    gets(str);
    
    // Initialized Stack With 0
    struct Stack* stack = createStack(100);
    push(stack, 0);
    
    // Loop Until Input String
    for (int i=0;str [i]!='\0';i++) {
        
        // Getting Top of Stack
        char top = pop(stack);
        push(stack, top);
        
        if (isnumber(top)) {
            
            // Action
            // Checking if the Action if Shift Reduce or Accept
            char action = parseTable [top+1][getCol(str[s], parseTable)][0];
            if (action == 's') {
                // Shift
                
            } else if (action == 'r') {
                // Reduce
            } else if (action == 'a') {
                // Accept State
            }
        } else {
            // Goto
        }
    }
    /*
    for (int i=0;str[i]!='\0';i++) {
        if (str[i] == '$') {
            
        } else {
            
            if ( parseTable [temp+1][temp][0] == 'r' ) {
                int len = lenPro (parseTable[temp+1][temp][1]);
                char pro[20] = readPro (parseTable[temp+1][temp][1]);
                for (int j=0;j<len;j++) {
                    pop(stack);
                }
                struct node *root = newNode(pro[0]);
                root->left=str[i-1];
                push(stack, )
            } else if ( parseTable [temp+1][temp][0] == 's' ) {
                push(stack, str [i]);
                push(stack, stack->top);
            } else if ( parseTable [temp+1][temp][0] == 'a' ) {
                
            } else {
                printf("Invalid Parse Tree !!!");
            }
        }
    }
    */
    return 0;
}
