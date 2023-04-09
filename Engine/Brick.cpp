#include "Brick.h"

Brick::Brick(const RectF& rect, Color col)
	: _rect(rect), _col(col)
{
}

void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(_rect, _col);
}
