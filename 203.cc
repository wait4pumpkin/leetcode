/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *last = nullptr, *p = head;
		while (p) {
			if (p->val == val) {
				if (last) {
					last->next = p->next;
				} else {
					head = p->next;
				}
			} else {
				last = p;
			}
			p = p->next;
		}
		return head;
	}
};