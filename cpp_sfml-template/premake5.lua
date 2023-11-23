project "cpp_sfml-template"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++20"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.h", "src/**.hpp" , "src/**.cpp" }

   includedirs
   {
    "../%{IncludeDir.glm}",
    "../%{IncludeDir.spd_log}",
    "../%{IncludeDir.sfml}"
   }
   defines {"SFML_STATIC"}
 
   libdirs { "../vendor/SFML/SFML-2.6.0/lib" }
	links
	{
		"opengl32",
		"freetype",
		"winmm",
		"gdi32",
		"flac",
		"vorbisenc",
		"vorbisfile",
		"vorbis",
		"ogg",
		"ws2_32"
    }

   targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
   objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

   filter "system:windows"
      systemversion "latest"
      defines { "PLATFORM_WINDOWS" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      links
      {	
          "sfml-graphics-s-d",
          "sfml-window-s-d",
          "sfml-system-s-d",
          "sfml-audio-s-d",
          "sfml-network-s-d"
      }
      runtime "Debug"
      symbols "On"

   filter "configurations:Release"
      defines { "RELEASE" }
      links
      {	
          "sfml-graphics-s",
          "sfml-window-s",
          "sfml-system-s",
          "sfml-audio-s",
          "sfml-network-s"
      }
      runtime "Release"
      optimize "On"
      symbols "On"

   filter "configurations:Dist"
      kind "WindowedApp"
      defines { "DIST" }
      links
      {	
          "sfml-graphics-s",
          "sfml-window-s",
          "sfml-system-s",
          "sfml-audio-s",
          "sfml-network-s"
      }
      runtime "Release"
      optimize "On"
      symbols "Off"