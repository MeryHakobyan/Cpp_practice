#include <iostream>
#include <vector>

bool binary_search(std::vector<int> &nums, int left, int right, int target){
    if(left>right) return false;

    int mid = left + (right - left)/2;
    if(target > nums[mid]){
        return binary_search(nums, mid + 1, right, target);
    } else if(target < nums[mid]){
        return binary_search(nums, left, mid - 1, target);
      } else{
        return true;
    }
}

int main(){
    std::vector<int> nums = {1, 2, 3, 4};
    int found = binary_search(nums, 0, nums.size() - 1, 2);
    std::cout<<found;
  
    return 0;
}
