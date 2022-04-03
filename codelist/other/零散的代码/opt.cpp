#include <bits/stdc++.h>

using namespace std;
const int N = 1007;
bool mystrncpy(char **to, char *from, unsigned startpos, unsigned len) {
    if (startpos + len > strlen(from) || len == 0 || startpos < 0) return false;
    *to = (char*) malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        (*to)[i] = from[startpos + i];
    }
    (*to)[len] = '\0';
    return true;
}
int main() {
    char from[] = "abcdefghijklmn";
    char *to = NULL;
    if (mystrncpy(&to, from, 3,4)) {
        cout << strlen(to) << endl;
        cout << to << endl;
    } else {
        cout << "Error\n";
    }
}