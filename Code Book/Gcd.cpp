#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define mdc __gcd

using namespace std;

int a,b;

int main(){_
  while (cin>>a>>b){
      cout<<mdc(a,b)<<endl; //mdc de a e b
      cout<<a*b/mdc(a,b)<<endl; //mmc de a e b
  }
  return 0;
}
