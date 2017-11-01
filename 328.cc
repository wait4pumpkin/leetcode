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
	ListNode* oddEvenList(ListNode* head) {
		if (!head || !head->next) return head;

		ListNode *odd = head, *even = head->next, *evenHead = head->next;

		auto n = 1;
		auto p = head->next->next;
		while (p) {
			auto& list = n++ % 2 ? odd : even;
			list->next = p;

			list = list->next;
			p = p->next;
		}
		even->next = nullptr;
		odd->next = evenHead;
		return head;
	}
};