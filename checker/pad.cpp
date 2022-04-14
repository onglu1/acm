#include <bits/stdc++.h>
using namespace std;

signed main()
{
    while(true) {
        system("C:\\Users\\onglu\\CLionProjects\\acm\\checker\\rnd.exe>data.in");
        system("C:\\Users\\onglu\\CLionProjects\\acm\\checker\\bf.exe<data.in>data.ans");
        system("C:\\Users\\onglu\\CLionProjects\\acm\\checker\\std.exe<data.in>data.out");
        if(system("fc data.out data.ans")) {
            cout << "!" << endl;
            break;
        }

    }
    return 0;
}