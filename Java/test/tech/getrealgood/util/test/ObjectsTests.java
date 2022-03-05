package tech.getrealgood.util.test;

import org.junit.jupiter.api.*;
import org.junit.platform.commons.logging.Logger;
import org.junit.platform.commons.logging.LoggerFactory;
import tech.getrealgood.util.Objects;

import static org.junit.jupiter.api.Assertions.*;

class ObjectsTests {

    private static final Logger log = LoggerFactory.getLogger(ObjectsTests.class);

    @Nested
    class IsNull {

        @Test
        void isNull_Common_Object_Boolean() {
            Object o = new Object();
            assertEquals(false, Objects.isNull(o));
        }

        @Test
        void isNull_Nullable_Null_Boolean() {
            Object o = null;
            assertNotEquals(false, Objects.isNull(o));
        }
    }

    @Nested
    class IsNotNull {

        @Test
        public void isNotNull_Common_Object_Boolean() {
            Object o = new Object();
            assertEquals(true, Objects.isNotNull(o));
        }

        @Test
        public void isNotNull_Nullable_Null_Boolean() {
            Object o = null;
            assertNotEquals(true, Objects.isNotNull(o));
        }
    }

}