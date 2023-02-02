// 포인터와 배열

// 배열 이름 = 포인터
// 일반 매개변수 : 매개 변수에 기억장소가 할당
// 배열 매개변수 : 배열 매개 변수에 기억 장소 할당X

// 평균과 표준편차 구하기
/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DATA 10

void Data(double data[]);
double Mean(double data[]);
double Std_dev(double data[], double mean);

int main()
{
	double data[10];
	double mean, std_dev;

	srand((unsigned)time(NULL));
	Data(data);
	mean = Mean(data);
	std_dev = Std_dev(data, mean);

	printf("평균 값 : %lf, 표준편차 : %lf\n", mean, std_dev);
}

void Data(double data[])
{
	int i;
	for (i = 0; i < DATA; i++)
	{
		data[i] = rand() % 100;
	}
}

double Mean(double data[])
{
	int i;
	double sum = 0;
	for (i = 0; i < DATA; i++)
	{
		sum += data[i];
	}
	return sum / DATA;
}

double Std_dev(double data[], double mean)
{
	int i;
	double sum = 0;
	for (i = 0; i < DATA; i++)
	{
		sum += pow(data[i] - mean, 2);
	}
	return sqrt(sum / DATA);
}
*/

// 함수 포인터
// 1) 함수 자체를 다른 함수의 인자로 넘겨주기 위해 사용
// 2) 여러 개의 함수를 배열로 관리하고자 할 때 사용

// 함수 포인터 예제 1
/*
#include <stdio.h>

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	int num1, num2;
	int (*pf) (int, int); // 함수 포인터

	scanf_s("%d %d", &num1, &num2);

	pf = min;
	printf("더 작은 수 : %d\n", pf(num1, num2));

	return 0;
}
*/

// 함수 포인터 예제 1
/*
#include <stdio.h>
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

int main()
{
	int (*fp[4])(int, int);

	fp[0] = add;
	fp[1] = sub;
	fp[2] = mul;
	fp[3] = div;

	for (int i = 0; i < 4; i++)
	{
		printf("배열[%d] 함수 실행 값 : %d\n", i, fp[i](20, 10));
	}

	return 0;
}
*/

// 문자열과 포인터

// 배열 문자열은 각 자리 값 변경 가능, 포인터 문자열은 변경 X


// 포인터와 배열 예제 코드 1
/*
#include <stdio.h>

void update_array1(int x[])
{
	x[0] = 99;
}

void updata_array2(int* x)
{
	*(x + 1) = 99;
} // 포인터를 전달받아 두번째 원소 값 수정

int main()
{
	int a[] = { 10,20,30,40,50 };
	update_array1(a);
	printf("a[0] = %d, a[1] = %d, a[2] = %d\n", a[0], a[1], a[2]);

	int b[] = { 100,200,300,400,500 };
	update_array2(b);
	printf("b[0] = %d, b[1] = %d, b[2] = %d\n", b[0], b[1], b[2]);
}
*/

// 포인터와 배열 예제 코드 2
/*
#include <stdio.h>

int mul(int x[], int n) // int *x (매개변수로 배열 대신 포인터)
{
	int i, mul = 1;

	for (i = 0; i < 5; i++)
	{
		// mul *= x[i];

		if(*(x+i)%2==1)
			mul *= x[i]; // 홀수의 곱 반환
	}

	return mul;
}

int main()
{
	int data[] = { 1,2,3,4,5 };
	int value;

	value = mul(data, 5);
	printf("%d\n",value);
}
*/

// 함수 포인터 예제 코드
/*
#include <stdio.h>

int annyeong() { printf("안녕!\n"); }
int hello() { printf("Hello!\n"); }
int bonjour() { printf("Bonjour!\n"); }

int main()
{
	int (*fp[3])();

	// 함수 포인터와 함수의 연결
	fp[0] = annyeong;
	fp[1] = hello;
	fp[2] = bonjour;

	for (int i = 0; i < 3; i++)
	{
		fp[i]();
	}
}
*/

// 문자열 예제 : 암호 강인성 검사
/*
#include <stdio.h>

int main()
{
	char password[30];

	while (1)
	{
		printf("암호 생성 : ");
		scanf_s(" %s", password); // 배열 이름에 입력받을 때 & 사용X

		int is_upper;
		int is_lower;
		int is_digit;

		is_upper = is_lower = is_digit = 0;
		for (int i = 0; i < strlen(password); i++)
		{
			if (password[i] >= '0' && password[i] <= '9')
				is_digit = 1;
			else if (password[i] >= 'A' && password[i] <= 'Z')
				is_upper = 1;
			else if (password[i] >= 'a' && password[i] <= 'z')
				is_lower = 1;
		}

		if ((is_digit == 1) && (is_upper == 1) && (is_lower == 1))
		{
			printf("적정한 암호\n");
			break;
		}
		else
		{
			printf("숫자, 대문자, 소문자를 섞어서 암호를 다시 만드세요.\n");
		}

	}
}
*/