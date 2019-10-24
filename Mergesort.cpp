#include<iostream>
#include<string>
using namespace std;
class Word{
	public:
char wd[100],meaning[100];
Word(){
		cout<<"Enter the Word:\n";
		cin>>wd;
		cout<<"Enter the meaning:\n";
		cin>>meaning;
		
	}
	void Merge( int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k ;
	char temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (wd[i] < wd[j])
		{
			temp[k] = wd[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = wd[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = wd[i];
		k++;
		i++;   
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = wd[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		wd[i] = temp[i-low];
	}
}

// A function to split array into two parts.
void MergeSort( int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		// Split the data into two half.
		MergeSort( low, mid);
		MergeSort( mid+1, high);

		// Merge them to get sorted output.
		Merge(low, high, mid);
	}
}
};
class dictionary{
	public:
	Word a[3];
	
	
};	
// A function to merge the two half into a sorted data.


 


int main()
{
	int n, i;
	/*cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;*/

	dictionary d;
	//for (i = 0; i < n; i++)
	d.a[0].MergeSort( 0, n-1);

	// Printing the sorted data.
	cout<<"\nSorted Data \n";
	for (i = 0; i < n; i++)
        cout<<"->"<<d.a[i].wd<<endl;

	return 0;
}
