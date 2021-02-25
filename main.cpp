#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;

void read_input(){
  #ifndef ONLINE_JUDGE
  freopen("a.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
}

int main(){
    read_input();
    int D,I,S,V,F;
    cin>>D>>I>>S>>V>>F;
    int temps = S,tempv=V;
    map<string,vector<int>> streets;
    vector<pair<int,vector<string>>> cars;
    
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
    
    
    return 0;
}
