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
//#include "fileinput.h"
#define max 10

int getlen (int top) {
    
    return 2-2;
}

void read_grammar(FILE* fp){
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	int nt,t;
	char grammar[max][max];
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			grammar[i][j]='\0';	
		}
	}
    if (fp == NULL){exit(EXIT_FAILURE);}
    
    read=getline(&line,&len,fp);
    printf("%c\n",line[0]);
    printf("%c\n",line[2]);
    
    nt =line[0]-'0';
    t = line[2]-'0';
	
	printf("Non Terminals= %d\n",nt);
	printf("Terminals= %d\n",t);
	
	int count=0;
    while ((read = getline(&line, &len, fp)) != -1){
        //printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
        int j=0;
        while(line[j]!='\0'){
        	grammar[count][j]=line[j];
        	j=j+1;
        }  
        count+=1;
    }

	printf("number of productions=%d\n",count);
	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
			printf("%c",grammar[i][j]);
		}
		printf("\n");
	}
	
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
            
}

char getpro () {
    return 'A';
}

int getCol (char ele, char table[max][max][3]) {
    for (int i=0; i<max; i++) {
        if (ele == table [0][i][0]) {
            return i;
        }
    }
    return 0;
}

int main (int argc, const char * argv[]) {
    
    int s = 0;  //Current String Element
    char str [20];
    char parseTable [max][max][3] = {
        {{'\0'}, {'$'}, {'a'}, {'b'}, {'A'}},
        {{0}, {'\0'}, {"s2"}, {'\0'}, {1}},
        {{1}, {"acc"}, {'\0'}, {'\0'}, {'\0'}},
        {{2}, {"r2"}, {"s2"}, {"r2"}, {3}},
        {{3}, {'\0'}, {'\0'}, {"s4"}, {'\0'}},
        {{4}, {'\0'}, {"s2"}, {'\0'}, {5}},
        {{5}, {"r1"}, {'\0'}, {"r1"}, {'\0'}}
    };
    
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
            int index = atoi(&top)+1;
            int col = getCol(str [s], parseTable);
            char action = parseTable [index][col][0];
            if (action == 's') {
                // Shift
                push(stack, str[s]);
                push(stack, parseTable [index][col][1]);
                s++;
            } else if (action == 'r') {
                // Reduce
                // For Loop Will Pop 2X the lenghth of Production
                int prono = parseTable [index][col][1];
                int temp = getlen(prono);
                for (int j=0;j<2*temp;j++) {
                    pop(stack);
                }
                push(stack, getpro ());  // getpro will return Non-Termainal
            } else if (action == 'a') {
                // Accept State
                printf("String Accepted !!!");
                exit(0);
            } else {
                // Rejected Action
                printf("string rejected :( ");
                
            }
        } else {
            // Goto
            int col = getCol(top, parseTable);
            char temp = pop(stack);
            char row = pop(stack);
            push(stack, row);
            push(stack, temp);
            push(stack, parseTable[row][col][0]);
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
