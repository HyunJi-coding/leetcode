/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode *iterA = headA, *iterB = headB;
	while (iterA || iterB)
	{
		if (iterA == iterB)
			return iterA;

		iterA = iterA ? iterA->next : headB;
		iterB = iterB ? iterB->next : headA;
	}

	return iterA;
}