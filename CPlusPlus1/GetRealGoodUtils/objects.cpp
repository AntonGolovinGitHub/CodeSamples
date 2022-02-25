#include "pch.h"

#include "objects.h"

using getrealgoodutils::objects;

bool objects::is_null(void* o) {
    return o == nullptr;
}


bool objects::is_not_null(void* o) {
    return o != nullptr;
}