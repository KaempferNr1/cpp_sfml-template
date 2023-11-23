#include <chrono>
#include <SFML/Graphics.hpp>
#include "Random.h"
#include "Log.h"

int Main(int argc, char** argv);


#if (defined(PLATFORM_WINDOWS) || defined (_WIN64)) && defined(DIST)

#include <windows.h>
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
    return Main(argc, argv);
}

#endif

int Main(int argc, char** argv)
{
    Blank::Log::Init();
    Blank::Random::Init();
    std::vector<uint32_t> arr;
    arr.reserve(10);
    for (int i = 0; i < 10; i++)
        arr.push_back(Blank::Random::UInt());
    for (int i = 0; i < 10; i++)
	    LOG_INFO("arr[{}]: {}", i, arr[i]);
    uint32_t max = 0;
		for (uint32_t i = 0; i < arr.size(); i++) if (max < arr[i]) max = arr[i];
    LOG_INFO("max: {}", max);
    int8_t s = 65;
    LOG_INFO("{0} {0}", s);
    sf::Event event{};
    LOG_INFO("Hallo welt");
    sf::RenderWindow window(sf::VideoMode(720, 480), "window", sf::Style::Close);

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        window.clear();
        window.display();
    }
    return 0;
}