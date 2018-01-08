#pragma once

#include "Colors.h"
#include <string>
#include <vector>
#include "Rect.h"

class Surface
{
public:
	Surface( const std::string& filename );
	Surface( int width,int height );
	Surface( Surface&& donor );
	Surface( const Surface& ) = default;
	Surface& operator=( Surface&& rhs );
	Surface& operator=( const Surface& ) = default;
	Surface() = default;
	void PutPixel( int x,int y,Color c );
	Color GetPixel( int x,int y ) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
	void Fill( Color c );
	const Color* Data() const;
private:
	std::vector<Color> pixels;
	int width = 0;
	int height = 0;
};