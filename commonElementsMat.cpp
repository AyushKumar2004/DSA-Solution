#include<bits/stdc++.h>
using namespace std;

void printCommonElements(vector<vector<int>> &mat, int n, int m)
{
    unordered_map<int,int> mp;

    for(int i=0;i<m;i++){
        mp[(mat[0][i])]=1;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp[(mat[i][j])]==i){
                mp[mat[i][j]]=i+1;
                if(i==n-1&&mp[mat[i][j]]==n){
                    cout<<mat[i][j]<<" "<<endl;
                }
            }

        }
    }
}


int main(){
    vector<vector<int>> mat={ 
        {1, 2, 1, 4, 8}, 
        {3, 7, 8, 5, 1}, 
        {8, 7, 7, 3, 1}, 
        {8, 1, 2, 7, 9}, 
    };
    int n=4;
    int m=5;
    printCommonElements(mat,n,m);

    return 0;
}