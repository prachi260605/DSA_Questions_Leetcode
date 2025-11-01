class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(auto it : nums){
            minheap.push(it);
            if(minheap.size()>k){
                minheap.pop();
            }
        }
        return minheap.top();
        
    }
};