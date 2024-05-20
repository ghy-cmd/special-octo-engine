#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
/*
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。

你需要按照以下要求，给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
相邻两个孩子评分更高的孩子会获得更多的糖果。
请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
*/
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
/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
*/
    int trap(vector<int>& height) {
        int maxi=height[0],count=height.size(),label=0;
        vector<int> res(count,0);
        res[0]=maxi;
        for (int i = 1; i < count; i++)
        {
            if (height[i]>=maxi)
            {
                for (int j = label+1; j <i; j++)
                {
                    res[j]=maxi;
                }
                maxi=height[i];
                label=i;
                res[i]=height[i];
            }else
            {
                for (int j = label+1; j < i; j++)
                {
                    res[j]=max(res[j],height[i]);
                }
                res[i]=height[i];
            }
        }
        label=0;
        for (int i = 0; i < count; i++)
        {
            label+=res[i]-height[i];
        }
        return label;
    }
};

int main(){
    Solution a;
    vector<int> vec={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<a.trap(vec)<<endl;
    return 0;
}