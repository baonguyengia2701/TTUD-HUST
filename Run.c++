#include<bits/stdc++.h>
using namespace std;
int x[10]; // x[0]=H,x[1]=U,x[2]=S,x[3]=T,s[4]=O,s[5]=I,s[6]=C.
int n;
int cnt;
bool visited[20];
void input(){
    cin>>n;
    for(int i=0;i<10;i++){
        visited[i]=false;
    }
    cnt=0;
}
bool check(int a,int i){
    if(a==0 && i == 0) return false;
    if(a==2 && i==0) return false;
    if(visited[i]) return false;
    return true;
}
void solve(){
int hust = x[0]*1000 + x[1]*100 +x[2]*10 + x[3];
int soict= x[2]*10000 +x[4]*1000+x[5]*100+x[6]*10+x[3]; 
if(hust+soict==n){
    cnt++;
}
}
void Try(int a){
    for(int i=0;i<10;i++){
        if(check(a,i)){
            visited[i]=true;
            x[a]=i;
            if(a==6){
                solve();
            }
            else Try(a+1);
            visited [i]=false;
        }
    }
}


int main(){

ios_base::sync_with_stdio(false);cin.tie(NULL);
int T;
cin>>T;
for(int i=0;i<T;i++){
    input();
    Try(0);
    cout<<cnt<<endl;
}
}