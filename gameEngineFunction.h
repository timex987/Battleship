#pragma once



#include <sstream>
#include <fstream>
#include <chrono>
#include <thread>
#include "playerClass.h"
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;



/*   Function that handles the gameplay modes.
	 1 = Hotseat Mode
	 2 = Online Mode
	 3 = Versus CPU Mode                       */
void gameEngine(int mode_, string P1name_, int _P1config, string P2name_, int _P2config, int maxACmssls_, int maxBAmssls_, int maxDRmssls_, int maxSBmssls_)
{
	dispTransition();
	dispTransition();
	dispTransition();
	dispTransition();
	dispBig3();
	sleep_until(system_clock::now() + 1s);
	dispBig2();
	sleep_until(system_clock::now() + 1s);
	dispBig1();
	sleep_until(system_clock::now() + 1s);
	dispBattleStartGraphic();
	sleep_until(system_clock::now() + 2s);
	dispTransition();
	dispTransition();
	dispTransition();
	dispTransition();

	player P1(P1name_, maxACmssls_, maxBAmssls_, maxDRmssls_, maxSBmssls_);
	P1.setShipConfig(_P1config);

	player P2(P2name_, maxACmssls_, maxBAmssls_, maxDRmssls_, maxSBmssls_);
	P2.setShipConfig(_P2config);

	string winner, loser;
	bool surrender = false;


	//   Handles game mode selection.
	switch (mode_)
	{
		//   Option 1: Hotseat Mode
		case 1:
		{
			int turnCounter = 1;							//   Keeps track of whose turn it is. 1 = Player 1, 2 = Player 2

			int choice = -1;								//   Keeps track of the main action choice.

			int subChoice = -1;								//   Keeps track of the sub-action choice.

			int subsubChoice = -1;							//   Keeps track of the sub-sub-action choice.

			int xAttack = -1;								//   Keeps track of the x-coordinate for attacking/scanning.

			int yAttack = -1;								//   Keeps track of the y-coordinate for attacking/scanning.

			int attackResult = -1;							//   Keeps track of the results of the attack/scan.

			int tempACHP = 0;								//   A temporary variable used to calculate remaining Aircraft Carrier HP.

			int tempBAHP = 0;								//   A temporary variable used to calculate remaining Battleship HP.

			int tempDRHP = 0;								//   A temporary variable used to calculate remaining Destroyer HP.

			int tempSBHP = 0;								//   A temporary variable used to calculate remaining Submarine HP.

			int tempPBHP = 0;								//   A temporary variable used to calculate remaining Patrol Boat HP.

			string atkCoord = "";							//   Provides a way to capture coordinate input.

			char xLetter;									//   Provides a way to process the x-coordinate of the input.

			bool endTurn = false;							//   Keeps track of the end of the turn.

			bool endGame = false;							//   Keeps track of the end of the game.

			bool invalidInput = true;						//   Keeps track of any invalid inputs.

			bool subInvalidInput = true;					//   Keeps track of any invalid sub-inputs.

			bool moveResult = false;						//   Keeps track of the success of Recon Plane movements.

			stringstream ss;								//   Provides a way to process coordinate input.

			vector<scnCoord> RPscanResult;					//   Provides a way to store confirmed coordinates of scanned ships.


			//   The entire game takes place in this loop, until the end-of-game condition has been met
			while (!endGame)
			{
				choice = 0;
				subChoice = 0;
				endTurn = false;


				//   Display the intro turn text
				switch (turnCounter)
				{
					case 1:
					{
						dispTurnStart(1);
						break;
					}

					case 2:
					{
						dispTurnStart(2);
						break;
					}
				}

				
				/*   Gather action input & perform selected action
					 1 = Display Target Grid
					 2 = Attack Actions
					 3 = Scan Actions
					 4 = Movement Actions        */
				while (!endTurn)
				{
					//   Prompt for an action
					dispPlayerMenu();


					//   Gather user input & validation
					cin >> choice;
					cout << endl;

					//   Invalid input
					while (!intValidCheck(choice, 1, 5))
					{
						cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n";
						cout << "     Selection: ";
						cin >> choice;
					}

					cout << endl;


					//   Handle the input
					switch (choice)
					{
						//   Display the Target Grid
						case 1:
						{
							cout << "\n   =================================================" << endl;
							cout << "   ===          Display the Target Grid          ===" << endl;
							cout << "   =================================================\n" << endl;
							cout << "     O = Miss" << endl;
							cout << "     X = Hit" << endl;
							cout << "     + = Scanned Cell" << endl;
							cout << "     # = Confirmed Scanned Cell" << endl;

							switch (turnCounter)
							{
								case 1:
									P1.dispTargetGrid();
									// P2.dispHomeGrid();    Commented out to prevent the other player from seeing the current player's configuration
									break;

								case 2:
									P2.dispTargetGrid();
									// P1.dispHomeGrid();    Commented out to prevent the other player from seeing the current player's configuration
									break;
							}

							cout << endl;

							break;
						}

						//   Attack Actions
						case 2:
						{
							//   Display the various attack options
							cout << "\n   =================================================" << endl;
							cout << "   ===              Launch an Attack             ===" << endl;
							cout << "   =================================================\n" << endl;
							cout << "     Choose an attack method.\n" << endl << endl;

							cout << "   1. Basic Attack: Attacks a single cell.\n" << endl;
							dispBattackFP();


							//   If the player has special missile attacks left, or if the ships are still alive, they will be shown
							switch (turnCounter)
							{
								case 1:
								{
									//   For the Destroyer
									if (P1.getDRatks() > 0 && P1.isDRalive() == true)
									{
										cout << "   2. Destroyer Apache Missile: Attacks cells in a 3x1 or a 1x3 shape." << endl;
										cout << "      Missiles Remaining: " << P1.getDRatks() << "/" << maxDRmssls_ << endl << endl;
										dispDRattackFP();
									}

									//   For the Submarine
									if (P1.getSBatks() > 0 && P1.isSBalive() == true)
									{
										cout << "   3. Submarine Torpedo: Attacks cells starting from an edge of the board, firing towards the center." << endl;
										cout << "      Missiles Remaining: " << P1.getSBatks() << "/" << maxSBmssls_ << endl << endl;
										dispSBattackFP();
									}

									//   For the Aircraft Carrier
									if (P1.getACatks() > 0 && P1.isACalive() == true)
									{
										cout << "   4. Aircraft Carrier Exocet Missile: Attacks cells in an X-shape formation, or a +-shape formation." << endl;
										cout << "      Missiles Remaining: " << P1.getACatks() << "/" << maxACmssls_ << endl << endl;
										dispACattackFP();
									}

									//   For the Battleship
									if (P1.getBAatks() > 0 && P1.isBAalive() == true)
									{
										cout << "   5. Battleship Tomahawk Missile: Attacks cells in a 3x3 formation." << endl;
										cout << "      Missiles Remaining: " << P1.getBAatks() << "/" << maxBAmssls_ << endl << endl;
										dispBAattackFP();
									}

									break;
								}

								case 2:
								{
									//   For the Destroyer
									if (P2.getDRatks() > 0 && P2.isDRalive() == true)
									{
										cout << "   2. Destroyer Apache Missile: Attacks cells in a 3x1 or a 1x3 shape." << endl;
										cout << "      Missiles Remaining: " << P2.getDRatks() << "/" << maxDRmssls_ << endl << endl;
										dispDRattackFP();
									}

									//   For the Submarine
									if (P2.getSBatks() > 0 && P2.isSBalive() == true)
									{
										cout << "   3. Submarine Torpedo: Attacks cells starting from an edge of the board, firing towards the center." << endl;
										cout << "      Missiles Remaining: " << P2.getSBatks() << "/" << maxSBmssls_ << endl << endl;
										dispSBattackFP();
									}

									//   For the Aircraft Carrier
									if (P2.getACatks() > 0 && P2.isACalive() == true)
									{
										cout << "   4. Aircraft Carrier Exocet Missile: Attacks cells in an X-shape formation, or a +-shape formation." << endl;
										cout << "      Missiles Remaining: " << P2.getACatks() << "/" << maxACmssls_ << endl << endl;
										dispACattackFP();
									}

									//   For the Battleship
									if (P2.getBAatks() > 0 && P2.isBAalive() == true)
									{
										cout << "   5. Battleship Tomahawk Missile: Attacks cells in a 3x3 formation." << endl;
										cout << "      Missiles Remaining: " << P2.getBAatks() << "/" << maxBAmssls_ << endl << endl;
										dispBAattackFP();
									}

									break;
								}
							}

							cout << "   6. Cancel Action: Cancel the attack & return to the player menu.\n" << endl << endl;
							cout << "     Selection: ";


							//   Gather user input & validation
							cin >> subChoice;
							cout << endl;

							/*   Check to see if the player has enough special attacks to perform & 
								 whether the requested ship is still alive                          */
							while (subInvalidInput)
							{
								switch (subChoice)
								{
									//   Basic Attacks
									case 1:
										subInvalidInput = false;
										break;

									//   Destroyer Attacks
									case 2:
										switch (turnCounter)
										{
											case 1:
											{
												if (P1.getDRatks() > 0 && P1.isDRalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Out of Apache Missiles!       !!!\n" << endl;}

												break;
											}

											case 2:
											{
												if (P2.getDRatks() > 0 && P2.isDRalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Out of Apache Missiles!       !!!\n" << endl;}

												break;
											}
										}

										break;

									//   Submaraine Attacks
									case 3:
										switch (turnCounter)
										{
											case 1:
											{
												if (P1.getSBatks() > 0 && P1.isSBalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Out of Torpedoes!       !!!\n" << endl;}

												break;
											}

											case 2:
											{
												if (P2.getSBatks() > 0 && P2.isSBalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Out of Torpedoes!       !!!\n" << endl;}

												break;
											}
										}

										break;

									//   Aircraft Carrier Attacks
									case 4:
										switch (turnCounter)
										{
											case 1:
											{
												if (P1.getACatks() > 0 && P1.isACalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Out of Exocet Missiles!       !!!\n" << endl;}

												break;
											}

											case 2:
											{
												if (P2.getACatks() > 0 && P2.isACalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Out of Exocet Missiles!       !!!\n" << endl;}

												break;
											}
										}

										break;

									//   Battleship Attacks
									case 5:
										switch (turnCounter)
										{
											case 1:
											{
												if (P1.getBAatks() > 0 && P1.isBAalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Out of Tomahawk Missiles!       !!!\n" << endl;}

												break;
											}

											case 2:
											{
												if (P2.getBAatks() > 0 && P2.isBAalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Out of Tomahawk Missiles!       !!!\n" << endl;}

												break;
											}
										}

										break;

									case 6:
										subInvalidInput = false;
										break;

									default:
										cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
										break;
								}

								//   Invalid selection
								if (subInvalidInput)
								{
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n";
									cout << "     Selection: ";
									cin >> subChoice;
									cout << endl;
								}
							}

							cout << endl;

							//   Performing the action if the player didn't cancel the attack
							if (subChoice != 6)
							{
								//   Display attack selection
								switch (subChoice)
								{
									case 1:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---                Basic Attack               ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										break;
									}

									case 2:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---           Apache Missile Attack           ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										cout << "     Choose a Firing Pattern.\n" << endl;
										cout << "     > ";
										cin >> subsubChoice;

										while (!intValidCheck(subsubChoice, 1, 2))
										{
											cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "\n";
											cout << "     > ";
											cin >> subsubChoice;
										}

										cout << endl << endl;

										break;
									}

									case 3:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---               Torpedo Attack              ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										cout << "     Choose a Firing Pattern.\n" << endl;
										cout << "     > ";
										cin >> subsubChoice;

										while (!intValidCheck(subsubChoice, 1, 2))
										{
											cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "\n";
											cout << "     > ";
											cin >> subsubChoice;
										}

										cout << endl << endl;

										break;
									}

									case 4:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---           Exocet Missile Attack           ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										cout << "     Choose a Firing Pattern.\n" << endl;
										cout << "     > ";
										cin >> subsubChoice;

										while (!intValidCheck(subsubChoice, 1, 2))
										{
											cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "\n";
											cout << "     > ";
											cin >> subsubChoice;
										}

										cout << endl << endl;

										break;
									}

									case 5:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---          Tomahawk Missile Attack          ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										break;
									}
								}

								cout << "     Enter in the coordinate to attack.\n" << endl;
								cout << "     > ";
								cin >> atkCoord;


								/*   Determines if entered coordinate is valid. If it is, attacks with the chosen weapon.
									 If not, prompts for a new input                                                      */
								while (invalidInput)
								{
									//   Proceed if the user's input is 2 or 3 characters long
									if (atkCoord.length() > 1 && atkCoord.length() < 4)
									{
										//   Split the coordinate into an "x" value and a "y" value
										ss << atkCoord;
										ss >> xLetter;
										ss >> yAttack;
										ss.clear();
										ss.str("");


										//   Convert the "x" value to upper-case and subtract 1 off the "y" value
										xLetter = toupper(xLetter);
										yAttack--;


										/*   Check to see if the entered coordinates are valid. If they are, proceed with the attack.
											 If not, don't do anything                                                                */
										if (xLetter >= 'A' || xLetter <= 'N' || yAttack >= 0 || yAttack <= 9)
										{
											//   Convert the letter to its corresponding x-coordinate
											switch (xLetter)
											{
												case 'A':
													xAttack = 0;
													break;

												case 'B':
													xAttack = 1;
													break;

												case 'C':
													xAttack = 2;
													break;

												case 'D':
													xAttack = 3;
													break;

												case 'E':
													xAttack = 4;
													break;

												case 'F':
													xAttack = 5;
													break;

												case 'G':
													xAttack = 6;
													break;

												case 'H':
													xAttack = 7;
													break;

												case 'I':
													xAttack = 8;
													break;

												case 'J':
													xAttack = 9;
													break;

												case 'K':
													xAttack = 10;
													break;

												case 'L':
													xAttack = 11;
													break;

												case 'M':
													xAttack = 12;
													break;

												case 'N':
													xAttack = 13;
													break;

												default:
													xAttack = -1;
													break;
											}

											//   Perform the attack. If the result is -1, the chosen coordinate had invalid coordinate locations
											switch (subChoice)
											{
												//   Basic Attack
												case 1:
													//   Perform the attack on the enemy player
													switch (turnCounter)
													{
														case 1:
															attackResult = P1.attack(1, xAttack, yAttack, 0);
															break;

														case 2:
															attackResult = P2.attack(1, xAttack, yAttack, 0);
															break;
													}

													break;

												//   Destroyer Attack
												case 2:
													//   Perform the attack on the enemy player
													switch (turnCounter)
													{
														case 1:
															attackResult = P1.attack(2, xAttack, yAttack, subsubChoice);

															if (attackResult != -1)
															{P1.useDRatk();}

															break;

														case 2:
															attackResult = P2.attack(2, xAttack, yAttack, subsubChoice);

															if (attackResult != -1)
															{P2.useDRatk();}

															break;
													}

													break;

												//   Submarine Attack
												case 3:
													//   Perform the attack on the enemy player
													switch (turnCounter)
													{
														case 1:
															attackResult = P1.attack(3, xAttack, yAttack, subsubChoice);

															if (attackResult != -1)
															{P1.useSBatk();}

															break;

														case 2:
															attackResult = P2.attack(3, xAttack, yAttack, subsubChoice);

															if (attackResult != -1)
															{P2.useSBatk();}

															break;
													}

													break;

												//   Aircraft Carrier Attack
												case 4:
													//   Perform the attack on the enemy player
													switch (turnCounter)
													{
														case 1:
															attackResult = P1.attack(4, xAttack, yAttack, subsubChoice);

															if (attackResult != -1)
															{P1.useACatk();}

															break;

														case 2:
															attackResult = P2.attack(4, xAttack, yAttack, subsubChoice);

															if (attackResult != -1)
															{P2.useACatk();}

															break;
													}

													break;

												//   Battleship Attack
												case 5:
													//   Perform the attack on the enemy player
													switch (turnCounter)
													{
														case 1:
															attackResult = P1.attack(5, xAttack, yAttack, 0);

															if (attackResult != -1)
															{P1.useBAatk();}

															break;

														case 2:
															attackResult = P2.attack(5, xAttack, yAttack, 0);

															if (attackResult != -1)
															{P2.useBAatk();}

															break;
													}

													break;
											}

											//   Display the results of the attack
											switch (attackResult)
											{
												case 0:
													dispMiss();
													cout << "\n     Miss...\n" << endl;
													invalidInput = false;
													break;

												case 1:
													dispHit();
													cout << "\n     Hit!\n" << endl;
													invalidInput = false;
													break;

												case 2:
													dispHit();
													dispReconHit();
													cout << "\n     Hit! Recon 1 destroyed!\n" << endl;
													invalidInput = false;
													break;

												case 3:
													dispHit();
													dispReconHit();
													cout << "\n     Hit! Recon 2 destroyed!\n" << endl;
													invalidInput = false;
													break;

												case 4:
													dispHit();
													dispReconHit();
													cout << "\n     Hit! Recon 1 & Recon 2 destroyed!\n" << endl;
													invalidInput = false;
													break;
											}
										}
									}

									//   Invalid coordinates
									if (invalidInput)
									{
										cout << "\n\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "\n";
										cout << "     Enter in the coordinate to attack.\n" << endl;
										cout << "     > ";
										cin >> atkCoord;
										cout << endl;
									}
								}


								/*   Update the HP values of all ships for Player 1, 
									 and display whether they were destroyed         */
								tempACHP = 0;
								tempBAHP = 0;
								tempDRHP = 0;
								tempSBHP = 0;
								tempPBHP = 0;

								for (int i = 0; i < P1.getBoard().getBoardYaxis(); i++)
								{
									for (int j = 0; j < P1.getBoard().getBoardXaxis(); j++)
									{
										switch (P2.getShipFromPlayer(j, i))
										{
											case 1:
												tempACHP++;
												break;

											case 2:
												tempBAHP++;
												break;

											case 3:
												tempDRHP++;
												break;

											case 4:
												tempSBHP++;
												break;

											case 5:
												tempPBHP++;
												break;

											default:
												break;
										}
									}
								}

								if (P1.isACalive() && tempACHP == 0)
								{
									cout << "\n     Aircraft Carrier destroyed!\n" << endl;
									P1.destroyAC();
								}

								if (P1.isBAalive() && tempBAHP == 0)
								{
									cout << "\n     Battleship destroyed!\n" << endl;
									P1.destroyBA();
								}

								if (P1.isDRalive() && tempDRHP == 0)
								{
									cout << "\n     Destroyer obliterated!\n" << endl;
									P1.destroyDR();
								}

								if (P1.isSBalive() && tempSBHP == 0)
								{
									cout << "\n     Submarine destroyed!\n" << endl;
									P1.destroySB();
								}

								if (P1.isPBalive() && tempPBHP == 0)
								{
									cout << "\n     Patrol Boat destroyed!\n" << endl;
									P1.destroyPB();
								}


								/*   Update the HP values of all ships for Player 2,
									 and display whether they were destroyed         */
								tempACHP = 0;
								tempBAHP = 0;
								tempDRHP = 0;
								tempSBHP = 0;
								tempPBHP = 0;

								for (int i = 0; i < P2.getBoard().getBoardYaxis(); i++)
								{
									for (int j = 0; j < P2.getBoard().getBoardXaxis(); j++)
									{
										switch (P1.getShipFromPlayer(j, i))
										{
											case 1:
												tempACHP++;
												break;

											case 2:
												tempBAHP++;
												break;

											case 3:
												tempDRHP++;
												break;

											case 4:
												tempSBHP++;
												break;

											case 5:
												tempPBHP++;
												break;

											default:
												break;
										}
									}
								}

								if (P2.isACalive() && tempACHP == 0)
								{
									cout << "\n     Aircraft Carrier destroyed!\n" << endl;
									P2.destroyAC();
								}

								if (P2.isBAalive() && tempBAHP == 0)
								{
									cout << "\n     Battleship destroyed!\n" << endl;
									P2.destroyBA();
								}

								if (P2.isDRalive() && tempDRHP == 0)
								{
									cout << "\n     Destroyer obliterated!\n" << endl;
									P2.destroyDR();
								}

								if (P2.isSBalive() && tempSBHP == 0)
								{
									cout << "\n     Submarine destroyed!\n" << endl;
									P2.destroySB();
								}

								if (P2.isPBalive() && tempPBHP == 0)
								{
									cout << "\n     Patrol Boat destroyed!\n" << endl;
									P2.destroyPB();
								}
							}


							endTurn = true;

							if (subChoice == 6)
							{endTurn = false;}
							
							break;
						}

						//   Scan Actions
						case 3:
						{
							//   Display the various scan options
							cout << "\n   =================================================" << endl;
							cout << "   ===                Scan an Area               ===" << endl;
							cout << "   =================================================\n" << endl;
							cout << "     Choose a unit to scan with.\n" << endl;


							//   If the player has scanning capabilities left, or if the scanning units are still alive, they will be shown
							switch (turnCounter)
							{
								//   For Player 1
								case 1:
								{
									//   For the Submarine
									if (P1.isSBalive() == true)
									{
										cout << "   1. Submarine Sonar: Scans a wide area and reports if there are enemy ships in the area." << endl << endl;
										dispSBscan();
									}

									//   For Recon 1
									if (P1.isReconAlive(1) == true && P2.isReconAirBrn(1))
									{
										cout << "   2. Recon 1 Reconnaissance: Scans a small area and reports the exact location of discovered enemy ships." << endl << endl;
										dispRPscan();
									}

									//   For Recon 2
									if (P1.isReconAlive(2) == true && P2.isReconAirBrn(2))
									{
										cout << "   3. Recon 2 Reconnaissance: Scans a small area and reports the exact location of discovered enemy ships." << endl << endl;
										dispRPscan();
									}

									break;
								}

								//   For Player 2
								case 2:
								{
									//   For the Submarine
									if (P2.isSBalive() == true)
									{
										cout << "   1. Submarine Sonar: Scans a wide area and reports if there are enemy ships in the area." << endl << endl;
										dispSBscan();
									}

									//   For Recon 1
									if (P2.isReconAlive(1) == true && P1.isReconAirBrn(1))
									{
										cout << "   2. Recon 1 Reconnaissance: Scans a small area and reports the exact location of discovered enemy ships." << endl << endl;
										dispRPscan();
									}

									//   For Recon 2
									if (P2.isReconAlive(2) == true && P1.isReconAirBrn(2))
									{
										cout << "   3. Recon 2 Reconnaissance: Scans a small area and reports the exact location of discovered enemy ships." << endl << endl;
										dispRPscan();
									}

									break;
								}

								break;
							}


							cout << "   4. Cancel Action: Cancel the scan & return to the player menu.\n" << endl << endl;
							cout << "     Selection: ";


							//   Gather user input & validation
							cin >> subChoice;
							cout << endl;


							//   Check to see if the player's requested unit is still alive
							while (subInvalidInput)
							{
								//   Handling sub-choice input
								switch (subChoice)
								{
									//   Chose the Submarine
									case 1: 
										//   Handle the turn player's action
										switch (turnCounter)
										{
											//   For Player 1
											case 1:
											{
												if (P1.isSBalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Submarine is destroyed!       !!!\n" << endl;}

												break;
											}

											//   For Player 2
											case 2:
											{
												if (P2.isSBalive() == true)
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Submarine is destroyed!       !!!\n" << endl;}

												break;
											}
										}

										break;

									//   Chose Recon 1
									case 2:
										//   Handle the turn player's action
										switch (turnCounter)
										{
											//   For Player 1
											case 1:
											{
												if (P1.isReconAlive(1) && P2.isReconAirBrn(1))
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Recon 1 is unavailable.       !!!\n" << endl;}

												break;
											}

											//   For Player 2
											case 2:
											{
												if (P2.isReconAlive(1) && P1.isReconAirBrn(1))
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Recon 1 is unavailable.       !!!\n" << endl;}

												break;
											}
										}

										break;

									//   Chose Recon 2
									case 3:
										//   Handle the turn player's action
										switch (turnCounter)
										{
											//   For Player 1
											case 1:
											{
												if (P1.isReconAlive(2) && P2.isReconAirBrn(2))
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Recon 2 is unavailable.       !!!\n" << endl;}

												break;
											}

											//   For Player 2
											case 2:
											{
												if (P2.isReconAlive(2) && P1.isReconAirBrn(2))
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Recon 2 is unavailable.       !!!\n" << endl;}

												break;
											}
										}

										break;

									//   Cancelled movement
									case 4:
										subInvalidInput = false;
										break;

									//   Invalid Input
									default:
										cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
										break;
								}

								//   Sub-input wasn't valid
								if (subInvalidInput)
								{
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n";
									cout << "     Selection: ";
									cin >> subChoice;
									cout << endl;
								}
							}

							cout << endl;

							//   Performing the action if the player didn't cancel the attack
							if (subChoice != 4)
							{
								//   Display scanning selection
								switch (subChoice)
								{
									//   Chose the Submarine
									case 1:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---               Submarine Scan              ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										break;
									}

									//   Chose Recon 1
									case 2:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---                Recon 1 Scan               ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										cout << "     Choose a Scanning Pattern.\n" << endl;
										cout << "     > ";
										cin >> subsubChoice;

										//   Invalid input
										while (!intValidCheck(subsubChoice, 1, 2))
										{
											cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "\n";
											cout << "     > ";
											cin >> subsubChoice;
										}

										cout << endl << endl;

										break;
									}

									//   Chose Recon 2
									case 3:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---                Recon 2 Scan               ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										cout << "     Choose a Scanning Pattern.\n" << endl;
										cout << "     > ";
										cin >> subsubChoice;

										//   Invalid input
										while (!intValidCheck(subsubChoice, 1, 2))
										{
											cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "\n";
											cout << "     > ";
											cin >> subsubChoice;
										}

										cout << endl << endl;

										break;
									}
								}

								//   Request for a coordinate if the Submarine was chosen. If not, use a random coordinate
								//   to avoid having to rewrite code
								if (subChoice == 1)
								{
									cout << "     Enter in the coordinate to scan.\n" << endl;
									cout << "     > ";
									cin >> atkCoord;
								}

								else
								{atkCoord = "a1";}
								
								/*   Determines if entered coordinate is valid. If it is, scans with the chosen method.
									 If not, prompts for a new input                                                     */
								while (invalidInput)
								{
									while (invalidInput)
									{
										//   Proceed if the user's input is 2 or 3 characters long
										if (atkCoord.length() > 1 && atkCoord.length() < 4)
										{
											//   Split the coordinate into an "x" value and a "y" value
											ss << atkCoord;
											ss >> xLetter;
											ss >> yAttack;
											ss.clear();
											ss.str("");


											//   Convert the "x" value to upper-case and subtract 1 off the "y" value
											xLetter = toupper(xLetter);
											yAttack--;


											/*   Check to see if the entered coordinates are valid. If they are, proceed with the attack.
												 If not, don't do anything                                                                */
											if (xLetter >= 'A' || xLetter <= 'N' || yAttack >= 0 || yAttack <= 9)
											{
												//   Convert the letter to its corresponding x-coordinate
												switch (xLetter)
												{
													case 'A':
														xAttack = 0;
														break;

													case 'B':
														xAttack = 1;
														break;

													case 'C':
														xAttack = 2;
														break;

													case 'D':
														xAttack = 3;
														break;

													case 'E':
														xAttack = 4;
														break;

													case 'F':
														xAttack = 5;
														break;

													case 'G':
														xAttack = 6;
														break;

													case 'H':
														xAttack = 7;
														break;

													case 'I':
														xAttack = 8;
														break;

													case 'J':
														xAttack = 9;
														break;

													case 'K':
														xAttack = 10;
														break;

													case 'L':
														xAttack = 11;
														break;

													case 'M':
														xAttack = 12;
														break;

													case 'N':
														xAttack = 13;
														break;

													default:
														xAttack = -1;
														break;
												}

												//   Perform the scan. If the result is -1, the chosen coordinate had invalid coordinate locations
												switch (subChoice)
												{
													//   Submarine Scan
													case 1:
													{
														//   Perform the scan on the enemy player
														switch (turnCounter)
														{
															case 1:
																attackResult = P1.SBscan(xAttack, yAttack);
																break;

															case 2:
																attackResult = P2.SBscan(xAttack, yAttack);
																break;
														}
												
														break;
													}

													//   Recon 1 Scan
													case 2:
													{
														//   Perform the scan on the enemy player
														switch (turnCounter)
														{
															//   For Player 1
															case 1:
																RPscanResult = P1.RPscan(P2.getRPcoord(1).x, P2.getRPcoord(1).y, subsubChoice);
																break;

															//   For Player 2
															case 2:
																RPscanResult = P2.RPscan(P1.getRPcoord(1).x, P1.getRPcoord(1).y, subsubChoice);
																break;
														}

														break;
													}

													//   Recon 2 Scan
													case 3:
													{
														//   Perform the scan on the enemy player
														switch (turnCounter)
														{
															case 1:
																RPscanResult = P1.RPscan(P2.getRPcoord(2).x, P2.getRPcoord(2).y, subsubChoice);
																break;

															case 2:
																RPscanResult = P2.RPscan(P1.getRPcoord(2).x, P1.getRPcoord(2).y, subsubChoice);
																break;
														}

														break;
													}
												}

												//   Display the results of the attack; result format changes based on scanning method
	 											switch (subChoice)
												{
													//   Displaying the results of the Submarine Scan
													case 1:
														switch (attackResult)
														{
															//   Nothing was detected
															case 0:
																dispMiss();
																cout << "\n     Nothing was detected.\n" << endl;
																invalidInput = false;
																break;

															//   Something was detected
															case 1:
																dispSonarScan();
																cout << "\n     Something was detected!\n" << endl;
																invalidInput = false;
																break;
														}

														break;

													//   Displaying the results of the Recon Plane Scan
													default:
														switch (RPscanResult.size())
														{
															case 0:
																dispMiss();
																cout << "\n     No enemy sighted.\n" << endl;
																invalidInput = false;
																break;

															default:
																dispReconScan();
																cout << "\n     Enemy sighted! Coordinates confirmed at:\n" << endl;
																
																for (unsigned int i = 0; i < RPscanResult.size(); i++)
																{
																	cout << "     ";
																	RPscanResult[i].display();
																	cout << endl;
																}

																cout << endl;

																invalidInput = false;
																break;
														}

														break;
												}
											}
										}

										//   Invalid coordinates
										if (invalidInput)
										{
											cout << "\n\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "\n";
											cout << "     Enter in the coordinate to scan.\n" << endl;
											cout << "     > ";
											cin >> atkCoord;
											cout << endl;
										}
									}
								}
							}

							endTurn = true;

							if (subChoice == 4)
							{endTurn = false;}

							break;
						}

						//   Movement Actions
						case 4:
						{
							cout << "\n   =================================================" << endl;
							cout << "   ===             Move a Recon Plane            ===" << endl;
							cout << "   =================================================\n" << endl;
							cout << "     Choose an option.\n" << endl << endl;


							//   If the player can move a recon plane, it will be shown
							switch (turnCounter)
							{
								//   For Player 1
								case 1:
								{
									//   For Recon 1
									if (P1.isReconAlive(1))
									{cout << "   1. Move Recon 1: Deploy or move Recon 1 to a new location." << endl;}

									//   For Recon 2
									if (P1.isReconAlive(2))
									{cout << "   2. Move Recon 2: Deploy or move Recon 2 to a new location." << endl;}

									break;
								}

								//   For Player 2
								case 2:
								{
									//   For Recon 1
									if (P2.isReconAlive(1))
									{cout << "   1. Move Recon 1: Deploy or move Recon 1 to a new location." << endl;}

									//   For Recon 2
									if (P2.isReconAlive(2))
									{cout << "   2. Move Recon 2: Deploy or move Recon 2 to a new location." << endl;}

									break;
								}
							}


							cout << "   3. Cancel Action: Cancel the movement & return to the player menu.\n" << endl << endl;
							cout << "     Selection: ";


							//   Gather user input & validation
							cin >> subChoice;
							cout << endl;


							//   Check to see if the player's requested recon plane is still alive
							while (subInvalidInput)
							{
								//   Handling sub-choice input
								switch (subChoice)
								{
									//   Chose Recon 1
									case 1:
										switch (turnCounter)
										{
											case 1:
											{
												if (P1.isReconAlive(1))
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Recon 1 is down!       !!!\n" << endl;}

												break;
											}

											case 2:
											{
												if (P2.isReconAlive(1))
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Recon 1 is down!       !!!\n" << endl;}

												break;
											}
										}
										
										break;

									//   Chose Recon 2
									case 2:
										switch (turnCounter)
										{
											case 1:
											{
												if (P1.isReconAlive(2))
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Recon 2 is down!       !!!\n" << endl;}

												break;
											}

											case 2:
											{
												if (P2.isReconAlive(2))
												{subInvalidInput = false;}

												else
												{cout << "\n   !!!       Recon 2 is down!       !!!\n" << endl;}

												break;
											}
										}

										break;

									//   Cancelled movement
									case 3:
										subInvalidInput = false;
										break;

									//   Invalid input
									default:
										cout << "\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
										break;
								}

								//   Sub-input wasn't valid
								if (subInvalidInput)
								{
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cout << "\n";
									cout << "     Selection: ";
									cin >> subChoice;
									cout << endl;
								}
							}

							cout << endl;

							//   Performing the action if the player didn't cancel the attack
							if (subChoice != 3)
							{
								//   Display movement selection
								switch (subChoice)
								{
									//   Chose Recon 1
									case 1:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---                Move Recon 1               ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										break;
									}

									//   Chose Recon 2
									case 2:
									{
										cout << "\n   -------------------------------------------------" << endl;
										cout << "   ---                Move Recon 2               ---" << endl;
										cout << "   -------------------------------------------------\n" << endl;
										break;
									}
								}

								cout << "     Enter in the coordinate to move the plane to.\n" << endl;
								cout << "     > ";
								cin >> atkCoord;

								/*   Determines if entered coordinate is valid. If it is, moves the chosen plane.
									 If not, prompts for a new input                                              */
								while (invalidInput)
								{
									//   Proceed if the user's input is 2 or 3 characters long
									if (atkCoord.length() > 1 && atkCoord.length() < 4)
									{
										//   Split the coordinate into an "x" value and a "y" value
										ss << atkCoord;
										ss >> xLetter;
										ss >> yAttack;
										ss.clear();
										ss.str("");


										//   Convert the "x" value to upper-case and subtract 1 off the "y" value
										xLetter = toupper(xLetter);
										yAttack--;


										/*   Check to see if the entered coordinates are valid. If they are, proceed with the movement.
											 If not, don't do anything                                                                */
										if (xLetter >= 'A' || xLetter <= 'N' || yAttack >= 0 || yAttack <= 9)
										{
											//   Convert the letter to its corresponding x-coordinate
											switch (xLetter)
											{
												case 'A':
													xAttack = 0;
													break;

												case 'B':
													xAttack = 1;
													break;

												case 'C':
													xAttack = 2;
													break;

												case 'D':
													xAttack = 3;
													break;

												case 'E':
													xAttack = 4;
													break;

												case 'F':
													xAttack = 5;
													break;

												case 'G':
													xAttack = 6;
													break;

												case 'H':
													xAttack = 7;
													break;

												case 'I':
													xAttack = 8;
													break;

												case 'J':
													xAttack = 9;
													break;

												case 'K':
													xAttack = 10;
													break;

												case 'L':
													xAttack = 11;
													break;

												case 'M':
													xAttack = 12;
													break;

												case 'N':
													xAttack = 13;
													break;

												default:
													xAttack = -1;
													break;
											}

											//   Perform the movement. If the result is -1, the chosen coordinate had invalid coordinate locations
											switch (subChoice)
											{
												//   Move Recon 1
												case 1:
													//   Perform the movement
													switch (turnCounter)
													{
														case 1:
															moveResult = P2.mveRecon(xAttack, yAttack, 1);
															break;

														case 2:
															moveResult = P1.mveRecon(xAttack, yAttack, 1);
															break;
													}

													break;
													
												//   Move Recon 2
												case 2:
													//   Perform the movement
													switch (turnCounter)
													{
														case 1:
															moveResult = P2.mveRecon(xAttack, yAttack, 2);
															break;

														case 2:
															moveResult = P1.mveRecon(xAttack, yAttack, 2);
															break;
													}

													break;
											}

											//   Display the results of the attack
											switch (moveResult)
											{
												case false:
													break;

												case true:
													dispReconMove();
													cout << "\n     Movement successful.\n" << endl;
													invalidInput = false;
													break;
											}
										}
									}

									//   Invalid input
									if (invalidInput)
									{
										cout << "\n\n   !!!       Invalid Input. Please try again.       !!!\n" << endl;
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "\n";
										cout << "     Enter in the coordinate to attack.\n" << endl;
										cout << "     > ";
										cin >> atkCoord;
										cout << endl;
									}
								}
							}

							endTurn = true;

							if (subChoice == 3)
							{endTurn = false;}

							break;
						}

						//   Surrender
						case 5:
						{
							//   Display the surrender text
							switch (turnCounter)
							{
								case 1:
									cout << "\n     Are you sure you want to surrender, Captain " << P1.getName() << "?" << endl;
									cout << "     Type in \"Surrender\" to confirm your action, or any other input to cancel.\n" << endl;
									break;

								case 2:
									cout << "\n     Are you sure you want to surrender, Captain " << P2.getName() << "?" << endl;
									cout << "     Type in \"Surrender\" to confirm your action, or any other input to cancel.\n" << endl;
									break;
							}

							cout << "     > ";
							cin >> atkCoord;
							cout << "\n" << endl;

							if (atkCoord == "Surrender")
							{
								endGame = true;
								surrender = true;
								switch (turnCounter)
								{
									case 1:
										winner = P2.getName();
										loser = P1.getName();
										break;

									case 2:
										winner = P1.getName();
										loser = P2.getName();
										break;
								}

								endTurn = true;
							}

							break;
						}
					}


				}


				//   Reset all values to prepare for the next turn
				choice = -1;
				subChoice = -1;
				subsubChoice = -1;
				xAttack = -1;
				yAttack = -1;
				attackResult = -1;
				moveResult = false;
				atkCoord = "";
				invalidInput = true;
				subInvalidInput = true;
				RPscanResult.clear();


				//   If any player loses all of their ships, the game end condition is activated, and the
				//   winner and loser are determined
				if (!P1.isAlive() || !P2.isAlive())
				{
					endGame = true;

					if (!P1.isAlive())
					{
						winner = P2.getName();
						loser = P1.getName();
					}

					else
					{
						winner = P1.getName();
						loser = P2.getName();
					}
				}


				//   End of turn, pass flow of game to next player
				if (turnCounter == 1)
				{turnCounter++;}

				else
				{turnCounter--;}

				if (!endGame)
				{
					cout << "\n     Press Enter to end your turn...\n" << endl;
					cin.get();
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "\n";
				}
				
				
				dispTransition();
				dispTransition();
				dispTransition();
				dispTransition();
				dispTransition();
			}

			break;
		}

		//   Option 2: Online Mode
		case 2:
		{

			break;
		}

		//   Option 3: Versus CPU Mode
		case 3:
		{

			break;
		}

		default:
			break;
	}


	//   Display the correct game ending
	if (surrender)
	{
		dispSurrender(winner, loser);
	}

	else
	{dispVictory(winner, loser);}

	













	


















	

}