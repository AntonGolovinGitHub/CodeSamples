export class MathsError {

    message: string

    constructor(s: string) {
        this.message = s;
    }
}

export class Maths {

    public EConst: number = 2.7182818284590451;
    public PIConst: number = 3.1415926535897931;

    public static sum(vars: number[]): number {

        if (vars == null)
            throw new MathsError("Null value passed in");

        if (vars.length == 0)
            return 0;

        let result: number = 0;

        try {

            for (var v of vars) {
                result = this.addAndCheckOverflow(result, v);
            }

        } catch (ex) {
            throw new MathsError(ex.message);
        }

        return result;
    }

    public static subtract(value: number, vars: number[]): number {

        if (vars == null)
            throw new MathsError("Null vars value passed in");

        if (vars.length == 0)
            return value;

        let result: number = value;

        try {

            for (let v of vars) {
                result = this.subtractAndCheckOverflow(result, v);
            }
        } catch (ex) {
            throw new MathsError(ex.message);
        }

        return result;
    }

    public static multiply(vars: number[]): number {
        if (vars == null)
            throw new MathsError("Null value passed in");

        if (vars.length == 0)
            throw new MathsError("Empty value passed in");

        let result: number = 1;

        try {
            for (let v of vars) {
                result = this.multiplyAndCheckOverflow(result, v);
            }
        } catch (ex) {
            throw new MathsError(ex.message);
        }

        return result;
    }

    public static divide(value: number, vars: number[]): number {

        if (vars == null)
            throw new MathsError("Null vars value passed in");

        if (vars.length == 0)
            return value;

        let result: number = value;

        try {
            for (let v of vars) {
                if (v == 0)
                    throw new MathsError("Division by zero");
                result = this.divideAndCheckOverflow(result, v);
            }
        } catch (ex) {
            throw new MathsError(ex.message);
        }

        return result;
    }

    public static powerOf(value: number, toThePowersOf: number[]): number {

        if (toThePowersOf == null)
            throw new MathsError("Null value passed in");

        if (toThePowersOf.length == 0)
            throw new MathsError("Empty value passed in");

        let result: number = value;

        try {

            let totalPowerOf: number = this.sum(toThePowersOf);

            if (totalPowerOf == null)
                throw new MathsError("Null value passed in");

            if (totalPowerOf == 0)
                return 1;

            if (totalPowerOf == 1)
                return value;

            result = Math.pow(result, totalPowerOf);

        } catch (ex) {
            throw new MathsError(ex.message);
        }

        if (result == Number.POSITIVE_INFINITY)
            throw new MathsError("Positive overflow");
        if (result == Number.NEGATIVE_INFINITY)
            throw new MathsError("Negative overflow");

        return result;
    }

    public static quadratic(a: number, b?: number, c?: number): number[] {

        var result: number[] = [];

        try {
            // a is never null or zero
            if (a == 0.00)
                throw new MathsError("Coefficient a is zero");

            b = b == null ? 0.00 : b;
            c = c == null ? 0.00 : c;

            if (b == 0.00 && c == 0.00 || ((b == null) && (c == null))) {
                // only one solution
                result[0] = 0.00;
                result[1] = null;
                return result;
            }

            let partOne = -b;
            let minus =
                this.subtractAndCheckOverflow(this.multiplyAndCheckOverflow(b, b),
                    this.multiplyAndCheckOverflow(4.00, this.multiplyAndCheckOverflow(a, c)));
            if (minus < 0)
                throw new MathsError("No real-number solution to the quadratic equation");
            let partTwo = Math.sqrt(minus);
            let partThree = this.multiplyAndCheckOverflow(2.00, a);

            result[0] = this.divideAndCheckOverflow(this.addAndCheckOverflow(partOne, partTwo), partThree);
            result[1] = this.divideAndCheckOverflow(this.subtractAndCheckOverflow(partOne, partTwo), partThree);
        } catch (ex) {
            throw new MathsError(ex.message);
        }

        return result;
    }

    public static hypotenuse(nearLine: number, farLine: number): number {
        if (nearLine <= 0)
            throw new MathsError("Invalid parameter value for nearLine (<=0)");

        if (farLine <= 0)
            throw new MathsError("Invalid parameter value for farLine (<=0)");

        let result: number;

        try {

            result = Math.sqrt(
                this.addAndCheckOverflow(this.multiplyAndCheckOverflow(
                    nearLine, nearLine), this.multiplyAndCheckOverflow(farLine, farLine)));
        } catch (ex) {
            throw new MathsError(ex.message);
        }

        return result;
    }

    // anything greater than Number.MAX_VALUE or less than -Number.MAX_VALUE is an overflow
    private static addAndCheckOverflow(o1: number, o2: number): number {

        if (o1 == 0 || o2 == 0)
            return o1 + o2;

        if (o1 == Number.MAX_VALUE && o2 > 0)
            throw new MathsError("Positive Overflow");

        if (o2 == Number.MAX_VALUE && o1 > 0)
            throw new MathsError("Positive Overflow");

        if (o1 == -Number.MAX_VALUE && o2 < 0)
            throw new MathsError("Negative Overflow");

        if (o2 == -Number.MAX_VALUE && o1 < 0)
            throw new MathsError("Negative Overflow");

        if (Number.MAX_VALUE - o1 == o2) {
            return Number.MAX_VALUE;
        }

        if (-Number.MAX_VALUE - o1 == o2) {
            return -Number.MAX_VALUE;
        }

        let result: number = o1 + o2;

        if (result == Number.POSITIVE_INFINITY)
            throw new MathsError("Positive Overflow");

        if (result == Number.NEGATIVE_INFINITY)
            throw new MathsError("Negative Overflow");

        return result;

    }

    // anything greater than Number.MAX_VALUE or less than -Number.MAX_VALUE is an overflow
    private static subtractAndCheckOverflow(o1: number, o2: number): number {

        if (o1 == 0 || o2 == 0)
            return o1 - o2;

        if (o1 == Number.MAX_VALUE && o2 < 0)
            throw new MathsError("Positive Overflow");

        if (o2 == Number.MAX_VALUE && o1 < 0)
            throw new MathsError("Negative Overflow");

        if (o1 == -Number.MAX_VALUE && o2 > 0)
            throw new MathsError("Negative Overflow");

        if (o2 == -Number.MAX_VALUE && o1 > 0)
            throw new MathsError("Positive Overflow");

        if (Number.MAX_VALUE + o1 == o2) {
            return -Number.MAX_VALUE;
        }

        if (-Number.MAX_VALUE + o1 == o2) {
            return Number.MAX_VALUE;
        }

        let result: number = o1 - o2;

        if (result == Number.POSITIVE_INFINITY)
            throw new MathsError("Positive Overflow");

        if (result == Number.NEGATIVE_INFINITY)
            throw new MathsError("Negative Overflow");

        return result;

    }

    // anything greater than Number.MAX_VALUE or less than -Number.MAX_VALUE is an overflow
    private static multiplyAndCheckOverflow(o1: number, o2: number): number {

        if (o1 == 0 || o2 == 0)
            return 0;

        if (o1 == Number.MAX_VALUE && o2 > 1)
            throw new MathsError("Positive Overflow");

        if (o2 == Number.MAX_VALUE && o1 > 1)
            throw new MathsError("Positive Overflow");

        if (o1 == -Number.MAX_VALUE && o2 > 1)
            throw new MathsError("Negative Overflow");

        if (o2 == -Number.MAX_VALUE && o1 > 1)
            throw new MathsError("Negative Overflow");

        if (o1 == Number.MAX_VALUE && o2 < -1)
            throw new MathsError("Negative Overflow");

        if (o2 == Number.MAX_VALUE && o1 < -1)
            throw new MathsError("Negative Overflow");

        if (o1 == -Number.MAX_VALUE && o2 < -1)
            throw new MathsError("Positive Overflow");

        if (o2 == -Number.MAX_VALUE && o1 < -1)
            throw new MathsError("Positive Overflow");

        if (Number.MAX_VALUE - o1 == o2) {
            return Number.MAX_VALUE;
        }

        if (-Number.MAX_VALUE - o1 == o2) {
            return -Number.MAX_VALUE;
        }

        let result: number = o1 * o2;

        if (result == Number.POSITIVE_INFINITY)
            throw new MathsError("Positive overflow");

        if (result == Number.NEGATIVE_INFINITY)
            throw new MathsError("Negative overflow");

        return result;

    }

    // anything greater than Number.MAX_VALUE or less than -Number.MAX_VALUE is an overflow
    private static divideAndCheckOverflow(o1: number, o2: number): number {

        if (o1 == 0)
            return 0;

        if (o2 == 0)
            throw new MathsError("Division by zero");

        if (o1 == Number.MAX_VALUE && o2 < 1 && o2 > 0)
            throw new MathsError("Positive Overflow");

        if (o1 == -Number.MAX_VALUE && o2 < 1 && o2 > 0)
            throw new MathsError("Negative Overflow");

        if (o1 == Number.MAX_VALUE && o2 > -1 && o2 < 0)
            throw new MathsError("Negative Overflow");

        if (o1 == -Number.MAX_VALUE && o2 > -1 && o2 < 0)
            throw new MathsError("Positive Overflow");

        if (Number.MAX_VALUE / o2 == o1) {
            return Number.MAX_VALUE;
        }

        if (-Number.MAX_VALUE / o2 == o1) {
            return -Number.MAX_VALUE;
        }

        let result: number = o1 / o2;

        if (result == Number.POSITIVE_INFINITY)
            throw new MathsError("Positive overflow");

        if (result == Number.NEGATIVE_INFINITY)
            throw new MathsError("Negative overflow");

        return result;

    }

}