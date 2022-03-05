package tech.getrealgood.util.test;

import org.junit.jupiter.api.*;
import org.junit.platform.commons.logging.Logger;
import org.junit.platform.commons.logging.LoggerFactory;
import tech.getrealgood.util.Strings;
import tech.getrealgood.util.StringsException;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class StringsTests {

    private static final Logger log = LoggerFactory.getLogger(StringsTests.class);

    @Nested
    class ToUpperTests {

        @Test
        void toUpper_Common_String_String() {

            try {

                String s = "Hello, World!";

                String result = Strings.toUpper(s);
                assertEquals("HELLO, WORLD!", result);
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Common_String_String__1() {

            try {

                String s = "Hello, World!";

                String result = Strings.toUpper(s);
                assertNotEquals(s, result);
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Common_String_String__2() {

            try {

                String s = "Hello, World!";

                String result = Strings.toUpper(s);
                assertTrue(!s.equals(result));
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Common_String_String__3() {

            try {

                String s = "Hello, World!";

                String result = Strings.toUpper(s);
                assertFalse(s.equals(result));
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Common_String_String__4() {

            try {

                String s = "Hello, World!";

                String result = Strings.toUpper(s);
                assertNotNull(result);
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Common_String_String__5() {

            try {

                String s = "Hello, World!";

                assertDoesNotThrow(() -> {
                    Strings.toUpper(s);
                });
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Nullable_Null_StringsException() {

            try {
                String s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.toUpper(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Empty_String_String() {

            try {
                String s = "";
                assertEquals(s, Strings.toUpper(s));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Exceptional_String_StringsException() {

            try {
                String s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.toUpper(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

    }

    @Nested
    class ToUpperTests__1 {

        @Test
        void toUpper_Common_StringList_StringList() {

            try {

                var s = new ArrayList(3);

                s.add("Hello, World!");
                s.add("hello, world!");
                s.add("HELLO, WORLD!");

                var s2 = new ArrayList(3);

                s2.add("HELLO, WORLD!");
                s2.add("HELLO, WORLD!");
                s2.add("HELLO, WORLD!");

                var result = Strings.toUpper(s);

                assertLinesMatch(s2, result);
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Common_StringList_StringList__1() {

            try {

                var s = new String[]{"Hello, World!", "hello, world!", "HELLO, WORLD!"};

                var s2 = new String[]{"HELLO, WORLD!", "HELLO, WORLD!", "HELLO, WORLD!"};

                var result = Strings.toUpper(Arrays.asList(s));

                assertArrayEquals(s2, result.toArray());
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Nullable_Null_StringsException() {

            try {
                List s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.toUpper(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Empty_StringList_String() {

            try {
                List s = new ArrayList<>(0);
                assertEquals(s, Strings.toUpper(s));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toUpper_Exceptional_StringList_StringsException() {

            try {
                var s = new ArrayList(3);

                s.add("Hello, World!");
                s.add(null);
                s.add("HELLO, WORLD!");

                assertThrows(StringsException.class, () -> {
                    Strings.toUpper(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

    }


    @Nested
    class ToLowerTests {

        @Test
        void toLower_Common_String_String() {

            try {
                String s = "Hello, World!";
                s = Strings.toLower(s);
                assertNotEquals(null, s);
                assertEquals("hello, world!", s);
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toLower_Nullable_Null_StringsException() {

            try {
                String s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.toLower(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void toLower_Empty_String_String() {

            try {
                String s = "";
                assertEquals(s, Strings.toLower(s));

            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void toLower_Exceptional_String_StringsException() {

            try {
                String s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.toLower(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }
    }

    @Nested
    class ToLowerTests__1 {

        @Test
        void toLower_Common_StringList_StringList() {

            try {

                var s = new ArrayList(3);

                s.add("Hello, World!");
                s.add("hello, world!");
                s.add("HELLO, WORLD!");

                var s2 = new ArrayList(3);

                s2.add("hello, world!");
                s2.add("hello, world!");
                s2.add("hello, world!");

                var result = Strings.toLower(s);

                assertLinesMatch(s2, result);
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toLower_Common_StringList_StringList__1() {

            try {

                var s = new ArrayList(3);

                s.add("Hello, World!");
                s.add("hello, world!");
                s.add("HELLO, WORLD!");

                var s2 = new ArrayList(3);

                s2.add("hello, world!");
                s2.add("hello, world!");
                s2.add("hello, world!");

                var result = Strings.toLower(s);

                assertIterableEquals(s2, result);
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toLower_Common_StringList_StringList__2() {

            try {

                var s = new ArrayList(3);

                s.add("Hello, World!");
                s.add("hellO, world!");
                s.add("HELLO, WORLD!");

                var s2 = new ArrayList(3);

                s2.add("hello, world!");
                s2.add("hello, world!");
                s2.add("hello, world!");

                var result = Strings.toLower(s);

                for (var i = 0; i < s2.size(); i++) {
                    assertNotSame(s2.get(i), result.get(i));
                }

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toLower_Common_StringList_StringList__3() {

            try {

                var s = new ArrayList(3);

                s.add("hello, world!");
                s.add("hello, world!");
                s.add("hello, world!");

                var s2 = new ArrayList(3);

                s2.add("hello, world!");
                s2.add("hello, world!");
                s2.add("hello, world!");

                var result = Strings.toLower(s);

                for (var i = 0; i < s2.size(); i++) {
                    assertSame(s2.get(i), result.get(i));
                }

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }


        @Test
        void toLower_Common_StringList_StringList__4() {

            try {

                var s = new String[]{"Hello, World!", "hello, world!", "HELLO, WORLD!"};

                var s2 = new String[]{"hello, world!", "hello, world!", "hello, world!"};

                var result = Strings.toLower(Arrays.asList(s));

                assertArrayEquals(s2, result.toArray());
            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }


        @Test
        void toLower_Nullable_Null_StringsException() {

            try {
                List s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.toLower(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toLower_Empty_StringList_String() {

            try {
                List s = new ArrayList<>(0);
                assertEquals(s, Strings.toLower(s));

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

        @Test
        void toLower_Exceptional_StringList_StringsException() {

            try {
                var s = new ArrayList(3);

                s.add("Hello, World!");
                s.add(null);
                s.add("HELLO, WORLD!");

                assertThrows(StringsException.class, () -> {
                    Strings.toLower(s);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }

        }

    }


    @Nested
    class SplitTests {

        @Test
        void split_Common_String_Boolean_String() {
            try {
                String s = "Hello, World!";
                var result = Strings.split(s, ',', false);
                assertEquals(true, result.contains("Hello"));
                assertEquals(true, result.contains(" World!"));
                assertEquals("Hello", result.get(0));
                assertEquals(" World!", result.get(1));

            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void split_Common_String_Boolean_String__1() {
            try {
                String s = "Hello, World! ";
                var result = Strings.split(s, ',', true);
                assertEquals(true, result.contains("Hello"));
                assertEquals(true, result.contains("World!"));
                assertEquals("Hello", result.get(0));
                assertEquals("World!", result.get(1));

            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void split_Common_String_Boolean_String__2() {
            try {
                String s = "Hello, World! ";
                var result = Strings.split(s, ',', false);
                assertEquals(true, result.contains("Hello"));
                assertEquals(true, result.contains(" World! "));
                assertEquals("Hello", result.get(0));
                assertEquals(" World! ", result.get(1));

            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void split_Nullable_Null_Boolean_StringsException() {
            try {
                String s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.split(s, ',', false);
                });
            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void split_Empty_String_Boolean_String() {
            try {
                String s = "";
                assertEquals(0, Strings.split(s, '`', false).size());

            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }
    }

    @Nested
    class ConcatTests {

        @Test
        void concat_Common_StringList_String_Boolean_String() {
            try {
                List s = Arrays.asList("Hello", "World!");
                var result = Strings.concat(s, ", ", true);
                assertEquals("Hello, World!", result);
            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void concat_Common_StringList_String_Boolean_String__1() {
            try {
                List s = Arrays.asList("Hello ", " World!");
                var result = Strings.concat(s, ", ", false);
                assertEquals("Hello ,  World!", result);
            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void concat_Common_StringList_String_Boolean_String__2() {
            try {
                List s = Arrays.asList("Hello ", " World!");
                var result = Strings.concat(s, ", ", true);
                assertEquals("Hello, World!", result);
            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }


        @Test
        void concat_Empty_StringList_String_Boolean_String() {
            try {
                List s = Arrays.asList("", "");
                var result = Strings.concat(s, ", ", false);
                assertEquals("", result);
            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void concat_Empty_StringList_String_Boolean_String__1() {
            try {
                List s = Arrays.asList("", "");
                var result = Strings.concat(s, ", ", true);
                assertEquals("", result);
            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }

        @Test
        void concat_Nullable_Null_String_Boolean_StringsException() {
            try {
                List s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.concat(s, ",", true);
                });
            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }


        @Test
        void concat_Nullable_Null_String_Boolean_StringsException__1() {
            try {
                List s = null;
                assertThrows(StringsException.class, () -> {
                    Strings.concat(s, ",", false);
                });
            } catch (Exception ex) {
                fail(ex.getMessage());

            }
        }
    }

    @Nested
    class ReplaceTests {

        @Test
        public void replace_Common_String_Char_Char_Boolean_String() {

            try {

                String origin = "Hello, World! ";
                char original = 'o';
                char replace = 'e';
                String result = Strings.replace(origin, original, replace, true);
                assertEquals("Helle, Werld!", result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Common_String_Char_Char_Boolean_String__1() {

            try {

                String origin = "Hello, World! ";
                char original = 'o';
                char replace = 'e';
                String result = Strings.replace(origin, original, replace, false);
                assertEquals("Helle, Werld! ", result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Empty_String_Char_Char_Boolean_String() {

            try {

                String origin = "";
                char original = 'o';
                char replace = 'e';
                String result = Strings.replace(origin, original, replace, true);
                assertEquals("", result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Empty_String_Char_Char_Boolean_String__1() {

            try {

                String origin = "";
                char original = 'o';
                char replace = 'e';
                String result = Strings.replace(origin, original, replace, false);
                assertEquals("", result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Nullable_Null_Char_Char_Boolean_StringsException() {

            try {

                String origin = null;
                char original = 'o';
                char replace = 'e';
                assertThrows(StringsException.class, () -> {
                    Strings.replace(origin, 'a', 'b', true);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Nullable_Null_Char_Char_Boolean_StringsException__1() {

            try {

                String origin = null;
                char original = 'o';
                char replace = 'e';
                assertThrows(StringsException.class, () -> {
                    Strings.replace(origin, 'a', 'b', true);
                });
            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Special_String_Char_Char_Boolean_String() {

            try {

                String origin = "Hello, World! ";
                char original = 'x';
                char replace = 'e';
                String result = Strings.replace(origin, original, replace, true);
                assertEquals("Hello, World!", result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Special_String_Char_Char_Boolean_String__1() {

            try {

                String origin = "Hello, World! ";
                char original = 'x';
                char replace = 'e';
                String result = Strings.replace(origin, original, replace, false);
                assertEquals("Hello, World! ", result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

    }

    @Nested
    class ReplaceTests__1 {

        @Test
        public void replace_Common_String_Char_Char_String() {

            try {

                String origin = "Hello, World! ";
                char original = 'o';
                char replace = 'e';
                String result = Strings.replace(origin, original, replace);
                assertEquals("Helle, Werld! ", result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Empty_String_Char_Char_String() {

            try {

                String origin = "";
                char original = 'o';
                char replace = 'e';
                String result = Strings.replace(origin, original, replace);
                assertEquals("", result);

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

        @Test
        public void replace_Nullable_Null_Char_Char_Boolean_StringsException() {

            try {

                String origin = null;
                char original = 'o';
                char replace = 'e';
                assertThrows(StringsException.class, () -> {
                    Strings.replace(origin, original, replace);
                });

            } catch (Exception ex) {
                fail(ex.getMessage());
            }
        }

    }
}