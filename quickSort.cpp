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

// Time complexity - O(n*n) - worst case - O(n*logn) - average case
// Space complexity - O(n) - auxiliary stack space
int partitionArray(int input[], int start, int end) {
	// randomise pivot selection to avoid worst case
    int randomIndex = start + std::rand() % (end - start + 1);
    swap(input[start], input[randomIndex]);

    int startingIndex = start;
    int count = 0;

	for(int i = start+1;i<=end;i++) {
		if(input[i] < input[startingIndex]) count++;
	}
    
	int pivotIndex = start + count;
    swap(input[startingIndex], input[pivotIndex]);
	int i=start, j=end;

	while(i<j) {

		if(input[i] < input[pivotIndex]) i++;
		
		else if (input[j] >= input[pivotIndex]) j--;

		else {
        swap(input[i++], input[j--]);
		}
	}
	return pivotIndex;
}


void quickSort(int input[], int start, int end) {

	if(start>= end) return;
    
	//partition around pivot element
	int pivotIndex = partitionArray(input, start, end);
	
	quickSort(input, start, pivotIndex-1);
	quickSort(input, pivotIndex +1, end);
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

    quickSort(input, 0,5);

    for(int ele : input) {
        cout << ele << " ";
    }

    return 0;
}