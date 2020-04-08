#include<bits/stdc++.h>

#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int countGreater(int arr[], int n, int k) 
{ 
    int l = 0; 
    int r = n - 1;
    int leftGreater = n;
    while (l <= r) { 
        int m = l + (r - l) / 2;
        if (arr[m] > k) { 
            leftGreater = m; 
            r = m - 1; 
        }
        else
            l = m + 1; 
    }
    return (n - leftGreater); 
} 

int main(){
	fastio;
	int N;
	cin>>N;
	int a[N], b[N], arr[N];
	for(int i=0; i<N; i++)
		cin>>a[i];

	for(int i=0; i<N; i++)
		cin>>b[i];

	for(int i=0; i<N; i++)
		arr[i] = a[i]-b[i];

	sort(arr, arr+N);

	ll ans = 0;
	for(int i=0; i<N; i++){
		if(arr[i]>0){
			ans+= (N-i-1);
		}
		else{
			ans+=countGreater(arr, N, -arr[i]);
		}
	}
	cout<<ans<<endl;
	return 0; 
}