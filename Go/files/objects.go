package getrealgoodutils

type Objects struct {
}

func (o *Objects) IsNil(object interface{}) bool {
	return object == nil

}

func (o *Objects) IsNotNil(object interface{}) bool {
	return object != nil

}
