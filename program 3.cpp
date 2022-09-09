#include<iostream>
#include<fstream>
using namespace std;
int r[7][7],p[7][7];//1202=最大基因编号+2		!!
int main()
{
	int m=3,n=5,max=7;//max最大基因编号+2，m链数，n链长		!!

	int a[3][7];//15是链数=m，1002是链长+2		!!
	int b[5];//链长	!!		存不动基因
	int c[5];//链长		!!	存转座子
	int i,j,k;
	int lo=0,min=0;
	int head=0,tail=max-1;
	int tr=0;
	int s=0;
	for(i=1;i<=n;i++)//数据输入，具体方式和数据格式有关。		
		for(j=0;j<m;j++)	
			cin>>a[j][i];
	for(j=0;j<m;j++)
	{
		a[j][0]=0;
		a[j][n+1]=max-1;
	}
	for(j=1;j<m;j++)
	{
		k=1;
		while(a[j][k]!=a[0][1])
			k++;
		for(i=0;i<n;i++)
		{
			b[i]=a[j][k];
			if(k==n)
				k=0;
			k++;
		}
		for(i=0;i<n;i++)
		{
			a[j][i+1]=b[i];
		}
	}
	fstream f;
	
	for(j=0;j<m;j++)
	{
		for(i=0;i<max;i++)
			cout<<a[j][i]<<' ';
		cout<<endl;
	}
	for(i=0;i<max;i++)	
		for(j=0;j<max;j++)
		{
			r[i][j]=0;
			p[i][j]=-1;
		}
		//初始化，r[i][j]=-1则在每条链中基因i都在基因j之前出现，可理解为i和j的距离是-1.其它各种情况都是r[i][j]=0，可理解为i和j不连通
	for(i=0;i<max;i++)		
		for(j=i+1;j<max;j++)	
			r[a[0][i]][a[0][j]]=-1;	
	for(i=0;i<max;i++)	
		for(j=i+1;j<max;j++)
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
					r[i][j]=r[i][k]+r[k][j];//rij：i到j的最短路长
					p[i][j]=p[k][j];					//pij：i到j的最短路最后一个经过的点
				}
			}//这段代码从算法上还可以优化
	
	k=p[head][tail];
	i=-r[head][tail];
	if(lo<i-1)
	{
		lo=i-1;
		b[i]=tail;
		cout<<lo<<endl;
		cout<<i<<' '<<b[i]<<endl;
		i--;
		tr=n-lo;
		while(k!=head)
		{
			b[i]=k;
			cout<<i<<' '<<b[i]<<endl;
			
			i--;
			k=p[head][k];
		}
		b[0]=0;
		j=1;
		k=1;
		for(i=1;i<=n;i++)
		{
			if(a[0][j]!=b[i])
			{
				c[k]=a[0][j];
				j++;
				k++;
			}
			else
				j++;
		}
		ofstream outfile("a.txt");//在程序所在文件目录下生成"a.txt"，并将结果输入进去
	
		for(i=1;i<=lo;i++)
			outfile<<b[i]<<endl;
//		ofstream outfile("t.txt");//在程序所在文件目录下生成"t.txt"，并将结果输入进去
		outfile<<endl;
		for(i=1;i<=tr;i++)
			outfile<<c[i]<<endl;
	}
//	cout<<"total length "<<1-r[head][tail]<<endl;//不动序列总长


	s=0;
	while(s<tr)//second part
	{
		for(j=0;j<m;j++)
		{
			k=1;
			while(a[j][k]!=c[s+1])
				k++;
			for(i=0;i<n;i++)
			{
				b[i]=a[j][k];
				if(k==n)
					k=0;
				k++;
			}
			for(i=0;i<n;i++)
			{
				a[j][i+1]=b[i];
			}
		}

		for(i=0;i<max;i++)	
		for(j=0;j<max;j++)
		{
			r[i][j]=0;
			p[i][j]=-1;
		}
		//初始化，r[i][j]=-1则在每条链中基因i都在基因j之前出现，可理解为i和j的距离是-1.其它各种情况都是r[i][j]=0，可理解为i和j不连通
		for(i=0;i<max;i++)		
			for(j=i+1;j<max;j++)	
				r[a[0][i]][a[0][j]]=-1;	
		for(i=0;i<max;i++)	
			for(j=i+1;j<max;j++)
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
						r[i][j]=r[i][k]+r[k][j];//rij：i到j的最短路长
						p[i][j]=p[k][j];					//pij：i到j的最短路最后一个经过的点
					}
				}//这段代码从算法上还可以优化
		
		k=p[head][tail];
		i=-r[head][tail];
		if(lo<i-1)
		{
			lo=i-1;
			b[i]=tail;
			cout<<lo<<endl;
			cout<<i<<' '<<b[i]<<endl;
			i--;
			tr=n-lo;
			while(k!=head)
			{
				b[i]=k;
				cout<<i<<' '<<b[i]<<endl;
				
				i--;
				k=p[head][k];
			}
			b[0]=0;
			j=1;
			k=1;
			for(i=1;i<=n;i++)
			{
				if(a[0][j]!=b[i])
				{
					c[k]=a[0][j];
					j++;
					k++;
				}
				else
					j++;
			}
			ofstream outfile("a.txt");//在程序所在文件目录下生成"a.txt"，并将结果输入进去
		
			for(i=1;i<=lo;i++)
				outfile<<b[i]<<endl;
		//	ofstream outfile("t.txt");//在程序所在文件目录下生成"t.txt"，并将结果输入进去
			outfile<<endl;
			for(i=1;i<=tr;i++)
				outfile<<c[i]<<endl;
			s=0;
		}
		else
			s++;

		
	}
	return 0;
}