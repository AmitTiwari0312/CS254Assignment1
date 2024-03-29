#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k,output;
cin>>n;
vector<pair<int ,int>>v(n);
for(int i =0 ; i<n; i++)
{
  cin>>k;
  v[i].first=k; //weight 
}
for(int i =0 ; i<n; i++)
{
  cin>>k;
  v[i].second=k;  //values
}
int wl;

cin>>wl;
output=0;
auto compare = [](const pair<int , int >&a,const pair<int , int >&b)
{
    
     double s  = (double)a.second/a.first;
    double r  = (double)b.second/b.first;
    if(s==r)return a.first< b.first;
    else return s>r;
};
sort(v.begin(),v.end(),compare);
for(int i =0 ; i<n; i++)
{
  if(wl>=v[i].first){output+=v[i].second; wl-=v[i].first;}
  else 
  {
   break;
  }
}
cout<<output<<endl;
  return 0;
}