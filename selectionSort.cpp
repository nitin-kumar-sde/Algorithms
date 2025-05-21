#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#define ll long long
#define ld long double
#define endl '\n'
#define N 1000005
#define MOD 1000000007

// Time complexity - O(n*n) - worst case, can be reduced to O(n*log(n)) using heaps
// Space complexity - O(1) - inplace
void selectionSort(int input[], int n) {
    // n-1 passes, select min from unsorted part
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        // select min among unsorted part
        for (int j = i + 1; j < n; ++j) {
            // comparision - can be custom
            if (input[j] < input[minIndex])
            minIndex = j;
        }
        swap(input[i], input[minIndex]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/sorting/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/sorting/output.txt", "w", stdout);
    #endif

    int input[6] = {8, 9, 6, 4, 1, 10};

    selectionSort(input, 6);

    for(int ele : input) {
        cout << ele << " ";
    }
    return 0;
}