#include <Account.h>
#include <Transaction.h>
#include <gtest/gtest.h>

//THIS FILE TESTS BOTH ACCOUNT.CPP AND TRANSACTION.CPP FILES
TEST(Banking, Account) {
Account acc(0, 0); //Account creation

ASSERT_EQ(acc.GetBalance(), 0); //Checking the constructor
ASSERT_THROW(acc.ChangeBalance(1234), std::runtime_error); //Checking if unlocked
acc.Lock(); //Let's lock it...
ASSERT_NO_THROW(acc.ChangeBalance(1234)); //Checking if locked
ASSERT_THROW(acc.Lock(), std::runtime_error); //Sure that we cannot lock this dude twice
ASSERT_EQ(acc.GetBalance(), 1234); //Checking the balance after we have change it
acc.ChangeBalance(-1235); //Let's do some %bad_words%
ASSERT_EQ(acc.GetBalance(), -1); //How could it be...?
acc.Unlock(); //Dobby is free
ASSERT_THROW(acc.ChangeBalance(1234), std::runtime_error); //Checking if it's right
}

