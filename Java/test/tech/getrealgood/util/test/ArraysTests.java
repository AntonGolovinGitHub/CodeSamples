package tech.getrealgood.util.test;

import org.junit.jupiter.api.*;
import org.junit.platform.commons.logging.Logger;
import org.junit.platform.commons.logging.LoggerFactory;
import tech.getrealgood.util.ArraysException;

import static org.junit.jupiter.api.Assertions.*;

class ArraysTests {

    private static final Logger log = LoggerFactory.getLogger(ArraysTests.class);

    @Nested
    class IsEmptyTests {

        @Test
        public void isEmpty_Common_Array_Boolean() {

            try {
                var o = new String[]{"sample1", "sample2"};
                assertEquals(false, tech.getrealgood.util.Arrays.isEmpty(o));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isEmpty_Common_Array_Boolean__1() {

            try {
                var o = new String[0];
                assertEquals(true, tech.getrealgood.util.Arrays.isEmpty(o));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isEmpty_Special_Array_Boolean() {

            try {
                var o = new String[]{"", ""};
                assertEquals(false, tech.getrealgood.util.Arrays.isEmpty(o));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isEmpty_Special_Array_Boolean__1() {

            try {
                var o = new String[]{null, null};
                assertEquals(false, tech.getrealgood.util.Arrays.isEmpty(o));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isEmpty_Nullable_Null_ArraysException() {

            try {
                String[] o = null;
                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.isEmpty(o);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

    }

    @Nested
    class IsNotEmptyTests {

        @Test
        public void isNotEmpty_Common_Array_Boolean() {

            try {
                var o = new String[]{"sample1", "sample2"};
                assertEquals(true, tech.getrealgood.util.Arrays.isNotEmpty(o));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isNotEmpty_Common_Array_Boolean__1() {

            try {
                var o = new String[0];
                assertEquals(false, tech.getrealgood.util.Arrays.isNotEmpty(o));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isNotEmpty_Special_Array_Boolean() {

            try {
                var o = new String[]{"", ""};
                assertEquals(true, tech.getrealgood.util.Arrays.isNotEmpty(o));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isNotEmpty_Special_Array_Boolean__1() {

            try {
                var o = new String[]{null, null};
                assertEquals(true, tech.getrealgood.util.Arrays.isNotEmpty(o));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void isNotEmpty_Nullable_Null_ArraysException() {

            try {
                String[] o = null;
                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.isNotEmpty(o);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

    }


    @Nested
    class HasNullsAtTests {

        @Test
        public void hasNullsAt_Common_Array_List() {
            try {

                String[] s = new String[]{null, null, "null"};

                var result = tech.getrealgood.util.Arrays.hasNullsAt(s);
                assertEquals(2, result.size());

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsAt_Common_Collection_List__1() {
            try {

                String[] s = new String[]{"", "null", "null"};

                var result = tech.getrealgood.util.Arrays.hasNullsAt(s);
                assertEquals(0, result.size());

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsAt_Nullable_Null_ArraysException() {
            try {

                String[] s = null;

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.hasNullsAt(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsAt_Special_Array_List() {
            try {
                String[] s = new String[]{null, null, null};

                var result = tech.getrealgood.util.Arrays.hasNullsAt(s);
                assertEquals(3, result.size());

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

    }

    @Nested
    class HasNullsTests {

        @Test
        public void hasNulls_Common_Array_Boolean() {
            try {

                String[] s = new String[]{"null", null, null};

                var result = tech.getrealgood.util.Arrays.hasNulls(s);
                assertEquals(true, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hasNulls_Common_Array_Boolean__1() {
            try {

                String[] s = new String[]{"null", "null", "null"};

                var result = tech.getrealgood.util.Arrays.hasNulls(s);
                assertEquals(false, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hasNulls_Special_Array_Boolean() {
            try {
                String[] s = new String[]{null, null, null};

                var result = tech.getrealgood.util.Arrays.hasNulls(s);
                assertEquals(true, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void hasNulls_Nullable_Null_ArraysException() {
            try {

                String[] s = null;

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.hasNulls(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

    }

    @Nested
    class HasNullsCountTests {

        @Test
        public void hasNullsCount_Common_Array_Long() {
            try {

                String[] s = new String[]{"null", null, null};

                var result = tech.getrealgood.util.Arrays.hasNullsCount(s);
                assertEquals(2, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsCount_Common_Array_Long__1() {
            try {

                String[] s = new String[]{"null", "null", "null"};

                var result = tech.getrealgood.util.Arrays.hasNullsCount(s);
                assertEquals(0, result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsCount_Nullable_Null_ArraysException() {
            try {

                String[] s = null;

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.hasNullsCount(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        public void hasNullsCount_Special_Array_Long() {
            try {

                String[] s = new String[]{null, null, null};

                var result = tech.getrealgood.util.Arrays.hasNullsCount(s);
                assertEquals(3, result);

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

                var coll = new String[]{"a", "b", "c"};

                var result = tech.getrealgood.util.Arrays.max(coll);

                assertTrue(result.equals("c"));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }


        @Test
        void max_Nullable_Null_ArraysException() {

            try {

                String[] coll = null;

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.max(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void max_Special_Arrays_ArraysException() {

            try {

                var coll = new String[]{null, null, null};

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.max(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void max_Special_Array_ArraysException__1() {

            try {

                var coll = new String[0];

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.max(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void max_Special_Array_Object__2() {

            try {

                var coll = new String[]{"a", "b", null};

                var result = tech.getrealgood.util.Arrays.max(coll);

                assertTrue(result.equals("b"));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }


    }


    @Nested
    class MinTests {

        @Test
        void min_Common_Array_Object() {

            try {

                var coll = new String[]{"a", "b", "c"};

                var result = tech.getrealgood.util.Arrays.min(coll);

                assertTrue(result.equals("a"));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }


        @Test
        void min_Nullable_Null_ArraysException() {

            try {

                String[] coll = null;

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.min(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void min_Special_Array_ArraysException() {

            try {

                var coll = new String[]{null, null, null};

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.min(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void min_Special_Array_ArraysException__1() {

            try {

                var coll = new String[0];

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.min(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void min_Special_Array_Object__2() {

            try {

                var coll = new String[]{"a", "b", null};

                var result = tech.getrealgood.util.Arrays.min(coll);

                assertTrue(result.equals("a"));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

    }

    @Nested
    class PeaksTests {

        @Test
        void peaks_Common_Array_Object() {

            try {

                var coll = new String[]{"a", "b", "c"};

                var result = tech.getrealgood.util.Arrays.peaks(coll);

                assertTrue(result.size() == 1);
                assertTrue(result.get(0) == "c");

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void peaks_Nullable_Null_ArraysException() {

            try {

                String[] coll = null;

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.peaks(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void peaks_Special_Array_ArraysException() {

            try {

                var coll = new String[]{null, null, null};

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.peaks(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void peaks_Special_Array_ArraysException__1() {

            try {

                var coll = new String[0];

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.peaks(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void peaks_Special_Array_Object__2() {

            try {

                var coll = new String[]{"a", "b", null};

                var result = tech.getrealgood.util.Arrays.peaks(coll);

                assertTrue(result.size() == 1);
                assertTrue(result.get(0).equals("b"));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

    }


    @Nested
    class TroughsTests {

        @Test
        void troughs_Common_Array_Object() {

            try {

                var coll = new String[]{"a", "b", "c"};

                var result = tech.getrealgood.util.Arrays.troughs(coll);

                assertTrue(result.size() == 1);
                assertTrue(result.get(0) == "a");

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }


        @Test
        void troughs_Nullable_Null_ArraysException() {

            try {

                String[] coll = null;

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.troughs(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void troughs_Special_Array_ArraysException() {

            try {

                var coll = new String[]{null, null, null};

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.troughs(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void troughs_Special_Array_ArraysException__1() {

            try {

                var coll = new String[0];

                assertThrows(ArraysException.class, () -> {
                    tech.getrealgood.util.Arrays.troughs(coll);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void troughs_Special_Array_Object__2() {

            try {

                var coll = new String[]{"a", "b", null};

                var result = tech.getrealgood.util.Arrays.troughs(coll);

                assertTrue(result.size() == 1);
                assertTrue(result.get(0).equals("a"));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

    }

}