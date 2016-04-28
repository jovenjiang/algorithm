#include<iostream>
using namespace std;

void Heapify(int s,int m,int R[])
{ /*对R[1..n]进行堆调整，用temp做暂存单元 */
     int j,temp;
     temp=R[s];
     j=2*s;
     while (j<=m)
     {
	  if (j<m&&R[j]>R[j+1])
		  j++;     /*两孩子较小的一个*/
	  if (temp<R[j]) 
		  break;
	  R[s]=R[j];
      s=j;
      j=j*2;
     }/* end of while */
     R[s]=temp;
} /* end of Heapify */

void BuildHeap(int n,int R[])
{ /* 由一个无序的序列建成一个堆 */
   int i;
   for(i=n/2;i>0;i--)
      Heapify(i,n,R);
}

void Heap_Sort(int n,int k,int R[])
{ /* 对R[1..n]进行堆排序，不妨用R[0]做暂存单元 */
    int i;
    BuildHeap(n,R); /* 将R[1-n]建成初始堆 */
    for(i=n;i>1&&k--;i--)
    { /* 对当前无序区R[1..i]进行堆排序，共做n-1趟。 */
    	R[0]=R[1];
		R[1]=R[i];
		R[i]=R[0]; /* 将堆顶和堆中最后一个记录交换 */
    	Heapify(1,i-1,R); /* 将R[1..i-1]重新调整为堆，仅有R[1]可能违反堆性质 */
    } /* end of for */
} /* end of Heap_Sort */


int main(){
	int k;
	int n;
	while(cin>>n>>k)
	{
		int *R=new int[n];
		for(int i=0;i<n;i++){
			cin>>R[i];

		Heap_Sort(n,k,R);

		while(k--)
			cout<<R[--n]<<" ";
		cout<<endl;
	}
	return 0;
}
