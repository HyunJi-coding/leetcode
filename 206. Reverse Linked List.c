/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
		return;
	struct ListNode *current = head;
	int count = 1;

	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}

	int *temp = (int *)malloc(sizeof(int)*count);
	current = head;
	temp[0] = current->val;
	for (int i = 1; current->next != NULL; i++) {
		current = current->next;
		temp[i] = current->val;

	}

	current = head;
	current->val = temp[count - 1];
	while (current->next != NULL)
	{
		current = current->next;
		count--;
		current->val = temp[count - 1];

	}


	return head;
}
