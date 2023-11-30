#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if(intervals.empty()){
            return intervals;
        }

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> mixedVector;

        mixedVector.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            if(mixedVector.back()[1]>=intervals[i][0]&&mixedVector.back()[0]<=intervals[i][1]){
                mixedVector.back()[1]=max(mixedVector.back()[1],intervals[i][1]);
            }
            else{
                mixedVector.push_back(intervals[i]);
            }
        }
        return mixedVector;

    }



int main(){

    vector<vector<int>> intervals(4,vector<int>(2));
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cin>>intervals[i][j];
        }
    }

    vector<vector<int>> mixedVector=merge(intervals);

    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            cout<<mixedVector[i][j]<<" ";
        }
    }

    return 0;
}