using System;
using System.Collections;
using NUnit.Framework;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using NUnit.Framework.Internal;

namespace GetRealGood.Utils.Tests
{
    public class CollectionsTests
    {
        [OneTimeSetUp]
        public void SetupAll()
        {
        }

        [OneTimeTearDown]
        public void TearDownAll()
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
        
        class IsEmptyTests {

        [Test]
        public void IsEmpty_Common_Collection_Boolean()
        {

            try {
                var o = new List<string>() {"sample1", "sample2" };
                Assert.AreEqual(Collections.IsEmpty(o), false);

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void IsEmpty_Common_Collection_Boolean__1()
        {

            try {
                var o = new List<string>(0);
                Assert.AreEqual(Collections.IsEmpty(o), true);

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void IsEmpty_Special_Collection_Boolean ()
        {

            try {
                var o = new List<string> {"", ""};
                Assert.AreEqual(Collections.IsEmpty(o), false);

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void isEmpty_Special_Collection_Boolean__1()
        {

            try {
                var o = new List<string> { null, null };
                Assert.AreEqual(Collections.IsEmpty(o), false);

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void IsEmpty_Nullable_Null_CollectionsException()
        {

            try {
                List<String> o = null;
                Assert.Throws(typeof(CollectionsException), delegate { Collections.IsEmpty(o); });

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

    }
        
    class IsNotEmptyTests {

        [Test]
        public void IsNotEmpty_Common_Collection_Boolean()
        {

            try {
                var o = new List<string>() { "sample1", "sample2" };
                Assert.AreEqual(Collections.IsNotEmpty(o), true);

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void IsNotEmpty_Common_Collection_Boolean__1()
        {

            try {
                var o = new List<string>(0);
                Assert.AreEqual(Collections.IsNotEmpty(o), false);

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void IsNotEmpty_Special_Collection_Boolean ()
        {

            try {
                var o = new List<string>() { "", "" };
                Assert.AreEqual(Collections.IsNotEmpty(o), true);

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void IsNotEmpty_Special_Collection_Boolean__1()
        {

            try {
                var o = new List<string> { null, null };
                Assert.AreEqual(Collections.IsNotEmpty(o), true);

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void IsNotEmpty_Nullable_Null_CollectionsException()
        {

            try {
                List<string> o = null;
                Assert.Throws(typeof(CollectionsException), delegate { Collections.IsNotEmpty(o); });

            } catch(Exception ex)
            {
                Assert.Fail(ex.Message);
            }
        }

    }


    class HasNullsAtTests {

        [Test]
        public void HasNullsAt_Common_Collection_List()
        {
            try {

                var s = new HashSet<string>() {
                null,
                null,
                "null"
                };

                var result = Collections.HasNullsAt(s);
                Assert.AreEqual(1, result.Count());

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void HasNullsAt_Common_Collection_List__1()
        {
            try
            {

                var s = new HashSet<string>()
                {
                    "",
                    "null",
                    "null"
                };

                var result = Collections.HasNullsAt(s);
                Assert.AreEqual(0, result.Count());

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void HasNullsAt_Nullable_Null_CollectionsException()
        {
            try {

                ISet<string> s = null;

                Assert.Throws(typeof(CollectionsException), delegate { Collections.HasNullsAt(s); });

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void HasNullsAt_Special_Collection_List()
        {
            try
            {

                ISet<string> s = new HashSet<string>()
                {
                    null,
                    null,
                    null
                };

                var result = Collections.HasNullsAt(s);
                Assert.AreEqual(1, result.Count());

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }

        }


    }

    
    class HasNullsTests {

        [Test]
        public void HasNulls_Common_Collection_Boolean()
        {
            try
            {

                ISet<string> s = new HashSet<string>()
                {
                    "null",
                    null,
                    null
                };

                var result = Collections.HasNulls(s);
                Assert.AreEqual(true, result);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void HasNulls_Common_Collection_Boolean__1()
        {
            try
            {

                ISet<string> s = new HashSet<string>()
                {
                    "null",
                    "null",
                    "null"
                };

                var result = Collections.HasNulls(s);
                Assert.AreEqual(false, result);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void HasNulls_Special_Collection_Boolean()
        {
            try
            {

                ISet<string> s = new HashSet<string>()
                {
                    null,
                    null,
                    null
                };

                var result = Collections.HasNulls(s);
                Assert.AreEqual(true, result);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

        [Test]
        public void HasNulls_Nullable_Null_CollectionsException()
        {
            try {

                ISet<string> s = null;

                Assert.Throws(typeof(CollectionsException), delegate { Collections.HasNulls(s); });

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }
        }

    }

    
    class HasNullsCountTests {

        [Test]
        public void HasNullsCount_Common_Collection_Long()
        {
            try
            {

                ISet<string> s = new HashSet<string>()
                {
                    "null",
                    null,
                    null
                };

                var result = Collections.HasNullsCount(s);
                Assert.AreEqual(1, result);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void HasNullsCount_Common_Collection_Long__1()
        {
            try
            {

                ISet<string> s = new HashSet<string>()
                {
                    "null",
                    "null",
                    "null"
                };

                var result = Collections.HasNullsCount(s);
                Assert.AreEqual(0, result);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void HasNullsCount_Nullable_Null_CollectionsException()
        {
            try {

                ISet<String> s = null;

                Assert.Throws(typeof(CollectionsException), delegate { Collections.HasNullsCount(s); });

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void HasNullsCount_Special_Collection_Long()
        {
            try
            {

                ISet<string> s = new HashSet<string>()
                {
                  null,
                  null,
                  null
                };

                var result = Collections.HasNullsCount(s);
                Assert.AreEqual(1, result);

            } catch (Exception ex) {
                Assert.Fail(ex.Message);
            }

        }


    }

    
    class MaxTests {

        [Test]
        public void Max_Common_Collection_Object() {

            try
            {

                var coll = new List<string>()
                {
                  "a",
                  "b",
                  "c"
                };

                var result = Collections.Max(coll);

                Assert.IsTrue(result.Equals("c"));

            } catch(Exception ex) {
                    Assert.Fail(ex.Message);
            }

        }



        [Test]
        public void Max_Nullable_Null_CollectionsException() {

            try {

                Collection<string> coll = null;

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Max(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Max_Special_Collection_CollectionsException() {

            try
            {

                var coll = new List<string>()
                {
                    null,
                    null,
                    null
                };

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Max(coll); });

            } catch(Exception ex) {
                 Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Max_Special_Collection_CollectionsException__1() {

            try {

                var coll = new List<string>(0);

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Max(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Max_Special_Collection_Object__1() {

            try
            {

                var coll = new List<string>()
                {
                    "a",
                    "b",
                    null
                };

                var result = Collections.Max(coll);

                Assert.IsTrue(result.Equals("b"));

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }


    }



    
    class MinTests {

        [Test]
        public void Min_Common_Collection_Object() {

            try
            {

                var coll = new List<string>()
                {
                    "a",
                    "b",
                    "c"
                };
                var result = Collections.Min(coll);

                Assert.IsTrue(result.Equals("a"));

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }



        [Test]
        public void Min_Nullable_Null_CollectionsException() {

            try {

                Collection<string> coll = null;

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Min(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Min_Special_Collection_CollectionsException() {

            try
            {

                var coll = new List<string>()
                {
                    null,
                    null,
                    null
                };
                
                Assert.Throws(typeof(CollectionsException), delegate { Collections.Min(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Min_Special_Collection_CollectionsException__1() {

            try {

                var coll = new List<string>(0);

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Min(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Min_Special_Collection_Object__1() {

            try
            {

                var coll = new List<string>()
                {
                    "a",
                    "b",
                    null
                };

                var result = Collections.Min(coll);

                Assert.IsTrue(result.Equals("a"));

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

    }

    class PeaksTests {

        [Test]
        public void Peaks_Common_Collection_Object() {

            try
            {

                var coll = new List<string>()
                {
                    "a",
                    "b",
                    "c"
                };

                var result = Collections.Peaks(coll);

                Assert.IsTrue(result.Count() == 1);
                Assert.IsTrue(result[0].Equals("c"));

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }



        [Test]
        public void Peaks_Nullable_Null_CollectionsException() {

            try {

                Collection<string> coll = null;

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Peaks(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Peaks_Special_Collection_CollectionsException() {

            try
            {

                var coll = new List<string>()
                {
                    null,
                    null,
                    null
                };

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Peaks(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Peaks_Special_Collection_CollectionsException__1() {

            try {

                var coll = new List<string>(0);

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Peaks(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Peaks_Special_Collection_Object__1() {

            try
            {

                var coll = new List<string>()
                {
                    "a",
                    "b",
                    null
                };

                var result = Collections.Peaks(coll);

                Assert.IsTrue(result.Count() == 1);
                Assert.IsTrue(result[0].Equals("b"));

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

    }


    class Troughs {

        [Test]
        public void Troughs_Common_Collection_Object() {

            try
            {

                var coll = new List<string>() {
                "a",
                "b",
                "c"
            };

                var result = Collections.Troughs(coll);

                Assert.IsTrue(result.Count() == 1);
                Assert.IsTrue(result[0] == "a");

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Troughs_Nullable_Null_CollectionsException() {

            try {

                Collection<string> coll = null;

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Troughs(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Troughs_Special_Collection_CollectionsException() {

            try
            {

                var coll = new List<string>() {
                null,
                null,
                null
            };

            

            ;

            Assert.Throws(typeof(CollectionsException), delegate { Collections.Troughs(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Troughs_Special_Collection_CollectionsException__1() {

            try {

                var coll = new List<string>(0);

                Assert.Throws(typeof(CollectionsException), delegate { Collections.Troughs(coll); });

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

        [Test]
        public void Troughs_Special_Collection_Object__1() {

            try
            {

                var coll = new List<string>()
                {
                    "a",
                    "b",
                    null
                };

                var result = Collections.Troughs(coll);

                Assert.IsTrue(result.Count() == 1);
                Assert.IsTrue(result[0].Equals("a"));

            } catch(Exception ex) {
                Assert.Fail(ex.Message);
            }

        }

    }

    }
}