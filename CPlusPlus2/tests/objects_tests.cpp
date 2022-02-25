#include "gtest/gtest.h"
#include "../headers/objects.h"

using namespace std;
using namespace getrealgoodutils;

class objects_tests : public ::testing::Test {

protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};

TEST_F(objects_tests, is_null_common_voidptr_bool){

    auto a = new int(0);
    ASSERT_EQ(false,objects::is_null(a));
    delete a;
}

TEST_F(objects_tests, is_null_nullable_nullptr_bool){

    ASSERT_EQ(true,objects::is_null(nullptr));
}

TEST_F(objects_tests, is_not_null_common_voidptr_bool){

    auto a = new int(0);
    ASSERT_EQ(true,objects::is_not_null(new int(0)));
    delete a;
}

TEST_F(objects_tests, is_not_null_nullable_nullptr_bool){

    ASSERT_EQ(false,objects::is_not_null(nullptr));
}