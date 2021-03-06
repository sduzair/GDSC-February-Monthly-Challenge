// GDSC February Monthly Challenge
// Uzair Ahmed Syed

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(int nums[], int size, int target) {

    // res will store final array of quadruple arrays
    vector<vector<int> > res;

    if (size == 0)
        return res;

    sort(nums, nums + size);

    for (int i = 0; i < size - 3; i++) {
    
        for (int j = i + 1; j < size - 2; j++) {
        
            int* lptr = nums + j + 1;
            int* rptr = (nums + size - 1);
        
            while(lptr != rptr) {
            
                vector<int> two_sum;
                if ( nums[i] + nums[j] + *lptr + *rptr == target ) {
                    two_sum.push_back(nums[i]);
                    two_sum.push_back(nums[j]);
                    two_sum.push_back(*lptr);
                    two_sum.push_back(*rptr);
                    res.push_back(two_sum);
                    
                    int vall = *lptr;
                    int valr = *rptr;
                    lptr = lptr + 1;
                    rptr = rptr - 1;
                    while ( vall == *lptr && lptr != rptr ) lptr = lptr + 1;
                    while ( valr == *rptr && lptr != rptr ) rptr = rptr - 1;
                }
                else if ( nums[i] + nums[j] + *lptr + *rptr > target ) {
                    rptr = rptr - 1;
                }
                else if ( nums[i] + nums[j] + *lptr + *rptr < target ) {
                    lptr = lptr + 1;
                }
            }
            while ( nums[j] == nums[j + 1] ) j++;
        } 
        while ( nums[i] == nums[i + 1] ) i++;   
    }

    return res;
}

int main()
{
    int nums[] = {2,2,2,2,2};
    int target = 8;
    
    int size = sizeof(nums)/sizeof(nums[0]);

    vector<vector<int>> quadruples = fourSum(nums, size, target);

    cout << endl;
    for ( vector<int> quadruple : quadruples ) {
        for ( int num : quadruple ) cout << num << " ";
        cout << endl;
    }
    
}
