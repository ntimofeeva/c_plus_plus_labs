#include <iostream>

using namespace std;

int FindMin(int array[], int size) {
    int minbeforelast = 999999, min = 999999;
    for (int i = 0; i < size; ++i) {
        if (array[i] < min) {
            minbeforelast = min;
            min = array[i];
        }
    }
    cout << minbeforelast << " " << min << endl;
    return min, minbeforelast;
}

int* FindMinUsingPointers(int* start, int* last) {

    int* min = last;
    int* minbeforelast;
    for (int* i = start; i <= last; i++)
        if (*i < *min) {
            minbeforelast = min;
            min = i;
        }
    cout << *minbeforelast << " " << *min << endl;
    return min;
}

void Swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void Sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                Swap(&arr[j], &arr[j + 1]);
}

void FindMissing(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        if ((arr[i] + 1 != arr[i + 1] && i != n - 1) || (arr[i + 1] - 1 != arr[i] && i != n - 1)) {
            cout << arr[i] + 1 << endl;
        }
    }
}

int main() {

    const int N = 6;
    int minbeforelast;
    int array[N] = { 1,3,5,0,4,666 };
    cout << endl;

    Sort(array, N);

    int min = FindMin(array, N);
    int* start = array;
    int* last = &array[N - 1];
    FindMinUsingPointers(start, last);



    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }

    int array1[N] = { 4,5,7,9,10,11 };
    FindMissing(array1, N);
    return 0;
}