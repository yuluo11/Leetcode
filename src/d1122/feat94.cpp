#include<vector>
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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int>res;
        dfs(root,res);
        return res;
    }
    void dfs(TreeNode* root,std::vector<int> &t){
        if(root==nullptr)
            return;
        dfs(root->left,t);
        t.push_back(root->val);
        dfs(root->right,t);
    }
};