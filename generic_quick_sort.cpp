// generic quicksort.cpp : Defines the entry point for the console application.
//
#include"stdafx.h"

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(void *arr, int a, int b,int size){
	void *temp = malloc(4);
	memcpy(temp, (char*)((char*)arr + b), size);
	memcpy((char*)((char*)arr + b), (char*)((char*)arr + a), size);
	memcpy((char*)((char*)arr + a), (char*)temp, size);

}

int cmp(void *a, void *b){
	int at = *(int*)a;
	int bt = *(int*)b;
	return (at)-(bt);
}

int partition(void *arr, int low, int high, int(*comparator)(void*, void*),int size)
{

	void *pivot = (void*)((char*)arr + high * size);
	int index = low - 1;
	for (int i = low; i<high; i++){
		if (comparator((void*)((char*)arr + i * size), pivot) <= 0){
			index++;
			swap(arr, index * size, i * size,size);
		}

	}
	swap(arr, (index + 1) * size, high * size,size);
	return index + 1;
}

void sort(void *arr, int low, int high, int(*comparator)(void*, void*),int size){
	if (low < high){
		int index = partition(arr, low, high, comparator,size);
		sort(arr, low, index - 1, comparator,size);
		sort(arr, index + 1, high, comparator,size);
	}
}

void qqsort(void *arr, int n, int size, int(*comparator)(void*, void*)){
	sort(arr, 0, n, comparator,size);
}

int main()
{
	int a[] = { 1, 11, 4, 9, 10, 2, 0,7, 3, 1 };
	int n = 10;
	printf("got into main\n");
	for (int i = 0; i<10; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
	qqsort((void*)a, n-1,sizeof(int), &cmp);
	for (int i = 0; i<10; i++){
		printf("%d\t", a[i]);
	}
	getchar();
}

