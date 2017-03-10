#include <cstdio>
#include <map>
#include <vector>
#include <queue>
#include <string>
#define MAX 4010
#define INF -1
using namespace std;
vector <int> AdjLst[MAX], d;
queue <int> q;
map <string, int> translate;

int main()
{
        int pt, lig;
        scanf("%d %d\n", &pt, &lig);

        int elem = 0;

        while (lig--) {
                char a[50], b[50]; scanf("%s %s\n", a, b);

                if (!translate.count(a)) translate[a] = elem++;
                if (!translate.count(b)) translate[b] = elem++;

                AdjLst[translate[a]].push_back(translate[b]);
                AdjLst[translate[b]].push_back(translate[a]);
        }

        int sum = 0;

        d.assign(elem, INF);
        q.push(translate["Entrada"]);
        d[translate["Entrada"]] = 0;

        while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int i = 0; i < AdjLst[u].size(); ++i)
                        if (d[AdjLst[u][i]] == INF) {
                                d[AdjLst[u][i]] = d[u] + 1;
                                q.push(AdjLst[u][i]);
                        }
        }

        sum += d[translate["*"]];

        d.assign(elem, INF);
        q.push(translate["*"]);
        d[translate["*"]] = 0;

        while (!q.empty()) {
                int u = q.front(); q.pop();

                for (int i = 0; i < AdjLst[u].size(); ++i)
                        if (d[AdjLst[u][i]] == INF) {
                                d[AdjLst[u][i]] = d[u] + 1;
                                q.push(AdjLst[u][i]);
                        }
        }

        sum += d[translate["Saida"]];
        printf("%d\n", sum);
}
