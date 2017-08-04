/*
 * =====================================================================================
 *
 *       Filename:  TileIsometric.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/14/2014 03:33:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  imane (), imanecr@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _TILEISOMETRIC_H_
#define _TILEISOMETRIC_H_

#include <set>
#include <vector>

typedef struct TilePos
{
	int x;
	int y;
} TilePos;

bool fncomp (TilePos lhs, TilePos rhs);

/*
 * =====================================================================================
 *        Class:  CTileIsometric
 *  Description:  Staggered Isometric Map  
 * =====================================================================================
 */
class CTileIsometric
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		CTileIsometric ();                             /* constructor */

		/* ====================  ACCESSORS     ======================================= */

		/* ====================  OPERATORS     ======================================= */
		bool Init(const std::vector<TilePos> &vec);
		void AddTile(const TilePos &tile);
		void AddTileByObj(const TilePos &tile, const int &weight, const int &height);

		bool IsHaveTile(const TilePos &tile);
		bool IsHaveTileByObj(const TilePos &tile, const int &weith, const int &height);
		bool IsHaveTileInRectArea(const TilePos &tile, const TilePos &initpos, const int &weight, const int &height);

	protected:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */

	private:
		/* ====================  METHODS       ======================================= */

		/* ====================  DATA MEMBERS  ======================================= */
		std::set<TilePos, bool (*)(TilePos, TilePos)> m_setData;

}; /* -----  end of class CTileIsometric  ----- */

#endif
