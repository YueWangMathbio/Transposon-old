#include<iostream>
#include<fstream>
using namespace std;
int r[7][7],p[7][7];//1202=��������+2		!!
int main()
{
	int m=3,n=5,max=7;//max��������+2��m������n����		!!

	int a[3][7];//15������=m��1002������+2		!!
	int b[5];//����	!!		�治������
	int c[5];//����		!!	��ת����
	int i,j,k;
	int lo=0,min=0;
	int head=0,tail=max-1;
	int tr=0;
	int s=0;
	for(i=1;i<=n;i++)//�������룬���巽ʽ�����ݸ�ʽ�йء�		
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
		//��ʼ����r[i][j]=-1����ÿ�����л���i���ڻ���j֮ǰ���֣������Ϊi��j�ľ�����-1.���������������r[i][j]=0�������Ϊi��j����ͨ
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
			for(j=min;j<max;j++)	//		//��һ�ε���������Floyd�㷨�ҵ�head��tail֮������·����Ҳ������head��ʼ��tail���������������
			{
				if(r[i][j]<0&&r[i][k]<0&&r[k][j]<0&&r[i][j]>r[i][k]+r[k][j]&&i!=k&&j!=k&&i!=j)
				{
					r[i][j]=r[i][k]+r[k][j];//rij��i��j�����·��
					p[i][j]=p[k][j];					//pij��i��j�����·���һ�������ĵ�
				}
			}//��δ�����㷨�ϻ������Ż�
	
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
		ofstream outfile("a.txt");//�ڳ��������ļ�Ŀ¼������"a.txt"��������������ȥ
	
		for(i=1;i<=lo;i++)
			outfile<<b[i]<<endl;
//		ofstream outfile("t.txt");//�ڳ��������ļ�Ŀ¼������"t.txt"��������������ȥ
		outfile<<endl;
		for(i=1;i<=tr;i++)
			outfile<<c[i]<<endl;
	}
//	cout<<"total length "<<1-r[head][tail]<<endl;//���������ܳ�


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
		//��ʼ����r[i][j]=-1����ÿ�����л���i���ڻ���j֮ǰ���֣������Ϊi��j�ľ�����-1.���������������r[i][j]=0�������Ϊi��j����ͨ
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
				for(j=min;j<max;j++)	//		//��һ�ε���������Floyd�㷨�ҵ�head��tail֮������·����Ҳ������head��ʼ��tail���������������
				{
					if(r[i][j]<0&&r[i][k]<0&&r[k][j]<0&&r[i][j]>r[i][k]+r[k][j]&&i!=k&&j!=k&&i!=j)
					{
						r[i][j]=r[i][k]+r[k][j];//rij��i��j�����·��
						p[i][j]=p[k][j];					//pij��i��j�����·���һ�������ĵ�
					}
				}//��δ�����㷨�ϻ������Ż�
		
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
			ofstream outfile("a.txt");//�ڳ��������ļ�Ŀ¼������"a.txt"��������������ȥ
		
			for(i=1;i<=lo;i++)
				outfile<<b[i]<<endl;
		//	ofstream outfile("t.txt");//�ڳ��������ļ�Ŀ¼������"t.txt"��������������ȥ
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