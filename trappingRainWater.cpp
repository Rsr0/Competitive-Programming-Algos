// Question link: https://leetcode.com/problems/trapping-rain-water/

/*
  Algorithm
  i)    Find maximum height of bar from the left end upto an index i in the array left.
  ii)   Find maximum height of bar from the right end upto an index i in the array right.
  iii)  Iterate over the height array and update ans:
            ans+=min(left[i],right[i])−height[i] 
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0; 
        int n=height.size();
        if(n==0)
            return 0;
        int left[n];
        int right[n];
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i]=max(height[i],left[i - 1]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(height[i],right[i+1]);
        }
        for (int i = 0; i < n; i++) 
        water += min(left[i], right[i]) -height[i]; 
  
    return water;
    }
};



/*
    Time complexity: O(n).
    Space complexity: O(n).
*/
