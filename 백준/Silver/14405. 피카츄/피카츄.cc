#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str;
bool flag = true;

int main() {
    ios_base::sync_with_stdio(false);    
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i]=='p' && str[++i]=='i') continue;
        else if(str[i]=='k' && str[++i]=='a' ) continue;
        else if(str[i]=='c' && str[++i]=='h' && str[++i]=='u') continue;
        else{
            flag=false;
            break;
        }
    }
    
    if(flag) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    
    return 0;
}