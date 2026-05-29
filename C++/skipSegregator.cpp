/* This is a program with a specific example: Consider that for a song, 1 means that a user listened to it till the end,
and 0 means that the user skipped the song, no matter how much the duration. Given is a sample array in which a random assortment
of these users are shown for an example song. We need the assortment as such:

All the zeroes should be at the start, and all the ones should be at the end.

This program shows how exactly it is done. */

#include <algorithm>
#include <iostream>
#include <vector>

void segregateSkips(std::vector<int>& vec) {
    int start = 0, end = vec.size() - 1;
    while (start < end) {
        if (vec[start] == 0) { start++; }
        else if (vec[end] == 1) { end--; }
        else if (vec[start] == 1 && vec[end] == 0) {
            std::swap(vec[start], vec[end]);
            start++;
            end--;
        }
    }
}

void print(std::vector<int>& vec) {
    for (int value: vec) {
        std::cout << value << " ";
    }
    std::cout << "\n\n"; // Refusing to use endl due to force in flush buffer, \n is simply faster.
}

int main() {
    std::vector<int> sample = {1, 0, 1, 1, 0, 0, 1};
    segregateSkips(sample);
    print(sample);

    return 0;
}
