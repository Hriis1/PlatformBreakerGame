#pragma once
#include "Graphics.h"
#include "Vec2.h"
#include "RectF.h"
class Ball
{
public:
	Ball(const Vec2& pos, const Vec2& vel);

	void draw(Graphics& gfx) const;
	void update(float deltaTime);

	bool collideWithWalls(const RectF& walls);
	void ReboundX();
	void ReboundY();

	//getters
	const Vec2& getPosition() const { return _pos; }
	const Vec2& getVelocity() const { return _vel; }
	RectF getRect() const { return RectF::fromCenter(_pos, radius, radius); }

private:
	static constexpr float radius = 7.0f;
	Vec2 _pos;
	Vec2 _vel;
	
};

