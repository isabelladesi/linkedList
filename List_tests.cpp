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

TEST (test_list_empty) {
    List<int> myList;
    ASSERT_TRUE(myList.empty());

    List<int> myList2; 
    myList2.push_back(1);
    ASSERT_FALSE(myList2.empty())
}

TEST (test_list_size) {
    List<int> myList; 
    myList.push_back(1); 
    int size = myList.size();
    ASSERT_EQUAL(size, 1);

    List<int> myList2; 
    int size2 = myList2.size();
    ASSERT_EQUAL(size2, 0);
}

TEST (test_list_push_front) {
    List<int> myList; 
    myList.push_front(1); 
    myList.push_front(2); 
    myList.push_front(3);
    int size = myList.size(); 
    ASSERT_EQUAL(myList.front(), 3);
    ASSERT_EQUAL(myList.back(), 1);
    ASSERT_EQUAL(size, 3);

    List<int> myList2; 
    myList2.push_front(1); 
    int size2 = myList2.size();
    ASSERT_EQUAL(myList2.front(), 1);
    ASSERT_EQUAL(myList2.back(), 1);
    ASSERT_EQUAL(size2, 1);
}

TEST (test_list_push_back) {
    List<int> myList; 
    myList.push_back(1); 
    myList.push_back(2); 
    myList.push_back(3); 
    ASSERT_EQUAL(myList.front(), 1);
    ASSERT_EQUAL(myList.back(), 3);

    List<int> myList2; 
    myList2.push_back(1); 
    int size2 = myList2.size();
    ASSERT_EQUAL(myList2.front(), 1);
    ASSERT_EQUAL(myList2.back(), 1);
    ASSERT_EQUAL(size2, 1);
}

TEST (test_list_pop_front) {
    List<int> myList; 
    myList.push_back(1); 
    myList.push_back(2); 
    myList.push_back(3); 
    int size = myList.size();
    for(int i = 0; i < size; i++){
        myList.pop_front();
    }
    ASSERT_TRUE(myList.empty());

    List<int> myList2; 
    myList2.push_back(1); 
    myList2.push_back(2); 
    myList2.push_back(3); 
    myList2.pop_front();
    int size2 = myList2.size();
    ASSERT_EQUAL(myList2.front(), 2);
    ASSERT_EQUAL(myList2.back(), 3);
    ASSERT_EQUAL(size2, 2);

    List<int> myList3; 
    myList3.push_back(3); 
    myList3.push_back(2); 
    myList3.pop_front();
    int size3 = myList3.size();
    ASSERT_EQUAL(myList3.front(), 2);
    ASSERT_EQUAL(myList3.back(), 2);
    ASSERT_EQUAL(size3, 1);

    List<int> myList4; 
    myList4.push_back(1); 
    myList4.pop_front();
    ASSERT_TRUE(myList4.empty());
}

//**this test doesnt work for some reason
TEST (test_pop_back) {
    List<int> myList; 
    myList.push_back(1); 
    myList.push_back(2); 
    myList.push_back(3); 
    int size = myList.size();
    for(int i = 0; i < size; i++){
        myList.pop_back();
    }
    ASSERT_TRUE(myList.empty());

    List<int> myList2; 
    myList2.push_back(1); 
    myList2.push_back(2); 
    myList2.push_back(3); 
    myList2.pop_back();
    int size2 = myList2.size();
    ASSERT_EQUAL(myList2.front(), 1);
    ASSERT_EQUAL(myList2.back(), 2);
    ASSERT_EQUAL(size2, 2);

    List<int> myList3; 
    myList3.push_back(3); 
    myList3.push_back(2); 
    myList3.pop_back();
    int size3 = myList3.size();
    ASSERT_EQUAL(myList3.front(), 3);
    ASSERT_EQUAL(myList3.back(), 3);
    ASSERT_EQUAL(size3, 1);

    List<int> myList4; 
    myList4.push_back(1); 
    myList4.pop_back();
    ASSERT_TRUE(myList4.empty());
}

TEST (test_list_clear) {
    List<int> myList; 
    myList.push_back(1); 
    myList.push_back(2); 
    myList.push_back(3); 
    myList.clear();
    int size = myList.size();
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(size, 0);

    List<int> myList2; 
    myList2.clear();
    int size2 = myList2.size();
    ASSERT_TRUE(myList2.empty());
    ASSERT_EQUAL(size2, 0);
}

TEST (test_front_back) {
    List<int> myList; 
    myList.push_back(1); 
    myList.push_front(2); 
    myList.push_back(3); 
    ASSERT_EQUAL(myList.front(), 2);
    ASSERT_EQUAL(myList.back(), 3);
}

TEST(test_iterator_PlusMinusDeref) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    List<int>::Iterator iterator = l.begin();
    ++iterator;
    ASSERT_EQUAL(*(iterator), 2);
    --iterator;
    ASSERT_EQUAL(*(iterator), 1);
}


TEST(test_iterator_equalNotEqualOp) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    List<int>::Iterator iterator = l.begin();
    List<int>::Iterator iteratorSame = l.begin();
    assert(iterator == iteratorSame);
    ++iteratorSame; 

    assert(iterator != iteratorSame);

}

TEST(test_iterator_insert) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    List<int>::Iterator iterator = l.begin();
    ++iterator;
    ++iterator;

    l.insert(iterator, 10);
    ASSERT_EQUAL(*(++(++l.begin())), 10);
}

TEST(test_iterator_erase) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3); //getting erased
    l.push_back(4);
    l.push_back(5);

    List<int>::Iterator iterator = l.begin();
    ++iterator;
    ++iterator;

    l.erase(iterator);
    ASSERT_EQUAL(*(++(++l.begin())), 4);
}

TEST(test_iterator_InsertAndEnd) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3); //getting erased


    List<int>::Iterator iterator = l.end();
    l.insert(iterator, 10);


    //assert(*iterator == null_ptr);
    ASSERT_EQUAL(*++(++(++l.begin())), 10);
}

TEST(test_iterator_erase_oneElementList) {
    List<int> l;
    l.push_back(1);
    


    List<int>::Iterator iterator = l.begin();
    l.erase(iterator);


    //assert(*iterator == null_ptr);
    ASSERT_TRUE(l.empty());
}

//not done yet
// TEST(test_iterator_insert_lastElement) {
//     List<int> l;
//     l.push_back(1);
    


//     List<int>::Iterator iterator = l.begin();
//     l.insert(iterator, 10);


//     //assert(*iterator == null_ptr);
//      ASSERT_EQUAL(*(l.begin()), 10);
// }


TEST_MAIN()
