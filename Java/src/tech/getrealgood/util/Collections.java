package tech.getrealgood.util;

import java.util.*;

/**
 * Set of utility methods to manipulate collections of objects.
 */
public final class Collections {
    /**
     * @param coll
     * @return
     * @throws CollectionsException
     */
    public static boolean isEmpty(Collection<?> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");
        return coll.size() == 0;
    }

    /**
     * @param coll
     * @return
     * @throws CollectionsException
     */
    public static boolean isNotEmpty(Collection<?> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");
        return coll.size() > 0;
    }


    /**
     * @param coll
     * @param <T>
     * @return
     * @throws CollectionsException
     */
    public static <T> List<Long> hasNullsAt(Collection<T> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");

        long i = 0;
        List<Long> s = new ArrayList<>(0);
        for (var v : coll) {
            if (Objects.isNull(v))
                s.add(i);
            i++;
        }

        return s;
    }

    /**
     * @param coll
     * @param <T>
     * @return
     * @throws CollectionsException
     */
    public static <T> boolean hasNulls(Collection<T> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");

        for (var v : coll) {
            if (Objects.isNull(v))
                return true;
        }

        return false;
    }

    /**
     * @param coll
     * @param <T>
     * @return
     * @throws CollectionsException
     */
    public static <T> long hasNullsCount(Collection<T> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");

        return hasNullsAt(coll).size();

    }

    /**
     * @param coll
     * @param <T>
     * @return
     * @throws CollectionsException
     */
    public static <T extends Comparable<T>> T max(Collection<T> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");

        if (isEmpty(coll))
            throw new CollectionsException("Empty parameter passed in for coll");

        T max = coll.iterator().next(); // first location

        if (coll.size() == 1)
            return max;

        for (T t : coll) {
            if (Objects.isNull(t))
                continue;
            if (t.compareTo(max) == 0)
                continue;
            if (t.compareTo(max) == 1)
                max = t;
        }

        if(Objects.isNull(max))
            throw new CollectionsException("All nulls found in Collection");

        return max;

    }

    /**
     * @param coll
     * @param <T>
     * @return
     * @throws CollectionsException
     */
    public static <T extends Comparable<T>> T min(Collection<T> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");

        if (isEmpty(coll))
            throw new CollectionsException("Empty parameter passed in for coll");

        T min = coll.iterator().next(); // first location

        if (coll.size() == 1)
            return min;

        for (T t : coll) {
            if (Objects.isNull(t))
                continue;
            if (t.compareTo(min) == 0)
                continue;
            if (t.compareTo(min) == -1)
                min = t;
        }

        if(Objects.isNull(min))
            throw new CollectionsException("Collection contains only null values");

        return min;

    }

    /**
     * @param coll
     * @param <T>
     * @return
     * @throws CollectionsException
     */
    public static <T extends Comparable<T>> List<T> peaks(Collection<T> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");

        if (isEmpty(coll))
            throw new CollectionsException("Empty parameter passed in for coll");

        T max = null; // first location

        List<T> peaks = new ArrayList<>();

        if (coll.size() == 1) {
            T item = coll.iterator().next();
            if(Objects.isNull(item))
                throw new CollectionsException("The single array item is null");
            peaks.add(item);
            return peaks;
        }

        int i = 0;
        for (T t : coll) {
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

        if(isEmpty(peaks))
            throw new CollectionsException("Array contains only nulls");

        return peaks;

    }

    /**
     *
     * @param coll
     * @param <T>
     * @return
     * @throws CollectionsException
     */
    public static <T extends Comparable<T>> List<T> troughs(Collection<T> coll) throws CollectionsException {
        if (Objects.isNull(coll))
            throw new CollectionsException("Null parameter passed in for coll");

        if (isEmpty(coll))
            throw new CollectionsException("Empty parameter passed in for coll");


        T min = null; // first location
        List<T> troughs = new ArrayList<>();

        if (coll.size() == 1) {
            T item = coll.iterator().next();
            if(Objects.isNull(item))
                throw new CollectionsException("The single array item is null");
            troughs.add(item);
            return troughs;
        }

        int i = 0;
        for (T t : coll) {
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

        if(isEmpty(troughs))
            throw new CollectionsException("Array contains only nulls");


        return troughs;

    }
}
