#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curPath;

    void backtrack(TreeNode* node, int sum, int curSum) {
        if (node->left == nullptr && node->right == nullptr && curSum == sum) {
            res.emplace_back(curPath);
            return;
        }
        else if (curSum > sum) {
            return;
        }
        else {
            if (node->left != nullptr) {
                curPath.push_back(node->left->val);
                backtrack(node->left, sum, curSum + node->left->val);
                curPath.pop_back();
            }
            if (node->right != nullptr) {
                curPath.push_back(node->right->val);
                backtrack(node->right, sum, curSum + node->right->val);
                curPath.pop_back();
            }
        }
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == nullptr)
            return res;
        
        curPath.push_back(root->val);
        backtrack(root, sum, root->val);
        return res;
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
    Solution sol;
    vector<int> input = {2, 3, 1, 1, 4};
    bool res = sol.canJump(input);
    cout << res;

    return 0;
}