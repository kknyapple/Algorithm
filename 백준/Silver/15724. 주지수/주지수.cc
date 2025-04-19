#include <iostream>

using namespace std;

int n,m;
int k,a,b,d,c;
int r[1050][1050], s[1050][1050];

int main() {
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>r[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + r[i][j];
        }
    }
    
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a>>b>>c>>d;
        cout<< s[c][d] - s[c][b-1] - s[a-1][d] + s[a-1][b-1]<<"\n";
    }
    
    return 0;
}