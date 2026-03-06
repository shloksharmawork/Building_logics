/*
 * ============================================================
 *  Problem    : 209. Minimum Size Subarray Sum
 *  Platform   : LeetCode
 *  Difficulty : Medium
 *  Date       : 2026-03-06
 *  Topic      : Sliding Window
 *  Link       : https://leetcode.com/problems/minimum-size-subarray-sum/
 * ============================================================
 *
 *  Given an array of positive integers nums and a positive integer
 *  target, return the minimal length of a subarray whose sum is
 *  greater than or equal to target. If there is no such subarray,
 *  return 0 instead.
 *
 *  Example 1:
 *    Input : target = 7, nums = [2,3,1,2,4,3]
 *    Output: 2   (subarray [4,3])
 *
 *  Example 2:
 *    Input : target = 4, nums = [1,4,4]
 *    Output: 1
 *
 *  Example 3:
 *    Input : target = 11, nums = [1,1,1,1,1,1,1,1]
 *    Output: 0
 * ============================================================
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

// ============================================================
//  APPROACH 1 — BRUTE FORCE
//  Idea  : Try every possible subarray and track the minimum
//          length whose sum >= target.
//  Time  : O(n^2)
//  Space : O(1)
// ============================================================
int bruteForce(int target, vector<int> &nums) {
  int n = nums.size();
  int res = INT_MAX;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += nums[j];
      if (sum >= target) {
        res = min(res, j - i + 1);
        break; // can't get shorter by extending further
      }
    }
  }

  return (res == INT_MAX) ? 0 : res;
}

// ============================================================
//  APPROACH 2 — OPTIMAL  (Sliding Window / Hire-and-Fire)
//  Idea  : Maintain a variable-size window [low, high].
//          Expand by moving high; once sum >= target, shrink
//          from the left (move low) to find the minimum window.
//  Time  : O(n)  — each element is added/removed at most once
//  Space : O(1)
// ============================================================
int optimal(int target, vector<int> &nums) {
  int n = nums.size();
  int low = 0, high = 0;
  int sum = 0;
  int res = INT_MAX;

  while (high < n) {
    sum += nums[high];

    while (sum >= target) {
      int len = high - low + 1;
      res = min(len, res);
      sum -= nums[low];
      low++;
    }

    high++;
  }

  return (res == INT_MAX) ? 0 : res;
}

// ============================================================
//  DRIVER / TEST
// ============================================================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Test cases
  vector<pair<int, vector<int>>> tests = {
      {7, {2, 3, 1, 2, 4, 3}},       // Expected: 2
      {4, {1, 4, 4}},                // Expected: 1
      {11, {1, 1, 1, 1, 1, 1, 1, 1}} // Expected: 0
  };

  cout << "--- Brute Force ---\n";
  for (auto &[target, nums] : tests) {
    cout << "Target=" << target << " -> " << bruteForce(target, nums) << "\n";
  }

  cout << "--- Optimal (Sliding Window) ---\n";
  for (auto &[target, nums] : tests) {
    cout << "Target=" << target << " -> " << optimal(target, nums) << "\n";
  }

  return 0;
}
