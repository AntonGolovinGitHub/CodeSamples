package tech.getrealgood.util.test;

import org.junit.jupiter.api.*;
import org.junit.platform.commons.logging.Logger;
import org.junit.platform.commons.logging.LoggerFactory;
import tech.getrealgood.util.Collections;
import tech.getrealgood.util.CollectionsException;

import java.util.*;

import static org.junit.jupiter.api.Assertions.*;

class CollectionsTests {

    private static final Logger log = LoggerFactory.getLogger(CollectionsTests.class);

    @Nested
    class IsEmptyTests {

        @Test
        public void isEmpty_Common_Collection_Boolean()
        {

            try {
                var o = Arrays.asList("sample1", "sample2");
                assertEquals(false, Collections.isEmpty(o));

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isEmpty_Common_Collection_Boolean__1()
        {

            try {
                var o = new ArrayList(0);
                assertEquals(true, Collections.isEmpty(o));

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isEmpty_Special_Collection_Boolean ()
        {

            try {
                var o = Arrays.asList("", "");
                assertEquals(false, Collections.isEmpty(o));

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isEmpty_Special_Collection_Boolean__1()
        {

            try {
                var o = Arrays.asList(null, null);
                assertEquals(false, Collections.isEmpty(o));

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isEmpty_Nullable_Null_CollectionsException()
        {

            try {
                List o = null;
                assertThrows(CollectionsException.class, () -> { Collections.isEmpty(o); });

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

    }

    @Nested
    class IsNotEmptyTests {

        @Test
        public void isNotEmpty_Common_Collection_Boolean()
        {

            try {
                var o = Arrays.asList("sample1", "sample2");
                assertEquals(true, Collections.isNotEmpty(o));

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isNotEmpty_Common_Collection_Boolean__1()
        {

            try {
                var o = new ArrayList(0);
                assertEquals(false, Collections.isNotEmpty(o));

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isNotEmpty_Special_Collection_Boolean ()
        {

            try {
                var o = Arrays.asList("", "");
                assertEquals(true, Collections.isNotEmpty(o));

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isNotEmpty_Special_Collection_Boolean__1()
        {

            try {
                var o = Arrays.asList(null, null);
                assertEquals(true, Collections.isNotEmpty(o));

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isNotEmpty_Nullable_Null_CollectionsException()
        {

            try {
                List o = null;
                assertThrows(CollectionsException.class, () -> { Collections.isNotEmpty(o); });

            } catch(Exception ex)
            {
                fail(ex.getMessage());
            }
        }

    }


    @Nested
    class HasNullsAtTests {

        @Test
        public void hasNullsAt_Common_Collection_List()
        {
            try {

                Set s = new HashSet<>();
                s.add(null);
                s.add(null);
                s.add("null");

                var result = Collections.hasNullsAt(s);
                assertEquals(1, result.size());

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsAt_Common_Collection_List__1()
        {
            try {

                Set s = new HashSet<>();
                s.add("");
                s.add("null");
                s.add("null");

                var result = Collections.hasNullsAt(s);
                assertEquals(0, result.size());

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsAt_Nullable_Null_CollectionsException()
        {
            try {

                Set s = null;

                assertThrows(CollectionsException.class, () -> { Collections.hasNullsAt(s); });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsAt_Special_Collection_List()
        {
            try {

                Set s = new HashSet<>();
                s.add(null);
                s.add(null);
                s.add(null);

                var result = Collections.hasNullsAt(s);
                assertEquals(1, result.size());

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }


    }

    @Nested
    class HasNullsTests {

        @Test
        public void hasNulls_Common_Collection_Boolean()
        {
            try {

                Set s = new HashSet();
                s.add("null");
                s.add(null);
                s.add(null);

                var result = Collections.hasNulls(s);
                assertEquals(true, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hasNulls_Common_Collection_Boolean__1()
        {
            try {

                Set s = new HashSet();
                s.add("null");
                s.add("null");
                s.add("null");

                var result = Collections.hasNulls(s);
                assertEquals(false, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hasNulls_Special_Collection_Boolean()
        {
            try {

                Set s = new HashSet();
                s.add(null);
                s.add(null);
                s.add(null);

                var result = Collections.hasNulls(s);
                assertEquals(true, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hasNulls_Nullable_Null_CollectionsException()
        {
            try {

                Set s = null;

                assertThrows(CollectionsException.class, () -> { Collections.hasNulls(s); });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

    }

    @Nested
    class HasNullsCountTests {

        @Test
        public void hasNullsCount_Common_Collection_Long()
        {
            try {

                Set s = new HashSet();
                s.add("null");
                s.add(null);
                s.add(null);

                var result = Collections.hasNullsCount(s);
                assertEquals(1, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsCount_Common_Collection_Long__1()
        {
            try {

                Set s = new HashSet();
                s.add("null");
                s.add("null");
                s.add("null");

                var result = Collections.hasNullsCount(s);
                assertEquals(0, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsCount_Nullable_Null_CollectionsException()
        {
            try {

                Set s = null;

                assertThrows(CollectionsException.class, () -> { Collections.hasNullsCount(s); });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsCount_Special_Collection_Long()
        {
            try {

                Set s = new HashSet();
                s.add(null);
                s.add(null);
                s.add(null);

                var result = Collections.hasNullsCount(s);
                assertEquals(1, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }


    }

    @Nested
    class MaxTests {

        @Test
        void max_Common_Collection_Object() {

            try {

                var coll = new ArrayList();
                coll.add("a");
                coll.add("b");
                coll.add("c");

                var result = Collections.max(coll);

                assertTrue(result.equals("c"));

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }



        @Test
        void max_Nullable_Null_CollectionsException() {

            try {

                Collection coll = null;

                assertThrows(CollectionsException.class, () -> { Collections.max(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void max_Special_Collection_CollectionsException() {

            try {

                var coll = new ArrayList();
                coll.add(null);
                coll.add(null);
                coll.add(null);

                assertThrows(CollectionsException.class, () -> { Collections.max(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void max_Special_Collection_CollectionsException__1() {

            try {

                var coll = new ArrayList(0);

                assertThrows(CollectionsException.class, () -> { Collections.max(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void max_Special_Collection_Object__2() {

            try {

                var coll = new ArrayList();
                coll.add("a");
                coll.add("b");
                coll.add(null);

                var result = Collections.max(coll);

                assertTrue(result.equals("b"));

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }


    }



    @Nested
    class MinTests {

        @Test
        void min_Common_Collection_Object() {

            try {

                var coll = new ArrayList();
                coll.add("a");
                coll.add("b");
                coll.add("c");

                var result = Collections.min(coll);

                assertTrue(result.equals("a"));

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }



        @Test
        void min_Nullable_Null_CollectionsException() {

            try {

                Collection coll = null;

                assertThrows(CollectionsException.class, () -> { Collections.min(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void min_Special_Collection_CollectionsException() {

            try {

                var coll = new ArrayList();
                coll.add(null);
                coll.add(null);
                coll.add(null);

                assertThrows(CollectionsException.class, () -> { Collections.min(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void min_Special_Collection_CollectionsException__1() {

            try {

                var coll = new ArrayList(0);

                assertThrows(CollectionsException.class, () -> { Collections.min(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void min_Special_Collection_Object__2() {

            try {

                var coll = new ArrayList();
                coll.add("a");
                coll.add("b");
                coll.add(null);

                var result = Collections.min(coll);

                assertTrue(result.equals("a"));

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }


    }

    @Nested
    class PeaksTests {

        @Test
        void peaks_Common_Collection_Object() {

            try {

                var coll = new ArrayList();
                coll.add("a");
                coll.add("b");
                coll.add("c");

                var result = Collections.peaks(coll);

                assertTrue(result.size() == 1);
                assertTrue(result.get(0) == "c");

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }



        @Test
        void peaks_Nullable_Null_CollectionsException() {

            try {

                Collection coll = null;

                assertThrows(CollectionsException.class, () -> { Collections.peaks(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void peaks_Special_Collection_CollectionsException() {

            try {

                var coll = new ArrayList();
                coll.add(null);
                coll.add(null);
                coll.add(null);

                assertThrows(CollectionsException.class, () -> { Collections.peaks(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void peaks_Special_Collection_CollectionsException__1() {

            try {

                var coll = new ArrayList(0);

                assertThrows(CollectionsException.class, () -> { Collections.peaks(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void peaks_Special_Collection_Object__2() {

            try {

                var coll = new ArrayList();
                coll.add("a");
                coll.add("b");
                coll.add(null);

                var result = Collections.peaks(coll);

                assertTrue(result.size() == 1);
                assertTrue(result.get(0).equals("b"));

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }



    }


    @Nested
    class TroughsTests {

        @Test
        void troughs_Common_Collection_Object() {

            try {

                var coll = new ArrayList();
                coll.add("a");
                coll.add("b");
                coll.add("c");

                var result = Collections.troughs(coll);

                assertTrue(result.size() == 1);
                assertTrue(result.get(0) == "a");

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }



        @Test
        void troughs_Nullable_Null_CollectionsException() {

            try {

                Collection coll = null;

                assertThrows(CollectionsException.class, () -> { Collections.troughs(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void troughs_Special_Collection_CollectionsException() {

            try {

                var coll = new ArrayList();
                coll.add(null);
                coll.add(null);
                coll.add(null);

                assertThrows(CollectionsException.class, () -> { Collections.troughs(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void troughs_Special_Collection_CollectionsException__1() {

            try {

                var coll = new ArrayList(0);

                assertThrows(CollectionsException.class, () -> { Collections.troughs(coll); });

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void troughs_Special_Collection_Object__2() {

            try {

                var coll = new ArrayList();
                coll.add("a");
                coll.add("b");
                coll.add(null);

                var result = Collections.troughs(coll);

                assertTrue(result.size() == 1);
                assertTrue(result.get(0).equals("a"));

            } catch(Exception ex) {
                fail(ex.getMessage());
            }

        }

    }

}