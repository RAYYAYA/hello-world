/*DIJKSTRA
广度优先搜索解决赋权有向图或者无向图的单源最短路径
此处以无向图为例
*/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<map>
using namespace std;
const int maxn=1050;
const int INF=0x3f3f3f3f;
int dis[maxn],g[maxn][maxn];
bool vis[maxn];
int n,m;

bool dij( )
{
    for(int i=1;i<=n;i++)
        dis[i]=(i==1)?0:INF;

    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        cout<<endl<<"点"<<i<<endl;
        int mark=-1,minidis=INF;
        for(int j=1;j<=n;j++)
        {
            if(dis[j]<minidis && !vis[j])
            {
                mark=j;
                minidis=dis[j];
                cout<<"考虑"<<mark<<" "<<dis[j]<<endl;
            }
        }
        cout<<"mark"<<mark<<" dis "<<minidis<<endl;
        vis[mark]=1;
        for(int j=1;j<=n;j++) //加入点后更新路径长度
        {
            if(!vis[j])
                dis[j]=min(dis[j],dis[mark]+g[mark][j]);
        }
    }
    //cout<<"以"<<s<<"为起点的单源最短路"<<endl;
    cout<<"以1为起点的单源最短路"<<endl;
    for(int i=1;i<=n;i++)
        cout<<i<<" :"<<dis[i]<<endl;
}
int main()
{
    printf("请输入图的结点数和边数:\n");
    scanf("%d%d",&n,&m);
    memset(g,INF,sizeof(g));
    printf("请输入每条边的起点终点权重:\n");
    int s,e,l;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&s,&e,&l);
        g[s][e]=g[e][s]=l;
    }
    dij(  );

}
/*
6 8
1 3 10
1 5 30
1 6 100
2 3 5
3 4 50
4 6 10
5 6 60
5 4 20
*/
