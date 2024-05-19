#include<iostream>
#include<vector>
using namespace std;
/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),res=0;
        vector<int> ans(n,1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i]>ratings[i-1])
            {
                ans[i]=ans[i-1]+1;
            }
        }
        res=ans[n-1];
        for (int i = n-2; i >=0; i--)
        {
            if (ratings[i]>ratings[i+1])
            {
                ans[i]=max(ans[i+1]+1,ans[i]);
                res+=ans[i];
            }else
            {
                res+=ans[i];
            }
        }
        return res;
    }
};

int main(){
    Solution a;
    vector<int> vec={1,3,4,5,2};
    cout<<a.candy(vec)<<endl;
    return 0;
}