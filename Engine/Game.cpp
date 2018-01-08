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
#include <random>
#include "SpriteEffect.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	std::mt19937 rng( 69 );
	std::uniform_int_distribution<int> xd( 0,Graphics::ScreenWidth - s.GetWidth() - 1 );
	std::uniform_int_distribution<int> yd( 0,Graphics::ScreenHeight - s.GetHeight() - 1 );

	for( int i = 0; i < 50; i++ )
	{
		positions.push_back( { xd( rng ),yd( rng ) } );
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
}

void Game::ComposeFrame()
{
	bencher.Start();

	for( const auto& pos : positions )
	{
		gfx.DrawSprite( pos.x,pos.y,s,SpriteEffect::Copy{} );
	}

	if( bencher.End() )
	{
		OutputDebugString( (std::wstring( bencher ) + L"\n").c_str() );
	}
}
