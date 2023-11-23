#pragma once
#include <memory>
#include "Log.h"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Blank
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}
#ifdef BL_DIST
#define LOG_TRACE(...)      
#define LOG_INFO(...)       
#define LOG_WARN(...)       
#define LOG_ERROR(...)      
#define LOG_CRITICAL(...)   
#else
#define LOG_TRACE(...)         ::Blank::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)          ::Blank::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::Blank::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::Blank::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::Blank::Log::GetLogger()->critical(__VA_ARGS__)
#endif

