#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/801/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int peak_index = 0;
      if (nums.size() < 2) {
        return peak_index;
      }

      for (int i = 1; i < nums.size(); ++i) {
        if (nums[peak_index] <= nums[i]) {
          peak_index = i;
        } else {
          break;
        }
      }

      return peak_index;      
    }
};

int main() {
  vector<int> num{1,2,6,7,9,8,5,3,4,0};
  Solution *s = new Solution();
  cout << s->findPeakElement(num) << endl;
}