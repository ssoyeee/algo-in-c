#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#define MAX_ELEMENTS 100  
double facto(int n);     
double fibo(int n);    
void hanoi_tower(int n, char from, char tmp, char to); 
void menu(void); 

int score[MAX_ELEMENTS];  
int find_max_score(int n); 
void measureTime(void);   
int seq_search(int* list, int n, int key); 

#define MAX_LIST_SIZE 100
typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE]; 
	int length; 
}ArrayListType;

void init(ArrayListType *);
element delete(ArrayListType *, int);
void add(ArrayListType *, int, element);
int is_empty(ArrayListType *);
int is_full(ArrayListType *);
void display(ArrayListType *);