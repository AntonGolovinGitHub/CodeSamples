package getrealgoodutils

type Collections struct{}

func (c *Collections) IsEmpty(m map[int]string) (bool, GetRealGoodUtilsErrors) {

	if m == nil {
		return false, NilError
	}

	return len(m) == 0, NoError
}

func (c *Collections) IsNotEmpty(m map[int]string) (bool, GetRealGoodUtilsErrors) {

	if m == nil {
		return false, NilError
	}

	return len(m) != 0, NoError
}

func (c *Collections) Max(m map[int]string) (string, GetRealGoodUtilsErrors) {

	if m == nil {
		return "", NilError
	}

	if len(m) == 0 {
		return "", EmptyError
	}

	var max string

	var j int = 0

	for _, v := range m {

		if j == 0 {
			max = v
			j++
			continue
		} else {
			if len(v) > len(max) {
				max = v
			}
		}

	}

	return max, NoError

	return "", NoError
}

func (c *Collections) Min(m map[int]string) (string, GetRealGoodUtilsErrors) {

	if m == nil {
		return "", NilError
	}

	if len(m) == 0 {
		return "", EmptyError
	}

	var min string

	var j int = 0

	for _, v := range m {

		if j == 0 {
			min = v
			j++
			continue
		} else {
			if len(v) < len(min) {
				min = v
			}
		}

	}

	return min, NoError

}

func (c *Collections) Peaks(m map[int]string) ([]string, GetRealGoodUtilsErrors) {

	if m == nil {
		return nil, NilError
	}

	if len(m) == 0 {
		return nil, EmptyError
	}

	var max string

	var peaks []string

	var j int = 0

	for _, v := range m {

		if j == 0 {
			max = v
			peaks = append(peaks, max)
			j++
			continue
		} else {
			if len(v) > len(max) {
				peaks = peaks[:0]
				max = v
				peaks = append(peaks, max)
			} else if len(v) == len(max) {
				peaks = append(peaks, max)
			} else {
				continue
			}
		}

	}

	return peaks, NoError

}

func (c *Collections) Troughs(m map[int]string) ([]string, GetRealGoodUtilsErrors) {

	if m == nil {
		return nil, NilError
	}

	if len(m) == 0 {
		return nil, EmptyError
	}

	var min string

	var troughs []string

	var j int = 0

	for _, v := range m {

		if j == 0 {
			min = v
			troughs = append(troughs, min)
			j++
			continue
		} else {
			if len(v) < len(min) {
				troughs = troughs[:0]
				min = v
				troughs = append(troughs, min)
			} else if len(v) == len(min) {
				troughs = append(troughs, min)
			} else {
				continue
			}
		}

	}

	return troughs, NoError

}
