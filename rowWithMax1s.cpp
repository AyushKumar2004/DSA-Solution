#include<bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr, int n, int m) {
	    int row=0;
	    int col=m-1;
	    int res=-1;
	    while(row<n&&col>=0){
	        if(arr[row][col]==1){
	            res=row;
	            col--;
	        }
	        else{
	            row++;
	        }
	    }
	    
	    if(res==-1){
	        return -1;
	    }
	    
	    return res;
	   
	}


int main(){

    vector<vector<int>> arr={{0,0,0,1},
							  {0,0,0,1},
							  {1,1,1,1},
							   {0,0,0,0}};
    int z=rowWithMax1s(arr,4,4);
    
	cout<<z<<endl;


    return 0;
}