#include<stdio.h>
void mergesort(int a[],int b,int c);
void merge(int a[],int l1,int u1, int u2);
int main()
{
	int a[100];
	int n;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int i;
	printf("Enter the array:\n");
	for (i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}

	mergesort(a,0,n);
	
	printf("Sorted array is:\n");
	for (i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}

void mergesort(int a[], int l, int n)
{
	if(l<=n)
	{
		int mid=l+(n-l)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,n);
		merge(a,l,mid,n);
	}
}

void merge(int a[],int l,int m,int n)
{
	int n1 = m - l + 1;
    int n2 = n - m;
	int L[n1],R[n2];

	int i,j,k;
	
	for (i = 0; i < n1; i++)
       { L[i] = a[l + i];}
    for (j = 0; j < n2; j++)
     { R[j] = a[l + 1 + j];}
        
        i=0,j=0;k=l;
        while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
  
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
