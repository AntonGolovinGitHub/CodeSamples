#include "pch.h"
#include "CppUnitTest.h"

#include "strings.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace getrealgoodutils;

namespace getrealgoodutilstests {

    TEST_CLASS(strings_tests)
    {

    public:


        TEST_METHOD(to_upper_common_stringptr_stringptr) {

            auto a = new string("Hello, World!");
            auto result = strings::to_upper(a);
            Assert::IsTrue("HELLO, WORLD!" == *result);

            delete a;
            delete result;
        }

        TEST_METHOD(to_upper_nullable_nullptr_string_exception) {

            Assert::ExpectException<strings_exception>([] { strings::to_upper(nullptr); });
        }

        TEST_METHOD(to_upper_empty_stringptr_stringptr) {

            auto result = strings::to_upper(new string(""));
            Assert::IsTrue("" == *result);
            delete result;
        }

        TEST_METHOD(to_upper_exceptional_nullptr_string_exception) {

            Assert::ExpectException<strings_exception>([] { strings::to_upper(nullptr); });
        }

        TEST_METHOD(to_lower_common_stringptr_stringptr) {

            auto result = strings::to_lower(new string("Hello, World!"));
            Assert::IsTrue("hello, world!" == *result);
            delete result;
        }

        TEST_METHOD(to_lower_nullable_nullptr_string_exception) {

            Assert::ExpectException<strings_exception>([] { strings::to_lower(nullptr); });
        }

        TEST_METHOD(to_lower_empty_stringptr_stringptr) {

            auto result = strings::to_lower(new string(""));
            Assert::IsTrue("" == *result);
            delete result;

        }

        TEST_METHOD(to_lower_exceptional_nullptr_string_exception) {

            Assert::ExpectException<strings_exception>([] { strings::to_lower(nullptr); });
        }

        TEST_METHOD(split_common_stringptr_stringref_bool_stringptr) {

            string to_split = "Hi, how are you ?";
            string delimiter = " ";

            vector<string*>* splitted = strings::split(to_split, delimiter, true);

            Assert::IsTrue(splitted->size() == 5);

            Assert::IsTrue("Hi," == *splitted->at(0));
            Assert::IsTrue("how" == *splitted->at(1));
            Assert::IsTrue("are" == *splitted->at(2));
            Assert::IsTrue("you" == *splitted->at(3));
            Assert::IsTrue("?" == *splitted->at(4));

            delete splitted->at(0);
            delete splitted->at(1);
            delete splitted->at(2);
            delete splitted->at(3);
            delete splitted->at(4);
            delete splitted;


        }

        TEST_METHOD(split_common_stringptr_stringref_bool_stringptr__1) {

            string to_split = "Hi, how are you ? ";
            string delimiter = " ";

            vector<string*>* splitted = strings::split(to_split, delimiter, true);

            Assert::IsTrue(splitted->size() == 5);

            Assert::IsTrue("Hi," == *splitted->at(0));
            Assert::IsTrue("how" == *splitted->at(1));
            Assert::IsTrue("are" == *splitted->at(2));
            Assert::IsTrue("you" == *splitted->at(3));
            Assert::IsTrue("?" == *splitted->at(4));

            delete splitted->at(0);
            delete splitted->at(1);
            delete splitted->at(2);
            delete splitted->at(3);
            delete splitted->at(4);
            delete splitted;

        }

        TEST_METHOD(split_common_stringptr_stringref_bool_stringptr__2) {

            string to_split = " Hi, how are you ? ";
            string delimiter = " ";

            vector<string*>* splitted = strings::split(to_split, delimiter, true);

            Assert::IsTrue(splitted->size() == 5);

            Assert::IsTrue("Hi," == *splitted->at(0));
            Assert::IsTrue("how" == *splitted->at(1));
            Assert::IsTrue("are" == *splitted->at(2));
            Assert::IsTrue("you" == *splitted->at(3));
            Assert::IsTrue("?" == *splitted->at(4));

            delete splitted->at(0);
            delete splitted->at(1);
            delete splitted->at(2);
            delete splitted->at(3);
            delete splitted->at(4);
            delete splitted;

        }

        TEST_METHOD(split_empty_stringptr_stringref_bool_stringptr) {

            string to_split = "";
            string delimiter = " ";

            vector<string*>* splitted = strings::split(to_split, delimiter, true);

            Assert::IsTrue(0 == splitted->size());

            delete splitted;

        }

        TEST_METHOD(concat_common_vectorofstringptrref_stringref_bool_stringptr) {

            vector<string*> strings_to_concat = vector<string*>(0);

            string* str1 = new string("How,");
            string* str2 = new string("are");
            string* str3 = new string("you?");

            strings_to_concat.push_back(str1);
            strings_to_concat.push_back(str2);
            strings_to_concat.push_back(str3);

            string delimiter = " ";

            string* concatted = strings::concat(strings_to_concat, delimiter, false);

            Assert::IsTrue("How, are you?" == *concatted);


            delete str1;
            delete str2;
            delete str3;
            delete concatted;

        }

        TEST_METHOD(concat_common_vectorofstringptrref_stringref_bool_stringptr__1) {

            vector<string*> strings_to_concat = vector<string*>(0);

            string* str1 = new string("How,");
            string* str2 = new string("are ");
            string* str3 = new string(" you? ");

            strings_to_concat.push_back(str1);
            strings_to_concat.push_back(str2);
            strings_to_concat.push_back(str3);

            string delimiter = " ";

            string* concatted = strings::concat(strings_to_concat, delimiter, false);

            Assert::IsTrue("How, are   you? " == *concatted);

            delete str1;
            delete str2;
            delete str3;
            delete concatted;

        }

        TEST_METHOD(concat_common_vectorofstringptrref_stringref_bool_stringptr__2) {

            vector<string*> strings_to_concat = vector<string*>(0);

            string* str1 = new string("How,");
            string* str2 = new string("are ");
            string* str3 = new string(" you? ");

            strings_to_concat.push_back(str1);
            strings_to_concat.push_back(str2);
            strings_to_concat.push_back(str3);

            string delimiter = " ";

            string* concatted = strings::concat(strings_to_concat, delimiter, true);

            Assert::IsTrue("How, are you?" == *concatted);

            delete str1;
            delete str2;
            delete str3;
            delete concatted;

        }

        TEST_METHOD(concat_empty_vectorofstringptrref_stringref_bool_stringptr) {

            vector<string*> strings_to_concat = vector<string*>(0);

            string* str1 = new string("");
            string* str2 = new string("");

            strings_to_concat.push_back(str1);
            strings_to_concat.push_back(str2);

            string delimiter = " ";

            string* concatted = strings::concat(strings_to_concat, delimiter, false);

            Assert::IsTrue("" == *concatted);

            delete str1;
            delete str2;
            delete concatted;

        }

        TEST_METHOD(concat_empty_vectorofstringptrref_stringref_bool_stringptr__1) {

            vector<string*> strings_to_concat = vector<string*>(0);

            string* str1 = new string("");
            string* str2 = new string("");

            strings_to_concat.push_back(str1);
            strings_to_concat.push_back(str2);

            string delimiter = " ";

            string* concatted = strings::concat(strings_to_concat, delimiter, true);

            Assert::IsTrue("" == *concatted);

            delete str1;
            delete str2;
            delete concatted;

        }

        TEST_METHOD(replace_common_stringref_char_bool_stringptr) {

            string str = "How are you?";
            char char1 = 'H';
            char char2 = 'N';

            string* result = strings::replace(str, char1, char2, true);

            Assert::IsTrue("Now are you?" == *result);

            delete result;

        }

        TEST_METHOD(replace_common_stringref_char_bool_stringptr__1) {

            string str = "How are you?";
            char char1 = 'H';
            char char2 = 'N';

            string* result = strings::replace(str, char1, char2, false);

            Assert::IsTrue("Now are you?" == *result);

            delete result;

        }

        TEST_METHOD(replace_empty_stringref_char_bool_stringptr) {

            string str = "";
            char char1 = 'H';
            char char2 = 'N';

            string* result = strings::replace(str, char1, char2, true);

            Assert::IsTrue("" == *result);

            delete result;

        }

        TEST_METHOD(replace_empty_stringref_char_bool_stringptr__1) {

            string str = "";
            char char1 = 'H';
            char char2 = 'N';

            string* result = strings::replace(str, char1, char2, false);

            Assert::IsTrue("" == *result);

            delete result;

        }

        TEST_METHOD(replace_special_stringref_char_bool_stringptr) {

            string str = "How are you?";
            char char1 = 'x';
            char char2 = 'e';

            string* result = strings::replace(str, char1, char2, true);

            Assert::IsTrue("How are you?" == *result);

            delete result;

        }

        TEST_METHOD(replace_special_stringref_char_bool_stringptr__1) {

            string str = "How are you?";
            char char1 = 'x';
            char char2 = 'e';

            string* result = strings::replace(str, char1, char2, false);

            Assert::IsTrue("How are you?" == *result);

            delete result;

        }

        TEST_METHOD(replace_common_stringref_char_stringptr) {

            string str = "How are you?";
            char char1 = 'H';
            char char2 = 'N';

            string* result = strings::replace(str, char1, char2);

            Assert::IsTrue("Now are you?" == *result);

            delete result;

        }

        TEST_METHOD(replace_empty_stringref_char_stringptr) {

            string str = "";
            char char1 = 'H';
            char char2 = 'N';

            string* result = strings::replace(str, char1, char2);

            Assert::IsTrue("" == *result);

            delete result;

        }


    };

}
