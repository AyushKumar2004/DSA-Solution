#include <bits/stdc++.h>
using namespace std;
long long cnt=0; 
    long long toh(int N, int from, int to, int aux) {
        if(N==0) return cnt;
        if(N==1){
            cnt++;
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<< to<<endl;
            return cnt;
        }
        toh(N-1,from,aux,to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<< to<<endl;
        cnt++;
        toh(N-1,aux,to,from);
        
        return cnt;
    }
int main() {
    
    cout<<toh(3,1,2,3);

    return 0;
}