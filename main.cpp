#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

    while(temps--){//streets
        int B,E,L;
        string name;
        cin>>B>>E>>name>>L;
        vector<int> temp;
        temp.push_back(B);
        temp.push_back(E);
        temp.push_back(L);
        streets.insert({name,temp})
    }
    while(tempv--){//car paths

    }
    return 0;
}
