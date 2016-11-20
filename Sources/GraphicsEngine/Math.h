#pragma once


class Math
{
public:

	/**
	* @brief Clamps value by interval [min, max].
	*/
	static float Clamp(float value, float min, float max)
	{
		value = (value < min) ? min : value;
		value = (value > max) ? max : value;

		return value;
	}

	/**
	* @brief Clamps value by interval [min, max].
	*/
	static double Clamp(double value, double min, double max)
	{
		value = (value < min) ? min : value;
		value = (value > max) ? max : value;

		return value;
	}
};
