//在数组中的两个数字，如果前面一个数字大于后面的数字，
//则这两个数字组成一个逆序对。
//输入一个数组，求出这个数组中的逆序对的总数。

class Solution {
public:
    int InversePairs(vector<int> data) {
        int len=data.size();
        if(len<2)
            return 0;
        int* tmp=new int[len];
        return merge_sort(data,0,len-1,tmp);
    }
    int merge_sort(vector<int>& data,int start,int end,int tmp[]){
        int count=0;
        if(start<end){
        	int mid=(start+end)/2;
        	count+=merge_sort(data,start,mid,tmp);
        	count+=merge_sort(data,mid+1,end,tmp);
            count+=merge(data,start,mid,end,tmp);
        }
        return count;
    }
    int merge(vector<int>& data,int start,int mid,int end,int tmp[]){
        int i=mid,j=end,k=end-start;
        int count=0;
        while(i>=start && j>mid){
            if(data[i]>data[j]){
                count+=j-mid;
                tmp[k--]=data[i--];
            }
            else 
                tmp[k--]=data[j--];
        }
        while(i>=start)
            tmp[k--]=data[i--];
        while(j>mid)
            tmp[k--]=data[j--];
        for(i=start,k=0;i<=end;i++,k++){
            data[i]=tmp[k];
        }
        return count;
    }
};
