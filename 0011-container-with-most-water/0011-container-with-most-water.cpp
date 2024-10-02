class Solution {
public:
    int maxArea(vector<int>& height) {
        // two pointer approach
        int l = 0; // left
        int r = height.size() - 1; // right
        int w; // width
        int h; // height
        int maxA = 0; // store the max at any given point
        while(l < r){
            w = r - l;
            h = min(height[l],height[r]);
            maxA = max(maxA, h * w);
            //cout << "h : " << h << ", w: " << w << " ";
            //cout << "area: " << h * w << " , maxA: " << maxA << endl;
            if(height[l] < height[r]){
                l++;
            } else if(height[r] < height[l]){
                r--;
            } else {
                l++;
            }
        }
        return maxA;
    }
};