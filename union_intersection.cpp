// union_intersection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class union_merge {
private:
	int size1, size2,size3,size4, *array1, *array2, *unions, *intersection;
public:
	int search(int array[], int size, int searchKey) {

		for (int i = 0; i<size; i++) {
			if (searchKey == array[i]) {
				return i;
			}
		}
		return -1;
	}
	void unionc()
	{
		int temp = 0,k;
		int *tempa;
		tempa = new int[size1 + size2];
		for (int i = 0; i < size1; i++)
		{
			if (search(array2, size2, array1[i]) == -1)
			{
				tempa[temp] = array1[i];
				temp = temp + 1;
			}
		}
		k = temp;
		for (int i = 0; i < size2; i++)
		{
			tempa[k + i] = array2[i];
			temp = temp + 1;
		}
		size3 = temp;
		unions = new int[temp];
		for (int i = 0; i < temp; i++)
		{
			unions[i] = tempa[i];
		}
		delete []tempa;
	}
	void intersectionc()
	{
		int temp=0, *tempa;
		if (size1 > size2)
		{
			tempa = new int[size1];
			for (int i = 0; i < size1; i++)
			{
				if (search(array2, size2, array1[i]) != -1)
				{
					tempa[temp] = array1[i];
					temp = temp + 1;
				}
			}
		}
		else
		{
			tempa = new int[size2];
			for (int i = 0; i < size2; i++)
			{
				if (search(array1, size1, array2[i]) != -1)
				{
					tempa[temp] = array2[i];
					temp = temp + 1;
				}
			}
		}
		intersection = new int[temp];
		for (int i = 0; i < temp; i++)
		{
			intersection[i] = tempa[i];
		}
		delete[]tempa;
		size4 = temp;
	}
	void input()
	{
		cout << "enter the sizes of arrays" << endl;
		cin >>size1>>size2;
		array1 = new int[size1];
		array2 = new int[size2];
		cout << "enter the elements of array1" << endl;
		for (int i = 0; i < size1; i++) {
			cin >> array1[i];
		}
		cout << "enter the elements of array2" << endl;
		for (int i = 0; i < size2; i++)
			cin >> array2[i];
	}
	void output()
	{
		cout << "union:" << endl;
		for (int i = 0; i < size3; i++)
			cout<< unions[i] << endl;
		cout << "intersection" << endl;
		for(int i = 0; i < size4; i++)
			cout << intersection[i] << endl;
	}
};

int main()
{
	union_merge test;
	test.input();
	test.unionc();
	test.intersectionc();
	test.output();
    return 0;
}

