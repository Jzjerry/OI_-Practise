#include<stdio.h>

int out[100010][2]={0};
int num[100010][2]={0};
int ab=0;
int cp=0;

void merge(int a[100010][2],int left,int mid,int right)
{
	int i=left,j=mid+1;
	int n=mid,m=right;
	int k=0;
	
	while(i<=n && j<=m)
	{
		if(a[i][0]>a[j][0])
		{
            cp+=n-i+1;
            cp%=99999997;
			out[k][ab]=a[j][0];
			num[k][ab]=a[j][1];
			k++,j++;
		}
		else
		{
			out[k][ab]=a[i][0];
			num[k][ab]=a[i][1];
			k++,i++;
		}
	}
	while(i<=n)
	{
		out[k][ab]=a[i][0];
		num[k][ab]=a[i][1];
		k++,i++;
	}
	while(j<=m)
	{
		out[k][ab]=a[j][0];
		num[k][ab]=a[j][1];
		k++,j++;
	}
	for(j=0;j<k;j++)
	{
		a[left+j][0]=out[j][ab];
		a[left+j][1]=num[j][ab];
	}
}

void sort(int ip[100010][2],int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		sort(ip,left,mid);
		sort(ip,mid+1,right);
		merge(ip,left,mid,right);
	}
}

int main()
{
	int left,right;
	int mid;
	int len;
	int i;
	int a[100010][2]={0};
	int b[100010][2]={0};
	
	
	scanf("%d",&len);
	for(i=0;i<len;i++)
	{
		scanf("%d",&a[i][0]);
		a[i][1]=i;
	}
	for(i=0;i<len;i++)
	{
		scanf("%d",&b[i][0]);
		b[i][1]=i;
	}
	

	left=0;
	right=len-1;

	
	sort(a,left,right);
	ab++;
	sort(b,left,right);
	for(i=0;i<len;i++)
	{         
         a[i][0]=b[i][1];
    }
    sort(a,left,right);
	cp=0;
	for(i=0;i<len;i++)
	{
         a[i][0]=a[i][1];
    }
    sort(a,left,right);
    printf("%d",cp);
	return 0;
}
