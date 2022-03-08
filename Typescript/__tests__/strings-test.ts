import { Strings, StringsError } from '../__files__/strings';

describe('strings_tests', () => {

    test('toUpper_Common_string_boolean', () => {
        expect(Strings.toUpper("hello, world!")).toBe("HELLO, WORLD!");
    });

    test('toUpper_Common_string_boolean__1', () => {
        expect(Strings.toUpper("hello, World!")).toBe("HELLO, WORLD!");
    });

    test('toUpper_Common_string_boolean__2', () => {
        expect(Strings.toUpper(" hello, World!")).toBe(" HELLO, WORLD!");
    });

    test('toUpper_Empty_string_boolean', () => {
        expect(Strings.toUpper("")).toBe("");
    });

    test('toUpper_Empty_string_boolean__1', () => {
        expect(Strings.toUpper(" ")).toBe(" ");
    });

    test('toUpper_Nullable_string_StringsError', () => {
        expect(() => { Strings.toUpper(null); }).toThrowError(StringsError);
    });

    test('toLower_Common_string_boolean', () => {
        expect(Strings.toLower("HELLO, WORLD!")).toBe("hello, world!");
    });

    test('toLower_Common_string_boolean__1', () => {
        expect(Strings.toLower("HELLO, World!")).toBe("hello, world!");
    });

    test('toLower_Common_string_boolean__2', () => {
        expect(Strings.toLower(" hello, World!")).toBe(" hello, world!");
    });

    test('toLower_Empty_string_boolean', () => {
        expect(Strings.toLower("")).toBe("");
    });

    test('toLower_Empty_string_boolean__1', () => {
        expect(Strings.toLower(" ")).toBe(" ");
    });

    test('toLower_Nullable_string_StringsError', () => {
        expect(() => { Strings.toLower(null); }).toThrowError(StringsError);
    });

    test('split_Common_string_string_boolean_stringarr', () => {
        let result = Strings.split("HELLO, WORLD!", " ", false);
        expect(result.length).toBe(2);
        expect(result[0]).toBe("HELLO,");
        expect(result[1]).toBe("WORLD!");
    });
    test('split_Common_string_string_boolean_stringarr__1', () => {
        let result = Strings.split(" HELLO, WORLD!  ", " ", true);
        expect(result.length).toBe(2);
        expect(result[0]).toBe("HELLO,");
        expect(result[1]).toBe("WORLD!");
    });

    test('split_Nullable_string_string_boolean_StringsError', () => {
        expect(() => { Strings.split(null, " ", false); }).toThrowError(StringsError);
    });

    test('split_Nullable_string_string_boolean_StringsError__1', () => {
        expect(() => { Strings.split("Hello, World!", null, false); }).toThrowError(StringsError);
    });

    test('split_Nullable_string_string_boolean_StringsError__2', () => {
        expect(() => { Strings.split(null, " ", true); }).toThrowError(StringsError);
    });

    test('split_Nullable_string_string_boolean_StringsError__3', () => {
        expect(() => { Strings.split("Hello, World!", null, true); }).toThrowError(StringsError);
    });

    test('split_Empty_string_string_boolean_stringarr', () => {
        let result = Strings.split("", " ", false);
        expect(result.length).toBe(1);
        expect(result[0]).toBe("");
    });

    test('split_Empty_string_string_boolean_stringarr__1', () => {
        let result = Strings.split(" ", " ", true);
        expect(result.length).toBe(1);
        expect(result[0]).toBe("");
    });

    test('split_Empty_string_string_boolean_stringarr__2', () => {
        let result = Strings.split("       ", " ", true);
        expect(result.length).toBe(1);
        expect(result[0]).toBe("");
    });

    test('split_Empty_string_string_boolean_StringsError__3', () => {
        expect(() => { Strings.split("Hello, World!", "", false); }).toThrowError(StringsError);
    });

    test('split_Empty_string_string_boolean_StringsError__4', () => {
        expect(() => { Strings.split("Hello, World!", "", true); }).toThrowError(StringsError);
    });

    test('concat_Common_stringarr_string_boolean_string', () => {
        let result = Strings.concat(["HELLO,", "WORLD!"], " ", false);
        expect(result).toBe("HELLO, WORLD!");
    });

    test('concat_Common_stringarr_string_boolean_string__1', () => {
        let result = Strings.concat(["HELLO, ", " WORLD!"], " ", true);
        expect(result).toBe("HELLO, WORLD!");
    });

    test('concat_Nullable_stringarr_string_boolean_StringsError', () => {
        expect(() => { Strings.concat(null, " ", false); }).toThrowError(StringsError);
    });

    test('concat_Nullable_stringarr_string_boolean_StringsError__1', () => {
        expect(() => { Strings.concat(null, " ", true); }).toThrowError(StringsError);
    });

    test('concat_Nullable_stringarr_string_boolean_StringsError__2', () => {
        expect(() => { Strings.concat(["HELLO, ", " WORLD!"], null, false); }).toThrowError(StringsError);
    });

    test('concat_Nullable_stringarr_string_boolean_StringsError__3', () => {
        expect(() => { Strings.concat(["HELLO, ", " WORLD!"], null, true); }).toThrowError(StringsError);
    });

    test('concat_Empty_stringarr_string_boolean_StringsError', () => {
        expect(() => { Strings.concat([], " ", false); }).toThrowError(StringsError);
    });

    test('concat_Empty_stringarr_string_boolean_StringsError__1', () => {
        expect(() => { Strings.concat([], " ", true); }).toThrowError(StringsError);
    });

    test('concat_Empty_stringarr_string_boolean_string', () => {
        let result = Strings.concat(["", " WORLD!"], "", false);
        expect(result).toBe(" WORLD!");
    });

    test('concat_Empty_stringarr_string_boolean_string__1', () => {
        let result = Strings.concat(["", " WORLD!"], "", true);
        expect(result).toBe("WORLD!");
    });

    test('replace_Common_string_string_string_boolean_string', () => {
        let result = Strings.replace("HELLO, WORLD!", "H", "M", false);
        expect(result).toBe("MELLO, WORLD!");
    });

    test('replace_Common_string_string_string_boolean_string__1', () => {
        let result = Strings.replace("   HELLO, WORLD!       ", "H", "M", true);
        expect(result).toBe("MELLO, WORLD!");
    });

    test('replace_Common_string_string_string_boolean_string__2', () => {
        let result = Strings.replace("HELLO, WORLD!", "L", "R", false);
        expect(result).toBe("HERRO, WORRD!");
    });

    test('replace_Common_string_string_string_boolean_string__3', () => {
        let result = Strings.replace(" HELLO, WORLD !", "L", "R", true);
        expect(result).toBe("HERRO, WORRD !");
    })

    test('replace_Nullable_string_string_string_boolean_StringsError', () => {
        expect(() => { Strings.replace(null, "H", "L", false); }).toThrowError(StringsError);
    });

    test('replace_Nullable_string_string_string_boolean_StringsError__1', () => {
        expect(() => { Strings.replace(null, "H", "L", true); }).toThrowError(StringsError);
    });

    test('replace_Nullable_string_string_string_boolean_StringsError__2', () => {
        expect(() => { Strings.replace("Hello, World!", null, "L", false); }).toThrowError(StringsError);
    });

    test('replace_Nullable_string_string_string_boolean_StringsError__3', () => {
        expect(() => { Strings.replace("Hello, World!", null, "L", true); }).toThrowError(StringsError);
    });

    test('replace_Nullable_string_string_string_boolean_StringsError__4', () => {
        expect(() => { Strings.replace("Hello, World!", "H", null, false); }).toThrowError(StringsError);
    });

    test('replace_Nullable_string_string_string_boolean_StringsError__5', () => {
        expect(() => { Strings.replace("Hello, World!", "H", null, true); }).toThrowError(StringsError);
    });

    test('replace_Empty_string_string_string_boolean_string', () => {
        let result = Strings.replace("", "H", "M", false);
        expect(result).toBe("");
    });

    test('replace_Empty_string_string_string_boolean_string__1', () => {
        let result = Strings.replace("", "H", "M", true);
        expect(result).toBe("");
    });

    test('replace_Empty_string_string_string_boolean_string__2', () => {
        expect(() => { Strings.replace("Hello, World!", "", "M", false); }).toThrowError(StringsError);
    });

    test('replace_Empty_string_string_string_boolean_string__3', () => {
        expect(() => { Strings.replace("Hello, World!", "", "M", true); }).toThrowError(StringsError);
    });

    test('replace_Empty_string_string_string_boolean_string__4', () => {
        let result = Strings.replace("Hello, World!", "H", "", false);
        expect(result).toBe("ello, World!");
    });

    test('replace_Empty_string_string_string_boolean_string__5', () => {
        let result = Strings.replace(" Hello, World!", "H", "", true);
        expect(result).toBe("ello, World!");
    });
});