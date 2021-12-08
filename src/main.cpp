#include "IpAddress.h"

int main(int, char **) {

    PrintIp(static_cast<char>(-1));
    PrintIp(static_cast<short>(0));
    PrintIp(static_cast<int>(2130706433));
    PrintIp(static_cast<long>(8875824491850138409));

    PrintIp("192.168.0.1");
    PrintIp(std::vector<int>({192, 168, 0, 1}));

    return 0;
}
