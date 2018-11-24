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
    
    
    int keynum = 0;
    Tree sec = new_Tree(keynum, "Course");
    BST_add_child(t4, sec, t4->array[keynum]);
    BST_add_child(t, sec, t->array[keynum]);
    BST_add_child(t2, sec, t2->array[keynum]);
    BST_add_child(t3, sec, t3->array[keynum]);

    ArrayList st1 = BST_find("CS101", sec);
    for(int i=0; i<st1->cur ;i++){
        print_Tupple(st1->array[i]);
    }

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
    Tuple t_search = new_Tuple();
    Tuple_add_el("CS101", t_search);
    Tuple_add_el("*", t_search);
    Tuple_add_el("*", t_search);
    
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
    printf("\n");
    printf("Search on CSC101\n");
    print_Relation(Relation_lookup(t_search, CSG));
    
    Relation_delete(t_search, CSG);
    printf("\n");
    printf("Delete CSC101\n");
    print_Relation(CSG);
    //printf("\n%d\t%d\n", CSG->n_attr, CSG->n_el);
    //LinkedList *found = Relation_lookup(t4, CSG);
    
    Tuple t5 = new_Tuple();
    Tuple_add_el("22222", t5);
    Tuple_add_el("G.Furguson", t5);
    Tuple_add_el("Wilson Blvd", t5);
    Tuple_add_el("585-123-456", t5);

    
    Tuple t6 = new_Tuple();
    Tuple_add_el("67890", t6);
    Tuple_add_el("T.Pawliki", t6);
    Tuple_add_el("Faculty Rd", t6);
    Tuple_add_el("585-956-234", t6);

    
    Tuple t7 = new_Tuple();
    Tuple_add_el("12345", t7);
    Tuple_add_el("C.Brown", t7);
    Tuple_add_el("Campus Drive", t7);
    Tuple_add_el("585-000-010", t7);
    
    Relation SNAP = new_Relation();
    Tuple SNAP_schema = new_Tuple();
    Tuple_add_el("Student", SNAP_schema);
    Tuple_add_el("Name", SNAP_schema);
    Tuple_add_el("Address", SNAP_schema);
    Tuple_add_el("Phone", SNAP_schema);

    Relation_set_KeySchema(1,SNAP_schema, SNAP);
    Relation_insert(t5, SNAP);
    Relation_insert(t6, SNAP);
    Relation_insert(t7, SNAP);
    printf("\n");
    printf("Join on students\n");
    print_Relation(Relation_join("Student", "Student", CSG, SNAP));
    printf("\n");
    
    Tuple test=new_Tuple();
    Tuple_add_el("Student", test);
    printf("Project on Student\n");
    print_Relation(Relation_projection(test, CSG));
    
    printf("Selection on Student\n");
    print_Relation(Relation_selection(CSG, "Course", "EE200"));
    return 0;
    
}

