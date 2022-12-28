#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> results;
    for (int i = 0; i < nums.size(); ++i) {
        int match = target - nums[i];
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[j] == match) {
                for (int index_match: {i, j})
                    results.push_back(index_match);
            }

        }
    }
    return results;
}


int main() {
    int n, target, v;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        cin >> v;
        nums.push_back(v);
    }

    cin >> target;
    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indies: " << endl;
        for (int i: result) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << "No matches found" << endl;
    }
}