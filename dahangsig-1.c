#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
    
typedef struct { //다항식 구조체 타입 선언
    int degree; //다항식의 차수
    float coef[MAX_DEGREE]; //다항식의 계수
} polynomial;

typedef struct {
    float*tocoef[];
    int max;
} polypointer;

polynomial poly_add1 (polynomial A, polynomial B){
    polynomial C; //결과 다항식
    int Apos=0, Bpos=0, Cpos=0; //배열 인덱스 변수
    int degree_a=A.degree; //
    int degree_b=B.degree;
    C.degree=MAX(A.degree, B.degree); //결과 다항식 차수
    while(Apos<=A.degree && Bpos<=B.degree){ 
        if( degree_a>degree_b){//A항 차수 > B항 차수
            C.coef[Cpos++]=A.coef[Apos++]; //pos=position
            degree_a --;
            }
        else if( degree_a == degree_b){ //A와 B항 차수가 같을 때
                C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++]; //더해버렷
            }
        else{
                C.coef[Cpos++]=B.coef[Bpos++];
                degree_b --;
            }
            }
        return C;
        
    }
int main ()
{
  int a, i;
  float *arr1;
  printf ("수식 1은 몇 개의 항으로 구성되어 있나요?");
  scanf ("%d", &a);
  printf ("수식 1을 입력하세요.");
  arr1 = (float *) malloc ((2 * a) * sizeof (float));
  for (i = 0; i < (a * 2); i++)
    {
      scanf ("%f", arr1 + i);
    }
  //for (i = 0; i < (a * 2); i++)
    //{
      //printf ("%f", arr1[i]);
    //}
  //free(arr1);

  int b, j;
  float *arr2;
  printf ("수식 2는 몇 개의 항으로 구성되어 있나요?");
  scanf ("%d", &b);
  printf ("수식 2를 입력하세요.");
  arr2 = (float *) malloc ((2 * b) * sizeof (float));
  for (j = 0; j < (b * 2); j++)
    {
      scanf ("%f", arr2 + j);
    }
  //for (j = 0; j < (b * 2); j++)
    //{
      //printf ("%f", arr2[j]);
    //}

 //int k=0;

 //polynomial a1 = {arr1[1], ;
 //polynomial b2 = {arr2[1], ;
 //polynomial c;
 //c=poly_add1(a1,b2);
 //for (k = 0; k < 8; k++){
   //   printf ("%f", c.coef[k]);
    //}

 free(arr1);
 free(arr2);
}


    