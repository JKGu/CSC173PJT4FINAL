//
//  main.c
//  Project4 Database_1
//
//  Created by Cecilia Zhang on 11/12/18.
//  Copyright © 2018 Cecilia Zhang. All rights reserved.
//

#include <stdio.h>
#include "Database.h"

int main(int argc, const char * argv[]) {
    
    Database db=readFile("Database.txt");
    
    printf("    Insert Tuple...\n");
    
    printf("    Relation [StudentID - Name - Address - Phone]\nBefore\n");
    
    // **** Check and Change the Index of the Relation in the Database ****
    print_Relation(db ->relationList ->array[1]);
    
    printf("    Inserting Tuple [67890 / T.Pawliki / Faculty Rd / 585-956-234]\n");
    Tuple tInsert1 = new_Tuple();
    Tuple_add_el("67890", tInsert1);
    Tuple_add_el("T.Pawliki", tInsert1);
    Tuple_add_el("Faculty Rd", tInsert1);
    Tuple_add_el("585-956-234", tInsert1);
    
    Relation toInsert = db ->relationList ->array[1];
    Relation_insert(tInsert1, toInsert);
    print_Relation(toInsert);
    
    
    
    printf("    Lookup Tuple...\n");
    printf("    Look Up Tuple [67890 / T.Pawliki / Faculty Rd / 585-956-234]\n");
    Relation toLookUp = Relation_lookup(tInsert1, toInsert);
    print_Relation(toLookUp);
    
    
    printf("    Delete Tuple...\n");
    printf("    Delete Tuple [67890 / T.Pawliki / Faculty Rd / 585-956-234]\n");
    Relation_delete(tInsert1, toInsert);
    print_Relation(toInsert);
    
    
    printf("    Relation Selection...\n");
    printf("    Select 'CS101' From Relation [Course - StudentID - Grade]\n");
    Relation csgToSelect = db -> relationList -> array[0];
    Relation csgSelected = Relation_selection(csgToSelect, "Course", "CS101");
    print_Relation(csgSelected);
    
    
    printf("    Relation Projection...\n");
    printf("    Project 'StudentID' From Relation [Course - StudentID - Grade]\n");
    Relation csgToProject = db -> relationList -> array[0];
    
    Tuple projectionT1 = new_Tuple();
    Tuple_add_el("Student", projectionT1);
    Relation csgProjected = Relation_projection(projectionT1, csgToProject);
    print_Relation(csgProjected);
    
    printf("    Relation Join...\n");
    printf("    Join Relation [Course - StudentID - Grade] and [StudentID - Name - Address -Phone] on 'StudentID'\n");
    Relation csgToJoin = db -> relationList -> array[0];
    Relation snapToJoin = db -> relationList -> array[1];
    Relation csgJoinedSnap = Relation_join("Student", "Student", csgToJoin, csgToProject);
    print_Relation(csgJoinedSnap);
    
    
    printf("    Query: What Grade Did [StudentName] get in [CourseName] ?...\n");
    
    char studentName[256];
    char courseName[256];
    do{
        printf("    -Please enter student's name (Enter 'quit' to quit query)\n");
        
        scanf("%s", studentName);
        
        printf("    -Please enter student's name (Enter 'quit' to quit query)\n");
        
        scanf("%s", courseName);
        Relation csgPart3 = db -> relationList -> array[0];
        Relation snapPart3 = db -> relationList -> array[1];
        
        print_Relation(what_grade_did_who_get_in_class(studentName, courseName, snapPart3, csgPart3));
        
    } while ( (strcmp(studentName, "quit")!=0 ) &&  (strcmp(courseName, "quit")!=0 ) );
    
    
    printf("    Query: Where is [StudentName] at [Time] on [Day]?...\n");
    
    char studentName2[256];
    char Time[256];
    char Day[256];
    
    do{
        printf("    -Please enter student's name (Enter 'quit' to quit query)\n");
        
        scanf("%s", studentName2);
        
        printf("    -Please enter Time (Enter 'quit' to quit query)\n");
        
        scanf("%s", Time);
        
        printf("    -Please enter Day (Enter 'quit' to quit query)\n");
        
        scanf("%s", Day);
        
        
        Relation csgPart3 = db -> relationList -> array[0];
        Relation snapPart3 = db -> relationList -> array[1];
        Relation cdhPart3 = db -> relationList -> array[3];
        Relation crPart3 = db -> relationList -> array[4];
        
        
        print_Relation(Where_is_who_at_when(studentName, Time, Day, csgPart3, snapPart3, cdhPart3, crPart3));
        
    } while ( (strcmp(studentName2, "quit")!=0 ) &&  (strcmp(Time, "quit")!=0 )
             &&  (strcmp(Day, "quit")!=0 ) );
    saveFile(db,"Database.txt");
    return 0;
    
}

