/*
 * ============================================================
 *  Problem    : 977. Squares of a Sorted Array
 *  Platform   : LeetCode
 *  Difficulty : Easy
 *  Date       : 2026-03-01
 *  Topic      : Two Pointer
 *  Link       : https://leetcode.com/problems/squares-of-a-sorted-array/
 * ============================================================
 *
 *  Given an integer array nums sorted in non-decreasing order,
 *  return an array of the squares of each number sorted in
 *  non-decreasing order.
 *
 *  Example 1:
 *    Input : nums = [-4,-1,0,3,10]
 *    Output: [0,1,9,16,100]
 *
 *  Example 2:
 *    Input : nums = [-7,-3,2,3,11]
 *    Output: [4,9,9,49,121]
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

// ============================================================
//  APPROACH 1 — BRUTE FORCE
//  Idea  : Square every element, then sort the result array.
//  Time  : O(n log n)  — O(n) to square + O(n log n) to sort
//  Space : O(n)        — result array
// ============================================================
vector<int> bruteForce(vector<int>& nums) {
    vector<int> arr;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        arr.push_back(nums[i] * nums[i]);
    }
    sort(arr.begin(), arr.end());
    return arr;
}

// ============================================================
//  APPROACH 2 — OPTIMAL  (Two Pointer)
//  Idea  : The largest squares must come from either the
//          leftmost or rightmost element (the most negative
//          or most positive). Use two pointers i (left) and
//          j (right), compare their squares and fill the
//          result array from the back.
//  Time  : O(n)   — single pass
//  Space : O(n)   — result array only
// ============================================================
vector<int> optimal(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    int k = n - 1;                  // fill result from the back
    vector<int> res(n);

    while (i <= j) {
        int leftsq  = nums[i] * nums[i];
        int rightsq = nums[j] * nums[j];

        if (leftsq > rightsq) {
            res[k--] = leftsq;
            i++;
        } else {
            res[k--] = rightsq;
            j--;
        }
    }
    return res;
}

// ============================================================
//  DRIVER / TEST
// ============================================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums1 = {-4, -1, 0, 3, 10};
    vector<int> nums2 = {-7, -3, 2, 3, 11};

    auto print = [](const string& label, vector<int>& v) {
        cout << label << ": [";
        for (int i = 0; i < (int)v.size(); i++)
            cout << v[i] << (i + 1 < (int)v.size() ? "," : "");
        cout << "]\n";
    };

    // Brute Force
    auto r1 = bruteForce(nums1);
    auto r2 = bruteForce(nums2);
    cout << "--- Brute Force ---\n";
    print("Test1", r1);   // Expected: [0,1,9,16,100]
    print("Test2", r2);   // Expected: [4,9,9,49,121]

    // Optimal
    auto r3 = optimal(nums1);
    auto r4 = optimal(nums2);
    cout << "--- Optimal ---\n";
    print("Test1", r3);   // Expected: [0,1,9,16,100]
    print("Test2", r4);   // Expected: [4,9,9,49,121]

    return 0;
}
