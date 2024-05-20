#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    /*
    n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

    你需要按照以下要求，给这些孩子分发糖果：

    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。
    请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
    */
    int candy(vector<int> &ratings)
    {
        int n = ratings.size(), res = 0;
        vector<int> ans(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                ans[i] = ans[i - 1] + 1;
            }
        }
        res = ans[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1])
            {
                ans[i] = max(ans[i + 1] + 1, ans[i]);
                res += ans[i];
            }
            else
            {
                res += ans[i];
            }
        }
        return res;
    }
    /*
    给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
    */
    int trap(vector<int> &height)
    {
        int maxi = height[0], count = height.size(), label = 0;
        vector<int> res(count, 0);
        res[0] = maxi;
        for (int i = 1; i < count; i++)
        {
            if (height[i] >= maxi)
            {
                for (int j = label + 1; j < i; j++)
                {
                    res[j] = maxi;
                }
                maxi = height[i];
                label = i;
                res[i] = height[i];
            }
            else
            {
                for (int j = label + 1; j < i; j++)
                {
                    res[j] = max(res[j], height[i]);
                }
                res[i] = height[i];
            }
        }
        label = 0;
        for (int i = 0; i < count; i++)
        {
            label += res[i] - height[i];
        }
        return label;
    }
    /*
    罗马数字转整数
    */
    int romanToInt(string s)
    {
        int n = 0, count = s.size(), i = 0;
        do
        {
            if (s[i] == 'I')
            {
                if (i + 1 < count && s[i + 1] == 'V')
                {
                    n += 4;
                    i += 2;
                }
                else if (i + 1 < count && s[i + 1] == 'X')
                {
                    n += 9;
                    i += 2;
                }
                else
                {
                    n += 1;
                    i += 1;
                }
            }
            else if (s[i] == 'V')
            {
                n += 5;
                i += 1;
            }
            else if (s[i] == 'X')
            {
                if (i + 1 < count && s[i + 1] == 'L')
                {
                    n += 40;
                    i += 2;
                }
                else if (i + 1 < count && s[i + 1] == 'C')
                {
                    n += 90;
                    i += 2;
                }
                else
                {
                    n += 10;
                    i += 1;
                }
            }
            else if (s[i] == 'L')
            {
                n += 50;
                i += 1;
            }
            else if (s[i] == 'C')
            {
                if (i + 1 < count && s[i + 1] == 'D')
                {
                    n += 400;
                    i += 2;
                }
                else if (i + 1 < count && s[i + 1] == 'M')
                {
                    n += 900;
                    i += 2;
                }
                else
                {
                    n += 100;
                    i += 1;
                }
            }
            else if (s[i] == 'D')
            {
                n += 500;
                i += 1;
            }
            else if (s[i] == 'M')
            {
                n += 1000;
                i += 1;
            }
        } while (i < count);
        return n;
    }
    /*
    给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
    trick:我们可以使用每行和每列的第一个单元格作为标志。此标志将确定行或列是否已设置为零。
    */
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool a = false, b = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)
                    {
                        a = true;
                    }
                    if (j == 0)
                    {
                        b = true;
                    }
                    if (i != 0 && j != 0)
                    {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (matrix[0][i] == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        if (a)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        }
        if (b)
        {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution a;
    // vector<int> vec={0,1,0,2,1,0,1,3,2,1,2,1};
    // cout<<a.trap(vec)<<endl;
    // string s = "MCMXCIV";
    // cout << a.romanToInt(s) << endl;
    vector<vector<int>> vec = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    a.setZeroes(vec);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}