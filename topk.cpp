#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;
struct Node {
  int value;
  int count;
};

bool compare(Node l, Node r) {
  return l.count > r.count; // min heap
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> result;
      priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq(compare);
      unordered_map<int, int> count;
      for (int i = 0 ; i < nums.size(); i++) {
        count[nums[i]] = count[nums[i]] + 1;
      }

      for (auto kv : count) {
        struct Node n = {kv.first, kv.second};
        if (pq.size() == k) {
          if (kv.second > pq.top().count) {// needs to be updated
            pq.pop();
            pq.push(n);
          }
        } else {
          pq.push(n);
        }
      }
      while (!pq.empty()){
        result.push_back(pq.top().value);
        pq.pop();
      }
      return result;
    }
};


int main() {
  Solution *s = new Solution();
  vector<int> a{2,2,3,3,3,4,4,4,4,5,12,12,12,12,12,1,1,1,1,1,1,4,3,3,15,12};
  auto result = s->topKFrequent(a, 3);
  for (auto r : result) {
    cout << r << " " << endl;
  }
}