#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void Sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
	cout << " The code is written by MESUM ABBAS CT-238" << endl;
    int N;
    cin >> N;
    
    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    vector<int> numbers_copy = numbers;
    
    clock_t start_time, end_time;
    
    start_time = clock();
    Sort(numbers);
    end_time = clock();
    double custom_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    start_time = clock();
    sort(numbers_copy.begin(), numbers_copy.end());
    end_time = clock();
    double stl_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    cout << "Sorted numbers: ";
    for (int i = 0; i < N; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
    
    cout << "Time taken by custom sort: " << custom_sort_time << " seconds" << endl;
    cout << "Time taken by STL sort: " << stl_sort_time << " seconds" << endl;
    
    return 0;
}
