#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};


void merge(int data[], int p, int q, int r);
void mergeSort(int data[], int p, int r);

struct ListNode* concatenate(struct ListNode *ptr1, struct ListNode *ptr2, int sum, int tmp[]) {
	struct ListNode *temp;
	if (!ptr1)
		return ptr2;
	if (!ptr2)
		return ptr1;
	for (temp = ptr1; temp->next; temp = temp->next); // temp를 ptr1의 끝으로 이동
	temp->next = ptr2; //ptr2를 연결함

	temp = ptr1;
	temp->val=tmp[0];
	for (int i = 1; temp->next != NULL; i++) {
		temp = temp->next;
		temp->val = tmp[i] ;
	}

	return ptr1;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	struct ListNode *current1 = l1;
	struct ListNode *current2 = l2;


	int count = 1, count2 = 1;

	while (current1->next != NULL)
	{
		current1 = current1->next;
		count++;
	}
	while (current2->next != NULL)
	{
		current2 = current2->next;
		count2++;
	}
	
	int sum = count + count2;
	//printf("%d", sum);
	int *temp = (int *)malloc(sizeof(int)*sum);

	current1 = l1;
	temp[0]=current1->val;
	for (int i = 1; current1->next != NULL; i++) {
		current1 = current1->next;
		temp[i] = current1->val;

	}

	current2 = l2;
	temp[count] = current2->val;
	for (int i = count + 1; current2->next != NULL; i++) {
		current2 = current2->next;
		temp[i] = current2->val;
	}

	/*printf("\n");
	for (int i = 0; i < sum; i++) {
		printf("%d", temp[i]);
	}*/
	mergeSort(temp, 0, sum-1);

	/*printf("\n");
	for (int i = 0; i < sum; i++) {
	printf("%d", temp[i]);
	}
	printf("\n");
	*/
	concatenate(l1, l2, sum, temp);



	
}

void merge(int data[], int p, int q, int r) {
	int i = p, j = q + 1, k = p;
	int tmp[100];
	while (i <= q && j <= r) {
		if (data[i] <= data[j])

			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}
	while (i <= q)
		tmp[k++] = data[i++];
	while (j <= r)
		tmp[k++] = data[j++];
	for (int i = p; i <= r; i++) {
		data[i] = tmp[i];
	}
}

void mergeSort(int data[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(data, p, q);
		mergeSort(data, q + 1, r);
		merge(data, p, q, r);
	}
}

struct ListNode i1 = { 4,NULL };
struct ListNode i2 = { 5,NULL };
struct ListNode i3 = { 9,NULL };

struct ListNode jj1 = { 1,NULL };
struct ListNode jj2 = { 2,NULL };
struct ListNode jj3 = { 7,NULL };
struct ListNode jj4 = { 10,NULL };

struct ListNode *l1, *l2;

void show_list(struct ListNode *l1)
{
	struct ListNode *list = l1;
	if (l1) {
		while (list) {
			printf("%d ", list->val);
			list = list->next;
		}
		printf("\n");
	}
}

int main()
{
	l1 = &i1; i1.next = &i2; i2.next = &i3;
	l2 = &jj1; jj1.next = &jj2; jj2.next = &jj3; jj3.next = &jj4;

	show_list(l1);
	show_list(l2);

	struct ListNode* list = NULL;
	list = mergeTwoLists(l1, l2);

	show_list(list);
}