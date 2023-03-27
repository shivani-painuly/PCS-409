#include<bits/stdc++.h>
using namespace std;
void count_sort(vector<char>a,int n)
{
    int i;
    vector<char> m(26,0);
    for(i=0;i<n;i++)
    {
        m[a[i]-'a']++;
    }
    int x = *max_element(m.begin(),m.end());
    vector<char>::iterator it;
    it = find(m.begin(),m.end(),x);
    int d = distance(m.begin(),it);
    cout<<char(d+97)<<" - "<<x<<endl; 
}
int main()
{
    int t;
    cout<<"enter number of test case";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter number of element";
        cin>>n;
        vector<char>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a.begin(),a.end());
        count_sort(a,n);
    }
}
