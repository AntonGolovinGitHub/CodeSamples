import unittest
from files.strings import Strings
from files.strings import StringsException

class StringsTests(unittest.TestCase):

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def test_toupper_Common_string_bool(self):
        v = "object"
        self.assertEqual(Strings.toupper(v), "OBJECT")

    def test_toupper_Nullable_stringNone_bool(self):
        with self.assertRaises(StringsException):
            Strings.toupper(None)

    def test_toupper_Empty_string_bool(self):
        v = ""
        self.assertEqual(Strings.toupper(v), "")

    def test_toupper_Exceptional_stringNone_bool(self):
        with self.assertRaises(StringsException):
            Strings.toupper(None)


    def test_tolower_Common_string_bool(self):
            v = "OBJECT"
            self.assertEqual(Strings.tolower(v), "object")

    def test_tolower_Nullable_stringNone_bool(self):
        with self.assertRaises(StringsException):
            Strings.tolower(None)

    def test_tolower_Empty_string_bool(self):
        v = ""
        self.assertEqual(Strings.tolower(v), "")

    def test_tolower_Exceptional_stringNone_bool(self):
        with self.assertRaises(StringsException):
            Strings.tolower(None)

    def test_split_Common_string_string_bool_string(self):

        str = "Hello, how are you?"
        strs = Strings.split(str, " ", False)

        self.assertEqual(strs[0], "Hello,")
        self.assertEqual(strs[1], "how")
        self.assertEqual(strs[2], "are")
        self.assertEqual(strs[3], "you?")


    def test_split_Common_string_string_bool_string__1(self):

        str = "Hello, how are you?"
        strs = Strings.split(str, " ", True)

        self.assertEqual(strs[0], "Hello,")
        self.assertEqual(strs[1], "how")
        self.assertEqual(strs[2], "are")
        self.assertEqual(strs[3], "you?")

    def test_split_Common_string_string_bool_string__2(self):

        str = "  Hello, how are you? "
        strs = Strings.split(str, " ", True)

        self.assertEqual(strs[0], "Hello,")
        self.assertEqual(strs[1], "how")
        self.assertEqual(strs[2], "are")
        self.assertEqual(strs[3], "you?")

    def test_split_Nullable_stringNone_string_bool_StringsException(self):

        str = None

        with self.assertRaises(StringsException):
            Strings.split(str, False)

    def test_split_Empty_string_string_bool_string(self):
        str = ""

        self.assertEqual(Strings.split(str, False), "")

    def test_concat_Common_stringlist_string_bool_string(self):

        strs = ["Hello,", "how", "are", "you?"]

        str = Strings.concat(strs, " ", False)

        self.assertEqual(str, "Hello, how are you?")

    def test_concat_Common_stringlist_string_bool_string__1(self):

        strs = ["Hello,", " how", "are", "you?  "]

        str = Strings.concat(strs, " ", True)

        self.assertEqual(str, "Hello, how are you?")

    def test_concat_Common_stringlist_string_bool_string__2(self):

        strs = ["   Hello,", " how ", " are", "                  you?  "]

        str = Strings.concat(strs, " ", True)

        self.assertEqual(str, "Hello, how are you?")

    def test_concat_Common_stringlist_string_bool_string__3(self):
        strs = ["   Hello,", " how", "are", "you?"]

        str = Strings.concat(strs, ",", True)

        self.assertEqual(str, "Hello,,how,are,you?")

    def test_concat_Special_stringlist_string_bool_string(self):
        strs = ["", "", "", ""]

        str = Strings.concat(strs, " ", False)

        self.assertEqual(str, "   ")

    def test_concat_Special_stringlist_string_bool_string__1(self):
        strs = [" ", "", "", ""]

        str = Strings.concat(strs, ",", True)

        self.assertEqual(str, ",,,")

    def test_concat_Nullable_stringlistNone_string_bool_string(self):

        strs = None

        with self.assertRaises(StringsException):
            Strings.concat(strs, " ", False)

    def test_concat_Nullable_stringlistNone_string_bool_string__1(self):

        strs = None

        with self.assertRaises(StringsException):
            Strings.concat(strs, " ", True)

    def test_replace_Common_string_string_string_bool_string(self):

        str = "Hello, World!"
        token1 = "H"
        token2 = "C"

        result = Strings.replace(str, token1, token2, False)

        self.assertEqual(result, "Cello, World!")

    def test_replace_Common_string_string_string_bool_string__1(self):

        str = "  Hello, World!  "
        token1 = "H"
        token2 = "C"

        result = Strings.replace(str, token1, token2, True)

        self.assertEqual(result, "Cello, World!")

    def test_replace_Special_string_string_string_bool_string(self):
            str = ""
            token1 = "H"
            token2 = "C"

            result = Strings.replace(str, token1, token2, False)

            self.assertEqual(result, "")

    def test_replace_Special_string_string_string_bool_string__1(self):
            str = "Hello, World!"
            token1 = "C"
            token2 = "H"

            result = Strings.replace(str, token1, token2, False)

            self.assertEqual(result, "Hello, World!")

    def test_replace_Special_string_string_string_bool_string__1(self):

            str = "Hello, World!"
            token1 = ""
            token2 = "H"

            with self.assertRaises(StringsException):
                Strings.replace(str, token1, token2, False)

    def test_replace_Special_string_string_string_bool_string__2(self):

            str = "Hello, World!"
            token1 = "H"
            token2 = ""

            with self.assertRaises(StringsException):
                Strings.replace(str, token1, token2, False)

    def test_replace_Special_string_string_string_bool_string__3(self):

            str = "Hello, World!"
            token1 = ""
            token2 = "H"

            with self.assertRaises(StringsException):
                Strings.replace(str, token1, token2, True)

    def test_replace_Special_string_string_string_bool_string__4(self):

            str = "Hello, World!"
            token1 = "H"
            token2 = ""

            with self.assertRaises(StringsException):
                Strings.replace(str, token1, token2, True)