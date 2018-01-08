#include "Graphics.h"

void Graphics::BeginFrame()
{
	// clear the sysbuffer
	sysBuffer.Fill( Colors::Black );
}

void Graphics::PutPixel( int x,int y,Color c )
{
	sysBuffer.PutPixel( x,y,c );
}

Color Graphics::GetPixel( int x,int y ) const
{
	return sysBuffer.GetPixel( x,y );
}