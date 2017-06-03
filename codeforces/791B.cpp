#include <bits/stdc++.h>
using namespace std;
#define MAX 200000
vector<int> Adj[MAX];
vector<bool> state;

bool dfs(int u, int &V, int &E)
{
    state[u] = true;
    V++;

    for (int i = 0; i < Adj[u].size(); ++i) {
        int v = Adj[u][i];

        E++;

        if (!state[v])
            dfs(v, V, E);
    }
}

int main()
{
    int n, m;

    scanf("%d %d\n", &n, &m);

    state.assign(n + 1, false);

    for (int k = 1; k <= m; ++k) {
        int i, f;
        scanf("%d %d\n", &i, &f);
        Adj[i].push_back(f);
        Adj[f].push_back(i);
    }

    int k;

    for (k = 1; k <= n; ++k)
        if (!state[k]) {
            int v = 0, e = 0;
            dfs(k,v,e);
            if (e != 1LL*v*(v-1))
                break;
        }

    printf("%s\n", k == n + 1 ? "YES" : "NO");
}
