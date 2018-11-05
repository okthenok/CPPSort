#include <iostream>
#include <vector>
#include <time.h>
#include <random>

using namespace std;

/*for (T& item : list) {} //C++ foreach but cycling through T array? */

template <typename T, size_t size>
void BubbleSort(T(&list)[size]) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < size - 1; i++) {
			if (list[i] > list[i + 1]) {
				auto replace = list[i + 1];
				list[i + 1] = list[i];
				list[i] = replace;
				sorted = false;
			}
		}
	}
}

template <typename T, size_t size>
void SelectionSort(T(&list)[size]) {
	for (int i = 0; i < size; i++) {
		int least = i;
		for (int j = i; j < size; j++) {
			if (list[j] < list[least]) {
				least = j;
			}
		}
		auto temp = list[least];
		list[least] = list[i];
		list[i] = temp;
	}
}

template <typename T, size_t size>
void InsertionSort(T(&list)[size]) {
	for (int i = 0; i < size; i++) {
		for (int j = i; j > 0; j--) {
			if (list[j] < list[j - 1]) {
				auto temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
			}
		}
	}
}

template <typename T>
void MergeSort(vector<T> &list) {
	if (list.size() == 1) {
		return;
	}
	vector<T> sub1;
	vector<T> sub2;
	for (unsigned int i = 0; i < list.size() / 2; i++) {
		sub1.push_back(list[i]);
	}
	for (unsigned int i = list.size() / 2; i < list.size(); i++) {
		sub2.push_back(list[i]);
	}
	MergeSort(sub1);
	MergeSort(sub2);
	list.clear();
	Merge(sub1, sub2, list);
}

template <typename T>
void Merge(vector<T> list1, vector<T> list2, vector<T> &listOut) {
	for (unsigned int i = 0; i < list1.size(); i++) {
		listOut.push_back(list1[i]);
	}
	for (unsigned int i = 0; i < list2.size(); i++) {
		listOut.push_back(list2[i]);
	}
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (unsigned int i = 0; i < listOut.size() - 1; i++) {
			if (listOut[i] > listOut[i + 1]) {
				auto replace = listOut[i + 1];
				listOut[i + 1] = listOut[i];
				listOut[i] = replace;
				sorted = false;
			}
		}
	}
}

template <typename T>
int HoareQuick(vector<T> &list, int left, int right) {
	int pivot = left;
	while (left < right) {
		while (list[left] < list[pivot]) {
			left++;
		}
		while (list[right] > list[pivot]) {
			right--;
		}
		auto temp = list[left];
		list[left] = list[right];
		list[right] = temp;
	}
	return right;
}
template <typename T>
void HoareQuickSort(vector<T> &list, int left, int right) {
	int pivot = 0;
	if (left < right) {
		pivot = HoareQuick(list, left, right);
		HoareQuickSort(list, left, pivot);
		HoareQuickSort(list, pivot + 1, right);
	}
}

template <typename T>
int LomutoQuick(vector<T> &list, int left, int right) {
	int wall = left - 1;
	int pivot = right;
	for (int i = left; i < right; i++) {
		if (list[i] < list[pivot]) {
			auto temp = list[wall + 1];
			list[wall + 1] = list[i];
			list[i] = temp;
			wall++;
		}
	}
	auto temp = list[pivot];
	list[pivot] = list[wall + 1];
	list[wall + 1] = temp;
	return wall + 1;
}
template <typename T>
void LomutoQuickSort(vector<T> &list, int left, int right) {
	int pivot = 0;
	if (left < right) {
		pivot = LomutoQuick(list, left, right);
		LomutoQuickSort(list, left, pivot - 1);
		LomutoQuickSort(list, pivot + 1, right);
	}
}

int main()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000);
	//std::vector<int> itemsV{ 1, 2, 3 };
	//for (int item : itemsV) { } // C++ foreach

	//int items[10];
	vector<int> items;
	for (int i = 0; i < 10; i++) {
		items.push_back(dist(rng));
		/*for (int j = 0; j < 10; j++) {
			while (items[i] = items[j]) {
				items[i] = rand();
			}
		}*/
	}
	LomutoQuickSort(items, 0, items.size() - 1);
	for (int item : items) {
		cout << item << endl;
	}
	system("pause");
	return 0;
}