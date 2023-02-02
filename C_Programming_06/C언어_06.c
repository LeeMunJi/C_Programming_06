// �����Ϳ� �迭

// �迭 �̸� = ������
// �Ϲ� �Ű����� : �Ű� ������ �����Ұ� �Ҵ�
// �迭 �Ű����� : �迭 �Ű� ������ ��� ��� �Ҵ�X

// ��հ� ǥ������ ���ϱ�
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

	printf("��� �� : %lf, ǥ������ : %lf\n", mean, std_dev);
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

// �Լ� ������
// 1) �Լ� ��ü�� �ٸ� �Լ��� ���ڷ� �Ѱ��ֱ� ���� ���
// 2) ���� ���� �Լ��� �迭�� �����ϰ��� �� �� ���

// �Լ� ������ ���� 1
/*
#include <stdio.h>

int min(int x, int y)
{
	return x < y ? x : y;
}

int main()
{
	int num1, num2;
	int (*pf) (int, int); // �Լ� ������

	scanf_s("%d %d", &num1, &num2);

	pf = min;
	printf("�� ���� �� : %d\n", pf(num1, num2));

	return 0;
}
*/

// �Լ� ������ ���� 1
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
		printf("�迭[%d] �Լ� ���� �� : %d\n", i, fp[i](20, 10));
	}

	return 0;
}
*/

// ���ڿ��� ������

// �迭 ���ڿ��� �� �ڸ� �� ���� ����, ������ ���ڿ��� ���� X


// �����Ϳ� �迭 ���� �ڵ� 1
/*
#include <stdio.h>

void update_array1(int x[])
{
	x[0] = 99;
}

void updata_array2(int* x)
{
	*(x + 1) = 99;
} // �����͸� ���޹޾� �ι�° ���� �� ����

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

// �����Ϳ� �迭 ���� �ڵ� 2
/*
#include <stdio.h>

int mul(int x[], int n) // int *x (�Ű������� �迭 ��� ������)
{
	int i, mul = 1;

	for (i = 0; i < 5; i++)
	{
		// mul *= x[i];

		if(*(x+i)%2==1)
			mul *= x[i]; // Ȧ���� �� ��ȯ
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

// �Լ� ������ ���� �ڵ�
/*
#include <stdio.h>

int annyeong() { printf("�ȳ�!\n"); }
int hello() { printf("Hello!\n"); }
int bonjour() { printf("Bonjour!\n"); }

int main()
{
	int (*fp[3])();

	// �Լ� �����Ϳ� �Լ��� ����
	fp[0] = annyeong;
	fp[1] = hello;
	fp[2] = bonjour;

	for (int i = 0; i < 3; i++)
	{
		fp[i]();
	}
}
*/

// ���ڿ� ���� : ��ȣ ���μ� �˻�
/*
#include <stdio.h>

int main()
{
	char password[30];

	while (1)
	{
		printf("��ȣ ���� : ");
		scanf_s(" %s", password); // �迭 �̸��� �Է¹��� �� & ���X

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
			printf("������ ��ȣ\n");
			break;
		}
		else
		{
			printf("����, �빮��, �ҹ��ڸ� ��� ��ȣ�� �ٽ� ���弼��.\n");
		}

	}
}
*/