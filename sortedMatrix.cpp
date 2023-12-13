#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        vector<int> ans;
        for(int i=0;i<N;i++){
           for(int j=0;j<N;j++){
               ans.push_back(Mat[i][j]);
           } 
        }
        sort(ans.begin(),ans.end());
        vector<vector<int>> Mati(N,vector<int>(N));
        int cnt=0;
        int total=N*N;
        for(int i=0;i<N&&cnt<total;i++){
            for(int j=0;j<N&&cnt<total;j++){
                Mati[i][j]=ans[cnt++];
            }
        }
        
        return Mati;
    }


int main(){

    vector<vector<int>> arr={{0,0,0,1},
							  {0,0,0,1},
							  {1,1,1,1},
							   {0,0,0,0}};
    vector<vector<int>> z=sortedMatrix(4,arr);
    
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<z[i][j]<<" ";
		}cout<<endl;
	}cout<<endl;

    return 0;
}