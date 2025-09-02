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


const int N = 1e5+100;
int n,m;
vector< pair<int,int> > G[N]; // (node, wt);
bool vis[N];
vector<int> dis(N, 1e18);
vector<int> par(N, -1);

void dij(){


    multiset< pair<int,int> > s; // (wt, node);

    dis[1] = 0;

    s.insert({0, 1});
    while(s.size() > 0){
        auto node = *s.begin();

        int distance = node.ff;
        int ver = node.ss;

        s.erase(s.begin());

        if(vis[ver]) continue;

        vis[ver] = 1;



        for(auto child : G[ver]){
            int child_v = child.ff;
            int wt = child.ss;

            if(dis[ver] + wt <  dis[child_v]){
                dis[child_v] = wt + dis[ver];
                par[child_v] = ver;
                s.insert({dis[child_v], child_v});
            }
        }
    }
}




///////////////////////////////// SHORTEST PATH BETWEEN A & B ////////////////////////////////////


void bfs(int a, int b, int x){

    vector<int> par(N,-1);
    vector<int> vis(N,0);
    queue<int> q;
    q.push(a);
    vis[a] = 1;
    while(!q.empty()){
        int ver = q.front(); q.pop();

        if(ver == b) break;



        for(auto child : G[ver]){
            if(vis[child]) continue;
            vis[child] = 1;
            q.push(child);
            par[child] = ver;
        }
    }
    vector<int> path;

    for(int i = b;i!=-1;i=par[i]){
        path.pb(i);
    }
    reverse(all(path)); 
}












void solve(){
    cin>>n>>m;
    for(int i =0 ;i<m;++i){
        int x,y,wt; cin>>x>>y>>wt;
        G[x].pb({y, wt});
        G[y].pb({x, wt});
    }
    dij();


    if(dis[n] == 1e18){
        cout<<-1; return;
    }

    vector<int> ans;
    for(int i = n;i!=-1; i = par[i]) ans.pb(i);

    reverse(all(ans));
        

    // shortest distance from 1 to n
    cout<<dis[n];
    nl
    
        

    // shortest path from 1 to n;
    for(auto e : ans) cout<<e<<" ";



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