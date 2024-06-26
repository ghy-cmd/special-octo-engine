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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while (i < n) {
            int sumOfGas = 0, sumOfCost = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                sumOfGas += gas[j];
                sumOfCost += cost[j];
                if (sumOfCost > sumOfGas) {
                    break;
                }
                cnt++;
            }
            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }
        return -1;
    }
};

int main(){
    Solution a;
    vector<int> gas={5,8,2,8},cost={6,5,6,6};
    cout<<a.canCompleteCircuit(gas,cost);
    return 0;
}