#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int startRow=0;
        int startCol=0;
        int endRow=r-1;
        int endCol=c-1;
        
        int cnt=0;
        int total=r*c;
        vector<int> ans;
        
        while(cnt<total){
            //starting row
            for(int index=startCol;cnt<total&&index<=endCol;index++){
                ans.push_back(matrix[startRow][index]);
                cnt++;
            }
            startRow++;
            
            //end column
            for(int index=startRow;cnt<total&&index<=endRow;index++){
                ans.push_back(matrix[index][endCol]);
                cnt++;
            }
            endCol--;
            
            //end row
            for(int index=endCol;cnt<total&&index>=startCol;index--){
                ans.push_back(matrix[endRow][index]);
                cnt++;
            }
            endRow--;
            
            //start column
            for(int index=endRow;cnt<total&&index>=startRow;index--){
                ans.push_back(matrix[index][startCol]);
                cnt++;
            }
            startCol++;
        }
        
        return ans;
    }


int main(){

    vector<vector<int>> arr={{1,2,3,4},
							  {5,6,7,8},
							  {9,10,11,12},
							   {13,14,15,16}};
    vector<int> z=spirallyTraverse(arr,4,4);
    
	for(int i=0;i<z.size();i++){
		cout<<z[i]<<" ";
	}

    return 0;
}