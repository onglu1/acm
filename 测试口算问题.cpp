#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> P;
vector<int> sum_min, sum_max;
vector<int> lead_zero;
bool used[10];
vector<P> weight;
int n;

int pow10(int x) {
    int ret = 1;
    for (int i = 0; i < x; ++i) {
        ret *= 10;
    }
    return ret;
}

bool dfs(int pos, int total) {

    if (pos == n) {
        return total == 0;
    }

    if (!(total + sum_min[pos] <= 0 && 0 <= total + sum_max[pos])) {
        return false;
    }

    for (int i = lead_zero[pos]; i < 10; ++i) {

        if (!used[i]) {
            used[i] = true;
            bool check = dfs(pos + 1, total + weight[pos].second * i);

            used[i] = false;

            if (check) {
                return true;
            }
        }
    }
    return false;
}

bool cmp(const P &u, const P &v) {
    return abs(u.second) > abs(v.second);
}

int main() {

    int m;
    cin >> m;
    vector<string> words(m);
    string result;
    for (int i = 0; i < m; i++)
        cin >> words[i];
    cin >> result;
    for (int i = 0; i < m; i++) {
        if (words[i].size() > result.size()) {
            cout << "No" << endl;
            return 0;
        }
    }


    map<char, int> _weight;
    set<char> _lead_zero;

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        for (int i = 0; i < word.size(); ++i) {
            _weight[word[i]] += pow10(word.size() - 1 - i);
        }

        if (word.size() > 1) {
            _lead_zero.insert(word[0]);
        }
    }


    for (int i = 0; i < result.size(); ++i) {
        _weight[result[i]] -= pow10(result.size() - i - 1);
    }
    if (result.size() > 1) {
        _lead_zero.insert(result[0]);
    }


    weight = vector<P>(_weight.begin(), _weight.end());
    sort(weight.begin(), weight.end(), cmp);

    n = weight.size();

    sum_min.resize(n);
    sum_max.resize(n);
    for (int i = 0; i < n; ++i) {

        vector<int> pos, neg;
        for (int j = i; j < n; ++j) {
            if (weight[j].second > 0) {
                pos.push_back(weight[j].second);
            } else if (weight[j].second < 0) {
                neg.push_back(weight[j].second);
            }
            sort(pos.begin(), pos.end());
            sort(neg.begin(), neg.end());
        }


        for (int j = 0; j < pos.size(); ++j) {
            sum_min[i] += (pos.size() - 1 - j) * pos[j];
            sum_max[i] += (10 - pos.size() + j) * pos[j];
        }

        for (int j = 0; j < neg.size(); ++j) {
            sum_min[i] += (9 - j) * neg[j];
            sum_max[i] += j * neg[j];
        }
    }

    lead_zero.resize(n);
    for (int i = 0; i < n; ++i) {
        lead_zero[i] = (_lead_zero.count(weight[i].first) ? 1 : 0);
    }
    memset(used, false, sizeof(used));

    if (dfs(0, 0)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

