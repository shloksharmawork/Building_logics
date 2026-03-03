/*
 * ============================================================
 *  SOLUTION TEMPLATE — Daily DSA Grind
 *  Platform : LeetCode
 *  Difficulty : Medium
 *  Date : 2026-03-03
 *  Topic : Two Pointer, Sorting, Array
 *  Link : https://leetcode.com/problems/3sum/
 *  Question : 15. 3Sum
 * ============================================================
 */

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// ============================================================
//  APPROACH 1 — BRUTE FORCE
//  Idea   : 3 nested loops to check every possible triplet.
//           Use a set to avoid duplicates.
//  Time   : O(N^3 log(M))
//  Space  : O(M) where M is unique triplets
// ============================================================
vector<vector<int>> bruteForce(vector<int> &nums) {
  int n = nums.size();
  set<vector<int>> st;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          vector<int> temp = {nums[i], nums[j], nums[k]};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }
  vector<vector<int>> res(st.begin(), st.end());
  return res;
}

// ============================================================
//  APPROACH 2 — OPTIMAL
//  Idea   : Sort the array first. Fix one number nums[i],
//           then use standard Two Pointer approach (left, right)
//           for the remaining part of the array to find target -nums[i].
//           Skip adjacent duplicates to avoid duplicate triplets.
//  Time   : O(N^2)
//  Space  : O(1) (ignoring output representation)
// ============================================================
vector<vector<int>> optimal(vector<int> &nums) {
  int n = nums.size();
  sort(nums.begin(), nums.end());
  vector<vector<int>> res;

  for (int i = 0; i < n - 2; i++) {
    // Skip duplicate for 'i' element
    if (i > 0 && nums[i] == nums[i - 1])
      continue;

    int left = i + 1;
    int right = n - 1;
    int target = -nums[i];

    while (left < right) {
      int current_sum = nums[left] + nums[right];
      if (current_sum == target) {
        res.push_back({nums[i], nums[left], nums[right]});
        left++;
        right--;

        // Skip duplicates for left pointer
        while (left < right && nums[left] == nums[left - 1]) {
          left++;
        }
        // Skip duplicates for right pointer
        while (left < right && nums[right] == nums[right + 1]) {
          right--;
        }
      } else if (current_sum < target) {
        left++;
      } else {
        right--;
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Test cases
  vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
  vector<int> nums2 = {0, 1, 1};
  vector<int> nums3 = {0, 0, 0};

  auto print = [](const string &label, const vector<vector<int>> &v) {
    cout << label << ": [";
    for (int i = 0; i < (int)v.size(); i++) {
      cout << "[";
      for (int j = 0; j < (int)v[i].size(); j++) {
        cout << v[i][j] << (j + 1 < (int)v[i].size() ? "," : "");
      }
      cout << "]" << (i + 1 < (int)v.size() ? "," : "");
    }
    cout << "]\n";
  };

  cout << "--- Brute Force ---\n";
  auto r1_brute = bruteForce(nums1);
  print("Test1", r1_brute);
  auto r2_brute = bruteForce(nums2);
  print("Test2", r2_brute);
  auto r3_brute = bruteForce(nums3);
  print("Test3", r3_brute);

  cout << "\n--- Optimal ---\n";
  auto r1_opt = optimal(nums1);
  print("Test1", r1_opt);
  auto r2_opt = optimal(nums2);
  print("Test2", r2_opt);
  auto r3_opt = optimal(nums3);
  print("Test3", r3_opt);

  return 0;
}
