#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();                       
        k=k%size;
        int n=-1,j=-1,temp,tt;
        for (int i = 0; i < size; i++)
        {
            if (j==n)
            {
                n=n+1;
                j=n;
                temp=nums[j];
            }
            j=(j+k)%size;
            tt=nums[j];
            nums[j]=temp;
            temp=tt;
        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    }
};

int main(){
    Solution a;
    vector<int> vec={1,2,3,4,5,6};
    a.rotate(vec,4);
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout<<*it<<" ";
    }
    return 0;
}