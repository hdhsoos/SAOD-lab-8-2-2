#include "sort.h"
#include "sort.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	menu();
}

void menu() {
	vector<int> arr;
	int choice, qsort_n_comps{ 0 }, qsort_n_reeqs{ 0 };
	unsigned int start_time, end_time;
	fill_array(arr);
	while (true) {
		cout << "Выберите пункт меню:" << endl;
		cout << "0 - выйти из программы" << endl;
		cout << "1 - пузырьковая сортировка" << endl;
		cout << "2 - сортировка вставками" << endl;
		cout << "3 - сортировка выбором" << endl;
		cout << "4 - заполнить массив новыми значениями" << endl;
		cout << "5 - быстрая сортировка" << endl;
		cout << "6 - сортировка Шелла" << endl;
		cout << "7 - пирамидальная сортировка" << endl;
		vector<int> arr1 = arr;
		cin >> choice;
		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			bubble_sort(arr1);
			arr1.clear();
			break;
		case 2:
			insertion_sort(arr1);
			arr1.clear();
			break;
		case 3:
			selection_sort(arr1);
			arr1.clear();
			break;
		case 4:
			arr.clear();
			fill_array(arr);
			break;
		case 5:
			quick_sort(arr1, 0, arr.size() - 1, qsort_n_comps, qsort_n_reeqs);
			cout << "Несортированный массив: ";
			output_array(arr);
			cout << "Количество сравнений: " << qsort_n_comps << endl;
			cout << "Количество переприсваиваний: " << qsort_n_reeqs << endl;
			cout << "Отсортированный массив: ";
			output_array(arr1);
			arr1.clear();
			break;

		case 6:
			shell_sort(arr1);
			break;

		case 7:
			heap_sort(arr1);
			break;
		}
	}
}
