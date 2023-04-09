#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& pos, const Vec2& vel)
	: _pos(pos), _vel(vel)
{
}

void Ball::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(_pos, gfx);
}
