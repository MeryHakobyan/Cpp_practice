#include <iostream>
#include <vector>

bool binary_search(std::vector<int> &nums, int target){
	int left = 0;
	int right = nums.size() -1;

	while(left<=right){
		int mid = left + (right - left)/2;
	
	if(target<nums[mid]){
		right = mid - 1;
	} else if(target>nums[mid]){
		left = mid + 1;
	  } else{
		return true;
	    }
	}

	return false;
}

int main() {
std::vector<int> nums = {1, 2, 3, 6};
int found = binary_search(nums, 4);
std::cout<<found;
return 0;
}
