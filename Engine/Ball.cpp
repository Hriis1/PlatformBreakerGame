#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(const Vec2& pos, const Vec2& vel)
	: _pos(pos), _vel(vel), _velRng(std::random_device()()), _xVelDist(-_veloctyChangeRange, _veloctyChangeRange)
{
}

void Ball::draw(Graphics& gfx) const
{
	SpriteCodex::DrawBall(_pos, gfx);
}

void Ball::update(float deltaTime)
{
	_pos += _vel * deltaTime;
}

bool Ball::collideWithWalls(const RectF& walls)
{
	bool collided = false;
	const RectF rect = getRect();
	if (rect.left <= walls.left)
	{
		_pos.x = walls.left + radius;
		ReboundX();
		collided = true;
	}
	else if (rect.right >= walls.right)
	{
		_pos.x = walls.right - radius;
		ReboundX();
		collided = true;
	}

	if (rect.top <= walls.top)
	{
		_pos.y = walls.top + radius;
		ReboundY();
		collided = true;
	}
	else if (rect.bot >= walls.bot)
	{
		_pos.y = walls.bot - radius;
		ReboundY();
		collided = true;
	}

	return collided;
}

void Ball::ReboundX()
{
	_vel.x = -_vel.x;
}

void Ball::ReboundY()
{
	_vel.y = -_vel.y;
}

void Ball::changeXVelocityOnPaddleHit()
{
	float xVelChange = _xVelDist(_velRng);
	_vel.x += xVelChange;

	if (_vel.x > _maxXVel)
		_vel.x = _maxXVel;
	else if (_vel.x < _minXVel)
		_vel.x = _minXVel;
}
