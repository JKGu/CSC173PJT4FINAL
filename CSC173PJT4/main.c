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
    Tuple_add_el("CS101", t);
    Tuple_add_el("12345", t);
    Tuple_add_el("A", t);

    Tuple t2 = new_Tuple();
    Tuple_add_el("CS101", t2);
    Tuple_add_el("67890", t2);
    Tuple_add_el("B", t2);

    Tuple t3 = new_Tuple();
    Tuple_add_el("EE200", t3);
    Tuple_add_el("12345", t3);
    Tuple_add_el("C", t3);

    Tuple t4 = new_Tuple();
    Tuple_add_el("EE200", t4);
    Tuple_add_el("22222", t4);
    Tuple_add_el("B+", t4);
    
    
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
    
    
    print_Relation(CSG);
    print_Relation(Relation_lookup(t, CSG));
    
Relation_delete(t, CSG);
    print_Relation(CSG);
    //LinkedList *found = Relation_lookup(t4, CSG);
    return 0;
}
