#pragma once

#include <vector>
#include <cstdint>


// функция смещает все числа == 0 в конец массива, а все числа != 0 в начало
// и не изменяет их порядок
void myCopyIf(std::vector<uint32_t> &v);
