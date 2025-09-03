#include<bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n";
#define nl cout << endl;
#define no cout << "NO\n";
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define st string
#define fr(i, x, y) for (int i = x; i < y; i++)
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAX 1e18
#define MIN -1e18

#ifndef ONLINE_JUDGE
#define debug(x) cerr << setw(15) << left << #x << ": "; _print(x); cerr << endl;
#define del cerr << '\n';
#else
#define debug(x)
#define del
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}

template <typename T, typename V> void _print(const pair<T, V>& p) {cerr << '{'; _print(p.first); cerr << ", "; _print(p.second); cerr << '}';}
template <typename T> void _print(const vector<T>& v) {cerr << '['; for (size_t i = 0; i < v.size(); ++i) {_print(v[i]); if (i != v.size() - 1) cerr << ", ";} cerr << ']';}
template <typename T> void _print(const set<T>& s) {cerr << '{'; bool first = true; for (const auto& x : s) {if (!first) cerr << ", "; _print(x); first = false;} cerr << '}';}
template <typename T> void _print(const multiset<T>& s) {cerr << '{'; bool first = true; for (const auto& x : s) {if (!first) cerr << ", "; _print(x); first = false;} cerr << '}';}
template <typename T, typename V> void _print(const map<T, V>& m) {cerr << '{'; bool first = true; for (const auto& kv : m) {if (!first) cerr << ", "; _print(kv); first = false;} cerr << '}';}

int power(int n, int k){int result = 1;while (k > 0) {if (k & 1) {result = (result * n);}n = (n * n);k >>= 1;}return result;}
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int lcm(int a, int b) {return (a / __gcd(a, b)) * b;}
bool isPrime(int n) {if (n <= 1) return false;if (n == 2) return true;if (n % 2 == 0) return false;for (int i = 3; i * i <= n; i += 2) {if (n % i == 0) return false;}return true;}



////////////////// main concept

// Either the shortest path from i to j doesn’t go through k → keep dist[i][j]
// Or it goes through k → dist[i][j] can be improved via dist[i][k] + dist[k][j]

// Process with k

// Start: only direct edges are known.

// For k = 1, we allow paths that go through node 1.

// For k = 2, we allow paths that go through nodes {1, 2}.

// For k = 3, we allow paths that go through nodes {1, 2, 3}.

// Continue until all nodes have been used.







const int N = 2005;
int n,m;
vector< pair<int,int> > G[N]; // (node, wt);

int dist[N][N];

// problem: Shortest Routes II




void solve(){
    for(int i = 0;i<N;++i){
        for(int j = 0;j<N;++j){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = 1e18;
        }
    }



    cin>>n>>m;
    int q; cin>>q;
    for(int i =0 ;i<m;++i){
        int x,y,wt; cin>>x>>y>>wt;
        dist[x][y] = min(dist[x][y],wt);
        dist[y][x] = min(dist[y][x],wt);
    }


    for(int k = 1;k<=n;++k){
        for(int i = 1;i<=n;++i){
            for(int j = 1;j<=n;++j){
                if(dist[i][k] != 1e18 && dist[k][j] != 1e18){ // handling negative value (there is no path)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
                }
            }
        }
    }



    while(q--){
        int a, b; cin>>a>>b;

        if(dist[a][b] == 1e18) cout<<-1;
        else cout<<dist[a][b];
        cout<<endl;
    }









}       


int32_t main() {
    FAST
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
    #endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

}

