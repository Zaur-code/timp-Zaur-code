#include <stdio.h>
#include <stdlib.h>

void Swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void siftDown(int Array[], int root, int bottom) {
	int maxChild;
	int done = 0;
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
		{
			maxChild = root * 2;
		}
		else if (Array[root * 2] > Array[root * 2 + 1])
		{
			maxChild = root * 2;
		}
		else
		{
			maxChild = root * 2 + 1;
		}
		if (Array[root] < Array[maxChild])
		{
			Swap(&Array[root], &Array[maxChild]);
			root = maxChild;
		}
		else
		{
			done = 1;
		}
	}
}

void heapSort(int* Array, int array_size, FILE *file) {
	for (int i = (array_size / 2) - 1; i >= 0; i--) {
		for (int j=0; j<array_size; j++)
                {
                        fprintf(file, "%d ", Array[j]);
                }
                fprintf(file, "\n");
		siftDown(Array, i, array_size - 1);
	}
	for (int i = array_size - 1; i >= 1; i--) {
		for (int j=0; j<array_size; j++)
                fprintf(file, "%d ", Array[j]);
                fprintf(file, "\n");
		Swap(&Array[0], &Array[i]);
		siftDown(Array, 0, i - 1);
	}
}

void quickSort(int *Array, int a, int b, int n, FILE *file) {
    int i;
    if (a < b)
    {
        int left = a, right = b, middle = Array[(left + right) / 2];
        do
        {
            while (Array[left] < middle) left++;
            while (Array[right] > middle) right--;
            if (left <= right)
            {
	             for (i=0; i<n; i++)
	             fprintf(file, "%d ", Array[i]);
	             fprintf(file, "\n");
	            int tmp = Array[left];
                Array[left] = Array[right];
                Array[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
	      quickSort(Array, a, right, n, file);
        quickSort(Array, left, b, n, file);
    }
}

int main ()
{
	int i, n, b;
        scanf("%d", &n);
	int *a = (int*)malloc(n*sizeof(int));
	int *c = (int*)malloc(n*sizeof(int));
        for (i=0; i<n; i++) {
                scanf("%d", &b);
                a[i]=b;
        	c[i]=b;
	}
        FILE *file;
        file = fopen("quicksort.log", "w");
quickSort(a, 0, n - 1, n, file);
 for (i = 0; i < n; i++)
 fprintf(file, "%d ", a[i]);
 fprintf(file, "\n");
fclose(file);
FILE *file2;
file2 = fopen("heapsort.log", "w");
heapSort(c, n, file2);
for (int j = 0; j < n; j++)
fprintf(file, "%d ", c[j]);
fprintf(file, "\n");
        for (i=0; i<n; i++)
                printf("%d ", c[i]);
	return 0;
}

