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

int stringToInt(char* string){
    int output=0;
    long length=strlen(string);
    for(int i=0; i<length;i++){
        output=output*10+(string[i]-'0');
    }
    return output;
}

Tuple stringToTuple(char* tuple){
    Tuple output=new_Tuple();
    char * string = strtok(tuple, ";");
    while (string != NULL)
    {
        Tuple_add_el(string, output);
        string = strtok(NULL, ";");
    }
    return output;
}


char* removeNewLine(char* i){
    long length=strlen(i);
    if(i[length-1]=='\n'){
        i[length-1]='\0';
    }
    printf("PRINT:%s\n",i);
    return i;
}

Database readFile(char* filename){
    Database db=new_Database();
    FILE* file;
    file=fopen(filename, "r");
    if(file==NULL){
        printf("File not found\n");
    }else{
        char line[256];
        fgets(line, sizeof(line), file);//ignore first line
        char* tmp=removeNewLine(fgets(line, sizeof(line), file));
        int numRelation=stringToInt(tmp);//NUMBER OF RELATIONS
        
        
        for( int i=0; i<numRelation;i++){//create a relation
            Relation tmp=new_Relation();
            fgets(line, sizeof(line), file);//ignore
            tmp->name=removeNewLine(fgets(line, sizeof(line), file));
            fgets(line, sizeof(line), file);//ignore
            tmp->key=stringToInt(removeNewLine(fgets(line, sizeof(line), file)));
            fgets(line, sizeof(line), file);//ignore
            int numofTuple=stringToInt(removeNewLine(fgets(line, sizeof(line), file)));
            char* schema=removeNewLine(fgets(line, sizeof(line), file));
            tmp->schema=stringToTuple(schema);
            for( int j=0; j<numofTuple; j++){//create a tuple
                char* tuple=removeNewLine(fgets(line, sizeof(line), file));
                Relation_insert(stringToTuple(tuple), tmp);
            }
            ArrayList_add(tmp, db->relationList);
        }
    }
    return db;
    
}

void saveFile(Database database){
    FILE * file=NULL;
    file=fopen("Database.txt", "w+");
    int numRelations=database->relationList->cur;
    fprintf(file,"Num of Relations\n%d\n",numRelations);//Number of relations
    for(int i=0; i<numRelations;i++){//write a relation
        fprintf(file,"\n");
        Relation r= database->relationList->array[i];
        fprintf(file, "%s\n",r->name);
        fprintf(file,"Primary Key\n");
        fprintf(file, "%d\n",r->key);
        fprintf(file,"Num of tuples\n");
        fprintf(file, "%d\n",r->all_Tuples->cur);
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
