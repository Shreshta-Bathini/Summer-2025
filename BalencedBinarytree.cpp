#include <algorithm>
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
    // Helper function to get height; returns -1 if subtree is not balanced
    int height(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = height(root->left);
        if (leftHeight == -1) return -1;  // left subtree not balanced

        int rightHeight = height(root->right);
        if (rightHeight == -1) return -1;  // right subtree not balanced

        if (abs(leftHeight - rightHeight) > 1)
            return -1;  // current node not balanced

        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
