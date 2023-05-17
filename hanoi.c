#include "hanoi.h"

double facto(int n)
{
   if (n == 0)
	   return 1;
   else 
	   return n*facto(n-1);
}

double fibo(int n)
{
	if(n==1) 
		return 0;
	else if(n==2) 
		return 1;
	else 
		return fibo(n-1)+fibo(n-2);
}

void hanoi_tower(int n, char from, char tmp, char to)
{
 	if( n==1 ) 
		printf("���� 1�� %c ���� %c���� �ű��.\n",from,to);
	else 
	{
		hanoi_tower(n-1, from, to, tmp);
		printf("���� %d�� %c���� %c���� �ű��.\n",n, from, to);
		hanoi_tower(n-1, tmp, from, to);
	}
}

element delete(ArrayListType *L, int position)
{
	int i;
	element item;
	if( position < 0 || position >= L->length ){
		fprintf(stderr, "��ġ ����");
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
	if( !is_full(L) /*��*/ && (position >= 0) /*��*/ &&
		(position <= L->length)/*��*/ ){
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

void menu()
{
    int num; 
	int i;   
	int k; 

	clock_t start, finish;
   
	double  duration;
	int sum, j;
    
	int result1;
	int array[10]={5,9,10,17,21,29,33,37,38,43};
	int result;
	ArrayListType list1, *plist;

	printf("<<< CHAPTER02 >>>\n");
	printf("01. ���丮��\n");
	printf("02. �Ǻ���ġ\n");
	printf("03. �ϳ��� Ÿ��\n");
	printf("04. Ž��\n");
	printf("05. �ð� ����\n");
	printf("06. �迭 ����Ʈ ����\n");
	printf("07. �迭 ����Ʈ ���� �޸� �Ҵ�\n");
	printf("08. ���α׷� ����\n");
	printf("select => : ");
	scanf("%d",&num);
	
	while(num!=8)
	{
		switch(num)
		{
		case 1:
			printf("01. facto(k)-> k���� �Է��Ͻÿ�.");
			scanf("%d",&k);
			
			start = clock();
			printf("%d ���丮�� ��� : %.2lf�Դϴ�.\n", k, facto(k));
			finish = clock();

			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("�ӵ� ���� ��� %f ���Դϴ�.\n", duration);
			break;

		case 2:
			printf("02. fibo(K)-> k���� �Է��Ͻÿ�.");
			scanf("%d",&k);

			start = clock();
			printf("�Ǻ���ġ ���� ���  \n");
			printf("******************************************\n");
	        
			for(i=1;i<=k;i++)
				printf("%.2lf\t",fibo(i));
			finish = clock();
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			
			printf("�ӵ� ���� ��� %f ���Դϴ�.\n", duration);
			break;

		case 3:
			printf("03. hanoi_tower(k)-> k���� �Է��Ͻÿ�.");
			scanf("%d",&k);
			
			start = clock();
			printf("�ϳ��� Ÿ�� ��� \n");
			
			hanoi_tower(k,'A','B','C');
	     	finish = clock();
	     	
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
            printf("�ӵ� ���� ��� %f ���Դϴ�.\n", duration);
		    break;

		case 4:
			printf("Ž���� ���� �Է�: ");  
			scanf("%d",&k);
			
			result = seq_search(array, 10, k);
			printf("�迭�� ��� %d ��°\n",result);
			break;

		case 5:
			start = clock(); 
			for(k=0; k<MAX_ELEMENTS; k++)
			{
				score[k]=k;
			}
			result1 = find_max_score(MAX_ELEMENTS);        
			printf("�ְ�����: %d\n", result1);
			finish = clock(); 
			
			duration = (double)(finish - start) / CLOCKS_PER_SEC;
			printf("%f ���Դϴ�.\n", duration);
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
		printf("01. ���丮��\n");
		printf("02. �Ǻ���ġ\n");
		printf("03. �ϳ��� Ÿ��\n");
		printf("04. Ž��\n");
		printf("05. �ð� ����\n");
		printf("06. �迭 ����Ʈ ����\n");
		printf("07. �迭 ����Ʈ ���� �޸� �Ҵ�\n");
		printf("08. ���α׷� ����\n");
		printf("\nselect => : ");
		scanf("%d",&num);
	}
}

int find_max_score(int n) 
{  
	int i, tmp;
	tmp=score[0];

	for(i=1;i<n;i++)
	{ 
	
		if( score[i] > tmp )
		{
			tmp = score[i];
		}
	}
	return tmp;
}

void measureTime(void)
{                            
    clock_t start, finish;
    double  duration;
    int i, sum,j;
    int k;
	int result1;
	int array[10]={5,9,10,17,21,29,33,37,38,43};
	int num;
	int result;
	    
   	printf("Ž���� ���� �Է�: ");  
	scanf("%d",&num);

	start = clock(); 
	result = seq_search(array, 10, num);
	printf("�迭�� ��� %d ��°\n", result);
	
	for(k=0; k<MAX_ELEMENTS; k++)
	{
		score[k]=k;
	}
	result1 = find_max_score(MAX_ELEMENTS); 
	printf("�ְ�����: %d\n", result1);
    finish = clock(); 
   
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f ���Դϴ�.\n", duration);
} 

int seq_search(int* list, int n, int key)  
{
	int i;
		
	for(i=0; i<n; i++)
	{
		if(list[i]==key)
			return i;
	}
	return -1;
}