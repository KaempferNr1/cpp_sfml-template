-- premake5.lua
workspace "cpp_sfml-template"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "cpp_sfml-template"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glm"] = "vendor/glm"
IncludeDir["spd_log"] = "vendor/spdlog/include"
IncludeDir["sfml"] = "vendor/SFML/SFML-2.6.0/include"

include "cpp_sfml-template"