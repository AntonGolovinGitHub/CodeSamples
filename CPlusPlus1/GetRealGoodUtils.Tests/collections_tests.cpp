#include "pch.h"
#include "CppUnitTest.h"

#include "collections.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace getrealgoodutils;

namespace getrealgoodutilstests {

    TEST_CLASS(collections_tests)
    {

    public:

        TEST_METHOD(is_empty_common_vector_bool) {


            try {
                vector<string*>* o = new vector<string*>();
                o->push_back(new string("sample1"));
                o->push_back(new string("sample2"));

                Assert::IsFalse(collections::is_empty<string>(*o));

                delete o->at(0);
                delete o->at(1);
                delete o;

            }
            catch (exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(is_empty_common_vector_bool__1) {


            try {
                vector<string*>* o = new vector<string*>();
                Assert::IsTrue(collections::is_empty<string>(*o));

                delete o;

            }
            catch (exception ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(is_empty_special_vector_bool) {

            try {
                auto o = new vector<string*>();
                o->push_back(new string(""));
                o->push_back(new string(""));

                Assert::IsFalse(collections::is_empty<string>(*o));

                delete o->at(0);
                delete o->at(1);
                delete o;

            }
            catch (exception ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(is_empty_special_vector_bool__1) {

            try {
                auto o = new vector<string*>();
                o->push_back(NULL);
                o->push_back(NULL);

                Assert::IsFalse(collections::is_empty<string>(*o));

                delete o->at(0);
                delete o->at(1);
                delete o;

            }
            catch (exception ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(is_empty_nullable_vectornullptr_collections_exception) {

            try {
                vector<string*>* o = NULL;
                Assert::ExpectException<collections_exception>([o] { collections::is_empty<string>(*o); });

                delete o;

            }
            catch (exception ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(is_not_empty_common_vector_bool) {


            try {
                vector<string*>* o = new vector<string*>();
                o->push_back(new string("sample1"));
                o->push_back(new string("sample2"));

                Assert::IsTrue(collections::is_not_empty<string>(*o));

                delete o->at(0);
                delete o->at(1);
                delete o;

            }
            catch (exception& ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(is_not_empty_common_vector_bool__1) {


            try {
                vector<string*>* o = new vector<string*>();
                Assert::IsFalse(collections::is_not_empty<string>(*o));

                delete o;

            }
            catch (exception ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(is_not_empty_special_vector_bool) {

            try {
                auto o = new vector<string*>();
                o->push_back(new string(""));
                o->push_back(new string(""));

                Assert::IsTrue(collections::is_not_empty<string>(*o));

                delete o->at(0);
                delete o->at(1);
                delete o;

            }
            catch (exception ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(is_not_empty_special_vector_bool__1) {

            try {
                auto o = new vector<string*>();
                o->push_back(NULL);
                o->push_back(NULL);

                Assert::IsTrue(collections::is_not_empty<string>(*o));

                delete o->at(0);
                delete o->at(1);
                delete o;

            }
            catch (exception ex)
            {
                Assert::Fail();
            }

        }

        TEST_METHOD(is_not_empty_nullable_vectornullptr_collections_exception) {

            try {
                vector<string*>* o = NULL;
                Assert::ExpectException<collections_exception>([o] { collections::is_not_empty<string>(*o); });

                delete o;

            }
            catch (exception ex)
            {
                Assert::Fail();
            }
        }

        TEST_METHOD(has_nulls_at_common_vector_set) {

            try {

                auto o = new vector<string*>();
                o->push_back(NULL);
                o->push_back(NULL);
                o->push_back(new string("NULL"));

                set<long>* result = collections::has_nulls_at<string>(*o);
                Assert::IsTrue(2 == result->size());

                delete o->at(0);
                delete o->at(1);
                delete o->at(2);
                delete o;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_at_common_vector_set__1) {

            try {

                auto o = new vector<string*>();
                o->push_back(new string(""));
                o->push_back(new string("NULL"));
                o->push_back(new string("NULL"));

                set<long>* result = collections::has_nulls_at<string>(*o);
                Assert::IsTrue(0 == result->size());

                delete o->at(0);
                delete o->at(1);
                delete o->at(2);
                delete o;
                delete result;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_at_common_vector_collections_exception) {

            try {

                vector<string*>* o = NULL;

                Assert::ExpectException<collections_exception>([o] { collections::has_nulls_at<string>(*o); });

                delete o;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_at_special_vector_set) {

            try {

                auto o = new vector<string*>();
                o->push_back(NULL);
                o->push_back(NULL);
                o->push_back(NULL);

                set<long>* result = collections::has_nulls_at<string>(*o);
                Assert::IsTrue(3 == result->size());

                delete o->at(0);
                delete o->at(1);
                delete o->at(2);
                delete o;
                delete result;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_common_vector_bool) {

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

                Assert::IsTrue(result);

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_common_vector_bool__1) {

            try
            {

                vector<string*>* v = new vector<string*>();
                v->push_back(new string("null"));
                v->push_back(new string("null"));
                v->push_back(new string("null"));

                bool result = collections::has_nulls<string>(*v);
                Assert::IsFalse(result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_special_vector_bool) {

            try
            {

                vector<string*>* v = new vector<string*>();
                v->push_back(NULL);
                v->push_back(NULL);
                v->push_back(NULL);

                bool result = collections::has_nulls<string>(*v);
                Assert::IsTrue(result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_nullable_vectornullptr_collections_exception) {

            try
            {

                vector<string*>* v = NULL;

                Assert::ExpectException<collections_exception>([v] { collections::has_nulls<string>(*v); });

                delete v;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_count_common_vector_long) {

            try
            {

                vector<string*>* v = new vector<string*>();
                v->push_back(new string("null"));
                v->push_back(NULL);
                v->push_back(NULL);

                long result = collections::has_nulls_count<string>(*v);
                Assert::IsTrue(2 == result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_count_common_vector_long__1) {

            try
            {

                vector<string*>* v = new vector<string*>();
                v->push_back(new string("null"));
                v->push_back(new string("null"));
                v->push_back(new string("null"));

                long result = collections::has_nulls_count<string>(*v);
                Assert::IsTrue(0 == result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_count_special_vector_long) {

            try
            {

                vector<string*>* v = new vector<string*>();
                v->push_back(NULL);
                v->push_back(NULL);
                v->push_back(NULL);

                long result = collections::has_nulls_count<string>(*v);
                Assert::IsTrue(3 == result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(has_nulls_count_nullable_vectornullptr_collections_exception) {

            try
            {

                vector<string*>* v = NULL;

                Assert::ExpectException<collections_exception>([v] { collections::has_nulls_count<string>(*v); });

                delete v;

            }
            catch (exception ex) {
                Assert::Fail();
            }

        }

        TEST_METHOD(get_max_common_vector_string) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(new string("a"));
                v->push_back(new string("b"));
                v->push_back(new string("c"));

                string* result = collections::get_max<string>(*v);

                Assert::IsTrue("c" == *result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_max_exceptional_vector_collections_exception) {

            try
            {

                vector<string*>* v = NULL;

                Assert::ExpectException<collections_exception>([v] { collections::get_max<string>(*v); });

                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_max_special_vector_string) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(NULL);
                v->push_back(NULL);
                v->push_back(NULL);

                Assert::IsTrue(collections::get_max<string>(*v) == NULL);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_max_special_vector_string__1) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(new string("a"));
                v->push_back(new string("b"));
                v->push_back(NULL);

                auto result = collections::get_max<string>(*v);
                Assert::IsTrue("b" == *result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_max_special_vector_collections_exception) {

            try
            {

                vector<string*>* v = new vector<string*>(0);

                Assert::ExpectException<collections_exception>([v] { collections::get_max<string>(*v); });

                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_min_common_vector_string) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(new string("a"));
                v->push_back(new string("b"));
                v->push_back(new string("c"));

                string* result = collections::get_min<string>(*v);

                Assert::IsTrue("a" == *result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;


            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_min_exceptional_vector_collections_exception) {

            try
            {

                vector<string*>* v = NULL;

                Assert::ExpectException<collections_exception>([v] { collections::get_min<string>(*v); });

                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_min_special_vector_string) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(NULL);
                v->push_back(NULL);
                v->push_back(NULL);

                string* result = collections::get_min<string>(*v);

                Assert::IsTrue(result == NULL);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;


            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_min_special_vector_string__1) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(new string("a"));
                v->push_back(new string("b"));
                v->push_back(NULL);

                auto result = collections::get_min<string>(*v);
                Assert::IsTrue(NULL == result);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_min_special_vector_collections_exception) {

            try
            {

                vector<string*>* v = new vector<string*>(0);

                Assert::ExpectException<collections_exception>([v] { collections::get_min<string>(*v); });

                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_peaks_common_vector_vector) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(new string("a"));
                v->push_back(new string("b"));
                v->push_back(new string("c"));
                v->push_back(new string("c"));

                auto result = collections::get_peaks<string>(*v);

                Assert::IsTrue("c" == *result->at(0));
                Assert::IsTrue("c" == *result->at(1));
                Assert::IsTrue(result->size() == 2);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v->at(3);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_peaks_exceptional_vector_collections_exception) {

            try
            {

                vector<string*>* v = NULL;

                Assert::ExpectException<collections_exception>([v] { collections::get_peaks<string>(*v); });

                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_peaks_special_vector_string) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(NULL);
                v->push_back(NULL);
                v->push_back(NULL);

                auto result = collections::get_peaks<string>(*v);
                Assert::IsTrue(0 == result->size());

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_peaks_special_vector_string__1) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(new string("a"));
                v->push_back(new string("b"));
                v->push_back(NULL);

                auto result = collections::get_peaks<string>(*v);

                Assert::IsTrue(1 == result->size());
                Assert::IsTrue("b" == *result->at(0));

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_peaks_special_vector_collections_exception) {

            try
            {

                vector<string*>* v = new vector<string*>(0);

                Assert::ExpectException<collections_exception>([v] { collections::get_peaks<string>(*v); });

                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_troughs_common_vector_vector) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(new string("a"));
                v->push_back(new string("b"));
                v->push_back(new string("c"));
                v->push_back(new string("c"));

                auto result = collections::get_troughs<string>(*v);

                Assert::IsTrue("a" == *result->at(0));
                Assert::IsTrue(result->size() == 1);

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v->at(3);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_troughs_exceptional_vector_collections_exception) {

            try
            {

                vector<string*>* v = NULL;

                Assert::ExpectException<collections_exception>([v] { collections::get_troughs<string>(*v); });

                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_troughs_special_vector_string) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(NULL);
                v->push_back(NULL);
                v->push_back(NULL);

                auto result = collections::get_troughs<string>(*v);
                Assert::IsTrue(0 == result->size());

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_troughs_special_vector_string__1) {

            try
            {

                vector<string*>* v = new vector<string*>();

                v->push_back(new string("a"));
                v->push_back(new string("b"));
                v->push_back(NULL);

                auto result = collections::get_troughs<string>(*v);

                Assert::IsTrue(1 == result->size());
                Assert::IsTrue("a" == *result->at(0));

                delete v->at(0);
                delete v->at(1);
                delete v->at(2);
                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

        TEST_METHOD(get_troughs_special_vector_collections_exception) {

            try
            {

                vector<string*>* v = new vector<string*>(0);

                Assert::ExpectException<collections_exception>([v] { collections::get_troughs<string>(*v); });

                delete v;

            }
            catch (exception ex) {

                Assert::Fail();

            }

        }

    };

}
