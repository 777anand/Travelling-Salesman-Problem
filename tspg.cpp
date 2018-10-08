#include <bits/stdc++.h>

using namespace std;

float adj[10000][10000];

vector<vector<int>>xy;
float cost(vector<int>tour)
{
	float ans=0;
	for(int i=0; i<tour.size()-1;i++)
	{
		ans+=adj[tour[i]][tour[i+1]];

	}
	ans+=adj[tour[tour.size()-1]][tour[0]];
	return ans;
}

void printtour(vector <int> tour)
{
	for(int i=0;i<tour.size();i++)
	{
		cout<<tour[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	srand(time(NULL));
	long int cnum;
	bool euc;
	string temp;
	float temp1,temp2;
	cin>>temp;
	if(temp=="euclidean")
		euc=true;
	else
		euc=false;
	cin>>cnum;
	for(int i=0;i<cnum;i++)
	{
		cin>>temp1>>temp2;
		vector<int> temp;
		temp.push_back(temp1);
		temp.push_back(temp2);
		
		xy.push_back(temp);
	}
	for(int i=0;i<cnum;i++)
		for(int j=0;j<cnum;j++)
		{
			cin>>adj[i][j];
		}
    
    vector <int> tour;
    vector <bool> pushed(cnum,false);
    int fir=rand()%cnum;
    pushed[fir]=1;
    tour.push_back(fir);
    for(int i=0;i<cnum-1;i++)
    {
    	float min=99999999999;
    	int index;
    	for(int j=0;j<cnum;j++)
    	{
    		if(adj[tour[i]][j]<min && !pushed[j])
    		{
    			min=adj[tour[i]][j];
    			index=j;
    		}
    	}
    	pushed[index]=1;
    	tour.push_back(index);
    }
    float costmin=cost(tour),costf;

    float costdiff=1000;
    while(true)
    {

    	int s1=rand()%cnum;
    	int s2=rand()%cnum;
    	if(s1!=s2)
    	{
    		vector<int> tour2;
    		tour2=tour;
    		int temp=tour2[s1];
    		tour2[s1]=tour2[s2];
    		tour2[s2]=temp;
    		costf=cost(tour2);
    		if(costf<costmin)
    		{
    			costmin=costf;
    			tour.swap(tour2);
    			cout<<cost(tour)<<endl;	
    			// printtour(tour);
    		}
    		
    	}
    }
}