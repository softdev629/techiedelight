/*
Given a binary array, sort it in linear time and constant space. The output should print all zeros, followed by all ones.

For example,

Input:  { 1, 0, 1, 0, 1, 0, 0, 1 }
Output: { 0, 0, 0, 0, 1, 1, 1, 1 }
*/

#include <stdio.h>

// Function to sort binary array in linear time
void sort(int nums[], int n) {
	// `k` stores index of next available position
	int k = 0;
	
	// do for each element
	for (int i = 0 ; i < n ; ++ i) {
		// if current element is zero, put 0 at the next free
		// position in the array
		if(nums[i] == 0)
			nums[k ++] = 0;	
	}
	
	// find all the remaining indices by 1
	while(k < n) {
		nums[k ++] = 1;
	}
}

int main() {
	int nums[] = { 1, 0, 1, 0, 1, 0, 0, 1 };
	int n = sizeof(nums) / sizeof(nums[0]);
	sort(nums, n);
	
	// print the rearranged array
	for(int i = 0 ; i < n ; ++ i) printf("%d ", nums[i]);
	return 0;
}