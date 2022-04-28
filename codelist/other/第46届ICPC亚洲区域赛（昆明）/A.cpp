#include <bits/stdc++.h>
using namespace std;

/*

Ala:           Asp:           Asn:           Cys:           Gly:                              
  H H O          H H O          H H O          H H O          H H O                           
  | | ||         | | ||         | | ||         | | ||         | | ||                          
H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H                       
    |              |              |              |              |                             
  H-C-H          H-C-H          H-C-H          H-C-S-H          H                             
    |              |              |              |                                            
    H            O=C-O-H        O=C-N-H          H                                            
                                    |                                                         
                                    H        

链接：https://ac.nowcoder.com/acm/contest/32708/A
来源：牛客网

Ser:           Met:           Thr:           Gln:           Glu:           Peptide bond:     
  H H O          H H O          H H O          H H O          H H O         O   H            
  | | ||         | | ||         | | ||         | | ||         | | ||        ||  |            
H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    -C---N-           
    |              |              |              |              |                            
  H-C-O-H        H-C-H          H-C-O-H        H-C-H          H-C-H                          
    |              |              |              |              |                            
    H            H-C-H          H-C-H          H-C-H          H-C-H                          
                   |              |              |              |                            
                   S              H            O=C-N-H        O=C-O-H                        
                   |                               |                                         
                 H-C-H                             H                                         
                   |                                                                         
                   H                                                                                                                             
链接：https://ac.nowcoder.com/acm/contest/32708/A
来源：牛客网

mino acid	3-letter symbol	Molecular mass
Alanine	Ala		89
Asparagine	Asn	132
Aspartate	Asp	133
Cysteine	Cys	121
Glutamine	Gln	146
Glutamate	Glu	147
Glycine	Gly	75
Methionine	Met	149
Serine	Ser	105
Threonine	Thr	119                
*/
map<string, int> M;
string s[10][13];
int h[10], n, limit;
int wei[19];
string a[19];
int now[19];
int tot = 0;
int ans = 0;
string printsp(int len) {
    string ss = "";
    for(int i = 0; i < len; i++) ss += " ";
    return ss;
}
void print(int f) {
    if(tot <= 1) {
        return ;
    }
    ans++;
    if(!f) return ;
    int maxhigh = 0;
    for(int i = 1; i <= tot; i++) {
        maxhigh = max(maxhigh, h[M[a[now[i]]]]);
    }
    for(int i = 0; i <= maxhigh; i++) {
        string ss = "";
        for(int j = 1; j <= tot; j++) {

            if(h[M[a[now[j]]]] < i) ss += printsp(8);
            else {
                ss += s[M[a[now[j]]]][i];
            }
        }
        if(i == 2) ss[ss.size() - 1] = 'O', ss += "-H";
        if(i == 2) ss = "H" + ss;
        else ss = " " + ss;
        int r = ss.size();
        r -= 1;
        while(r >= 0 && ss[r] == ' ') r--;
        for(int k = 0; k <= r; k++) cout << ss[k];
        cout << endl;
    }

    cout << endl;
}
void dfs(int x, int siz, int ff) {
//    for(int i = 1; i <= tot; i++) cout << a[now[i]] << " " ;
//    cout << siz << endl;
    if(siz <= limit) {
        print(ff);
    }
    if(siz > limit) return ;
    // dfs(x + 1, siz);
    for(int i = 1; i <= n; i++) {
        now[++tot] = i;
        dfs(x + 1, siz + wei[M[a[i]]] - 18, ff);
        tot--;
    }
}
void work() {
    M["Ala"] = 0; M["Asp"] = 1; M["Asn"] = 2; M["Cys"] = 3; M["Gly"] = 4;
    M["Ser"] = 5; M["Met"] = 6; M["Thr"] = 7; M["Gln"] = 8; M["Glu"] = 9;
    wei[M["Ala"]] = 89; wei[M["Asp"]] = 133; wei[M["Asn"]] = 132; wei[M["Cys"]] = 121; wei[M["Gly"]] = 75;
    wei[M["Ser"]] = 105; wei[M["Met"]] = 149; wei[M["Thr"]] = 119; wei[M["Gln"]] = 146; wei[M["Glu"]] = 147;
    cin >> n >> limit;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
//    cout << wei[M[a[1]]] << endl;
//    cout << wei[M[a[2]]] << endl;
    sort(a + 1, a + 1 + n);
    dfs(0, 18, 0);
    cout << ans << endl;
    dfs(0, 18, 1);
    cout << endl;
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    s[0][0] = " H H O  ";
    s[0][1] = " | | || ";
    s[0][2] = "-N-C-C--";
    s[0][3] = "   |    ";
    s[0][4] = " H-C-H  ";
    s[0][5] = "   |    ";
    s[0][6] = "   H    ";
    h[0] = 6;
// cout << s[0][2] << endl;
    // s[0][0] = " H H O    ";
    // s[0][1] = "-N-C-C-O--";
    // s[0][2] = "   |      ";
    // s[0][3] = " H-C-H    ";
    // s[0][4] = "   |      ";
    // s[0][5] = "   H      ";
    // h[0] = 6;

    s[1][0] = " H H O  ";
    s[1][1] = " | | || ";
    s[1][2] = "-N-C-C--";
    s[1][3] = "   |    ";
    s[1][4] = " H-C-H  ";
    s[1][5] = "   |    ";
    s[1][6] = " O=C-O-H";
    h[1] = 6;
    s[2][0] = " H H O  ";
    s[2][1] = " | | || ";
    s[2][2] = "-N-C-C--";
    s[2][3] = "   |    ";
    s[2][4] = " H-C-H  ";
    s[2][5] = "   |    ";
    s[2][6] = " O=C-N-H";
    s[2][7] = "     |  ";
    s[2][8] = "     H  ";
    h[2] = 8;
    s[3][0] = " H H O  ";
    s[3][1] = " | | || ";
    s[3][2] = "-N-C-C--";
    s[3][3] = "   |    ";
    s[3][4] = " H-C-S-H";
    s[3][5] = "   |    ";
    s[3][6] = "   H    ";
    h[3] = 6;

    s[4][0] = " H H O  ";
    s[4][1] = " | | || ";
    s[4][2] = "-N-C-C--";
    s[4][3] = "   |    ";
    s[4][4] = "   H    ";
    h[4] = 4;

    s[5][0] = " H H O  ";
    s[5][1] = " | | || ";
    s[5][2] = "-N-C-C--";
    s[5][3] = "   |    ";
    s[5][4] = " H-C-O-H";
    s[5][5] = "   |    ";
    s[5][6] = "   H    ";
    h[5] = 6;

    s[6][0] = " H H O  ";
    s[6][1] = " | | || ";
    s[6][2] = "-N-C-C--";
    s[6][3] = "   |    ";
    s[6][4] = " H-C-H  ";
    s[6][5] = "   |    ";
    s[6][6] = " H-C-H  ";
    s[6][7] = "   |    ";
    s[6][8] = "   S    ";
    s[6][9] = "   |    ";
    s[6][10] = " H-C-H  ";
    s[6][11] = "   |    ";
    s[6][12] = "   H    ";
    h[6] = 12;
    s[7][0] = " H H O  ";
    s[7][1] = " | | || ";
    s[7][2] = "-N-C-C--";
    s[7][3] = "   |    ";
    s[7][4] = " H-C-O-H";
    s[7][5] = "   |    ";
    s[7][6] = " H-C-H  ";
    s[7][7] = "   |    ";
    s[7][8] = "   H    ";
    h[7] = 8;
    s[8][0] = " H H O  ";
    s[8][1] = " | | || ";
    s[8][2] = "-N-C-C--";
    s[8][3] = "   |    ";
    s[8][4] = " H-C-H  ";
    s[8][5] = "   |    ";
    s[8][6] = " H-C-H  ";
    s[8][7] = "   |    ";
    s[8][8] = " O=C-N-H";
    s[8][9] = "     |  ";
    s[8][10] = "     H  ";
    h[8] = 10;
    s[9][0] = " H H O  ";
    s[9][1] = " | | || ";
    s[9][2] = "-N-C-C--";
    s[9][3] = "   |    ";
    s[9][4] = " H-C-H  ";
    s[9][5] = "   |    ";
    s[9][6] = " H-C-H  ";
    s[9][7] = "   |    ";
    s[9][8] = " O=C-O-H";
    h[9] = 8;
    work();
    return 0;
}

