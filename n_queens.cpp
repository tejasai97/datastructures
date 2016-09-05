// n_queens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
int ct=0;
class queen
{
    int n;
public:
    void read()
    {
        cout<<"Enter board size\n";
        cin>>n;
    }
    bool place(int x[10],int k)
    {
        for(int i=1;i<k;i++)
        {
            if(x[i]==x[k]||i+x[i]==k+x[k]||i-x[i]==k-x[k])
                return false;
        }
        return true;
    }
    void nqueen()
    {
        int x[10];
        int k=1;
        x[k]=0;
        while(k!=0)
        {
            x[k]++;
            while((!place(x,k))&&(x[k]<=n))x[k]++;

        if(x[k]<=n)
        {
            if(k==n)
            {
                ct++;
                cout<<"Solution "<<ct<<":\n";
                print(x);
				k = n + 1;
                cout<<endl;
            }
            else
            {
                k++;
                x[k]=0;
            }
        }
        else
            k--;
        }
    }
    void print(int x[10])
    {
        char c[10][10];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                c[i][j]='X';
        }
        for(int i=1;i<=n;i++)
        {
            c[i][x[i]]='Q';
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<c[i][j];
                cout<<endl;
        }
        cout<<endl;
    }
};
int main()
{
    queen A;
    A.read();
    A.nqueen();
    return 0;
}

