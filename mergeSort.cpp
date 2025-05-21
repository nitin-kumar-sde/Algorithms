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

// Time complexity - O(nlogn)
// Space complexity - O(2*n) - temp array + auxiliary stack space
void mergeSort(int input[], int l, int r) {
    
    if(r<=l) return;
    
    int mid = (l + r)/2;

    mergeSort(input, l, mid);

    mergeSort(input, mid+1, r);

    int * temp = new int [r-l+1];
    int count = 0;
    int i=l, j=mid+1;
    
    // merge sorted arrays
    while(i<=mid && j<=r) {
        if(input[i] < input[j]) {
            temp[count++] = input[i++];
        }
        else  temp[count++] = input[j++];
    }

    while(i<=mid) {
        temp[count++] = input[i++];
    }
    
    while( j<=r) {
        temp[count++] = input[j++];
    }

    for(int i=0;i<r-l+1;i++) {
        input[i+l] = temp[i];
    }

    delete [] temp;
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

    mergeSort(input, 0,5);

    for(int ele : input) {
        cout << ele << " ";
    }

    return 0;
}