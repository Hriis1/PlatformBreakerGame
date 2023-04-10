#pragma once
#include "Vec2.h"
class RectF
{
public:
	RectF() = default;
	RectF(float left_, float right_, float top_, float bot_);
	RectF(const Vec2& topLeft, const Vec2& botRight);
	RectF(const Vec2& topLeft, float width, float height);

	bool isOverlappingWith(const RectF& other) const;

	static RectF fromCenter(const Vec2& center, float halfWidth, float halfHeight);
	RectF getExpanded(float offset) const;
public:
	float left = 0.0f;
	float right = 0.0f;
	float top = 0.0f;
	float bot = 0.0f;
};

