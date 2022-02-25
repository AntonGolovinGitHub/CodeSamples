#include "gtest/gtest.h"
#include "../headers/arrays.h"
#include "../headers/collections.h"


using namespace std;
using namespace getrealgoodutils;



class arrays_tests : public ::testing::Test {

protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};

TEST_F(arrays_tests, is_empty_common_stringarr_bool){


    try {
        string* o[2];
        o[0] = new string("sample1");
        o[1] = new string("sample2");

        ASSERT_EQ(false, arrays::is_empty<string>(o, 2));

    } catch(exception &ex)
    {
        FAIL();
    }

}

TEST_F(arrays_tests, is_empty_common_stringarr_bool__1){


    try {

        string* o[0];
        ASSERT_EQ(true, arrays::is_empty<string>(o, 0));

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(arrays_tests, is_empty_special_stringarr_bool){

    try {
        string* o[2];
        o[0] = new string("");
        o[1] = new string("");

        ASSERT_EQ(false, arrays::is_empty<string>(o, 2));

        delete o[0];
        delete o[1];

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(arrays_tests, is_empty_special_stringarr_bool__1){

    try {
        string* o[2];
        o[0] = NULL;
        o[1] = NULL;

        ASSERT_EQ(false, arrays::is_empty<string>(o, 2));

        delete o[0];
        delete o[1];

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(arrays_tests, is_empty_nullable_stringarrnullptr_arrays_exception){

    try {
        string* o = NULL;
        ASSERT_EQ(true, arrays::is_empty<string>(&o, 0));

    } catch(exception ex)
    {
        FAIL();
    }
}

TEST_F(arrays_tests, is_not_empty_common_stringarr_bool){


    try {

        string* o[] = { new string("sample1"), new string("sample2") };

        ASSERT_EQ(true, arrays::is_not_empty<string>(o, 2));

        delete o[0];
        delete o[1];

    } catch(exception &ex)
    {
        FAIL();
    }

}

TEST_F(arrays_tests, is_not_empty_common_stringarr_bool__1){


    try {
        string* o[0];
        ASSERT_EQ(false, arrays::is_not_empty<string>(o, 0));

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(arrays_tests, is_not_empty_special_stringarr_bool){

    try {

        string* o[] = { new string("sample1"), new string("sample2") };

        ASSERT_EQ(true, arrays::is_not_empty<string>(o, 2));

        delete o[0];
        delete o[1];

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(arrays_tests, is_not_empty_special_stringarr_bool__1){

    try {
        string* o[] = { NULL, NULL };

        ASSERT_EQ(true, arrays::is_not_empty<string>(o, 2));

        delete o[0];
        delete o[1];

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(arrays_tests, is_not_empty_nullable_stringarrnullptr_arrays_exception){

    try {
        string** o = NULL;
        ASSERT_THROW(arrays::is_not_empty<string>(o, 0), arrays_exception);

        delete o;

    } catch(exception ex)
    {
        FAIL();
    }
}

TEST_F(arrays_tests, has_nulls_at_common_stringarr_set){

    try {

        string* o[] = { NULL, NULL, new string("NULL") };
        vector<long>* result = arrays::has_nulls_at<string>(o, 3);
        ASSERT_EQ(2, result->size());

        delete o[0];
        delete o[1];
        delete o[2];
        delete result;

    } catch (exception ex) {
        FAIL();
    }
}

TEST_F(arrays_tests, has_nulls_at_common_stringarr_set__1){

    try {

        string* o[] = { new string(""), new string("NULL"), new string("NULL") };

        vector<long>* result = arrays::has_nulls_at<string>(o, 3);
        ASSERT_EQ(0, result->size());

        delete o[0];
        delete o[1];
        delete o[2];
        delete result;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_at_common_stringarr_arrays_exception){

    try {

        string** o = NULL;

        ASSERT_THROW(arrays::has_nulls_at<string>(o, 0), arrays_exception);

        delete o;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_at_special_stringarr_set){

    try {

        string* o[] = { NULL, NULL, NULL };

        vector<long>* result = arrays::has_nulls_at<string>(o, 3);
        ASSERT_EQ(3, result->size());

        delete o[0];
        delete o[1];
        delete o[2];
        delete result;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_common_stringarr_bool){

    try
    {

        string* o[] = { new string("null"), NULL, NULL };

        bool result = arrays::has_nulls<string>(o, 3);
        ASSERT_TRUE(result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_common_stringarr_bool__1){

    try
    {

        string* o[] = { new string("null"), new string("null"), new string("null") };

        bool result = arrays::has_nulls<string>(o, 3);
        ASSERT_FALSE(result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_special_stringarr_bool){

    try
    {

        string* o[] = { NULL, NULL, NULL };

        bool result = arrays::has_nulls<string>(o, 3);
        ASSERT_TRUE(result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_nullable_stringarrnullptr_arrays_exception){

    try
    {

        string** o = NULL;

        ASSERT_THROW(arrays::has_nulls<string>(o, 0), arrays_exception);

        delete o;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_count_common_stringarr_long){

    try
    {

        string* o[] = { new string("null"), NULL, NULL };

        long result = arrays::has_nulls_count<string>(o, 3);
        ASSERT_EQ(2, result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_count_common_stringarr_long__1){

    try
    {

        string* o[] = { new string("null"), new string("null"), new string("null") };

        long result = arrays::has_nulls_count<string>(o, 3);
        ASSERT_EQ(0, result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_count_special_stringarr_long){

    try
    {

        string* o[] = { NULL, NULL, NULL };

        long result = arrays::has_nulls_count<string>(o, 3);
        ASSERT_EQ(3, result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, has_nulls_count_nullable_stringarrnullptr_arrays_exception){

    try
    {

        string** o = NULL;

        ASSERT_THROW(arrays::has_nulls_count<string>(o, 0), arrays_exception);

        delete o;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(arrays_tests, get_max_common_stringarr_string){

    try
    {
        string* s1 {new string("a")};
        string* s2 {new string("b")};
        string* s3 {new string("c")};
        string* o[] = { s1, s2, s3 };

        string* result = arrays::get_max<string>(o, 3);

        ASSERT_EQ("c", *result);

        delete s1;
        delete s2;
        delete s3;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_max_exceptional_stringarr_arrays_exception){

    try
    {

        string** o = NULL;

        ASSERT_THROW(arrays::get_max<string>(o, 3), arrays_exception);

        delete o;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_max_special_stringarr_string){

    try
    {

        string* o[] = { NULL, NULL, NULL };

        ASSERT_THROW(arrays::get_max<string>(o, 3), arrays_exception);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_max_special_stringarr_string__1){

    try
    {

        string* o[] = { new string("a"), new string("b"), NULL };

        auto result = arrays::get_max<string>(o, 3);

        ASSERT_EQ("b", *result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_max_special_stringarr_arrays_exception){

    try
    {

        string* o[0];

        ASSERT_THROW(arrays::get_max<string>(o, 0), arrays_exception);

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_min_common_stringarr_string){

    try
    {

        string* o[] = { new string("a"), new string("b"), new string("c") };

        string* result = arrays::get_min<string>(o, 3);

        ASSERT_EQ("a", *result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_min_exceptional_stringarr_arrays_exception){

    try
    {

        string** o = NULL;

        ASSERT_THROW(arrays::get_min<string>(o, 0), arrays_exception);

        delete o;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_min_special_stringarr_string){

    try
    {

        string* o[] = { NULL, NULL, NULL };

        ASSERT_THROW(arrays::get_min<string>(o, 3), arrays_exception);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_min_special_stringarr_string__1){

    try
    {

        string* o[] = { new string("a"), new string("b"), NULL };

        auto result = arrays::get_min<string>(o, 3);

        ASSERT_EQ("a", *result);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_min_special_stringarr_arrays_exception){

    try
    {

        string* o[0];

        ASSERT_THROW(arrays::get_min<string>(o, 0), arrays_exception);

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_peaks_common_stringarr_vector){

    try
    {

        string* o[] = { new string("a"), new string("b"), new string("c"), new string("c") };

        auto result = arrays::get_peaks<string>(o, 4);

        ASSERT_EQ("c", *result->at(0));
        ASSERT_EQ("c", *result->at(1));
        ASSERT_TRUE(result->size() == 2);

        delete o[0];
        delete o[1];
        delete o[2];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_peaks_exceptional_stringarr_arrays_exception){

    try
    {

        string* o[0];

        ASSERT_THROW(arrays::get_peaks<string>(o, 0), arrays_exception);

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_peaks_special_stringarr_string){

    try
    {

        string* o[] = { NULL, NULL, NULL };

        auto result = arrays::get_peaks<string>(o, 3);
        ASSERT_EQ(0, result->size());

        delete o[0];
        delete o[1];
        delete o[2];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_peaks_special_stringarr_string__1){

    try
    {

        string* o[] = { new string("a"), new string("b"), NULL };

        auto result = arrays::get_peaks<string>(o, 3);

        ASSERT_EQ(1, result->size());
        ASSERT_EQ("b", *result->at(0));

        delete o[0];
        delete o[1];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_peaks_special_stringarr_arrays_exception){

    try
    {

        string* o[0];

        ASSERT_THROW(arrays::get_peaks<string>(o, 0), arrays_exception);

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_troughs_common_stringarr_vector){

    try
    {

        string* o[] = { new string("a"), new string("b"), new string("c"), new string("c") };

        auto result = arrays::get_troughs<string>(o, 4);

        ASSERT_EQ("a", *result->at(0));
        ASSERT_TRUE(result->size() == 1);

        delete o[0];
        delete o[1];
        delete o[2];
        delete o[3];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_troughs_exceptional_stringarr_arrays_exception){

    try
    {

        string** o = NULL;

        ASSERT_THROW(arrays::get_troughs<string>(o, 0), arrays_exception);

        delete o;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_troughs_special_stringarr_string){

    try
    {

        string* o[] = { NULL, NULL, NULL };

        auto result = arrays::get_troughs<string>(o, 3);
        ASSERT_EQ(0, result->size());

        delete o[0];
        delete o[1];
        delete o[2];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_troughs_special_stringarr_string__1){

    try
    {

        string* o[] = { new string("a"), new string("b"), NULL };

        auto result = arrays::get_troughs<string>(o, 3);

        ASSERT_EQ(1, result->size());
        ASSERT_EQ("a", *result->at(0));

        delete o[0];
        delete o[1];

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(arrays_tests, get_troughs_special_stringarr_arrays_exception){

    try
    {

        string* o[0];

        ASSERT_THROW(arrays::get_troughs<string>(o, 0), arrays_exception);

    } catch(exception ex) {

        FAIL();

    }

}
