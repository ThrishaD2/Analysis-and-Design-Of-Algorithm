#include <stdio.h>

void main() {
    int i, j, n, v, k, min, u;
    int c[20][20], s[20], d[20];  

    printf("\n Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("\n Enter the cost adjacency matrix: ");
    printf("\n Enter 999 for no edge\n");

   
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\n Enter the source vertex: ");
    scanf("%d", &v);

   
    for (i = 1; i <= n; i++) {
        s[i] = 0;  
        d[i] = c[v][i];  
    }
    d[v] = 0;  
    s[v] = 1;  

   
    for (k = 2; k <= n; k++) {
        min = 999;
        
        
        for (i = 1; i <= n; i++) {
            if ((s[i] == 0) && (d[i] < min)) {
                min = d[i];
                u = i;
            }
        }
        
     
        s[u] = 1;

      
        for (i = 1; i <= n; i++) {
            if (s[i] == 0) {
                if (d[i] > (d[u] + c[u][i])) {
                    d[i] = d[u] + c[u][i];
                }
            }
        }
    }

   
    printf("\n The shortest distance from %d is:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d --> %d = %d\n", v, i, d[i]);
    }
}


OUTPUT

Enter the no. of vertices: 5
Enter the cost adjacency matrix:
Enter 999 for no edge:
999 7 3 999 999
7 999 2 5 4
3 2 999 4 999
999 5 4 999 6
999 4 999 6 999
Enter the source vertex: 1
The shortest distance from 1 is:
1 --&gt; 1 = 0
1 --&gt; 2 = 5
1 --&gt; 3 = 3
1 --&gt; 4 = 7
1 --&gt; 5 = 9
