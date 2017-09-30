#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "binarytreetemplate.h"
#include "stacktemplate.h"

using namespace std;

// The fixture for testing class Foo.
class TempTest : public ::testing::Test {
protected:

    // You can remove any or all of the following functions if its body

    // is empty.


    TempTest() {

        // You can do set-up work for each test here.
        intTree = new BinaryTreeTemplate<int>(10);
        doubleTree = new BinaryTreeTemplate<double>();
        charTree = new BinaryTreeTemplate<char>();

        intStack = new StackTemplate<int>();
        charStack = new StackTemplate<char>();
        strStack = new StackTemplate<string>();

    }


    virtual ~TempTest() {

        // You can do clean-up work that doesn't throw exceptions here.
        delete intTree;
        delete doubleTree;
        delete charTree;

        delete intStack;
        delete charStack;
        delete strStack;
    }


    // If the constructor and destructor are not enough for setting up

    // and cleaning up each test, you can define the following methods:


    virtual void SetUp() {

        // Code here will be called immediately after the constructor (right

        // before each test).
    }


    virtual void TearDown() {

        // Code here will be called immediately after each test (right

        // before the destructor).
    }


    // Objects declared here can be used by all tests in the test case for Foo.
    BinaryTreeTemplate<int>* intTree;
    BinaryTreeTemplate<double>* doubleTree;
    BinaryTreeTemplate<char>* charTree;

    StackTemplate<int>* intStack;
    StackTemplate<char>* charStack;
    StackTemplate<string>* strStack;
};

//Test if testing works
TEST_F(TempTest, TESTTESTTEST) {

    if (true) {

        ASSERT_TRUE(true);
    }
}

//Test if constuctor works
TEST_F(TempTest, CONSTRUCTORHEADTEST) {

    ASSERT_TRUE(intTree->contains(10));
}

//Test if basic constructor works
TEST_F(TempTest, CONSTRUCTORBASICTEST) {

    ASSERT_TRUE(charTree->getHead() == nullptr);
    ASSERT_TRUE(doubleTree->getHead() == nullptr);
}

//Test if adding the head works
TEST_F(TempTest, INTADDTEST2) {

    intTree->remove(10);
    ASSERT_TRUE(intTree->add(2));
    ASSERT_EQ(*(intTree->getHead()), 2);
}

//Test if adding to the left of the head works
TEST_F(TempTest, INTADDTEST3) {

    ASSERT_TRUE(intTree->add(2));
    ASSERT_TRUE(intTree->contains(2));
    ASSERT_EQ((intTree->head->left->data), 2);
}

//Test if adding the right of the head works
TEST_F(TempTest, INTADDTEST4) {

    ASSERT_TRUE(intTree->add(12));
    ASSERT_TRUE(intTree->contains(12));
    ASSERT_EQ((intTree->head->right->data), 12);
}

//Test if adding to the right of a node on the left works
TEST_F(TempTest, INTADDTEST5) {

    intTree->add(1);
    ASSERT_TRUE(intTree->add(2));
    ASSERT_TRUE(intTree->contains(2));
    ASSERT_EQ((intTree->head->left->right->data), 2);
}

//Test if adding to the left of a node on the left works
TEST_F(TempTest, INTADDTEST6) {

    intTree->add(2);
    ASSERT_TRUE(intTree->add(1));
    ASSERT_TRUE(intTree->contains(1));
    ASSERT_EQ((intTree->head->left->left->data), 1);
}

//Test if adding to the right of a node on the right works
TEST_F(TempTest, INTADDTEST7) {

    intTree->add(11);
    ASSERT_TRUE(intTree->add(12));
    ASSERT_TRUE(intTree->contains(12));
    ASSERT_EQ((intTree->head->right->right->data), 12);
}

//Test if adding to the left of a node on the right works
TEST_F(TempTest, INTADDTEST8) {

    intTree->add(12);
    ASSERT_TRUE(intTree->add(11));
    ASSERT_TRUE(intTree->contains(11));
    ASSERT_EQ((intTree->head->right->left->data), 11);
}

//Test if adding the same value fails
TEST_F(TempTest, INTADDTEST9) {

    intTree->add(12);
    ASSERT_FALSE(intTree->add(12));
}

//Test if contains can find all relevant values
TEST_F(TempTest, INTCONTAINSTEST1) {

    intTree->add(12);
    intTree->add(11);
    intTree->add(13);
    intTree->add(2);
    intTree->add(1);
    intTree->add(4);
    intTree->add(7);

    ASSERT_TRUE(intTree->contains(10));
    ASSERT_TRUE(intTree->contains(12));
    ASSERT_TRUE(intTree->contains(11));
    ASSERT_TRUE(intTree->contains(13));
    ASSERT_TRUE(intTree->contains(2));
    ASSERT_TRUE(intTree->contains(1));
    ASSERT_TRUE(intTree->contains(4));
    ASSERT_TRUE(intTree->contains(7));

}

//Test if contains fails if value is not in tree
TEST_F(TempTest, INTCONTAINSTEST2) {

    intTree->add(12);
    intTree->add(11);
    intTree->add(13);
    intTree->add(2);
    intTree->add(1);
    intTree->add(4);
    intTree->add(7);

    ASSERT_FALSE(intTree->contains(14));
}

//Test if remove can get rid of leaves
TEST_F(TempTest, INTREMOVETEST1) {

    intTree->add(12);
    intTree->add(11);
    intTree->add(13);
    intTree->add(2);
    intTree->add(1);
    intTree->add(4);
    intTree->add(7);

    ASSERT_TRUE(intTree->remove(7));
    ASSERT_TRUE(intTree->remove(11));
    ASSERT_EQ(intTree->head->left->right->right, nullptr);
    ASSERT_EQ(intTree->head->right->left, nullptr);
}

//Test if remove can git rid of single child nodes
TEST_F(TempTest, INTREMOVETEST2) {

    intTree->add(12);
    intTree->add(11);
    intTree->add(13);
    intTree->add(2);
    intTree->add(1);
    intTree->add(4);
    intTree->add(7);

    ASSERT_TRUE(intTree->remove(4));
    ASSERT_EQ(intTree->head->left->right->data, 7);
}

//Test if remove can get rid of dual parent nodes
TEST_F(TempTest, INTREMOVETEST3) {

    intTree->add(12);
    intTree->add(11);
    intTree->add(13);
    intTree->add(2);
    intTree->add(1);
    intTree->add(4);
    intTree->add(7);

    ASSERT_TRUE(intTree->remove(12));
    ASSERT_EQ(intTree->head->right->data, 13);
    ASSERT_EQ(intTree->head->right->left->data, 11);
    ASSERT_EQ(intTree->head->right->right, nullptr);
}

//Test if remove can get rid of the head
TEST_F(TempTest, INTREMOVETEST4) {

    intTree->add(12);
    intTree->add(11);
    intTree->add(13);
    intTree->add(2);
    intTree->add(1);
    intTree->add(4);
    intTree->add(7);

    ASSERT_TRUE(intTree->remove(10));
    ASSERT_EQ(*(intTree->getHead()), 11);
    ASSERT_EQ(intTree->head->right->data, 12);
    ASSERT_EQ(intTree->head->left->data, 2);
}

//Test if remove can get rid of the head
TEST_F(TempTest, INTMINMAXTEST) {

    intTree->add(12);
    intTree->add(11);
    intTree->add(13);
    intTree->add(2);
    intTree->add(1);
    intTree->add(4);
    intTree->add(7);

    ASSERT_EQ(*(intTree->getMax()), 13);
    ASSERT_EQ(*(intTree->getMin()), 1);
}

//Test if adding the head works
TEST_F(TempTest, DOUBLEADDTEST2) {

    ASSERT_TRUE(doubleTree->add(.2));
    ASSERT_EQ(*(doubleTree->getHead()), .2);
}

//Test if adding to the left of the head works
TEST_F(TempTest, DOUBLEADDTEST3) {

    doubleTree->add(1.0);
    ASSERT_TRUE(doubleTree->add(.2));
    ASSERT_TRUE(doubleTree->contains(.2));
    ASSERT_EQ((doubleTree->head->left->data), .2);
}

//Test if adding the right of the head works
TEST_F(TempTest, DOUBLEADDTEST4) {

    doubleTree->add(1.0);
    ASSERT_TRUE(doubleTree->add(1.2));
    ASSERT_TRUE(doubleTree->contains(1.2));
    ASSERT_EQ((doubleTree->head->right->data), 1.2);
}

//Test if adding to the right of a node on the left works
TEST_F(TempTest, DOUBLEADDTEST5) {

    doubleTree->add(1.0);
    doubleTree->add(.1);
    ASSERT_TRUE(doubleTree->add(.2));
    ASSERT_TRUE(doubleTree->contains(.2));
    ASSERT_EQ((doubleTree->head->left->right->data), .2);
}

//Test if adding to the left of a node on the left works
TEST_F(TempTest, DOUBLEADDTEST6) {

    doubleTree->add(1.0);
    doubleTree->add(.2);
    ASSERT_TRUE(doubleTree->add(.1));
    ASSERT_TRUE(doubleTree->contains(.1));
    ASSERT_EQ((doubleTree->head->left->left->data), .1);
}

//Test if adding to the right of a node on the right works
TEST_F(TempTest, DOUBLEADDTEST7) {

    doubleTree->add(1.0);
    doubleTree->add(1.1);
    ASSERT_TRUE(doubleTree->add(1.2));
    ASSERT_TRUE(doubleTree->contains(1.2));
    ASSERT_EQ((doubleTree->head->right->right->data), 1.2);
}

//Test if adding to the left of a node on the right works
TEST_F(TempTest, DOUBLEADDTEST8) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    ASSERT_TRUE(doubleTree->add(1.1));
    ASSERT_TRUE(doubleTree->contains(1.1));
    ASSERT_EQ((doubleTree->head->right->left->data), 1.1);
}

//Test if adding the same value fails
TEST_F(TempTest, DOUBLEADDTEST9) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    ASSERT_FALSE(doubleTree->add(1.2));
}

//Test if contains can find all relevant values
TEST_F(TempTest, DOUBLECONTAINSTEST1) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    doubleTree->add(1.1);
    doubleTree->add(1.3);
    doubleTree->add(.2);
    doubleTree->add(.1);
    doubleTree->add(.4);
    doubleTree->add(.7);

    ASSERT_TRUE(doubleTree->contains(1.0));
    ASSERT_TRUE(doubleTree->contains(1.2));
    ASSERT_TRUE(doubleTree->contains(1.1));
    ASSERT_TRUE(doubleTree->contains(1.3));
    ASSERT_TRUE(doubleTree->contains(.2));
    ASSERT_TRUE(doubleTree->contains(.1));
    ASSERT_TRUE(doubleTree->contains(.4));
    ASSERT_TRUE(doubleTree->contains(.7));

}

//Test if contains fails if value is not in tree
TEST_F(TempTest, DOUBLECONTAINSTEST2) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    doubleTree->add(1.1);
    doubleTree->add(1.3);
    doubleTree->add(.2);
    doubleTree->add(.1);
    doubleTree->add(.4);
    doubleTree->add(.7);

    ASSERT_FALSE(doubleTree->contains(1.4));
}

//Test if remove can get rid of leaves
TEST_F(TempTest, DOUBLEREMOVETEST1) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    doubleTree->add(1.1);
    doubleTree->add(1.3);
    doubleTree->add(.2);
    doubleTree->add(.1);
    doubleTree->add(.4);
    doubleTree->add(.7);

    ASSERT_TRUE(doubleTree->remove(.7));
    ASSERT_TRUE(doubleTree->remove(1.1));
    ASSERT_EQ(doubleTree->head->left->right->right, nullptr);
    ASSERT_EQ(doubleTree->head->right->left, nullptr);
}

//Test if remove can git rid of single child nodes
TEST_F(TempTest, DOUBLEREMOVETEST2) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    doubleTree->add(1.1);
    doubleTree->add(1.3);
    doubleTree->add(.2);
    doubleTree->add(.1);
    doubleTree->add(.4);
    doubleTree->add(.7);

    ASSERT_TRUE(doubleTree->remove(.4));
    ASSERT_EQ(doubleTree->head->left->right->data, .7);
}

//Test if remove can get rid of dual parent nodes
TEST_F(TempTest, DOUBLEREMOVETEST3) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    doubleTree->add(1.1);
    doubleTree->add(1.3);
    doubleTree->add(.2);
    doubleTree->add(.1);
    doubleTree->add(.4);
    doubleTree->add(.7);

    ASSERT_TRUE(doubleTree->remove(1.2));
    ASSERT_EQ(doubleTree->head->right->data, 1.3);
    ASSERT_EQ(doubleTree->head->right->left->data, 1.1);
    ASSERT_EQ(doubleTree->head->right->right, nullptr);
}

//Test if remove can get rid of the head
TEST_F(TempTest, DOUBLEREMOVETEST4) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    doubleTree->add(1.1);
    doubleTree->add(1.3);
    doubleTree->add(.2);
    doubleTree->add(.1);
    doubleTree->add(.4);
    doubleTree->add(.7);

    ASSERT_TRUE(doubleTree->remove(1.0));
    ASSERT_EQ(*(doubleTree->getHead()), 1.1);
    ASSERT_EQ(doubleTree->head->right->data, 1.2);
    ASSERT_EQ(doubleTree->head->left->data, .2);
}

//Test if remove can get rid of the head
TEST_F(TempTest, DOUBLEMINMAXTEST) {

    doubleTree->add(1.0);
    doubleTree->add(1.2);
    doubleTree->add(1.1);
    doubleTree->add(1.3);
    doubleTree->add(.2);
    doubleTree->add(.1);
    doubleTree->add(.4);
    doubleTree->add(.7);

    ASSERT_EQ(*(doubleTree->getMax()), 1.3);
    ASSERT_EQ(*(doubleTree->getMin()), .1);
}

//Test if adding the head works
TEST_F(TempTest, CHARADDTEST2) {

    ASSERT_TRUE(charTree->add('b'));
    ASSERT_EQ(*(charTree->getHead()), 'b');
}

//Test if adding to the left of the head works
TEST_F(TempTest, CHARADDTEST3) {

    charTree->add('j');
    ASSERT_TRUE(charTree->add('b'));
    ASSERT_TRUE(charTree->contains('b'));
    ASSERT_EQ((charTree->head->left->data), 'b');
}

//Test if adding the right of the head works
TEST_F(TempTest, CHARADDTEST4) {

    charTree->add('j');
    ASSERT_TRUE(charTree->add('l'));
    ASSERT_TRUE(charTree->contains('l'));
    ASSERT_EQ((charTree->head->right->data), 'l');
}

//Test if adding to the right of a node on the left works
TEST_F(TempTest, CHARADDTEST5) {

    charTree->add('j');
    charTree->add('a');
    ASSERT_TRUE(charTree->add('b'));
    ASSERT_TRUE(charTree->contains('b'));
    ASSERT_EQ((charTree->head->left->right->data), 'b');
}

//Test if adding to the left of a node on the left works
TEST_F(TempTest, CHARADDTEST6) {

    charTree->add('j');
    charTree->add('b');
    ASSERT_TRUE(charTree->add('a'));
    ASSERT_TRUE(charTree->contains('a'));
    ASSERT_EQ((charTree->head->left->left->data), 'a');
}

//Test if adding to the right of a node on the right works
TEST_F(TempTest, CHARADDTEST7) {

    charTree->add('j');
    charTree->add('k');
    ASSERT_TRUE(charTree->add('l'));
    ASSERT_TRUE(charTree->contains('l'));
    ASSERT_EQ((charTree->head->right->right->data), 'l');
}

//Test if adding to the left of a node on the right works
TEST_F(TempTest, CHARADDTEST8) {

    charTree->add('j');
    charTree->add('l');
    ASSERT_TRUE(charTree->add('k'));
    ASSERT_TRUE(charTree->contains('k'));
    ASSERT_EQ((charTree->head->right->left->data), 'k');
}

//Test if adding the same value fails
TEST_F(TempTest, CHARADDTEST9) {

    charTree->add('j');
    charTree->add('l');
    ASSERT_FALSE(charTree->add('l'));
}

//Test if contains can find all relevant values
TEST_F(TempTest, CHARCONTAINSTEST1) {

    charTree->add('j');
    charTree->add('l');
    charTree->add('k');
    charTree->add('m');
    charTree->add('b');
    charTree->add('a');
    charTree->add('d');
    charTree->add('g');

    ASSERT_TRUE(charTree->contains('j'));
    ASSERT_TRUE(charTree->contains('l'));
    ASSERT_TRUE(charTree->contains('k'));
    ASSERT_TRUE(charTree->contains('m'));
    ASSERT_TRUE(charTree->contains('b'));
    ASSERT_TRUE(charTree->contains('a'));
    ASSERT_TRUE(charTree->contains('d'));
    ASSERT_TRUE(charTree->contains('g'));

}

//Test if contains fails if value is not in tree
TEST_F(TempTest, CHARCONTAINSTEST2) {

    charTree->add('j');
    charTree->add('l');
    charTree->add('k');
    charTree->add('m');
    charTree->add('b');
    charTree->add('a');
    charTree->add('d');
    charTree->add('g');

    ASSERT_FALSE(charTree->contains('n'));
}

//Test if remove can get rid of leaves
TEST_F(TempTest, CHARREMOVETEST1) {

    charTree->add('j');
    charTree->add('l');
    charTree->add('k');
    charTree->add('m');
    charTree->add('b');
    charTree->add('a');
    charTree->add('d');
    charTree->add('g');

    ASSERT_TRUE(charTree->remove('g'));
    ASSERT_TRUE(charTree->remove('k'));
    ASSERT_EQ(charTree->head->left->right->right, nullptr);
    ASSERT_EQ(charTree->head->right->left, nullptr);
}

//Test if remove can git rid of single child nodes
TEST_F(TempTest, CHARREMOVETEST2) {

    charTree->add('j');
    charTree->add('l');
    charTree->add('k');
    charTree->add('m');
    charTree->add('b');
    charTree->add('a');
    charTree->add('d');
    charTree->add('g');

    ASSERT_TRUE(charTree->remove('d'));
    ASSERT_EQ(charTree->head->left->right->data, 'g');
}

//Test if remove can get rid of dual parent nodes
TEST_F(TempTest, CHARREMOVETEST3) {

    charTree->add('j');
    charTree->add('l');
    charTree->add('k');
    charTree->add('m');
    charTree->add('b');
    charTree->add('a');
    charTree->add('d');
    charTree->add('g');

    ASSERT_TRUE(charTree->remove('l'));
    ASSERT_EQ(charTree->head->right->data, 'm');
    ASSERT_EQ(charTree->head->right->left->data, 'k');
    ASSERT_EQ(charTree->head->right->right, nullptr);
}

//Test if remove can get rid of the head
TEST_F(TempTest, CHARREMOVETEST4) {

    charTree->add('j');
    charTree->add('l');
    charTree->add('k');
    charTree->add('m');
    charTree->add('b');
    charTree->add('a');
    charTree->add('d');
    charTree->add('g');

    ASSERT_TRUE(charTree->remove('j'));
    ASSERT_EQ(*(charTree->getHead()), 'k');
    ASSERT_EQ(charTree->head->right->data, 'l');
    ASSERT_EQ(charTree->head->left->data, 'b');
}

//Test if remove can get rid of the head
TEST_F(TempTest, CHARMINMAXTEST) {

    charTree->add('j');
    charTree->add('l');
    charTree->add('k');
    charTree->add('m');
    charTree->add('b');
    charTree->add('a');
    charTree->add('d');
    charTree->add('g');

    ASSERT_EQ(*(charTree->getMax()), 'm');
    ASSERT_EQ(*(charTree->getMin()), 'a');
}

//STACK TESTS -- int
TEST_F(TempTest, CONSTRUCTSTACK){

    intStack->emplace(10);

    int val = *intStack->top();

    ASSERT_EQ(val, 10);
}

TEST_F(TempTest, EMPTYSTACK){
    ASSERT_TRUE(intStack->size == 0);
    ASSERT_TRUE(intStack->empty());
}

TEST_F(TempTest, EMPTYSTACKSIZE){
    ASSERT_EQ(intStack->get_size(), 0);
}

TEST_F(TempTest, ADDELEMENT){

    intStack->push(11);

    int val = *intStack->top();

    ASSERT_EQ(val, 11);
}

TEST_F(TempTest, NOTEMPTYSTACK){
    intStack->push(11);
    ASSERT_FALSE(intStack->empty());
}

TEST_F(TempTest, STACKSIZE1){

    intStack->push(11);
    intStack->push(22);
    intStack->push(33);

    ASSERT_EQ(intStack->get_size(), 3);
}

TEST_F(TempTest, STACKSIZE2){

    intStack->push(11);
    intStack->push(22);
    intStack->push(33);

    intStack->pop();
    intStack->pop();

    ASSERT_EQ(intStack->get_size(), 1);
}

TEST_F(TempTest, TOPSTACK){

    intStack->push(11);
    intStack->push(22);

    int val = *intStack->top();

    ASSERT_EQ(val, 22);
}

TEST_F(TempTest, POPSTACK){

    intStack->push(11);
    intStack->push(22);

    intStack->pop();


    int val = *intStack->top();

    ASSERT_EQ(val, 11);

}

TEST_F(TempTest, POPSTACKSIZE1){

    intStack->push(11);
    intStack->push(22);
    intStack->push(33);

    intStack->pop();

    ASSERT_EQ(intStack->get_size(), 2);

}

TEST_F(TempTest, POPSTACKSIZE2){

    intStack->push(11);
    intStack->push(22);
    intStack->push(33);

    intStack->pop();
    intStack->pop();
    intStack->pop();

    ASSERT_EQ(intStack->get_size(), 0);
    ASSERT_TRUE(intStack->empty());
}

//char
TEST_F(TempTest, CCONSTRUCTSTACK){

//    charStack->emplace('a');

//    char val = *charStack->top();

//    ASSERT_EQ(val, 'a');
}

TEST_F(TempTest, CEMPTYSTACK){
   // ASSERT_TRUE(charStack->empty());
}

TEST_F(TempTest, CEMPTYSTACKSIZE){

}

TEST_F(TempTest, CADDELEMENT){

}

TEST_F(TempTest, CNOTEMPTYSTACK){

}

TEST_F(TempTest, CSTACKSIZE1){

}

TEST_F(TempTest, CSTACKSIZE2){

}

TEST_F(TempTest, CTOPSTACK){

}

TEST_F(TempTest, CPOPSTACK){

}

TEST_F(TempTest, CPOPSTACKSIZE1){

}

TEST_F(TempTest, CPOPSTACKSIZE2){

}

//string
TEST_F(TempTest, SCONSTRUCTSTACK){

//    strStack->emplace("a");

//    string val = *strStack->top();

//    ASSERT_EQ(val, "a");

}

TEST_F(TempTest, SEMPTYSTACK){
//    ASSERT_TRUE(strStack->empty());
}

TEST_F(TempTest, SEMPTYSTACKSIZE){

}

TEST_F(TempTest, SADDELEMENT){

}

TEST_F(TempTest, SNOTEMPTYSTACK){

}

TEST_F(TempTest, SSTACKSIZE1){

}

TEST_F(TempTest, SSTACKSIZE2){

}

TEST_F(TempTest, STOPSTACK){

}

TEST_F(TempTest, SPOPSTACK){

}

TEST_F(TempTest, SPOPSTACKSIZE1){

}

TEST_F(TempTest, SPOPSTACKSIZE2){

}

int main(int argc, char **argv) {


    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
