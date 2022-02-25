package getrealgoodutils

import "math"

type Maths struct {
	errors GetRealGoodUtilsErrors
}

const E float64 = math.E
const PI float64 = math.Pi

// adds 2 int64's with overflow checks
func (m *Maths) addAndCheckOverflowInt64(a int64, b int64) (c int64, error GetRealGoodUtilsErrors) {

	if a == 0 || b == 0 {
		return a + b, NoError
	}

	var result int64

	if a < 0 {
		if b < 0 {
			// check for negative overflow
			if math.MinInt64-b <= a {
				result = a + b
			} else {
				return math.MinInt64, NegativeOverflowError
			}
		} else {
			result = a + b
		}
	} else {

		if b < 0 {
			result = a + b
		} else {
			// check for positive overflow
			if math.MaxInt64-b >= a {
				result = a + b
			} else {
				return math.MaxInt64, PositiveOverflowError
			}
		}
	}

	return result, NoError
}

// adds 2 float64's with overflow checks
func (m *Maths) addAndCheckOverflowFloat64(a float64, b float64) (c float64, error GetRealGoodUtilsErrors) {

	if a == 0.00 || b == 0.00 {
		return a + b, NoError
	}

	var result float64 = a + b

	if result == math.Inf(1) {
		return math.MaxFloat64, PositiveOverflowError
	}

	if result == math.Inf(-1) {
		return -math.MaxFloat64, NegativeOverflowError
	}

	return result, NoError
}

// subtracts 2 int64's with overflow checks
func (m *Maths) subtractAndCheckOverflowInt64(a int64, b int64) (c int64, error GetRealGoodUtilsErrors) {

	if a == 0 || b == 0 {
		return a - b, NoError
	}

	if b < 0 {
		// very edge case due to non-symmetric int64 max, min
		if b == math.MinInt64 {
			var b0 int64 = (b + 1) * -1
			var result0, error = m.addAndCheckOverflowInt64(a, b0)
			if error != NoError {
				return 0, error
			}
			return m.addAndCheckOverflowInt64(result0, -1)
		}
		var b1 int64 = b
		return m.addAndCheckOverflowInt64(a, b1)
	} else {
		var b2 int64 = b * -1
		return m.addAndCheckOverflowInt64(a, b2)
	}
}

// subtracts 2 float64's with overflow checks
func (m *Maths) subtractAndCheckOverflowFloat64(a float64, b float64) (c float64, error GetRealGoodUtilsErrors) {

	if a == 0.00 || b == 0.00 {
		return a - b, NoError
	}

	var result float64 = a - b

	if result == math.Inf(1) {
		return math.MaxFloat64, PositiveOverflowError
	}

	if result == math.Inf(-1) {
		return -math.MaxFloat64, NegativeOverflowError
	}

	return result, NoError
}

// multiplies 2 int64's with overflow checks
func (m *Maths) multiplyAndCheckOverflowInt64(a int64, b int64) (c int64, error GetRealGoodUtilsErrors) {

	if a == 0 || b == 0 {
		return 0, NoError
	}

	var result int64 = a * b

	if a == result/b {
		return result, NoError
	} else {

		if (a > 0 && b > 0) || (a < 0 && b < 0) {
			return 0, PositiveOverflowError
		} else {
			return 0, NegativeOverflowError
		}
	}
}

// multiplies 2 float64's with overflow checks
func (m *Maths) multiplyAndCheckOverflowFloat64(a float64, b float64) (c float64, error GetRealGoodUtilsErrors) {

	if a == 0.00 || b == 0.00 {
		return 0.00, NoError
	}

	var result float64 = a * float64(b)

	if math.IsInf(result, 1) {
		return math.MaxFloat64, PositiveOverflowError
	}

	if math.IsInf(result, -1) {
		return -math.MaxFloat64, NegativeOverflowError
	}

	return result, NoError
}

// divides 2 int64's with overflow checks
func (m *Maths) divideAndCheckOverflowInt64(a int64, b int64) (c int64, error GetRealGoodUtilsErrors) {

	if b == 0 {
		return 0, DivisionByZeroError
	}

	if a == 0 {
		return 0, NoError
	}

	var result int64 = a / b

	if result == 0 || a == result*b {
		return result, NoError
	} else {

		if (a > 0 && b > 0) || (a < 0 && b < 0) {
			return 0, PositiveOverflowError
		} else {
			return 0, NegativeOverflowError
		}
	}
}

// divides 2 float64's with overflow checks
func (m *Maths) divideAndCheckOverflowFloat64(a float64, b float64) (c float64, error GetRealGoodUtilsErrors) {

	if b == 0.00 {
		return 0.00, DivisionByZeroError
	}

	if a == 0.00 {
		return 0.00, NoError
	}

	var result float64 = a / b

	if result == math.Inf(1) {
		return math.MaxFloat64, PositiveOverflowError
	}

	if result == math.Inf(-1) {
		return -math.MaxFloat64, NegativeOverflowError
	}

	return result, NoError
}

func (m *Maths) SumInt64(vars ...int64) (s int64, error GetRealGoodUtilsErrors) {

	if vars == nil {
		return 0, NilError
	}

	if len(vars) == 0 {
		return 0, EmptyError
	}

	if len(vars) == 1 {
		return vars[0], NoError
	}

	var result int64 = 0

	for _, v := range vars {
		result, error = m.addAndCheckOverflowInt64(result, v)
		if error != NoError {
			return 0, error
		}
	}

	return result, NoError
}

func (m *Maths) SumFloat64(vars ...float64) (s float64, error GetRealGoodUtilsErrors) {

	if vars == nil {
		return 0.00, NilError
	}

	if len(vars) == 0 {
		return 0.00, EmptyError
	}

	if len(vars) == 1 {
		return vars[0], NoError
	}

	var result float64 = 0

	for _, v := range vars {
		result, error = m.addAndCheckOverflowFloat64(result, v)
		if error != NoError {
			return 0.00, error
		}
	}

	return result, NoError
}

func (m *Maths) SubtractInt64(value int64, vars ...int64) (s int64, error GetRealGoodUtilsErrors) {

	if vars == nil {
		return 0, NilError
	}

	if len(vars) == 0 {
		return value, NoError
	}

	if len(vars) == 1 {
		return m.subtractAndCheckOverflowInt64(value, vars[0])
	}

	var result int64 = value

	for _, v := range vars {
		result, error = m.subtractAndCheckOverflowInt64(result, v)
		if error != NoError {
			return 0, error
		}
	}

	return result, NoError
}

func (m *Maths) SubtractFloat64(value float64, vars ...float64) (s float64, error GetRealGoodUtilsErrors) {

	if vars == nil {
		return 0.00, NilError
	}

	if len(vars) == 0 {
		return value, NoError
	}

	if len(vars) == 1 {
		return m.subtractAndCheckOverflowFloat64(value, vars[0])
	}

	var result float64 = value

	for _, v := range vars {
		result, error = m.subtractAndCheckOverflowFloat64(result, v)
		if error != NoError {
			return 0.00, error
		}
	}

	return result, NoError
}

func (m *Maths) MultiplyInt64(vars ...int64) (s int64, error GetRealGoodUtilsErrors) {

	if vars == nil {
		return 0, NilError
	}

	if len(vars) == 0 {
		return 0, EmptyError
	}

	if len(vars) == 1 {
		return vars[0], NoError
	}

	var result int64 = 1

	for _, v := range vars {
		result, error = m.multiplyAndCheckOverflowInt64(result, v)
		if error != NoError {
			return 0, error
		}
	}

	return result, NoError
}

func (m *Maths) MultiplyFloat64(vars ...float64) (s float64, error GetRealGoodUtilsErrors) {

	if vars == nil {
		return 0.00, NilError
	}

	if len(vars) == 0 {
		return 0.00, EmptyError
	}

	if len(vars) == 1 {
		return vars[0], NoError
	}

	var result float64 = 1.00

	for _, v := range vars {
		result, error = m.multiplyAndCheckOverflowFloat64(result, v)
		if error != NoError {
			return 0.00, error
		}
	}

	return result, NoError
}

func (m *Maths) DivideInt64(value int64, vars ...int64) (s int64, error GetRealGoodUtilsErrors) {

	if vars == nil {
		return 0, NilError
	}

	if len(vars) == 0 {
		return value, NoError
	}

	var result int64 = value

	for _, v := range vars {
		if v == 0 {
			return 0, DivisionByZeroError
		}
		result, error = m.divideAndCheckOverflowInt64(result, v)
		if error != NoError {
			return 0, error
		}
	}

	return result, NoError
}

func (m *Maths) DivideFloat64(value float64, vars ...float64) (s float64, error GetRealGoodUtilsErrors) {

	if vars == nil {
		return 0, NilError
	}

	if len(vars) == 0 {
		return value, NoError
	}

	var result float64 = value

	for _, v := range vars {
		result, error = m.divideAndCheckOverflowFloat64(result, v)
		if error != NoError {
			return 0.00, error
		}
	}

	return result, NoError
}

func (m *Maths) PowerOfInt64(value int64, toThePowersOf ...int64) (result int64, error GetRealGoodUtilsErrors) {

	if toThePowersOf == nil {
		return 0, NilError
	}

	if len(toThePowersOf) == 0 {
		return 0, EmptyError
	}

	var resulted int64 = 1

	var totalPowerOf int64 = 0

	for _, v := range toThePowersOf {
		totalPowerOf, error = m.addAndCheckOverflowInt64(totalPowerOf, v)
		if error != NoError {
			return 0, error
		}
	}

	if totalPowerOf == 0 {
		return 1, NoError
	}

	if totalPowerOf == 1 {
		return resulted, NoError
	}

	var powerOf int64 = 1

	for powerOf = 1; powerOf <= totalPowerOf; powerOf++ {
		resulted, error = m.multiplyAndCheckOverflowInt64(resulted, value)
		if error != NoError {
			return 0, error
		}
	}

	return resulted, NoError
}

func (m *Maths) PowerOfFloat64Int64(value float64, toThePowersOf ...int64) (result float64, error GetRealGoodUtilsErrors) {

	if toThePowersOf == nil {
		return 0, NilError
	}

	if len(toThePowersOf) == 0 {
		return 0, EmptyError
	}

	var resulted float64 = 1

	var totalPowerOf int64 = 0

	for _, v := range toThePowersOf {
		totalPowerOf, error = m.addAndCheckOverflowInt64(totalPowerOf, v)
		if error != NoError {
			return 0, error
		}
	}

	if totalPowerOf == 0 {
		return 1, NoError
	}

	if totalPowerOf == 1 {
		return resulted, NoError
	}

	var powerOf int64 = 1

	for powerOf = 1; powerOf <= totalPowerOf; powerOf++ {
		resulted, error = m.multiplyAndCheckOverflowFloat64(resulted, value)
		if error != NoError {
			return 0, error
		}
	}

	return resulted, NoError
}

func (m *Maths) PowerOfFloat64Float64(value float64, toThePowersOf ...float64) (result float64, error GetRealGoodUtilsErrors) {

	if toThePowersOf == nil {
		return 0, NilError
	}

	if len(toThePowersOf) == 0 {
		return 0, EmptyError
	}

	var resulted float64 = value

	var totalPowerOf float64 = 0

	for _, v := range toThePowersOf {
		totalPowerOf, error = m.addAndCheckOverflowFloat64(totalPowerOf, v)
		if error != NoError {
			return 0, error
		}
	}

	if totalPowerOf == 0 {
		return 1, NoError
	}

	if totalPowerOf == 1 {
		return resulted, NoError
	}

	resulted = math.Pow(resulted, totalPowerOf)

	if math.IsInf(resulted, 1) {
		return 0, PositiveOverflowError
	}

	if math.IsInf(resulted, -1) {
		return 0, NegativeOverflowError
	}

	return resulted, NoError
}

func (m *Maths) Quadratic(a float64, b float64, c float64) (d []float64, error GetRealGoodUtilsErrors) {

	var result []float64 = []float64{}

	// a is never null or zero
	if a == 0.00 {
		return result, NilError
	}

	if b == 0.00 && c == 0.00 {
		// only one solution
		result = append(result, 0.00)
		return result, NoError
	}

	var partOne float64 = -b

	var entry1, error1 = m.multiplyAndCheckOverflowFloat64(a, c)

	if error1 != NoError {
		return nil, error1
	}

	var entry2, error2 = m.multiplyAndCheckOverflowFloat64(4.00, entry1)

	if error2 != NoError {
		return nil, error2
	}

	var entry3, error3 = m.multiplyAndCheckOverflowFloat64(b, b)

	if error3 != NoError {
		return nil, error3
	}

	var entry4, error4 = m.subtractAndCheckOverflowFloat64(entry3, entry2)

	if error4 != NoError {
		return nil, error4
	}

	var partTwo float64 = math.Sqrt(entry4)

	var partThree, error5 = m.multiplyAndCheckOverflowFloat64(2.00, a)

	if error5 != NoError {
		return nil, error5
	}

	var entry6, error6 = m.addAndCheckOverflowFloat64(partOne, partTwo)

	if error6 != NoError {
		return nil, error6
	}

	var result0, error7 = m.divideAndCheckOverflowFloat64(entry6, partThree)

	if error7 != NoError {
		return nil, error7
	}

	var entry8, error8 = m.subtractAndCheckOverflowFloat64(partOne, partTwo)

	if error8 != NoError {
		return nil, error8
	}

	var result1, error9 = m.divideAndCheckOverflowFloat64(entry8, partThree)

	if error9 != NoError {
		return nil, error9
	}

	result = append(result, result0)
	result = append(result, result1)

	return result, NoError
}

func (m *Maths) Hypotenuse(nearLine float64, farLine float64) (result float64, error GetRealGoodUtilsErrors) {

	if nearLine <= 0 {
		return 0, NoopError
	}

	if farLine <= 0 {
		return 0, NoopError
	}

	var entry1, error1 = m.multiplyAndCheckOverflowFloat64(farLine, farLine)

	if error1 != NoError {
		return 0, error1
	}

	var entry2, error2 = m.multiplyAndCheckOverflowFloat64(nearLine, nearLine)

	if error2 != NoError {
		return 0, error2
	}

	var entry3, error3 = m.addAndCheckOverflowFloat64(entry2, entry1)

	if error3 != NoError {
		return 0, error3
	}

	result = math.Sqrt(entry3)

	return result, NoError
}
