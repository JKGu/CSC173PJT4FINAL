//
//  Relation.c
//  Project4 Database_1
//
//  Created by Cecilia Zhang on 11/12/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#include "Relation.h"

#include <stdio.h>
#include <stdlib.h>

struct Relation {
    Tuple schema;
    int key;
    ArrayList all_Tuples; //A general list to keep all tuples so that we can iterate
    Tree secTrees[10];
    LinkedList *hashT[20];
    int n_attr;
    int n_el;
};

Relation new_Relation(){
    Relation this = (Relation)malloc(sizeof(struct Relation));
    this->schema = new_Tuple();
    this->key = -1;
    this->all_Tuples = new_ArrayList();
    for (int i=0; i<20; i++){
        this->hashT[i] = LinkedList_new();
    }
    for (int i = 0; i<10; i++){
        this->secTrees[i] = NULL;
    }
    this->n_attr = 0;
    this->n_el = 0;
    return this;
}

void Relation_set_KeySchema(int keynum, Tuple schema, Relation this){
    this->schema = schema;
    this->n_attr = schema->num;
    
    this->key = keynum;
    //Initialize all secTrees
    for (int i=0; i<this->n_attr ; i++){
        if(i!=keynum){
            this->secTrees[i] = new_Tree(i, this->schema->array[i]);
        }
    }
}


void Relation_insert(Tuple el, Relation this){
    
    //All_Tuples
    ArrayList_add(el, this->all_Tuples);
    
    //Hash basket
    int index = *(el->array[this->key]);
    int hash_to = Relation_hash_fun(index);
    LinkedList_add_at_end(this->hashT[hash_to], el);
    
    //Secondary trees
    for (int i=0; i<this->n_attr ; i++){
        if(i!=this->key){
            BST_add_child(el, this->secTrees[i], el->array[i]);
        }
    }
}

int Relation_hash_fun(int index){
    return index%20;
}

void Relation_append_attr(char* new_schema, ArrayList new_els,  Relation this){
    
    //Update the schema
    Tuple_add_el(new_schema, this->schema);
    
    //Iterate through all tuples to add new element
    for (int i=0; i<new_els->cur; i++){
        while(i<this->all_Tuples->cur){
            this->all_Tuples->array[i] = new_els->array[i];
        }
    }
    //No need to care about the hash table and trees cuz they are just pointers
}

LinkedList* Relation_lookup(Tuple quest, Relation this){
    LinkedList *valid_tuples = LinkedList_new();
    if(quest->num != this->n_attr){
        printf("Invalid Quest");
        return NULL;
    }
    for (int i=0; i < quest->num; i++){
        if(i == this->key){
            int hash_to = Relation_hash_fun(*quest->array[i]);
            LinkedListIterator it = *LinkedList_iterator(this->hashT[hash_to]);
            while(LinkedListIterator_has_next(&it)){
                Tuple temp = LinkedListIterator_next(&it);
                if(Compare_tuples(temp, quest)){
                    if(!LinkedList_contains(valid_tuples, temp))
                        LinkedList_add_at_end(valid_tuples, temp);
                }
            }
            if (!LinkedListIterator_has_next(&it)){
                printf("Item not found\n");
                return NULL;
            }
        }else {
            Tuple temp = BST_find(quest->array[i], this->secTrees[i]);
            if(temp == NULL){
                printf("Item not found\n");
                return NULL;
            } else {
                if(Compare_tuples(temp, quest)){
                    if(!LinkedList_contains(valid_tuples, temp))
                        LinkedList_add_at_end(valid_tuples, temp);
                }
            }
        }
    }
    return valid_tuples;
}



bool Compare_tuples (Tuple t1, Tuple t2){
    for (int i=0; i<t1->num; i++){
        if(*t1->array[i] != *t2->array[i] && *t1->array[i] != '*')
            return false;
    }
    return true;
}
