#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_stub) {
    // Add test code here
    List <int> list1;
    list1.push_back(3);
    list1.push_back(2);
    list1.push_back(1);
    list1.clear();
    ASSERT_TRUE(list1.empty());
}

TEST_MAIN()
