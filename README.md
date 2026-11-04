# Data Structures & Algorithms in C++

Implementations of classic data structures and algorithms in C++, each with a small
console driver.

| Topic | Folder | What is implemented |
|-------|--------|---------------------|
| Sorting | [`sorting/randomized-quicksort-select`](sorting/randomized-quicksort-select) | Merge sort, Quicksort with randomized partition, Randomized-Select (i-th order statistic) |
| Sorting | [`sorting/linear-time-sorts`](sorting/linear-time-sorts) | Counting sort, Radix sort (plus Merge/Quick sort for comparison) |
| Trees | [`trees`](trees) | Binary tree with traversals; binary search tree |
| Heap | [`heap`](heap) | Max/Min-heap, heap sort, priority queue (insert / extract / increase-key); see its README, THEORY and TESTS |
| Graphs | [`mst/kruskal`](mst/kruskal), [`mst/prim`](mst/prim) | Minimum spanning tree: Kruskal (with Disjoint Set Union) and Prim; see [`mst/README.md`](mst/README.md) |
| Hash tables | [`hash-tables/chaining`](hash-tables/chaining) | Division / multiplication hashing, collision resolution by chaining |
| Hash tables | [`hash-tables/open-addressing`](hash-tables/open-addressing) | Open addressing: linear, quadratic and double hashing |

## Build

Each subfolder is self-contained. Use whichever build file it contains:

```bash
# Makefile projects: heap, trees, mst/kruskal, mst/prim
cd heap && make

# CMake projects: sorting/*, hash-tables/*
cd sorting/linear-time-sorts
cmake -S . -B build && cmake --build build
```

Requires a C++11 (Makefile projects) or C++20 (CMake projects) compiler.

## Notes

The program prompts and comments are in Ukrainian, since this was written as university coursework
(Data Structures and Algorithms).
