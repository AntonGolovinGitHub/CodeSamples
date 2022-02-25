package tech.getrealgood.util;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * Set of utility methods to manipulate arrays of objects.
 */
public final class Arrays {

    public static <T> boolean isEmpty(T[] coll) throws ArraysException {
        if (Objects.isNull(coll))
            throw new ArraysException("Null parameter passed in for coll");
        return coll.length == 0;
    }

    /**
     *
     * @param ar
     * @param <T>
     * @return
     * @throws ArraysException
     */
    public static <T> boolean isNotEmpty(T[] ar) throws ArraysException {
        if (Objects.isNull(ar))
            throw new ArraysException("Null parameter passed in for coll");
        return ar.length > 0;
    }

    /**
     *
     * @param ar
     * @param <T>
     * @return
     * @throws ArraysException
     */
    public static <T> List<Long> hasNullsAt(T[] ar) throws ArraysException {
        if (Objects.isNull(ar))
            throw new ArraysException("Null parameter passed in for coll");

        long i = 0;
        List<Long> s = new ArrayList<>(0);
        for (var v : ar) {
            if (Objects.isNull(v))
                s.add(i);
            i++;
        }

        return s;
    }

    /**
     *
     * @param ar
     * @param <T>
     * @return
     * @throws ArraysException
     */
    public static <T> boolean hasNulls(T[] ar) throws ArraysException {
        if (Objects.isNull(ar))
            throw new ArraysException("Null parameter passed in for ar");

        for (var v : ar) {
            if (Objects.isNull(v))
                return true;
        }

        return false;
    }

    /**
     *
     * @param ar
     * @param <T>
     * @return
     * @throws ArraysException
     */
    public static <T> long hasNullsCount(T[] ar) throws ArraysException {
        if (Objects.isNull(ar))
            throw new ArraysException("Null parameter passed in for ar");

        return hasNullsAt(ar).size();

    }

    /**
     *
     * @param ar
     * @param <T>
     * @return
     * @throws ArraysException
     */
    public static <T extends Comparable<T>> T max(T[] ar) throws ArraysException {
        if (Objects.isNull(ar))
            throw new ArraysException("Null parameter passed in for ar");

        if (ar.length == 0)
            throw new ArraysException("Empty parameter passed in for ar");

        T max = ar[0]; // first location

        if (ar.length == 1)
            return max;

        for (T t : ar) {
            if (Objects.isNull(t))
                continue;
            if (t.compareTo(max) == 0)
                continue;
            if (t.compareTo(max) == 1)
                max = t;
        }

        if(Objects.isNull(max))
            throw new ArraysException("Array contains only nulls");

        return max;

    }

    /**
     *
     * @param ar
     * @param <T>
     * @return
     * @throws ArraysException
     */
    public static <T extends Comparable<T>> T min(T[] ar) throws ArraysException {
        if (Objects.isNull(ar))
            throw new ArraysException("Null parameter passed in for ar");

        if (ar.length == 0)
            throw new ArraysException("Empty parameter passed in for ar");

        T min = ar[0]; // first location

        if (ar.length == 1)
            return min;

        for (T t : ar) {
            if (Objects.isNull(t))
                continue;
            if (t.compareTo(min) == 0)
                continue;
            if (t.compareTo(min) == -1)
                min = t;
        }

        if(Objects.isNull(min))
            throw new ArraysException("Array contains only nulls");

        return min;

    }

    /**
     *
     * @param ar
     * @param <T>
     * @return
     * @throws ArraysException
     */
    public static <T extends Comparable<T>> List<T> peaks(T[] ar) throws ArraysException {
        if (Objects.isNull(ar))
            throw new ArraysException("Null parameter passed in for ar");

        if (ar.length == 0)
            throw new ArraysException("Empty parameter passed in for ar");

        T max = null; // first location

        List<T> peaks = new ArrayList<>();

        if (ar.length == 1) {
            peaks.add(ar[0]);
            return peaks;
        }

        int i = 0;
        for (T t : ar) {
            if (Objects.isNull(t))
                continue;
            if(i++ == 0) {
                max = t;
                peaks.add(max);
            }
            else if (t.compareTo(max) == 0)
                peaks.add(max);
            else if (t.compareTo(max) == 1) {
                peaks.clear();
                max = t;
                peaks.add(max);
            }
        }

        if(peaks.size() == 0)
            throw new ArraysException("Array contains only nulls");

        return peaks;

    }

    /**
     *
     * @param ar
     * @param <T>
     * @return
     * @throws ArraysException
     */
    public static <T extends Comparable<T>> List<T> troughs(T[] ar) throws ArraysException {
        if (Objects.isNull(ar))
            throw new ArraysException("Null parameter passed in for ar");

        if (ar.length == 0)
            throw new ArraysException("Empty parameter passed in for ar");

        T min = null; // first location
        List<T> troughs = new ArrayList<>();

        if (ar.length == 1) {
            troughs.add(ar[0]);
            return troughs;
        }

        int i = 0;
        for (T t : ar) {
            if (Objects.isNull(t))
                continue;
            if(i++ == 0) {
                min = t;
                troughs.add(min);
            }
            else if (t.compareTo(min) == 0)
                troughs.add(min);
            else if (t.compareTo(min) == -1) {
                troughs.clear();
                min = t;
                troughs.add(min);
            }
        }

        if(troughs.size() == 0)
            throw new ArraysException("Array contains only nulls");

        return troughs;

    }
}
