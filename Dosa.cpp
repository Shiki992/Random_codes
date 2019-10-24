
#include <iostream>
#include <stdlib.h>
using namespace std;
int arr[100],n;
void init()
{

    cout<<"Enter the number of Dosas:\n";
    cin>>n;
    cout<<"The radii of the Dosas are as follows:\n";
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
        cout<<arr[i]<<endl;
    }
}
void flip(int i)
{
	int temp, start = 0;
	while (start < i)
	{
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		start++;
		i--;
	}
}

// Returns index of the maximum element in arr
int findMax(int n)
{
int mi, i;
for (mi = 0, i = 0; i < n; ++i)
	if (arr[i] > arr[mi])
			mi = i;
return mi;
}

// A utility function to print n array of size n
void printArray(int c)
{
	for (int i = 0; i < c; ++i)
		cout<< arr[i]<<endl;
}

// The main function that sorts given array using flip operations
int DosaSort()
{
    int flps=0;
	// Start from the complete array and one by one reduce current size by one

	for (int csize = n; csize > 1; --csize)
	{
		// Find index of the maximum element in arr
		int mi = findMax(csize);

		// Move the maximum element to end of current array if it's not already at the end
		if (mi != csize-1)
		{
		    flps++;
			// To move at the end, first move maximum number to beginning
			flip(mi);
			cout<<"Flip: "<<flps<<" First flip array:\n";
			printArray(csize);

			// Now move the maximum number to end by reversing current array
			flip(csize-1);
			cout<<"Flip: "<<flps<<" Second flip array:\n";
			printArray(csize);

		}
	}
	return flps;
}


int main()
{
    init();
    int flips;
	flips=DosaSort();

	cout<<"Sorted Dosas \n";
	printArray(n);
	cout<<"The no. of total flips it took were: "<<flips<<endl;

	return 0;
}
