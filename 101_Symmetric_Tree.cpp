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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr || root->left == nullptr && root->right == nullptr)
            return true;
        else if(root->left == nullptr || root->right == nullptr)
            return false;
        else if ((root->left)->val == (root->right)->val){
            TreeNode* external =  new TreeNode((root->left)->val, (root->left)->left, (root->right)->right);
            TreeNode* internal =  new TreeNode((root->left)->val, (root->left)->right, (root->right)->left);
            return isSymmetric(external) && isSymmetric(internal);
        }
        else 
            return false;
    }
};
