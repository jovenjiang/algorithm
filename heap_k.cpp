#include<iostream>
#include<priority_queue>
#include<vector>
using namespace std;

void heapify(vector<int> &heap,int begin,int k){
	int i;
	heap[0]=heap[begin];
	i=begin*2;
	while(i<=k){
		if(i<k && heap[i]<heap[i+1])
			i++;
		if(heap[0]>heap[i])
			break;
		heap[begin]=heap[i];
		begin=i;
		i*=2;
	}
	heap[begin]=heap[0];
}
void build_heap(vector<int>& heap,int k){
	for(int i=k/2;i>0;i--)
		heapify(heap,i,k);
}

struct cmp2  
{    
    bool operator ()(int &a,int &b)  
    {    
        return a<b;//最大值优先     
    }    
};

int main(){
	int k=4;
	vector<int> input;
	input.push_back(12);
	input.push_back(6);
	input.push_back(4);
	input.push_back(44);
	input.push_back(11);
	input.push_back(5);
	input.push_back(8);
priority_queue<int,vector<int>,cmp1>q2;	
	if(k>input.size() || k<1)
		return -1;
	vector<int> heap(k+1);
	for(int j=1;j<=k;j++)
		heap[j]=input[j-1];
	build_heap(heap,k);
	for(int i=k;i<input.size();i++){
		if(input[i]<heap[1]){
			heap[1]=input[i];
			heapify(heap,1,k);
		}
	}
	for(int idx=1;idx<heap.size();idx++)
		cout<<heap[idx]<<"  ";
	cout<<endl;
	return 0;
	
}
