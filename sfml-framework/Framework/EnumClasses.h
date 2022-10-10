#pragma once

enum class Axis
{
	Horizontal,
	Vertical,
};

enum class ResourceTypes
{
	Texture,
	Font,
	SoundBuffer,
};

enum class Origins
{
	TL,	// 0
	TC,
	TR,
	ML,
	MC,
	MR,
	BL,
	BC,
	BR,	// 8
};

enum class Collision
{
	TL,	// 0
	TR,
	BL,
	BR,	// 3
};

enum class Scenes
{
	Dev1,
	Dev2,
	PongTitle,
	PongGame,
};
