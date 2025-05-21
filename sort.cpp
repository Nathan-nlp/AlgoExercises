#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Sentinel Partition Function for Quick Sort */
int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[left];
    int i = left, j = right;
    while (i < j) {
        while (i < j && nums[j] >= pivot) j--;
        while (i < j && nums[i] <= pivot) i++;
        if (i < j) swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);
    return i;
}

/* Selection Sort */
void selectionSort(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k])
                k = j;
        }
        swap(nums[i], nums[k]);
    }
}

/* Bubble Sort */
void bubbleSort(vector<int> &nums) {
    for (int i = nums.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

/* Insertion Sort */
void insertionSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        int base = nums[i], j = i - 1;
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = base;
    }
}

/* Quick Sort */
void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right)
        return;
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

/* Print Vector */
void printVector(const vector<int> &nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

/* Main Function */
int main() {
    vector<int> nums;

    cout << "Please enter an integer: ";
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.get() == '\n') break;
    }

    vector<int> a = nums, b = nums, c = nums, d = nums;

    cout << "\nOriginal array: ";
    printVector(nums);

    selectionSort(a);
    cout << "Selection sort: ";
    printVector(a);

    bubbleSort(b);
    cout << "Bubble sort: ";
    printVector(b);

    insertionSort(c);
    cout << "Insertion sort: ";
    printVector(c);

    quickSort(d, 0, d.size() - 1);
    cout << "Quick sort: ";
    printVector(d);

    return 0;
}

