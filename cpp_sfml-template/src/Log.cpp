#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Blank
{

	std::shared_ptr<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] [thread %t] %n: %v%$");
		s_Logger = spdlog::stdout_color_mt("st9");
		s_Logger->set_level(spdlog::level::trace);
	}

}