#include "IpAddress.h"

int main(int, char **) {

    PrintIp("192.168.0.1");
    PrintIp((short) 192);
    PrintIp((int) 19216801);
    PrintIp((long) 19216802);

    return 0;
}

