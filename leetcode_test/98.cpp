#include <climits>

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
    void inorderTravel(TreeNode* node, int &prev, bool &ret){
        if(ret == false) return;
        if(node == nullptr) return;
        inorderTravel(node->left,prev,ret);
        if(prev > node->val){
            ret = false;
        } 
        prev = node->val;
        inorderTravel(node->right,prev,ret);
    }
    bool isValidBST(TreeNode* root) {
        int prev = INT_MIN;
        bool ret = true;
        inorderTravel(root,prev,ret);
        return ret ;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(2);
    TreeNode *root = new TreeNode(2,left,right);
    auto s = sol.isValidBST(root);
  
}
