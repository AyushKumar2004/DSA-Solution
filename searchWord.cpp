#include<bits/stdc++.h>
using namespace std;

bool exists(vector<vector<char>>grid, string word,int i,int j,int n,int m,int s,int x1[],int y1[]){
        for(int dir=0;dir<8;dir++){
            int i1=i,j1=j,k=0;
            int x=x1[dir];
            int y=y1[dir];
            
            while(i1>=0&&j1>=0&&i1<n&&j1<m&&k<s){
                if(grid[i1][j1]==word[k]){
                    i1+=x;
                    j1+=y;
                    k++;
                }else{
                    break;
                }
            }
            
            if(k==s){
                return true;
            }
        }
        
        return false;
    }

	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> ans;
	    vector<int> p(2);
	    int x1[8]={-1,0,1,1,1,0,-1,-1};
	    int y1[8]={1,1,1,0,-1,-1,-1,0};
	    int s=word.length();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(exists(grid,word,i,j,n,m,s,x1,y1)){
	                p[0]=i;
	                p[1]=j;
	                ans.push_back(p);
	            }
	        }
	    }
	    
	    return ans;
	}


int main(){
    
	vector<vector<char>> grid={{'B','B','M','B','B','B'},
                    {'C','B','A','B','B','B'},
                    {'I','B','G','B','B','B'},
                    {'G','B','I','B','B','B'},
                    {'A','B','C','B','B','B'},
                    {'M','C','I','G','A','M'}};
    string word="MAGIC";
    vector<vector<int>> ans=searchWord(grid,word);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
   
    return 0;
}