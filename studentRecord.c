// Student record implementation ... Assignment 1 COMP9024 17s2
#include <stdio.h>

#define LINE_LENGTH 1024

// scan input for a positive integer, returns -1 if none
int readInt(void) {
   char line[LINE_LENGTH];
   int  n;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%d", &n) != 1) || n <= 0 )
      return -1;
   else
      return n;
}

// scan input for a positive floating point number, returns -1 if none
float readFloat(void) {
   char  line[LINE_LENGTH];
   float f;

   fgets(line, LINE_LENGTH, stdin);
   if ( (sscanf(line, "%f", &f) != 1) || f <= 0.0 )
      return -1;
   else
      return f;
}

/*** Your code for stage 1 starts here ***/
/**/


int readValidID(void) {
    
    printf("Enter student ID is : ");
    
    while (1) {
        int id = readInt();
        int id_7digits = id;
        //printf("id: %d\n", id);
        if (id == -1) {
            printf("Not valid. Enter a valid value: \n");
        }
        else {
            int id_counts = 0;
            
            while (id) {
                id = id / 10;
                id_counts++;
            }
            if (id_counts != 7) {
                printf("Not valid. Enter a valid value: \n");
                continue;
            }
            else {
                printf("Student zID: z%d\n", id_7digits );
                return id_7digits;
                
            }
        }
    }

   //return 0;  /* needs to be replaced */
}

int readValidCredits(void) {
    
    while (1) {
        printf("Enter credit points: ");
        int points = readInt();
        if (points <= 2 || points >= 480) {
            printf("Not valid. Enter a valid value: \n");
            continue;
        }
        else {
            return points;
        }
    }
   //return 0;  /* needs to be replaced */
}

float readValidWAM(void) {
    
    while (1) {
        printf("Enter WAM: ");
        float wam = readFloat();
        if (wam <=50 || wam >= 100) {
            
            printf("Not valid. Enter a valid value: \n");
            continue;
        }
        else {
            return wam;
        }
    }
   //return 0;  /* needs to be replaced */
}

void printStudentData(int zID, int credits, float WAM) {
    
    int sum_wam = 0;
    printf("-----------------\n");
    printf("Student zID: z%d\n",zID);
    printf("Credits: %d\n",credits);
    if (WAM >= 85) {
        printf("Level of performance: HD\n");
    }
    else if (WAM < 85 && WAM >=75 ) {
        printf("Level of performance: DN\n");
    }
    else if (WAM < 75 && WAM >=65 ) {
        printf("Level of performance: CR\n");
    }
    else if (WAM < 65 && WAM >=50 ) {
        printf("Level of performance: PS\n");
    }
    //printf("Level of performance: %f\n",WAM);
    printf("-----------------\n");
    
   //return;  /* needs to be replaced */
}
