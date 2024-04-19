/*
Given an integer array, check if it contains a subarray having zero-sum.

For example,

Input:  { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }
Output: Subarray with zero-sum exists



The subarrays with a sum of 0 are:
{ 3, 4, -7 }
{ 4, -7, 3 }
{ -7, 3, 1, 3 }
{ 3, 1, -4 }
{ 3, 1, 3, 1, -4, -2, -2 }
{ 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }
*/

#include <iostream>
#include <unordered_map>
using namespace std;


// function to find a pair in an array with a given sum
void findPair(int nums[], int n, int target) {
	//	create an empty map
	unordered_map<int, bool> map;
	
	for(int i = 0 ; i < n ; ++ i) {
		// check if the pair exists
		if(map.find(target - nums[i]) != map.end())	 {
			cout << "Pair found: (" << target - nums[i] << ", " << nums[i] << ")" << endl;
			return;
		}
		// sign the current element in the map
		map[nums[i]] = true;
	}
	cout << "Pair not found" << endl;
}

int main() {
	int nums[] = { 8, 7, 2, 5, 3, 1 };
	int target = 10;
	
	int n = sizeof(nums) / sizeof(nums[0]);
	findPair(nums, n, target);
	return 0;
}