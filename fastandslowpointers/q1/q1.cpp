#include <vector>

using namespace std;

// ===================== BRUTE FORCE =====================
// Time: O(N log N)   Space: O(1)
// Sorting the array and finding the adjacent duplicate.

// ===================== BETTER =====================
// Time: O(N)   Space: O(N)
// Using a hash set to keep track of seen elements.

// ===================== OPTIMAL =====================
// Time: O(N)   Space: O(1)
// Floyd's Tortoise and Hare (Cycle Detection)

class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    auto slow = 0;
    auto fast = 0;
    while (true) {
      slow = nums[slow];
      fast = nums[fast];
      fast = nums[fast];
      if (slow == fast) {
        slow = 0;
        while (slow != fast) {
          slow = nums[slow];
          fast = nums[fast];
        }
        return slow;
      }
    }
    return -1;
  }
};
