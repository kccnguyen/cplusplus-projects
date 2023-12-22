// Binary Search

#include<iostream>

using namespace std;

template<typename T>

int binary_search(T arr[], int n, T x) {
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

template<typename T>

void PrintArray(T arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n\n";
}

int main() {

    int arr[] = { 1, 13, 19, 22, 30, 32, 40, 50, 62, 82, 96 ,100 };
    int n = sizeof(arr) / sizeof(int);

    cout << "Array : " << endl;
    PrintArray(arr, n);

    int x, index;
    cout << "Enter a number you want to search: ";
    cin >> x;

    index = binary_search(arr, n, x);

    if (index == -1)
        cout << x << " is not in the array." << endl;
    else
        cout << x << " is in the array at the position " << index << endl;

}