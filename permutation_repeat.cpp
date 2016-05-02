#include<iostream> 
#include<algorithm>
using namespace std;  
#include<vector>
#include<string>
#include<unordered_set>

void perm(vector<string> &v,string str,int start){  //str用引用不行
	if(start>=str.length())
		v.push_back(str);
	unordered_set<char> us;
	sort(str.begin()+start,str.end());
	for(int i=start;i<str.length();i++)
	{
		if( us.find(str[i]) == us.end() ){
			us.insert(str[i]);
			swap(str[i],str[start]);
			perm(v,str,start+1);
			swap(str[i],str[start]);
		}
	}
}

int main(void)  
{  
	string str="accca";
    vector<string> v;
    perm(v,str,0);
    for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	cout<<v.size()<<endl;
	return 0;
}  
