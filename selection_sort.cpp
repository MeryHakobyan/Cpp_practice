#include <iostream>
#include <vector>

void selection_sort(std::vector<int>& arr){
	int n = arr.size();
	for(int i = 0; i<n-1; ++i){
		int min = i;
		for(int j = i+1; i<n; ++j){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		std::swap(arr[i], arr[min]);
	}
}

int main() {
	std::vector<int> arr = {64, 25, 0, 1, 67};
	selection_sort(arr);
	for(int a: arr){
		std::cout<<a;
	}
	return 0;

}
