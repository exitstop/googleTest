#pragma once

#include <vector>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <algorithm>
#include <cassert>
#include <cstdint>


// функция смещает все числа == 0 в конец массива, а все числа != 0 в начало
// и не изменяет их порядок
void myCopyIf(std::vector<uint32_t> &v);
