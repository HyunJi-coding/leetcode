/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* oddEvenList(struct ListNode* head) {
	struct ListNode *temp = head, *temp1, *temp2;
	int n = 0, s;
	while (temp != NULL)
	{
		temp = temp->next;
		n++;
	}
	s = n / 2;
	if (head == NULL || n == 1 || n == 2)
	{
		return head;
	}
	temp = head;
	temp1 = temp->next;
	temp2 = temp1;
	if (n % 2 == 0)
	{
		while (s - 1 != 0)
		{
			temp->next = temp1->next;
			temp1->next = temp1->next->next;
			temp->next->next = temp2;
			temp = temp->next;
			temp1 = temp1->next;
			s--;
		}
	}
	else
	{
		while (s != 0)
		{
			temp->next = temp1->next;
			temp1->next = temp1->next->next;
			temp->next->next = temp2;
			temp = temp->next;
			temp1 = temp1->next;
			s--;
		}

	}
	return head;

}
