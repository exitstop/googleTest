#include <vector>
#include "my_copyif.h"

#define DBG(v) copy(v.begin(), v.end(), ostream_iterator<typeof(*v.begin())>(cout, " "))

int main()
{
    std::vector<uint32_t> v0{0,1,0,2,0,6,9,0,4,5,4,6,6,0};
    std::vector<uint32_t> v1{0,5,0,6,9,0,4,5,4,6,6,0};
    std::vector<uint32_t> v2{0,4,0,2,0,67,0,4,8,0};

    // функция смещает все числа == 0 в конец массива, а все числа != 0 в начало
    // и не изменяет их порядок
    myCopyIf(v0);
    myCopyIf(v1);
    myCopyIf(v2);
    return 0;
}
