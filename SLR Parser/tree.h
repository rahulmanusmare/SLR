//
//  tree.h
//  SLR Parser
//
//  Created by eRrOr on 22/03/19.
//  Copyright © 2019 eRrOr. All rights reserved.
//

#ifndef tree_h
#define tree_h

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node* newNode(char data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

#endif /* tree_h */
