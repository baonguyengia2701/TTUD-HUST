#include<bits/stdc++.h>
using namespace std;
int n;
vector<long long> arr;
void inp(){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        arr.push_back(x);
    }
}
void solve(){
    vector<long long> dpEven(n,0); // Lưu tổng chẵn lớn nhất tại vị trí i
    vector<long long> dpOdd(n,0); //    Lưu tổng lẻ lớn nhất tại vị trí i
    if(arr[0]%2==0) dpEven[0]=arr[0];
    else dpOdd[0]=arr[0];
    long long res=dpEven[0];
    for(int i=1;i<n;i++){
        if(arr[i]%2==0){
            dpEven[i]=max(arr[i],arr[i]+dpEven[i-1]);
            dpOdd[i]=dpOdd[i-1]+arr[i];
        }
        else{
            dpEven[i]=dpOdd[i-1]+arr[i];
            dpOdd[i]=max(arr[i],arr[i]+dpEven[i-1]);
        }
        res=max(res,dpEven[i]);
    }
    cout<<res;
}




int main(){
inp();
solve();
}