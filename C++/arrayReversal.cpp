#include <iostream>
#include <algorithm>

void reverseArray(int arr[], int size) {

    /*while (start < end) {
        std::swap(arr[start], arr[end]);
        start++;
        end--;
    }*/

    for (int start = 0, end = size - 1; start < end; start++, end--) {
        std::swap(arr[start], arr[end]);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    reverseArray(arr, std::size(arr));

    for (int i = 0; i < 5; i++) {
        std::cout << *(arr + i) << " ";
    }

    return 0;
}
