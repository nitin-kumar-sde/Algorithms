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

// Time complexity - O(n*n) - worst case - O(n) - best case
// Space complexity - O(1) - inplace sorting 
void insertionSort(int input[], int n) {
        // treat left part as sorted 
        for (int i = 1; i < n; ++i) {
            int key = input[i];
            int j = i - 1;
            // insert key at its right place
            while (j >= 0 && input[j] > key) {
                input[j + 1] = input[j];
                --j;
            }
            input[j + 1] = key;
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

    insertionSort(input, 6);

    for(int ele : input) {
        cout << ele << " ";
    }

    return 0;
}