#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k,output;
cin>>n;
vector<pair<int ,int>>v(n);
for(int i =0 ; i<n; i++)
{
  cin>>k;
  v[i].first=k; //deadline 
}
for(int i =0 ; i<n; i++)
{
  cin>>k;
  v[i].second=k;  //profit
}

output=0;
auto compare = [](const pair<int , int >&a,const pair<int , int >&b)
{
    
     double s  = (double)a.second/a.first;
    double r  = (double)b.second/b.first;
    if(a.first==b.first)return s>r;
    else return a.first<b.first;
};
sort(v.begin(),v.end(),compare);
for(int i =0 ; i<n; i++)
{
  output+=v[i].second;
  while(v[i].first==v[i+1].first){i++;}
  
}
cout<<output<<"\n";
  return 0;
}