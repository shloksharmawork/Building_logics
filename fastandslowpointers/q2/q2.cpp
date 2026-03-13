// ===================== BRUTE FORCE =====================
// Time: O(??)   Space: O(??)
// Using a HashSet to keep track of seen sums.

// ===================== BETTER =====================
// Time: O(??)   Space: O(??)
// ...

// ===================== OPTIMAL =====================
// Time: O(log N) Space: O(1)
// Floyd's Tortoise and Hare Cycle Detection

class Solution {
public:
  int sum(int n) {
    int sum0 = 0;
    while (n > 0) {
      int d = n % 10;
      n = n / 10;
      sum0 = sum0 + (d * d);
    }
    return sum0;
  }
  bool isHappy(int n) {
    auto slow = n;
    auto fast = n;
    while (fast != 1) {
      slow = sum(slow);
      fast = sum(sum(fast));
      if (slow == fast && slow != 1) {
        return false;
      }
    }
    return true;
  }
};
