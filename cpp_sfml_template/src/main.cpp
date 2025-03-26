#include <chrono>
#include <SFML/Graphics.hpp>

#include "imgui-SFML.h"
#include "imgui.h"
#include "Random.h"
#include "Log.h"

int Main(int argc, char** argv);

static [[nodiscard]] bool init_sfml_imgui(sf::RenderWindow& window);

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
    Log::init(LOG_LEVEL_INFO);
    Random::init();

    sf::RenderWindow window(sf::VideoMode({720, 480}), "window", sf::Style::Close);

    if (!init_sfml_imgui(window))
    {
        LOG_ERROR("failed to initialize imgui");
    }

    window.setFramerateLimit(60);
    sf::Clock delta_clock;

    while (window.isOpen())
    {
        while (const auto& event = window.pollEvent())
        {
            ImGui::SFML::ProcessEvent(window, *event);
            if(event->is<sf::Event::Closed>())
            {
	            window.close();
            }

        }
        ImGui::SFML::Update(window, delta_clock.restart());

        ImGui::Begin("hello world");
        ImGui::Text("hello world");
        ImGui::End();

        window.clear();


        ImGui::SFML::Render(window);
    	window.display();
    }
    return 0;
}


#include "../Resources/Images/Roboto-Regular.embed"
bool init_sfml_imgui(sf::RenderWindow& window)
{

    if (!ImGui::SFML::Init(window, false))
        return false;

    ImGui::SFML::ProcessEvent(window, sf::Event::FocusLost());
    ImGui::SFML::ProcessEvent(window, sf::Event::FocusGained());

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows // funktioniert nicht weil die sfml backends das nicht haben

    ImFontConfig font_config;
    font_config.FontDataOwnedByAtlas = false;
    ImFont* roboto_font = io.Fonts->AddFontFromMemoryTTF(const_cast<uint8_t*>(g_RobotoRegular), sizeof g_RobotoRegular, 20.0f, &font_config);
    io.FontDefault = roboto_font;
    if (!ImGui::SFML::UpdateFontTexture())
    {
        LOG_ERROR("failed to update font");
    }
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }
    return true;
}
