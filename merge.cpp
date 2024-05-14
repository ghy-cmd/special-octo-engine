#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0,k=0;
        vector<int> nums3;
        if (m==0)
        {
            nums1=nums2;
        }else if (n!=0)
        {
            for(int i=0;i<m+n;i++){
                int a=nums1[j],b=nums2[k];
                if (a<b){
                    nums3.push_back(a);
                    j++;
                }else{
                    nums3.push_back(b);
                    k++;
                }
                if(j==m){
                    nums3.insert(nums3.end(),nums2.begin()+k,nums2.end());
                    break;
                }else if (k==n)
                {
                    nums3.insert(nums3.end(),nums1.begin()+j,nums1.begin()+m);
                    break;
                }
            }
            nums1=nums3;
        }
    }
};

int main(){
    vector<int> vec1={2,0};
    vector<int> vec2={1};
    int m=1,n=1;
    Solution a;
    a.merge(vec1,m,vec2,n);
    for(auto it=vec1.begin();it!=vec1.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}