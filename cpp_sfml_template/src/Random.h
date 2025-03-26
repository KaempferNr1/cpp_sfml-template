﻿#pragma once
#include <random>

#include <glm/glm.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

class Random
{
public:
	static void init()
	{
		s_random_engine.seed(std::random_device()());
	}

	[[nodiscard]] static uint32_t uint()
	{
		return s_distribution(s_random_engine);
	}

	[[nodiscard]] static uint32_t uint(const uint32_t min, const uint32_t max)
	{
		return min + (s_distribution(s_random_engine) % (max - min + 1));
	}

	[[nodiscard]] static float floating()
	{
		return static_cast<float>(s_distribution(s_random_engine)) / static_cast<float>(std::numeric_limits<uint32_t>::max());
	}

	[[nodiscard]] static float floating(const float min, const float max)
	{
		return floating() * (max - min) + min;
	}

	[[nodiscard]] static sf::Vector2f vec2()
	{
		return { floating(), floating() };
	}

	[[nodiscard]] static sf::Vector2f vec2(const float min, const float max)
	{
		return { floating(min,max),floating(min,max) };
	}

	[[nodiscard]] static sf::Vector2f vec2_in_unit_sphere()
	{
		return vec2(-1.0f, 1.0f).normalized();
	}

	[[nodiscard]] static glm::vec3 vec3()
	{
		return { floating(), floating(), floating() };
	}

	[[nodiscard]] static glm::vec3 vec3(const float min, const float max)
	{
		return { floating(min,max), floating(min,max), floating(min,max) };
	}

	[[nodiscard]] static glm::vec3 vec3_in_unit_sphere()
	{
		return glm::normalize(vec3(-1.0f, 1.0f));
	}

private:
	thread_local static std::mt19937 s_random_engine;

	thread_local static std::uniform_int_distribution<std::mt19937::result_type> s_distribution;
};



