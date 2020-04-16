#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 101 

//다항식을 나타내기 위한 구조체 
typedef struct 
{
	int coef; //계수
	int degree;//차수 
}row;

void sayData(row* a, int count) {
	int i;
	printf("수식을 입력하세요.");
	for (i = 0; i < count; i++) {
		scanf_s("%d", &a[i].coef);
		scanf_s("%d", &a[i].degree);
	}

}


void setData(row* a, row* a1) {
	int i = 0;
	int x;
	int j = a[0].degree;
	int index = (a[0].degree)+1;
	int num = 0;
	while (j != -1)
	{
		a1[i].degree = j;
		j--;
		i++;
	}
	
	for (x = 0; x <index; x++)
	{
		if (a1[x].degree == a[num].degree) {
			a1[x].coef = a[num].coef;
			num++;
		}
		else {
			a1[x].coef = 0;
			//printf("%d", a1[x].coef);
			//printf("%d", a1[x].degree);
		}
	}
	
	return;

}

void multi_poly(row* c, int count1, row* d, int count2, row* result)
{
	//result에 인덱스 설정하기 위해 k설정
	int k = 0;
	int num = c[0].degree + d[0].degree; //
	result[0].degree = c[0].degree + d[0].degree;//결과 다항식의 최고차항 정해주기
	for (int a = 0; a <= result[0].degree; a++)
	{
		result[a].degree = num;//결과 다항식 차수 입력
		num--;
	}
	for (int i = 0; i < count1; i++)
	{
		for (int j = 0; j < count2; j++)
		{
			//다항식의 곱-> 지수끼리 덧셈 계수끼리 곱셈
			result[k].degree = c[i].degree + d[j].degree;
			result[k].coef = c[i].coef * d[j].coef;
			k++;
		}

	}
	return;
}

void regulation(row* result, int count) //곱셈시 차수가 같은 지수끼리 묶어주기 
{
	for (int i = 0; i < count; i++)
	{
		if (result[i].degree == 0) break;
		if (result[i].coef == 0) break;
		for (int j = i + 1; j < count; j++)
		{
			//if (result[i].degree == 0) break;
			if (result[i].degree == result[j].degree)
			{
				result[i].coef += result[j].coef;
				result[j].coef = 0;
				result[j].degree = 0;
			}
		}
	}
	return;
}

void swapMax_Struct(row* a, int count)
{
	//임시 구조체 자리 변수
	row temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			//차수 비교하여 i보다 j가 크면 swap 함수 응용하여 result 구조체 변경
			if (a[i].degree < a[j].degree)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

		}
	}
	return;
}

void add_poly(row* c,  row* d,  row* result)
{
	int c_index = 0, d_index = 0, result_index = 0; //인덱스 변수 선언
	int c_degree = c[0].degree, d_degree = d[0].degree; //각 식의 최고차항 

	int big;
	if (c_degree > d_degree)
	{
		big = c_degree;
	}
	else
	{
		big = d_degree;
	}
	result[0].degree = big; //두 식의 최고차항 중 더 큰 차수가 결과값의 최고 차수
	int num = big;
	
	for (int x = 0; x <= big; x++)
	{
		result[x].degree = num;
		num--;
	}

	while (c_index <= c[0].degree && d_index <= d[0].degree)
	{
		if (c_degree > d_degree) //식1의 차수가 더 클 때
		{
			result[result_index++].coef = c[c_index++].coef;
			//printf("%d", c_degree);
			//printf("%d", result[result_index].coef);
			c_degree--;
			

		}
		else if (c_degree == d_degree)
		{
			result[result_index++].coef = c[c_index++].coef + d[d_index++].coef;
			//printf("%d", c_degree);
			//printf("%d", result[result_index].coef);
			
			d_degree--;
			c_degree--;

		}
		else
		{
			result[result_index++].coef = d[d_index++].coef;
			printf("%d", d_degree);
			printf("%d", result[result_index].coef);
		
			d_degree--;

		}
	}/*
	for (int a = 0; a <= c[0].degree; a++)
	{
		printf("%d %d", result[a].coef, result[a].degree);
	}*/
	return;
}

void getResult(row* a, int num)
{
	for (int i = 0; i <= num; i++)
	{
		if (a[i].degree == 0 && a[i].coef == 0) break;
		if (a[i].coef == 0) break; 
		printf("%d %d ", a[i].coef, a[i].degree);
	}
	printf("\n");

}

void calculate_sig(row* a, int input) //다항식에 값 입력 후 계산
{
	int num=0;
	int result=0;
	int rest = a[0].degree;
	for (int i = 0; i < a[0].degree; i++)
	{
		num = a[i].coef;
		for (int j = 0; j < a[i].degree; j++)
		{
			num = num * input;
		}
		result += num;
	}
	result += a[rest].coef; //차수0의 계수 더하기 
	printf("결과값은 %d\n", result);
}

void main()
{
	/* a,b는 다항식의 항의 개수를 입력하는 변수
*c*d*result는 각 구조체의 배열을 동적으로 전달하기 위해 포인터로 설정
c는 첫번째 다항식 d는 두번째 다항식
result는 결과 다항식
*/
	int a, b;
	row* c;
	row* c1;
	row* d;
	row* d1;
	row* result1; //덧셈 결과
	row* result2; // 곱셈 결과
	//입력 부분항의 개수
	printf("수식1의 항의 갯수?");
	scanf_s("%d", &a);
	c = (row*)(malloc((sizeof(row) * a)));
	c1 = (row*)(malloc)(sizeof(row) * (a * 2));
	sayData(c, a);
	setData(c, c1);

	printf("수식2의 항의 갯수?");
	scanf_s("%d", &b);
	d = (row*)(malloc((sizeof(row) * b)));
	d1 = (row*)(malloc)(sizeof(row) * (a * 2));
	sayData(d, b);
	setData(d, d1);

	
	result1 = (row*)(malloc(sizeof(row) * MAX_DEGREE));
	result2 = (row*)(malloc(sizeof(row) * MAX_DEGREE));
	int MAX;
	if (c[0].degree > d[0].degree)
	{
		MAX = c[0].degree;		
	}
	else
	{
		MAX = d[0].degree;
	}

	add_poly(c1, d1,result1);
	printf("식1+식2 >>>\n");
	getResult(result1, MAX);


	int max1 = c1[0].degree+1;
	int max2 = d1[0].degree+1;
	multi_poly(c1, max1, d1, max2, result2);
	regulation(result2, max1+max2);
	swapMax_Struct(result2, max1 + max2);

	printf("식1*식2>>>\n");
	getResult(result2, max1 * max2);

	
	int numsig, numnum, uinput;
	while (1)
	{
		printf("수식에 값을 넣으세요");
		scanf_s("%d %d", &numsig, &numnum);
		if (numsig == 1) uinput = c1;
		else if (numsig == 2)uinput = d1;
		else if (numsig == 3) uinput = result1;
		else if (numsig == 4) uinput = result2;
		calculate_sig(uinput, numnum);

	}
	
	
	
	//동적메모리 해제
	free(c);
	free(d);
	free(result2);
	free(result1);


}