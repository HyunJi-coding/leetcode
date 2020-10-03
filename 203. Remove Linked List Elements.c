/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* removeElements(struct ListNode* head, int val)
{
	if (!head)
		return head;

	struct ListNode* cur = head;
	struct ListNode* prev = NULL;

	while (cur != NULL)
	{

		if (cur->val == val)
		{
			if (cur == head)
			{
				struct ListNode* temp = head;

				head = head->next;

				free(temp);
				temp = NULL;

				cur = head;
			}
			else
			{
				struct ListNode* temp = cur;

				prev->next = cur->next;
				cur = cur->next;

				free(temp);
				temp = NULL;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}

	return head;
}
