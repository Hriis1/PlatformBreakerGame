#pragma once
#include "Graphics.h"
#include "Colors.h"
#include "RectF.h"
#include "Ball.h"


class Brick
{
public:
	Brick() = default;
	Brick(const RectF& rect, Color col);

	void Draw(Graphics& gfx) const;

	bool doBallCollision(Ball& ball);
private:
	RectF _rect;
	Color _col;
	bool _isDestroyed = false;

};

