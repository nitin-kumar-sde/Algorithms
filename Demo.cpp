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
#include "algo/algo.hpp"

using namespace std;
using namespace mystl;

struct Person {
    std::string name;
    int age;
};

bool comp1(Person const& a, Person const& b) {
    return a.age < b.age;
}

bool comp2(Person const& a, Person const& b) {
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

    vector<int> nums = { 5, 2, 9, 1, 5, 6 };

    // Sort: ascending
    sort(nums.begin(), nums.end());
    mystl::for_each(nums.begin(), nums.end(), [](int x) { cout << x << " "; });
    cout << "\n";

    // Reverse
    mystl::reverse(nums.begin(), nums.end());
    mystl::for_each(nums.begin(), nums.end(), [](int x) { cout << x << " "; });
    cout << "\n";

    // Accumulate
    int sum = accumulate(nums.begin(), nums.end(), 0);
    cout << "Sum = " << sum << "\n";

    // Count
    int count_5 = mystl::count(nums.begin(), nums.end(), 5);
    cout << "Count of 5 = " << count_5 << "\n";

    // Find
    auto it = mystl::find(nums.begin(), nums.end(), 9);
    if (it != nums.end()) cout << "Found 9\n";

    // all_of, any_of, none_of
    cout << "All positive? " << mystl::all_of(nums.begin(), nums.end(), [](int x) { return x > 0; }) << "\n";
    cout << "Any even? " << mystl::any_of(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; }) << "\n";
    cout << "None negative? " << mystl::none_of(nums.begin(), nums.end(), [](int x) { return x < 0; }) << "\n";

    // Max / Min
    cout << "Max = " << *mystl::max_element(nums.begin(), nums.end()) << "\n";
    cout << "Min = " << *mystl::min_element(nums.begin(), nums.end()) << "\n";

    // for_each to increment all
    mystl::for_each(nums.begin(), nums.end(), [](int& x) { x++; });
    for (int x : nums) cout << x << ' ';
    cout << "\n";

    // Custom datatype: Person
    vector<Person> people = {
        {"Alice", 30}, {"Bob", 25}, {"Carol", 30}, {"Dave", 20}
    };

    // Sort by age
    sort(people.begin(), people.end(), comp1);
    mystl::for_each(people.begin(), people.end(), [](const Person& p) {
        cout << p.name << " (" << p.age << ")\n";
    });

    // Sort by name descending
    sort(people.begin(), people.end(), comp2);
    mystl::for_each(people.begin(), people.end(), [](const Person& p) {
        cout << p.name << " (" << p.age << ")\n";
    });

    // max_element with Person
    auto oldest = mystl::max_element(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.age < b.age;
    });
    cout << "Oldest: " << oldest->name << " (" << oldest->age << ")\n";

    // count_if example
    int over25 = mystl::count_if(people.begin(), people.end(), [](const Person& p) {
        return p.age > 25;
    });
    cout << "People older than 25: " << over25 << "\n";

    return 0;
}
