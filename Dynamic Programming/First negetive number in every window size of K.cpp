// First negetive number in every window size of K


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution {
public:
	vector<int> negetive(vector<int>& nums, int k) {
		int i =0;
		int j =0;
		int count =0;
		vector<int> ans;
		queue<int> q;
		
		while(j<nums.size()) {
			if(nums[j] < 0)
				q.push(nums[j]);
			if(j-i+1 <k) {
				j++;
			}
			else if(j-i+1 == k) {
				if(q.size() == 0) {
					ans.push_back(0);
				}
				else {
					ans.push_back(q.front());
				}
				
				if(nums[i] == q.front()) {
					q.pop();
				}
				i++;j++;
			}
		}
	return ans;
		
	}
};

int main() {
    vector<int> nums = {12,-1,-7,8,-15,30,16,28};
    int k = 3;

    solution sol;
    vector<int> ans = sol.negetive(nums, k);

    cout << "Output: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}