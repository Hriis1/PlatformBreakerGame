/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	_soundPad(L"Sounds\\arkpad.wav"), _soundBrick(L"Sounds\\arkbrick.wav"),
	_walls(0, float(Graphics::ScreenWidth), 0, float(Graphics::ScreenHeight)), _ball(Vec2(200.0f, 350.0f), Vec2(150.0f, 150.0f)),
	 _paddle(Vec2(400.0f, 500.0f), 65.0f, 7.0f)
{
	const Color colors[_nBricksVertically] = { Colors::White, Colors::Green, Colors::Red };
	const Vec2 topLeft(0.0f, 50.0f);

	int i = 0;
	for (size_t y = 0; y < _nBricksVertically; y++)
	{
		const Color c = colors[y];
		for (size_t x = 0; x < _nBricksHorizontally; x++)
		{
			_bricks[i++] = Brick(RectF(topLeft + Vec2(x * _brickWidth, y * _brickHeight), _brickWidth, _brickHeight), c);
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	float deltaTime = _ft.Mark();
	_paddle.update(wnd.kbd, deltaTime);
	_paddle.doWallCollision(_walls);

	_ball.update(deltaTime);
	if (_ball.collideWithWalls(_walls) || _paddle.doBallCollision(_ball))
	{
		_soundPad.Play();
	}
	for (size_t i = 0; i < _nBricks; i++)
	{
		if (_bricks[i].doBallCollision(_ball))
		{
			_soundBrick.Play();
			break;
		}
	}
	
}

void Game::ComposeFrame()
{
	_ball.draw(gfx);
	for (size_t i = 0; i < _nBricks; i++)
	{
		_bricks[i].Draw(gfx);
	}

	_paddle.draw(gfx);
}
