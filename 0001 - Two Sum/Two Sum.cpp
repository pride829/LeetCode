class Solution {
public:

	// Using map
	static std::vector<int> twoSum(std::vector<int>& nums, int target) {

		int q = 0;
		std::map<int, int> nums_map;

		// Build a map to nums
		for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
			nums_map[*it] = q++;

		for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {

			if (std::distance(nums.begin(), it) != nums_map.find(target - *it)->second && nums_map.find(target - *it) != nums_map.end()) {

				const int index0 = std::distance(nums.begin(), it);
				const int index1 = nums_map.find(target - *it)->second;
				int ans_ints[] = { index0,index1 };
				return std::vector<int>(ans_ints, ans_ints + sizeof(ans_ints) / sizeof(int));

			}

		}



		// Retrun empty value
		return std::vector<int>();
	}

};