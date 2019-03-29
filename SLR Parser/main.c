//
//  main.c
//  SLR-new
//
//  Created by eRrOr on 30/03/19.
//  Copyright © 2019 eRrOr. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include "stack.h"
#include "grammerReader.h"
#define max 10

int getCol (char ele, char table[max][max][3]) {
    for (int i=0; i<max; i++) {
        if (ele == table [0][i][0]) {
            return i;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int s=0;
    char str[20];
    printf("Enter string ending with $ : ");
    scanf("%s", str);
    char parseTable [max][max][3] = {
        {{'\0'}, {'$'}, {'a'}, {'b'}, {'A'}},
        {{'0'}, {'\0'}, {"s2"}, {'\0'}, {1}},
        {{'1'}, {"acc"}, {'\0'}, {'\0'}, {'\0'}},
        {{'2'}, {"r2"}, {"s2"}, {"r2"}, {3}},
        {{'3'}, {'\0'}, {'\0'}, {"s4"}, {'\0'}},
        {{'4'}, {'\0'}, {"s2"}, {'\0'}, {5}},
        {{'5'}, {"r1"}, {'\0'}, {"r1"}, {'\0'}}
    };
    
    printf("Get Production : %c", getpro(2));
    
    printf("\n\nGiven parse table : \n\n");
    for (int i=0; i<max; i++) {
        for (int j=0; j<max; j++) {
            printf("\t%s", parseTable [i][j]);
        }
        printf("\n");
    }
    struct Stack* stack = createStack(100);
    push(stack, 0);
    
    for (int i=0; str [i] !='\0'; i++) {
        char top = pop(stack);
        push(stack, top);
        
        int index = top-'\0';
        printf("\n%d", index);
        if (!isalpha(index)) {
            int col = getCol(str [s], parseTable);
            char action = parseTable[index+1][col][0];
            if (action == 's') {
                char pushitem = parseTable[index+1][col][1]-'\0';
                push(stack, str[s]);
                push(stack, pushitem);
                s++;
            } else if (action == 'r') {
                printf("\n%c : Reduce", str[s]);
                int prono = parseTable [index+1][col][1];
                int temp = getlen(prono);
                for (int j=0;j<2*temp;j++) {
                    pop(stack);
                }
                char character = getpro (prono);
                push(stack, character);
            } else if (action == 'a') {
                printf("String Accepted !!!");
                exit(0);
            } else {
                printf("else");
            }
        } else {
            printf("\n%c : Goto", str[s]);
            int col = getCol(top, parseTable);
            char temp = pop(stack);
            char row = pop(stack);
            push(stack, row);
            push(stack, temp);
            push(stack, parseTable[row][col][0]);
        }
    }
    
    return 0;
}
