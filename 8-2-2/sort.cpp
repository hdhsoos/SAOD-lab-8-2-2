#include "sort.h"
using namespace std;

bool comp(int a, int b) {
	return a ? (a > b) : b;
}

void fill_array(vector<int>& arr) {
	cout << "Введите количество элементов в массиве (не больше 10 000)" << endl;
	int n;
	cin >> n;
	for (int i{ 0 }; i < n; i++) {
		arr.push_back(rand() % 100);
	}
}

void bubble_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int i{ 0 }; i < arr.size() - 1; i++) {
		for (int j{ 0 }; j < arr.size() - i - 1; j++) {
			n_comps++;
			if (comp(arr[j], arr[j + 1])) {
				n_reeqs += 3;
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	// проверяет соседние элементы и меняет местами
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void insertion_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };
	int i, key, j;

	for (i = 1; i < arr.size(); i++) {
		n_reeqs++;
		key = arr[i];
		j = i - 1;
		n_comps++;
		while (j >= 0 && comp(arr[j], key)) {
			n_comps++;
			arr[j + 1] = arr[j];
			n_reeqs++;
			j--;
		}

		n_comps++;
		if (arr[j + 1] != key) {
			//n_comps++;
			arr[j + 1] = key;
			n_reeqs++;
		}
	}
	// один элемент сравнивает со всеми, пока тот не встанет на место
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void selection_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	for (int i{ 0 }; i < arr.size() - 1; i++) {
		int min_ind{ i };
		for (int j{ i + 1 }; j < arr.size(); j++) {
			n_comps++;
			if (arr[min_ind] > arr[j]) {
				min_ind = j;
			}
		}

		if (min_ind != i) {
			n_reeqs += 3;
			swap(arr[i], arr[min_ind]);
		}
	}
	// поиск наибольшего элемента и перемещение его в отсортированную часть списка
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void heapify(vector<int>& arr, int i, int size, int& n_comps, int& n_reeqs) {
	int largest{ i };
	int left{ 2 * i + 1 };
	int right{ 2 * i + 2 };

	n_comps++;
	if (left < size && arr[left] > arr[largest])
		largest = left;

	n_comps++;
	if (right < size && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		if (arr[largest] != arr[i]) {
			n_reeqs += 3;
			swap(arr[i], arr[largest]);
		}
		heapify(arr, largest, size, n_comps, n_reeqs);
	}
}


void quick_sort(vector<int>& arr, int start, int end, int& n_comps, int& n_assigs) {
	int pivot{ arr[(start + end) / 2] };

	int low{ start };
	int high{ end };
	while (low <= high) {
		n_comps++;
		while (arr[low] < pivot) {
			low++;
			n_comps++;
		}

		++n_comps;
		while (arr[high] > pivot) {
			high--;
			n_comps++;
		}

		if (low <= high) {
			n_comps++;
			if (arr[low] != arr[high]) {
				swap(arr[low], arr[high]);
				n_assigs += 3;
			}
			low++;
			high--;
		}
	}
	// выбор опорного элемента, разделение пополам и рекурсия пока не будет 1 или 0 элементов
	if (start < high)
		quick_sort(arr, start, high, n_comps, n_assigs);
	if (low < end)
		quick_sort(arr, low, end, n_comps, n_assigs);
}


void heap_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };

	int size = (int)arr.size();

	for (int i{ size / 2 - 1 }; i >= 0; i--) {
		heapify(arr, i, size, n_comps, n_reeqs);
	}

	for (int i{ size - 1 }; i >= 0; i--) {
		if (arr[0] != arr[i]) {
			n_reeqs += 3;
			swap(arr[0], arr[i]);
		}
		heapify(arr, 0, i, n_comps, n_reeqs);
	}
	// сначала создаем пирамиду и делаем так, чтобы наименьший элемент был на вершине. Меняем  верхний и последний элементы массива, проводим просеивание. И так пока не будет отсортировано. 
	// родитель должен быть не меньше детей
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void shell_sort(vector<int>& arr) {
	cout << "Несортированный массив: ";
	output_array(arr);
	int n_comps{ 0 };
	int n_reeqs{ 0 };
	int temp{};
	for (int gap{ (int)arr.size() }; gap > 0; gap /= 2) {
		for (int i{ gap }; i < arr.size(); ++i) {
			n_reeqs++;
			int temp{ arr[i] };
			int j{};
			n_comps++;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
				n_comps++;
				arr[j] = arr[j - gap];
				n_reeqs++;
			}
			arr[j] = temp;
			n_reeqs++;
		}
	}
	// сравнение элементов с шагом, который постепенно уменьшается (улучшение метода вставок)
	cout << "Количество сравнений: " << n_comps << endl;
	cout << "Количество переприсваиваний: " << n_reeqs << endl;
	cout << "Отсортированный массив: ";
	output_array(arr);
}

void output_array(vector<int>& arr) {
	for (int i{ 0 }; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}