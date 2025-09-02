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
#define skt string
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const int N = 1e5+100;

vector<int> G[N];
vector<int> lvl(N,1);   
bool vis[N];



vector<pair<int,int>> G[N];
vector<int> lvl(N,1e9+19);





int lvl[505][505];
int vis[505][505];
int v[505][505];
int n, m;


//////////////////////////////////// BASIC BFS ////////////////////////////////////////

void bfs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = 1;

    while(!q.empty()){
        int cur_ver = q.front();
        q.pop();
        // cout<<cur_ver<<" ";
        for(auto child : G[cur_ver]){
            if(vis[child]) continue;
            vis[child]=1;
            q.push(child);
            lvl[child] = lvl[cur_ver]+1;
        }
    }
}





/////////////////////////////// 0-1 BFS /////////////////////////////////////////////////


void bfs01(int src){
    dequeue<int> dq;
    dq.push_back(src);
    lvl[1] = 0;
    while(!dq.empty()){
        int cur_v = dq.front();
        dq.pop_front();
        for(auto child : G[cur_v]){
            int child_v = child.ff;
            int weight = child.ss; // either 0 or 1
            int lvlOfChildNode = lvl[cur_v] + weight;
            int curLvl = lvl[child_v];
            if(lvlOfChildNode < curLvl){
                lvl[child_v] = lvlOfChildNode;
                if(weight == 1){
                    dq.push_back(child_v);
                }
                else{
                    dq.push_front(child_v);
                }
            }
        }
    }
}



/////////////////////////////// MultiSource BFS /////////////////////////////////////////////////

vector<pair<int,int>> moves = {
    {0, 1}, {0, -1},
    {1, 0}, {-1, 0},
    {1, 1}, {1, -1},
    {-1, 1}, {-1, -1}
};



bool isValid(int i, int j){
    return i>=0 && j>=0 && i<n && j<m;
}



int multiSrcBfs(){
    int mx = 0;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            mx = max(mx, v[i][j]);
        }
    }

    queue<pair<int,int>> q;

    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            if(v[i][j] == mx){
                q.push({i,j});
                lvl[i][j] = 0;
                vis[i][j] = 1;
            }
        }
    }


    int ans = 0;
     while(!q.empty()){
        auto ver = q.front();
        int v_x = ver.ff, v_y = ver.ss;
        q.pop();

        for(auto move : moves){
             int child_x = v_x + move.ff;
             int child_y = v_y + move.ss;

             if(!isValid(child_x,child_y) || vis[child_x][child_y]) continue;

             q.push({child_x,child_y});

             lvl[child_x][child_y] = lvl[v_x][v_y] + 1;
             vis[child_x][child_y] = 1;
             ans = max(ans, lvl[child_x][child_y]);
        }
     }


     return ans;
}







void solve() {

    ///////////////////////////// BASIC BFS ///////////////////////////////
    //https://www.youtube.com/watch?v=M8jdDR5kV3k&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=93

    int n; cin>>n;
    for(int i = 0;i<n-1;++i){
        int u, v; cin>>u>>v;
        G[u].pb(v); G[v].pb(u);
    }
    bfs(1);
    for(int i = 1;i<=n;++i) cout<<i<<": "<<lvl[i]<<" "<<endl;



    ///////////////////////////// 0-1 BFS ///////////////////////////////
    //https://www.youtube.com/watch?v=SQOQ99stCas&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=95

    int n, m; cin>>n>>m;

    for(int i = 0;i<m;++i){
        int x,y; cin>>x>>y;
        G[x].pb({y,0});
        G[y].pb({x,1});
    }

    ///////////////////////////// multiSrcBfs BFS ///////////////////////////////

    // https://www.youtube.com/watch?v=xvi8PqRrAyU&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=95


    cin>>n>>m;
    for(int i = 0;i<n;++i){
        for(int j = 0;j<m;++j){
            cin>>v[i][j];
            vis[i][j] = 0;
            lvl[i][j] = 1e9+10;
        }
    }
    cout<<multiSrcBfs();





}


int32_t main() {
FAST

int t = 1;
cin >> t;
while (t--) {
    solve();
    cout << endl;
}
}