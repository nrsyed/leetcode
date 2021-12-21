class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0;
        int j = heights.size() - 1;
        
        int max_area = 0;
        
        while (i < j) {
            int width {j - i};
            
            int height;
            if (heights[i] > heights[j]) {
                height = heights[j];
                --j;
            } else {
                height = heights[i];
                ++i;
            }
            
            max_area = max(max_area, width * height);
        }
        
        return max_area;
    }
};
