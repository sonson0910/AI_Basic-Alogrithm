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

struct Rule {
    vector<string> conditions;
    string conclusion;
};

void forwardInference(const vector<Rule>& rules, const unordered_map<string, bool>& knownFacts) {
    unordered_map<string, bool> inferredFacts = knownFacts;

    bool newFactAdded = true;
    while (newFactAdded) {
        newFactAdded = false;

        for (auto& rule : rules) {
        	string s = "Ki la ";
            bool allConditionsTrue = true;
            for (const string& condition : rule.conditions) {
//            	cout << condition << endl;
            	s += condition + ", ";
                if (!inferredFacts[condition]) {
                    allConditionsTrue = false;
                    break;
                }
            }

            if (allConditionsTrue && !inferredFacts[rule.conclusion]) {
            	total.push_back(s.erase(s.size() - 2) + " => Ki la " + rule.conclusion);
                inferredFacts[rule.conclusion] = true;
                newFactAdded = true;
            }
        }
    }
    
    for(string s : total){
    	cout << s << endl;
	}

}

int main() {
	fast_io;
	
    vector<Rule> rules = {
        {{"long mao"}, "loai co vu"},
        {{"long vu"}, "chim"},
        {{"biet bay", "de trung"}, "chim"},
        {{"loai co vu", "an thit"}, "thu an thit"},
        {{"loai co vu", "rang nhon", "mong vuot"}, "thu an thit"},
        {{"thu an thit", "mau long vang hung", "dom sam"}, "bao Chau Phi"},
        {{"thu an thit", "mau long vang hung", "van den"}, "ho"},
        {{"chim", "khong biet bay", "chan dai", "co dai"}, "da dieu"},
        {{"chim", "khong biet bay", "biet boi", "long den va trang"}, "chim canh cut"}
    };

    unordered_map<string, bool> knownFacts = {
        {"long mao", true},
        {"an thit", true},
        {"mau long vang hung", true},
        {"dom sam", true},
    };

    forwardInference(rules, knownFacts);
}
