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
        //int student_count = argc_count;
        
        typedef struct{
            char id[9];
            int credit;
            float wam;
        }studentRecord;
        
        //studentRecord *studentRecord = malloc(argc_count*sizeof(studentRecords));
        studentRecord studentRecords[argc_count];
        assert(studentRecords != NULL);
        
        for (int i = 0; i < argc_count; i++) {
            
            char id_digits[100];
            int points;//whether the variable needs to be initialized or not
            float wam;
            
            // expecting a 7-digit number
            while (1) {
                
                printf("Enter student ID: ");
                scanf("%s",&id_digits[0]);
               // printf("Enter student ID is : %s\n",id_digits);
                int id_counts = 0;
                char *c = &id_digits[0];
                while (*c != '\0') {
                    c++;
                    id_counts++;
                }
                if (id_counts != 7) {

                    printf("Not valid. Enter a valid value: \n");
                    continue;
                }
                else {
                    for (int j = 0; j < 8; j++) {
                        studentRecords[i].id[j] = id_digits[j];
                        //printf("studentRecords[%d]->id[%d] : %c\n", i,j, studentRecords[i].id[j]);
                    }
                    break;
                }
            }
            //expecting a number between 2 and 480
            while (1) {
                printf("Enter credit points: ");
                scanf("%d",&points);
                if (points <= 2 || points >= 480) {
                    
                    printf("Not valid. Enter a valid value: \n");
                    continue;
                }
                else {
                    studentRecords[i].credit = points;
                    break;
                    
                }
            }
                
            //a floating point number between 50 and 100
            while (1) {
                printf("Enter WAM: ");
                scanf("%f",&wam);
                if (wam <=50 || wam >= 100) {
                    
                    printf("Not valid. Enter a valid value: \n");
                    continue;
                }
                else {
                    studentRecords[i].wam = wam;
                    break;
                }
            }
            
            //argc_count--;
        }
        int sum_wam = 0;
        for (int i = 0; i < argc_count; i++) {
            printf("-----------------\n");
            printf("Student zID: z%s\n",studentRecords[i].id);
            printf("Credits: %d\n",studentRecords[i].credit);
            if (studentRecords[i].credit >= 85) {
                printf("Level of performance: HD\n");
            }
            else if (studentRecords[i].wam < 85 && studentRecords[i].wam >=75 ) {
                printf("Level of performance: DN\n");
            }
            else if (studentRecords[i].wam < 75 && studentRecords[i].wam >=65 ) {
                printf("Level of performance: CR\n");
            }
            else if (studentRecords[i].wam < 65 && studentRecords[i].wam >=50 ) {
                printf("Level of performance: PS\n");
            }
            printf("Level of performance: %f\n",studentRecords[i].wam);
            printf("-----------------\n");
            sum_wam = studentRecords[i].wam + sum_wam;
        }
        printf("Average WAM:%f\n",sum_wam/argc_count);

            //scanf("%s",&studentRecords->id);
        
            /*if (studentRecords->credit <2 || studentRecords->credit >480) {
                //free(studentRecords->credit);
                printf("Not valid. Enter a valid value: \n");
            }
            scanf("%d",&studentRecords->credit);
            
            printf("Enter WAM: \n");
            scanf("%f",&studentRecords->wam);
            count--;
            printf("count: %d",count);*/
        
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

