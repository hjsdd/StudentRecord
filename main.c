/**
 main.c
 Program supplied as a starting point for
 Assignment 1: Student record manager
 COMP9024 17s2
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
        //printf("argc_count:%d\n", argc_count);
        //char *id_count = malloc(sizeof(char));
        
        //testing
        /*char *test;
        test = "121411414241414";
        printf("Testing: %s\n", test);
        
        The sizeof(char) = 1, sizeof(*char) = 8 for 64 bits CPU
        int charArraySize = sizeof(test);
        printf("Testing Char Arry Size: %d\n", charArraySize);*/
        
        typedef struct{
            char id[8];
            int credit;
            float wam;
        }studentRecord;
        
        //studentRecord *studentRecords = malloc(argc_count*sizeof(studentRecord));
        //assert(studentRecords != NULL);
        
        while (argc_count > 0) {
            
            char id_digits[100];
            
            while (1) {
                
                printf("Enter student ID: \n");
                scanf("%s",&id_digits[0]);
                printf("Enter student ID is : %s\n",id_digits);
                
                int id_counts = 0;
                char *c = &id_digits[0];
                while (*c != '\0') {
                    c++;
                    id_counts++;
                    //printf("Pointer Value ===== : %c\n",*c);
                    //printf("ID Counts: %d\n",id_counts);
                }
                /* 2rd attempt, try to initial a unsigned int type for scanf the inputs
                 while (id_digits != 0) {
                    id_digits = id_digits / 10;
                    id_counts++;
                }*/
                if (id_counts == 7) {
                    break;
                }
                else {printf("Not valid. Enter a valid value: \n");}
            }

            argc_count--;
            
        }
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

