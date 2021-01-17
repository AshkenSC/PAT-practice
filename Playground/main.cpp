#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;

// 0096. Unique Binary Search Trees
/*
dp[i] 以1到i为结点组成的二叉搜索树有多少种
dp[i] = dp


*/

class Solution {
    void setZeroes(vector<vector<int>> matrix) {
        // 判断首行是否设0，记录在rowFlag
        bool rowFlag = false;
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                rowFlag = true;
                break;
            }
        }

        // 判断首列是否设0，记录在colFlag
        bool colFlag = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                colFlag = true;
                break;
            }
        }

        // 遍历，将要设0的行列记录在第0行，第0列
        // 如果(i, j)为0，则i行，j列都设为0
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 设i列为0
        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }

        // 设i行为0
        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 处理0行0列
        if (rowFlag){
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
        if (colFlag){
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main() {
    Solution sol;
    //vector<vector<int>> input = {{0,0,0},{0,1,0},{0,0,0}};
    vector<int> input = {1, 1, 1, 2, 2, 3};
    vector<int> res = sol.topKFrequent(input, 2);
    for (auto num : res) {
        cout << num << " ";
    }

    return 0;
}