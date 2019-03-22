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


int main (int argc, const char * argv[]) {
    
    char str [20];
    printf("Enter Any String (Ending with \'$\') : ");
    gets(str);
    struct Stack* stack = createStack(100);
    push(stack, 0);

    return 0;
}
