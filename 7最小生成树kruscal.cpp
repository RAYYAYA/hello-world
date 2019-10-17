//要先对边排序，顺序找端点是不同联通分量的边
//用并查集findx()实现求连通分量，sort直接排序
//适用于稀疏图，直接存边 node(s,e,len)

#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn=1050;
struct edge{
  int s,e,len;
  bool operator<(const edge b)const
  {
      return len<b.len;
  }
};
edge e[maxn];
int n,m;
vector <edge> ve; //记录纳入的边
int pre[maxn];  //记录祖先节点

int findx(int x)
{
    if(pre[x]!=x)
        pre[x]=findx(pre[x]);
    return pre[x];
}
int init()
{
    for(int i=0;i<n;i++)
        pre[i]=i;
}
int unit(int x,int y) //判断两个结点的祖先结点
{
   int m=findx(x);
   int n=findx(y);
   if(m!=n)
   {
       pre[m]=n;
       return true;
   }
   return false;
}

int kruskal()
{
    sort(e,e+m);  //先对所有的边排序
    int num=n,sum=0;
    for(int i=0;i<m&&num>1;i++)
    {
        if(unit(e[i].s,e[i].e))
        {
            ve.push_back(e[i]);
            sum+=e[i].len;
            num--;
        }
    }
    if(num==1)
        cout<<"最小生成树权值之和是"<<sum<<endl;
    else
        cout<<"没有最小生成树"<<endl;

}
int travel() //遍历所有加入的边
{
    cout<<"遍历所有选择的边"<<endl;
    for(int i=0;i<ve.size();i++)
        cout<<ve[i].s<<"<->"<<ve[i].e<<" len:"<<ve[i].len<<endl;

}


int main()
{
    scanf("%d%d",&n,&m);
    init();
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&e[i].s,&e[i].e,&e[i].len);
    }
    kruskal();
    travel();
    return 0;
}

/*
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3
最小生成树的权值和为12
纳入的边为：
3<->5 长度为1
3<->6 长度为1
1<->6 长度为2
2<->5 长度为2
2<->4 长度为6

*/
