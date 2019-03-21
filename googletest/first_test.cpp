#include "gtest/gtest.h"

#include <iostream>
#include "my_copyif.h"

#define DBG(v) copy(v.begin(), v.end(), ostream_iterator<typeof(*v.begin())>(cout, " "))

uint32_t gen()
{
    return std::rand() % 255;
}

TEST(main, test0)
{
    using namespace std;
    {
        // Проверка корректности выполнения 
        vector<uint32_t> v0{0,1,0,2,0,6,9,0,4,5,4,6,6,0};

        size_t sumStart = accumulate(v0.begin(), v0.end(), 1, [](int x, int y){ return x + y;} );
        myCopyIf(v0);
        size_t sumEnd = accumulate(v0.begin(), v0.end(), 1, [](int x, int y){ return x + y;} );

        ASSERT_TRUE(sumStart == sumEnd);
    }

    // Сгенерим рандомные данные
    for(size_t i = 0; i < 10; i ++) {
        const uint32_t sizeVector = 18;
        vector<uint32_t> v0(sizeVector);
        generate(v0.begin(), v0.end(), gen ); 
        for(uint32_t y = 0; y < rand() % sizeVector; y++) {
            v0[rand() % (sizeVector - 1) ] = 0;
        }

        DBG(v0);
        cout << endl;
        size_t sumStart = accumulate(v0.begin(), v0.end(), 1, [](int x, int y){ return x + y;} );
        myCopyIf(v0);
        size_t sumEnd = accumulate(v0.begin(), v0.end(), 1, [](int x, int y){ return x + y;} );

        ASSERT_TRUE(sumStart == sumEnd);
    }
}
