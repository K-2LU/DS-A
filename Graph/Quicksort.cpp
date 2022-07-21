#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)	{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int data[], int low, int high)	{
	int piv = data[high];
	int i = low - 1;
	
	for(int j = low; j < high; j++)	{
		if(data[j] <= piv)	{
			i++;
			swap(&data[i], &data[j]);
		}
	}
	
	swap(&data[i+1], &data[high]);
	
	return i+1;
}

void quickSort(int data[], int low, int high)	{
	if(low < high)	{
		int pi = partition(data, low, high);
		
		quickSort(data, low, pi - 1);
		quickSort(data, pi + 1, high);
	}
}

void printArray(int data[], int n)	{
	for(int i = 0; i < n; i++)	
		cout << data[i] << ' ';
	cout << endl;
}

int main()	{
	int data[] = {8, 7, 6, 1, 0, 5, 2, 4, 3};
	int n = sizeof(data)/sizeof(data[0]);
	
	quickSort(data, 0, n-1);
	printArray(data, n);
}