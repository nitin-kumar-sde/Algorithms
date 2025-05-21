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

void heapify(int arr[], int n, int i) {
    int largest = i;         
    int left    = 2*i + 1; 
    int right   = 2*i + 2;

    // If left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child exists and is greater than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Time Complexity - O(nlogn) - worst case
// Space Complexity - O(n) - mergeSort.cpp - inplace 
void heapSort(int input[], int n) {

    for (int i = n/2 - 1; i >= 0; --i)
        heapify(input, n, i);

    for (int end = n - 1; end > 0; --end) {
        swap(input[0], input[end]);
        heapify(input, end, 0);
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
    
    heapSort(input, 6);

    for(int ele : input) {
        cout << ele << " ";
    }

    return 0;
}