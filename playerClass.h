#pragma once



#include "boardClass.h"



class player
{
	private:
		//   The Enemy's Home Grid & the Player's Target Grid
		board gameBoard;


		/*   Keeps track of which player ships still have HP 
			 true = Alive
			 false = Destroyed                          */
		bool ACHP, BAHP, DRHP, SBHP, PBHP;


		/*   Keeping track of the status of the Player's Recon Planes 
			 0 = Destroyed
			 1 = Grounded
			 2 = Airborne                                             */
		int recon1, recon2;


		//   Missile amounts for the ships
		int ACmssls, BAmssls, DRmssls, SBmssls;


		//   Player Name
		string name;


		//   List of confirmed coordinates


	public:
		//   Constructor to create a Player with ability to set custom special missile amounts
		player(string name_, int ACmssls_, int BAmssls_, int DRmssls_, int SBmssls_)
		{
			name = name_;
			ACHP = true;
			BAHP = true;
			DRHP = true;
			SBHP = true;
			PBHP = true;
			recon1 = true;
			recon2 = true;

			ACmssls = ACmssls_;
			BAmssls = BAmssls_;
			DRmssls = DRmssls_;
			SBmssls = SBmssls_;
		}

		~player()
		{}

		/*   Attacks the Player's Target Grid & the Enemy's Home Grid, using Attack Type, Coordinates, 
			 and Fire Pattern as parameters. 
			 Returns 1 if a Ship Bit was hit, and adds a Hit Marker in its place.
			 Returns 2 if a Recon1 Bit was hit as well.
			 Returns 3 if a Recon2 Bit was hit instead.
			 Returns 4 if both Recon Bits were hit.
			 Returns 0 otherwise.
			 Returns -1 if any of the coordinates are out of bounds, or an invalid Firing Pattern is selected. */
		int attack(int atkType_, int xAtk_, int yAtk_, int firePattern_)
		{
			int result = -1;

			switch (atkType_)
			{
				case 1:
					result = gameBoard.Battack(xAtk_, yAtk_);
					break;

				case 2:
					result = gameBoard.DRattack(xAtk_, yAtk_, firePattern_);
					break;

				case 3:
					result = gameBoard.SBattack(xAtk_, yAtk_, firePattern_);
					break;

				case 4:
					result = gameBoard.ACattack(xAtk_, yAtk_, firePattern_);
					break;

				case 5:
					result = gameBoard.BSattack(xAtk_, yAtk_);
					break;
			}

			return result;
		}

		/*   Launches an Anti-air attack on the Player's Target Grid & the Enemy's Home Grid.
			 Returns 1 if a Recon 1 was hit.
			 Returns 2 if a Recon 2 was hit instead.
			 Returns 0 otherwise.
			 Returns -1 if the attacking coordinate is out of bounds.                         */
		int AAattack(int xAtk_, int yAtk_)
		{return gameBoard.AAattack(xAtk_, yAtk_);}



		/*   Performs a scan with the Submarine, using coordinates as the parameter.
			 The Scanning Pattern scans cells in a 3x3 square.
			 Returns 1 if a ship was detected, and adds Scan Markers in the area.
			 Returns 0 otherwise, and adds Miss Markers in the area.
			 Returns -1 if any of the coordinates are out of bounds.                 */
		int SBscan(int xScn_, int yScn_)
		{return gameBoard.SBscan(xScn_, yScn_);}

		/*   Performs a scan with a Recon Plane, using coordinates and scanning pattern as the parameters.
			 Scanning Pattern 1 scans cells in an X-pattern, without the center. Scanning Pattern 2 scans a +-pattern.
			 Returns a vector containing scnCoord objects, which contain the coordinates of the located ships if they were detected,
			 and adds Scan Markers on the detected cells along with Miss Markers on the empty cells.
			 Returns a vector of size 0 if nothing was detected otherwise, and adds Miss Markers on the scanned cells.
			 Returns a vector of size 5 if any of the coordinates are out of bounds, or an invalid Scanning Pattern is selected.     */
		vector<scnCoord> RPscan(int xScn_, int yScn_, int scanPattern_)
		{return gameBoard.RPscan(xScn_, yScn_, scanPattern_);}


		/*   Returns whether the enemy is still alive.
			 Returns True if the player still has ships that are alive.
			 Returns False if the player has no ships left alive.       */
		bool isAlive()
		{return (ACHP || BAHP || DRHP || SBHP || PBHP);}




		//   Sets the Enemy's Home Grid & the Player's Target Grid
		void setShipConfig(int config_)
		{gameBoard.preConfigShips(config_);}

		//   Returns the Player's Home Grid
		board getBoard()
		{return gameBoard;}

		//   Displays the Player's Target Grid
		void dispTargetGrid()
		{gameBoard.displayTgrid();}

		//   Displays the Enemy's Home Grid
		void dispHomeGrid()
		{gameBoard.displayHgrid();}

		//   Returns the Player's name
		string getName()
		{return name;}



		//   Returns the amount of missiles the Aircraft Carrier has
		int getACatks()
		{return ACmssls;}

		//   Reduces the amount of Aircraft Carrier missiles by 1, used for attacking
		void useACatk()
		{ACmssls--;}

		//   Returns whether the Aircraft Carrier is still alive
		bool isACalive()
		{return ACHP;}

		//   Marks the Aircraft Carrier as destroyed
		void destroyAC()
		{ACHP = false;}



		//   Returns the amount of missiles the Battleship has
		int getBAatks()
		{return BAmssls;}

		//   Reduces the amount of Battleship missiles by 1, used for attacking
		void useBAatk()
		{BAmssls--;}

		//   Returns whether the Battleship is still alive
		bool isBAalive()
		{return BAHP;}

		//   Marks the Battleship as destroyed
		void destroyBA()
		{BAHP = false;}



		//   Returns the amount of missiles the Destroyer has
		int getDRatks()
		{return DRmssls;}

		//   Reduces the amount of Destroyer missiles by 1
		void useDRatk()
		{DRmssls--;}

		//   Returns whether the Destroyer is still alive
		bool isDRalive()
		{return DRHP;}

		//   Marks the Destroyer as destroyed
		void destroyDR()
		{DRHP = false;}



		//   Returns the amount of torpedoes the Submarine has
		int getSBatks()
		{return SBmssls;}

		//   Reduces the amount of Submarine torpedoes by 1
		void useSBatk()
		{SBmssls--;}

		//   Returns whether the Submarine is still alive
		bool isSBalive()
		{return SBHP;}

		//   Marks the Submarine as destroyed
		void destroySB()
		{SBHP = false;}



		//   Returns whether the Patrol Boat is still alive
		bool isPBalive()
		{return PBHP;}

		//   Marks the Patrol Boat as destroyed
		void destroyPB()
		{PBHP = false;}



		//   Returns whether the requested Recon plane is still alive
		bool isReconAlive(int plane_)
		{
			bool temp = false;

			switch (plane_)
			{
				//   Checking if Recon 1 is alive
				case 1:
					if (recon1 != 0)
					{temp = true;}

					break;

				//   Checking if Recon 2 is alive
				case 2:
					if (recon2 != 0)
					{temp = true;}

					break;
			}

			return temp;
		}

		//   Marks the chosen Recon plane as destroyed
		void destroyRecon(int plane_)
		{
			switch (plane_)
			{
				case 1:
					recon1 = false;
					break;

				case 2:
					recon2 = false;
					break;
					
				default:
					break;
			}
		}

		/*   Deploys or moves the chosen Recon plane to the chosen coordinates.
			 Scans the board to perform the operation.
			 Returns True if the operation was successful.
			 Returns False if another plane occpuies the spot.                 */
		bool mveRecon(int x_, int y_, int plane_)
		{return gameBoard.moveRecon(x_, y_, plane_);}

		/*   Returns whether the requested recon plane is airborne.
			 Scans the board to find the requested plane.
			 Returns True if it is.
			 Returns False if it isn't.                             */
		bool isReconAirBrn(int plane_)
		{return gameBoard.isRairborne(plane_);}

		/*   Finds the coordinates of the requested Recon Plane.
			 Returns a scnCoord object with the coordinates if it was able to find it.
			 Returns a scnCoord object with the coordinates (-1, -1) if the plane was not found. */
		scnCoord getRPcoord(int plane_)
		{return gameBoard.getRPcoord(plane_);}



		/*   Returns which ship is on the cell.
			 Returns 1 if an Aircraft Carrier is on the cell.
			 Returns 2 if a Battleship is found.
			 Returns 3 if a Destroyer is found instead.
			 Returns 4 if a Submarine is there.
			 Returns 5 if a Patrol Boat is found.             */
		int getShipFromPlayer(int x_, int y_)
		{return gameBoard.getShipFromBoard(x_, y_);}





};

