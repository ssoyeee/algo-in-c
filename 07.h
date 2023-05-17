#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // 시간측정을 위해 라이브러리와 time 헤어파일 인클루드
#define MAX_ELEMENTS 100  
double FACT(int n);      // 팩토리얼 함수 선언
double FIBO(int n);      // 피보나치 함수 수열 선언
void hanoi_tower(int n, char from, char tmp, char to); // 하노이 타워 함수 선언
void MENU(void);  // 메뉴 함수 선언

int score[MAX_ELEMENTS];  // 자료구조
int find_max_score(int n); // find_max_score 함수 선언
void measureTime(void);    //measureTime 함수 선언
int seq_search(int* list, int n, int key); //seq_search 함수 정의부

#define MAX_LIST_SIZE 100
typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE]; // 배열 정의
	int length; // 현재 배열에 저장된 항목들의 개수
}ArrayListType;

void init(ArrayListType *);
element delete(ArrayListType *, int);
void add(ArrayListType *, int, element);
int is_empty(ArrayListType *);
int is_full(ArrayListType *);
void display(ArrayListType *);