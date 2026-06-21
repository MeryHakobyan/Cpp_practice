#include <iostream>
#include <vector>


void merge(std::vector<int> &nums, int left, int mid, int right){
	int size1 = mid - left + 1;
	int size2 = right - mid;

	std::vector<int> L(size1);
	std::vector<int> R(size2);

	for(int i = 0; i < size1; ++i){
		L[i] = nums[left + i];
	}

	for(int i = 0; i < size2; ++i){
		R[i] = nums[mid + 1 + i];
	}

	int i = 0;
	int j = 0;
	int k = left;
	while(i < size1 && j < size2){
		if(L[i] <= R[j]){
			nums[k++] = L[i++];
		} else {
			nums[k++] = R[j++];
		}
	}

	while(i<size1){
		nums[k++] = L[i++];
	}

	while(j<size2){
		nums[k++] = R[j++];
	}
}

void merge_sort(std::vector<int>& nums, int left, int right){
	if(left>=right) return;

	int mid = left + (right - left)/2;

	merge_sort(nums, left, mid);
	merge_sort(nums, mid+1, right);

	merge(nums, left, mid, right);
}

int main() {
	std::vector<int> nums = {1, 6 , 7 , 3};

	merge_sort(nums, 0, nums.size() - 1);
	for (int x : nums) {
  	  std::cout << x;
	}
	return 0;
}
