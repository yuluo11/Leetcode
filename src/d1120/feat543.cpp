#include<algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int best=0;
        dfs(root,best);
        return best;
    }
    int dfs(TreeNode* root ,int &best){
        if(root==nullptr)
            return 0;
        int l=dfs(root->left,best);
        int r=dfs(root->right,best);
        best=std::max(best,l+r);
        return std::max(r,l)+1;
    }
};