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

private:
	static constexpr float radius = 7.0f;
	Vec2 _pos;
	Vec2 _vel;
	
};

