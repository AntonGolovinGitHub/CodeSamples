#include "gtest/gtest.h"
#include "../headers/collections.h"


using namespace std;
using namespace getrealgoodutils;



class collections_tests : public ::testing::Test {

protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};

TEST_F(collections_tests, is_empty_common_vector_bool){


    try {
        vector<string*>* o = new vector<string*>();
        o->push_back(new string("sample1"));
        o->push_back(new string("sample2"));

        ASSERT_EQ(false, collections::is_empty<string>(*o));

        delete o->at(0);
        delete o->at(1);
        delete o;

    } catch(exception &ex)
    {
        FAIL();
    }

}

TEST_F(collections_tests, is_empty_common_vector_bool__1){


    try {
        vector<string*>* o = new vector<string*>();
        ASSERT_EQ(true, collections::is_empty<string>(*o));

        delete o;

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(collections_tests, is_empty_special_vector_bool){

    try {
        auto o = new vector<string*>();
        o->push_back(new string(""));
        o->push_back(new string(""));

        ASSERT_EQ(false, collections::is_empty<string>(*o));

        delete o->at(0);
        delete o->at(1);
        delete o;

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(collections_tests, is_empty_special_vector_bool__1){

    try {
        auto o = new vector<string*>();
        o->push_back(NULL);
        o->push_back(NULL);

        ASSERT_EQ(false, collections::is_empty<string>(*o));

        delete o->at(0);
        delete o->at(1);
        delete o;

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(collections_tests, is_empty_nullable_vectornullptr_collections_exception){

    try {
        vector<string*>* o = NULL;
        ASSERT_THROW(collections::is_empty<string>(*o), collections_exception);

        delete o;

    } catch(exception ex)
    {
        FAIL();
    }
}

TEST_F(collections_tests, is_not_empty_common_vector_bool){


    try {
        vector<string*>* o = new vector<string*>();
        o->push_back(new string("sample1"));
        o->push_back(new string("sample2"));

        ASSERT_EQ(true, collections::is_not_empty<string>(*o));

        delete o->at(0);
        delete o->at(1);
        delete o;

    } catch(exception &ex)
    {
        FAIL();
    }

}

TEST_F(collections_tests, is_not_empty_common_vector_bool__1){


    try {
        vector<string*>* o = new vector<string*>();
        ASSERT_EQ(false, collections::is_not_empty<string>(*o));

        delete o;

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(collections_tests, is_not_empty_special_vector_bool){

    try {
        auto o = new vector<string*>();
        o->push_back(new string(""));
        o->push_back(new string(""));

        ASSERT_EQ(true, collections::is_not_empty<string>(*o));

        delete o->at(0);
        delete o->at(1);
        delete o;

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(collections_tests, is_not_empty_special_vector_bool__1){

    try {
        auto o = new vector<string*>();
        o->push_back(NULL);
        o->push_back(NULL);

        ASSERT_EQ(true, collections::is_not_empty<string>(*o));

        delete o->at(0);
        delete o->at(1);
        delete o;

    } catch(exception ex)
    {
        FAIL();
    }

}

TEST_F(collections_tests, is_not_empty_nullable_vectornullptr_collections_exception){

    try {
        vector<string*>* o = NULL;
        ASSERT_THROW(collections::is_not_empty<string>(*o), collections_exception);

        delete o;

    } catch(exception ex)
    {
        FAIL();
    }
}

TEST_F(collections_tests, has_nulls_at_common_vector_set){

    try {

        auto o = new vector<string*>();
        o->push_back(NULL);
        o->push_back(NULL);
        o->push_back(new string("NULL"));

        set<long>* result = collections::has_nulls_at<string>(*o);
        ASSERT_EQ(2, result->size());

        delete o->at(0);
        delete o->at(1);
        delete o->at(2);
        delete o;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_at_common_vector_set__1){

    try {

        auto o = new vector<string*>();
        o->push_back(new string(""));
        o->push_back(new string("NULL"));
        o->push_back(new string("NULL"));

        set<long>* result = collections::has_nulls_at<string>(*o);
        ASSERT_EQ(0, result->size());

        delete o->at(0);
        delete o->at(1);
        delete o->at(2);
        delete o;
        delete result;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_at_common_vector_collections_exception){

    try {

        vector<string*>* o = NULL;

        ASSERT_THROW(collections::has_nulls_at<string>(*o), collections_exception);

        delete o;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_at_special_vector_set){

    try {

        auto o = new vector<string*>();
        o->push_back(NULL);
        o->push_back(NULL);
        o->push_back(NULL);

        set<long>* result = collections::has_nulls_at<string>(*o);
        ASSERT_EQ(3, result->size());

        delete o->at(0);
        delete o->at(1);
        delete o->at(2);
        delete o;
        delete result;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_common_vector_bool){

    try
    {

         vector<string*>* v = new vector<string*>();
         v->push_back(new string("null"));
         v->push_back(NULL);
         v->push_back(NULL);

        bool result = collections::has_nulls<string>(*v);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

        ASSERT_TRUE(result);

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_common_vector_bool__1){

    try
    {

        vector<string*>* v = new vector<string*>();
        v->push_back(new string("null"));
        v->push_back(new string("null"));
        v->push_back(new string("null"));

        bool result = collections::has_nulls<string>(*v);
        ASSERT_FALSE(result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_special_vector_bool){

    try
    {

        vector<string*>* v = new vector<string*>();
        v->push_back(NULL);
        v->push_back(NULL);
        v->push_back(NULL);

        bool result = collections::has_nulls<string>(*v);
        ASSERT_TRUE(result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_nullable_vectornullptr_collections_exception){

    try
    {

        vector<string*>* v = NULL;

        ASSERT_THROW(collections::has_nulls<string>(*v), collections_exception);

        delete v;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_count_common_vector_long){

    try
    {

        vector<string*>* v = new vector<string*>();
        v->push_back(new string("null"));
        v->push_back(NULL);
        v->push_back(NULL);

        long result = collections::has_nulls_count<string>(*v);
        ASSERT_EQ(2, result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_count_common_vector_long__1){

    try
    {

        vector<string*>* v = new vector<string*>();
        v->push_back(new string("null"));
        v->push_back(new string("null"));
        v->push_back(new string("null"));

        long result = collections::has_nulls_count<string>(*v);
        ASSERT_EQ(0, result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_count_special_vector_long){

    try
    {

        vector<string*>* v = new vector<string*>();
        v->push_back(NULL);
        v->push_back(NULL);
        v->push_back(NULL);

        long result = collections::has_nulls_count<string>(*v);
        ASSERT_EQ(3, result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, has_nulls_count_nullable_vectornullptr_collections_exception){

    try
    {

        vector<string*>* v = NULL;

        ASSERT_THROW(collections::has_nulls_count<string>(*v), collections_exception);

        delete v;

    } catch (exception ex) {
        FAIL();
    }

}

TEST_F(collections_tests, get_max_common_vector_string){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(new string("a"));
        v->push_back(new string("b"));
        v->push_back(new string("c"));

        string* result = collections::get_max<string>(*v);

        ASSERT_EQ("c", *result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_max_exceptional_vector_collections_exception){

    try
    {

        vector<string*>* v = NULL;

        ASSERT_THROW(collections::get_max<string>(*v), collections_exception);

        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_max_special_vector_string){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(NULL);
        v->push_back(NULL);
        v->push_back(NULL);

        ASSERT_TRUE(collections::get_max<string>(*v) == NULL);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_max_special_vector_string__1){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(new string("a"));
        v->push_back(new string("b"));
        v->push_back(NULL);

        auto result = collections::get_max<string>(*v);
        ASSERT_EQ("b", *result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_max_special_vector_collections_exception){

    try
    {

        vector<string*>* v = new vector<string*>(0);

        ASSERT_THROW(collections::get_max<string>(*v), collections_exception);

        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_min_common_vector_string){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(new string("a"));
        v->push_back(new string("b"));
        v->push_back(new string("c"));

        string* result = collections::get_min<string>(*v);

        ASSERT_EQ("a", *result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;


    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_min_exceptional_vector_collections_exception){

    try
    {

        vector<string*>* v = NULL;

        ASSERT_THROW(collections::get_min<string>(*v), collections_exception);

        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_min_special_vector_string){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(NULL);
        v->push_back(NULL);
        v->push_back(NULL);

        string* result = collections::get_min<string>(*v);

        ASSERT_TRUE(result == NULL);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;


    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_min_special_vector_string__1){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(new string("a"));
        v->push_back(new string("b"));
        v->push_back(NULL);

        auto result = collections::get_min<string>(*v);
        ASSERT_EQ(NULL, result);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_min_special_vector_collections_exception){

    try
    {

        vector<string*>* v = new vector<string*>(0);

        ASSERT_THROW(collections::get_min<string>(*v), collections_exception);

        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_peaks_common_vector_vector){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(new string("a"));
        v->push_back(new string("b"));
        v->push_back(new string("c"));
        v->push_back(new string("c"));

        auto result = collections::get_peaks<string>(*v);

        ASSERT_EQ("c", *result->at(0));
        ASSERT_EQ("c", *result->at(1));
        ASSERT_TRUE(result->size() == 2);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v->at(3);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_peaks_exceptional_vector_collections_exception){

    try
    {

        vector<string*>* v = NULL;

        ASSERT_THROW(collections::get_peaks<string>(*v), collections_exception);

        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_peaks_special_vector_string){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(NULL);
        v->push_back(NULL);
        v->push_back(NULL);

        auto result = collections::get_peaks<string>(*v);
        ASSERT_EQ(0, result->size());

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_peaks_special_vector_string__1){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(new string("a"));
        v->push_back(new string("b"));
        v->push_back(NULL);

        auto result = collections::get_peaks<string>(*v);

        ASSERT_EQ(1, result->size());
        ASSERT_EQ("b", *result->at(0));

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_peaks_special_vector_collections_exception){

    try
    {

        vector<string*>* v = new vector<string*>(0);

        ASSERT_THROW(collections::get_peaks<string>(*v), collections_exception);

        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_troughs_common_vector_vector){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(new string("a"));
        v->push_back(new string("b"));
        v->push_back(new string("c"));
        v->push_back(new string("c"));

        auto result = collections::get_troughs<string>(*v);

        ASSERT_EQ("a", *result->at(0));
        ASSERT_TRUE(result->size() == 1);

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v->at(3);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_troughs_exceptional_vector_collections_exception){

    try
    {

        vector<string*>* v = NULL;

        ASSERT_THROW(collections::get_troughs<string>(*v), collections_exception);

        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_troughs_special_vector_string){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(NULL);
        v->push_back(NULL);
        v->push_back(NULL);

        auto result = collections::get_troughs<string>(*v);
        ASSERT_EQ(0, result->size());

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_troughs_special_vector_string__1){

    try
    {

        vector<string*>* v = new vector<string*>();

        v->push_back(new string("a"));
        v->push_back(new string("b"));
        v->push_back(NULL);

        auto result = collections::get_troughs<string>(*v);

        ASSERT_EQ(1, result->size());
        ASSERT_EQ("a", *result->at(0));

        delete v->at(0);
        delete v->at(1);
        delete v->at(2);
        delete v;

    } catch(exception ex) {

        FAIL();

    }

}

TEST_F(collections_tests, get_troughs_special_vector_collections_exception){

    try
    {

        vector<string*>* v = new vector<string*>(0);

        ASSERT_THROW(collections::get_troughs<string>(*v), collections_exception);

        delete v;

    } catch(exception ex) {

        FAIL();

    }

}