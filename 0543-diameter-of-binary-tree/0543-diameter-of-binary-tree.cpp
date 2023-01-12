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
    
    int check(TreeNode* root, int &ans)
    {
        if(root==NULL)
            return 0;
        int ld = check(root->left,ans);
        int rd = check(root->right, ans);
        ans = max(ans, ld + rd);
        return max(ld,rd)+1;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
       int ans = 0;
        check(root, ans);
        return ans;
        
    }
};