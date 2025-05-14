//C program to implement topological sort using DFS
#include &lt;stdio.h&gt;
int n, a[10][10], res[10], s[10], top = 0;
void dfs(int, int, int[][10]);
void dfs_top(int, int[][10]);
int main()
{
printf(&quot;Enter the no. of nodes&quot;);
scanf(&quot;%d&quot;, &amp;n);
int i, j;
for (i = 0; i &lt; n; i++) {
for (j = 0; j &lt; n; j++) {
scanf(&quot;%d&quot;, &amp;a[i][j]);
}
}
dfs_top(n, a);
printf(&quot;Solution: &quot;);
for (i = n - 1; i &gt;= 0; i--) {
printf(&quot;%d &quot;, res[i]);
}
return 0;
}
void dfs_top(int n, int a[][10]) {
int i;
for (i = 0; i &lt; n; i++) {
s[i] = 0;
}
for (i = 0; i &lt; n; i++) {
if (s[i] == 0) {
dfs(i, n, a);
}
}
}
void dfs(int j, int n, int a[][10]) {
s[j] = 1;
int i;
for (i = 0; i &lt; n; i++) {
if (a[j][i] == 1 &amp;&amp; s[i] == 0) {
dfs(i, n, a);
}
}
res[top++] = j;
}




##############OUTPUT###########
Enter the no. of nodes6
0 0 1 1 0 0
0 0 0 1 1 0
0 0 0 1 0 1
0 0 0 0 0 1
0 0 0 0 0 1
0 0 0 0 0 0
Solution: 1 4 0 2 3 5
