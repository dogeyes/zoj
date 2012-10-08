#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

string s1,s2;
stack<char> cs;
vector<char> io;
int l;//��ǰ�������ַ����ĳ���

void Prints()
{
    for(int i=0;i<io.size();i++)
        cout<<io[i]<<" ";
    cout<<endl;
}

//in��ʾ��ջ������out��ʾ��ջ����
void dfs(int in,int out)
{
    char t;
    if( in==l && out==l )//�����ջ�ͳ�ջ�����������ַ������ȣ����ʾ�ѵõ�һ���ɹ���
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