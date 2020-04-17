#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 101 

//���׽��� ��Ÿ���� ���� ����ü 
typedef struct
{
	int coef; //���
	int degree;//���� 
}row;

void setData(row* a, int count) { //������ �Է¹ް� ����ü�� �ʱ�ȭ�ϴ� �Լ�
	int i;
	printf("������ �Է��ϼ���.");
	for (i = 0; i < count; i++) {
		scanf_s("%d", &a[i].coef);
		scanf_s("%d", &a[i].degree);
	}

}



void multi_poly(row* c, int count1, row*d,int count2, row* result) //���� �Լ�
{//������ 0�� �Ͱ� ������� �ϴ� ������ ��� ���� �޴� ����
	int Rpos = 0;//result ��ġ
	for (int i = 0; i < count1; i++)
	{

		for (int j = 0; j < count2; j++)
		{
			result[Rpos].degree = c[i].degree + d[j].degree;//���׽��� ��-> �������� ���� ������� ����
			result[Rpos].coef = c[i].coef * d[j].coef;
			Rpos++;
		}

	}

	return;
}

void regulation(row* result, int count) //������ ������ ���� �������� �����ֱ� 
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
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
	row temp;//�ӽ� ����ü �ڸ� ����
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			//���� ���Ͽ� i���� j�� ũ�� swap �Լ� �����Ͽ� result ����ü ����
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

void add_poly(row* c,int count1, row* d, int count2, row* result) //���� �Լ�
{
	int Cpos = 0;
	int Dpos = 0;
	int Rpos = 0; //�� ���׽��� ��ġ�� ��Ÿ���� ������ �˻���
	while (Cpos < count1 && Dpos <= count2) {
		if ((c[Cpos].degree) == (d[Dpos].degree)) {
			result[Rpos].degree = c[Cpos].degree;
			result[Rpos].coef = (c[Cpos].degree) + (d[Dpos].degree);
			Dpos++;
		}
		else if (Dpos == (count2)-1) {
			Cpos += 1;
		}
		else Dpos++;
		
	}
	return;
}

void getResult(row* a, int num) //����� ������ 0�� ���� �����ϰ� ������ִ� ����� ��� �Լ�
{
	for (int i = 0; i <= num; i++)
	{
		if (a[i].degree == 0 && a[i].coef == 0) break;
		if (a[i].coef == 0) break;
		printf("%d %d ", a[i].coef, a[i].degree);
	}
	printf("\n");

}

void calculate_sig(row* a, int input) //���׽Ŀ� �� �Է� �� ���
{
	int num = 0;
	int result = 0;
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
	result += a[rest].coef; //����0�� ��� ���ϱ� 
	printf("������� %d\n", result);
}

void main()
{
	/* a,b�� ���׽��� ���� ������ �Է��ϴ� ����
	*c*d*result�� �� ����ü�� �迭�� �������� �����ϱ� ���� �����ͷ� ����
	c�� ù��° ���׽� d�� �ι�° ���׽�
	result�� ��� ���׽�
	*/
	int a, b;
	row* c;
	row* d;
	row* result1; //���� ���
	row* result2; // ���� ���
	//�Է� �κ����� ����
	printf("���� 1�� �� ���� ������ �����Ǿ� �ֳ���?");
	scanf_s("%d", &a);
	c = (row*)(malloc((sizeof(row) * a)));
	setData(c, a);

	printf("���� 2�� �� ���� ������ �����Ǿ� �ֳ���?");
	scanf_s("%d", &b);
	d = (row*)(malloc((sizeof(row) * b)));
	setData(d, b);


	result1 = (row*)(malloc(sizeof(row) * MAX_DEGREE));
	result2 = (row*)(malloc(sizeof(row) * MAX_DEGREE));
	int MAX;
	if (c[0].degree > d[0].degree) MAX = c[0].degree;
	else MAX = d[0].degree;

	add_poly(c,a,d,b, result1);
	printf("���� 1 + 2��\n");
	getResult(result1, MAX);


	int max1 = c[0].degree + 1;
	int max2 = d[0].degree + 1;
	multi_poly(c,a,d,b, result2);
	regulation(result2, max1 * max2);
	swapMax_Struct(result2, max1 * max2);

	printf("���� 1 * 2��\n");
	getResult(result2, max1 * max2);


	int numsig, numnum;
	row* uinput;
	uinput = (row*)(malloc(sizeof(row) * MAX_DEGREE));
	while (1)
	{
		printf("���Ŀ� ���� ��������");
		scanf_s("%d %d", &numsig, &numnum);
		if (numsig == 1) uinput = c;
		else if (numsig == 2)uinput = d;
		else if (numsig == 3) uinput = result1;
		else if (numsig == 4) uinput = result2;
		calculate_sig(uinput, numnum);

	}



	//�����޸� ����
	free(c);
	free(d);
	free(result2);
	free(result1);

	return;
}

