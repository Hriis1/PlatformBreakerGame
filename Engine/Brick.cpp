#include "Brick.h"

#include <assert.h>
#include <cmath>

Brick::Brick(const RectF& rect, Color col)
	: _rect(rect), _col(col)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if(!_isDestroyed)
		gfx.DrawRect(_rect.getExpanded(-_padding), _col);
}

bool Brick::checkBallCollision(const Ball& ball) const
{
	return !_isDestroyed && _rect.isOverlappingWith(ball.getRect());
}

void Brick::executeBallCollision(Ball& ball)
{
	assert(checkBallCollision(ball));

	const Vec2 ballPos = ball.getPosition();
	
	//the ball is coming from inside of the brick
	if (std::signbit(ball.getVelocity().x) == std::signbit(ballPos.x - getCenter().x))
	{
		ball.ReboundY();
	}
	else //the ball is coming from outside the brick
	{
		if (ballPos.x >= _rect.left && ballPos.x <= _rect.right)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}
	}
	
	_isDestroyed = true;
}
