class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Both empty
        if (p == nullptr && q == nullptr)
            return true;

        // One empty, one non-empty
        if (p == nullptr || q == nullptr)
            return false;

        // Values are different
        if (p->val != q->val)
            return false;

        // Compare left and right subtrees
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};