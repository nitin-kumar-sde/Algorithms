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
// Space complexity - O(1) - inplace
void bubbleSort(int input[], int n) {
    int swap_count = 0;
    // n-1 passes
    for (int i = 0; i < n - 1; ++i) {
        swap_count = 0;
        // check for adjacent numbers
        for (int j = 0; j < n - i - 1; ++j) {
            // comparision - can be custom 
            if (input[j] > input[j + 1]) {
                swap(input[j], input[j + 1]);
                swap_count++;
            }
        }
        // sorted , no more passes required
        if (swap_count == 0) break; 
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
    
    bubbleSort(input, 6);

    for(int ele : input) {
        cout << ele << " ";
    }
    return 0;
}