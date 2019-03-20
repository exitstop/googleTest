#include "gtest/gtest.h"

#include <iostream>
#include "my_copyif.h"

uint32_t gen()
{
    return std::rand() % 255;
}

TEST(main, test0)
{
    using namespace std;
    {
        // Проверка корректности выполения
        std::vector<uint32_t> v0{0,1,0,2,0,6,9,0,4,5,4,6,6,0};

        size_t sumStart = std::accumulate(v0.begin(), v0.end(), 1, [](int x, int y){ return x + y;} );
        myCopyIf(v0);
        size_t sumEnd = std::accumulate(v0.begin(), v0.end(), 1, [](int x, int y){ return x + y;} );

        ASSERT_TRUE(sumStart == sumEnd);
    }

    // Сгенерим рандомные данные
    for(size_t i = 0; i < 10; i ++) {
        const uint32_t sizeVector = 18;
        std::vector<uint32_t> v0(sizeVector);
        std::generate(v0.begin(), v0.end(), gen ); 
        for(uint32_t y = 0; y < std::rand() % sizeVector; y++) {
            v0[std::rand() % (sizeVector -1) ] = 0;
        }

        size_t sumStart = std::accumulate(v0.begin(), v0.end(), 1, [](int x, int y){ return x + y;} );
        myCopyIf(v0);
        size_t sumEnd = std::accumulate(v0.begin(), v0.end(), 1, [](int x, int y){ return x + y;} );

        ASSERT_TRUE(sumStart == sumEnd);
    }
}
