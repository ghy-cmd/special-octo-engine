#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h=0,n=citations.size();
        sort(citations.begin(), citations.end(), [](int a, int b) { return a > b; });
        for (int i = 0; i < n; i++)
        {
            if (i+1>=citations[i])
            {
                return max(h,min(i+1,citations[i]));
            }else{
                h=max(h,min(i+1,citations[i]));
            }   
        }
        return n;
    }
};

int main(){
    vector<int> vec={3,0,6,1,5};
    Solution a;
    cout<<a.hIndex(vec)<<endl;
    for (auto i :vec)
    {
        cout<<i<<" ";
    }
    
    return 0;
}