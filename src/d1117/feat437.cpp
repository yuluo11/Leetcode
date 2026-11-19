//这里用的暴力解法
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
    int helper(TreeNode* root,long long sum,int targetSum){
        if(root==nullptr)
            return 0;
        sum+=root->val;
        int count=0;
        if(sum==targetSum)
            count++;
        count+=helper(root->left, sum, targetSum);
        count+=helper(root->right, sum, targetSum);
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return 0;
        int total=helper(root,0LL, targetSum);
        total+=pathSum(root->left, targetSum);
        total+=pathSum(root->right, targetSum);
        return total;
    }
};
