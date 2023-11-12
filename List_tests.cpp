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

TEST (test_empty_list) {
List<int> myList;
ASSERT_TRUE(myList.empty());
}

TEST (test_not_empty_list) {
List<int> myList; myList.push_back(1);
ASSERT_FALSE (myList .empty() )
}

TEST (test_empty_list_pop_front) {
List<int> myList; myList.push_back(1); myList.push_back(2); myList.push_back(3); myList.push_back(4); myList.push_back (5);
int size = mylist.size h
for(int i = 0; i < size; i++)
myList.pop_ front O
ASSERT_TRUE (myList.empty())
}

TEST_MAIN()
