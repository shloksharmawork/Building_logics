/*
 * ============================================================
 *  Problem    : 904. Fruit Into Baskets
 *  Platform   : LeetCode
 *  Difficulty : Medium
 *  Date       : 2026-03-06
 *  Topic      : Sliding Window
 *  Link       : https://leetcode.com/problems/fruit-into-baskets/
 * ============================================================
 *
 *  You are visiting a farm that has a single row of fruit trees
 *  arranged from left to right. The trees are represented by an
 *  integer array fruits where fruits[i] is the type of fruit the
 *  ith tree produces.
 *
 *  You want to collect as much fruit as possible. However, the
 *  owner has some strict rules that you must follow:
 *  - You have two baskets, each basket can only hold a single type of fruit.
 *  - You must pick exactly one fruit from every tree while moving right.
 *  - Once you reach a tree with fruit that cannot fit, you must stop.
 *
 *  Return the maximum number of fruits you can pick.
 *
 *  Example 1:
 *    Input : fruits = [1,2,1]
 *    Output: 3
 *
 *  Example 2:
 *    Input : fruits = [0,1,2,2]
 *    Output: 3
 *
 *  Example 3:
 *    Input : fruits = [1,2,3,2,2]
 *    Output: 4
 * ============================================================
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ============================================================
//  APPROACH — OPTIMAL (Sliding Window)
//  Idea  : Find the longest subarray with at most 2 distinct elements.
//  Time  : O(n)
//  Space : O(1) (Map stores at most 3 entries)
// ============================================================
int totalFruit(vector<int> &fruits) {
  int n = fruits.size();
  int low = 0;
  int res = 0;
  unordered_map<int, int> mpp;

  for (int high = 0; high < n; high++) {
    mpp[fruits[high]]++;

    while (mpp.size() > 2) {
      mpp[fruits[low]]--;
      if (mpp[fruits[low]] == 0) {
        mpp.erase(fruits[low]);
      }
      low++;
    }

    res = max(res, high - low + 1);
  }

  return res;
}

// ============================================================
//  DRIVER / TEST
// ============================================================
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<pair<string, vector<int>>> tests = {{"[1,2,1]", {1, 2, 1}},
                                             {"[0,1,2,2]", {0, 1, 2, 2}},
                                             {"[1,2,3,2,2]", {1, 2, 3, 2, 2}}};

  cout << "--- Optimal (Sliding Window) ---\n";
  for (auto &test : tests) {
    string label = test.first;
    vector<int> fruits = test.second;
    cout << "Fruits=" << label << " -> " << totalFruit(fruits) << "\n";
  }

  return 0;
}
