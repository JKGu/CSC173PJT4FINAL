//
//  Database.c
//  CSC173PJT4
//
//  Created by Cecilia Zhang on 11/23/18.
//  Copyright © 2018 Junkang Gu. All rights reserved.
//

#include "Database.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Database new_Database(){
    Database this = (Database)malloc(sizeof(struct Database));
    this->relationList=new_ArrayList();
    return this;
}

void saveFile(Database database){
    FILE* file = NULL;
    file=fopen("Database.txt", "w+");
    int numRelations=database->relationList->cur;
    fprintf(file,"Num of Relations\n%d\n",numRelations);//Number of relations
    for(int i=0; i<numRelations;i++){//write a relation
        fprintf(file,"\n");
        Relation r= database->relationList->array[i];
        fprintf(file, "%s\n",r->name);
        fprintf(file,"Primary Key\n");
        fprintf(file, "%d\n",r->key);
        for(int k=0; k<r->schema->num;k++){//write the schema
            fprintf(file, "%s",r->schema->array[k]);
            if(k!=r->schema->num-1) fprintf(file, ";"); else fprintf(file, "\n");
        }
        int numTuples=r->all_Tuples->cur;
        for(int j=0; j<numTuples;j++){//write all tuples
            Tuple t=r->all_Tuples->array[j];
            for(int l=0; l<r->schema->num; l++){//write a tuple
                fprintf(file, "%s",t->array[l]);
                if(l!=r->schema->num-1) fprintf(file, ";"); else fprintf(file, "\n");
            }
        }
    }
    fclose(file);
}

//Database readFile(char* filename){
//    Database db=new_Database();
//    FILE* file;
//    file=fopen(filename, "r");
//    if(file==NULL){
//        printf("File not found\n");
//    }else{
//        char line[256];
//        fgets(line, sizeof(line), file);//ignore first line
//        char* tmp=fgets(line, sizeof(line), file);
//        int numRelation=stringToInt(tmp);
//        for( int i=0; i<numRelation;i++){//create a relation
//            Relation tmp=new_Relation();
//            fgets(line, sizeof(line), file);//ignore
//            tmp->name=fgets(line, sizeof(line), file);
//            fgets(line, sizeof(line), file);//ignore
//            tmp->key=stringToInt(fgets(line, sizeof(line), file));
//            char* schema=fgets(line, sizeof(line), file);
//            for(int j=0;j<)
//                }
//    }
//    return db;
//
//}

int stringToInt(char* string){
    int output=0;
    long length=strlen(string);
    for(int i=0; i<length;i++){
        output=output*10+(string[i]-'0');
    }
    return output;
}

//Tuple stringToTuple(char* tuple){
//    Tuple output=new_Tuple();
//    
//}
