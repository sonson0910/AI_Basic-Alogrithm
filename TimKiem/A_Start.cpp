#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define ll long long
#define endl "\n"
#define me(a, b) memset(a, b, sizeof(a))
#define MOD 1e9 + 7
#define MAX 3
#define fi first
#define se second
#define Pop(a) pop_back(a)
#define pb(a) push_back(a)
#define pf(a) push_font(a)
#define all(a) a.begin(),a.end()

using namespace std;

int m, n, c, t;
typedef pair<int, int> dd;
//typedef pair<double, double> dd;
bool visited[5][5][5];
int walkWay[5][5][5];
int dRobber[6] = {0, 1, 1, 2, 0};
int dMillionaire[6] = {1, 0, 1, 0, 2};

/* from Flynn */


struct Game{
	int robber;
	int millionaire;
	int expense;
	int status;
};

struct CompareExpense {
    bool operator()(const Game& g1, const Game& g2) {
        return g1.expense > g2.expense; 
    }
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
	tmp.expense = walkWay[tmp.robber][tmp.millionaire][tmp.status];
	if(g.status == 0){
		cout << "------------------------------Trang thai thuyen o ben phai---------------------------" << endl;
		cout << "Bo trai co so ke trom la " << tmp.robber << " va so trieu phu la " << g.millionaire << endl;
		cout << "Bo phai co so ke trom la " << MAX - tmp.robber << " va so trieu phu la " << MAX - g.millionaire << endl;
		cout << "So nuoc di hien tai la " << walkWay[tmp.robber][tmp.millionaire][tmp.status] << endl;
		cout << "Tong trong so tai nuoc di la " << tmp.expense << endl;
	}else{
		cout << "------------------------------Trang thai thuyen o ben trai---------------------------" << endl;
		cout << "Bo trai co so ke trom la " << tmp.robber << " va so trieu phu la " << tmp.millionaire << endl;
		cout << "Bo phai co so ke trom la " << MAX - tmp.robber << " va so trieu phu la " << MAX - tmp.millionaire << endl;
		cout << "So nuoc di hien tai la " << walkWay[tmp.robber][tmp.millionaire][tmp.status] << endl;
		cout << "Tong trong so tai nuoc di la " << tmp.expense << endl;
	}
	return tmp;
}

void Alogrithm(Game g){
	priority_queue<Game, vector<Game>, CompareExpense> pq;	
	pq.push(g);
	visited[MAX][MAX][0] = true;
	int tmp1, tmp2;
	while(!pq.empty()){
		Game top = pq.top();
		pq.pop();
		if(top.millionaire == 0 and top.robber == 0 and visited[top.robber][top.millionaire][top.status] and top.status == 1){
			cout << "------------------------------Trang thai thuyen o ben phai---------------------------" << endl;
			cout << "Bo trai co so ke trom la " << top.robber << " va so trieu phu la " << top.millionaire << endl;
			cout << "Bo phai co so ke trom la " << MAX - top.robber << " va so trieu phu la " << MAX - top.millionaire << endl;
			cout << "So nuoc di hien tai la " << walkWay[top.robber][top.millionaire][top.status] << endl;
			cout << "\nDuong di ngan nhat la: " << walkWay[top.robber][top.millionaire][top.status] << endl;
			cout << "Tong trong so = " << top.expense << endl;
			return;
		}
		for(int i = 0; i < 5; i++){
			tmp1 = top.status == 0 ? top.millionaire - dMillionaire[i] : top.millionaire + dMillionaire[i];
			tmp2 = top.status == 0 ? top.robber - dRobber[i] : top.robber + dRobber[i];
			if(tmp1 >= 0 and tmp2 >= 0 and tmp1 <= 3 and tmp2 <= 3 and !visited[tmp2][tmp1][abs(top.status - 1)]){
				if(Checker(tmp1, tmp2)){
					Game tmp = setG(top, tmp1, tmp2, abs(top.status - 1));
					pq.push(tmp);
				}
			}
		}
	}
}

int main(){
	fast_io;
	Game g;
	g.millionaire = MAX;
	g.robber = MAX;
	g.expense = 0;
	g.status = 0;
	
	cout << "--------------------------------------------A Star-----------------------------------------------" << endl;
	Alogrithm(g);
}
