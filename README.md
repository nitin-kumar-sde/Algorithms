# 📦 mystl Algorithms – lightweight C++ Algorithms library

🚀 A lightweight, header-only C++ algorithm library that mimics STL-style `sort()` , `accumulate` , `reverse` and other important algorithms.

---

## 📚 Features

### Sort 
- ✅ STL-like Interface – drop-in replacement with familiar syntax.
- 🧠 Smart Algorithm Selection – auto selects the best sort algo based on input
- 💼 Custom Comparator Support
- 🎛️ Manual Algorithm Control
- 🔗 Header-only – simple and lightweight

---

### 🧰 Algorithms Implemented

| Algorithm       | Class             | Best Use Case              |
|-----------------|-------------------|-----------------------------|
| 📌 Insertion     | `InsertionSorter` | Tiny datasets (`n < 16`)    |
| ⚡ Quick         | `QuickSorter`     | General-purpose, fast       |
| 🧵 Merge         | `MergeSorter`     | Stable sort, large datasets |

---

## 🛠 Usage

First, clone the repo to your local machine:

```
git clone https://github.com/nitin-kumar-sde/sorting.git
cd sorting

```

```
algorithms/
├── sort/
│   └── sort.hpp
├── accumulate/
│   └── accumulate.hpp
├── count/
│   └── count.hpp
├── find/
│   └── find.hpp
├── for_each/
│   └── for_each.hpp
├── max_min/
│   └── max_min_element.hpp
├── reverse/
│   └── reverse.hpp
├── algo/
│   └── algos.hpp   <-- include this to get all utilities
├── demo.cpp
└── README.md


```

import header file in your main file 

```
#include "sort/sort.hpp"

```

use mystl namespace

```
using namespace mystl;

```

---

## ✅ Auto Algorithm Selection

```
// Automatically picks best sort
std::vector<int> nums = {5, 3, 9, 1};
sort(nums.begin(), nums.end());

```
---

## 🧠 With Custom Comparator
```
sort(nums.begin(), nums.end(), std::greater<int>());  // Descending

```
---

🎛️ Manual Algorithm Selection

```
sort(nums.begin(), nums.end(), Algorithm::Merge); // Force merge sort
sort(nums.begin(), nums.end(), Algorithm::Quick, std::greater<int>()); // Quick sort descending
```

---

## 🔍 How Auto Selection Works

When you use
```
sort(begin, end);
```
The following decision is made internally based on input size n:

| `n` Range       | Algorithm Used    |
| --------------- | ----------------- |
| `n < 16`        | 📌 Insertion Sort |
| `16 ≤ n < 1000` | ⚡ Quick Sort      |
| `n ≥ 1000`      | 🧵 Merge Sort     |


---

## ➕ Accumulate

```
#include "algo/algo.hpp"

....

std::vector<int> v = {1, 2, 3};
int sum = mystl::accumulate(v.begin(), v.end(), 0); 

// Custom operation
int prod = accumulate(v.begin(), v.end(), 1, [](int a, int b) { return a * b; });

```

---

## 🔄 Reverse

```
#include "algo/algo.hpp"

reverse(v.begin(), v.end());

```

---

## 🔍 Find and Find If

```
#include "algo/algo.hpp"

auto it = find(v.begin(), v.end(), 5);
auto it2 = find_if(v.begin(), v.end(), [](int x){ return x > 3; });

```
---

## 🔢 Count and Count If

```
#include "algo/algo.hpp"

...

int cnt = count(v.begin(), v.end(), 2);
int even = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
```
---

## ✅ all_of, any_of, none_of

```
#include "algo/algo.hpp"

...

bool allPos = all_of(v.begin(), v.end(), [](int x){ return x > 0; });
bool hasZero = any_of(v.begin(), v.end(), [](int x){ return x == 0; });
bool noneNeg = none_of(v.begin(), v.end(), [](int x){ return x < 0; });
```
---

## 🧲 Min Element & Max Element

```
#include "algo/algo.hpp"

...

auto minIt = min_element(v.begin(), v.end());
auto maxIt = max_element(v.begin(), v.end());
```

---

## ♻️ For Each

```
#include "algo/algo.hpp"

...

for_each(v.begin(), v.end(), [](int& x){ x++; });
```

---

## 🔨 Requirements

- Compiler with C++14 support or higher
- No external dependencies
- Works on any platform

---

## 🤝 Contributions

You're welcome to contribute! Ideas for contribution:

- ✨ Add more algorithms (e.g., HeapSort, TimSort)
- 📈 Add performance benchmarks
- 📘 Improve documentation
- 🧪 Add unit tests


