#include "Paddle.h"

Paddle::Paddle(const Vec2& pos, float halfWidth, float halfHeight)
	: _pos(pos), _halfWidth(halfWidth), _halfHeight(halfHeight)
{
}

void Paddle::update(const Keyboard& kbd, float deltaTime)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		_pos.x -= _speed * deltaTime;
	}
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		_pos.x += _speed * deltaTime;
	}
}

void Paddle::draw(Graphics& gfx) const
{
	RectF rect = getRect();
	gfx.DrawRect(rect, _wingColor);
	rect.left += _wingWidth;
	rect.right -= _wingWidth;
	gfx.DrawRect(rect, _color);
}

void Paddle::doWallCollision(const RectF& walls)
{
	const RectF rect = getRect();
	if (rect.left <= walls.left)
	{
		_pos.x = walls.left + _halfWidth;
	}
	else if (rect.right >= walls.right)
	{
		_pos.x = walls.right - _halfWidth;
	}
}

bool Paddle::doBallCollision(Ball& ball) const
{
	if (ball.getVelocity().y >= 0.0f) {
		if (getRect().isOverlappingWith(ball.getRect()))
		{
			ball.ReboundY();
			return true;
		}
	}
	return false;	
}


