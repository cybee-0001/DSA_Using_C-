#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    bool isPossible(int a,int b)
    {
        return ((a==2 || b==2) && !(a==2 && b==2));
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    }
}