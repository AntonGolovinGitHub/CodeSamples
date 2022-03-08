import { Objects } from '../__files__/objects';

describe('objects_tests', () => {
    test('isNull_Common_Object_Boolean', () => {
        expect(Objects.isNull({})).toBe(false);
    });
    test('isNull_Common_Object_Boolean__1', () => {
        expect(Objects.isNull(null)).toBe(true);
    });
    test('isNotNull_Common_Object_Boolean', () => {
        expect(Objects.isNotNull({})).toBe(true);
    });
    test('isNotNull_Common_Object_Boolean__1', () => {
        expect(Objects.isNotNull(null)).toBe(false);
    });
});