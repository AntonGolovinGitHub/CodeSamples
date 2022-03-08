import { Maths, MathsError } from '../__files__/maths';

describe('maths_tests', () => {

    test('sum_Common_numberarr_number', () => {
        expect(Maths.sum([1, 0, 1, 1, 1])).toBe(4);
    });

    test('sum_Special_numberarr_number', () => {
        expect(Maths.sum([0, 0, 0, 0, 0])).toBe(0);
    });

    test('sum_Special_numberarr_number__1', () => {
        expect(Maths.sum([0])).toBe(0);
    });

    test('sum_Special_numberarr_number__2', () => {
        expect(Maths.sum([2])).toBe(2);
    });

    test('sum_Empty_numberarr_number', () => {
        expect(Maths.sum([])).toBe(0);
    });

    test('sum_Exceptional_numberarr_MathsError', () => {
        expect(() => { Maths.sum([Number.MAX_VALUE, 1]); }).toThrowError(MathsError);
    });

    test('sum_Exceptional_numberarr_MathsError__1', () => {
        expect(() => { Maths.sum([-Number.MAX_VALUE, -1]); }).toThrowError(MathsError);
    });

    test('sum_Exceptional_numberarr_MathsError__2', () => {
        expect(() => { Maths.sum([Number.MAX_VALUE, -Number.MAX_VALUE, Number.MAX_VALUE, 1]); }).toThrowError(MathsError);
    });

    test('sum_Exceptional_numberarr_MathsError__3', () => {
        expect(() => { Maths.sum([Number.MAX_VALUE, Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });

    test('sum_Exceptional_numberarr_MathsError__4', () => {
        expect(() => { Maths.sum([-Number.MAX_VALUE, -Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });


    test('sum_Nullable_numberarr_MathsError', () => {
        expect(() => { Maths.sum(null); }).toThrowError(MathsError);
    });



    test('subtract_Common_numberarr_number', () => {
        expect(Maths.subtract(2, [1, 0, 1, 1, 1])).toBe(-2);
    });

    test('subtract_Special_numberarr_number', () => {
        expect(Maths.subtract(0,[0, 0, 0, 0, 0])).toBe(0);
    });

    test('subtract_Special_numberarr_number__1', () => {
        expect(Maths.subtract(0, [0])).toBe(0);
    });

    test('subtract_Special_numberarr_number__2', () => {
        expect(Maths.subtract(2, [2])).toBe(0);
    });

    test('subtract_Empty_numberarr_number', () => {
        expect(Maths.subtract(0,[])).toBe(0);
    });

    test('subtract_Exceptional_numberarr_MathsError', () => {
        expect(() => { Maths.subtract(-Number.MAX_VALUE, [Number.MAX_VALUE, 1]); }).toThrowError(MathsError);
    });

    test('subtract_Exceptional_numberarr_MathsError__1', () => {
        expect(() => { Maths.subtract(Number.MAX_VALUE,[-Number.MAX_VALUE, -1]); }).toThrowError(MathsError);
    });

    test('subtract_Exceptional_numberarr_MathsError__2', () => {
        expect(() => { Maths.subtract(-Number.MAX_VALUE, [Number.MAX_VALUE, -Number.MAX_VALUE, Number.MAX_VALUE, 1]); }).toThrowError(MathsError);
    });

    test('subtract_Exceptional_numberarr_MathsError__3', () => {
        expect(() => { Maths.subtract(0, [Number.MAX_VALUE, Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });

    test('subtract_Exceptional_numberarr_MathsError__4', () => {
        expect(() => { Maths.subtract(Number.MAX_VALUE, [-Number.MAX_VALUE, -Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });


    test('subtract_Nullable_numberarr_MathsError', () => {
        expect(() => { Maths.subtract(100, null); }).toThrowError(MathsError);
    });



    test('multiply_Common_numberarr_number', () => {
        expect(Maths.multiply([1, 0, 1, 1, 1])).toBe(0);
    });

    test('multiply_Special_numberarr_number', () => {
        expect(Maths.multiply([0, 0, 0, 0, 0])).toBe(0);
    });

    test('multiply_Special_numberarr_number__1', () => {
        expect(Maths.multiply([0])).toBe(0);
    });

    test('multiply_Special_numberarr_number__2', () => {
        expect(Maths.multiply([2])).toBe(2);
    });

    test('multiply_Empty_numberarr_number', () => {
        expect(() => { Maths.multiply([]); }).toThrowError(MathsError);
    });

    test('multiply_Exceptional_numberarr_MathsError', () => {
        expect(() => { Maths.multiply([Number.MAX_VALUE, 1.1]); }).toThrowError(MathsError);
    });

    test('multiply_Exceptional_numberarr_MathsError__1', () => {
        expect(() => { Maths.multiply([-Number.MAX_VALUE, -1.1]); }).toThrowError(MathsError);
    });

    test('multiply_Exceptional_numberarr_MathsError__2', () => {
        expect(() => { Maths.multiply([Number.MAX_VALUE, -Number.MAX_VALUE, Number.MAX_VALUE, 1]); }).toThrowError(MathsError);
    });

    test('multiply_Exceptional_numberarr_MathsError__3', () => {
        expect(() => { Maths.multiply([Number.MAX_VALUE, Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });

    test('multiply_Exceptional_numberarr_MathsError__4', () => {
        expect(() => { Maths.multiply([-Number.MAX_VALUE, -Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });

    test('multiply_Nullable_numberarr_MathsError', () => {
        expect(() => { Maths.multiply(null); }).toThrowError(MathsError);
    });




    test('sum_Common_numberarr_number', () => {
        expect(Maths.sum([1, 0, 1, 1, 1])).toBe(4);
    });

    test('sum_Special_numberarr_number', () => {
        expect(Maths.sum([0, 0, 0, 0, 0])).toBe(0);
    });

    test('sum_Special_numberarr_number__1', () => {
        expect(Maths.sum([0])).toBe(0);
    });

    test('sum_Special_numberarr_number__2', () => {
        expect(Maths.sum([2])).toBe(2);
    });

    test('sum_Empty_numberarr_number', () => {
        expect(Maths.sum([])).toBe(0);
    });

    test('sum_Exceptional_numberarr_MathsError', () => {
        expect(() => { Maths.sum([Number.MAX_VALUE, 1]); }).toThrowError(MathsError);
    });

    test('sum_Exceptional_numberarr_MathsError__1', () => {
        expect(() => { Maths.sum([-Number.MAX_VALUE, -1]); }).toThrowError(MathsError);
    });

    test('sum_Exceptional_numberarr_MathsError__2', () => {
        expect(() => { Maths.sum([Number.MAX_VALUE, -Number.MAX_VALUE, Number.MAX_VALUE, 1]); }).toThrowError(MathsError);
    });

    test('sum_Exceptional_numberarr_MathsError__3', () => {
        expect(() => { Maths.sum([Number.MAX_VALUE, Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });

    test('sum_Exceptional_numberarr_MathsError__4', () => {
        expect(() => { Maths.sum([-Number.MAX_VALUE, -Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });


    test('sum_Nullable_numberarr_MathsError', () => {
        expect(() => { Maths.sum(null); }).toThrowError(MathsError);
    });



    test('divide_Common_numberarr_number', () => {
        expect(Maths.divide(2, [1, 1, 1, 1, 1])).toBe(2);
    });

    test('divide_Special_numberarr_number', () => {
        expect(Maths.divide(0,[10, 10, 10, 10, 10])).toBe(0);
    });

    test('divide_Special_numberarr_number__1', () => {
        expect(Maths.divide(0, [10])).toBe(0);
    });

    test('divide_Special_numberarr_number__2', () => {
        expect(Maths.divide(2, [2])).toBe(1);
    });

    test('divide_Empty_numberarr_number', () => {
        expect(Maths.divide(0,[])).toBe(0);
    });

    test('divide_Exceptional_numberarr_MathsError', () => {
        expect(() => { Maths.divide(-Number.MAX_VALUE, [1, 0.1]); }).toThrowError(MathsError);
    });

    test('divide_Exceptional_numberarr_MathsError__1', () => {
        expect(() => { Maths.divide(Number.MAX_VALUE,[-1, -0.1]); }).toThrowError(MathsError);
    });

    test('divide_Exceptional_numberarr_MathsError__2', () => {
        expect(() => { Maths.divide(-Number.MAX_VALUE, [Number.MAX_VALUE, 1/-Number.MAX_VALUE, 1/Number.MAX_VALUE, 1]); }).toThrowError(MathsError);
    });

    test('divide_Exceptional_numberarr_MathsError__3', () => {
        expect(() => { Maths.divide(Number.MAX_VALUE, [1/Number.MAX_VALUE, Number.MAX_VALUE * 1000000]); }).toThrowError(MathsError);
    });

    test('divide_Exceptional_numberarr_MathsError__4', () => {
        expect(() => { Maths.divide(Number.MAX_VALUE, [-Number.MAX_VALUE, 1/(-Number.MAX_VALUE * 1000000)]); }).toThrowError(MathsError);
    });


    test('divide_Nullable_numberarr_MathsError', () => {
        expect(() => { Maths.divide(100, null); }).toThrowError(MathsError);
    });


});