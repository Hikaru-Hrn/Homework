#include <iostream>
#include <math.h>
#include <stdlib.h>     // подключаем qsort (поможет отсортировать нам масив block)
#include <algorithm>
using namespace std;

int comp1(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}
//Функция для сортировки по возрастанию

bool next_perm(int* first, int* last)
{
	if (first == last) return false;
	int* i = first;
	++i;
	if (i == last) return false;
	i = last;
	--i;

	for (;;)
	{
		int* ii = i--;
		if (*i < *ii)
		{
			int* j = last;
			while (!(*i < *--j));
			iter_swap(i, j);
			reverse(ii, last);
			return true;
		}
		if (i == first)
		{
			reverse(first, last);
			return false;
		}
	}
}




void ShowArray(const int* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
} 
//Фукция для вывода массива на экран

void push_back(int*& arr, int& size, int value){
	int* newArray = new int[size+1];
	for (int i = 0; i < size; i++) {
		newArray[i] = arr[i];
	}
	newArray[size] = value;
	size++;
	delete[] arr;
	arr = newArray;
}
//Функция для добавления элемента в конец масива

void push_block(int*& arr, int*& block, int& size, int& block_size, int k) {
	for (int i = 0; i < size; i++) {
		push_back(block, block_size, abs(k - arr[i]));
	}
}
//Функция для добавления растояния между всеми элементами в масив block



bool Check_1(int*& arr, int*& block, int& size, int& block_size, int k) {
	for (int i = 0; i < block_size; i++) {
		if (block[i] == k)
			return false;

	}
	return true;
}
//Функция, проверяющая находиться ли число "k" в block

bool Check_2(int*& arr, int*& block, int& size, int& block_size, int k) {
	for (int i = 0; i < size; i++) {
		for (int n = 0; n < block_size; n++) {
			if (k - arr[i] == block[n]) {
				return false;
			}
		}
	}
	return true;
}
//Функция, которая проверит, можно ли ставить число вправо

bool Check_3(int*& block, int& block_size) {
	qsort(block, block_size, sizeof(int), comp1);
	for (int i = 0; i < block_size; i++) {
		if (i + 1 >= block_size) {
			break;
		}
		if (block[i] - block[i + 1] != -1)
			return false;
	}
	return true;
}
//Функция, проверяющая все растояния между футболистами, и если обнаружиться пропуск одного числа, то возвращает false

int main()
{
	setlocale(LC_ALL, "Russian");
	int cin_size;
	cin >> cin_size;
	int size = 1;
	int* ar = new int[cin_size]; //Вспомогательная функция
	for (int i = 0; i < cin_size; ++i)
		ar[i] = i + 1;


	int* arr = new int[size] {0}; //В массив arr мы вносим координаты ответа, т.е. координаты футболистов
	int block_size = 0; //В массив block мы вносим растояние между ВСЕМИ элементами, находящиеся в arr
	int* block = new int[block_size];


	do
	{
		for (int i = 0; i < cin_size; ++i) {
			int* arr = new int[size] {0};
			if (Check_1(arr, block, size, block_size, arr[i] + ar[i]) == false)
				continue;
			if (Check_2(arr, block, size, block_size, arr[i] + ar[i]) == false) {
				continue;

			}
			else {
				push_block(arr, block, size, block_size, arr[i] + ar[i]); //Добавляет растояние между к и всеми остальными футболистами
				push_back(arr, size, arr[i] + ar[i]); //И только затем добавляет положительное к
			}
			ShowArray(arr, size);
			cout << endl;
			delete[] arr;
		}
	} while (next_perm(ar, ar + cin_size));


}
	//for (int i = 1; size < cin_size; i++) { //Чем больше максимальное число k, тем точнее будет ответ (на 1 милионе мой норм ноут считал ответ 5 минут)
	//	//Далее идет проверка, ставить нам вообще число к, и если ставить то вправо, или влево
	//	if (Check_1(arr, block,size, block_size, arr[k-1]+k) == false)
	//		continue;
	//	if (Check_2(arr, block, size, block_size, arr[k-1]+k) == false) {
	//		continue;

	//	}
	//	else {
	//		push_block(arr, block, size, block_size, arr[k - 1] + k); //Добавляет растояние между к и всеми остальными футболистами
	//		push_back(arr, size, arr[k - 1] + k); //И только затем добавляет положительное к
	//	}
	//	}




	//cout << "Ответ: " << endl;
	//ShowArray(arr, size); //Выводит ответ на экран
	//cout << endl << endl;

	//Check_3(block, block_size);
	//qsort(block, block_size, sizeof(int), comp1); //Сортирует block для проверки ответа на точность
	//cout << "Все растояния между футболистами" << endl;
	//ShowArray(block, block_size); // Выводит на экран block

	//delete[] arr;
	//return 0;
	//}
//Проблема состоит в том, что чем дальше мы идем, тем менее точнее ответ, но с этим мы ничего не поделаем лол



