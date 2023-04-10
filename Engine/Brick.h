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

	bool checkBallCollision(const Ball& ball) const;
	void executeBallCollision(Ball& ball);

	Vec2 getCenter() const { return _rect.getCenter(); }
private:
	static constexpr float _padding = 2.0f;

	RectF _rect;
	Color _col;
	bool _isDestroyed = false;

};

