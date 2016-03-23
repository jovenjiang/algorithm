
//What if duplicates are allowed at most twice?

//For example,
//Given sorted array nums = [1,1,1,2,2,3],

//Your function should return length = 5, 
//with the first five elements of nums being 
//1, 1, 2, 2 and 3. 
//It doesn't matter what you leave beyond the new length.

public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len<3)
            return len;
        
        int n=0;    
        for(int i=0;i<len;i++){
            if(i<2 || nums[i]>nums[n-2])
                nums[n++]=nums[i];
        }   
        return n;
    }
};
