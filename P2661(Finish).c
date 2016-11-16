#include<stdio.h>

int link[3][200010]={0};//link[1]ºó¼Ì£¬link[2]Èë¶È//
int min=9999999;
int count=0;
int flag[200010]={0};
int temp;

void del(int i)
{
	int j;
	link[2][link[1][i]]--;
	j=link[1][i];
	link[1][i]=0;
	if(link[2][j]==0)
	{
	del(j);
    }
}

void find(int i)
{
	count=0;
	while(flag[i]!=1)
	{	
		flag[i]=1;
		temp=link[1][i];
		link[1][i]=0;
		i=temp;
		count++;
    }
    if(min>count)
    {
    	min=count;
	}
}

int main()
{
	int i,j;
	int n;
	int round[200010]={0};
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&link[1][i]);
		link[2][link[1][i]]++;
	}
	
	for(i=1;i<=n;i++)
	{
		if(link[2][i]==0)
		{
			del(i);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(link[1][i]!=0)
		{
			find(i);
		}
	}
	
	printf("%d",min);
	
	return 0;
}
