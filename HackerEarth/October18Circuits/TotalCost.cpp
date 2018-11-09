#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, P, T, H, S;
    cin>>P>>S>>T>>H>>x;
    if(S-x>=T){
        cout<<P*x<<endl;
    }
    else{
        cout<<(S-T)*P+(x-(S-T))*H<<endl;
    }
    return 0;
}
