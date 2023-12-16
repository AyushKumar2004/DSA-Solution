#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &Mat,int n,int m){
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            swap(Mat[i][j],Mat[j][i]);
        }
    }
    //for reverse
    for(int i=0;i<n;i++){
        reverse(Mat[i].begin(),Mat[i].end());
    }
}


int main(){
    vector<vector<int>> Mat={
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    int n=5;
    int m=5;
    rotateMatrix(Mat,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<Mat[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}