#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void read_input(){
  #ifndef ONLINE_JUDGE
  freopen("a.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}



struct intersection
{
	vector <string> in;
	vector <int> id;
};


struct ans{
	int id;
	vector<pair<string,int>> sections;
};


void simulation(int I,int D,vector<pair<int,vector<string>>> &cars,map<string,vector<int>> &streets){
    vector <intersection> intersections(I);
    
    vector <ans> solution;

    int cur_time=0;
    for (int i=0;i<cars.size();i++){
    	intersections[i].id.push_back(streets[cars[i].second[0]][1]);
    	intersections[i].in.push_back(cars[i].second[0]);//  string pushed
    }
  
    while(cur_time<D){
    	for (int i=0;i<intersections.size();i++){
    		
    	}
    	cur_time++;
    }

    print_answer(solution);

}

void print_answer(vector <ans> &solution){
    cout<<solution.size()<<"\n";
    for(auto itr= solution.begin();itr!=solution.end();itr++){
        cout<<itr->id<<"\n";
        cout<<itr->sections.size()<<"\n";
        for(auto itr2 = itr->sections.begin();itr2!=itr->sections.end()){
            cout<<itr2->first<<" ";
            cout<<itr2->second<<"\n";
        }
    }
}


vector<int> time_calc(map<string,vector<int>> &streets, vector<pair<int,vector<string>>> &cars){
    vector <int> timetaken(cars.size());

    for(int i=0;i<cars.size();i++){
        int temp=(cars[i].first-1);
        vector <string> path=cars[i].second;
        for (int i=1;i<path.size();i++){
            temp+=streets[path[i]][2];
        }
        timetaken[i]=temp;
    }
    return timetaken;
}

int main(){
    read_input();
    int D,I,S,V,F;
    cin>>D>>I>>S>>V>>F;
    int temps = S,tempv=V;
    map<string,vector<int>> streets;
    vector<pair<int,vector<string>>> cars;
    vector<pair<pair<int,int>,vector<pair<string,int>>>> answer;
    while(temps--){//input streets
        int B,E,L;
        string name;
        cin>>B>>E>>name>>L;
        vector<int> temp;
        temp.push_back(B);
        temp.push_back(E);
        temp.push_back(L);
        streets.insert({name,temp});
    }


    while(tempv--){//input car paths
        int P;
        cin>>P;
        vector<string> names;
        int temp = P;
        while(temp--){
            string name;
            cin>>name;
            names.push_back(name);
        }
        cars.push_back(make_pair(P,names));
    }
    

    auto timetaken = time_calc(streets,cars);
    simulation(I,D,cars,streets);
    return 0;
}


/**     checking output remove befor submission
    for (auto itr = streets.begin(); itr != streets.end(); ++itr) {  
        cout<<itr->first;
        cout<<" ";
        for(auto itr2 = itr->second.begin();itr2!=itr->second.end();itr2++){
            cout<<*itr2<<" ";
        }
        cout<<"\n";
    } 
   
    cout<<"ok input";

    for (auto itr = cars.begin(); itr != cars.end(); ++itr) {  
        cout<<itr->first;
        cout<<" ";
        for(auto itr2 = itr->second.begin();itr2!=itr->second.end();itr2++){
            cout<<*itr2<<" ";
        }
        cout<<"\n";
    } 

**/
