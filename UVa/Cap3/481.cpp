#include <bits/stdc++.h>
using namespace std;
vector<int> num, L, p, L_id;

int main()
{
        int tmp;

        while (scanf("%d\n", &tmp) != EOF)
                num.push_back(tmp);

        L.assign(num.size() + 1, 0);
        p.assign(num.size() + 1, 0);
        L_id.assign(num.size() + 1, 0);

        L[0] = num[0];
        p[0] = -1;
        L_id[0] = 0;

        int N = 1, maior = 1, index = 0;

        for (int i = 1; i < num.size(); ++i) {
                int pos = lower_bound(L.begin(), L.begin() + N, num[i]) - L.begin();
                L[pos] = num[i];

                if (pos == N) N++;

                p[i] = pos ? L_id[pos - 1] : -1;
                L_id[pos] = i;

                if (pos + 1 >= maior) {
                        maior = pos + 1;
                        index = i;
                }
        }

        stack<int> s;

        do {
                s.push(num[index]);
                index = p[index];
        } while (index >= 0);

        printf("%d\n-\n", s.size());

        while(!s.empty()) {
                printf("%d\n", s.top());
                s.pop();
        }
}
