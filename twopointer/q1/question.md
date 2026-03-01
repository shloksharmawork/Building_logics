# Q1 — 977. Squares of a Sorted Array

**Platform**: LeetCode  
**Difficulty**: Easy  
**Date**: 2026-03-01  
**Topic**: Two Pointer  
**Link**: https://leetcode.com/problems/squares-of-a-sorted-array/

---

## 📋 Problem Statement

Given an integer array `nums` sorted in **non-decreasing order**, return an array of the **squares of each number** sorted in non-decreasing order.

**Example 1:**
- Input: `nums = [-4,-1,0,3,10]`
- Output: `[0,1,9,16,100]`

**Example 2:**
- Input: `nums = [-7,-3,2,3,11]`
- Output: `[4,9,9,49,121]`

---

## ⏱️ Complexity Summary

| Approach | Time | Space | Notes |
|----------|------|-------|-------|
| Brute Force | O(n log n) | O(n) | Square all + sort |
| Optimal (Two Pointer) | O(n) | O(n) | Two pointers, fill from back |

---

## 💡 Key Insight

The array is already sorted, so the **largest squares** must come from either the **leftmost** (most negative) or **rightmost** (most positive) end.

Use two pointers `i = 0` and `j = n-1`, compare their squares, place the larger at the back of the result array, and move that pointer inward.

---

## 📊 Results

- Brute Force: Accepted ✅ — Runtime 11ms (beats 17%)
- Optimal: Accepted ✅ — Runtime 0ms (beats **100%** 🔥)
