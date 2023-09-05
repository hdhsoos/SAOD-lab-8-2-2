#pragma once
#include <iostream>
#include <ctime>
#include <vector>

void menu();
void fill_array(std::vector<int>& arr);
void bubble_sort(std::vector<int>& arr);
void insertion_sort(std::vector<int>& arr);
void selection_sort(std::vector<int>& arr);
void output_array(std::vector<int>& arr);
// void quick_sort(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs);
// int partition(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs);
void shell_sort(std::vector<int>& arr);
void heap_sort(std::vector<int>& arr);
void quick_sort(std::vector<int>& arr, int start, int end, int& n_comps, int& n_reeqs);