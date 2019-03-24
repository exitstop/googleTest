#include "my_copyif.hpp"

#include <iostream>
#include <iterator>
#include <algorithm>
#include <typeinfo>

#define DBG(v) copy((v).begin(), (v).end(), ostream_iterator<decltype(*(v).begin())>(cout, " "))

// функция смещает все числа == 0 в конец массива, а все числа != 0 в начало    
// и не изменяет их порядок
void myCopyIf(std::vector<uint32_t> &v)
{
    using namespace std;

    uint32_t count = 0;
    copy_if(v.begin(), v.end(), v.begin(), [&count](uint32_t i)
                {
                    if( i != 0 ) {
                        count++;
                        return true;
                    }
                    return false;
                }
            );
    fill(v.begin() + count, v.end(), 0);
    DBG(v); 
    cout << endl;
}
