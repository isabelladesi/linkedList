#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

TEST(test_empty_list) {
    List<int> myList;
    ASSERT_EQUAL(myList.size(), 0);
    ASSERT_TRUE(myList.empty());
    ASSERT_TRUE(myList.begin() == myList.end());
}

TEST(test_not_empty_list) {
    List<int> myList;
    myList.push_back(1);
    ASSERT_EQUAL(myList.size(), 1);
    ASSERT_FALSE(myList.empty());
    ASSERT_EQUAL(myList.front(), 1);
    ASSERT_EQUAL(myList.back(), 1);
}

TEST(test_empty_list_pop_front) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    int size = myList.size();
    for(int i = 0; i < size; i++) {
        myList.pop_front();
    }
    ASSERT_EQUAL(myList.size(), 0);
    ASSERT_TRUE(myList.empty());
}

TEST(test_empty_list_pop_back) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    int size = myList.size();
    for(int i = 0; i < size; i++) {
        myList.pop_back();
    }
    ASSERT_EQUAL(myList.size(), 0);
    ASSERT_TRUE(myList.empty());
}

TEST(test_size) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    ASSERT_EQUAL(myList.size(), 5);
}

TEST(test_size_empty) {
    List<int> myList;
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);

    myList.pop_front();
    myList.pop_back();
    myList.pop_front();
    ASSERT_EQUAL(myList.size(), 0);
}

TEST(test_size_empty_after_removal) {
    List<int> myList;
    ASSERT_EQUAL(myList.size(), 0);
}

TEST(test_front) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    ASSERT_EQUAL(myList.front(), 1);
}

TEST(test_front_for_1) {
    List<int> myList;
    myList.push_back(1);
    ASSERT_EQUAL(myList.front(), 1);
    myList.front() = 10;
    ASSERT_EQUAL(myList.front(), 10);
}

TEST(test_front_long) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    ASSERT_EQUAL(myList.front(), 1);
    ASSERT_EQUAL(myList.size(), 15);
}

TEST(test_back) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    ASSERT_EQUAL(myList.size(), 5);
    ASSERT_EQUAL(myList.back(), 5);
    myList.back() = 6;
    ASSERT_EQUAL(myList.back(), 6);
}

TEST(test_back_for_1) {
    List<int> myList;
    myList.push_back(1);
    ASSERT_EQUAL(myList.front(), 1);
    ASSERT_EQUAL(myList.size(), 1);
}

TEST(test_back_long) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);
    ASSERT_EQUAL(myList.size(), 15);
    ASSERT_EQUAL(myList.back(), 5);
}

TEST(test_push_front) {
    List<int> myList;
    myList.push_front(1);
    ASSERT_EQUAL(myList.size(), 1);
    ASSERT_EQUAL(myList.front(), 1);
}

TEST(test_front2) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    ASSERT_EQUAL(myList.front(), 1);
    myList.front() = 4;
    ASSERT_EQUAL(myList.front(), 4);
    ASSERT_EQUAL(myList.size(), 3);
}

TEST(test_push_front_twice) {
    List<int> myList;
    myList.push_front(1);
    myList.push_front(2);
    ASSERT_TRUE(myList.front() == 2 && myList.back() == 1);
    ASSERT_EQUAL(myList.size(), 2);
    myList.push_front(3);
    ASSERT_EQUAL(myList.front(), 3);
    ASSERT_EQUAL(myList.size(), 3);
    myList.push_back(4);
    ASSERT_EQUAL(myList.size(), 4);
    ASSERT_EQUAL(myList.back(), 4);
}

TEST(test_push_back) {
    List<int> myList;
    myList.push_back(1);
    ASSERT_EQUAL(myList.back(), 1);
    ASSERT_EQUAL(myList.front(), 1);
    ASSERT_EQUAL(myList.size(), 1);
}

TEST(test_push_back_twice) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    ASSERT_TRUE(myList.front() == 1 && myList.back() == 2);
    ASSERT_EQUAL(myList.size(), 2);
}

TEST(test_pop_front) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(4);  
    ASSERT_EQUAL(myList.size(), 3);
    myList.pop_front();
    ASSERT_TRUE(myList.front() == 2 && myList.back() == 4);
    ASSERT_EQUAL(myList.size(), 2);

    myList.pop_back();
    ASSERT_TRUE(myList.front() == 2);
    ASSERT_TRUE(myList.back() == 2);
    ASSERT_EQUAL(myList.size(), 1);

    myList.pop_front();
    ASSERT_TRUE(myList.size() == 0);
}

TEST(test_pop_front_empty) {
    List<int> myList;
    myList.push_back(1); 
    myList.pop_front();
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(myList.size(), 0);
}

TEST(test_pop_back) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(4);  
    ASSERT_EQUAL(myList.size(), 3);
    myList.pop_back();
    ASSERT_TRUE(myList.front() == 1 && myList.back() == 2);
    ASSERT_EQUAL(myList.size(), 2);
}

TEST(test_pop_back_empty) {
    List<int> myList;
    myList.push_back(1); 
    myList.pop_back();
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(myList.size(), 0);
}

TEST(test_one_element) {
    List<int> myList;
    myList.push_back(500);
    ASSERT_EQUAL(myList.front(), 500);
    ASSERT_EQUAL(myList.back(), 500);
    ASSERT_EQUAL(myList.size(), 1);

    myList.pop_front();
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(myList.size(), 0);
}

TEST(test_begin) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    ASSERT_EQUAL(myList.size(), 2);

    myList.erase(myList.begin());
    ASSERT_EQUAL(myList.front(), 2);
    ASSERT_EQUAL(myList.size(), 1);

    myList.erase(myList.begin());
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(myList.size(), 0);
}

TEST(test_copy_constructor_and_assignment) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    ASSERT_EQUAL(myList.size(), 3);

    List<int> copyList(myList);
    ASSERT_EQUAL(copyList.size(), myList.size());
    ASSERT_EQUAL(copyList.front(), myList.front());
    ASSERT_EQUAL(copyList.back(), myList.back());
    myList.push_back(5);
    ASSERT_NOT_EQUAL(copyList.size(), myList.size());
    ASSERT_EQUAL(copyList.front(), myList.front());
    ASSERT_NOT_EQUAL(copyList.back(), myList.back());

    List<int> List;
    List = myList;
    ASSERT_EQUAL(List.size(), myList.size());
    ASSERT_EQUAL(List.front(), myList.front());
    ASSERT_EQUAL(List.back(), myList.back());
    List.push_front(5);
    ASSERT_NOT_EQUAL(List.size(), myList.size());
    ASSERT_NOT_EQUAL(List.front(), myList.front());
    ASSERT_EQUAL(List.back(), myList.back());

}


TEST(test_iterator) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    myList.push_back(5);

    ASSERT_EQUAL(myList.size(), 5);
    ASSERT_EQUAL(myList.front(), 1);
    ASSERT_EQUAL(myList.back(), 5);

    List<int>::Iterator iteration = myList.begin();
    ++iteration;

    myList.insert(iteration, 500);
    ASSERT_EQUAL(*(++myList.begin()), 500);
    ASSERT_EQUAL(myList.size(), 6);

    myList.insert(iteration, 200);
    ASSERT_EQUAL(*(++++myList.begin()), 200);
    ASSERT_EQUAL(myList.size(), 7);

    //test copy ctor
    List<int>::Iterator iteration2(iteration);
    ASSERT_TRUE(iteration == iteration2);
}


TEST(test_iterator_operations) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    ASSERT_EQUAL(myList.size(), 3);

    List<int>::Iterator iteration = myList.begin();
    ASSERT_EQUAL(*iteration, 1);
    ++iteration;
    ASSERT_EQUAL(*iteration, 2);
    --iteration;
    ASSERT_EQUAL(*iteration, 1);

    List<int>::Iterator iteration2 = myList.begin();
    ASSERT_TRUE(iteration == iteration2);
    ASSERT_FALSE(iteration != iteration2);
}

TEST(test_iterator_assigmnent) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    List<int>::Iterator iteration = myList.begin();
    List<int>::Iterator iteration2 = myList.begin();
    ASSERT_TRUE(*iteration == 1 && *iteration2 == 1);
    ASSERT_EQUAL(*iteration, *iteration2);

    ++iteration;
    iteration2 = iteration;
    ASSERT_EQUAL(*iteration, *iteration2);
   
    ++iteration2;
    ASSERT_NOT_EQUAL(*iteration, *iteration2);
    ASSERT_TRUE(iteration != iteration2);

    myList.pop_front();
    ASSERT_EQUAL(*iteration2, 3);
    ASSERT_EQUAL(*iteration, 2);
}

TEST(test_iterator_end) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    List<int>::Iterator iteration = myList.begin();
    int count = 0;
    while (count < 3) {
        ++iteration;
        ++count;
    }

    ASSERT_EQUAL(iteration, myList.end());
}

TEST(test_iterator_empty){
    List<int> myList;
    List<int>::Iterator iteration = myList.begin();
    ASSERT_TRUE(iteration == myList.begin());
    ASSERT_TRUE(iteration == myList.end());

    ASSERT_TRUE(myList.begin() == myList.end());
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(myList.size(), 0);
}


TEST(test_iterator_end2) {
    List<int> l;
    l.push_back(8);
    l.push_back(9);
    l.push_back(10);

    List<int>::Iterator iterator = l.begin();
    for (int x=0; x<3; ++x){
        ++iterator;
    }

    ASSERT_EQUAL(iterator, l.end());
}

TEST(test_iterator_empty2){
    List<int> l;
    ASSERT_EQUAL(l.size(), 0);
    ASSERT_TRUE(l.begin() == l.end());
    ASSERT_TRUE(l.empty());
    List<int>::Iterator iterator = l.begin();
    ASSERT_TRUE(iterator == l.begin());
    ASSERT_TRUE(iterator == l.end());
}

TEST(test_iterator_insert_beginning) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(4);
    
    List<int>::Iterator position = myList.begin();

    myList.insert(position, 2);

    ASSERT_EQUAL(myList.size(), 3);
    ASSERT_EQUAL(myList.front(), 2);
    ASSERT_EQUAL(*(++myList.begin()), 1);
    ASSERT_EQUAL(myList.back(), 4);

    myList.erase(position);
    ASSERT_EQUAL(myList.size(), 2);
    ASSERT_EQUAL(myList.front(), 2);
}

TEST(test_iterator_loop) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    int expectedval = 1;
    for (List<int>::Iterator iterator = myList.begin(); \
    iterator != myList.end(); ++iterator) {
        ASSERT_EQUAL(*iterator, expectedval);
        ++expectedval;
    }
}


TEST(test_clear) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(1);
    myList.push_back(2);
    ASSERT_EQUAL(myList.size(), 4);
    myList.clear();
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(myList.size(), 0);
    myList.clear();
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(myList.size(), 0);
    myList.push_back(10);
    myList.push_front(5);
    myList.push_back(1);
    ASSERT_TRUE(myList.size() == 3);
    myList.clear();
    ASSERT_TRUE(myList.empty());
    ASSERT_EQUAL(myList.size(), 0);
}

TEST(test_lists) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(1);
    myList.push_back(2);
    ASSERT_EQUAL(myList.size(), 4);

    List<int> newList(myList);
    ASSERT_EQUAL(myList.size(), newList.size());
    ASSERT_EQUAL(myList.front(), newList.front());
    ASSERT_EQUAL(myList.back(), newList.back());
}

TEST(test_lists_again) {
    List<int> myList;
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(1);
    myList.push_back(2);
    ASSERT_EQUAL(myList.size(), 4);

    List<int> myListAGAIN;
    myListAGAIN.push_back(1);

    myListAGAIN = myList;
    ASSERT_EQUAL(myListAGAIN.size(), myList.size());
}

TEST(test_different_data_types){
    List<double> doubleList;
    doubleList.push_back(0.5);
    doubleList.push_back(2.5);
    ASSERT_EQUAL(doubleList.front(), 0.5);
    ASSERT_EQUAL(doubleList.back(), 2.5);

    List<char> charList;
    charList.push_back('a');
    charList.push_back('b');
    ASSERT_EQUAL(charList.front(), 'a');
    ASSERT_EQUAL(charList.back(), 'b');
}

TEST_MAIN()
