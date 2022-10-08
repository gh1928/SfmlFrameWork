#include <SFML/Graphics.hpp>
#include "Framework/Framework.h"
#include "Framework/Constants.h"

int main()
{
    Framework framework(WIN_WIDTH, WIN_HEIGHT);
    framework.Init();
    framework.Do();
    return 0;
}