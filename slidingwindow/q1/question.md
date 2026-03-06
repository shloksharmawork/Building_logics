# Q1 — 209. Minimum Size Subarray Sum

**Platform**: LeetCode  
**Difficulty**: Medium  
**Date**: 2026-03-06  
**Topic**: Sliding Window  
**Link**: https://leetcode.com/problems/minimum-size-subarray-sum/

---

## 📋 Problem Statement

Given an array of positive integers `nums` and a positive integer `target`, return the **minimal length** of a subarray whose sum is **greater than or equal to** `target`. If there is no such subarray, return `0` instead.

**Example 1:**
- Input: `target = 7, nums = [2,3,1,2,4,3]`
- Output: `2`
- Explanation: The subarray `[4,3]` has the minimal length under the problem constraint.

**Example 2:**
- Input: `target = 4, nums = [1,4,4]`
- Output: `1`

**Example 3:**
- Input: `target = 11, nums = [1,1,1,1,1,1,1,1]`
- Output: `0`

**Constraints:**
- `1 <= target <= 10^9`
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`

---

## ⏱️ Complexity Summary

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n²) | O(1) | Check all subarrays |
| Optimal (Sliding Window) | O(n) | O(1) | Hire and fire / shrink window |

---

## 💡 Key Insight

Use a **sliding window** (two pointers `low` and `high`):
- Expand the window by moving `high` forward and adding `nums[high]` to the sum.
- While `sum >= target`, record the window length and shrink from the left by moving `low` forward.
- This guarantees every element is visited at most twice — O(n) overall.

---

## 📊 Results

- Optimal (Sliding Window): Accepted ✅ — Runtime 0ms (beats **100%** 🔥)
