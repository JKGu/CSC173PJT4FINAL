//
//  BST Tree.c
//  Project4 Database_1
//
//  Created by Cecilia Zhang on 11/14/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#include "BST Tree.h"

#include <stdio.h>
#include <stdlib.h>

struct Tree {
    Node root;
    int key_attribute;
};

struct Node {
    void* data;
    char* attr_el;
    Node lc;
    Node rc;
    Node p;
};

Node new_Node(void* data, char* key){
    Node this = (Node)malloc(sizeof(struct Node));
    this->data = data;
    this->attr_el = key;
    this->lc = NULL;
    this->rc = NULL;
    this->p=NULL;
    return this;
}

Tree new_Tree(int key_attribute, char* name){
    Tree this = (Tree)malloc(sizeof(struct Tree));
    this->root = new_Node(NULL, name);
    this->key_attribute = key_attribute;
    return this;
}

void BST_set_root(Tree this, void* data, char* key){
    this->root = new_Node(data, key);
}

void BST_add_child(void* data, Tree this, char* key){
    Node new = new_Node(data, key);
    BST_insert_help(this->root, new);
}

void BST_insert_help(Node this, Node new){
    if(new->attr_el > this->attr_el){
        if(this->rc == NULL)
        {this->rc = new; new->p=this;}
        else
            BST_insert_help(this->rc, new);
    }if(new->attr_el <= this->attr_el){
        if(this->lc == NULL)
        {this->lc = new;new->p=this;}
        else
            BST_insert_help(this->lc, new);
    }else{
        this = new;
    }
}

void* BST_find(char* key, Tree this){
    return BST_find_help(key, this->root);
}

void* BST_find_help(char* key, Node this){
    if(key > this->attr_el)
        return BST_find_help(key, this->rc);
    if(key < this->attr_el)
        return BST_find_help(key, this->lc);
    else if(this->attr_el == key)
        return this->data;
    return NULL;
}

void BST_delete(void*data, Tree this, char* key){
    BST_delete_help(data, this->root, key);
}

char* BSTminValue(Node node){
    char* min = node->attr_el;
    while (node->lc != NULL)
    {
        min = node->lc->attr_el;
        node=node->lc;
    }
    return min;
}

Node BST_delete_help(void* data, Node this, char* key){
    if(this==NULL) return this;
    if (key < this->attr_el)
        this->lc = BST_delete_help(data, this->lc, key);
    else if (key > this->attr_el)
        this->rc = BST_delete_help(data, this->rc, key);
    else
    {
        if (this->lc == NULL)
            return this->rc;
        else if (this->rc==NULL)
            return this->lc;
        this->attr_el = BSTminValue(this->rc);
        this->rc=BST_delete_help(data, this->rc, key);
    }
    return this;
}
