/**
 * class LLNode {
 *     public:
 *         int val;
 *         LLNode *next;
 * };
 */
LLNode *solve(LLNode *node, int target) {
	LLNode *dummyNode = new LLNode();
	LLNode *ans = dummyNode;
	while (node != nullptr) {
		if (node->val != target) {
			dummyNode->next = new LLNode(node->val);
			dummyNode = dummyNode->next;
		}
		node = node->next;
	}
	return ans->next;
}