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

void bfs(Game g){
	queue<Game> q;
	q.push(g);
	visited[MAX][MAX][0] = true;
	int tmp1, tmp2;
	while(!q.empty()){
		Game top = q.front();
		q.pop();
		if(top.millionaire == 0 and top.robber == 0 and visited[top.robber][top.millionaire][top.status] and top.status == 1){
			cout << "------------------------------Trang thai thuyen o ben phai---------------------------" << endl;
			cout << "Bo trai co so ke trom la " << top.robber << " va so trieu phu la " << top.millionaire << endl;
			cout << "Bo phai co so ke trom la " << MAX - top.robber << " va so trieu phu la " << MAX - top.millionaire << endl;
			cout << "So nuoc di hien tai la " << walkWay[top.robber][top.millionaire][top.status] << endl;
			cout << "------------------------------------------END----------------------------------------" << endl;
			cout << "\nDuong di ngan nhat la: " << walkWay[top.robber][top.millionaire][top.status] << endl;
			return;
		}
		for(int i = 0; i < 5; i++){
			tmp1 = top.status == 0 ? top.millionaire - dMillionaire[i] : top.millionaire + dMillionaire[i];
			tmp2 = top.status == 0 ? top.robber - dRobber[i] : top.robber + dRobber[i];
			if(tmp1 >= 0 and tmp2 >= 0 and tmp1 <= 3 and tmp2 <= 3 and !visited[tmp2][tmp1][abs(top.status - 1)]){
				if(Checker(tmp1, tmp2)){
					Game tmp = setG(top, tmp1, tmp2, abs(top.status - 1));
					q.push(tmp);
				}
			}
		}
		
	}
	cout << "\nKhong co duong di ngan nhat!" << endl;
}

int main(){
	fast_io;
	
	Game g;
	g.millionaire = MAX;
	g.robber = MAX;
	g.status = 0;
	
	cout << "--------------------------------------------BFS-----------------------------------------------" << endl;
	me(visited, false);
	me(walkWay, 0);
	bfs(g);
	cout << endl;
}
