#include <iostream>
using namespace std;
#include <vector>
class solution {
public:
	int windowsize(vector<int> nums, int k) {
		int i =0; int j =0;
		int sum =0; int maxi =0;
		
		while(j<nums.size()) {
			sum = sum + nums[j];
			if (sum <k) {
				j++;
			}
			else if(sum == k) {
				maxi = max(maxi, j-i+1);
				j++;
			}
			else if (sum >k) {
				while(sum > k ){
					sum = sum - nums[i];
					i++;
				}
				j++;
			}
		}
	return maxi;
	}	
};
int main() {
	vector<int> nums = {4,1,1,1,2,3,5};
	int k = 5;
	solution sol;
	int maxi = sol.windowsize(nums, k);
	cout << maxi;
	return 0;
}


/*int main() {
	vector<int> nums = {-5,8,-14,2,4,12};
	int k = -5;
	solution sol;
	int maxi = sol.windowsize(nums, k);
	cout << maxi;
	return 0;
} *///for the negetive part