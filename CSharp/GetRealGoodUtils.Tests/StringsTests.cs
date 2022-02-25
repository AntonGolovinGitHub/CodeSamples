using System;
using NUnit.Framework;
using System.Collections.Generic;

namespace GetRealGood.Utils.Tests
{
    public class StringsTests
    {

        [OneTimeSetUp]
        public static void SetupAll()
        {
        }

        [OneTimeTearDown]
        public static void TearDownAll()
        {
        }

        [SetUp]
        public void Setup()
        {
        }

        [TearDown]
        public void TearDown()
        {
        }

        class ToUpperTests
        {
            [SetUp]
            public void Setup()
            {
            }

            [TearDown]
            public void TearDown()
            {
            }

            [Test]
            public void ToUpper_Common_String_String()
            {

                try
                {

                    string s = "Hello, World!";

                    string result = Strings.ToUpper(s);
                    Assert.AreEqual("HELLO, WORLD!", result);
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void ToUpper_Nullable_Null_StringsException()
            {

                try
                {
                    string s = null;
                    Assert.Throws(typeof(StringsException), delegate { Strings.ToUpper(s); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void ToUpper_Empty_String_String()
            {

                try
                {
                    string s = "";
                    Assert.AreEqual(s, Strings.ToUpper(s));

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void ToUpper_Exceptional_String_StringsException()
            {

                try
                {
                    String s = null;
                    Assert.Throws(typeof(StringsException), delegate { Strings.ToUpper(s); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }
        }

        class ToLowerTests
        {

            [SetUp]
            public void Setup()
            {
            }

            [TearDown]
            public void TearDown()
            {
            }

            [Test]
            public void ToLower_Common_String_String()
            {

                try
                {
                    string s = "Hello, World!";
                    s = Strings.ToLower(s);
                    Assert.AreNotEqual(null, s);
                    Assert.AreEqual("hello, world!", s);
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void ToLower_Nullable_Null_StringsException()
            {

                try
                {
                    String s = null;
                    Assert.Throws(typeof(StringsException), delegate { Strings.ToLower(s); });
                    // Assert.That(delegate { Strings.ToLower(s); }, Throws.Exception.TypeOf(typeof(StringsException)));
                    

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }

            [Test]
            public void ToLower_Empty_String_String()
            {

                try
                {
                    string s = "";
                    Assert.AreEqual(s, Strings.ToLower(s));

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }

            [Test]
            public void ToLower_Exceptional_String_StringsException()
            {

                try
                {
                    string s = null;
                    Assert.Throws(typeof(StringsException), delegate { Strings.ToLower(s); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }
        }

        
         
    class SplitTests {

        [SetUp]
        public void SetUp() {

        }

        [TearDown]
        public void TearDown() {

        }

        [Test]
        public void Split_Common_String_Boolean_String() {
            try {
                String s = "Hello, World!";
                var result = Strings.Split(s, ',', false);
                Assert.AreEqual(result.Contains("Hello"), true);
                Assert.AreEqual(result.Contains(" World!"), true);
                Assert.AreEqual(result[0], "Hello");
                Assert.AreEqual(result[1], " World!");

            } catch (Exception ex) {
                Assert.Fail(ex.Message);

            }
        }

        [Test]
        public void Split_Common_String_Boolean_String__1() {
            try {
                String s = "Hello, World! ";
                var result = Strings.Split(s, ',', true);
                Assert.AreEqual(result.Contains("Hello"), true);
                Assert.AreEqual(result.Contains("World!"), true);
                Assert.AreEqual(result[0], "Hello");
                Assert.AreEqual(result[1], "World!");

            } catch (Exception ex) {
                Assert.Fail(ex.Message);

            }
        }

        [Test]
        public void Split_Common_String_Boolean_String__2() {
            try {
                String s = "Hello, World! ";
                var result = Strings.Split(s, ',', false);
                Assert.AreEqual(result.Contains("Hello"), true);
                Assert.AreEqual(result.Contains(" World! "), true);
                Assert.AreEqual(result[0], "Hello");
                Assert.AreEqual(result[1], " World! ");

            } catch (Exception ex) {
                Assert.Fail(ex.Message);

            }
        }

        [Test]
        public void Split_Nullable_Null_Boolean_StringsException() {
            try {
                String s = null;
                Assert.Throws(typeof(StringsException), delegate {
                    Strings.Split(s, ',', false);
                });
            } catch (Exception ex) {
                Assert.Fail(ex.Message);

            }
        }

        [Test]
        public void Split_Empty_String_Boolean_String() {
            try {
                String s = "";
                Assert.AreEqual(0, Strings.Split(s, '`', false).Count);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);

            }
        }
    }

        class ConcatTests
        {

            [SetUp]
            public void Setup()
            {
            }

            [TearDown]
            public void TearDown()
            {
            }


            [Test]
            public void Concat_Common_StringList_String_Boolean_String()
            {
                try
                {
                    IList<string> s = new List<string> {"Hello", "World!"};
                    var result = Strings.Concat(s, ", ", true);
                    Assert.AreEqual("Hello, World!", result);
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }

            [Test]
            public void Concat_Common_StringList_String_Boolean_String__1()
            {
                try
                {
                    IList<string> s = new List<string> {"Hello ", " World!"};
                    var result = Strings.Concat(s, ", ", false);
                    Assert.AreEqual("Hello ,  World!", result);
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }

            [Test]
            public void Concat_Common_StringList_String_Boolean_String__2()
            {
                try
                {
                    IList<string> s = new List<string> {"Hello ", " World!"};
                    var result = Strings.Concat(s, ", ", true);
                    Assert.AreEqual("Hello, World!", result);
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }


            [Test]
            public void Concat_Empty_StringList_String_Boolean_String()
            {
                try
                {
                    IList<string> s = new List<string> {"", ""};
                    var result = Strings.Concat(s, ", ", false);
                    Assert.AreEqual("", result);
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }

            [Test]
            public void Concat_Empty_StringList_String_Boolean_String__1()
            {
                try
                {
                    IList<string> s = new List<string> {"", ""};
                    var result = Strings.Concat(s, ", ", true);
                    Assert.AreEqual("", result);
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }

            [Test]
            public void Concat_Nullable_Null_String_Boolean_StringsException()
            {
                try
                {
                    IList<string> s = null;
                    Assert.Throws(typeof(StringsException), delegate { Strings.Concat(s, ",", true); });
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }


            [Test]
            public void Concat_Nullable_Null_String_Boolean_StringsException__1()
            {
                try
                {
                    IList<String> s = null;
                    Assert.Throws(typeof(StringsException), delegate { Strings.Concat(s, ",", false); });
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);

                }
            }
        }

        class ReplaceTests
        {

            [SetUp]
            public void Setup()
            {
            }

            [TearDown]
            public void TearDown()
            {
            }

            [Test]
            public void Replace_Common_String_Char_Char_Boolean_String()
            {

                try
                {

                    string origin = "Hello, World! ";
                    char original = 'o';
                    char replace = 'e';
                    string result = Strings.Replace(origin, original, replace, true);
                    Assert.AreEqual("Helle, Werld!", result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Common_String_Char_Char_Boolean_String__1()
            {

                try
                {

                    string origin = "Hello, World! ";
                    char original = 'o';
                    char replace = 'e';
                    string result = Strings.Replace(origin, original, replace, false);
                    Assert.AreEqual("Helle, Werld! ", result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Empty_String_Char_Char_Boolean_String()
            {

                try
                {

                    string origin = "";
                    char original = 'o';
                    char replace = 'e';
                    string result = Strings.Replace(origin, original, replace, true);
                    Assert.AreEqual("", result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Empty_String_Char_Char_Boolean_String__1()
            {

                try
                {

                    string origin = "";
                    char original = 'o';
                    char replace = 'e';
                    string result = Strings.Replace(origin, original, replace, false);
                    Assert.AreEqual("", result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Nullable_Null_Char_Char_Boolean_StringsException()
            {

                try
                {

                    string origin = null;
                    char original = 'o';
                    char replace = 'e';
                    Assert.Throws(typeof(StringsException), delegate { Strings.Replace(origin, 'a', 'b', true); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Nullable_Null_Char_Char_Boolean_StringsException__1()
            {

                try
                {

                    string origin = null;
                    char original = 'o';
                    char replace = 'e';
                    Assert.Throws(typeof(StringsException), delegate { Strings.Replace(origin, 'a', 'b', true); });
                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Special_String_Char_Char_Boolean_String()
            {

                try
                {

                    string origin = "Hello, World! ";
                    char original = 'x';
                    char replace = 'e';
                    string result = Strings.Replace(origin, original, replace, true);
                    Assert.AreEqual("Hello, World!", result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Special_String_Char_Char_Boolean_String__1()
            {

                try
                {

                    string origin = "Hello, World! ";
                    char original = 'x';
                    char replace = 'e';
                    string result = Strings.Replace(origin, original, replace, false);
                    Assert.AreEqual("Hello, World! ", result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

        }

        class ReplaceTests__1
        {

            [SetUp]
            public void Setup()
            {
            }

            [TearDown]
            public void TearDown()
            {
            }

            
            [Test]
            public void Replace_Common_String_Char_Char_String()
            {

                try
                {

                    string origin = "Hello, World! ";
                    char original = 'o';
                    char replace = 'e';
                    string result = Strings.Replace(origin, original, replace);
                    Assert.AreEqual("Helle, Werld! ", result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Empty_String_Char_Char_String()
            {

                try
                {

                    string origin = "";
                    char original = 'o';
                    char replace = 'e';
                    string result = Strings.Replace(origin, original, replace);
                    Assert.AreEqual("", result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void Replace_Nullable_Null_Char_Char_Boolean_StringsException()
            {

                try
                {

                    string origin = null;
                    char original = 'o';
                    char replace = 'e';
                    Assert.Throws(typeof(StringsException), delegate { Strings.Replace(origin, original, replace); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }
        }
    }

}