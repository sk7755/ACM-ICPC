#include <cstdio>
#include <cstring>

using namespace std;

int myComp(char *a, char *b);
void mySort(char* arr[], int start, int end);

int main()
{
	int n;
	char str[20000][51];
	char* arr[20000];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
		arr[i] = str[i];
	}

	mySort(arr, 0, n - 1);

	printf("%s\n", arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (strcmp(arr[i - 1], arr[i]))
			printf("%s\n", arr[i]);
	}
}

int myComp(char* a, char* b)
{
	int len_a = strlen(a);
	int len_b = strlen(b);

	if (len_a > len_b)
		return 1;
	else if (len_a < len_b)
		return -1;
	else
		return strcmp(a, b);
}

char* temp_arr[20000];

void mySort(char* arr[], int start, int end)
{
	if (start == end)
		return;

	int mid = (start + end) / 2;

	mySort(arr, start, mid);
	mySort(arr, mid + 1, end);
	
	int i = start, j = mid + 1;

	int k = start;
	while (i <= mid && j <= end)
	{
		int temp = myComp(arr[i], arr[j]);

		if (temp <0)
		{
			temp_arr[k++] = arr[i++];
		}
		else if (temp > 0)
		{
			temp_arr[k++] = arr[j++];
		}
		else
		{
			temp_arr[k++] = arr[i++];
			temp_arr[k++] = arr[j++];
		}
	}

	while (i <= mid)
		temp_arr[k++] = arr[i++];
	while (j <= end)
		temp_arr[k++] = arr[j++];

	for (int i = start; i <= end; i++)
		arr[i] = temp_arr[i];

	return;
}