#include<iostream>
using namespace std;


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
    void depTravel(TreeNode* node,int dep,int &monitors){
        if(node == nullptr) return;
        if(dep % 2) monitors ++;
        else if(node->left != 0 && node->left != 0){
            if(node->left->left == nullptr && node->left->right == nullptr && node->right->left == nullptr && node->right->right == nullptr){
                monitors ++;
                return;
            }
        }
        depTravel(node->left,dep+1,monitors);
        depTravel(node->right,dep+1,monitors);
    }
    int minCameraCover(TreeNode* root) {
        int monitors = 0;
        depTravel(root,0,monitors);
        if (monitors==0) return 1;
        return monitors;
    }
};

int main(int argc, char const *argv[])
{
     TreeNode *root = new TreeNode(0);
     TreeNode *left = new TreeNode(0);
     root->left = left;
     Solution Solut;
     Solut.minCameraCover(root);
    return 0;
}
