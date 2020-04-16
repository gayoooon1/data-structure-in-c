#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int coef; //
	int degree;
} row;

void sayData(row* a, int count) {
	int i;
	printf("수식을 입력하세요.");
	for (i = 0; i < count; i++) {
		scanf_s("%d", &a[i].coef);
		scanf_s("%d", &a[i].degree);
	}

}



void setData(row* a, row* a1) {
	int i;
	int j;
	int index = a[0].degree;
	int num = 0;
	for (i = 0; i < a[0].degree; i++) { //0,1,2,3
		for (j = a[0].degree; j > -1; j--) { //3,2,1,0
			a1[i].degree = j;
			if (j==index){
				if (a[num].degree == a1[i].degree) {
					a1[i].coef = a[num].coef;
					num++;
					printf("%d", a1[i].coef);
					printf("%d", a1[i].degree);
				}
				else {
					a1[i].coef = 0;
					printf("%d", a1[i].coef);
					printf("%d", a1[i].degree);
				}
				index--;
			}
		}
	}
	//가윤이언니 보여? 아아앙~? 

}
int main() {
	int a;
	row* c;
	row* c1;
	//c = (row*)(malloc)(sizeof(row)*a);
	//c1 = (row*)(malloc)(sizeof(row)*(a * 2));
	printf("항의 개수?");
	scanf_s("%d", &a);
	c = (row*)(malloc)(sizeof(row) * a);
	c1 = (row*)(malloc)(sizeof(row) * (a * 2));
	sayData(c, a);
	setData(c, c1);

	free(c);
	free(c1);
}