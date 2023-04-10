#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Colors.h"
#include "Vec2.h"
#include "RectF.h"
#include "Ball.h"


class Paddle
{
public:
	Paddle(const Vec2& pos, float halfWidth, float halfHeight);

	void update(const Keyboard& kbd, float deltaTime);
	void draw(Graphics& gfx) const;

	void doWallCollision(const RectF& walls);
	bool doBallCollision(Ball& ball) const;
	
	//getters
	RectF getRect() const { return RectF::fromCenter(_pos, _halfWidth, _halfHeight); }
private:
	Color _color = Colors::White;
	float _halfWidth = 0.0f;
	float _halfHeight = 0.0f;
	float _speed = 300.0f;
	Vec2 _pos;
};

