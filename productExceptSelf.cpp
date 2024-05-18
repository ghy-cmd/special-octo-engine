#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> bef(n,1),aft(n,1),res;
        for (int i = 1; i < n; i++)
        {
            bef[i]=bef[i-1]*nums[i-1];
        }
        for (int i = n-2; i >= 0; i--)
        {
            aft[i]=aft[i+1]*nums[i+1];
        }
        for (int i = 0; i < n; i++)
        {
            res.push_back(bef[i]*aft[i]);
        }
        return res;
    }
};

int main(){

    return 0;
}