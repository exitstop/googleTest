#include "my_copyif.h"

#define DBG(v) copy(v.begin(), v.end(), ostream_iterator<typeof(*v.begin())>(cout, " "))

bool myCopyIf(std::vector<uint32_t> &v)
{
    using namespace std;
    size_t sumStart = std::accumulate(v.begin(), v.end(), 1, [](int x, int y){ return x + y;} );

    uint32_t count = 0;
    std::copy_if(v.begin(), v.end(), v.begin(), [&count](uint32_t i)
                {
                    if( i != 0 ) 
                    {
                        count++;
                        return true;
                    }
                    return false;
                }
            );
    std::fill(v.begin() + count, v.end(), 0);
    size_t sumEnd = std::accumulate(v.begin(), v.end(), 1, [](int x, int y){ return x + y;} );
    DBG(v); 
    cout << endl;
}
