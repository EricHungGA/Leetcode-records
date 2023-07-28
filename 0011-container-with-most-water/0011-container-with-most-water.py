class Solution:
    def maxArea(self, height: List[int]) -> int:
        #utilize 2 pointer approach starting points being left and right pointers
        left = 0
        right = len(height) - 1

        #calculate the area of each instance of our pointers, and then overwrite the max area each time we iterate over the bar heights and move our pointers
        max_area = 0

        while left < right:
            width = right - left
            h = min(height[left], height[right])
            area = width * h
            max_area = max(area, max_area)
            # print(f'left = {left} , right = {right}, width = {width}, area = {area}')
            #increment pointers for whichever is smaller to move towards the center
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
            
        return max_area