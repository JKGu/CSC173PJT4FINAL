//
//  main.c
//  Project4 Database_1
//
//  Created by Cecilia Zhang on 11/12/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#include <stdio.h>
#include "Relation.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    Tuple t = new_Tuple();
    Tuple_add_el("CSC", t);
    Tuple_add_el("LZD", t);
    Tuple_add_el("D+", t);

    Tuple t2 = new_Tuple();
    Tuple_add_el("ECO", t2);
    Tuple_add_el("ZYX", t2);
    Tuple_add_el("A+", t2);

    Tuple t3 = new_Tuple();
    Tuple_add_el("AME", t3);
    Tuple_add_el("FSY", t3);
    Tuple_add_el("C", t3);
    Tuple_remove_el(1, t3);

    Tuple t4 = new_Tuple();
    Tuple_add_el("DMS", t4);
    Tuple_add_el("QYR", t4);
    Tuple_add_el("A", t4);
    
    
//    int keynum = 1;
//    Tree sec = new_Tree(keynum, "Student");
//    BST_add_child(t4, sec, t4->array[keynum]);
//    BST_add_child(t, sec, t->array[keynum]);
//    BST_add_child(t2, sec, t2->array[keynum]);
//    BST_add_child(t3, sec, t3->array[keynum]);
//
//    Tuple fsy = BST_find("QYR", sec);
//    print_Tupple(fsy);
//    Tuple zyx = BST_find("ZYX", sec);
//    print_Tupple(zyx);
//
//    ArrayList test = new_ArrayList();
//    ArrayList_add(t, test);
//    ArrayList_add(t2, test);
//    ArrayList_add(t3, test);
//
//    char* strings[] = {"Hello", "World","VeryLondWord","s"};
//    int n = sizeof(strings)/sizeof(strings[0]);
//    printf("%d\n", n);
//
//
    Relation CSG = new_Relation();
    Tuple CSG_schema = new_Tuple();
    Tuple_add_el("Course", CSG_schema);
    Tuple_add_el("Student", CSG_schema);
    Tuple_add_el("Grade", CSG_schema);
    Relation_set_KeySchema(1,CSG_schema, CSG);
    Relation_insert(t, CSG);
    Relation_insert(t2, CSG);
    Relation_insert(t3, CSG);
    Relation_insert(t4, CSG);

    LinkedList *ls = LinkedList_new();
    LinkedList_add_at_end(ls, t);
    LinkedList_add_at_end(ls, t3);
    LinkedList_add_at_end(ls, t2);
    LinkedList_add_at_end(ls, t4);
    
    LinkedListIterator it = *LinkedList_iterator(ls);
    
    while(LinkedListIterator_has_next(&it)){
        if(LinkedListIterator_next(&it)==t2){
            print_Tupple(t2);
        }
    }

    LinkedList *found = Relation_lookup(t4, CSG);
    l
    return 0;
}
