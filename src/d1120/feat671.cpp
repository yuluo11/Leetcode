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
    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root, root->val);
    }

    int dfs(TreeNode* root, int minVal) {
        if (root->val > minVal) 
            return root->val;   

        if (root->left == nullptr) 
            return -1;       

        int l = dfs(root->left, minVal);
        int r = dfs(root->right, minVal);

        if (l == -1) 
            return r;
        if (r == -1) 
            return l;
        return std::min(l, r);
    }
};
