/*
nums[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 }
target = 8

Subarrays with sum 8 are
{ -5, 5, 3, 5 }
{ 3, 5 }
{ 5, 3 }

The longest subarray is { -5, 5, 3, 5 } having length 4
*/

#include <iostream>
#include <unordered_map>
using namespace std;

// Function to find the maximum length subarray with sum `S` present
// in a given array
void findMaxLenSubarray(int nums[], int n, int S) {
	// create an empty map to store the ending index of the first subarray
	// having some sum
	unordered_map<int, int> map;
	
	// insert (0, -1) pair into the set to handle the case when a
	// subarray with the sum `S` starts from index 0
	map[0] = -1;
	
	int target = 0;
	
	// `len` stores the maximum length of subarray with sum `S`
	int len = 0;
	
	// stores ending index of the maximum length subarray having sum `S`
	int ending_index = -1;
	
	// traverse the given array
	for(int i = 0 ; i < n ; ++ i) {
		// sum of elements so far
		target += nums[i];
		
		// if the sum is seen for the first time, insert the sum with it
		// into the map
		if(map.find(target) == map.end()) map[target] = i;
		
		// update the length and ending index of the maximum length subarray
		// having sum `S`
		if(map.find(target - S) != map.end() && len < i - map[target - S]) {
			len = i - map[target - S];
			ending_index = i;
		}
	}
	
	// print the subarray
	cout << "[" << (ending_index - len + 1) << ", " << ending_index << "]" << endl;
}

int main() {
	int nums[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
	int target = 8;
	
	int n = sizeof(nums) / sizeof(nums[0]);
	
	findMaxLenSubarray(nums, n, target);
	
	return 0;
}