#include "Class.h"

int main() {
    std::vector<int> nums = {5, 3, 7, 2, 8, 1, 6};

    auto min_it = my::min_element(nums.begin(), nums.end());
    if (min_it != nums.end()) {
        std::cout << "Min value: " << *min_it << std::endl;
    }

    LessThan<int> less_than_5(5);
    auto min_if_it = min_element_if(nums.begin(), nums.end(), less_than_5);
    if (min_if_it != nums.end()) {
        std::cout << "The minimum value that satisfies the condition: " << *min_if_it << std::endl;
    }

    return 0;
}
