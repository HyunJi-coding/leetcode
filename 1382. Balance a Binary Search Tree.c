/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int num, arr[10000];

void inorder(struct TreeNode* root) {
	if (root) {
		inorder(root->left);
		arr[num++] = root->val;
		inorder(root->right);
	}
}

struct TreeNode* balance(int left, int right) {
	struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	if (left > right)
		return NULL;

	int mid = (left + right) / 2;
	root->val = arr[mid];
	root->left = balance(left, mid - 1);
	root->right = balance(mid + 1, right);
	return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
	num = 0;
	inorder(root);
	return balance(0, num - 1);
}