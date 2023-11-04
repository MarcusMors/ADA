#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

#define int long long
// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;

const int N = 2e5 + 10;
typedef array<int, 3> ii;
// ii a[N];

vector<int> adj[N];
bool vis[N];
int ans= 1;

int bfs()
{
  queue<int> q;
  q.push(1);
  vis[1]= 1;
  int accum= 1;
  while(!q.empty()){
    int u= q.front();
    int noVis= 0;
    for(auto v:adj[u]){
        if(!vis[v]){
            noVis++;
            q.push(v);
        }
    }
    q.pop();
    cout<<accum<<endl;
    accum+= accum*noVis;
  }
  return accum;
}

void solve()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans= bfs();
  cout << ans << "\n";
}

signed main()
{
  fastio();

  // unsigned t;
  // cin >> t;

  // while (t--) { solve(); }
  solve();

  return 0;
}
