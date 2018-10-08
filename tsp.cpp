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
	return (ans);
}

float prob(float h,float t)
{
	float ans=1+exp(h/t);
	ans=1/ans;
	// if(ans>0.4)
	// cout<<h<<"lol"<<t<<"lol"<<ans<<endl;
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

    // for(int i=0;i<cnum;i++)
    // {
    // 	tour.push_back(i);
    // }
    
    vector <bool> pushed(cnum,false);
    // int fir=rand()%cnum;
    // pushed[fir]=1;
    for(int j=0;j<cnum;)
    {
    	int fir=rand()%cnum;
    	if(!pushed[fir])
    	{
    		pushed[fir]=1;
    		tour.push_back(fir);
    		j++;
    	}
    }

    // vector <bool> pushed(cnum,false);
    // int fir=0;
    // pushed[fir]=1;
    // tour.push_back(fir);
    // for(int i=0;i<cnum-1;i++)
    // {
    // 	float min=99999999999;
    // 	int index;
    // 	for(int j=0;j<cnum;j++)
    // 	{
    // 		if(adj[tour[i]][j]<min && !pushed[j])
    // 		{
    // 			min=adj[tour[i]][j];
    // 			index=j;
    // 		}
    // 	}
    // 	pushed[index]=1;
    // 	tour.push_back(index);
    // }
    float costmin=cost(tour),costf;

    float costdiff=1000;
    // float t=10000;
    for(float t=99;t>=0.00001;t*=0.9999995)
    // for(int s=0;s<10;s++)
    {
  
    	// int s1=rand()%(cnum-2)+1;
    	// int s2=rand()%(cnum-2)+1;

    	int s1=rand()%cnum;
    	int s2=rand()%cnum;
    	if(s1>s2)
    	{
    		int temp=s1;
    		s1=s2;
    		s2=temp;
    	}
    	if(s1!=s2)
    	{
    		// cout<<s1<<" "<<s2<<endl;
    		vector<int> tour2(s2-s1+1);
    		copy(tour.begin()+s1,tour.begin()+s2+1,tour2.begin());
    		// printtour(tour2);
    		reverse(tour2.begin(),tour2.end());
    		vector<int> tour3(tour);
    		// tour3[s1+1]=tour3[s2];
    		copy(tour2.begin(),tour2.end(),tour3.begin()+s1);
    		// printtour(tour3);
    		// printtour(tour);
    		costf=cost(tour3);

    		// swap(tour[s1],tour[s2]);
    		// int temp=tour2[s1];
    		// vector<int> sl=slice(tour)
    		// tour2[s1]=tour2[s2];
    		// tour2[s2]=temp;
    		// costf=cost(tour2);
    		if(costf<costmin)
    		{
    			costmin=costf;
    			tour.swap(tour3);
    			cout<<cost(tour)<<endl;	
    			// printtour(tour);
    		}
    		else
    		{
    			float p=prob(-(costmin-costf),t);
    			if(p>0.3)
    			{
    				costmin=costf;
    			    tour.swap(tour3);
    			    cout<<cost(tour)<<endl;	
    			    // printtour(tour);

    			}
    		// 	// t-=0.000001;
    		// }
            tour2.clear();
            tour3.clear();
    		
    	}
    }
    }
}