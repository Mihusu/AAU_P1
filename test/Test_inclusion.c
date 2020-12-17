#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    double doubleVal; //density array
    int intVal; //value to be inserted into CV, to declare which to add first.
} tTuple;//defines the tuple as (x,y), where x is double val, and y is intval

#define KEYWORD_LENGTH 12 //amount of keywords in array
#define PARA_AMOUNT 6 //amount of paragraphs
#define PARA_LENGTH 12 //length of each paragraph
#define MAX_WORDS 10 //max words in the CV
#define OUTPUT_PARA_AMOUNT 2 //amount of paragraphs in output

void inclusion();
int cmp_tuples();

int main(void) {
    //char **cv[PARA_AMOUNT];
    //char **cv1[];
    char *CV[PARA_AMOUNT][PARA_LENGTH] = {{"Jeg","har","en","gym","uddannelse"}, //testing, tb replace by read.c
                                            {"jeg","har","arbejdet","i","netto"},
                                            {"Jeg","er","god","til","C","prog"},
                                            {"Erfaring","med","C","python","css","og","databaser"}};
    char *buzz[KEYWORD_LENGTH] = {"netto","gym","C","prog","css","databaser","python","statistik",
                                  "sandsynlighedsteori","machinelearning","Bsc","Software"}; //testing, tb replace by read.c
    int length[PARA_AMOUNT] = {5,5,6,10,6,7};
    double density_of_Paragraph[PARA_AMOUNT] = {0.2, 0.96, 0.53, 0.67, 0.77, 0.4};
    bool included_Paragraphs[PARA_AMOUNT] = {};
    inclusion(density_of_Paragraph,CV, length, &included_Paragraphs);

    return 0;
}

// Comparing tuples by comparing the first (double) value = doubleval. to be used in stdlib.qsort
int cmp_tuples(const void * a, const void * b) {
    double cmp = ((*(tTuple*)b).doubleVal - (*(tTuple*)a).doubleVal);
    // Make sure a negative double also results in returning a negative int, and likewise for positive
    if (cmp < 0.0) {return -1;}
    else if (cmp > 0.0) {return 1;}
    else {return 0;}
}


void inclusion(double *Density, char *CV[PARA_AMOUNT][PARA_LENGTH], int length[PARA_AMOUNT], bool *include) {
    tTuple priority_array[PARA_AMOUNT]; //defining priority array as a tuple

    for (int i = 0; i < PARA_AMOUNT; i++) { //initializes the priority array with the values from density.
        priority_array[i].doubleVal = Density[i];
        priority_array[i].intVal = i;
        printf("%d doubleval: %lf, intVal: %d  ---", i, priority_array[i].doubleVal,priority_array[i].intVal); //testing
        printf("density[%d]: %lf, CV[%d]: %s, length[%d]: %d, include[%d]: %d\n",i, Density[i], i, *CV[i], i, length[i],i,include[i]); //test
    }

    int words = 0;
    int i = 0;
    i++;
    
    printf("\n==============\n"); //test
    qsort(priority_array, PARA_AMOUNT, sizeof(tTuple), cmp_tuples); //sorts the priority array from highest density to lowest
    for (int i = 0; i < PARA_AMOUNT; i++) { //test
        printf("%d doubleval: %lf, intVal: %d  ---\n", i, priority_array[i].doubleVal,priority_array[i].intVal); //testing
    }
}