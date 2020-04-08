#include<bits/stdc++.h>
using namespace std;

int main(){
	int T, N, X;
	cin>>T;
	while(T--){
		cin>>N>>X;
		int arr[N], i=0;
		stack<int> st;

		for(int i=0; i<N; i++){
			cin>>arr[i];
		}

		sort(arr, arr+N);
		st.push(0);
        
		while(i<N && X>-1){
		    if(arr[i]<=st.top())
		        i++;
			else if(arr[i]==st.top()+1){
				st.push(arr[i]);
				i++;
			}
			else{
				st.push(st.top()+1);
				X--;
			}
		}
        
        if(X==-1)
            st.pop();
        else{
            while(X>0){
                st.push(st.top()+1);
                X--;
            }
        }
        
		cout<<st.top()<<endl;
	}
	return 0;
}