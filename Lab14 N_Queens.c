#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x[20], count = 1;

void queens(int k, int n);
int place(int k, int j);

int main() {
    int n;
    printf("\nEnter the number of queens to be placed: ");
    scanf("%d", &n);
    queens(1, n);
    return 0;
}

void queens(int k, int n) {
    int j, i;
    for (j = 1; j <= n; j++) {
        if (place(k, j)) {
            x[k] = j; 
            if (k == n) {  
                printf("\nSolution %d\n", count++);
                for (i = 1; i <= n; i++) {
                    printf("\tRow %d <--- > Column %d\n", i, x[i]);
                }
                
            } else {
                queens(k + 1, n); 
            }
        }
    }
}

int place(int k, int j) {
    int i;
    for (i = 1; i < k; i++) {
        if (x[i] == j || abs(x[i] - j) == abs(i - k)) {
            return 0; 
        }
    }
    return 1; 
}


OUTPUT
enter the number of queens to be placed

4
1 solution
1 row &lt;---&gt; 2 column
2 row &lt;---&gt; 4 column
3 row &lt;---&gt; 1 column
4 row &lt;---&gt; 3 column
2 solution
1 row &lt;---&gt; 3 column
2 row &lt;---&gt; 1 column
3 row &lt;---&gt; 4 column
4 row &lt;---&gt; 2 column
