using System;
using System.Configuration;
using NUnit.Framework;
using NUnit.Framework.Internal;

namespace GetRealGood.Utils.Tests
{
    
    
    public class ObjectsTests
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

        class IsNullTests {
        
            [SetUp]
            public void Setup()
            {
            }

            [TearDown]
            public void TearDown()
            {
            }
            
        [Test]
        public void IsNull_Common_Object_Boolean()
        {
            
            object o = new object();
            Assert.AreEqual(Objects.IsNull(o), false);
        }

        [Test]
        public void IsNull_Nullable_Null_Boolean()
        {

            object o = null;
            Assert.AreEqual(Objects.IsNull(o), true);
        }
        }

        
        class IsNotNullTests
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
            public void IsNotNull_Common_Object_Boolean()
            {
                object o = new object();
                Assert.AreEqual(Objects.IsNotNull(o), true);
            }

            [Test]
            public void IsNotNull_Nullable_Null_Boolean()
            {
                object o = null;
                Assert.AreEqual(Objects.IsNotNull(o), false);
            }

        }

    }
}