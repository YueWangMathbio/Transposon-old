#include<iostream>
#include<fstream>
using namespace std;
int r[51][51],p[51][51];//��������+1		!!
int main()
{
	int m=5,n=50,max=51,min=1,head=1,tail=50;//min��С�����ţ�max��������+1��m������n������head��һ������ı�ţ�tail���һ������ı��
	int a[5][50];//m=5����������n=50��ÿ�����Ļ������		!!
	int i,j,k;
	for(i=0;i<n;i++)//�������룬���巽ʽ�����ݸ�ʽ�йء�		
		for(j=0;j<m;j++)	
			cin>>a[j][i];

	fstream f;
	
	for(i=0;i<max;i++)	
		for(j=0;j<max;j++)
		{
			r[i][j]=0;
			p[i][j]=-1;
		}
		//��ʼ����r[i][j]=-1����ÿ�����л���i���ڻ���j֮ǰ���֣������Ϊi��j�ľ�����-1.���������������r[i][j]=0�������Ϊi��j����ͨ
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
			for(j=min;j<max;j++)	//		//��һ�ε���������Floyd�㷨�ҵ�head��tail֮������·����Ҳ������head��ʼ��tail���������������
			{
				if(r[i][j]<0&&r[i][k]<0&&r[k][j]<0&&r[i][j]>r[i][k]+r[k][j]&&i!=k&&j!=k&&i!=j)
				{
					r[i][j]=r[i][k]+r[k][j];
					p[i][j]=p[k][j];					
				}
			}//��δ�����㷨�ϻ������Ż�
	
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

	ofstream outfile("a.txt");//�ڳ��������ļ�Ŀ¼������"a.txt"��������������ȥ

	for(i=0;i<=-r[head][tail];i++)
		outfile<<a[1][i]<<endl;

//	cout<<"total length "<<1-r[head][tail]<<endl;//���������ܳ�


	return 0;
}