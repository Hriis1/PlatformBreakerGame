#include "Paddle.h"
#include <cmath>

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

bool Paddle::doBallCollision(Ball& ball)
{
	if (!_collisionCooldown)
	{
		const RectF paddleRect = getRect();
		if (paddleRect.isOverlappingWith(ball.getRect()))
		{
			const Vec2 ballPos = ball.getPosition();

			//the ball is coming from inside of the brick
			if (std::signbit(ball.getVelocity().x) == std::signbit(ballPos.x - _pos.x))
			{
				ball.ReboundY();
			}
			else //the ball is coming from outside the brick
			{
				if (ballPos.x >= paddleRect.left && ballPos.x <= paddleRect.right)
				{
					ball.ReboundY();
				}
				else
				{
					ball.ReboundX();
				}
			}
			_collisionCooldown = true;
			return true;
		}
	}
	return false;	
}


