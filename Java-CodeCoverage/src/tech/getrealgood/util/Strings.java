package tech.getrealgood.util;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

/**
 *
 */
public final class Strings {

    /**
     * @param s
     * @return
     */
    public static String toUpper(String s) throws StringsException {

        if (Objects.isNull(s))
            throw new StringsException("Null parameter passed in for s");
        return s.toUpperCase();

    }

    /**
     *
     * @param s
     * @return
     * @throws StringsException
     */
    public static List<String> toUpper(List<String> s) throws StringsException {

        if (Objects.isNull(s))
            throw new StringsException("Null parameter passed in for s");

        var result = new ArrayList<String>(s.size());

        for (var s1: s) {

            result.add(toUpper(s1));
        }

        return result;

    }

    /**
     * @param s
     * @return
     */
    public static String toLower(String s) throws StringsException {
        if (Objects.isNull(s))
            throw new StringsException("Null parameter passed in for s");
        return s.toLowerCase();

    }

    /**
     *
     * @param s
     * @return
     * @throws StringsException
     */
    public static List<String> toLower(List<String> s) throws StringsException {

        if (Objects.isNull(s))
            throw new StringsException("Null parameter passed in for s");

        var result = new ArrayList<String>(s.size());

        for (var s1: s) {

            result.add(toLower(s1));
        }

        return result;

    }

    /**
     * @param s
     * @param token
     * @param trim
     * @return
     */
    public static List<String> split(String s, char token, boolean trim) throws StringsException {
        if (Objects.isNull(s))
            throw new StringsException("Null parameter passed in for s");

        if(s.length() == 0)
            return new ArrayList<>(0);

        List<String> result = Arrays.<String>asList(s.split(String.valueOf(token)));

        if (trim) {
            result = result.stream().map(String::trim).collect(Collectors.toList());
        }

        return result;
    }

    /**
     * @param s
     * @param token
     * @param trim
     * @return
     */
    public static String concat(List<String> s, String token, boolean trim) throws StringsException {

        if (Objects.isNull(s))
            throw new StringsException("Null parameter passed in for s");

        String result = new String("");
        int counter = 0;
        int length = s.size() - 1;

        for (var e : s) {

            if (trim) {
                if(e.length() == 0)
                    continue;
                result += e.trim();
            }
            else {
                if(e.length() == 0)
                    continue;
                result += e;
            }

            if (Objects.isNull(token))
                continue;
            else {
                if (counter < length) {
                    result += token;
                    counter++;
                }

            }

        }

        return result;
    }

    /**
     * @param s
     * @param orig
     * @param w
     * @param trim
     * @return
     * @throws StringsException
     */
    public static String replace(String s, char orig, char w, boolean trim) throws StringsException {
        if (Objects.isNull(s))
            throw new StringsException("Null value passed in for s");

        if (trim)
            s = s.trim();

        char[] chars = s.toCharArray();

        for (var i = 0; i < chars.length; i++)
            if (chars[i] == orig)
                chars[i] = w;

        return new String(chars);
    }

    /**
     * @param s
     * @param orig
     * @param w
     * @return
     */
    public static String replace(String s, char orig, char w) throws StringsException {
        if (Objects.isNull(s))
            throw new StringsException("Null value passed in for s");
        return replace(s, orig, w, false);
    }

}