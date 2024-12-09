-- premake5.lua
workspace "cpp_sfml_template"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "cpp_sfml_template"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glm"] = "vendor/glm"
IncludeDir["spd_log"] = "vendor/spdlog/include"
IncludeDir["SFML"] = "vendor/SFML/SFML-2.6.2/include"
IncludeDir["ImGui"] = "vendor/imgui"




group "Dependencies"
	include "Vendor/imgui"
group ""

include "cpp_sfml_template"

