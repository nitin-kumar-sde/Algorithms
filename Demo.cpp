#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <fstream>
#include "sort/sort.hpp"
using namespace std;
using namespace mystl;

struct Person {
    std::string name;
    int age;
};

bool comp1(Person const& a, Person const& b){
    return a.age < b.age; 
}

bool comp2(Person const& a, Person const& b){
    return a.name > b.name;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
        freopen("/Users/nitinkumar/Desktop/sorting/input.txt", "r", stdin);
        freopen("/Users/nitinkumar/Desktop/sorting/output.txt", "w", stdout);
    #endif

    // Example 1: sort ints ascending (default comparator)
    vector<int> nums = { 5, 2, 9, 1, 5, 6 };
    sort(nums.begin(), nums.end());

    for (int x : nums) std::cout << x << ' ';
    cout << "\n";

    // Example 2: sort Person by age ascending
    vector<Person> people = {
        {"Alice", 30}, {"Bob", 25}, {"Carol", 30}, {"Dave", 20}
    };
    sort(people.begin(),people.end(), comp1);

    for (auto const& p : people) {
        cout << p.name << " (" << p.age << ")\n";
    }

    // Example 3: sort Person by name descending
    sort(people.begin(), people.end(),comp2);
   
    for (auto const& p : people) {
        cout << p.name << " (" << p.age << ")\n";
    }

    return 0;
}
