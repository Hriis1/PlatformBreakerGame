#pragma once
#include <random>

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
	void changeXVelocityOnPaddleHit();

	//getters
	const Vec2& getPosition() const { return _pos; }
	const Vec2& getVelocity() const { return _vel; }
	RectF getRect() const { return RectF::fromCenter(_pos, radius, radius); }

private:
	static constexpr float radius = 7.0f;
	static constexpr float _veloctyChangeRange = 300.0f;
	static constexpr float _minXVel = 150.0f;
	static constexpr float _maxXVel = 600.0f;

	Vec2 _pos;
	Vec2 _vel;
	
	std::mt19937 _velRng;
	std::uniform_real_distribution<float> _xVelDist;
};

