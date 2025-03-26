#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


class Log
{
public:
	static void init(const spdlog::level::level_enum level)
	{
		spdlog::set_pattern("%^[%T] [thread %t] %n: %v%$");
		s_logger = spdlog::stdout_color_mt("st2");
		s_logger->set_level(level);
		s_logger = spdlog::stdout_color_mt("client");
	}

	[[nodiscard]] static std::shared_ptr<spdlog::logger>& get_logger() { return s_logger; }
private:
	inline static std::shared_ptr<spdlog::logger> s_logger;
};

#define LOG_LEVEL_TRACE spdlog::level::trace
#define LOG_LEVEL_DEBUG spdlog::level::debug
#define LOG_LEVEL_INFO spdlog::level::info
#define LOG_LEVEL_WARN spdlog::level::warn
#define LOG_LEVEL_ERROR spdlog::level::err
#define LOG_LEVEL_CRITICAL spdlog::level::critical
#define LOG_LEVEL_OFF spdlog::level::off

#ifdef DIST
#define LOG_TRACE(...)      
#define LOG_DEBUG(...)      
#define LOG_INFO(...)       
#define LOG_WARN(...)       
#define LOG_ERROR(...)      
#define LOG_CRITICAL(...)
#define GET_LOG_LEVEL() (LOG_LEVEL_OFF)
#define SET_LOG_LEVEL(...)
#else
#define LOG_TRACE(...)         ::Log::get_logger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...)         ::Log::get_logger()->debug(__VA_ARGS__)
#define LOG_INFO(...)          ::Log::get_logger()->info(__VA_ARGS__)
#define LOG_WARN(...)          ::Log::get_logger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)         ::Log::get_logger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)      ::Log::get_logger()->critical(__VA_ARGS__)
#define GET_LOG_LEVEL()		   ::Log::get_logger()->level()
#define SET_LOG_LEVEL(...)	   ::Log::get_logger()->set_level(__VA_ARGS__)
#endif
