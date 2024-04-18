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

using namespace std;

int m, n, c, t;
typedef pair<int, int> dd;
//typedef pair<double, double> dd;
int a[300][300], cnt[300];
bool visited[300][300];
int dx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[8] = {0, -1, 1, 0, -1, 1, -1, 1};
vector<string> total;

/* from Nguy?n H?ng Son */

unordered_map<string, vector<string>> rules = {
    {"loai co vu", {"long mao"}},
    {"chim", {"long vu"}},
    {"chim", {"biet bay", "de trung"}},
    {"thu an thit", {"loai co vu", "an thit"}},
    {"thu an thit", {"loai co vu", "rang nhon", "mong vuot"}},
    {"bao Chau Phi", {"thu an thit", "mau long vang hung", "dom sam"}},
    {"ho", {"thu an thit", "mau long vang hung", "van den"}},
    {"da dieu", {"chim", "khong biet bay", "chan dai", "co dai"}},
    {"chim canh cut", {"chim", "khong biet bay", "biet boi", "long den va trang"}}
};

bool backwardInference(string &goal, unordered_map<string, bool> &inferred, string &s) {
    if (inferred[goal]) {
    	total.push_back(s);
    	s = "";
        return true;
    }

    if (rules.find(goal) == rules.end()) {
        return false;
    }

    for (string premise : rules[goal]) {
    	string temp = "";
		temp += temp == "" ? premise : ", " + premise;
		s += s != "" ? " => Bibi la " + temp : temp;
        if (!backwardInference(premise, inferred, s)) {
        	s = "";
            return false;
        }
    }

    inferred[goal] = true;
    return true;
}

int main() {
	fast_io;
	
    unordered_map<string, bool> inferred = {
    	{"long vu", true},
		{"khong biet bay", true},
		{"chan dai", true},
		{"co dai", true},
	};
    string goal = "da dieu";
    string s = "";

    if (backwardInference(goal, inferred, s)) { 
    	for(string s:total){
	    	cout << "Bibi la: " << s << endl;
		}
        cout << "Lap luan Bibi la " << goal << " da duoc chung minh" << endl;
    } else {
        cout << "Lap luan Bibi la " << goal << " khong the chung minh" << endl;
    }
}
