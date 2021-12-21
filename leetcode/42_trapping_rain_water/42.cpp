class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int max_left[n];
        max_left[0] = 0;
            
        int max_right[n];
        max_right[n - 1] = 0;
        
        for (int i = 1; i < n; ++i) {
            max_left[i] = max(max_left[i-1], height[i-1]);
            max_right[n - 1 - i] = max(max_right[n - i], height[n - i]);
        }
        
        int area {0};
        for (int i = 0; i < n; ++i) {
            int max_height = min(max_left[i], max_right[i]);
            area += max(0, max_height - height[i]);
        }
        return area;
    }
};
