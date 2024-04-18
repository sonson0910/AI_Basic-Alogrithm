#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define ll long long
#define endl "\n"
#define me(a, b) memset(a, b, sizeof(a))
#define MOD 1e9 + 7
#define fi first
#define se second
#define Pop(a) pop_back(a)
#define pb(a) push_back(a)
#define pf(a) push_font(a)
#define all(a) a.begin(),a.end()
#define MAX 3

using namespace std;

int m, n, c, t;
typedef pair<int, int> dd;
int a[300][300], cnt[300];
bool visited[5][5][5];
int walkWay[5][5][5];
int dRobber[6] = {0, 1, 1, 2, 0};
int dMillionaire[6] = {1, 0, 1, 0, 2};
int flag = 1;

/* from Flynn */

struct Game{
	int robber;
	int millionaire;
	int status;
};

bool Checker(int millionaire, int robber){
	if(millionaire == 0 and robber == 0){
		return true;
	}else if(millionaire >= robber){
		if(millionaire == robber){
			return true;
		}else if(robber == 0 and millionaire > 0 and millionaire != 3){
			return false;
		}else if(millionaire == 3){
			return true;
		}
	}else{
		if(millionaire == 0){
			return true;
		}else{
			return false;
		}
	}
	return false;
}

Game setG(Game g, int tmp1, int tmp2, int status){
	Game tmp;
	tmp.robber = tmp2;
	tmp.millionaire = tmp1;
	tmp.status = abs(g.status - 1);
	visited[tmp2][tmp1][status] = true;
	walkWay[tmp.robber][tmp.millionaire][tmp.status] = walkWay[g.robber][g.millionaire][g.status] + 1;
	if(g.status == 0){
		cout << "------------------------------Trang thai thuyen o ben phai---------------------------" << endl;
		cout << "Bo trai co so ke trom la " << tmp.robber << " va so trieu phu la " << g.millionaire << endl;
		cout << "Bo phai co so ke trom la " << MAX - tmp.robber << " va so trieu phu la " << MAX - g.millionaire << endl;
		cout << "So nuoc di hien tai la " << walkWay[tmp.robber][tmp.millionaire][tmp.status] << endl;
	}else{
		cout << "------------------------------Trang thai thuyen o ben trai---------------------------" << endl;
		cout << "Bo trai co so ke trom la " << tmp.robber << " va so trieu phu la " << tmp.millionaire << endl;
		cout << "Bo phai co so ke trom la " << MAX - tmp.robber << " va so trieu phu la " << MAX - tmp.millionaire << endl;
		cout << "So nuoc di hien tai la " << walkWay[tmp.robber][tmp.millionaire][tmp.status] << endl;
	}
	return tmp;
}

void dfs(Game g){
	visited[g.robber][g.millionaire][g.status] = true;
	int tmp1, tmp2;
	if(g.millionaire == 0 and g.robber == 0 and visited[g.robber][g.millionaire][g.status] and g.status == 1){
		flag = 0;
		cout << "------------------------------Trang thai thuyen o ben phai---------------------------" << endl;
		cout << "Bo trai co so ke trom la " << g.robber << " va so trieu phu la " << g.millionaire << endl;
		cout << "Bo phai co so ke trom la " << MAX - g.robber << " va so trieu phu la " << MAX - g.millionaire << endl;
		cout << "So nuoc di hien tai la " << walkWay[g.robber][g.millionaire][g.status] << endl;
		cout << "------------------------------------------END----------------------------------------" << endl;
		cout << "\nDuong di ngan nhat la: " << walkWay[g.robber][g.millionaire][g.status] << endl;
		return;
	}
	for(int i = 0; i < 5; i++){
		tmp1 = g.status == 0 ? g.millionaire - dMillionaire[i] : g.millionaire + dMillionaire[i];
		tmp2 = g.status == 0 ? g.robber - dRobber[i] : g.robber + dRobber[i];
		if(tmp1 >= 0 and tmp2 >= 0 and tmp1 <= 3 and tmp2 <= 3 and !visited[tmp2][tmp1][abs(g.status - 1)]){
			if(Checker(tmp1, tmp2)){
				Game tmp = setG(g, tmp1, tmp2, abs(g.status - 1));
				dfs(tmp);
			}
		}
		if(flag == 0){
			return;
		}
	}
}

int main(){
	fast_io;
	
	Game g;
	g.millionaire = MAX;
	g.robber = MAX;
	g.status = 0;
	
	cout << "--------------------------------------------DFS-----------------------------------------------" << endl;
	me(visited, false);
	me(walkWay, 0);
	dfs(g);
	if(flag == 1){
		cout << "Khong ton tai duong di ngan nhat!" << endl;
	}
}
