#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }


int main(){
    vector<char> s;
    s.push_back('h');
    s.push_back('e');
    s.push_back('l');
    s.push_back('l');
    s.push_back('o');
    reverseString(s);
    int n=s.size();
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }

    return 0;
}