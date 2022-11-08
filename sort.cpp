#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//#1
// Write a function (in C++) that prints the values of an array in ascending order 
// order on the console and use it with an example array, e.g.
//    int values[10] = {5,4,3,2,1,1,2,3,4,5}; // expected output: 1 1 2 2 3 3 4 4 5 5
// Assume a clean C++ environment with STL but no other libraries

// Quick Sort implementation:
// on average O(nlogn)
// worst case O(n^2)
class QuickSort {
  public:
    void sort(vector<int>& num) {
      return sortInternal(num, 0, num.size()-1);
    }

  private:
    void sortInternal(vector<int>& nums, int l, int r) {
      if (r <= l) {
        return;
      }

      int pivot = nums.at(r); // making the right most element our pivot
      int pivotIndex = l; // finding the right most element 
      
      for (int i = l; i < r; ++i) {
        if (nums.at(i) < pivot) {
          swap(nums.at(i), nums.at(pivotIndex));
          pivotIndex++;
        }
      }
      swap(nums.at(pivotIndex), nums.at(r));

      sortInternal(nums, l, pivotIndex-1);
      sortInternal(nums, pivotIndex+1, r);
    }
};

int main() {
    vector<int> num{1,2,6,7,9,8,5,3,4,0};
    QuickSort *qs = new QuickSort();
    qs->sort(num);
    vector<int>::iterator i;
    for (i = num.begin(); i != num.end(); i++) {
      cout << *i << " "; 
    }
    return 0;
}


