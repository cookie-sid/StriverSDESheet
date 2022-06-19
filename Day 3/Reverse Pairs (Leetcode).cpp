class Solution {
public:
    
    void mergeS(vector<int> &nums, int start, int end, int &ans) {
        if(start == end) {
            return;
        }
        int mid = (start + end)/2;
        mergeS(nums, start, mid, ans);
        mergeS(nums,mid + 1, end, ans);
        merge(nums,start,mid,end, ans);
    }
    
    void merge(vector<int> &nums, int start, int mid, int end, int &ans) {
        int lstart = start, rstart = mid + 1, len = end - start + 1, ctr = 0;
        vector<int> temp(len);
        int tmpL = lstart, tmpR = rstart, tmpE = end, tmpM = tmpR - 1, tctr = 0;
        while(tmpL <= tmpM and tmpR <= tmpE) {
            if(nums[tmpL] > 2 * (long long)nums[tmpR]) {
                ans += tmpE - tmpR + 1;
                tctr++;
                tmpL++;
            }
            else {
                tctr++;
                tmpR++;
            }
        }
        while(lstart <= mid and rstart <= end) {
            if(nums[lstart] >= nums[rstart]) {
                temp[ctr++] = nums[lstart++];
            }
            else {
                temp[ctr++] = nums[rstart++];
            }
        }
        while(lstart <= mid) {
            temp[ctr++] = nums[lstart++];
        }
        while(rstart <= end) {
            temp[ctr++] = nums[rstart++];
        }
        ctr = 0;
        for(int i = start; i <= end; i++) {
            nums[i] = temp[ctr++];
        }
    }
    
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        mergeS(nums,0,n-1,ans);
        return ans;
    }
};
