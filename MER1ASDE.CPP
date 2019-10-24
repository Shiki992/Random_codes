#include<iostream.h>
#include<conio.h>

/*Suppose A, B, C are arrays of integers of size M, N, and M + N respectively.
  The numbers in array A appear in ascending order while the numbers in array B appear in descending order.
  Write a user defined function in C++ to produce third array C by merging arrays A and B in ascending order.
  Use A, B and C as arguments in the function.   */

void Merge(int A[], int B[], int C[], int N, int M, int &K);


int main()
{
	int A[100], B[100], C[200],i,n,m,k;

	cout<<"\nEnter number of elements you want to insert in first array ";
	cin>>n;

	cout<<"Enter element in ascending order\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter element "<<i+1<<":";
		cin>>A[i];
	}

	cout<<"\nEnter number of elements you want to insert in second array ";
	cin>>m;

	cout<<"Enter element in descending order\n";
	for(i=0;i<m;i++)
	{
		cout<<"Enter element "<<i+1<<":";
		cin>>B[i];
	}

	Merge(A,B,C,n,m,k);

	cout<<"\nThe Merged Array in Ascending Order"<<endl;
	for(i=0;i<k;i++)
	{
		cout<<C[i]<<" ";
	}
	getch();
	return 0;
}


void Merge(int A[], int B[], int C[], int N, int M, int &K)
{
	int I=0, J=M-1;
	K=0;

	while (I<N && J>=0)
	{
		if (A[I]<=B[J])
			C[K++]=A[I++];
		else if (A[I]>=B[J])
			C[K++]=B[J--];
		else
		{
			C[K++]=A[I++];
			J--;
		}
	}

	for (int T=I;T<N;T++)
		C[K++]=A[T];
	for (T=J;T>=0;T--)
		C[K++]=B[T];
}