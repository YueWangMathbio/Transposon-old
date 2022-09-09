#include<iostream>
#include<fstream>
using namespace std;
int r[51][51],p[51][51];//最大基因编号+1		!!
int main()
{
	int m=5,n=50,max=51,min=1,head=1,tail=50;//min最小基因编号，max最大基因编号+1，m链数，n链长，head第一个基因的编号，tail最后一个基因的编号
	int a[5][50];//m=5是五条链，n=50是每条链的基因个数		!!
	int i,j,k;
	for(i=0;i<n;i++)//数据输入，具体方式和数据格式有关。		
		for(j=0;j<m;j++)	
			cin>>a[j][i];

	fstream f;
	
	for(i=0;i<max;i++)	
		for(j=0;j<max;j++)
		{
			r[i][j]=0;
			p[i][j]=-1;
		}
		//初始化，r[i][j]=-1则在每条链中基因i都在基因j之前出现，可理解为i和j的距离是-1.其它各种情况都是r[i][j]=0，可理解为i和j不连通
	for(i=0;i<n;i++)		
		for(j=i+1;j<n;j++)	
			r[a[0][i]][a[0][j]]=-1;	
	for(i=0;i<n;i++)	
		for(j=i+1;j<n;j++)
			for(k=0;k<m;k++)
				r[a[k][j]][a[k][i]]=0;
	for(i=0;i<max;i++)
		for(j=0;j<max;j++)
			if(r[i][j]==-1)
				p[i][j]=i;
	for(i=0;i<max;i++)
		p[i][i]=i;
			



	for(k=min;k<max;k++)		
		for(i=min;i<max;i++)
			for(j=min;j<max;j++)	//		//这一段的作用是用Floyd算法找到head到tail之间的最短路径，也就是以head开始，tail结束的最长公共子列
			{
				if(r[i][j]<0&&r[i][k]<0&&r[k][j]<0&&r[i][j]>r[i][k]+r[k][j]&&i!=k&&j!=k&&i!=j)
				{
					r[i][j]=r[i][k]+r[k][j];
					p[i][j]=p[k][j];					
				}
			}//这段代码从算法上还可以优化
	
	k=p[head][tail];
	i=-r[head][tail];
	a[1][i]=tail;
	i--;
	while(k!=head)
	{
		a[1][i]=k;

		
		i--;
		k=p[head][k];
	}

	ofstream outfile("a.txt");//在程序所在文件目录下生成"a.txt"，并将结果输入进去

	for(i=0;i<=-r[head][tail];i++)
		outfile<<a[1][i]<<endl;

//	cout<<"total length "<<1-r[head][tail]<<endl;//不动序列总长


	return 0;
}