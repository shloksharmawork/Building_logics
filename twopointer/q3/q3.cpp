/*
 * ============================================================
 *  SOLUTION TEMPLATE — Daily DSA Grind
 *  Platform   : LeetCode
 *  Difficulty : Medium
 *  Date       : 2026-03-04
 *  Topic      : Two Pointer, Array, Sorting
 *  Link       : https://leetcode.com/problems/sort-colors/
 *  Question   : 75. Sort Colors
 * ============================================================
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ============================================================
//  APPROACH 1 — BRUTE FORCE (Counting Sort)
//  Idea   : Count occurrences of 0s, 1s, and 2s,
//           then overwrite the array in order.
//  Time   : O(N)   — two passes
//  Space  : O(1)
// ============================================================
void bruteForce(vector<int> &nums) {
  int count0 = 0, count1 = 0, count2 = 0;
  for (int x : nums) {
    if (x == 0)
      count0++;
    else if (x == 1)
      count1++;
    else
      count2++;
  }
  int i = 0;
  while (count0--)
    nums[i++] = 0;
  while (count1--)
    nums[i++] = 1;
  while (count2--)
    nums[i++] = 2;
}

// ============================================================
//  APPROACH 2 — OPTIMAL (Dutch National Flag — one pass)
//  Idea   : Maintain three pointers: low, mid, high.
//           - Everything before low is 0
//           - Everything between low and mid is 1
//           - Everything after high is 2
//           Walk mid from start to high, swapping as needed.
//  Time   : O(N)   — single pass
//  Space  : O(1)
// ============================================================
void optimal(vector<int> &nums) {
  int n = nums.size();
  int low = 0, mid = 0, high = n - 1;

  while (mid <= high) {
    if (nums[mid] == 0) {
      swap(nums[mid], nums[low]);
      low++;
      mid++;
    } else if (nums[mid] == 2) {
      swap(nums[mid], nums[high]);
      high--;
      // don't increment mid — newly swapped element not yet inspected
    } else {
      mid++;
    }
  }
}

// Helper to print a vector
void printVec(const string &label, const vector<int> &v) {
  cout << label << ": [";
  for (int i = 0; i < (int)v.size(); i++) {
    cout << v[i] << (i + 1 < (int)v.size() ? "," : "");
  }
  cout << "]\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Test cases
  vector<int> t1a = {2, 0, 2, 1, 1, 0};
  vector<int> t1b = {2, 0, 2, 1, 1, 0};
  vector<int> t2a = {2, 0, 1};
  vector<int> t2b = {2, 0, 1};
  vector<int> t3a = {0};
  vector<int> t3b = {0};

  cout << "--- Brute Force (Counting Sort) ---\n";
  bruteForce(t1a);
  printVec("Test1", t1a);
  bruteForce(t2a);
  printVec("Test2", t2a);
  bruteForce(t3a);
  printVec("Test3", t3a);

  cout << "\n--- Optimal (Dutch National Flag) ---\n";
  optimal(t1b);
  printVec("Test1", t1b);
  optimal(t2b);
  printVec("Test2", t2b);
  optimal(t3b);
  printVec("Test3", t3b);

  return 0;
}
