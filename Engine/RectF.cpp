#include "RectF.h"

RectF::RectF(float left_, float right_, float top_, float bot_)
	: left(left_), right(right_), top(top_), bot(bot_)
{
}

RectF::RectF(const Vec2& topLeft, const Vec2& botRight)
	: RectF(topLeft.x, botRight.x, topLeft.y, botRight.y)
{
}

RectF::RectF(const Vec2& topLeft, float width, float height)
	: RectF(topLeft.x, topLeft.x + width, topLeft.y, topLeft.y + height)
{
}

bool RectF::isOverlappingWith(const RectF& other) const
{
	return right >= other.left && left <= other.right && bot >=other.top && top <= other.bot;
}

RectF RectF::fromCenter(const Vec2& center, float halfWidth, float halfHeight)
{
	const Vec2 half(halfWidth, halfHeight);
	return RectF(center - half, center + half);
}
