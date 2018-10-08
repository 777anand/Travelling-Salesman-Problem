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

    for(int i=0;i<cnum;i++)
    {
    	tour.push_back(i);
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
    for(float t=1400;t>=0.000001;t*=0.99999)
    // for(int s=0;s<10;s++)
    {
  
    	// int s1=rand()%(cnum-2)+1;
    	// int s2=rand()%(cnum-2)+1;

    	int s1=rand()%(cnum-2) +1 ;
    	int s2=rand()%(cnum-2) +1 ;
        int s3=rand()%(cnum-2) +1 ;
    	if(s1>s2)
    	{
    		int temp=s1;
    		s1=s2;
    		s2=temp;
    	}
        if(s2>s3)
        {
            int temp=s2;
            s2=s3;
            s3=temp;
        }
        if(s1>s2)
        {
            int temp=s1;
            s1=s3;
            s2=temp;
        }
    	if(s1!=s2&&s2!=s3&&s3!=s1 )
    	{
            vector<int> tour3;
    		vector <int>seg1,seg2,seg3;
    		for(int w=s1;w<s2;w++)
                seg1.push_back(tour[w]);
            for(int w=s2;w<s3;w++)
                seg2.push_back(tour[w]);
            for(int w=s3;w<tour.size();w++)
                seg3.push_back(tour[w]);
            for(int w=0;w<s1;w++)
                seg3.push_back(tour[w]);

            float cv1 = adj[seg1[seg1.size() - 1]][seg2[seg2.size() - 1]] + adj[seg2[0]][seg3[seg3.size() - 1]] + adj[seg3[0]][seg1[0]];
            float cv2 = adj[seg1[seg1.size() - 1]][seg3[seg3.size() - 1]] + adj[seg3[0]][seg2[0]] + adj[seg2[seg2.size() - 1]][seg1[0]];
            float cv3 = adj[seg1[seg1.size() - 1]][seg2[0]] + adj[seg3[seg3.size() - 1]][seg2[0]] + adj[seg2[seg2.size() - 1]][seg1[0]];
            float cv4 = adj[seg1[seg1.size() - 1]][seg3[0]] + adj[seg3[seg3.size() - 1]][seg2[seg2.size() - 1]] + adj[seg2[0]][seg1[0]];
            float minC = min(cv1, min(cv2, min(cv3, cv4)));

            if(cv1 == minC){
                tour3.insert(tour3.end(), seg1.begin(), seg1.end());
                tour3.insert(tour3.end(), seg2.rbegin(), seg2.rend());
                tour3.insert(tour3.end(), seg3.rbegin(), seg3.rend());
            }
            else
            if(cv2 == minC){
                tour3.insert(tour3.end(), seg1.begin(), seg1.end());        
                tour3.insert(tour3.end(), seg3.rbegin(), seg3.rend());
                tour3.insert(tour3.end(), seg2.begin(), seg2.end());
            }
            else
            if(cv3 == minC){
                tour3.insert(tour3.end(), seg1.begin(), seg1.end());
                tour3.insert(tour3.end(), seg3.begin(), seg3.end());
                tour3.insert(tour3.end(), seg2.begin(), seg2.end());
            }
            else{
                tour3.insert(tour3.end(), seg1.begin(), seg1.end());
                tour3.insert(tour3.end(), seg3.begin(), seg3.end());
                tour3.insert(tour3.end(), seg2.rbegin(), seg2.rend());
            }
            
            costf=cost(tour3);
    		
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
    			if(p>0.25)
    			{
    				costmin=costf;
    			    tour.swap(tour3);
    			    cout<<cost(tour)<<endl;	
    			    // printtour(tour);

    			}
    			// t-=0.000001;
    		}
            // tour2.clear();
            tour3.clear();
    		
    	}
    }
}