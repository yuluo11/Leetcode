#include<stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    std::stack<TreeNode*>st;
public:
    BSTIterator(TreeNode* root) {
        while(root!=nullptr){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* cur=st.top();
        st.pop();
        TreeNode* temp = cur->right;
        while (temp != nullptr) {
            st.push(temp);
            temp = temp->left;
        }

        return cur->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};