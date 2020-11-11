/*
0222. Count Complete Tree Nodes

给出一个完全二叉树，求出该树的节点个数。
说明：
完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

思路：递归遍历。
*/


class Solution {
private:
    int nodeNum = 0;

public:
    void traverse(TreeNode* node) {
        if (!node)
            return;
        else {
            nodeNum++;
            traverse(node->left);
            traverse(node->right);
        }
    }    

    int countNodes(TreeNode* root) {
        traverse(root);
        return nodeNum;
    }
};