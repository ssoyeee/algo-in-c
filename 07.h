#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // �ð������� ���� ���̺귯���� time ������� ��Ŭ���
#define MAX_ELEMENTS 100  
double FACT(int n);      // ���丮�� �Լ� ����
double FIBO(int n);      // �Ǻ���ġ �Լ� ���� ����
void hanoi_tower(int n, char from, char tmp, char to); // �ϳ��� Ÿ�� �Լ� ����
void MENU(void);  // �޴� �Լ� ����

int score[MAX_ELEMENTS];  // �ڷᱸ��
int find_max_score(int n); // find_max_score �Լ� ����
void measureTime(void);    //measureTime �Լ� ����
int seq_search(int* list, int n, int key); //seq_search �Լ� ���Ǻ�

#define MAX_LIST_SIZE 100
typedef int element;
typedef struct {
	element list[MAX_LIST_SIZE]; // �迭 ����
	int length; // ���� �迭�� ����� �׸���� ����
}ArrayListType;

void init(ArrayListType *);
element delete(ArrayListType *, int);
void add(ArrayListType *, int, element);
int is_empty(ArrayListType *);
int is_full(ArrayListType *);
void display(ArrayListType *);