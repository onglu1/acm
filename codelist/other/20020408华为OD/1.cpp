#include <bits/stdc++.h>
using namespace std;
class SkiRankingSystm {
public:
    struct node {
        int ord, id, dur;
    };
    vector<node> v;
    int tot = 0;
    SkiRankingSystm() {
        v.clear();
        tot = 0;
    }
    void AddRecord(int userId, int duration) {
        v.push_back({++tot, userId, duration});
    }
    vector<int> GetTopAthletes(int num) {
        sort(v.begin(), v.end(), [] (const node &a, const node &b) {
            if(a.dur != b.dur) return a.dur < b.dur;
            else return a.ord < b.ord;
        });
        vector<int> t;
        map<int, int> M;
        for(int i = 0; t.size() < num && i < v.size(); i++) {
            if(!M.count(v[i].id)) {
                t.push_back(v[i].id);
                M[v[i].id] = 1;
            }
        }
        return t;
    }
    vector<int> QueryTop3Record(int userId) {
        vector<int> t;
        for(int i = 0; i < v.size(); i++) if(v[i].id == userId) {
            t.push_back(v[i].dur);
        }
        sort(t.begin(), t.end());
        if(t.size() <= 3) return t;
        else {
            t.resize(3);
            return t;
        }
    }
};
void print(vector<int> v) {
    cout << "v : ";
    for(auto x : v) {
        cout << x << " ";
    }
    cout << endl;
}
int main()
{
    SkiRankingSystm t;
//    t.AddRecord(1, 10);
//    t.AddRecord(2, 8);
//    auto tt = t.GetTopAthletes(3);
//    for(auto x : tt) {
//        cout << x << " ";
//    }
//    cout << endl;
//    tt = t.QueryTop3Record(1);
//    for(auto x : tt) {
//        cout << x << " ";
//    }
//    cout << endl;
    t.AddRecord(20, 8);
    t.AddRecord(22, 6);
    t.AddRecord(20, 6);
    print(t.GetTopAthletes(4));
    t.AddRecord(33, 5);
    t.AddRecord(22, 9);
    t.AddRecord(31, 4);
    print(t.GetTopAthletes(4));
    t.AddRecord(20, 8);
    print(t.QueryTop3Record(20));
    t.AddRecord(20, 6);
    print(t.QueryTop3Record(20));
    return 0;
}