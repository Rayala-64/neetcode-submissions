/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // The idea is simple. Using the BST property, depending on p.val and q.val present, there arises 3 different cases 
        // 1. both p.val and q.val < root.val - explore the left subtree of the root
        // 2. both p.val and q.val > root.val - explore the right subtree of the root
        // 3. Otherwise condition, (p.val < root.val and q.val > root.val or vice versa, or if p is itself an ancestor of q)

        //run a while loop, where local variable (a pointer) = root is not pointing to null pointer
        while (root != nullptr){
            // case 1 as mentioned above
            if(p -> val < root -> val && q -> val < root -> val){
                root = root -> left;
            }
            // case 2 as mentioned above
            else if(p -> val > root -> val && q -> val > root -> val){
                root = root -> right;
            }
            // case 3 as mentioned above
            else{
                return root;
            }
        }
        // if in case, there is no LCA 
        return nullptr;
    }
};
