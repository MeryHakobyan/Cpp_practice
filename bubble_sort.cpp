#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &arr){
		int n = arr.size();
	for(int i=0; i<n-1; i++){
		bool swap=0;
		for(int j=0; j<n-1-i; ++j){
			if(arr[j] > arr[j+1]){
				std::swap(arr[j], arr[j+1]);
				swap = 1;
			}
		}

		if(!swap){
			break;
		}
	}
}

int main() {
std::vector<int> arr = {9, 10, 7, 5, 1};
bubble_sort(arr);

for(int a: arr){
	std::cout<<a;
}

return 0;
}
