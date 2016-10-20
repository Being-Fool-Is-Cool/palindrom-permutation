#include<bits/stdc++.h>
using namespace std;
#define M 26

bool ispallindrom(string str, int freq[])
{
	int len=str.length();
	for(int i=0;i<len;i++)
	{
		freq[str[i]-'a']++;
	}
	int odd=0;
	for(int i=0;i<M;i++)
	{
		if(freq[i]%2 ==1)
		odd++;
	}
	if(odd==1 && len%2==1 || odd==0 && len%2==0)
	return true;
	
	return false;
	
}
string reverse(string str)
{
	string temp=str;
	reverse(temp.begin(), temp.end());
	return temp;
}

void allpallindrom(string str)
{
	int len= str.length();
	int freq[M]={0};
	
	if(ispallindrom(str, freq))
	{
		string half="";
		string palin="";
		char odd;
		for(int i=0;i<M;i++)
		{
			half+=string(freq[i]/2 , i+'a');
			if(freq[i]%2 ==1)
			odd += i+'a';
		}
		do{
			palin=half;
			if(len %2==1)
			palin += odd;
			palin+= reverse(half);
			cout<<palin<<endl;
		}while(next_permutation(half.begin(), half.end()));
	}
}

int main()
{
	string str;
	cin>>str;
	allpallindrom(str);
}
