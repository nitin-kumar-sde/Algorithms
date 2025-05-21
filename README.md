# 📦 mystl sort – lightweight C++ sorting library

🚀 A lightweight, header-only C++ sorting library that mimics STL-style `sort()` but allows you to choose or automatically select the best sorting algorithm based on input size.


## 📚 Features

- ✅ STL-like Interface – drop-in replacement with familiar syntax.
- 🧠 Smart Algorithm Selection – auto selects the best sort algo based on input
- 💼 Custom Comparator Support
- 🎛️ Manual Algorithm Control
- 🔗 Header-only – simple and lightweight

---

## 🧰 Algorithms Implemented

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
sorting/
├── sort/
│   ├── insertion_sort.hpp
│   ├── merge_sort.hpp
│   ├── quick_sort.hpp
│   └── sort.hpp
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


