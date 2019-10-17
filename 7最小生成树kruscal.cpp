//Ҫ�ȶԱ�����˳���Ҷ˵��ǲ�ͬ��ͨ�����ı�
//�ò��鼯findx()ʵ������ͨ������sortֱ������
//������ϡ��ͼ��ֱ�Ӵ�� node(s,e,len)

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
vector <edge> ve; //��¼����ı�
int pre[maxn];  //��¼���Ƚڵ�

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
int unit(int x,int y) //�ж������������Ƚ��
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
    sort(e,e+m);  //�ȶ����еı�����
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
        cout<<"��С������Ȩֵ֮����"<<sum<<endl;
    else
        cout<<"û����С������"<<endl;

}
int travel() //�������м���ı�
{
    cout<<"��������ѡ��ı�"<<endl;
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
��С��������Ȩֵ��Ϊ12
����ı�Ϊ��
3<->5 ����Ϊ1
3<->6 ����Ϊ1
1<->6 ����Ϊ2
2<->5 ����Ϊ2
2<->4 ����Ϊ6

*/
