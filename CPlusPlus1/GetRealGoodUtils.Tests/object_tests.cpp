#include "pch.h"
#include "CppUnitTest.h"

#include "objects.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace getrealgoodutils;

namespace getrealgoodutilstests {

    TEST_CLASS(objects_tests)
    {

    public:


        TEST_METHOD(is_null_common_voidptr_bool) {

            auto a = new int(0);
            Assert::AreEqual(false, objects::is_null(a));
            delete a;
        }

        TEST_METHOD(is_null_nullable_nullptr_bool) {

            Assert::AreEqual(true, objects::is_null(nullptr));
        }

        TEST_METHOD(is_not_null_common_voidptr_bool) {

            auto a = new int(0);
            Assert::AreEqual(true, objects::is_not_null(new int(0)));
            delete a;
        }

        TEST_METHOD(is_not_null_nullable_nullptr_bool) {

            Assert::AreEqual(false, objects::is_not_null(nullptr));
        }

    };

}
