/*
剑指 Offer 04. 二维数组中的查找

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

思路：
从左下角或者右上角开始。这样，如果比当前数大就水平左移动，比当前数小就垂直下移动。

注意：
1）判断行列为0的情况；
2）注意别把宽和高弄混了。
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        int width = matrix[0].size(), height = matrix.size();

        int i = 0, j = width - 1;
        while (i < height && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                --j;
            }
            else if (matrix[i][j] < target) {
                ++i;
            }
        }

        return false;
    }
};
