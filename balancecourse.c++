#include<bits/stdc++.h>

using namespace std;

int m, n; // m <= 10, n <= 30
int cList[30][50]; // cList[i][j] = 1 if course j is in list of teacher i
bool conf[50][50]; // conf[i][j] = 1 if course i and course j are conflict
vector<int> assign[30]; // assign[i] = list of courses that teacher i teaches

int curMax_id = 0; // teacher who has most courses
int res = INT_MAX; // result 

void input(){
	scanf("%d %d", &m, &n);
	for( int i = 1; i<=m; ++i){
		int k;
		scanf("%d", &k);
		for( int j = 1; j<=k ; ++j) {
			int x; scanf("%d", &x);
			cList[i][x] = 1;
		}
	}
	int k;
	scanf("%d", &k);
	for( int i = 0; i<k; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		conf[u][v] = 1; conf[v][u] = 1;
	}
}

bool check(int k, int i){
	if( !cList[i][k]) return false;
	
	for( auto x: assign[i])
		if( conf[k][x] ) return false;
	
	return true;
}

void solution(){
	res = min(res, (int) assign[curMax_id].size());
}
void Try(int k){ // find teacher who teach course k
	for( int i = 1; i<= m; ++i){ // teacher i
		if( check(k, i)){  // if teacher i can teach course k
			assign[i].push_back(k); // assign course k to teacher i
			int temp = curMax_id; // save current max_id
			
			if( assign[curMax_id].size() < assign[i].size()) curMax_id = i; // update max_id
			
			if( k == n) solution(); // if all courses are assigned
			else if( res > assign[curMax_id].size()) Try(k + 1); // if current result is better than best result
			
			curMax_id = temp;// restore max_id
			assign[i].pop_back();// unassign course k to teacher i
		}
	}
}

int main(){
	input();
	Try(1);
	if( res == INT_MAX) res = -1;
	printf("%d", res);
	return 0;
}
