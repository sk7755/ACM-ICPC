#include <stdio.h>
#include <stdlib.h>

#define size 4

typedef struct{
	unsigned int d[size];
}big_int;

big_int* generate_big_int();
void delete_big_int(big_int *a);
void init_big_int(big_int* a, int init);
void input_big_int(big_int* a);
void print_big_int(big_int *a);
void lshift_big_int(big_int *a);
void rshift_big_int(big_int *a);
void complement_big_int(big_int *a);
void assign_big_int(big_int *a, big_int *b);
void add_big_int(big_int *a, big_int *b, big_int *c);
void sub_big_int(big_int *a, big_int *b, big_int *c);
void mul_big_int(big_int *a, big_int *b, big_int *c);
int cmp_unsigned_big_int(big_int *a, big_int *b);
int cmp_signed_big_int(big_int *a, big_int *b);
void div_big_int(big_int *a, big_int *b, big_int *c);
void mod_big_int(big_int *a, big_int *b, big_int *c);

big_int* generate_big_int()
{
	int i;
	big_int *a = (big_int*)malloc(sizeof(big_int));

	for (i = 0; i < size; i++)
		a->d[i] = 0;

	return a;

}

void delete_big_int(big_int *a)
{
	free(a);
}

void init_big_int(big_int* a, int init)
{
	int sign = init & 0x80000000;
	int i;

	if (sign)
		sign = 0x77777777;
	else
		sign = 0x00000000;

	for (i = 0; i < size - 1; i++)
		a->d[i] = sign;
	a->d[i] = init;

}

void input_big_int(big_int* a)
{
	char *buffer;
	int i, j, k;
	int n = 0;
	int sign = 0;
	int carry = 0;

	buffer = (char*)malloc(sizeof(char)* 10 * size + 1);

	for (i = 0; i <= size * 10 && (buffer[i] = getchar()) != '\n' && buffer[i] != ' '; i++)		// buffer[i]에는'\n' 이 저장
		buffer[i] -= '0';

	if (buffer[0] == '-' - '0')
		sign = 1;

	k = sign;
	while (k != i)
	{
		carry = 0;
		for (j = k; j < i; j++)
		{
			buffer[j] = (carry + buffer[j]);
			if (buffer[j] % 2)
				carry = 10;
			else
				carry = 0;
			buffer[j] /= 2;
		}

		if (carry)
		{
			a->d[size - 1 - n / 32] += 0x00000001 << (n % 32);
		}
		n++;

		if (buffer[k] == 0)
			k++;
	}

	if (sign)
		complement_big_int(a);

	free(buffer);
	return;
}

void print_big_int(big_int *a)
{
	char *buffer;
	int sign = a->d[0] & 0x80000000;
	int i, j, k;
	int n = 1; //n은 숫자열 크기
	int carry;

	buffer = (char*)malloc(sizeof(char)* 10 * size + 1);

	buffer[0] = 0;

	if (sign)
	{
		printf("-");
		complement_big_int(a);
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 32; j++)
		{
			carry = 0;

			for (k = 0; k <n; k++)
			{
				buffer[k] = buffer[k] * 2 + carry;
				carry = buffer[k] / 10;
				buffer[k] = buffer[k] % 10;
			}

			if (carry)
				buffer[n++] = 1;

			if (a->d[i] & (0x80000000 >> j))
				buffer[0]++;
		}
	}

	for (i = n - 1; i >= 0; i--)
		printf("%c", buffer[i] + '0');

	if (sign)
		complement_big_int(a);

	free(buffer);
}

void lshift_big_int(big_int *a)
{
	int i;
	int carry = 0;
	int temp;

	for (i = size - 1; i >= 0; i--)
	{
		temp = carry;
		if (a->d[i] & 0x80000000)
			carry = 1;
		else
			carry = 0;

		a->d[i] = a->d[i] << 1;
		a->d[i] += temp;
	}
}

void rshift_big_int(big_int *a)
{
	int i;
	int carry = 0;
	int temp;

	for (i = 0; i <size; i++)
	{
		temp = carry;
		if (a->d[i] & 0x00000001)
			carry = 0x80000000;
		else
			carry = 0x00000000;

		a->d[i] = a->d[i] >> 1;
		a->d[i] += temp;
	}
}

void complement_big_int(big_int *a)
{
	int i, j;

	for (i = 0; i < size; i++)
		a->d[i] = ~a->d[i];

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 0; j < 32; j++)
		{
			if (a->d[i] & (0x00000001 << j))
			{
				a->d[i] = a->d[i] - (0x00000001 << j);
			}
			else
			{
				a->d[i] = a->d[i] + (0x00000001 << j);
				return;
			}

		}
	}
}

void assign_big_int(big_int *a, big_int *b)
{
	for (int i = 0; i < size; i++)
		b->d[i] = a->d[i];
}

void add_big_int(big_int *a, big_int *b, big_int *c)
{
	int i;
	int carry = 0;
	unsigned long long temp;

	for (i = size - 1; i >= 0; i--)
	{
		temp = (unsigned long long)a->d[i] + (unsigned long long)b->d[i] + carry;
		if (temp >= 0x0000000100000000)
			carry = 1;
		else
			carry = 0;
		c->d[i] = (unsigned int)temp;
	}
}

void sub_big_int(big_int *a, big_int *b, big_int *c)
{
	int i;
	unsigned long long borrow = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if ((unsigned long long)a->d[i] >= (unsigned long long)b->d[i] + borrow)
		{
			c->d[i] = a->d[i] - b->d[i] - borrow;
			borrow = 0;
		}
		else
		{
			c->d[i] = a->d[i] - b->d[i] - borrow;
			borrow = 1;
		}
	}

}

void mul_big_int(big_int *a, big_int *b, big_int *c)
{
	big_int *temp_a, *temp_b;
	int i, j, k;
	unsigned long long temp;
	unsigned long long carry;

	temp_a = generate_big_int();
	temp_b = generate_big_int();
	assign_big_int(a, temp_a);
	assign_big_int(b, temp_b);

	for (i = size - 1; i >= 0; i--)
		c->d[i] = 0;

	for (i = size - 1; i >= 0; i--)
	{
		carry = 0;

		for (j = size - 1, k = i; j >= 0 && k >= 0; j--, k--)
		{
			temp = (unsigned long long)temp_a->d[j] * (unsigned long long)temp_b->d[i] + (unsigned long long)c->d[k] + carry;
			c->d[k] = (unsigned int)temp;
			carry = temp >> 32;
		}
	}

	delete_big_int(temp_a);
	delete_big_int(temp_b);
}

int cmp_unsigned_big_int(big_int *a, big_int *b)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (a->d[i] > b->d[i])
			return 1;
		if (a->d[i] < b->d[i])
			return -1;
	}
	return 0;
}

int cmp_signed_big_int(big_int *a, big_int *b)
{
	int i;

	if (!(a->d[0] & 0x80000000) && (b->d[0] & 0x80000000))
		return 1;
	else if ((a->d[0] & 0x80000000) && !(b->d[0] & 0x80000000))
		return -1;
	else if (!(a->d[0] & 0x80000000) && !(b->d[0] & 0x80000000))
	{
		for (i = 0; i < size; i++)
		{
			if (a->d[i] > b->d[i])
				return 1;
			if (a->d[i] < b->d[i])
				return -1;
		}
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			if (a->d[i] > b->d[i])
				return -1;
			if (a->d[i] < b->d[i])
				return 1;
		}
	}

	return 0;
}

void div_big_int(big_int *a, big_int *b, big_int *c)
{
	big_int *temp_a, *temp_b;
	int a_sign = a->d[0] & 0x80000000;
	int b_sign = b->d[0] & 0x80000000;
	int i;

	temp_a = generate_big_int();
	temp_b = generate_big_int();
	assign_big_int(a, temp_a);
	assign_big_int(b, temp_b);

	for (i = size - 1; i >= 0; i--)
		c->d[i] = 0;

	if (a_sign)
		complement_big_int(temp_a);
	if (b_sign)
		complement_big_int(temp_b);

	i = 0;
	while (!(temp_b->d[0] & 0x80000000))
	{
		lshift_big_int(temp_b);
		i++;
	}

	for (; i >= 0; i--)
	{
		if (cmp_unsigned_big_int(temp_a, temp_b) >= 0)
		{
			c->d[size - 1 - i / 32] = c->d[size - 1 - i / 32] + (0x00000001 << (i % 32));
			sub_big_int(temp_a, temp_b, temp_a);
		}
		rshift_big_int(temp_b);
	}

	if (a_sign ^ b_sign)
		complement_big_int(c);

	delete_big_int(temp_a);
	delete_big_int(temp_b);
}

void mod_big_int(big_int *a, big_int *b, big_int *c)
{
	big_int *temp_a, *temp_b;
	int a_sign = a->d[0] & 0x80000000;
	int b_sign = b->d[0] & 0x80000000;
	int i;

	temp_a = generate_big_int();
	temp_b = generate_big_int();
	assign_big_int(a, temp_a);
	assign_big_int(b, temp_b);

	for (i = size - 1; i >= 0; i--)
		c->d[i] = 0;

	if (a_sign)
		complement_big_int(temp_a);
	if (b_sign)
		complement_big_int(temp_b);

	i = 0;
	while (!(temp_b->d[0] & 0x80000000))
	{
		lshift_big_int(temp_b);
		i++;
	}

	for (; i >= 0; i--)
	{
		if (cmp_unsigned_big_int(temp_a, temp_b) >= 0)
		{
			c->d[size - 1 - i / 32] = c->d[size - 1 - i / 32] + (0x00000001 << (i % 32));
			sub_big_int(temp_a, temp_b, temp_a);
		}
		rshift_big_int(temp_b);
	}

	assign_big_int(temp_a, c);

	if (a_sign)
		complement_big_int(c);

	delete_big_int(temp_a);
	delete_big_int(temp_b);
}

int main()
{
	big_int* a = generate_big_int();
	big_int* b = generate_big_int();

	input_big_int(a);
	input_big_int(b);

	add_big_int(a, b, a);
	print_big_int(a);

	return 0;
}