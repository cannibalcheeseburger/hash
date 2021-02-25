#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void read_input(){
  #ifndef ONLINE_JUDGE
  freopen("a.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}


void simulation(int I,map<string,vector<int>> &streets){
    vector<vector<pair<string,int>>> intersections(I);
    

}

void print_answer(vector<pair<pair<int,int>,vector<pair<string,int>>>> &answer){
    cout<<answer.size();//intersections
        for(auto itr = answer.begin();itr!=answer.end();itr++){
            cout<<itr->first.first<<"\n";
            cout<<itr->first.second<<"\n";
            for(int i =0;i<itr->first.second;i++){
                cout<<itr->second[i].first<<" ";
                cout<<itr->second[i].second<<"\n";
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
    simulation(I);
    print_answer(answer);
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
