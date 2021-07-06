#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
  

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution{
    private:
        int l_s = 0;
        void helper(TreeNode * root, vector<int> path){
            if(root == nullptr) return;
            if(path.size() == 0) path.push_back(root->val);
            else{
                if(path[path.size()-1] == root->val-1){
                    path.push_back(root->val);
                }
                else{
                    path.clear();
                    path.push_back(root->val);
                }
            }
            if(path.size() > l_s) l_s = path.size();
            helper(root->left,path);
            helper(root->right,path);
            return;
        }
    public:
        int binaryTreeLongestConsecutiveSequence(TreeNode *root){
            vector<int> init;
            helper(root,init);
            return l_s;
        }

};
// A utility function to create a node
TreeNode* newNode(int data)
{
    TreeNode* temp = new TreeNode;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    TreeNode* root = newNode(5);
    root->right = newNode(6);
    root->right->left = newNode(7);
    root->right->left->left = newNode(8);

    root->right->right = newNode(10);
    root->right->right->right = newNode(11);


    Solution new_solution;
    printf("%d\n", new_solution.binaryTreeLongestConsecutiveSequence(root));
    return 0;
}