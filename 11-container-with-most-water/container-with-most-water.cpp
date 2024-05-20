class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0, l=0,h=height.size()-1;
        while(l<h)
        {
            area=max(area,min(height[l],height[h])*abs(l-h));
            if(height[l]<=height[h])
                l++;
            else if(height[l]>height[h])
                h--;
        }
        return area;
    }
};