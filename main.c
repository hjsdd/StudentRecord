/**
 main.c
 Program supplied as a starting point for
 Assignment 1: Student record manager
 COMP9024 17s2
 
 //?? *type[] , what's this mean?
 **/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "studentRecord.h"
#include "studentLL.h"

void printHelp();
void StudentLinkedListProcessing();

int main(int argc, char *argv[]) {
    //printf("Enter student ID: 111\n");
    if (argc == 2) {
        
        /*** Insert your code for stage 1 here ***/
        /*29 Nov 2018, 10:43 PM start*/
        // char converted to int
        int argc_count;
        sscanf(argv[1], "%d", &argc_count);

        studentRecordT studentRecords[argc_count];
        assert(studentRecords != NULL);
        float sum_wam = 0;
        
        for (int i = 0; i < argc_count; i++) {
            
            studentRecords[i].zID = readValidID();
            studentRecords[i].credits = readValidCredits();
            studentRecords[i].WAM = readValidWAM();
        }
        for (int i = 0; i < argc_count; i++) {
            printStudentData(studentRecords[i].zID,studentRecords[i].credits,studentRecords[i].WAM);
            sum_wam = studentRecords[i].WAM + sum_wam;
            
        }
        printf("Average WAM:%f\n",sum_wam/argc_count);
        
    } else {
        StudentLinkedListProcessing();
    }
    return 0;
}

/* Code for Stages 2 and 3 starts here */

void StudentLinkedListProcessing() {
    int op, ch;
    
    List list = newLL();   // create a new linked list
    
    while (1) {
        printf("Enter command (a,f,g,p,q, h for Help)> ");
        
        do {
            ch = getchar();
        } while (!isalpha(ch) && ch != '\n');  // isalpha() defined in ctype.h
        op = ch;
        // skip the rest of the line until newline is encountered
        while (ch != '\n') {
            ch = getchar();
        }
        
        switch (op) {
                
            case 'a':
            case 'A':
                
                /*** Insert your code for adding a student record ***/
                
                break;
                
            case 'f':
            case 'F':
                
                /*** Insert your code for finding a student record ***/
                
                break;
                
            case 'g':
            case 'G':
                
                /*** Insert your code for getting statistical information ***/
                
                break;
                
            case 'h':
            case 'H':
                printHelp();
                break;
                
            case 'p':
            case 'P':
                
                /*** Insert your code for printing all student records ***/
                
                break;
                
            case 'q':
            case 'Q':
                dropLL(list);       // destroy linked list before returning
                printf("Bye.\n");
                return;
        }
    }
}

void printHelp() {
    printf("\n");
    printf(" A - Add student record\n" );
    printf(" F - Find student record\n" );
    printf(" G - Get statistics\n" );
    printf(" H - Help\n");
    printf(" P - Print all records\n" );
    printf(" Q - Quit\n");
    printf("\n");
}

