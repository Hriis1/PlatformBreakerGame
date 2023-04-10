#include "Brick.h"

#include <assert.h>

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
	if (ballPos.x >= _rect.left && ballPos.x <= _rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	_isDestroyed = true;
}
