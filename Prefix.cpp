//#include<bits/stdc++.h> 
#include<iostream>
using namespace std; 

void GetPrefix(string a)
{ 
	int i,j;
	for(j=0,i=1;i<=a.length();i++){
			cout << a.substr(j,i)<<endl;
	}
} 

int main() 
{ 
    string a = "computer" ; 
    GetPrefix(a); 
    return 0; 
} 
