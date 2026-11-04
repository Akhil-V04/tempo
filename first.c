#include <stdio.h>
#include <ctype.h>

char p[10][10];
int n;

void findFirst(char c) {
    for (int i = 0; i < n; i++) {
        if (p[i][0] == c) {
            if (!isupper(p[i][2]))
                printf("%c ", p[i][2]);
            else
                findFirst(p[i][2]);
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (e.g., E=TR for E -> TR, use # for e):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", p[i]);

    printf("\nFIRST sets:\n");
    for (int i = 0; i < n; i++) {
        printf("FIRST(%c) = { ", p[i][0]);
        findFirst(p[i][0]);
        printf("}\n");
    }
    return 0;
}
