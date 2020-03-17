#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* mergeTwoLists (struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *temp, *finHead, *fin;
	
	if (!l1)
		return l2;
	else if (!l2)
		return l1;

	if (l1->val > l2->val) {
		finHead = fin = l2;
		l2 = l2->next;
	}
	else {
		finHead = fin = l1;
		l1 = l1->next;
	}

	while (1) {
		if (!l1) {
			fin->next = l2;
			break;
		}
		else if (!l2) {
			fin->next = l1;
			break;
		}
		
		if (l1->val < l2->val) {
			fin->next = l1;
			l1 = l1->next;
		}
		else {
			fin->next = l2;
			l2 = l2->next;
		}
		
		fin = fin->next;
	}

	return finHead;
}