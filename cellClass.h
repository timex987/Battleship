#pragma once



#include <iostream>
#include <vector>
using namespace std;



//   Custom Class that makes up the individual cells of the Battleship Grids
class cell
{
	private:
		enum mark { none, hit, miss };
		enum shipBit { empty, destroyed, Aircraft_Carrier, Battleship, Destroyer, Submarine, Patrol_Boat };
		enum reconBit { absent, Recon1, G_Recon1, Recon2, G_Recon2 };
		enum scanMark { blank, normalScan, trueScan };

		/*   Keeps track of the presence of a Hit/Miss Marker on the cell, if there is one
			 (0 = none, 1 = hit, 2 = miss)                                                 */
		mark marker;			
	
		/*   Keeps track of which Ship Bit is on the cell, if there is one
			 (0 = empty, 1 = destroyed, 2 = Aircraft_Carrier, 3 = Battleship, 4 = Destroyer, 5 = Submarine, 6 = Patrol_Boat)   */
		shipBit shipPart;		

		/*   Keeps track of which Recon Bit is in the cell's airspace, if there is one
			 (0 = absent, 1 = Recon1, 2 = G_Recon1, 3 = Recon2, 4 = G_Recon2)          */
		reconBit aircraft;

		/*   Keeps track of the presence of a Scan Marker on the cell, if there is one 
			 ( 0 = blank, 1 = scan, 2 = trueScan)                                       */
		scanMark scanMarker;			
	

	public:

		//   Initializes an empty cell.
		cell()
		{
			marker = none;
			shipPart = empty;
			aircraft = absent;
			scanMarker = blank;
		}

		~cell()
		{}


		/*   Adds a Ship Bit to the cell. 
			 0 = empty
			 1 = Aircraft Carrier
			 2 = Battleship
			 3 = Destroyer
			 4 = Submarine
			 5 = Patrol Boat              */
		void setShipBit(int bit_)
		{
			switch (bit_)
			{
				case 1:
					shipPart = Aircraft_Carrier;
					break;

				case 2:
					shipPart = Battleship;
					break;

				case 3:
					shipPart = Destroyer;
					break;

				case 4:
					shipPart = Submarine;
					break;

				case 5:
					shipPart = Patrol_Boat;
					break;

				default:
					break;
			}
		}


		/*   Adds a Grounded Recon Plane to the cell.
			 1 = Recon 1
			 2 = Recon 2                              */
		void setReconBit(int bit_)
		{
			switch (bit_)
			{
				case 1:
					aircraft = G_Recon1;
					break;

				case 2:
					aircraft = G_Recon2;
					break;

				default:
					break;
			}
		}


		/*   Used for detecting recon collisions.
			 Returns True if there is a Grounded Recon Bit on the cell.
			 Returns False otherwise.                                   */
		bool isGRecon()
		{
			bool temp = true;

			switch (aircraft)
			{
				case G_Recon1:
					break;

				case G_Recon2:
					break;

				default:
					temp = false;
					break;
			}

			return temp;
		}


		/*   Checks to see which aerial Recon plane is on the cell.
			 Returns 1 if Recon 1 is there.
			 Returns 2 if Recon 2 is there instead.
			 Returns 0 otherwise.                                   */
		int isRecon()
		{
			int temp = 0;
			
			switch (aircraft)
			{
				case Recon1:
					temp = 1;
					break;

				case Recon2:
					temp = 2;
					break;

				default:
					break;
			}

			return temp;
		}


		/*   Checks to see if the cell has battle marks on it.
			 Returns True if there is a battle mark on it.
			 Returns False otherwise.                             */
		bool isBmark()
		{
			bool temp = false;

			switch (marker)
			{
				case none:
					switch (scanMarker)
					{
						case blank:
							break;

						default:
							temp = true;
							break;
					}
					
					break;

				default:
					temp = true;
					break;
			}

			return temp;
		}

		
		/*   Deploys a Grounded Recon Plane. 
			 Returns True if the operation was successful.
			 Returns False otherwise.                      */
		bool deployRecon(int reconChoice_)
		{
			bool temp = true;

			switch (reconChoice_)
			{
				case 1:
					if (aircraft == G_Recon1)
					{aircraft = Recon1;}
					break;

				case 2:
					if (aircraft == G_Recon2)
					{aircraft = Recon2;}
					break;

				default:
					temp = false;
					break;
			}

			return temp;
		}


		/*   Moves a Recon Plane to its new location, by marking it as occupied by
			 the requested plane. 
			 Returns True if the movement was successful.
			 Returns False if another plane occpuies the spot.                     */
		bool newReconPos(int reconChoice_)
		{
			bool temp = false;

			if (aircraft == empty)
			{
				switch (reconChoice_)
				{
					case 1:
						aircraft = Recon1;
						break;

					case 2:
						aircraft = Recon2;
						break;

					default:
						break;
				}

				temp = true;
			}

			return temp;
		}


		/*   Adds a Scan Mark to the cell. Used for scanning. 
			 A parameter of 1 sets a Normal Scan Mark.
			 A parameter of 2 sets a True Scan Mark.          */
		void setScan(int type_)
		{
			switch (type_)
			{
				case 1:
					scanMarker = normalScan;
					break;

				case 2:
					scanMarker = trueScan;
					break;
			}
		}


		//   Adds a Miss Mark to the cell.
		void setMiss()
		{marker = miss;}


		/*   Launches an attack on the cell. Removes Scan Marks.
			 Returns 1 if a Ship Bit is on there, destroys it, and adds a Hit Marker in its place.
			 Returns 2 if a Recon1 Bit was on the cell as well.
			 Returns 3 if a Recon2 Bit was on the cell instead.
			 Returns 0 otherwise, and adds a Miss Marker.                                          */
		int attack()
		{
			int landedAttack = 0;
			scanMarker = blank;

			switch (shipPart)
			{
				case empty:
					marker = miss;
					break;

				case destroyed:
					break;

				default:
					landedAttack = 1;
					marker = hit;
					shipPart = destroyed;

					switch (aircraft)
					{
						case G_Recon1:
							landedAttack = 2;
							aircraft = absent;
							break;

						case G_Recon2:
							landedAttack = 3;
							aircraft = absent;
							break;

						default:
							break;
					}

					break;
			}

			return landedAttack;
		}


		/*   Launches an anti-air attack on the cell. 
			 Returns 1 if a Recon1 Bit is in its airspace, and destroys it.
			 Returns 2 if a Recon2 Bit is present instead, and destroys it. 
			 Returns 0 otherwise.                                           */
		int AAatk()
		{
			int landedAAattack = 0;

			switch (aircraft)
			{
				case Recon1:
					landedAAattack = 1;
					aircraft = absent;
					break;

				case Recon2:
					landedAAattack = 2;
					aircraft = absent;
					break;

				default:
					break;
			}

			return landedAAattack;
		}


		/*   Scans the cell for ship presence. 
			 Returns True if a Ship Bit is on there. 
			 Returns False otherwise.                */
		bool scan()
		{
			bool scanResult = false;

			switch (shipPart)
			{
				case empty:
					break;

				case destroyed:
					break;

				default:
					scanResult = true;
					break;
			}

			return scanResult;
		}
	

		//   Displays the status of the cell.
		void display()
		{
			switch (scanMarker)
			{
				case blank:
					switch (marker)
					{
						case hit:
							cout << " X ";
							break;

						case miss:
							cout << " O ";
							break;

						default:
							cout << "   ";
							break;
					}

					break;

				case trueScan:
					cout << " # ";
					break;

				default:
					cout << " + ";
					break;
			}
		}


		//   Displays the Ship Bit on the cell, if there is any.
		void displayShipBit()
		{
			switch (shipPart)
			{
				case Aircraft_Carrier:
					switch (aircraft)
					{
						case G_Recon1:
							cout << "1A1";
							break;

						case G_Recon2:
							cout << "2A2";
							break;

						case Recon1:
							cout << "RA1";
							break;

						case Recon2:
							cout << "RA2";
							break;

						default:
							cout << " A ";
							break;
					}
				
					break;
			
				case Battleship:
					switch (aircraft)
					{
						case Recon1:
							cout << "RB1";
							break;

						case Recon2:
							cout << "RB2";
							break;

						default:
							cout << " B ";
							break;
					}

					break;

				case Destroyer:
					switch (aircraft)
					{
						case Recon1:
							cout << "RD1";
							break;

						case Recon2:
							cout << "RD2";
							break;

						default:
							cout << " D ";
							break;
					}

					break;

				case Submarine:
					switch (aircraft)
					{
						case Recon1:
							cout << "RS1";
							break;

						case Recon2:
							cout << "RS2";
							break;

						default:
							cout << " S ";
							break;
					}

					break;

				case Patrol_Boat:
					switch (aircraft)
					{
						case Recon1:
							cout << "RP1";
							break;

						case Recon2:
							cout << "RP2";
							break;

						default:
							cout << " P ";
							break;
					}

					break;

				default:
					switch (aircraft)
					{
						case Recon1:
							cout << "R 1";
							break;

						case Recon2:
							cout << "R 2";
							break;

						default:
							cout << "   ";
							break;
					}

					break;
			}
		}


		/*   Used for placing Recon Planes.
			 Returns True if there is an Aircraft Carrier on the cell.
			 Returns False otherwise.                                  */
		bool isAC()
		{
			bool temp = true;

			switch (shipPart)
			{
				case Aircraft_Carrier:
					break;

				default:
					temp = false;
					break;
			}

			return temp;
		}

	
		/*   Returns which ship is on the cell. 
			 Returns 1 if an Aircraft Carrier is on the cell.
			 Returns 2 if a Battleship is found.
			 Returns 3 if a Destroyer is found instead.
			 Returns 4 if a Submarine is there.
			 Returns 5 if a Patrol Boat is found.
			 Returns 0 if no ship is on the cell.             */
		int getShip()
		{
			int temp = 0;

			switch (shipPart)
			{
				case Aircraft_Carrier:
					temp = 1;
					break;

				case Battleship:
					temp = 2;
					break;

				case Destroyer:
					temp = 3;
					break;

				case Submarine:
					temp = 4;
					break;

				case Patrol_Boat:
					temp = 5;
					break;
			}

			return temp;
		}


};


//   Custom Struct Type that handles coordinates
struct scnCoord
{
	int x, y;

	scnCoord()
	{
		x = -1;
		y = -1;
	}

	//   Constructor that creates a new scnCoord object with the parameters
	scnCoord(int x_, int y_)
	{
		x = x_;
		y = y_;
	}

	//   Displays the coordinates in the object in human-readable form
	void display()
	{
		switch (x)
		{
			case 0:
				cout << "A";
				break;

			case 1:
				cout << "B";
				break;

			case 2:
				cout << "C";
				break;

			case 3:
				cout << "D";
				break;

			case 4:
				cout << "E";
				break;

			case 5:
				cout << "F";
				break;

			case 6:
				cout << "G";
				break;

			case 7:
				cout << "H";
				break;

			case 8:
				cout << "I";
				break;

			case 9:
				cout << "J";
				break;

			case 10:
				cout << "K";
				break;

			case 11:
				cout << "L";
				break;

			case 12:
				cout << "M";
				break;

			case 13:
				cout << "N";
				break;
		}

		cout << y + 1;
	}
};

