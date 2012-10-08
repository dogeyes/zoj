#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

string s1,s2;
stack<char> cs;
vector<char> io;
int l;//当前案例，字符串的长度

void Prints()
{
    for(int i=0;i<io.size();i++)
        cout<<io[i]<<" ";
    cout<<endl;
}

//in表示入栈数量，out表示出栈数量
void dfs(int in,int out)
{
    char t;
    if( in==l && out==l )//如果入栈和出栈数量都等于字符串长度，则表示已得到一个成功解
    {
        Prints();
        return;
    }

    if( in<l )
    {
        cs.push(s1[in]);
        io.push_back('i');
        dfs(in+1,out);
        cs.pop();
        io.pop_back();
    }
    if( out<in && out <l && cs.top()==s2[out] )
    {
        t = cs.top();
        cs.pop();
        io.push_back('o');
        dfs(in,out+1);
        cs.push(t);
        io.pop_back();
    }
}

int main()
{
    while(cin>>s1>>s2)
    {
        l=s1.length();
        cout<<"["<<endl;
        dfs(0,0);
        cout<<"]"<<endl;
    }
    return 0;
}