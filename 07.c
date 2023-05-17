/*
    7조 조장: 이승민(2012150033)
	    조원: 박재환(2012154023), 박소연(2014150043)
*/

#include "07.h"

double FACT(int n)
{
   if (n == 0)
	   return 1;
   else 
	   return n*FACT(n-1);
}

double FIBO(int n)
{
	if(n==1) 
		return 0;
	else if(n==2) 
		return 1;
	else 
		return FIBO(n-1)+FIBO(n-2);
}

void hanoi_tower(int n, char from, char tmp, char to)
{
 	if( n==1 ) 
		printf("원판 1을 %c 에서 %c으로 옮긴다.\n",from,to);
	else 
	{
		hanoi_tower(n-1, from, to, tmp);
		printf("원판 %d을 %c에서 %c으로 옮긴다.\n",n, from, to);
		hanoi_tower(n-1, tmp, from, to);
	}
}

//리스트
element delete(ArrayListType *L, int position)
{
	int i;
	element item;
	if( position < 0 || position >= L->length ){
		fprintf(stderr, "위치 오류");
		exit(1);
	}
	item = L->list[position];
	
	for(i=position; i<(L->length-1);i++)
		L->list[i] = L->list[i+1];
	L->length--;
	return item;
}
void add(ArrayListType *L, int position, element item)
{
	if( !is_full(L) /*참*/ && (position >= 0) /*참*/ &&
		(position <= L->length)/*참*/ ){
		int i;
		for(i=(L->length-1); i>=position;i--)
			L->list[i+1] = L->list[i];
		L->list[position] = item;
		L->length++;
	}
}
int is_empty(ArrayListType *L)
{
	return L->length == 0;
}

int is_full(ArrayListType *L)
{
	return L->length == MAX_LIST_SIZE;
}
void display(ArrayListType *L)
{
	int i;
	for( i=0; i<L->length; i++)
		printf("%d\n", L->list[i]);
}
void init(ArrayListType *L)
{ //
	L->length = 0;
}

void MENU()
{
    int num; // 메뉴열 선택 넘버
	int i;   // 반복 함수 
	int k;  // 입력값

	clock_t start, finish;
   
	double  duration;
	int sum, j;
    
	int result1;
	int array[10]={5,9,10,17,21,29,33,37,38,43};
	int result;
	ArrayListType list1, *plist;

	printf("<<< CHAPTER02 >>>\n");
	printf("01. 팩토리얼\n");
	printf("02. 피보나치\n");
	printf("03. 하노이 타워\n");
	printf("04. 탐색\n");
	printf("05. 시간 측정\n");
	printf("06. 배열 리스트 선언\n");
	printf("07. 배열 리스트 동적 메모리 할당\n");
	printf("08. 프로그램 종료\n");
	printf("select => : ");
	scanf("%d",&num);
	
	while(num!=8)
	{
		switch(num)
		{
		case 1:
			printf("01. FACT(k)-> k값을 입력하시오.");
			scanf("%d",&k);
			
			start = clock();
			printf("%d 팩토리얼 결과 : %.2lf입니다.\n", k, FACT(k));
			finish = clock();

			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("속도 측정 결과 %f 초입니다.\n", duration);
			break;

		case 2:
			printf("02. FIBO(K)-> k값을 입력하시오.");
			scanf("%d",&k);

			start = clock();
			printf("피보나치 수열 결과  \n");
			printf("******************************************\n");
	        
			for(i=1;i<=k;i++)
				printf("%.2lf\t",FIBO(i));
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			
			printf("속도 측정 결과 %f 초입니다.\n", duration);
			break;

		case 3:
			printf("03. hanoi_tower(k)-> k값을 입력하시오.");
			scanf("%d",&k);
			
			start = clock();
			printf("하노이 타워 결과 \n");
			
			hanoi_tower(k,'A','B','C');
	     	finish = clock();
	     	
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
            printf("속도 측정 결과 %f 초입니다.\n", duration);
		    break;

		case 4:
			printf("탐색할 숫자 입력: "); // 탐색 함수 
			scanf("%d",&k);
			
			result = seq_search(array, 10, k);
			printf("배열의 요소 %d 번째\n",result);
			break;

		case 5:
			start = clock(); // 시작시간
			for(k=0; k<MAX_ELEMENTS; k++)
			{
				score[k]=k;
			}
			result1 = find_max_score(MAX_ELEMENTS);        // 검색 함수
			printf("최고점수: %d\n", result1);
			finish = clock(); // 종료시간
			
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("%f 초입니다.\n", duration);
			break;

		case 6:
		    init(&list1);
			add(&list1, 0, 10);
			add(&list1, 0, 20);
			add(&list1, 0, 30);
			display(&list1);
			break;
		case 7:
			plist = (ArrayListType*)malloc(sizeof(ArrayListType));
			init(plist);
			add(plist, 0, 10);
			add(plist, 0, 20);
			add(plist, 0, 30);
			display(plist);
			free(plist);
			break;
		}

		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("####CHAPTER02####\n");
		printf("01. 팩토리얼\n");
		printf("02. 피보나치\n");
		printf("03. 하노이 타워\n");
		printf("04. 탐색\n");
		printf("05. 시간 측정\n");
		printf("06. 배열 리스트 선언\n");
		printf("07. 배열 리스트 동적 메모리 할당\n");
		printf("08. 프로그램 종료\n");
		printf("\nselect => : ");
		scanf("%d",&num);
	}
}

int find_max_score(int n) // 학생의 숫자는 n
{  
	int i, tmp;
	tmp=score[0];

	for(i=1;i<n;i++)
	{ 
		// 알고리즘
		if( score[i] > tmp )
		{
			tmp = score[i];
		}
	}
	return tmp;
}

void measureTime(void)
{                              //수행시간 측정 코드
    clock_t start, finish;
    double  duration;
    int i, sum,j;
    int k;
	int result1;
	int array[10]={5,9,10,17,21,29,33,37,38,43};
	int num;
	int result;
	    
   	printf("탐색할 숫자 입력: ");  // 탐색 함수 
	scanf("%d",&num);

	start = clock(); // 시작시간
	result = seq_search(array, 10, num);
	printf("배열의 요소 %d 번째\n", result);
	
	for(k=0; k<MAX_ELEMENTS; k++)
	{
		score[k]=k;
	}
	result1 = find_max_score(MAX_ELEMENTS);  // 검색 함수
	printf("최고점수: %d\n", result1);
    finish = clock(); // 종료시간
   
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f 초입니다.\n", duration);
} 

int seq_search(int* list, int n, int key)  //순차탐색함수
{
	int i;
		
	for(i=0; i<n; i++)
	{
		if(list[i]==key)
			return i;
	}
	return -1;
}