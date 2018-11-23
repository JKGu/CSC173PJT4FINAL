//
//  Relation.h
//  Project4 Database_1
//
//  Created by Cecilia Zhang on 11/12/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#ifndef Relation_h
#define Relation_h

#include "BST Tree.h"
#include "Tuple.h"
#include "LinkedList.h"

#include <stdio.h>

#endif /* Relation_h */

typedef struct Relation* Relation;

Relation new_Relation(void);

void Relation_set_KeySchema(int keynum, Tuple schema, Relation this);

int Relation_hash_fun(int index);

void Relation_insert(Tuple el, Relation this);

void Relation_append_attr(char* new_schema, ArrayList new_els,  Relation this);

Relation Relation_lookup(Tuple quest, Relation this);

bool Compare_tuples (Tuple t1, Tuple t2);

void Relation_delete(Tuple quest, Relation this);

void print_Relation(Relation R);
