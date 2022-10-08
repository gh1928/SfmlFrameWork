#include <SFML/Graphics.hpp>
#include "Framework/Framework.h"
#include "Framework/Constants.h"

int main()
{
    Framework framework(WIN_WIDTH, WIN_WIDTH);
    framework.Init();
    framework.Do();
    return 0;
}