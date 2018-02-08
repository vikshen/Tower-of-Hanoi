#include <iostream>
#include <iomanip>
#include <stack>
#include <cmath>

using namespace std;

struct post1
{
        char n='a';
        stack<int> s;
};

struct post2
{
        char n='b';
        stack<int> s;
};

struct post3
{
        char n='c';
        stack<int> s;
};

post1 A;
post2 B;
post3 C;

int ts;

void print()
{
        int i, j, p, t;
        stack<int> dump1, dump2, dump3, pad1, pad2, pad3, temp1, temp2, temp3;

        pad1=A.s;
        if((A.s.size()<ts))
        {
                for(i=1;i<=ts-A.s.size();i++)
                        pad1.push(0);
        }

        pad2=B.s;
        if((B.s.size()<ts))
        {
                for(i=1;i<=ts-B.s.size();i++)
                        pad2.push(0);
        }

        pad3=C.s;
        if((C.s.size()<ts))
        {
                for(i=1;i<=ts-C.s.size();i++)
                        pad3.push(0);
      }

        for(dump1=pad1,dump2=pad2,dump3=pad3;!dump1.empty(),!dump2.empty(),!dump3.empty();dump1.pop(),dump2.pop(),dump3.pop())
        {
                cout<<"  ";
                i=dump1.top();
                if(i<ts)
                {
                        for(p=1;p<=(ts-i);p++)
                                cout<<" ";
                }
                for(j=1;j<=i;j++)
                        cout<<"_";
                if(i==0)
                        cout<<" ";
                if((i==0)&&(ts>=10))
                        cout<<" ";
                else if((i>0)&&(i<10)&&(ts>=10))
                        cout<<" "<<dump1.top();
                else if(i!=0)
                        cout<<dump1.top();
                for(j=1;j<=i;j++)
                        cout<<"_";
                if(i<ts)
                {
                        for(p=1;p<=(ts-i);p++)
                                cout<<" ";
                }
                cout<<"  ";
                i=dump2.top();
                if(i<ts)
                {
                        for(p=1;p<=(ts-i);p++)
                                cout<<" ";
                }
                for(j=1;j<=i;j++)
                        cout<<"_";
                if(i==0)
                        cout<<" ";
                if((i==0)&&(ts>=10))
                        cout<<" ";
                else if((i>0)&&(i<10)&&(ts>=10))
                        cout<<" "<<dump2.top();
                else if(i!=0)
                        cout<<dump2.top();
                for(j=1;j<=i;j++)
                        cout<<"_";
                if(i<ts)
                {
                        for(p=1;p<=(ts-i);p++)
                                cout<<" ";
                }
                cout<<"  ";
                i=dump3.top();
               if(i<ts)
                {
                        for(p=1;p<=(ts-i);p++)
                                cout<<" ";
                }
                for(j=1;j<=i;j++)
                        cout<<"_";
                if(i==0)
                        cout<<" ";
                if((i==0)&&(ts>=10))
                        cout<<" ";
                else if((i>0)&&(i<10)&&(ts>=10))
                        cout<<" "<<dump3.top();
                else if(i!=0)
                        cout<<dump3.top();
                for(j=1;j<=i;j++)
                        cout<<"_";
                if(i<ts)
                {
                        for(p=1;p<=(ts-i);p++)
                                cout<<" ";
                }
                cout<<"\n";
        }
}

void modify(int n,char from,char to)
{
        if((from=='a')&&(to=='b'))
        {
                A.s.pop();
                B.s.push(n);
        }
        else if((from=='a')&&(to=='c'))
        {
                A.s.pop();
                C.s.push(n);
        }
        else if((from=='b')&&(to=='c'))
        {
                B.s.pop();
                C.s.push(n);
        }
        else if((from=='b')&&(to=='a'))
        {
                B.s.pop();
                A.s.push(n);
        }
        else if((from=='c')&&(to=='b'))
        {
                C.s.pop();
                B.s.push(n);
        }
        else if((from=='c')&&(to=='a'))
        {
                C.s.pop();
                A.s.push(n);
        }
        print();
}

void towers(int n,char from,char to,char aux)
{
        if(n==1)
        {
                cout<<"Move a disk from peg "<<from<<" to peg "<<to<<".";
                cout<<"\n";
                modify(1,from,to);
                return;
        }
        towers(n-1,from,aux,to);
        cout<<"Move a disk from peg "<<from<<" to peg "<<to<<".";
        cout<<"\n";
        modify(n,from,to);
        towers(n-1,aux,to,from);
}


void towerOfHanoi(int nbDisks)
{
        towers(nbDisks,A.n,C.n,B.n);
}

void emptystack(stack<int> &s)
{
        while(!s.empty())
                s.pop();
}

int main ()
{
        cout << "4 disc tower of Hanoi" << endl << endl;
        for(int i=4;i>=1;i--)
                A.s.push(i);
        ts=4;
        print();
        towerOfHanoi(4);

        emptystack(A.s);
        emptystack(B.s);
        emptystack(C.s);

        cout << endl << endl << endl << "10 disc tower of Hanoi" << endl << endl;
        for(int i=10;i>=1;i--)
                A.s.push(i);
        ts=10;
        print();
        towerOfHanoi(10);

        emptystack(A.s);
        emptystack(B.s);
        emptystack(C.s);

        cout << endl << endl << endl << "15 disc tower of Hanoi" << endl << endl;
        for(int i=15;i>=1;i--)
                A.s.push(i);
        ts=15;
        print();
        towerOfHanoi(15);
        return 0;
}
