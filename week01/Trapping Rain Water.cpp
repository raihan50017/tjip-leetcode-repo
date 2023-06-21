class Solution {
public:
    int trap(vector<int>& height) {
        int leftCurrentIndex = 0, rigthCurrentIndex = height.size()-1, leftMax = 0, rightMax= 0, result = 0;
        while(leftCurrentIndex!=rigthCurrentIndex){
            if(height[leftCurrentIndex]<=height[rigthCurrentIndex]){
                if(leftMax<height[leftCurrentIndex]){
                    leftMax = height[leftCurrentIndex];
                }
                else{
                    result += leftMax - height[leftCurrentIndex];
                }
                leftCurrentIndex++;
            }
            else{
                if(rightMax<height[rigthCurrentIndex]){
                    rightMax = height[rigthCurrentIndex];
                }
                else{
                    result += rightMax - height[rigthCurrentIndex];
                }
                rigthCurrentIndex--;
            }
        }
        return result;
    }
};