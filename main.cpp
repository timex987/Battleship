#include "gameEngineFunction.h"
#include "fencrypt.h"




int main()
{
	int menuOption = -1;
	int subMenuOption = 4;
	int subSubMenuOption = 4;
	int P1choice = -1;
	int P2choice = -1;
	bool configExists = false;
	const string KEY = "r4(6YYkc#d,!m7Zba?[e|`3p)^h8";
	vector<board> shipConfigs;
	string readIn, tempName1, tempName2;
	ifstream in;


	//   Importing the stock ship configurations
	for (int i = 0; i < 30; i++)
	{
		board tempConfig;

		tempConfig.preConfigShips(i + 1);

		shipConfigs.push_back(tempConfig);
	}

	//   Open custom ship config file, decode it, and read the contents, if it exists
	in.open("shipconfig.dat");

	if (in.is_open())
	{
		getline(in, readIn);

		if (decrypt(readIn, KEY) == "THISfileISforBATTLESHIP")
		{
			configExists = true;



		}
	}

	else
	{

	}


	


	

	//   Need to work on opening the file & decoding first line
	//   to check for file existence and integrity before reading










	//   Displays the Main Title Screen
	dispTitle();
	cout << "                                               Press Enter to start..." << endl;
	cin.get();
	

	//   Display transitional space
	dispTransition();

	//   Handle the input from the main menu
	while (subMenuOption == 4 || subSubMenuOption == 4)
	{
		//   Display Main Menu and gather menu input
		dispMainMenuGraphic();
		cout << "                  Selection: ";
		cin >> menuOption;

		//   Invalid input
		while (!intValidCheck(menuOption, 1, 5))
		{
			cout << "\n                                  !!!       Invalid Input. Please try again.       !!!\n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n";
			cout << "                  Selection: ";
			cin >> menuOption;
		}

		cout << "\n" << endl;

		switch (menuOption)
		{
			//   Start a New Game
			case 1:
			{
				//   Display connection mode menu & gather input
				dispConnModeMenu();
				cout << "                  Selection: ";
				cin >> subMenuOption;

				//   Invalid input
				while (!intValidCheck(subMenuOption, 1, 4))
				{
					cout << "\n                                  !!!       Invalid Input. Please try again.       !!!\n" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n";
					cout << "                  Selection: ";
					cin >> subMenuOption;
				}

				cout << "\n" << endl;

				//   Enter chosen connection mode
				switch (subMenuOption)
				{
					//   Hotseat Mode
					case 1:
					{
						//   Display game type menu & gather input
						dispCreateGameMenuHotseat();
						cout << "                  Selection: ";
						cin >> subSubMenuOption;

						//   Invalid input
						while (!intValidCheck(subSubMenuOption, 1, 4))
						{
							cout << "\n                                  !!!       Invalid Input. Please try again.       !!!\n" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "\n";
							cout << "                  Selection: ";
							cin >> subSubMenuOption;
						}

						cout << "\n\n" << endl;

						//   If the player didn't cancel the action, continue
						if (subSubMenuOption != 4)
						{
							string tempConfirm = "invalid";
							bool validChoice = false;
							bool finalChoice = false;

							//   Get Player 1's name & desired ship configuration
							cout << "\n\n                  Player 1, enter your name: ";
							cin >> tempName1;

							cout << "\n" << endl;

							while (!finalChoice)
							{
								cout << "\n\n                  Enter in a Configuration Number from 1 - " << shipConfigs.size() << ": ";
								cin >> P2choice;

								//   Invalid input
								while (!intValidCheck(P2choice, 1, shipConfigs.size()))
								{
									cout << "\n                                  !!!       Invalid Input. Please try again.       !!!\n" << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n";
									cout << "                  Selection: ";
									cin >> P2choice;
								}

								cout << "\n\n\n                  Configuration " << P2choice << ": ";

								shipConfigs[P2choice - 1].displayHgrid();

								cout << "\n\n                  Is this your choice? (Y/N): ";
								cin >> tempConfirm;

								//   Verifying valid input
								while (!validChoice)
								{
									if (tempConfirm == "y" || tempConfirm == "Y" || tempConfirm == "n" || tempConfirm == "N")
									{
										validChoice = true;
									}

									else
									{
										cout << "\n                                  !!!       Invalid Input. Please try again.       !!!\n" << endl;

										cout << "                  Is this your choice? (Y/N): ";
										cin >> tempConfirm;
									}
								}

								if (tempConfirm == "y" || tempConfirm == "Y")
								{
									finalChoice = true;
								}
							}

							//   Resetting parameters for player 2 to enter in their choices
							tempConfirm = "invalid";
							validChoice = false;
							finalChoice = false;

							dispTransition();
							dispTransition();
							dispTransition();
							dispTransition();
							dispTransition();
							dispTransition();
							dispTransition();
							dispTransition();
							dispTransition();
							dispTransition();
							dispTransition();

							//   Get Player 2's name & desired ship configuration
							cout << "\n\n                  Player 2, enter your name: ";
							cin >> tempName2;

							cout << "\n" << endl;

							while (!finalChoice)
							{
								cout << "\n\n                  Enter in a Configuration Number from 1 - " << shipConfigs.size() << ": ";
								cin >> P1choice;

								//   Invalid input
								while (!intValidCheck(P1choice, 1, shipConfigs.size()))
								{
									cout << "\n                                  !!!       Invalid Input. Please try again.       !!!\n" << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n";
									cout << "                  Selection: ";
									cin >> P1choice;
								}

								cout << "\n\n\n                  Configuration " << P1choice << ": ";

								shipConfigs[P1choice - 1].displayHgrid();

								cout << "\n\n                  Is this your choice? (Y/N): ";
								cin >> tempConfirm;

								//   Verifying input
								while (!validChoice)
								{
									if (tempConfirm == "y" || tempConfirm == "Y" || tempConfirm == "n" || tempConfirm == "N")
									{
										validChoice = true;
									}

									else
									{
										cout << "\n                                  !!!       Invalid Input. Please try again.       !!!\n" << endl;

										cout << "                  Is this your choice? (Y/N): ";
										cin >> tempConfirm;
									}
								}

								if (tempConfirm == "y" || tempConfirm == "Y")
								{
									finalChoice = true;
								}
							}

							//   Resetting parameters
							tempConfirm = "invalid";
							validChoice = false;
							finalChoice = false;
						}

						cout << "\n\n" << endl;

						//   Starting the game with the gathered parameters
						switch (subSubMenuOption)
						{
							//   Normal Battle
							case 1:
							{
								gameEngine(subMenuOption, tempName1, P1choice, tempName2, P2choice, 0, 0, 0, 0);
								break;
							}

							//   Advanced Battle
							case 2:
							{
								gameEngine(subMenuOption, tempName1, P1choice, tempName2, P2choice, 2, 1, 2, 2);
								break;
							}

							//   Blitz Battle
							case 3:
							{
								gameEngine(subMenuOption, tempName1, P1choice, tempName2, P2choice, 99, 99, 99, 99);
								break;
							}

							//   Back
							case 4:
							{
								break;
							}

							default:
								break;
						}

						break;
					}

					//   Online Mode
					case 2:
					{
						cout << "                  Online Mode is in development!\n" << endl;
						cout << "                  Press Enter to continue..." << endl;
						cin.get();
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n";

						break;
					}

					//   Versus CPU Mode
					case 3:
					{
						cout << "                  Versus CPU Mode is in development!\n" << endl;
						cout << "                  Press Enter to continue..." << endl;
						cin.get();
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n";

						break;
					}

					//   Back
					case 4:
					{



						break;
					}

					default:
						break;
				}
			}

			//   Load a Saved Game
			case 2:
			{
				break;
			}

			//   Ship Configuration Editor
			case 3:
			{
				cout << "\n                                 ========================================================" << endl;
				cout << "                                 ===             Ship Configuration Editor            ===" << endl;
				cout << "                                 ========================================================\n" << endl;
				cout << "                                            1. Create a Custom Configuration\n" << endl;
				cout << "                                            2. View/Edit Custom Configurations\n" << endl;
				cout << "                                            3. Back\n" << endl;


				//   Need to work on the custom ship config editor








				break;
			}

			//   Credits
			case 4:
			{
				break;
			}

			//   Quit
			case 5:
			{
				subMenuOption = 5;
				subSubMenuOption = 5;
			}
				break;

			default:

				break;
		}

	}

	
	
	



	cout << "                  Press Enter to close the game..." << endl;
	cin.get();
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n";

	return 0;
}