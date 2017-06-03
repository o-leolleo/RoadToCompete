#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
int main()
{
    int snk[MAX], n;
    priority_queue<int> queue; 

    scanf("%d\n", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d\n", &snk[i]);

    int index = 0;

    while (n) {
        queue.push(snk[index++]);

        if (queue.top() != n) {
            printf("\n");
        } else{
            printf("%d", queue.top()); queue.pop(); n--;
            while (n && !queue.empty() && queue.top() == n) {
                printf(" %d", queue.top());
                n--; queue.pop();
            } 
            printf("\n");
        }
    }
}
