#include <iostream>
#include <vector>
#include <time.h>
#include <random>

using namespace std;


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
	/*for (T& item : list) {} //C++ foreach but cycling through T array? */
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

int main()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1, 1000);
	//std::vector<int> itemsV{ 1, 2, 3 };
	//for (int item : itemsV) { } // C++ foreach

	int items[10];
	for (int i = 0; i < 10; i++) {
		items[i] = dist(rng);
		/*for (int j = 0; j < 10; j++) {
			while (items[i] = items[j]) {
				items[i] = rand();
			}
		}*/
	}
	SelectionSort(items);
	for (int item : items) {
		cout << item << endl;
	}
	system("pause");
	return 0;
}