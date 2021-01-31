#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <iomanip>

using namespace std;
using ll = unsigned long long;

typedef pair<ll, ll> P;
ll ans=0;

void clt(ll X,ll Y,ll A,ll B){
    if(X<Y){
        if(X*A<X+B){
            clt(X*A,Y,A,B);
            ans++;
        }else{
            clt(X+B,Y,A,B);
            ans++;
        }
    }
    return;
}

int main(void){
    //XをA倍
    //Yにならないうようにする
    ll X,Y,A,B;
    cin >> X>>Y>>A>>B;
    clt(X,Y,A,B);
    cout <<--ans<<endl;
}


/*
int main(void){
    string lineF;
    getline(cin, lineF);
    vector<string> N;
    istringstream iss(lineF);
    string k;
    while(iss >>k)
    {
        N.push_back(k);
    }
    vector<int> num;
    vector<string> str;
    for(int d=0; d<N.size();d++){
        string pre =N[d];
        for(int h=0;h<pre.length()-1;h++){
            if(pre[h]==':'){
                string prenum="";
                string prestr="";
                for(int s=0;s<h;s++){
                    prenum+=pre[s];
                }
                for(int s=h+1;s<pre[h];s++){
                    prestr+=pre[s];
                }
                int kkkkk=stoi(prenum);
                num.push_back(kkkkk);
                str.push_back(prestr);
            }
        }
    }
    int m=stoi(N[N.size()-1]);
    vector<string> ans;
    for(int j=0;j<N.size()-1;j++){
        if(m/num[j]==0){
            ans.push_back(str[j]);
        }
    }
    for(int l=0;l<ans.size();l++){
        cout <<ans[l];
    }
}
*/


/*
ll LCM(ll a,ll b){

}

int main(void)
{
    ll l, r, m;
    cin >> l >> r >> m;
    int nnsize = m * (m - 1) / 2;
    vector<ll> n(m);
    vector<ll> nans(m);
    vector<ll> nnans(0);
    ll ans = 0;
    for (int a = 0; a < m; a++)
    {
        cin >> n[a];
    }
    //m=1のとき
    for(int k=0;k<m;k++){
        vector<bool> k(m);
        vector<vector<bool>> kk(mCk);
        for(){
            //k個の1(残りは0)が並ぶ長さmの数列をDPS()で生成
        }
        for(int m=0;m<kk.size();m++){
            vector<ll> nn;

        }

    }
    */


    /*
    for (int a = 0; a < m; a++)
    {
        cin >> n[a];
    }
    for (int a = 0; a < m; a++)
    {
        for (int b = a + 1; b < m; b++)
        {
            nn.push_back(n[a] * n[b]);
        }
    }
    for (int a = 0; a < m; a++)
    {
        ll bg = r / n[a];
        ll sm = l / n[a];
        if (l % n[a] == 0)
            sm--;
        nans[a] = bg - sm;
        ans += nans[a];
        cout << ans << " " << endl;
    }
    for (int a = 0; a < nn.size(); a++)
    {
        if (nn.empty())
            break;
        ll bg = r / nn[a];
        ll sm = l / nn[a];
        if (l % nn[a] == 0) sm--;
        nnans.push_back(bg - sm);
        ans -= nnans[a];
        cout << ans << " " << endl;
    }
    cout << r - l + 1 - ans << endl;
}
*/

/*
int main(void){
    vector<int> N;
    vector<string> A;
    string lineF;
    string lineS;
    getline(cin, lineF);
    getline(cin,lineS);
    istringstream iss(lineF);
    int k;
    while(iss >>k)
    {
        N.push_back(k);
    }
    istringstream ism(lineS);
    string j;
    while(ism >>j){
        A.push_back(j);
    }
    int ans=0;
    for(int x=0;x<A.size();x++){
        if(A[x]=="Alice"){
            ans += N[x];
        }
    }
    std::cout << ans <<endl;
    
}
*/

