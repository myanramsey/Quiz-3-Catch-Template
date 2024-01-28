#include <catch2/catch_test_macros.hpp>
#include <iostream>

#include "interquartile_range.h"

using namespace std;
// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
//TEST_CASE("Test 1: Total Number Odd, Q1 & Q3", "[Made]"){
//	// instantiate any class members that you need to test here
//    SECTION("Positive Numbers"){
//        std::vector<int> v = {6, 18, 27, 42, 50, 75, 93};
//        Node* head = nullptr;
//        for(int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 57.00);
//        while (head != nullptr)
//        {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//    SECTION("Negative Numbers"){
//        std::vector<int> v = {-15, -8, -5, -3, 7, 12, 20};
//        Node* head = nullptr;
//        for(int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 20.00);
//        while (head != nullptr)
//        {
//            Node* temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//}
//
//TEST_CASE("Test 2: Odd Total Entires & Even Number of Q1 & Q2", "[Made]"){
//	SECTION("Postive") {
//        std::vector<int> v = {1, 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9,10,11};
//        Node *head = nullptr;
//        for (int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 6.00);
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//	SECTION("Negative") {
//        std::vector<int> v = {-10, -8, -5, -3, 1, 4, 7, 9, 12, 15, 20};
//        Node *head = nullptr;
//        for (int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 17.00);
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//}
//
//TEST_CASE("Test 3: Even Number Entries Odd Quartile", "[Made]"){
//    SECTION("Postive") {
//        std::vector<int> v = {1, 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9,10};
//        Node *head = nullptr;
//        for (int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 5.00);
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    SECTION("Negative") {
//        std::vector<int> v = {-8, -5, -3, 2, 6, 9, 11, 13, 15, 18};
//        Node *head = nullptr;
//        for (int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 16.00);
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//}
//
//TEST_CASE("Test 4: Even Number Entries Even Quartile", "[Made]"){
//    SECTION("Postive") {
//        std::vector<int> v = {1, 2 ,3 ,4 ,5 ,6 ,7 ,8 ,9,10,11,12};
//        Node *head = nullptr;
//        for (int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 6.00);
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    SECTION("Negative") {
//        std::vector<int> v = {-10, -8, -5, -3, 2, 4, 7, 9, 12, 15, 18, 20};
//        Node *head = nullptr;
//        for (int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 17.5);
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//}
//
//TEST_CASE("Test 5: 5 Entries", "[Made]"){
//    SECTION("Postive") {
//        std::vector<int> v = {1, 2 ,3 ,4 ,5};
//        Node *head = nullptr;
//        for (int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 3.00);
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//
//    SECTION("Negative") {
//        std::vector<int> v = {-10, -5, 3, 8, 12};
//        Node *head = nullptr;
//        for (int i: v)
//            head = insertEnd(head, i);
//        REQUIRE(interQuartile(head) == 17.5);
//        while (head != nullptr) {
//            Node *temp = head;
//            head = head->next;
//            delete temp;
//        }
//    }
//}


TEST_CASE("Function: IQR 1", "[given]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 2", "[given]") {
	std::vector<int> v = {1, 2, 3, 4};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2.00);

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


TEST_CASE("Function: IQR 3", "[given]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2441.00);

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 4", "[given]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8, 9, 10};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 4.5);

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 5", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556, 137576};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 55330);

    while (head != nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
