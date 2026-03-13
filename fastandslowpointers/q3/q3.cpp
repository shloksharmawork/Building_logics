// ===================== BRUTE FORCE =====================
// Time: O(N)   Space: O(N)
// Using a hash set to track visited nodes. First repeated node is cycle start.

// ===================== BETTER =====================
// Time: O(??)   Space: O(??)
// ...

// ===================== OPTIMAL =====================
// Time: O(N)   Space: O(1)
// Floyd's Cycle Detection Algorithm

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
