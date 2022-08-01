#pragma once



#include <iomanip>
#include "cellClass.h"
#include "functions.h"



//   Custom Class that makes up the Battleship Grids for both players
class board
{
	private:
		//   Dimensions of the Battleship Grid
		static const int X_DIM = 14;
		static const int Y_DIM = 10;

		//   The Main Battleship Grid
		cell grid[X_DIM][Y_DIM];


	public:

		board()
		{}

		~board()
		{}


		/*   Launches a Basic Attack, using coordinates as the parameter.
			 Returns 1 if a Ship Bit is on there, destroys it, and adds a Hit Marker in its place.
			 Returns 2 if a Recon1 Bit was on the cell as well.
			 Returns 3 if a Recon2 Bit was on there instead.
			 Returns 0 otherwise.
			 Returns -1 if the coordinate is out of bounds.                                        */
		int Battack(int x_, int y_)
		{
			//   Check for valid coordinates. If valid, attack the cell
			if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1))
			{return grid[x_][y_].attack();}

			//   Invalid coordinate
			else
			{return -1;}
		}


		/*   Launches a Special Attack with the Aircraft Carrier, using coordinates as the parameter.
			 Firing Pattern 1 hits cells in an X-pattern. Firing Pattern 2 hits cells in a plus-pattern.
			 Returns 1 if a Ship Bit was hit, and adds a Hit Marker in its place.
			 Returns 2 if a Recon1 Bit was hit as well.
			 Returns 3 if a Recon2 Bit was hit instead.
			 Returns 4 if both Recon Bits were hit.
			 Returns 0 otherwise.
			 Returns -1 if any of the coordinates are out of bounds, or an invalid Firing Pattern is selected. */
		int ACattack(int x_, int y_, int firePattern_)
		{
			int A1, A2, A3, A4, A5;
			int temp = 0;
			bool Recon1hit = false;
			bool Recon2hit = false;


			switch (firePattern_)
			{
				//   Firing Pattern 1
				case 1:

					//   Check for valid coordinates
					if (intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
						intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
						intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
						intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1) &&
						intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1))
					{
						//   Attack the cells
						A1 = grid[x_ - 1][y_ - 1].attack();
						A2 = grid[x_ + 1][y_ - 1].attack();
						A3 = grid[x_][y_].attack();
						A4 = grid[x_ - 1][y_ + 1].attack();
						A5 = grid[x_ + 1][y_ + 1].attack();


						//   Check the results of the attack
						if (A1 == 1 || A2 == 1 || A3 == 1 || A4 == 1 || A5 == 1)
						{temp = 1;}

						if (A1 == 2 || A2 == 2 || A3 == 2 || A4 == 2 || A5 == 2)
						{
							Recon1hit = true;
							temp = 2;
						}

						if (A1 == 3 || A2 == 3 || A3 == 3 || A4 == 3 || A5 == 3)
						{
							Recon2hit = true;
							temp = 3;
						}

						if (Recon1hit && Recon2hit)
						{temp = 4;}
					}

					//   Invalid coordinates
					else
					{temp = -1;}

					break;

				//   Firing Pattern 2
				case 2:

					//   Check for valid coordinates
					if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
						intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
						intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
						intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
						intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1))
					{
						//   Attack the cells
						A1 = grid[x_][y_ - 1].attack();
						A2 = grid[x_ - 1][y_].attack();
						A3 = grid[x_][y_].attack();
						A4 = grid[x_ + 1][y_].attack();
						A5 = grid[x_][y_ + 1].attack();


						//   Check the results of the attack
						if (A1 == 1 || A2 == 1 || A3 == 1 || A4 == 1 || A5 == 1)
						{temp = 1;}

						if (A1 == 2 || A2 == 2 || A3 == 2 || A4 == 2 || A5 == 2)
						{
							Recon1hit = true;
							temp = 2;
						}

						if (A1 == 3 || A2 == 3 || A3 == 3 || A4 == 3 || A5 == 3)
						{
							Recon2hit = true;
							temp = 3;
						}

						if (Recon1hit && Recon2hit)
						{temp = 4;}
					}

					//   Invalid coordinates
					else
					{temp = -1;}

					break;

				//   Invalid Firing Pattern
				default:
					temp = -1;
					break;
		
			}

			return temp;
		}


		/*   Launches a Special Attack with the Battleship, using coordinates as the parameter.
			 The Firing Pattern hits cells in a 3x3 square.
			 Returns 1 if a Ship Bit was hit, and adds a Hit Marker in its place.
			 Returns 2 if a Recon1 Bit was hit as well.
			 Returns 3 if a Recon2 Bit was hit instead.
			 Returns 4 if both Recon Bits were hit.
			 Returns 0 otherwise.
			 Returns -1 if any of the coordinates are out of bounds.                            */
		int BSattack(int x_, int y_)
		{
			int A1, A2, A3, A4, A5, A6, A7, A8, A9;
			int temp = 0;
			bool Recon1hit = false;
			bool Recon2hit = false;

			//   Check for valid coordinates
			if (intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
				intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
				intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
				intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
				intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
				intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
				intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1) &&
				intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1) &&
				intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1))
			{
				//   Attack the cells
				A1 = grid[x_ - 1][y_ - 1].attack();
				A2 = grid[x_][y_ - 1].attack();
				A3 = grid[x_ + 1][y_ - 1].attack();
				A4 = grid[x_ - 1][y_].attack();
				A5 = grid[x_][y_].attack();
				A6 = grid[x_ + 1][y_].attack();
				A7 = grid[x_ - 1][y_ + 1].attack();
				A8 = grid[x_][y_ + 1].attack();
				A9 = grid[x_ + 1][y_ + 1].attack();


				//   Check the results of the attack
				if (A1 == 1 || A2 == 1 || A3 == 1 || A4 == 1 || A5 == 1 || A6 == 1 || 
					A7 == 1 || A8 == 1 || A9 == 1)
				{temp = 1;}

				if (A1 == 2 || A2 == 2 || A3 == 2 || A4 == 2 || A5 == 2 || A6 == 2 || 
					A7 == 2 || A8 == 2 || A9 == 2)
				{
					Recon1hit = true;
					temp = 2;
				}

				if (A1 == 3 || A2 == 3 || A3 == 3 || A4 == 3 || A5 == 3 || A6 == 3 ||
					A7 == 3 || A8 == 3 || A9 == 3)
				{
					Recon2hit = true;
					temp = 3;
				}

				if (Recon1hit && Recon2hit)
				{temp = 4;}
			}

			//   Invalid coordinates
			else
			{temp = -1;}

			return temp;
		}


		/*   Launches a Special Attack with the Destroyer, using coordinates as the parameter.
			 Firing Pattern 1 hits cells in a 3x1 (Horizontal) pattern. Firing Pattern 2 hits cells in a 1x3 (Vertical) pattern. 
			 Returns 1 if a Ship Bit was hit, and adds a Hit Marker in its place.
			 Returns 2 if a Recon1 Bit was hit as well.
			 Returns 3 if a Recon2 Bit was hit instead.
			 Returns 4 if both Recon Bits were hit.
			 Returns 0 otherwise.
			 Returns -1 if any of the coordinates are out of bounds, or an invalid Firing Pattern is selected.                   */
		int DRattack(int x_, int y_, int firePattern_)
		{
			int A1, A2, A3;
			int temp = 0;
			bool Recon1hit = false;
			bool Recon2hit = false;


			switch (firePattern_)
			{
				//   Firing Pattern 1
				case 1:

					//   Check for valid coordinates
					if (intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
						intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
						intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1))
					{
						//   Attack the cells
						A1 = grid[x_ - 1][y_].attack();
						A2 = grid[x_][y_].attack();
						A3 = grid[x_ + 1][y_].attack();


						//   Check the results of the attack
						if (A1 == 1 || A2 == 1 || A3 == 1)
						{temp = 1;}

						if (A1 == 2 || A2 == 2 || A3 == 2)
						{
							Recon1hit = true;
							temp = 2;
						}

						if (A1 == 3 || A2 == 3 || A3 == 3)
						{
							Recon2hit = true;
							temp = 3;
						}

						if (Recon1hit && Recon2hit)
						{temp = 4;}
					}

					//   Invalid coordinates
					else
					{temp = -1;}
				
					break;

				//   Firing Pattern 2
				case 2:

					//   Check for valid coordinates
					if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
						intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
						intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1))
					{
						//   Attack the cells
						A1 = grid[x_][y_ - 1].attack();
						A2 = grid[x_][y_].attack();
						A3 = grid[x_][y_ + 1].attack();


						//   Check the results of the attack
						if (A1 == 1 || A2 == 1 || A3 == 1)
						{temp = 1;}

						if (A1 == 2 || A2 == 2 || A3 == 2)
						{
							Recon1hit = true;
							temp = 2;
						}

						if (A1 == 3 || A2 == 3 || A3 == 3)
						{
							Recon2hit = true;
							temp = 3;
						}

						if (Recon1hit && Recon2hit)
						{temp = 4;}
					}

					//   Invalid coordinates
					else
					{temp = -1;}

					break;

				//   Invalid Firing Pattern
				default:
					temp = -1;
					break;
			}

			return temp;
		}


		/*   Launches a Special Attack with the Submarine, using coordinates as the parameter.
			 Firing Pattern 1 attacks across the Horizontal Plane. Firing Pattern 2 attacks across the Vertical Plane.
			 Attack originates from the edges of the grid, firing inwards towards the center.
			 Adds Miss Marks as the attack travels across the grid, until a Ship Bit is hit, 
			 or if it hits the opposite	edge.
			 Returns 1 if a Ship Bit was hit, and adds a Hit Marker in its place.
			 Returns 2 if a Recon1 Bit was hit as well.
			 Returns 3 if a Recon2 Bit was hit instead.
			 Returns 0 otherwise.
			 Returns -1 if the origin coordinate is out of bounds, or an invalid Firing Pattern is selected.           */
		int SBattack(int x_, int y_, int firingPattern_)
		{
			int temp = 0;

			switch (firingPattern_)
			{
				//   Firing Pattern 1
				case 1:

					//   Check for valid origin coordinate
					if ((intValidCheck(x_, 0, 0) || intValidCheck(x_, X_DIM - 1, X_DIM - 1)) &&
						intValidCheck(y_, 0, Y_DIM - 1))
					{
						//   Starting from left edge of the grid
						if (x_ == 0)
						{
							//   Attack every cell & stop if a Ship Bit is hit or if the edge of the
							//   grid is reached
							for (int i = 0; i < X_DIM; i++)
							{
								switch (grid[i][y_].attack())
								{
									case 1:
										temp = 1;
										break;

									case 2:
										temp = 2;
										break;

									case 3:
										temp = 3;
										break;

									default:
										break;
								}

								//   Stopping attack after a confirmed hit
								if (temp == 1 || temp == 2 || temp == 3)
								{break;}
							}
						}

						//   Starting from the right edge of the grid
						else
						{
							//   Attack every cell & stop if a Ship Bit is hit or if the edge of the
							//   grid is reached
							for (int i = X_DIM - 1; i > -1; i--)
							{
								switch (grid[i][y_].attack())
								{
									case 1:
										temp = 1;
										break;

									case 2:
										temp = 2;
										break;

									case 3:
										temp = 3;
										break;

									default:
										break;
								}

								//   Stopping attack after a confirmed hit
								if (temp == 1 || temp == 2 || temp == 3)
								{break;}
							}
						}
					}

					//   Invalid coordinate
					else
					{temp = -1;}

					break;

				//   Firing Pattern 2
				case 2:

					//   Check for valid origin coordinate
					if ((intValidCheck(y_, 0, 0) || intValidCheck(y_, Y_DIM - 1, Y_DIM - 1)) &&
						intValidCheck(x_, 0, X_DIM - 1))
					{
						//   Starting from the top edge of the grid
						if (y_ == 0)
						{
							//   Attack every cell & stop if a Ship Bit is hit or if the edge of the
							//   grid is reached
							for (int i = 0; i < Y_DIM; i++)
							{
								switch (grid[x_][i].attack())
								{
									case 1:
										temp = 1;
										break;

									case 2:
										temp = 2;
										break;

									case 3:
										temp = 3;
										break;

									default:
										break;
								}

								//   Stopping attack after a confirmed hit
								if (temp == 1 || temp == 2 || temp == 3)
								{break;}
							}
						}

						//   Starting from the bottom edge of the grid
						else
						{
							//   Attack every cell & stop if a Ship Bit is hit or if the edge of the
							//   grid is reached
							for (int i = Y_DIM - 1; i > -1; i--)
							{
								switch (grid[x_][i].attack())
								{
									case 1:
										temp = 1;
										break;

									case 2:
										temp = 2;
										break;

									case 3:
										temp = 3;
										break;

									default:
										break;
								}

								//   Stopping attack after a confirmed hit
								if (temp == 1 || temp == 2 || temp == 3)
								{break;}
							}
						}
					}

					//   Invalid coordinate
					else
					{temp = -1;}

					break;

				//   Invalid Firing Pattern
				default:
					temp = -1;
					break;
			}

			return temp;
		}


		/*   Launches an Anti-air Attack, using coordinates as the parameter.
			 Returns 1 if a Recon1 Bit was hit.
			 Returns 2 if a Recon2 Bit was hit instead. 
			 Returns 0 otherwise.                                             
			 Returns -1 if the chosen coordinate is out of bounds.            */
		int AAattack(int x_, int y_)
		{
			int temp = 0;

			if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1))
			{temp = AAattack(x_, y_);}

			else
			{temp = -1;}

			return temp;
		}


		/*   Performs a scan with the Submarine, using coordinates as the parameter.
			 The Scanning Pattern scans cells in a 3x3 square.
			 Returns 1 if a ship was detected, and adds Scan Markers in the area.
			 Returns 0 otherwise, and adds Miss Markers in the area.
			 Returns -1 if any of the coordinates are out of bounds.                 */
		int SBscan(int x_, int y_)
		{
			bool S1, S2, S3, S4, S5, S6, S7, S8, S9;
			int temp = 0;

			//   Check for valid coordinates
			if (intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
				intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
				intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1) &&
				intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
				intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
				intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
				intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1) &&
				intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1) &&
				intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1))
			{
				//   Scan the cells
				S1 = grid[x_ - 1][y_ - 1].scan();
				S2 = grid[x_][y_ - 1].scan();
				S3 = grid[x_ + 1][y_ - 1].scan();
				S4 = grid[x_ - 1][y_].scan();
				S5 = grid[x_][y_].scan();
				S6 = grid[x_ + 1][y_].scan();
				S7 = grid[x_ - 1][y_ + 1].scan();
				S8 = grid[x_][y_ + 1].scan();
				S9 = grid[x_ + 1][y_ + 1].scan();

				//   Check the results of the scan, and proceed if something was detected
				if (S1 || S2 || S3 || S4 || S5 || S6 || S7 || S8 || S9)
				{
					temp = 1;

					//   Mark all the cells in the area with Scan Marks if they don't have any battle marks
					if (!grid[x_ - 1][y_ - 1].isBmark())
					{grid[x_ - 1][y_ - 1].setScan(1);}

					if (!grid[x_][y_ - 1].isBmark())
					{grid[x_][y_ - 1].setScan(1);}

					if (!grid[x_ + 1][y_ - 1].isBmark())
					{grid[x_ + 1][y_ - 1].setScan(1);}

					if (!grid[x_ - 1][y_].isBmark())
					{grid[x_ - 1][y_].setScan(1);}

					if (!grid[x_][y_].isBmark())
					{grid[x_][y_].setScan(1);}

					if (!grid[x_ + 1][y_].isBmark())
					{grid[x_ + 1][y_].setScan(1);}

					if (!grid[x_ - 1][y_ + 1].isBmark())
					{grid[x_ - 1][y_ + 1].setScan(1);}

					if (!grid[x_][y_ + 1].isBmark())
					{grid[x_][y_ + 1].setScan(1);}

					if (!grid[x_ + 1][y_ + 1].isBmark())
					{grid[x_ + 1][y_ + 1].setScan(1);}
				}

				/*   Mark all the cells in the area with Miss Markers if nothing was detected
					 by attacking the cells, handles scanning the same area twice             */
				else
				{
					grid[x_ - 1][y_ - 1].attack();
					grid[x_][y_ - 1].attack();
					grid[x_ + 1][y_ - 1].attack();
					grid[x_ - 1][y_].attack();
					grid[x_][y_].attack();
					grid[x_ + 1][y_].attack();
					grid[x_ - 1][y_ + 1].attack();
					grid[x_][y_ + 1].attack();
					grid[x_ + 1][y_ + 1].attack();
				}
			}

			//   Invalid coordinates
			else
			{temp = -1;}

			return temp;
		}


		/*   Finds the coordinates of the requested Recon Plane.
			 Returns a scnCoord object with the coordinates if it was able to find it.
			 Returns a scnCoord object with the coordinates (-1, -1) if the plane was not found. */
		scnCoord getRPcoord(int plane_)
		{
			scnCoord temp;
			int x_ = -1;
			int y_ = -1;

			//   Find the requested recon plane
			for (int i = 0; i < Y_DIM; i++)
			{
				for (int j = 0; j < X_DIM; j++)
				{
					switch (plane_)
					{
						case 1:
							if (grid[j][i].isRecon() == 1)
							{
								x_ = j;
								y_ = i;
							}

							break;

						case 2:
							if (grid[j][i].isRecon() == 2)
							{
								x_ = j;
								y_ = i;
							}

							break;

						default:
							break;
					}
				}
			}

			temp.x = x_;
			temp.y = y_;

			return temp;
		}


		/*   Performs a scan with a Recon Plane, using coordinates and scanning pattern as the parameters.
			 Scanning Pattern 1 scans cells in an X-pattern, without the center. Scanning Pattern 2 scans a +-pattern.
			 Returns a vector containing scnCoord objects, which contain the coordinates of the located ships if they were detected,
			 and adds Scan Markers on the detected cells along with Miss Markers on the empty cells.
			 Returns a vector of size 0 if nothing was detected otherwise, and adds Miss Markers on the scanned cells.
			 Returns a vector of size 5 if any of the coordinates are out of bounds, or an invalid Scanning Pattern is selected.     */
		vector<scnCoord> RPscan(int x_, int y_, int scanPattern_)
		{
			vector<scnCoord> tempVector;

			//   Scan the coordinate with the requested scan pattern
			switch (scanPattern_)
			{
				//   Scanning Pattern 1
				case 1:
				{
					//   Check for valid origin coordinate
					if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1))
					{
						//   If the (x_ - 1, y_ - 1) coordinate is valid, scan it
						if (intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1))
						{
							//   If something is there, add it to the vector and add a Scan Mark on it
							if (grid[x_ - 1][y_ - 1].scan())
							{
								scnCoord temp(x_ - 1, y_ - 1);
								tempVector.push_back(temp);
								grid[x_ - 1][y_ - 1].setScan(2);
							}

							//   If nothing is there, add a Miss Mark on it
							else
							{grid[x_ - 1][y_ - 1].attack();}
						}


						//   If the (x_ + 1, y_ - 1) coordinate is valid, scan it
						if (intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1))
						{
							//   If something is there, add it to the vector and add a Scan Mark on it
							if (grid[x_ + 1][y_ - 1].scan())
							{
								scnCoord temp(x_ + 1, y_ - 1);
								tempVector.push_back(temp);
								grid[x_ + 1][y_ - 1].setScan(2);
							}

							//   If nothing is there, add a Miss Mark on it
							else
							{grid[x_ + 1][y_ - 1].attack();}
						}


						//   If the (x_ - 1, y_ + 1) coordinate is valid, scan it
						if (intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1))
						{
							//   If something is there, add it to the vector and add a Scan Mark on it
							if (grid[x_ - 1][y_ + 1].scan())
							{
								scnCoord temp(x_ - 1, y_ + 1);
								tempVector.push_back(temp);
								grid[x_ - 1][y_ + 1].setScan(2);
							}

							//   If nothing is there, add a Miss Mark on it
							else
							{grid[x_ - 1][y_ + 1].attack();}
						}


						//   If the (x_ + 1, y_ + 1) coordinate is valid, scan it
						if (intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1))
						{
							//   If something is there, add it to the vector and add a Scan Mark on it
							if (grid[x_ + 1][y_ + 1].scan())
							{
								scnCoord temp(x_ + 1, y_ + 1);
								tempVector.push_back(temp);
								grid[x_ + 1][y_ + 1].setScan(2);
							}

							//   If nothing is there, add a Miss Mark on it
							else
							{grid[x_ + 1][y_ + 1].attack();}
						}
					}

					//   Invalid coordinate
					else
					{
						scnCoord temp(-1, -1);

						//   Push-back 5 elements into the vector to indicate invalid coordinates
						for (int i = 0; i < 5; i++)
						{tempVector.push_back(temp);}
					}

					break;
				}

				//   Scanning Pattern 2
				case 2:
				{
					//   Check for valid origin coordinate
					if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1))
					{
						//   If the (x_, y_ - 1) coordinate is valid, scan it
						if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ - 1, 0, Y_DIM - 1))
						{
							//   If something is there, add it to the vector and add a Scan Mark on it
							if (grid[x_][y_ - 1].scan())
							{
								scnCoord temp(x_, y_ - 1);
								tempVector.push_back(temp);
								grid[x_][y_ - 1].setScan(2);
							}

							//   If nothing is there, add a Miss Mark on it
							else
							{grid[x_][y_ - 1].attack();}
						}

						//   If the (x_ - 1, y_) coordinate is valid, scan it
						if (intValidCheck(x_ - 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1))
						{
							//   If something is there, add it to the vector and add a Scan Mark on it
							if (grid[x_ - 1][y_].scan())
							{
								scnCoord temp(x_ - 1, y_);
								tempVector.push_back(temp);
								grid[x_ - 1][y_].setScan(2);
							}

							//   If nothing is there, add a Miss Mark on it
							else
							{grid[x_ - 1][y_].attack();}
						}

						//   If the (x_ + 1, y_) coordinate is valid, scan it
						if (intValidCheck(x_ + 1, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1))
						{
							//   If something is there, add it to the vector and add a Scan Mark on it
							if (grid[x_ + 1][y_].scan())
							{
								scnCoord temp(x_ + 1, y_);
								tempVector.push_back(temp);
								grid[x_ + 1][y_].setScan(2);
							}

							//   If nothing is there, add a Miss Mark on it
							else
							{grid[x_ + 1][y_].attack();}
						}

						//   If the (x_, y_ + 1) coordinate is valid, scan it
						if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_ + 1, 0, Y_DIM - 1))
						{
							//   If something is there, add it to the vector and add a Scan Mark on it
							if (grid[x_][y_ + 1].scan())
							{
								scnCoord temp(x_, y_ + 1);
								tempVector.push_back(temp);
								grid[x_][y_ + 1].setScan(2);
							}

							//   If nothing is there, add a Miss Mark on it
							else
							{grid[x_][y_ + 1].attack();}
						}
					}

					//   Invalid coordinate
					else
					{
						scnCoord temp(-1, -1);

						//   Push-back 5 elements into the vector to indicate invalid coordinates
						for (int i = 0; i < 5; i++)
						{tempVector.push_back(temp);}
					}

					break;
				}

				//   Invalid Scanning Pattern
				default:
				{
					scnCoord temp(-1, -1);

					//   Push-back 5 elements into the vector to indicate invalid scanning pattern
					for (int i = 0; i < 5; i++)
					{tempVector.push_back(temp);}
				}
			}

			return tempVector;
		}


		//   Displays the Target Subgrid.
		void displayTgrid()
		{
			int gridY = 1;
			char letter = 'A';

			cout << "\n" << endl;
			cout << "         |";

			//   Displaying the top row of letters
			for (int i = 0; i < X_DIM; i++)
			{
				cout << "  " << letter << "  |";
				letter++;
			}

			cout << endl;

			//   Displaying each row
			for (int y = 0; y < Y_DIM; y++)
			{
				cout << "   -";

				for (int i = 0; i < X_DIM + 1; i++)
				{cout << "------";}

				cout << endl;

				cout << "     ";
			
				cout << setw(3) << left << gridY;

				//   Calling the display function of each cell in the current row
				for (int x = 0; x < X_DIM; x++)
				{
					cout << " | ";
					grid[x][y].display();
				
				}

				cout << " | ";
				cout << endl;
				gridY++;
			}

			cout << "   -";

			for (int i = 0; i < X_DIM + 1; i++)
			{cout << "------";}

			cout << endl;
		}


		//   Displays the Home Subgrid.
		void displayHgrid()
		{
			int gridY = 1;
			char letter = 'A';

			cout << "\n" << endl;
			cout << "         |";

			//   Displaying the top row of letters
			for (int i = 0; i < X_DIM; i++)
			{
				cout << "  " << letter << "  |";
				letter++;
			}

			cout << endl;

			//   Displaying each row
			for (int y = 0; y < Y_DIM; y++)
			{
				cout << "   -";

				for (int i = 0; i < X_DIM + 1; i++)
				{cout << "------";}

				cout << endl;

				cout << "     ";

				cout << setw(3) << left << gridY;

				//   Calling the display function of each cell in the current row
				for (int x = 0; x < X_DIM; x++)
				{
					cout << " | ";
					grid[x][y].displayShipBit();

				}

				cout << " | ";
				cout << endl;
				gridY++;
			}

			cout << "   -";

			for (int i = 0; i < X_DIM + 1; i++)
			{cout << "------";}

			cout << endl;
		}


		/*   Sets the specified ship on the specified coordinate range.
			 Coordinates must be either in a horizontal or vertical line, no diagonal lines.
			 Returns True if the coordinates specified are valid for the chosen ship.
			 Returns False otherwise.
			 1 = Aircraft Carrier, 5 Units
			 2 = Battleship, 4 Units
			 3 = Destroyer, 3 Units
			 4 = Submarine, 3 Units
			 5 = Patrol Boat, 2 Units                                                        */
		bool setShipBits(int x1_, int y1_, int x2_, int y2_, int shipType_)
		{
			bool validPlacement = true;

			//   Checking the coordinates to see if they are within the bounds of the grid
			if (intValidCheck(x1_, 0, X_DIM - 1) && intValidCheck(y1_, 0, Y_DIM - 1) &&
				intValidCheck(x2_, 0, X_DIM - 1) && intValidCheck(y2_, 0, Y_DIM - 1))
			{
				switch (shipType_)
				{
					//   Placing the Aircraft Carrier on the grid
					case 1:

						//   Checking if the specified coordinates span 5 units
						if (distValidCheck(x1_, y1_, x2_, y2_, 5))
						{
							//   Vertical placement
							if (x1_ == x2_)
							{
								//   Finding out where to start checking for intersecting ships
								if (y1_ < y2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y1_; i <= y2_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y2_; i <= y1_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							//   Horizontal placement
							else
							{
								//   Finding out where to start checking for intersecting ships
								if (x1_ < x2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x1_; i <= x2_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x2_; i <= x1_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							/*   If specified coordinate range doesn't have any existing Ship Bits in it, and the
								 range is still valid, add the requested ship to that range                       */
							if (validPlacement)
							{
								//   Range is vertical
								if (x1_ == x2_)
								{
									//   y1 is the smaller coordinate
									if (y1_ < y2_)
									{
										for (int i = y1_; i <= y2_; i++)
										{grid[x1_][i].setShipBit(1);}
									}

									//   y2 is the smaller coordinate
									else
									{
										for (int i = y2_; i <= y1_; i++)
										{grid[x1_][i].setShipBit(1);}
									}
								}

								//   Range is horizontal
								else
								{
									//   x1 is the smaller coordinate
									if (x1_ < x2_)
									{
										for (int i = x1_; i <= x2_; i++)
										{grid[i][y1_].setShipBit(1);}
									}

									//   x2 is the smaller coordinate
									else
									{
										for (int i = x2_; i <= x1_; i++)
										{grid[i][y1_].setShipBit(1);}
									}
								}
							}
						}

						//   Coordinates aren't valid
						else
						{validPlacement = false;}

						break;

					//   Placing the Battleship on the grid
					case 2:

						//   Checking if the specified coordinates span 4 units
						if (distValidCheck(x1_, y1_, x2_, y2_, 4))
						{
							//   Vertical placement
							if (x1_ == x2_)
							{
								//   Finding out where to start checking for intersecting ships
								if (y1_ < y2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y1_; i <= y2_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y2_; i <= y1_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							//   Horizontal placement
							else
							{
								//   Finding out where to start checking for intersecting ships
								if (x1_ < x2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x1_; i <= x2_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x2_; i <= x1_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							/*   If specified coordinate range doesn't have any existing Ship Bits in it, and the
								 range is still valid, add the requested ship to that range                       */
							if (validPlacement)
							{
								//   Range is vertical
								if (x1_ == x2_)
								{
									//   y1 is the smaller coordinate
									if (y1_ < y2_)
									{
										for (int i = y1_; i <= y2_; i++)
										{grid[x1_][i].setShipBit(2);}
									}

									//   y2 is the smaller coordinate
									else
									{
										for (int i = y2_; i <= y1_; i++)
										{grid[x1_][i].setShipBit(2);}
									}
								}

								//   Range is horizontal
								else
								{
									//   x1 is the smaller coordinate
									if (x1_ < x2_)
									{
										for (int i = x1_; i <= x2_; i++)
										{grid[i][y1_].setShipBit(2);}
									}

									//   x2 is the smaller coordinate
									else
									{
										for (int i = x2_; i <= x1_; i++)
										{grid[i][y1_].setShipBit(2);}
									}
								}
							}
						}

						//   Coordinates aren't valid
						else
						{validPlacement = false;}

						break;

					//   Placing the Destroyer on the grid
					case 3:

						//   Checking if the specified coordinates span 3 units
						if (distValidCheck(x1_, y1_, x2_, y2_, 3))
						{
							//   Vertical placement
							if (x1_ == x2_)
							{
								//   Finding out where to start checking for intersecting ships
								if (y1_ < y2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y1_; i <= y2_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y2_; i <= y1_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							//   Horizontal placement
							else
							{
								//   Finding out where to start checking for intersecting ships
								if (x1_ < x2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x1_; i <= x2_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x2_; i <= x1_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							/*   If specified coordinate range doesn't have any existing Ship Bits in it, and the
								 range is still valid, add the requested ship to that range                       */
							if (validPlacement)
							{
								//   Range is vertical
								if (x1_ == x2_)
								{
									//   y1 is the smaller coordinate
									if (y1_ < y2_)
									{
										for (int i = y1_; i <= y2_; i++)
										{grid[x1_][i].setShipBit(3);}
									}

									//   y2 is the smaller coordinate
									else
									{
										for (int i = y2_; i <= y1_; i++)
										{grid[x1_][i].setShipBit(3);}
									}
								}

								//   Range is horizontal
								else
								{
									//   x1 is the smaller coordinate
									if (x1_ < x2_)
									{
										for (int i = x1_; i <= x2_; i++)
										{grid[i][y1_].setShipBit(3);}
									}

									//   x2 is the smaller coordinate
									else
									{
										for (int i = x2_; i <= x1_; i++)
										{grid[i][y1_].setShipBit(3);}
									}
								}
							}
						}

						//   Coordinates aren't valid
						else
						{validPlacement = false;}

						break;

					//   Placing the Submarine on the grid
					case 4:

						//   Checking if the specified coordinates span 3 units
						if (distValidCheck(x1_, y1_, x2_, y2_, 3))
						{
							//   Vertical placement
							if (x1_ == x2_)
							{
								//   Finding out where to start checking for intersecting ships
								if (y1_ < y2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y1_; i <= y2_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y2_; i <= y1_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							//   Horizontal placement
							else
							{
								//   Finding out where to start checking for intersecting ships
								if (x1_ < x2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x1_; i <= x2_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x2_; i <= x1_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							/*   If specified coordinate range doesn't have any existing Ship Bits in it, and the
								 range is still valid, add the requested ship to that range                       */
							if (validPlacement)
							{
								//   Range is vertical
								if (x1_ == x2_)
								{
									//   y1 is the smaller coordinate
									if (y1_ < y2_)
									{
										for (int i = y1_; i <= y2_; i++)
										{grid[x1_][i].setShipBit(4);}
									}

									//   y2 is the smaller coordinate
									else
									{
										for (int i = y2_; i <= y1_; i++)
										{grid[x1_][i].setShipBit(4);}
									}
								}

								//   Range is horizontal
								else
								{
									//   x1 is the smaller coordinate
									if (x1_ < x2_)
									{
										for (int i = x1_; i <= x2_; i++)
										{grid[i][y1_].setShipBit(4);}
									}

									//   x2 is the smaller coordinate
									else
									{
										for (int i = x2_; i <= x1_; i++)
										{grid[i][y1_].setShipBit(4);}
									}
								}
							}
						}

						//   Coordinates aren't valid
						else
						{validPlacement = false;}

						break;

					//   Placing the Patrol Boat on the grid
					case 5:

						//   Checking if the specified coordinates span 2 units
						if (distValidCheck(x1_, y1_, x2_, y2_, 2))
						{
							//   Vertical placement
							if (x1_ == x2_)
							{
								//   Finding out where to start checking for intersecting ships
								if (y1_ < y2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y1_; i <= y2_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = y2_; i <= y1_; i++)
									{
										if (grid[x1_][i].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							//   Horizontal placement
							else
							{
								//   Finding out where to start checking for intersecting ships
								if (x1_ < x2_)
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x1_; i <= x2_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}

								//   Finding out where to start checking for intersecting ships
								else
								{
									//   Checking each cell within the requested range for existing Ship Bits
									for (int i = x2_; i <= x1_; i++)
									{
										if (grid[i][y1_].getShip() != 0)
										{validPlacement = false;}
									}
								}
							}

							/*   If specified coordinate range doesn't have any existing Ship Bits in it, and the
								 range is still valid, add the requested ship to that range                       */
							if (validPlacement)
							{
								//   Range is vertical
								if (x1_ == x2_)
								{
									//   y1 is the smaller coordinate
									if (y1_ < y2_)
									{
										for (int i = y1_; i <= y2_; i++)
										{grid[x1_][i].setShipBit(5);}
									}

									//   y2 is the smaller coordinate
									else
									{
										for (int i = y2_; i <= y1_; i++)
										{grid[x1_][i].setShipBit(5);}
									}
								}

								//   Range is horizontal
								else
								{
									//   x1 is the smaller coordinate
									if (x1_ < x2_)
									{
										for (int i = x1_; i <= x2_; i++)
										{grid[i][y1_].setShipBit(5);}
									}

									//   x2 is the smaller coordinate
									else
									{
										for (int i = x2_; i <= x1_; i++)
										{grid[i][y1_].setShipBit(5);}
									}
								}
							}
						}

						//   Coordinates aren't valid
						else
						{validPlacement = false;}

						break;


					default:
						validPlacement = false;
						break;
				}
			}

			else
			{validPlacement = false;}

		

			return validPlacement;
		}


		/*   Sets the Recon Planes on the specified coordinate.
			 Coordinates must be located on an Aircraft Carrier, and cannot be on an existing Recon Plane.
			 Returns True if the coordinate is valid, false otherwise.  
			 1 = Recon 1
			 2 = Recon 2                                                                                   */
		bool setReconBits(int x_, int y_, int reconBit_)
		{
			bool temp = true;

			if (intValidCheck(x_, 0, X_DIM - 1) && intValidCheck(y_, 0, Y_DIM - 1) &&
				grid[x_][y_].isAC() && !grid[x_][y_].isGRecon())
			{grid[x_][y_].setReconBit(reconBit_);}

			else
			{temp = false;}

			return temp;
		}


		/*   Moves the requested Recon Plane to the requested cell, by marking it as 
			 occupied by the requested plane.
			 Scans the board to perform the operation.
			 Returns True if the operation was successful.
			 Returns False if another plane occpuies the spot.                       */
		bool moveRecon(int x_, int y_, int choice_)
		{
			bool temp = true;

			//   Check all the cells to find a grounded recon plane
			for (int i = 0; i < Y_DIM; i++)
			{
				for (int j = 0; j < X_DIM; j++)
				{
					//   Destroy the chosen plane, since it removes its old location
					switch (choice_)
					{
						case 1:
						{
							grid[j][i].deployRecon(1);

							if (grid[j][i].isRecon() == 1)
							{grid[j][i].AAatk();}

							break;
						}

						case 2:
						{
							grid[j][i].deployRecon(2);

							if (grid[j][i].isRecon() == 2)
							{grid[j][i].AAatk();}

							break;
						}
					}
				}
			}


			switch (choice_)
			{
				case 1:
					temp = grid[x_][y_].newReconPos(1);
					break;

				case 2:
					temp = grid[x_][y_].newReconPos(2);
					break;

				default:
					break;
			}

			return temp;
		}


		/*   Responsible for predeploying Ship Configurations based on the choice. 
			 Choices range from 1 to 30.                                           */
		bool preConfigShips(int choice_)
		{
			bool validChoice = true;

			switch (choice_)
			{
				case 1: //   Configuration A1
					setShipBits(6, 6, 10, 6, 1);
					setShipBits(9, 4, 12, 4, 2);
					setShipBits(1, 8, 3, 8, 3);
					setShipBits(3, 1, 5, 1, 4);
					setShipBits(13, 6, 13, 7, 5);
					setReconBits(7, 6, 1);
					setReconBits(9, 6, 2);
					break;

				case 2: //   Configuration A2
					setShipBits(0, 1, 0, 5, 1);
					setShipBits(4, 1, 4, 4, 2);
					setShipBits(13, 5, 13, 7, 3);
					setShipBits(5, 9, 7, 9, 4);
					setShipBits(8, 6, 9, 6, 5);
					setReconBits(0, 1, 1);
					setReconBits(0, 5, 2);
					break;

				case 3: //   Configuration A5
					setShipBits(6, 1, 10, 1, 1);
					setShipBits(5, 3, 8, 3, 2);
					setShipBits(3, 7, 3, 9, 3);
					setShipBits(9, 2, 11, 2, 4);
					setShipBits(8, 8, 8, 9, 5);
					setReconBits(9, 1, 1);
					setReconBits(10, 1, 2);
					break;

				case 4: //   Configuration A6
					setShipBits(6, 3, 10, 3, 1);
					setShipBits(12, 4, 12, 7, 2);
					setShipBits(7, 0, 7, 2, 3);
					setShipBits(2, 7, 4, 7, 4);
					setShipBits(11, 9, 12, 9, 5);
					setReconBits(6, 3, 1);
					setReconBits(7, 3, 2);
					break;

				case 5: //   Configuration A9
					setShipBits(1, 0, 1, 4, 1);
					setShipBits(1, 6, 4, 6, 2);
					setShipBits(0, 4, 0, 6, 3);
					setShipBits(11, 1, 13, 1, 4);
					setShipBits(7, 5, 7, 6, 5);
					setReconBits(1, 1, 1);
					setReconBits(1, 4, 2);
					break;

				case 6: //   Configuration A10
					setShipBits(3, 6, 7, 6, 1);
					setShipBits(8, 1, 8, 4, 2);
					setShipBits(11, 3, 13, 3, 3);
					setShipBits(0, 2, 0, 4, 4);
					setShipBits(10, 8, 10, 9, 5);
					setReconBits(5, 6, 1);
					setReconBits(7, 6, 2);
					break;

				case 7: //   Configuration B1
					setShipBits(6, 4, 10, 4, 1);
					setShipBits(3, 9, 6, 9, 2);
					setShipBits(9, 6, 9, 8, 3);
					setShipBits(6, 7, 8, 7, 4);
					setShipBits(1, 1, 1, 2, 5);
					setReconBits(7, 4, 1);
					setReconBits(9, 4, 2);
					break;

				case 8: //   Configuration B2
					setShipBits(3, 3, 3, 7, 1);
					setShipBits(6, 1, 6, 4, 2);
					setShipBits(12, 4, 12, 6, 3);
					setShipBits(0, 5, 2, 5, 4);
					setShipBits(12, 7, 12, 8, 5);
					setReconBits(3, 3, 1);
					setReconBits(3, 7, 2);
					break;

				case 9: //   Configuration B5
					setShipBits(9, 4, 9, 8, 1);
					setShipBits(12, 5, 12, 8, 2);
					setShipBits(5, 6, 7, 6, 3);
					setShipBits(10, 0, 10, 2, 4);
					setShipBits(5, 0, 6, 0, 5);
					setReconBits(9, 7, 1);
					setReconBits(9, 8, 2);
					break;

				case 10: //   Configuration B6
					setShipBits(1, 0, 1, 4, 1);
					setShipBits(13, 0, 13, 3, 2);
					setShipBits(6, 8, 8, 8, 3);
					setShipBits(11, 6, 13, 6, 4);
					setShipBits(6, 1, 6, 2, 5);
					setReconBits(1, 0, 1);
					setReconBits(1, 1, 2);
					break;

				case 11: //   Configuration B9
					setShipBits(13, 3, 13, 7, 1);
					setShipBits(7, 0, 10, 0, 2);
					setShipBits(4, 7, 6, 7, 3);
					setShipBits(6, 2, 6, 4, 4);
					setShipBits(4, 4, 4, 5, 5);
					setReconBits(13, 4, 1);
					setReconBits(13, 7, 2);
					break;

				case 12: //   Configuration B10
					setShipBits(2, 1, 2, 5, 1);
					setShipBits(4, 8, 7, 8, 2);
					setShipBits(0, 4, 0, 6, 3);
					setShipBits(1, 0, 3, 0, 4);
					setShipBits(12, 2, 13, 2, 5);
					setReconBits(2, 3, 1);
					setReconBits(2, 5, 2);
					break;

				case 13: //   Configuration C3
					setShipBits(13, 2, 13, 6, 1);
					setShipBits(0, 6, 0, 9, 2);
					setShipBits(3, 4, 5, 4, 3);
					setShipBits(3, 6, 3, 8, 4);
					setShipBits(12, 3, 12, 4, 5);
					setReconBits(13, 4, 1);
					setReconBits(13, 5, 2);
					break;

				case 14: //   Configuration C4
					setShipBits(5, 1, 9, 1, 1);
					setShipBits(3, 5, 3, 8, 2);
					setShipBits(6, 7, 6, 9, 3);
					setShipBits(5, 4, 7, 4, 4);
					setShipBits(13, 7, 13, 8, 5);
					setReconBits(6, 1, 1);
					setReconBits(7, 1, 2);
					break;

				case 15: //   Configuration C7
					setShipBits(1, 6, 5, 6, 1);
					setShipBits(0, 5, 3, 5, 2);
					setShipBits(0, 6, 0, 8, 3);
					setShipBits(6, 4, 8, 4, 4);
					setShipBits(8, 3, 9, 3, 5);
					setReconBits(1, 6, 1);
					setReconBits(3, 6, 2);
					break;

				case 16: //   Configuration C8
					setShipBits(12, 3, 12, 7, 1);
					setShipBits(3, 3, 3, 6, 2);
					setShipBits(7, 1, 7, 3, 3);
					setShipBits(6, 9, 8, 9, 4);
					setShipBits(0, 2, 0, 3, 5);
					setReconBits(12, 3, 1);
					setReconBits(12, 6, 2);
					break;

				case 17: //   Configuration D3
					setShipBits(5, 1, 9, 1, 1);
					setShipBits(2, 0, 5, 0, 2);
					setShipBits(8, 2, 8, 4, 3);
					setShipBits(12, 1, 12, 3, 4);
					setShipBits(0, 3, 0, 4, 5);
					setReconBits(7, 1, 1);
					setReconBits(8, 1, 2);
					break;

				case 18: //   Configuration D4
					setShipBits(5, 3, 9, 3, 1);
					setShipBits(0, 4, 3, 4, 2);
					setShipBits(1, 9, 3, 9, 3);
					setShipBits(5, 5, 5, 7, 4);
					setShipBits(7, 4, 8, 4, 5);
					setReconBits(6, 3, 1);
					setReconBits(7, 3, 2);
					break;

				case 19: //   Configuration D7
					setShipBits(0, 4, 0, 8, 1);
					setShipBits(13, 2, 13, 5, 2);
					setShipBits(3, 0, 5, 0, 3);
					setShipBits(8, 7, 8, 9, 4);
					setShipBits(4, 7, 4, 8, 5);
					setReconBits(0, 4, 1);
					setReconBits(0, 6, 2);
					break;

				case 20: //   Configuration D8
					setShipBits(3, 7, 7, 7, 1);
					setShipBits(9, 1, 9, 4, 2);
					setShipBits(0, 3, 0, 5, 3);
					setShipBits(13, 0, 13, 2, 4);
					setShipBits(12, 8, 12, 9, 5);
					setReconBits(3, 7, 1);
					setReconBits(6, 7, 2);
					break;

				case 21: //   Configuration E1
					setShipBits(2, 1, 6, 1, 1);
					setShipBits(12, 3, 12, 6, 2);
					setShipBits(0, 7, 2, 7, 3);
					setShipBits(6, 7, 8, 7, 4);
					setShipBits(3, 4, 3, 5, 5);
					setReconBits(3, 1, 1);
					setReconBits(5, 1, 2);
					break;

				case 22: //   Configuration E2
					setShipBits(0, 0, 4, 0, 1);
					setShipBits(6, 5, 6, 8, 2);
					setShipBits(2, 7, 4, 7, 3);
					setShipBits(0, 5, 2, 5, 4);
					setShipBits(2, 6, 3, 6, 5);
					setReconBits(0, 0, 1);
					setReconBits(4, 0, 2);
					break;

				case 23: //   Configuration E5
					setShipBits(3, 4, 3, 8, 1);
					setShipBits(2, 3, 5, 3, 2);
					setShipBits(0, 0, 0, 2, 3);
					setShipBits(5, 2, 7, 2, 4);
					setShipBits(5, 8, 6, 8, 5);
					setReconBits(3, 7, 1);
					setReconBits(3, 8, 2);
					break;

				case 24: //   Configuration E6
					setShipBits(6, 3, 10, 3, 1);
					setShipBits(3, 7, 6, 7, 2);
					setShipBits(0, 8, 2, 8, 3);
					setShipBits(0, 6, 2, 6, 4);
					setShipBits(3, 9, 4, 9, 5);
					setReconBits(6, 3, 1);
					setReconBits(7, 3, 2);
					break;

				case 25: //   Configuration E9
					setShipBits(6, 5, 6, 9, 1);
					setShipBits(3, 5, 3, 8, 2);
					setShipBits(10, 3, 12, 3, 3);
					setShipBits(3, 1, 3, 3, 4);
					setShipBits(0, 2, 1, 2, 5);
					setReconBits(6, 6, 1);
					setReconBits(6, 9, 2);
					break;

				case 26: //   Configuration E10
					setShipBits(3, 4, 3, 8, 1);
					setShipBits(6, 2, 6, 5, 2);
					setShipBits(9, 6, 11, 6, 3);
					setShipBits(9, 5, 11, 5, 4);
					setShipBits(1, 4, 1, 5, 5);
					setReconBits(3, 6, 1);
					setReconBits(3, 8, 2);
					break;

				case 27: //   Configuration F3
					setShipBits(5, 7, 9, 7, 1);
					setShipBits(2, 5, 5, 5, 2);
					setShipBits(8, 3, 10, 3, 3);
					setShipBits(0, 7, 0, 9, 4);
					setShipBits(7, 1, 7, 2, 5);
					setReconBits(7, 7, 1);
					setReconBits(8, 7, 2);
					break;

				case 28: //   Configuration F4
					setShipBits(0, 0, 0, 4, 1);
					setShipBits(10, 8, 13, 8, 2);
					setShipBits(2, 4, 4, 4, 3);
					setShipBits(7, 0, 7, 2, 4);
					setShipBits(4, 6, 5, 6, 5);
					setReconBits(0, 1, 1);
					setReconBits(0, 2, 2);
					break;

				case 29: //   Configuration F7
					setShipBits(5, 9, 9, 9, 1);
					setShipBits(2, 8, 5, 8, 2);
					setShipBits(8, 2, 8, 4, 3);
					setShipBits(1, 7, 3, 7, 4);
					setShipBits(4, 4, 4, 5, 5);
					setReconBits(5, 9, 1);
					setReconBits(7, 9, 2);
					break;

				case 30: //   Configuration F8
					setShipBits(8, 1, 8, 5, 1);
					setShipBits(10, 3, 10, 6, 2);
					setShipBits(7, 7, 7, 9, 3);
					setShipBits(7, 0, 7, 2, 4);
					setShipBits(2, 3, 3, 3, 5);
					setReconBits(8, 1, 1);
					setReconBits(8, 4, 2);
					break;

				default:
					validChoice = false;
					break;
			}

			return validChoice;
		}


		//   Returns the length of the board's x-axis.
		int getBoardXaxis()
		{return X_DIM;}


		//   Returns the length of the board's y-axis.
		int getBoardYaxis()
		{return Y_DIM;}


		/*   Returns which ship is on the cell.
			 Returns 1 if an Aircraft Carrier is on the cell.
			 Returns 2 if a Battleship is found.
			 Returns 3 if a Destroyer is found instead.
			 Returns 4 if a Submarine is there.
			 Returns 5 if a Patrol Boat is found.             */
		int getShipFromBoard(int x_, int y_)
		{return grid[x_][y_].getShip();}


		/*   Returns whether the requested recon plane is airborne.
			 Scans the board to find the requested plane.
			 Returns True if it is.
			 Returns False if it isn't.                             */
		bool isRairborne(int plane_)
		{
			bool temp = false;

			switch (plane_)
			{
				case 1:
					for (int i = 0; i < Y_DIM; i++)
					{
						for (int j = 0; j < X_DIM; j++)
						{
							if (grid[j][i].isRecon() == 1)
							{temp = true;}
						}
					}

					break;

				case 2:
					for (int i = 0; i < Y_DIM; i++)
					{
						for (int j = 0; j < X_DIM; j++)
						{
							if (grid[j][i].isRecon() == 2)
							{temp = true;}
						}
					}
					break;

				default:
					break;
			}

			return temp;
		}


};

