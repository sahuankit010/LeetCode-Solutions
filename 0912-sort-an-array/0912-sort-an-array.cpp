class Solution {
public:
    void merge(vector<int>&nums, int l, int m, int r){
        
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;

        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = nums[l + i];
        for (j = 0; j < n2; j++)
            R[j] = nums[m + 1 + j];
        
        i = 0;
        j = 0;
        k = l; 
        
        while (i < n1 && j < n2){
            if (L[i] <= R[j]){
                nums[k] = L[i];
                i++;
            }
            else{
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1){
            nums[k] = L[i];
            i++;
            k++;
        }

        while (j < n2){
            nums[k] = R[j];
            j++;
            k++;
        }
        
    }
    void mergeSort(vector<int> &nums, int l, int r){
        if(l<r){
            int m = l + (r-l)/2;
            mergeSort(nums, l, m);
            mergeSort(nums, m+1, r);
            merge(nums, l, m, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};