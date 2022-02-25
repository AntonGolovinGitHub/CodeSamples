using System;
using NUnit.Framework;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;

namespace GetRealGood.Utils.Tests
{
    public class ArraysTests
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

        class IsEmptyTests
        {

            [Test]
            public void IsEmpty_Common_Array_Boolean()
            {

                try
                {
                    var o = new String[] {"sample1", "sample2"};
                    Assert.AreEqual(Arrays.IsEmpty(o), false);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void IsEmpty_Common_Array_Boolean__1()
            {

                try
                {
                    var o = new String[0];
                    Assert.AreEqual(Arrays.IsEmpty(o), true);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void IsEmpty_Special_Array_Boolean()
            {

                try
                {
                    var o = new String[] {"", ""};
                    Assert.AreEqual(Arrays.IsEmpty(o), false);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void IsEmpty_Special_Array_Boolean__1()
            {

                try
                {
                    var o = new String[] {null, null};
                    Assert.AreEqual(Arrays.IsEmpty(o), false);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void IsEmpty_Nullable_Null_ArraysException()
            {

                try
                {
                    String[] o = null;
                    Assert.Throws(typeof(ArraysException), delegate { Arrays.IsEmpty(o); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

        }


        class IsNotEmptyTests
        {

            [Test]
            public void IsNotEmpty_Common_Array_Boolean()
            {

                try
                {
                    var o = new String[] {"sample1", "sample2"};
                    Assert.AreEqual(Arrays.IsNotEmpty(o), true);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void IsNotEmpty_Common_Array_Boolean__1()
            {

                try
                {
                    var o = new String[0];
                    Assert.AreEqual(Arrays.IsNotEmpty(o), false);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void IsNotEmpty_Special_Array_Boolean()
            {

                try
                {
                    var o = new String[] {"", ""};
                    Assert.AreEqual(Arrays.IsNotEmpty(o), true);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void IsNotEmpty_Special_Array_Boolean__1()
            {

                try
                {
                    var o = new String[] {null, null};
                    Assert.AreEqual(Arrays.IsNotEmpty(o), true);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void IsNotEmpty_Nullable_Null_ArraysException()
            {

                try
                {
                    String[] o = null;
                    Assert.Throws(typeof(ArraysException), delegate { Arrays.IsNotEmpty(o); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

        }


        class HasNullsAtTests
        {

            [Test]
            public void HasNullsAt_Common_Array_List()
            {
                try
                {

                    String[] s = new String[] {null, null, "null"};

                    var result = Arrays.HasNullsAt(s);
                    Assert.AreEqual(2, result.Count());

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void HasNullsAt_Common_Collection_List__1()
            {
                try
                {

                    String[] s = new String[] {"", "null", "null"};

                    var result = Arrays.HasNullsAt(s);
                    Assert.AreEqual(0, result.Count());

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void HasNullsAt_Nullable_Null_ArraysException()
            {
                try
                {

                    String[] s = null;

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.HasNullsAt(s); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void HasNullsAt_Special_Array_List()
            {
                try
                {
                    String[] s = new String[] {null, null, null};

                    var result = Arrays.HasNullsAt(s);
                    Assert.AreEqual(3, result.Count());

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

        }


        class HasNullsTests
        {

            [Test]
            public void HasNulls_Common_Array_Boolean()
            {
                try
                {

                    String[] s = new String[] {"null", null, null};

                    var result = Arrays.HasNulls(s);
                    Assert.AreEqual(true, result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void HasNulls_Common_Array_Boolean__1()
            {
                try
                {

                    String[] s = new String[] {"null", "null", "null"};

                    var result = Arrays.HasNulls(s);
                    Assert.AreEqual(false, result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void HasNulls_Special_Array_Boolean()
            {
                try
                {
                    String[] s = new String[] {null, null, null};

                    var result = Arrays.HasNulls(s);
                    Assert.AreEqual(true, result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

            [Test]
            public void HasNulls_Nullable_Null_ArraysException()
            {
                try
                {

                    String[] s = null;

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.HasNulls(s); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }
            }

        }


        class HasNullsCountTests
        {

            [Test]
            public void HasNullsCount_Common_Array_Long()
            {
                try
                {

                    String[] s = new String[] {"null", null, null};

                    var result = Arrays.HasNullsCount(s);
                    Assert.AreEqual(2, result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void HasNullsCount_Common_Array_Long__1()
            {
                try
                {

                    String[] s = new String[] {"null", "null", "null"};

                    var result = Arrays.HasNullsCount(s);
                    Assert.AreEqual(0, result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void HasNullsCount_Nullable_Null_ArraysException()
            {
                try
                {

                    String[] s = null;

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.HasNullsCount(s); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void HasNullsCount_Special_Array_Long()
            {
                try
                {

                    String[] s = new String[] {null, null, null};

                    var result = Arrays.HasNullsCount(s);
                    Assert.AreEqual(3, result);

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }


        }


        class MaxTests
        {

            [Test]
            public void Max_Common_Collection_Object()
            {

                try
                {

                    var coll = new String[] {"a", "b", "c"};

                    var result = Arrays.Max(coll);

                    Assert.IsTrue(result.Equals("c"));

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }



            [Test]
            public void Max_Nullable_Null_ArraysException()
            {

                try
                {

                    String[] coll = null;

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Max(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Max_Special_Arrays_ArraysException()
            {

                try
                {

                    var coll = new String[] {null, null, null};

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Max(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Max_Special_Array_ArraysException__1()
            {

                try
                {

                    var coll = new String[0];

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Max(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Max_Special_Array_Object__2()
            {

                try
                {

                    var coll = new String[] {"a", "b", null};

                    var result = Arrays.Max(coll);

                    Assert.IsTrue(result.Equals("b"));

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

        }

        class MinTests
        {

            [Test]
            public void Min_Common_Array_Object()
            {

                try
                {

                    var coll = new String[] {"a", "b", "c"};

                    var result = Arrays.Min(coll);

                    Assert.IsTrue(result.Equals("a"));

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }



            [Test]
            public void Min_Nullable_Null_ArraysException()
            {

                try
                {

                    String[] coll = null;

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Min(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Min_Special_Array_ArraysException()
            {

                try
                {

                    var coll = new String[] {null, null, null};

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Min(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Min_Special_Array_ArraysException__1()
            {

                try
                {

                    var coll = new String[0];

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Min(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Min_Special_Array_Object__2()
            {

                try
                {

                    var coll = new String[] {"a", "b", null};

                    var result = Arrays.Min(coll);

                    Assert.IsTrue(result.Equals("a"));

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

        }

        class PeaksTests
        {

            [Test]
            public void Peaks_Common_Array_Object()
            {

                try
                {

                    var coll = new String[] {"a", "b", "c"};

                    var result = Arrays.Peaks(coll);

                    Assert.IsTrue(result.Count() == 1);
                    Assert.IsTrue(result[0] == "c");

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Peaks_Nullable_Null_ArraysException()
            {

                try
                {

                    String[] coll = null;

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Peaks(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Peaks_Special_Array_ArraysException()
            {

                try
                {

                    var coll = new String[] {null, null, null};

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Peaks(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Peaks_Special_Array_ArraysException__1()
            {

                try
                {

                    var coll = new String[0];

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Peaks(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Peaks_Special_Array_Object__2()
            {

                try
                {

                    var coll = new String[] {"a", "b", null};

                    var result = Arrays.Peaks(coll);

                    Assert.IsTrue(result.Count() == 1);
                    Assert.IsTrue(result[0].Equals("b"));

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

        }

        class Troughs
        {

            [Test]
            public void Troughs_Common_Array_Object()
            {

                try
                {

                    var coll = new String[] {"a", "b", "c"};

                    var result = Arrays.Troughs(coll);

                    Assert.IsTrue(result.Count() == 1);
                    Assert.IsTrue(result[0] == "a");

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Troughs_Nullable_Null_ArraysException()
            {

                try
                {

                    String[] coll = null;

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Troughs(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Troughs_Special_Array_ArraysException()
            {

                try
                {

                    var coll = new String[] {null, null, null};

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Troughs(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Troughs_Special_Array_ArraysException__1()
            {

                try
                {

                    var coll = new String[0];

                    Assert.Throws(typeof(ArraysException), delegate { Arrays.Troughs(coll); });

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

            [Test]
            public void Troughs_Special_Array_Object__2()
            {

                try
                {

                    var coll = new String[] {"a", "b", null};

                    var result = Arrays.Troughs(coll);

                    Assert.IsTrue(result.Count() == 1);
                    Assert.IsTrue(result[0].Equals("a"));

                }
                catch (Exception ex)
                {
                    Assert.Fail(ex.Message);
                }

            }

        }
    }
    
}