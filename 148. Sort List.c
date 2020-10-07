/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

void bubble_sort(int arr[], int count);

struct ListNode* sortList(struct ListNode* head) {

	struct ListNode *current1 = head;

	int count = 1;

	if (head == NULL)
		return NULL;

	while (current1->next != NULL)
	{
		current1 = current1->next;
		count++;
	}

	int *temp = (int *)malloc(sizeof(int)*count);

	current1 = head;
	temp[0] = current1->val;
	for (int i = 1; current1->next != NULL; i++) {
		current1 = current1->next;
		temp[i] = current1->val;

	}


	//mergeSort(temp, 0, count-1);
	bubble_sort(temp, count);


	current1 = head;
	current1->val = temp[0];
	for (int i = 1; current1->next != NULL; i++) {
		current1 = current1->next;
		current1->val = temp[i];
	}

	return head;
}


void bubble_sort(int arr[], int count)    // �Ű������� ������ �迭�� ����� ������ ����
{
	int temp;

	for (int i = 0; i < count; i++)    // ����� ������ŭ �ݺ�
	{
		for (int j = 0; j < count - 1; j++)   // ����� ���� - 1��ŭ �ݺ�
		{
			if (arr[j] > arr[j + 1])          // ���� ����� ���� ���� ����� ���� ���Ͽ�
			{                                 // ū ����
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;            // ���� ��ҷ� ����
			}
		}
	}
}
