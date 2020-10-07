#include <vector>
#include <iostream>
#include <map>

class Probelm_1 {

	class Solution0 {
	public:

		// Using brute force to solve the problem
		static std::vector<int> twoSum(std::vector<int>& nums, int target) {

			// Traverse through the vector
			for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {

				for (std::vector<int>::iterator it2 = it + 1; it2 != nums.end(); ++it2) {

					if (*it + *it2 == target) {

						//Using std::distance to get the index
						const int index0 = std::distance(nums.begin(), it);
						const int index1 = std::distance(nums.begin(), it2);

						//Array can only be constructed with constant?
						int ans_ints[] = { index0,index1 };
						return std::vector<int>(ans_ints, ans_ints + sizeof(ans_ints) / sizeof(int));
					}
				}
			}

			// Return empty value
			return std::vector<int>();
		}
	};

	class Solution1 {
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


public:
	static void solve() {

		int intsforvector[] = { 3, 2, 4 };
		std::vector<int> input_v(intsforvector, intsforvector + sizeof(intsforvector) / sizeof(int));

		std::vector<int> ans = Solution1().twoSum(input_v, 6);

		for (std::vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
			std::cout << *it << " ";
		}

	}

};