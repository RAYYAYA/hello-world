/*DIJKSTRA
����������������Ȩ����ͼ��������ͼ�ĵ�Դ���·��
�˴�������ͼΪ��
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
        cout<<endl<<"��"<<i<<endl;
        int mark=-1,minidis=INF;
        for(int j=1;j<=n;j++)
        {
            if(dis[j]<minidis && !vis[j])
            {
                mark=j;
                minidis=dis[j];
                cout<<"����"<<mark<<" "<<dis[j]<<endl;
            }
        }
        cout<<"mark"<<mark<<" dis "<<minidis<<endl;
        vis[mark]=1;
        for(int j=1;j<=n;j++) //���������·������
        {
            if(!vis[j])
                dis[j]=min(dis[j],dis[mark]+g[mark][j]);
        }
    }
    //cout<<"��"<<s<<"Ϊ���ĵ�Դ���·"<<endl;
    cout<<"��1Ϊ���ĵ�Դ���·"<<endl;
    for(int i=1;i<=n;i++)
        cout<<i<<" :"<<dis[i]<<endl;
}
int main()
{
    printf("������ͼ�Ľ�����ͱ���:\n");
    scanf("%d%d",&n,&m);
    memset(g,INF,sizeof(g));
    printf("������ÿ���ߵ�����յ�Ȩ��:\n");
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
