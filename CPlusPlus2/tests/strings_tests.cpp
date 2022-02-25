#include "gtest/gtest.h"
#include "../headers/strings.h"

using namespace std;
using namespace getrealgoodutils;

class strings_tests : public ::testing::Test {

protected:
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }

};

TEST_F(strings_tests, to_upper_common_stringptr_stringptr){

    auto a = new string("Hello, World!");
    auto result = strings::to_upper(a);
    ASSERT_EQ("HELLO, WORLD!", *result);

    delete a;
    delete result;
}

TEST_F(strings_tests, to_upper_nullable_nullptr_string_exception){

    ASSERT_THROW(strings::to_upper(nullptr), strings_exception);
}

TEST_F(strings_tests, to_upper_empty_stringptr_stringptr){

    auto result = strings::to_upper(new string(""));
    ASSERT_EQ("", *result);
    delete result;
}

TEST_F(strings_tests, to_upper_exceptional_nullptr_string_exception){

    ASSERT_THROW(strings::to_upper(nullptr), strings_exception);
}

TEST_F(strings_tests, to_lower_common_stringptr_stringptr){

    auto result = strings::to_lower(new string("Hello, World!"));
    ASSERT_EQ("hello, world!", *result);
    delete result;
}

TEST_F(strings_tests, to_lower_nullable_nullptr_string_exception){

    ASSERT_THROW(strings::to_lower(nullptr), strings_exception);
}

TEST_F(strings_tests, to_lower_empty_stringptr_stringptr){

    auto result = strings::to_lower(new string(""));
    ASSERT_EQ("", *result);
    delete result;

}

TEST_F(strings_tests, to_lower_exceptional_nullptr_string_exception){

    ASSERT_THROW(strings::to_lower(nullptr), strings_exception);
}

TEST_F(strings_tests, split_common_stringptr_stringref_bool_stringptr){

    string to_split  = "Hi, how are you ?";
    string delimiter = " ";

    vector<string*> *splitted = strings::split(to_split, delimiter, true);

        EXPECT_EQ(splitted->size(), 5);

        ASSERT_EQ("Hi,", *splitted->at(0));
        ASSERT_EQ("how", *splitted->at(1));
        ASSERT_EQ("are", *splitted->at(2));
        ASSERT_EQ("you", *splitted->at(3));
        ASSERT_EQ("?", *splitted->at(4));

        delete splitted->at(0);
        delete splitted->at(1);
        delete splitted->at(2);
        delete splitted->at(3);
        delete splitted->at(4);
        delete splitted;


}

TEST_F(strings_tests, split_common_stringptr_stringref_bool_stringptr__1){

    string to_split  = "Hi, how are you ? ";
    string delimiter = " ";

    vector<string*> *splitted = strings::split(to_split, delimiter, true);

    EXPECT_EQ(splitted->size(), 5);

    ASSERT_EQ("Hi,", *splitted->at(0));
    ASSERT_EQ("how", *splitted->at(1));
    ASSERT_EQ("are", *splitted->at(2));
    ASSERT_EQ("you", *splitted->at(3));
    ASSERT_EQ("?", *splitted->at(4));

    delete splitted->at(0);
    delete splitted->at(1);
    delete splitted->at(2);
    delete splitted->at(3);
    delete splitted->at(4);
    delete splitted;

}

TEST_F(strings_tests, split_common_stringptr_stringref_bool_stringptr__2){

    string to_split  = " Hi, how are you ? ";
    string delimiter = " ";

    vector<string*> *splitted = strings::split(to_split, delimiter, true);

    EXPECT_EQ(splitted->size(), 5);

    ASSERT_EQ("Hi,", *splitted->at(0));
    ASSERT_EQ("how", *splitted->at(1));
    ASSERT_EQ("are", *splitted->at(2));
    ASSERT_EQ("you", *splitted->at(3));
    ASSERT_EQ("?", *splitted->at(4));

    delete splitted->at(0);
    delete splitted->at(1);
    delete splitted->at(2);
    delete splitted->at(3);
    delete splitted->at(4);
    delete splitted;

}

TEST_F(strings_tests, split_empty_stringptr_stringref_bool_stringptr){

    string to_split  = "";
    string delimiter = " ";

    vector<string*> *splitted = strings::split(to_split, delimiter, true);

    ASSERT_EQ(0, splitted->size());

    delete splitted;

}

TEST_F(strings_tests, concat_common_vectorofstringptrref_stringref_bool_stringptr){

    vector<string*> strings_to_concat = vector<string*>(0);

    string * str1 = new string("How,");
    string * str2 = new string("are");
    string * str3 = new string("you?");

    strings_to_concat.push_back(str1);
    strings_to_concat.push_back(str2);
    strings_to_concat.push_back(str3);

    string delimiter = " ";

    string *concatted = strings::concat(strings_to_concat, delimiter, false);

    ASSERT_EQ("How, are you?", *concatted);


    delete str1;
    delete str2;
    delete str3;
    delete concatted;

}

TEST_F(strings_tests, concat_common_vectorofstringptrref_stringref_bool_stringptr__1){

    vector<string*> strings_to_concat = vector<string*>(0);

    string * str1 = new string("How,");
    string * str2 = new string("are ");
    string * str3 = new string(" you? ");

    strings_to_concat.push_back(str1);
    strings_to_concat.push_back(str2);
    strings_to_concat.push_back(str3);

    string delimiter = " ";

    string *concatted = strings::concat(strings_to_concat, delimiter, false);

    ASSERT_EQ("How, are   you? ", *concatted);

    delete str1;
    delete str2;
    delete str3;
    delete concatted;

}

TEST_F(strings_tests, concat_common_vectorofstringptrref_stringref_bool_stringptr__2){

    vector<string*> strings_to_concat = vector<string*>(0);

    string * str1 = new string("How,");
    string * str2 = new string("are ");
    string * str3 = new string(" you? ");

    strings_to_concat.push_back(str1);
    strings_to_concat.push_back(str2);
    strings_to_concat.push_back(str3);

    string delimiter = " ";

    string *concatted = strings::concat(strings_to_concat, delimiter, true);

    ASSERT_EQ("How, are you?", *concatted);

    delete str1;
    delete str2;
    delete str3;
    delete concatted;

}

TEST_F(strings_tests, concat_empty_vectorofstringptrref_stringref_bool_stringptr){

    vector<string*> strings_to_concat = vector<string*>(0);

    string * str1 = new string("");
    string * str2 = new string("");

    strings_to_concat.push_back(str1);
    strings_to_concat.push_back(str2);

    string delimiter = " ";

    string *concatted = strings::concat(strings_to_concat, delimiter, false);

    ASSERT_EQ("", *concatted);

    delete str1;
    delete str2;
    delete concatted;

}

TEST_F(strings_tests, concat_empty_vectorofstringptrref_stringref_bool_stringptr__1){

    vector<string*> strings_to_concat = vector<string*>(0);

    string * str1 = new string("");
    string * str2 = new string("");

    strings_to_concat.push_back(str1);
    strings_to_concat.push_back(str2);

    string delimiter = " ";

    string *concatted = strings::concat(strings_to_concat, delimiter, true);

    ASSERT_EQ("", *concatted);

    delete str1;
    delete str2;
    delete concatted;

}

TEST_F(strings_tests, replace_common_stringref_char_bool_stringptr){

    string str = "How are you?";
    char char1 = 'H';
    char char2 = 'N';

    string* result = strings::replace(str, char1, char2, true);

    ASSERT_EQ("Now are you?", *result);

    delete result;

}

TEST_F(strings_tests, replace_common_stringref_char_bool_stringptr__1){

    string str = "How are you?";
    char char1 = 'H';
    char char2 = 'N';

    string* result = strings::replace(str, char1, char2, false);

    ASSERT_EQ("Now are you?", *result);

    delete result;

}

TEST_F(strings_tests, replace_empty_stringref_char_bool_stringptr){

    string str = "";
    char char1 = 'H';
    char char2 = 'N';

    string* result = strings::replace(str, char1, char2, true);

    ASSERT_EQ("", *result);

    delete result;

}

TEST_F(strings_tests, replace_empty_stringref_char_bool_stringptr__1){

    string str = "";
    char char1 = 'H';
    char char2 = 'N';

    string* result = strings::replace(str, char1, char2, false);

    ASSERT_EQ("", *result);

    delete result;

}

TEST_F(strings_tests, replace_special_stringref_char_bool_stringptr){

    string str = "How are you?";
    char char1 = 'x';
    char char2 = 'e';

    string* result = strings::replace(str, char1, char2, true);

    ASSERT_EQ("How are you?", *result);

    delete result;

}

TEST_F(strings_tests, replace_special_stringref_char_bool_stringptr__1){

    string str = "How are you?";
    char char1 = 'x';
    char char2 = 'e';

    string* result = strings::replace(str, char1, char2, false);

    ASSERT_EQ("How are you?", *result);

    delete result;

}

TEST_F(strings_tests, replace_common_stringref_char_stringptr){

    string str = "How are you?";
    char char1 = 'H';
    char char2 = 'N';

    string* result = strings::replace(str, char1, char2);

    ASSERT_EQ("Now are you?", *result);

    delete result;

}

TEST_F(strings_tests, replace_empty_stringref_char_stringptr){

    string str = "";
    char char1 = 'H';
    char char2 = 'N';

    string* result = strings::replace(str, char1, char2);

    ASSERT_EQ("", *result);

    delete result;

}