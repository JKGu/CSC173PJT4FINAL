//
//  BST Tree.h
//  Project4 Database_1
//
//  Created by Cecilia Zhang on 11/14/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#ifndef BST_Tree_h
#define BST_Tree_h

#include <stdio.h>

#endif /* BST_Tree_h */

typedef struct Tree* Tree;

typedef struct Node* Node;

Node new_Node(void* data, char* key);

Tree new_Tree(int key_attribute, char* name);

void BST_add_child(void* data, Tree this, char* key);

void BST_insert_help(Node this, Node new);

void* BST_find(char* key, Tree this);

void* BST_find_help(char* key, Node this);

void BST_set_root(Tree this, void* data, char* key);
