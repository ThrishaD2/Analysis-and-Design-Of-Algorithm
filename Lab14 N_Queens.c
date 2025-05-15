#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;math.h&gt;
int x[20],count=1;
void queens(int,int);
int place(int,int);
void main()
{
int n,k=1;
clrscr();
printf(&quot;\n enter the number of queens to be placed\n&quot;);
scanf(&quot;%d&quot;,&amp;n);
queens(k,n);
}
void queens(int k,int n)
{
int i,j;
for(j=1;j&lt;=n;j++)
{
if(place(k,j))
{
x[k]=j;
if(k==n)
{
printf(&quot;\n %d solution&quot;,count);
count++;
for(i=1;i&lt;=n;i++)
printf(&quot;\n \t %d row &lt;---&gt; %d
column&quot;,i,x[i]);
getch();
}
else
queens(k+1,n);
}
}
}
int place(int k,int j)
{
int i;
for(i=1;i&lt;k;i++)
if((x[i]==j) || (abs(x[i]-j))==abs(i-k))
return 0;
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
