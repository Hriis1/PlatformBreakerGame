#include "Brick.h"

Brick::Brick(const RectF& rect, Color col)
	: _rect(rect), _col(col)
{
}

void Brick::Draw(Graphics& gfx) const
{
	if(!_isDestroyed)
		gfx.DrawRect(_rect, _col);
}

bool Brick::doBallCollision(Ball& ball)
{
	if (!_isDestroyed && _rect.isOverlappingWith(ball.getRect()))
	{
		ball.ReboundY();
		_isDestroyed = true;
		return true;
	}
	return false;
}
