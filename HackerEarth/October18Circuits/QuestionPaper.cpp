#include<bits/stdc++.h>
using namespace std;

int gcd(int A,int B){
    if(A==0)
        return B;

    return gcd(B%A, A);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, a, b, combis;
        cin>>N>>a>>b;

        int A = min(a,b)/gcd(a,b);
        int B = max(a,b)/gcd(a,b);

        int S=A+B;

        int diff = N-S;

        combis = ((N+1)*(N+2))/2 - (diff>=0?((diff+1)*(diff+2))/2:0);

        cout<<combis<<endl;
    }
    return 0;
}
