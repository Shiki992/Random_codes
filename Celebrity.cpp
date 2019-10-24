#include<iostream>
#include<bits/stdc++.h>
#include <list>
using namespace std;

// Max # of persons in the party
int N;
int noele()
{
    cout<<"How many ppl in the room?\n";
    cin>>N;
    return N;
}

// Person with 2 is celebrity
bool MATRIX[10][10];
void init()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(i==j)
            {
                MATRIX[i][j]=0;
            }
            else{
                MATRIX[i][j]=rand()%2;
            }
        }
    }
    cout<<"the matrix is:\n";
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            cout<<MATRIX[i][j]<<"\t";
        }
        cout<<endl;
    }
}

bool knows(int a, int b)
{
	return MATRIX[a][b];
}

// Returns -1 if celebrity is not present. If present, returns id (value from 0 to n-1).
int findCelebrity(int n)
{
	stack<int> s;
	int C; // Celebrity
	// Push everybody to stack
	for (int i = 0; i < n; i++)
		s.push(i);
	int A = s.top();
	s.pop();
	int B = s.top();
	s.pop();
	while (s.size() > 1)
	{
		if (knows(A, B))
		{
			A = s.top();
			s.pop();
		}
		else
		{
			B = s.top();
			s.pop();
		}
	}
	C = s.top();
	s.pop();
	// Last candidate was not examined, it leads one excess comparison (optimize)
	if (knows(C, B))
		C = B;

	if (knows(C, A))
		C = A;

	// Check if C is actually a celebrity or not
	for (int i = 0; i < n; i++)
	{
		// If any person doesn't know A or A doesn't know any person, return -1
		if ( (i != C) &&
				(knows(C, i) ||
				!knows(i, C)) )
			return -1;
	}

	return C;
}


int main()
{
	int n = 4;
	bool cont=1;
	while(cont==1)
    {
	n=noele();
	init();
	int id = findCelebrity(n);
	id == -1 ? cout << "No celebrity\n" :
			cout << "Celebrity ID " << id<<endl;
    cout<<"Do you want to try again??(1/0)\n";
    cin>>cont;
    }
	return 0;
}
