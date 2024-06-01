#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int arr[10000];
double max_avg = -1e5;
void input(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
double avg(int i, int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum+=arr[k];
    }
    return (double)sum/(j-i+1);
}

void solve(){
    for(int i=0;i<n;i++){
        for(int j=i+k-1;j<n;j++){
        double tmp=avg(i,j);
        if(tmp>max_avg){
            max_avg=tmp;
        }
    }
    }
}

int main(){
 ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    printf("%.5lf", max_avg);
    return 0;
}