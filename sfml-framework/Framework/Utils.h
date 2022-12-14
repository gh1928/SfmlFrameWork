#pragma once
#include <random>
#include <SFML/Graphics.hpp>
#include "EnumClasses.h"
#include "Constants.h"

using namespace sf;
using namespace std;



class Utils
{
private:
	static random_device rd;
	static mt19937 gen;

public:
	static void SetOrigin(Text& obj, Origins origin);
	static void SetOrigin(Sprite& obj, Origins origin);
	static void SetOrigin(Shape& obj, Origins origin);
	static void SetOrigin(Transformable& obj, Origins origin, FloatRect rect);
	


	static int RandomRange(int min, int maxExclude);
	static float RandomRange(float min, float max);

	static float SqrMagnitude(const Vector2f& vec);
	static float Magnitude(const Vector2f& vec);

	static Vector2f VectorRotation(Vector2f original, float degree);
	static Vector2f Normalize(const Vector2f& vec);

};

