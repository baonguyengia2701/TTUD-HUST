#include<bits/stdc++.h>

using namespace std;

int n; // so phan tu
int a[1000000]; // mang a
int M[20][1000000]; // mang 2 chieu

int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(0); cout.tie(0);
	
	//input
	cin >> n; // 
	for( int i = 0; i<n; ++i){
		cin >> a[i];
		M[0][i] = a[i];
	}
	
	for( int j = 1; (1 << j) - 1 < n; ++j){ // j la so bit cua so 2
		for( int i = 0; i + (1 << j) - 1 < n; ++i){// i la vi tri bat dau cua day con
			M[j][i] = min(M[j-1][i], M[j-1][i + (1<<(j -  1))]); // tinh min cua 2 day con
		}
	}
	
	// query
	int m, res = 0;
	cin >> m;
	while( m -- ){
		int u, v;
		cin >> u >> v;
		int k = log2(v - u + 1);
		res += min(M[k][u], M[k][v - (1 << k) + 1]);
	}
	cout << res;
	
	return 0;
}

