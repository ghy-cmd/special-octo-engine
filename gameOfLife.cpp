#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int a=board.size(),b=board[0].size();
        vector<vector<int>> res(a,vector<int>(b,0));
        for (int i=0;i<a;i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (board[i][j]==1)
                {
                    if (i>0 && j>0)
                    {
                        res[i-1][j-1]++;
                    }
                    if (i>0)
                    {
                        res[i-1][j]++;
                    }
                    if (j>0)
                    {
                        res[i][j-1]++;
                    }
                    if (i>0 && j<b-1)
                    {
                        res[i-1][j+1]++;
                    }
                    if (j<b-1)
                    {
                        res[i][j+1]++;
                    }
                    if (i<a-1 && j>0)
                    {
                        res[i+1][j-1]++;
                    }
                    if (i<a-1)
                    {
                       res[i+1][j]++;
                    }
                    if (i<a-1 && j<b-1)
                    {
                        res[i+1][j+1]++;
                    }
                }
            }
        }
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                if (res[i][j]<2)
                {
                    board[i][j]=0;
                }else if (res[i][j]==3 && board[i][j]==0)
                {
                    board[i][j]=1;
                }else if(res[i][j]>3){
                    board[i][j]=0;
                }
            }
        }
        
    }
};

int main(){
    Solution a;
    vector<vector<int>> vec={{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    a.gameOfLife(vec);
    for (auto i :vec)
    {
        for (auto j :i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}