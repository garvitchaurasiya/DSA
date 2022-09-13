#include "bits/stdc++.h"
using namespace std;
#define ll long long;

int main(){

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        
        int e = n; int s = 1;
        for (int i=1; i<=n; i++){
            if(i%2==0){
                cout<<s<<' ';
                s++;
            }
            else{
                cout<<e<<" ";
                e--;
            }
        }
        cout<<endl;

    }
    return 0;

}