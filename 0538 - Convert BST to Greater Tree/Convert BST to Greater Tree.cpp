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
    /**
    * Utilize the recursion method.
    * The sum of greater nodes of a node will be sum of its right tree
    * plus the sum of all of its ancestors' right child tree, which will be pass by variable "pre".
    */
    
    int greaterBT(int pre, TreeNode* node) {
        if(!node){
            return pre;
        }
        int right = greaterBT(pre, node->right);
        node->val = node->val + right;
        if(node->left)
            return greaterBT(node->val, node->left);
        else
            return node->val;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        greaterBT(0, root);
        
        return root;
    }
};