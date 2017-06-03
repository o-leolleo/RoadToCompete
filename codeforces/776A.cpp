#include <bits/stdc++.h>
using namespace std;

int main() {
    char person[2][20], person_A[20], person_B[20];
    int n;
    scanf("%s %s\n", person[0], person[1]);
    scanf("%d\n", &n);

    printf("%s %s\n", person[0], person[1]);

    while (n--) {
        scanf("%s %s\n", person_A, person_B);
        
        if (!strcmp(person_A, person[0]))
            strcpy(person[0], person_B);
        else
            strcpy(person[1], person_B);

        printf("%s %s\n", person[0], person[1]);
    }
}
