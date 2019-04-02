#include "my_copyif.hpp"
#include "yandex_tasks/ya0.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>

#define DBG(v) copy((v).begin(), (v).end(), std::ostream_iterator<typeof(*(v).begin())>(cout, " ")); cout << endl;

using std::cout;
using std::endl;

int main()
{
    cout << "[  myCopyIf ]" << endl;
    std::vector<uint32_t> v0{0,1,0,2,0,6,9,0,4,5,4,6,6,0};
    std::vector<uint32_t> v1{0,5,0,6,9,0,4,5,4,6,6,0};
    std::vector<uint32_t> v2{0,4,0,2,0,67,0,4,8,0};

    // функция смещает все числа == 0 в конец массива, а все числа != 0 в начало
    // и не изменяет их порядок
    myCopyIf(v0);
    myCopyIf(v1);
    myCopyIf(v2);

    // аналогичный алгоритм реализован в std::stable_partition();
    std::stable_partition(v0.begin(), v0.end(), [](int n) {return n>0;} );
    std::stable_partition(v1.begin(), v1.end(), [](int n) {return n>0;} );
    std::stable_partition(v2.begin(), v2.end(), [](int n) {return n>0;} );

    cout << "std::stable_partition: " << endl; 
    DBG(v0); 
    DBG(v1); 
    DBG(v2); 

    /* ****************************************************
    **************** yandex tasks *************************
    *******************************************************/
    cout << "[  fucn0 ]" << endl;
    func0();
    cout << "[  fucn1 ]" << endl;
    func1();
    return 0;
}
