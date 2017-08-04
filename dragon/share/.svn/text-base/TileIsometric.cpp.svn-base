/*
 * =====================================================================================
 *
 *       Filename:  TileIsometric.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/14/2014 03:32:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include "TileIsometric.h"

bool fncomp (TilePos lhs, TilePos rhs) {return lhs.x < rhs.x || lhs.y < rhs.y;}
/*
 *--------------------------------------------------------------------------------------
 *       Class:  CTileIsometric
 *      Method:  CTileIsometric
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
CTileIsometric::CTileIsometric ():m_setData(fncomp)
{
}  /* -----  end of method CTileIsometric::CTileIsometric  (constructor)  ----- */

bool
CTileIsometric::Init (const std::vector<TilePos> &vec)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		TilePos a = {vec[i].x, vec[i].y};
		m_setData.insert(a);
	}
	return true;
}		/* -----  end of method CTileIsometric::Init  ----- */

void
CTileIsometric::AddTile (const TilePos &tile)
{
	m_setData.insert(tile);
	return ;
}		/* -----  end of method CTileIsometric::AddTile  ----- */

void
CTileIsometric::AddTileByObj (const TilePos &tile, const int &weight, const int &height)
{
	int hposw = tile.x;
	int hposh = tile.y;
	int posw = tile.x;
	int posh = tile.y;
	for (int i = 0; i < height; i++) // from height 0 begin; one line by one line
	{
		posw = hposw;
		posh = hposh;
		for (int j = 0; j < weight ; j++) // from weight 0 to max; one line
		{
			TilePos t = {posw, posh};
			m_setData.insert(t);
			if (posh % 2 == 1 && (posh + 1) % 2 == 0)
			{
				posw += 1;
			}
			posh += 1;
		}

		if (hposh % 2 == 0 && (hposh + 1) % 2 == 1)
		{
			hposw -= 1;
		}
		hposh += 1;
	}

	return ;
}		/* -----  end of method CTileIsometric::AddTileByObj  ----- */


bool
CTileIsometric::IsHaveTile (const TilePos &tile)
{
	return m_setData.find(tile) != m_setData.end();
}		/* -----  end of method CTileIsometric::IsHaveTile  ----- */


bool
CTileIsometric::IsHaveTileByObj (const TilePos &tile, const int &weight, const int &height)
{
	int hposw = tile.x;
	int hposh = tile.y;
	int posw = tile.x;
	int posh = tile.y;
	for (int i = 0; i < height; i++) // from height 0 begin; one line by one line
	{
		posw = hposw;
		posh = hposh;
		for (int j = 0; j < weight ; j++) // from weight 0 to max; one line
		{
			TilePos t = {posw, posh};
			if (m_setData.find(t) != m_setData.end())
				return true;
			if (posh % 2 == 1 && (posh + 1) % 2 == 0)
			{
				posw += 1;
			}
			posh += 1;
		}

		if (hposh % 2 == 0 && (hposh + 1) % 2 == 1)
		{
			hposw -= 1;
		}
		hposh += 1;
	}
	return false;
}		/* -----  end of method CTileIsometric::IsHaveTileByObj  ----- */


bool
CTileIsometric::IsHaveTileInRectArea (const TilePos &tile, const TilePos &initpos, const int &weight, const int &height)
{
	return (tile.x >= initpos.x && tile.x <= initpos.x + weight) && (tile.y >= initpos.y && tile.y <= initpos.y + height);
}		/* -----  end of method CTileIsometric::IsHaveTileInRectArea  ----- */

