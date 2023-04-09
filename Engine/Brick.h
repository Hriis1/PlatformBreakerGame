#pragma once
#include "Graphics.h"
#include "RectF.h"
#include "Colors.h"

class Brick
{
public:
	Brick(const RectF& rect, Color col);

	void Draw(Graphics& gfx) const;
private:
	RectF _rect;
	Color _col;
	bool _isDestroyed = false;

};

