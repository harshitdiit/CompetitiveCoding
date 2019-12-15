#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define vec vector<int>
#define finput ifstream cin;cin.open("in.txt")
#define foutput ofstream cout;cout.open("out.txt")
#define F(i, N) for(int i=0; i<N; i++)
#define MOD 1000000007

// Fast I/O
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

// Lower Bound Binary Search

int bins(int a[],int lo,int hi){
	//finds the last false
	// F F F "F" T T T T T
	int mid;
	while(lo < hi){
		mid = lo + (hi-lo+1)/2;
		if(a[mid]==true)
	 		hi = mid-1;
		else
	        lo = mid;
    }
    if(a[lo]==true){
    	return -1;
    	//All are true
    }
    return lo;
}

// Upper Bound Binary Search

int bins2(int a[],int lo,int hi){
	//finds the first true
	// F F F F "T" T T T T
	int mid;
	while(lo < hi){
		mid = lo + (hi-lo)/2;
		if(a[mid]==true)
	 		hi = mid;
		else
	        lo = mid+1;
    }
    if(a[lo]==false){
    	return -1;
    	//All are false
    }
    return lo;
}
ll int mod(ll int a){
	if(a<0) return -a;
	return a;
}

// Eratosthenes Sieve && Push prime numbers

int prime[1000001]={0};vector <int> p;
void sieve(){
	for(int i=2;i*i<=1000000;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=1000000;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
}

// Matrix exponentiation (matrix initialized as I)
class Matrix{
public:
    ll mat[2][2];
    Matrix() {
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) mat[i][j] = (i==j?1:0);
    }

    Matrix operator*(Matrix &m) {
        Matrix m2;
        m2.mat[0][0] = ((mat[0][0] * m.mat[0][0]) % MOD + (mat[0][1] * m.mat[1][0]) % MOD) % MOD;
        m2.mat[0][1] = ((mat[0][0] * m.mat[1][0]) % MOD + (mat[0][1] * m.mat[1][1]) % MOD) % MOD;
        m2.mat[1][0] = ((mat[1][0] * m.mat[0][0]) % MOD + (mat[1][1] * m.mat[1][0]) % MOD) % MOD;
        m2.mat[1][1] = ((mat[1][0] * m.mat[1][0]) % MOD + (mat[1][1] * m.mat[1][1]) % MOD) % MOD;
        return m2;
    }

    Matrix operator^ (ll n) {
        Matrix m2, base=*this;
        while(n>0) {
            if(n&1) {
                m2 = m2 * base;
            }
            base = base*base;
            n>>=1;
        }
        return m2;
    }

};
//nCr % p
ll factorial[2000010];

ll modexp(ll x, ll b){
	ll ans=1;
	while(b>0){
		if(b%2==1)
			ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		b/=2;
	}
	return ans;
}

ll modinv(ll x){
  return modexp(x, MOD-2);
}

ll nCr(ll N, ll R){
  return (((factorial[N]*modinv(factorial[R]))%MOD)*modinv(factorial[N-R]))%MOD;
}

// Modular Exponentiation

ll int modexp(ll int x, ll int b, ll int mod){
	ll int ans=1;
	while(b>0){
		if(b%2==1)
			ans=(ans*x)%mod;
		x=(x*x)%mod;
		b/=2;
	}
	return ans;
}

// Dijkstra

vector<int> dijkstra(vector<vector<pair<int, int>>> &G, vector<bool> &vis, int source){
    vector<int> dist(G.size(), 1000000);
    dist[source]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> pq;
    pq.push({0, source});
    while(!pq.empty()){
        pair<int, int> P = pq.top();
        pq.pop();

        int v = P.second;
        int wt = P.first;

        if(vis[v]){
            continue;
        }
        vis[v]=true;
        for(auto edge:G[v]){
            int w = edge.first;
            int x = edge.second;
            if(dist[v]+w<dist[x]){
                dist[x] = dist[v]+w;
                pq.push({dist[x], x});
            }
        }
    }
    return dist;
}


// TRIE

//-----------------------------------------------
#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;

		TrieNode() : isEndOfWord(false){
			for (int i = 0; i < ALPHABET_SIZE; i++)
      	children[i] = NULL;
		}
};

void insert(struct TrieNode *root, string key) {
    TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(TrieNode *root, string key) {
    TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

//------------------------------------------------------
//Disjoint Set
void initialize( int Arr[ ], int N) {
  for(int i = 0; i<N; i++) {
		Arr[ i ] = i ;
		size[ i ] = 1;
	}
}

int root (int Arr[ ] ,int i){
	while(Arr[ i ] != i){
    Arr[ i ] = Arr[ Arr[ i ] ] ;
    i = Arr[ i ];
	}
  return i;
}

void unionize(int Arr[ ],int size[ ],int A,int B) {
  int root_A = root(A);
  int root_B = root(B);
  if(size[root_A] < size[root_B ]){
		Arr[ root_A ] = Arr[root_B];
		size[root_B] += size[root_A];
		//size[root_A]=0;
	}
  else {
		Arr[ root_B ] = Arr[root_A];
		size[root_A] += size[root_B];
		//size[root_B]=0
	}
}


//-----------------------------------------------------

//Segment tree Pass 1 as start index of segment tree.
void build(int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
    }
    else{
        int mid = (start + end) / 2;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}
int query(int node, int start, int end, int l, int r){
    if(r < start or end < l){
    	return 0;
    }
    if(l <= start and end <= r){
    	return tree[node];
    }
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}
void update(int node, int left, int right, int index, int val){
    if(l == r){
		tree[node] = val;
		return;
	}
	int mid = (l+r)>>1;
	int left = node<<1;
	int right = left + 1;
	if(ind <= mid)
		update(left, l, mid, ind, val);
	else
		update(right, mid+1, r, ind, val);
	tree[node] = tree[left] + tree[right];
	return;
}

// PERSISTENT SEGMENT TREE // :


void build(int id = ir,int l = 0,int r = n){
	if(r - l < 2){
		s[id] = a[l];
		return ;
	}
	int mid = (l+r)/2;
	L[id] = NEXT_FREE_INDEX ++;
	R[id] = NEXT_FREE_INDEX ++;
	build(L[id], l, mid);
	build(R[id], mid, r);
	s[id] = s[L[id]] + s[R[id]];
}
int upd(int p, int v,int id,int l = 0,int r = n){
	int ID =  NEXT_FREE_INDEX ++; // index of the node in new version of segment tree
	if(r - l < 2){
		s[ID] = (a[p] += v);
		return ID;
	}
	int mid = (l+r)/2;
	L[ID] = L[id], R[ID] a= R[id]; // in case of not updating the interval of left child or right child
	if(p < mid)
		L[ID] = upd(p, v, L[ID], l, mid);
	else
		R[ID] = upd(p, v, R[ID], mid, r);
	return ID;
}
int sum(int x,int y,int id,int l = 0,int r = n){
	if(x >= r or l >= y)	return 0;
	if(x <= l && r <= y)	return s[id];
	int mid = (l+r)/2;
	return sum(x, y, L[id], l, mid) +
	       sum(x, y, R[id], mid, r);
}
/ PERSISTENT SEGMENT TREE /

int main(){
	clock_t cc;
	cc=clock();


	cc=clock()-cc;
	cout<<float(cc)/CLOCKS_PER_SEC<<endl;
}
