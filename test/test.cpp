//#include <catch2/catch_test_macros.hpp>
//#include <iostream>
//#include "AVLTree.h"
//
//using namespace std;
//
//// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
//TEST_CASE("Example Test Name - Change me!", "[flag]"){
//	// instantiate any class members that you need to test here
//	int one = 1;
//
//	// anything that evaluates to false in a REQUIRE block will result in a failing test
//	REQUIRE(one == 1); // fix me!
//
//	// all REQUIRE blocks must evaluate to true for the whole test to pass
//	REQUIRE(true); // also fix me!
//}
//
//TEST_CASE("Test 2", "[flag]"){
//	// you can also use "sections" to share setup code between tests, for example:
//	int one = 1;
//
//	SECTION("num is 2") {
//		int num = one + 1;
//		REQUIRE(num == 2);
//	};
//
//	SECTION("num is 3") {
//		int num = one + 2;
//		REQUIRE(num == 3);
//	};
//
//	// each section runs the setup code independently to ensure that they don't affect each other
//}
//
//// you must write 5 unique, meaningful tests for credit on the testing portion of this project!
//
//// the provided test from the template is below.
//
//TEST_CASE("Edge cases", "[flag]"){
//    AVLTree tree;
//
//    // insert nodes
//    tree.insertNode("A", 2);
//    tree.insertNode("B", 3);
//    tree.insertNode("C",1);
//
//    // test search
//    string actualString = tree.searchByID(0); // search for a non-existent ID
//    string expectedString = "unsuccessful";
//
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//    actualString = tree.removeByID(0); // remove an ID that doesn't exist
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//    actualString = tree.removeAtN(5); // removeInorder at an N higher than the amount of nodes
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//}
//
//TEST_CASE("Rotation cases", "[rotations]"){
//    AVLTree tree;
//    string expectedString;
//    string actualString;
//
//    // insert nodes
//    tree.insertNode("E", 11);
//    tree.insertNode("F", 22);
//    tree.insertNode("G", 33);
//
//    // right right case
//    actualString = tree.inorderTraversal();
//    expectedString = "E, F, G";
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//    // left left case
//    tree.removeByID(33);
//    tree.insertNode("H", 0);
//    actualString = tree.inorderTraversal();
//    expectedString = "H, E, F";
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//    // left right case
//    tree.removeByID(22);
//    tree.insertNode("I", 5);
//    actualString = tree.inorderTraversal();
//    expectedString = "H, I, E";
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//    // right left case
//    tree.removeByID(0);
//    tree.insertNode("J", 7);
//    actualString = tree.inorderTraversal();
//    expectedString = "I, J, E";
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//}
//
//TEST_CASE("Deletion cases", "[deletions]"){
//    AVLTree tree;
//    string expectedString;
//    string actualString;
//
//    // insert nodes
//    tree.insertNode("A", 2);
//    tree.insertNode("B", 3);
//    tree.insertNode("C",1);
//    tree.insertNode("D",0);
//
//    tree.removeByID(1); // remove with 1 child
//    actualString = tree.inorderTraversal();
//    expectedString = "D, A, B";
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//    tree.removeByID(2); // remove with 2 children
//    actualString = tree.inorderTraversal();
//    expectedString = "D, B";
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//    tree.removeAtN(1); // removal with no children
//    actualString = tree.inorderTraversal();
//    expectedString = "D";
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//}
//
//
//TEST_CASE("100 nodes", "[a lot]"){
//    AVLTree tree;
//    string expectedString;
//    string actualString;
//
//    // insert nodes
//    tree.insertNode("zero", 0);
//    tree.insertNode("one", 1);
//    tree.insertNode("two", 2);
//    tree.insertNode("three", 3);
//    tree.insertNode("four", 4);
//    tree.insertNode("five", 5);
//    tree.insertNode("six", 6);
//    tree.insertNode("seven", 7);
//    tree.insertNode("eight", 8);
//    tree.insertNode("nine", 9);
//    tree.insertNode("ten", 10);
//    tree.insertNode("eleven", 11);
//    tree.insertNode("twelve", 12);
//    tree.insertNode("thirteen", 13);
//    tree.insertNode("fourteen", 14);
//    tree.insertNode("fifteen", 15);
//    tree.insertNode("sixteen", 16);
//    tree.insertNode("seventeen", 17);
//    tree.insertNode("eighteen", 18);
//    tree.insertNode("nineteen", 19);
//    tree.insertNode("twenty", 20);
//    tree.insertNode("twenty one", 21);
//    tree.insertNode("twenty two", 22);
//    tree.insertNode("twenty three", 23);
//    tree.insertNode("twenty four", 24);
//    tree.insertNode("twenty five", 25);
//    tree.insertNode("twenty six", 26);
//    tree.insertNode("twenty seven", 27);
//    tree.insertNode("twenty eight", 28);
//    tree.insertNode("twenty nine", 29);
//    tree.insertNode("thirty", 30);
//    tree.insertNode("thirty one", 31);
//    tree.insertNode("thirty two", 32);
//    tree.insertNode("thirty three", 33);
//    tree.insertNode("thirty four", 34);
//    tree.insertNode("thirty five", 35);
//    tree.insertNode("thirty six", 36);
//    tree.insertNode("thirty seven", 37);
//    tree.insertNode("thirty eight", 38);
//    tree.insertNode("thirty nine", 39);
//    tree.insertNode("forty", 40);
//    tree.insertNode("forty one", 41);
//    tree.insertNode("forty two", 42);
//    tree.insertNode("forty three", 43);
//    tree.insertNode("forty four", 44);
//    tree.insertNode("forty five", 45);
//    tree.insertNode("forty six", 46);
//    tree.insertNode("forty seven", 47);
//    tree.insertNode("forty eight", 48);
//    tree.insertNode("forty nine", 49);
//    tree.insertNode("fifty", 50);
//    tree.insertNode("fifty one", 51);
//    tree.insertNode("fifty two", 52);
//    tree.insertNode("fifty three", 53);
//    tree.insertNode("fifty four", 54);
//    tree.insertNode("fifty five", 55);
//    tree.insertNode("fifty six", 56);
//    tree.insertNode("fifty seven", 57);
//    tree.insertNode("fifty eight", 58);
//    tree.insertNode("fifty nine", 59);
//    tree.insertNode("sixty", 60);
//    tree.insertNode("sixty one", 61);
//    tree.insertNode("sixty two", 62);
//    tree.insertNode("sixty three", 63);
//    tree.insertNode("sixty four", 64);
//    tree.insertNode("sixty five", 65);
//    tree.insertNode("sixty six", 66);
//    tree.insertNode("sixty seven", 67);
//    tree.insertNode("sixty eight", 68);
//    tree.insertNode("sixty nine", 69);
//    tree.insertNode("seventy", 70);
//    tree.insertNode("seventy one", 71);
//    tree.insertNode("seventy two", 72);
//    tree.insertNode("seventy three", 73);
//    tree.insertNode("seventy four", 74);
//    tree.insertNode("seventy five", 75);
//    tree.insertNode("seventy six", 76);
//    tree.insertNode("seventy seven", 77);
//    tree.insertNode("seventy eight", 78);
//    tree.insertNode("seventy nine", 79);
//    tree.insertNode("eighty", 80);
//    tree.insertNode("eighty one", 81);
//    tree.insertNode("eighty two", 82);
//    tree.insertNode("eighty three", 83);
//    tree.insertNode("eighty four", 84);
//    tree.insertNode("eighty five", 85);
//    tree.insertNode("eighty six", 86);
//    tree.insertNode("eighty seven", 87);
//    tree.insertNode("eighty eight", 88);
//    tree.insertNode("eighty nine", 89);
//    tree.insertNode("ninety", 90);
//    tree.insertNode("ninety one", 91);
//    tree.insertNode("ninety two", 92);
//    tree.insertNode("ninety three", 93);
//    tree.insertNode("ninety four", 94);
//    tree.insertNode("ninety five", 95);
//    tree.insertNode("ninety six", 96);
//    tree.insertNode("ninety seven", 97);
//    tree.insertNode("ninety eight", 98);
//    tree.insertNode("ninety nine", 99);
//
//    actualString = tree.inorderTraversal();
//
//    expectedString = "zero, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen, twenty, twenty one, twenty two, twenty three, twenty four, twenty five, twenty six, twenty seven, twenty eight, twenty nine, thirty, thirty one, thirty two, thirty three, thirty four, thirty five, thirty six, thirty seven, thirty eight, thirty nine, forty, forty one, forty two, forty three, forty four, forty five, forty six, forty seven, forty eight, forty nine, fifty, fifty one, fifty two, fifty three, fifty four, fifty five, fifty six, fifty seven, fifty eight, fifty nine, sixty, sixty one, sixty two, sixty three, sixty four, sixty five, sixty six, sixty seven, sixty eight, sixty nine, seventy, seventy one, seventy two, seventy three, seventy four, seventy five, seventy six, seventy seven, seventy eight, seventy nine, eighty, eighty one, eighty two, eighty three, eighty four, eighty five, eighty six, eighty seven, eighty eight, eighty nine, ninety, ninety one, ninety two, ninety three, ninety four, ninety five, ninety six, ninety seven, ninety eight, ninety nine";
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//    tree.removeByID(54);
//    tree.removeByID(99);
//    tree.removeByID(1);
//    tree.removeByID(50);
//    tree.removeByID(3);
//    tree.removeByID(8);
//    tree.removeAtN(3);
//    tree.removeAtN(6);
//    tree.removeAtN(9);
//    tree.removeAtN(6);
//
//    expectedString = "zero, two, four, six, seven, twelve, fifteen, sixteen, seventeen, eighteen, nineteen, twenty, twenty one, twenty two, twenty three, twenty four, twenty five, twenty six, twenty seven, twenty eight, twenty nine, thirty, thirty one, thirty two, thirty three, thirty four, thirty five, thirty six, thirty seven, thirty eight, thirty nine, forty, forty one, forty two, forty three, forty four, forty five, forty six, forty seven, forty eight, forty nine, fifty one, fifty two, fifty three, fifty five, fifty six, fifty seven, fifty eight, fifty nine, sixty, sixty one, sixty two, sixty three, sixty four, sixty five, sixty six, sixty seven, sixty eight, sixty nine, seventy, seventy one, seventy two, seventy three, seventy four, seventy five, seventy six, seventy seven, seventy eight, seventy nine, eighty, eighty one, eighty two, eighty three, eighty four, eighty five, eighty six, eighty seven, eighty eight, eighty nine, ninety, ninety one, ninety two, ninety three, ninety four, ninety five, ninety six, ninety seven, ninety eight";
//    actualString = tree.inorderTraversal();
//
//    REQUIRE(actualString.size() == expectedString.size());
//    REQUIRE(actualString == expectedString);
//
//}
//
