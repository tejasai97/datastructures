// mergesort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class sort
{
private:
	int *a;
public:
	int size;
	void merge(int low, int high, int mid);
	void mergesort(int low,int high);
	void input();
	void output();
};
void sort::merge(int low, int high, int mid) {
	int i, j, k, *c;
	c = new int[size];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++, i++;
		}
		else
		{
			c[k] = a[j];
			k++, j++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++, i++;
	}
	while (j <= high)
	{
		c[k] = a[j];
		k++, j++;
	}
	for (i = low; i < k; i++)
	{
		a[i] = c[i];
	}
}
void sort::mergesort(int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, high, mid);
	}
	return;
}
void sort::input() {
	cout << "enter the size of the array" << endl;
	cin >> size;
	a = new int[size];
	for (int i = 0; i < size; i++)
		cin >> a[i];
}
void sort::output()
{
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
}
int main()
{
	sort test;
	test.input();
	test.mergesort(0, test.size-1);
	cout << "sorted array:" << endl;
	test.output();
    return 0;
}

