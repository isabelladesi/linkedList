#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

TEST(test_clear) {
    // Add test code here
    List <int> list1;
    list1.push_back(3);
    list1.push_back(2);
    list1.push_back(1);
    list1.clear();
    ASSERT_TRUE(list1.empty());
}

TEST(test_diff_types) {
    // Add test code here
    List <char> list1;
    list1.push_back('A');
    list1.push_back('B');
    ASSERT_EQUAL(list1.front(), 'A');
    ASSERT_EQUAL(list1.back(), 'B');

    List <double> list2;
    list2.push_back(2.1);
    ASSERT_EQUAL(list2.front(), 2.1);
    ASSERT_EQUAL(list2.back(), 2.1);
}

TEST (test_list_empty) {
    List<int> myList;
    ASSERT_TRUE(myList.empty());
    ASSERT_TRUE(myList.begin() == myList.end());

    List<int> myList2; 
    myList2.push_back(1);
    ASSERT_FALSE(myList2.empty());
    ASSERT_TRUE(myList.begin() == myList.end());
}

TEST (test_list_size) {
    List<int> myList; 
    myList.push_back(1); 
    int size = myList.size();
    ASSERT_EQUAL(size, 1);

    List<int> myList1; 
    myList1.push_back(1);
    myList1.push_front(2);
    myList1.push_back(1);
    myList1.push_front(1);
    myList1.push_back(5);
    myList1.push_front(1); 
    int size1 = myList1.size();
    ASSERT_EQUAL(size1, 6);

    List<int> myList2; 
    int size2 = myList2.size();
    ASSERT_EQUAL(size2, 0);

    List<int> myList3;
    myList3.push_back(5);
    myList3.push_back(20);
    myList3.push_back(9);

    myList3.pop_front();
    myList3.pop_back();
    myList3.pop_front();
    ASSERT_EQUAL(myList.size(), 0);
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

    List<int> myList7;
    myList7.push_front(1);
    myList7.push_front(2);
    ASSERT_TRUE(myList7.front() == 2 && myList7.back() == 1);
    ASSERT_EQUAL(myList7.size(), 2);
    myList7.push_front(9);
    ASSERT_EQUAL(myList7.front(), 9);
    ASSERT_EQUAL(myList7.size(), 3);
    myList7.push_back(11);
    ASSERT_EQUAL(myList7.size(), 4);
    ASSERT_EQUAL(myList7.back(), 11);
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

    List<int> myList3;
    myList3.push_back(9);
    myList3.push_back(22);
    ASSERT_TRUE(myList3.front() == 9 && myList3.back() == 22);
    ASSERT_EQUAL(myList3.size(), 2);
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

    List<int> myList2; 
    myList2.push_back(1); 
    myList2.push_front(2); 
    myList2.back() = 0;
    myList2.front() = 0;
    ASSERT_EQUAL(myList2.front(), 0);
    ASSERT_EQUAL(myList2.back(), 0);

    List<int> myList3; 
    myList3.push_back(1); 
    myList3.front() = 0;
    ASSERT_EQUAL(myList2.front(), 0);
    ASSERT_EQUAL(myList2.back(), 0);

    List<int> myList4; 
    myList4.push_back(1); 
    myList4.back() = 0;
    ASSERT_EQUAL(myList2.front(), 0);
    ASSERT_EQUAL(myList2.back(), 0);

    List<int> myList5;
    myList5.push_back(10);
    ASSERT_EQUAL(myList5.front(), 10);
    ASSERT_EQUAL(myList5.size(), 10);

    List<int> myList6;
    myList6.push_back(10);
    ASSERT_EQUAL(myList6.front(), 10);
    myList6.front() = 9;
    ASSERT_EQUAL(myList6.front(), 9);
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
    l.push_back(3); 

    List<int>::Iterator iterator = l.end();
    l.insert(iterator, 10);

    ASSERT_EQUAL(*++(++(++l.begin())), 10);
}

TEST(test_iterator_InsertEndBack) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3); 

    List<int>::Iterator iterator = l.begin();
    ++iterator;
    l.insert(iterator, 10);

    ASSERT_EQUAL(*(++l.begin()), 10);
    ASSERT_EQUAL(l.back(), 3);
    ASSERT_EQUAL(l.front(), 1);

}

TEST(test_iterator_erase_oneElementList) {
    List<int> l;
    l.push_back(1);

    List<int>::Iterator iterator = l.begin();
    l.erase(iterator);

    ASSERT_TRUE(l.empty());
}

TEST(test_iterator_insert_lastElement) {
    List<int> l;
    l.push_back(1);

    List<int>::Iterator iterator = l.begin();
    l.insert(iterator, 10);
    ASSERT_EQUAL(*(l.begin()), 10);
}

TEST(test_copy) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    List<int> l_copied(l);
  
    List<int>::Iterator l_iterator = l.end();
    List<int>::Iterator l_copied_iterator = l_copied.begin();

    while (l_copied_iterator != l_copied.end()){
        for (l_iterator=l.begin(); l_iterator != l.end(); ++l_iterator) {
            ASSERT_EQUAL(*(l_iterator), *(l_copied_iterator));
            ++l_copied_iterator;
        }
    }
}

TEST(test_list_operator_equalequal_diffLists) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    List<int> l2;
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);

    l = l2;

    List<int>::Iterator l_iterator = l.end();
    List<int>::Iterator l2_iterator = l2.begin();

    while (l2_iterator != l2.end()){
        for (l_iterator=l.begin(); l_iterator != l.end(); ++l_iterator) {
            ASSERT_EQUAL(*(l_iterator), *(l2_iterator));
            ++l2_iterator;
        }
    }
}

TEST(test_list_operator_equal_diff) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    List<int> l2;
    l2.push_back(4);
    l2.push_back(5);
    l2.push_back(6);
    int sizel2 = 3;


    ASSERT_EQUAL(l.size(), l2.size());

    l.push_back(4);
    int sizel = 4;
    ASSERT_NOT_EQUAL(l.size(), l2.size());
    ASSERT_EQUAL(l.size(), sizel);
    ASSERT_EQUAL(l2.size(), sizel2);

    l = l2;

    List<int>::Iterator l_iterator = l.end();
    List<int>::Iterator l2_iterator = l2.begin();

    while (l2_iterator != l2.end()){
        for (l_iterator=l.begin(); l_iterator != l.end(); ++l_iterator) {
            ASSERT_EQUAL(*(l_iterator), *(l2_iterator));
            ++l2_iterator;
        }
    }
}

TEST(test_list_operator_equalequal_equalLists) {
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    List<int> l2;
    l2.push_back(1);
    l2.push_back(2);
    l2.push_back(3);

    l = l2;

    List<int>::Iterator l_iterator = l.end();
    List<int>::Iterator l2_iterator = l2.begin();

    while (l2_iterator != l2.end()){
        for (l_iterator=l.begin(); l_iterator != l.end(); ++l_iterator) {
            ASSERT_EQUAL(*(l_iterator), *(l2_iterator));
            ++l2_iterator;
        }
    }
}

TEST(test_iterator_insert_beginning) {
    List<int> l;
    l.push_back(11);
    l.push_back(10);
    
    List<int>::Iterator iterator = l.begin();

    l.insert(iterator, 2);

    ASSERT_EQUAL(l.size(), 3);
    ASSERT_EQUAL(l.front(), 2);
    ASSERT_EQUAL(*(++l.begin()), 11);
    ASSERT_EQUAL(l.back(), 10);

    l.erase(iterator);
    ASSERT_EQUAL(l.size(), 2);
    ASSERT_EQUAL(l.front(), 2);
}

TEST(test_iterator_loop) {
    List<int> myList;
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(6);

    int expectedval = 4;
    for (List<int>::Iterator iterator = myList.begin(); \
    iterator != myList.end(); ++iterator) {
        ASSERT_EQUAL(*iterator, expectedval);
        ++expectedval;
    }
}




TEST_MAIN()
