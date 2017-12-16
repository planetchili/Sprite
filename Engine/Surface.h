#pragma once

#include "Colors.h"
#include <string>
#include "Rect.h"

class Surface
{
public:
	Surface( const std::string& filename );
	Surface( int width,int height );
	Surface( const Surface& );
	Surface( Surface&& );
	Surface() = default;
	~Surface();
	Surface& operator=( const Surface& );
	Surface& operator=( Surface&& );
	void PutPixel( int x,int y,Color c );
	Color GetPixel( int x,int y ) const;
	int GetWidth() const;
	int GetHeight() const;
	RectI GetRect() const;
private:
	Color* pPixels = nullptr;
	int width = 0;
	int height = 0;
};