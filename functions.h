#pragma once



/*   Checks the input field for a valid integer within the Left & Right Bounds.
	 Returns True if the input is valid & inclusively within the bounds. 
	 Returns False otherwise.                                                   */
bool intValidCheck(int input_, int LBound_, int RBound_)
{return (input_ >= LBound_ && input_ <= RBound_);}

/*   Checks the input coordinates for a valid horizontal/vertical distance in between the two points specified. 
	 Returns True if the distance between the two points matches the distance parameter. 
	 Returns False otherwise.                                                                                   */
bool distValidCheck(int x1_, int y1_, int x2_, int y2_, int distance_)
{
	bool validDist = false;
	int xDelta = 0;
	int yDelta = 0;

	//   Finding the delta between the x-coordinates
	if (x1_ > x2_)
	{xDelta = x1_ - x2_;}

	else if (x2_ > x1_)
	{xDelta = x2_ - x1_;}

	//   Finding the delta between the y-coordinates
	if (y1_ > y2_)
	{yDelta = y1_ - y2_;}

	else if (y2_ > y1_)
	{yDelta = y2_ - y1_;}


	//   Checking if the points lie in a line & are not the same
	if ((x1_ == x2_ || y1_ == y2_) && (xDelta != yDelta) && 
		((x1_ == x2_ && yDelta == distance_ - 1) || (y1_ == y2_ && xDelta == distance_ - 1)))
	{validDist = true;}


	return validDist;
}

/*   Displays the intro turn text to the current player.
	 1 = Player 1
	 2 = Player 2                                        */
void dispTurnStart(int pNumber_)
{
	switch (pNumber_)
	{
		case 1:
			cout << "\n           oooooooooo    oo  888                 ooooooooooo                                    " << endl;
			cout << "            888    888 o888  888 oooooooo8       88  888  88 oooo  oooo  oo oooooo  oo oooooo   " << endl;
			cout << "            888oooo88   888 o88 888ooooooo           888      888   888   888    888 888   888  " << endl;
			cout << "            888         888             888          888      888   888   888        888   888  " << endl;
			cout << "           o888o       o888o    88oooooo88          o888o      888o88 8o o888o      o888o o888o " << endl;
			cout << "     ================================================================================================\n" << endl;
                                                                                     
			break;

		case 2:
			cout << "\n           oooooooooo    ooooooo   888                 ooooooooooo                                    " << endl;
			cout << "            888    888 o88     888 888 oooooooo8       88  888  88 oooo  oooo  oo oooooo  oo oooooo   " << endl;
			cout << "            888oooo88        o888 o88 888ooooooo           888      888   888   888    888 888   888  " << endl;
			cout << "            888           o888   o            888          888      888   888   888        888   888  " << endl;
			cout << "           o888o       o8888oooo88    88oooooo88          o888o      888o88 8o o888o      o888o o888o " << endl;
			cout << "     ======================================================================================================\n" << endl;
                                                                                           
			break;

		default:
			break;
	}
}

//   Displays the turn player menu & prompts for input. 
void dispPlayerMenu()
{
	cout << "\n   1. Display the Target Grid" << endl;
	cout << "   2. Launch an Attack" << endl;
	cout << "   3. Scan an Area" << endl;
	cout << "   4. Move a Recon Plane" << endl;
	cout << "   5. Forfeit\n" << endl;
	cout << "     Selection: ";
}

//   Displays the firing pattern of a Basic Attack.
void dispBattackFP()
{
	cout << "      Firing Pattern:" << endl;
	cout << "     -------------------" << endl;
	cout << "     |     |     |     |" << endl;
	cout << "     -------------------" << endl;
	cout << "     |     |  X  |     |" << endl;
	cout << "     -------------------" << endl;
	cout << "     |     |     |     |" << endl;
	cout << "     -------------------\n\n" << endl;
}

//   Displays the firing patterns of the Destroyer's Apache Missiles.
void dispDRattackFP()
{
	cout << "      Firing Pattern 1:       Firing Pattern 2:" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |     |     |     |     |     |  X  |     |" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |  X  |  X  |  X  |     |     |  X  |     |" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |     |     |     |     |     |  X  |     |" << endl;
	cout << "     -------------------     -------------------\n\n" << endl;
}

//   Displays the firing patterns of the Submarine's Torpedoes.
void dispSBattackFP()
{
	cout << "      Firing Pattern 1:       Firing Pattern 2:" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |     |     |     |     |     |  X  |     |" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |  O  |  O  |  X  |     |     |  O  |     |" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |     |     |     |     |     |  O  |     |" << endl;
	cout << "     -------------------     -------------------\n\n" << endl;
}

//   Displays the firing patterns of the Aircraft Carrier's Exocet Missiles.
void dispACattackFP()
{
	cout << "      Firing Pattern 1:       Firing Pattern 2:" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |  X  |     |  X  |     |     |  X  |     |" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |     |  X  |     |     |  X  |  X  |  X  |" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |  X  |     |  X  |     |     |  X  |     |" << endl;
	cout << "     -------------------     -------------------\n\n" << endl;
}

//   Displays the firing patterns of the Battleship's Tomahawk Missile.
void dispBAattackFP()
{
	cout << "      Firing Pattern:" << endl;
	cout << "     -------------------" << endl;
	cout << "     |  X  |  X  |  X  |" << endl;
	cout << "     -------------------" << endl;
	cout << "     |  X  |  X  |  X  |" << endl;
	cout << "     -------------------" << endl;
	cout << "     |  X  |  X  |  X  |" << endl;
	cout << "     -------------------\n\n" << endl;
}

//   Displays the scanning pattern of the Submarine.
void dispSBscan()
{
	cout << "      Scanning Pattern:" << endl;
	cout << "     -------------------" << endl;
	cout << "     |  +  |  +  |  +  |" << endl;
	cout << "     -------------------" << endl;
	cout << "     |  +  |  +  |  +  |" << endl;
	cout << "     -------------------" << endl;
	cout << "     |  +  |  +  |  +  |" << endl;
	cout << "     -------------------\n\n" << endl;
}

//   Displays the scanning patterns of the Recon Planes.
void dispRPscan()
{
	cout << "     Scanning Pattern 1:     Scanning Pattern 2:" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |  +  |     |  +  |     |     |  +  |     |" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |     |     |     |     |  +  |     |  +  |" << endl;
	cout << "     -------------------     -------------------" << endl;
	cout << "     |  +  |     |  +  |     |     |  +  |     |" << endl;
	cout << "     -------------------     -------------------\n\n" << endl;
}

//   Displays the graphic when an attack misses.
void dispMiss()
{                                                                               
	cout << "                                                                                " << endl;
	cout << "                                                                                " << endl;
	cout << "                                  @@@@@@@@@@@@@                                 " << endl;
	cout << "                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@%                         " << endl;
	cout << "                      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                     " << endl;
	cout << "                   @@@@@@@@@@@                     @@@@@@@@@@@                  " << endl;
	cout << "                @@@@@@@@@*                             %@@@@@@@@@               " << endl;
	cout << "              @@@@@@@@                                     @@@@@@@@             " << endl;
	cout << "            @@@@@@@@                                         @@@@@@@@           " << endl;
	cout << "           @@@@@@@                                             @@@@@@@          " << endl;
	cout << "          @@@@@@                                                *@@@@@@         " << endl;
	cout << "         @@@@@@                                                   @@@@@@        " << endl;
	cout << "        @@@@@@                                                    ,@@@@@@       " << endl;
	cout << "       *@@@@@@                                                     @@@@@@       " << endl;
	cout << "       @@@@@@                                                      (@@@@@@      " << endl;
	cout << "       @@@@@@                                                       @@@@@@      " << endl;
	cout << "       @@@@@@                                                      (@@@@@@      " << endl;
	cout << "       *@@@@@@                                                     @@@@@@       " << endl;
	cout << "        @@@@@@                                                    ,@@@@@@       " << endl;
	cout << "         @@@@@@                                                   @@@@@@        " << endl;
	cout << "          @@@@@@                                                *@@@@@@         " << endl;
	cout << "           @@@@@@@                                             @@@@@@@          " << endl;
	cout << "            @@@@@@@@                                         @@@@@@@@           " << endl;
	cout << "              @@@@@@@@                                     @@@@@@@@             " << endl;
	cout << "                @@@@@@@@@*                             %@@@@@@@@@               " << endl;
	cout << "                   @@@@@@@@@@@                     @@@@@@@@@@@                  " << endl;
	cout << "                      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                     " << endl;
	cout << "                          @@@@@@@@@@@@@@@@@@@@@@@@@@@@%                         " << endl;
	cout << "                                  @@@@@@@@@@@@@                                 " << endl;
	cout << "                                                                                " << endl;
	cout << "                                                                                " << endl;
}

//   Displays the graphic when an attack lands.
void dispHit()
{                                                                          
	cout << "                                                                                " << endl;
	cout << "                                       %%                                       " << endl;
	cout << "                                       %%                                       " << endl;
	cout << "                                      %%%%                                      " << endl;
	cout << "                                      %/*%             ,                        " << endl;
	cout << "                         %(          %%**%%          %%                         " << endl;
	cout << "                          %%%      *%%%***%%       %%%                          " << endl;
	cout << "      %%/                 %%%%%%%%%%%%****%%%%%%%%%%%%                  %%,     " << endl;
	cout << "         %%%%%%%         %%%%%%%%%%%%(*****%%%%%%%%%%%%          %%%%%%%        " << endl;
	cout << "           ,%%***#%%%%%%%%%%%%%%%%%%/*******%%%%*%%%%%%%%%%%%%%%%*%%%           " << endl;
	cout << "              %%%(******%%%%%%%%*****************%%%%%%%%%*****%%%%#            " << endl;
	cout << "                %%%%#******************.********************(%%%%%              " << endl;
	cout << "                 #%%%%%***************...*****************%%%%%%%%              " << endl;
	cout << "                  %%%%%%%********..............**********%%%%%%%%%%             " << endl;
	cout << "               %%%%%%%%%%%********.............************%%%%%%%%%%%(         " << endl;
	cout << "          (%%%%%%%%%%%%%%*********...........******************#%%%%%%%%%%%%    " << endl;
	cout << "                 %%%%%%%%%******..***.*.....***********%%%%%%%%%%%              " << endl;
	cout << "                   %%%%%%**************.***..********/%%%%%%%%                  " << endl;
	cout << "                  %%%%(**********************.*********%%%%%%%                  " << endl;
	cout << "                %%%%********%%%*********************%%%%%%%%%%%                 " << endl;
	cout << "              %%#***%%%%%%%%%%%%*%%%%%****%%%/******%%%%%%%%%%%%%               " << endl;
	cout << "           %%(%%%%*     %%%%%%%%%%%%%%%**%%%%%%%****%%%%%%%%(    %%%            " << endl;
	cout << "        %%                %%%%%%%%%%%%%*%%%%%%%%%%***%%%%%                      " << endl;
	cout << "                          %%%%%    %%%%%%%%%%%%%%%%%**%%%%                      " << endl;
	cout << "                          %%        %%%%%%%%     %%%%%*%%%                      " << endl;
	cout << "                         %           %%%%%          %%%#%%%                     " << endl;
	cout << "                                     %%%%              %%%%                     " << endl;
	cout << "                                      %%                 %%%                    " << endl;
	cout << "                                      %#                   %%                   " << endl;
	cout << "                                      %                      %                  " << endl;
	cout << "                                                                                " << endl;
	cout << endl;
}

//   Displays the graphic when a Recon Plane is destroyed.
void dispReconHit()
{
	cout << "   " << endl;
	cout << "                                                             .*//*                 " << endl;
	cout << "                                                     .((((((((/                    " << endl;
	cout << "                                                 .((((((((((                       " << endl;
	cout << "                                              .(((((((((((,                        " << endl;
	cout << "                                            *((((((((((((.                         " << endl;
	cout << "                                          ,(((((((((((((/     .                    " << endl;
	cout << "                                   *     (((((((((((((((.   .((                    " << endl;
	cout << "                                 ((.    /(((((((((((((((/  ,(((                    " << endl;
	cout << "                               .(((    *((((((((*  ((((((  ((((                    " << endl;
	cout << "                               ((((/   (((((((,   ((((((((((((((                   " << endl;
	cout << "                              /(((((( *((((((     (((/(((((((((((                  " << endl;
	cout << "                              /(((((((((((((      .((  ((((((((((,                 " << endl;
	cout << "                              /((((((((((((,        *,   ((((((((/                 " << endl;
	cout << "                              .((((((((((((.               *(((((/                 " << endl;
	cout << "                               ,(((((((( (((                 ((((,                 " << endl;
	cout << "                                .(((((((   (*                (((*                  " << endl;
	cout << "                                  *(((((*                    ((                    " << endl;
	cout << "                                     (((((                 .(            *#&&&&&(  " << endl;
	cout << "      /&&&&&&&&&&&&&&&#(/*,.            ,(((.       %#            *%&&&&&&&&&&&&&&&" << endl;
	cout << "    %&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&(               (&&&%.,#&&&&&&&&&&&&&&&&&&&&&&" << endl;
	cout << "     .#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/             /&&&&&&&&&&&&&&&&&&&&&&&&&&  " << endl;
	cout << "           *&&&&&&&&&&&&&&&&&&&&&&&&&&&*        &&&&&&&&&&&&&&&&&&&&&&&&&&&&&.     " << endl;
	cout << "                 #&&&&&&&&&&&&&&&&&&,             &&&&&&&&&&&&&&&&&&&&(            " << endl;
	cout << "                      *%&&&&&&&&&&&&&&&%.           &&&&&&&&&&&#.                  " << endl;
	cout << "                            (&&&&&&&&&&&&&&&%.        &&&&&&&%                     " << endl;
	cout << "                             %&&&&&&&&&&&&&&&&%        (&&&&&                      " << endl;
	cout << "                           &&&&&&&&&&&&&&&&&&#      %&&&&&&&                       " << endl;
	cout << "                        /&&&&&&&&&&&&&&&&&&&,    &&&&&&&&&&.                       " << endl;
	cout << "         ,&&&&&&&%(*,.&&&&&&&&&&&&&&( .&&&&  ,&&&&&&&&&&&&.                        " << endl;
	cout << "       %&&&&&&&&&&&&&&&&&&&&&&&&&%      &&  &&&&&&&&&&&&&/                         " << endl;
	cout << "         ,%&&&&&&&&&&&&&&&&&&&&,            &&&&&&&&&&&&#                          " << endl;
	cout << "               (&&&&&&&&&&&&&               &&&&&&&&&&&%                           " << endl;
	cout << "                    &&&&&&&&&               &&&&&&&&&&&                            " << endl;
	cout << "                     &&&&&&&&*              &&&&&&&&&&                             " << endl;
	cout << "                      &&&&&&&#              &&&&&&&&&.                             " << endl;
	cout << "                       #&&&&&%              &&&&&&&&.                              " << endl;
	cout << "                        #&&&(              .&&&&&&&*                               " << endl;
	cout << "                         .                 .&&&&&&/                                " << endl;
	cout << endl;
}

//   Displays the graphic for a recon plane movement.
void dispReconMove()
{
	cout << "                                                                                                         " << endl;
	cout << "   ,                                                                                                     " << endl;
	cout << "   &@@.                                                                                                  " << endl;
	cout << "    @@@@@@                                                                                               " << endl;
	cout << "      @@@@@@@                                                                                            " << endl;
	cout << "       .@@@@@@@@                                                                                         " << endl;
	cout << "          @@@   @@(                                                                                      " << endl;
	cout << "            @@  @@ @@@                                                                                   " << endl;
	cout << "              @@ /    @@@                                                                                " << endl;
	cout << "                @@@    *@@@@                                                                             " << endl;
	cout << "                  @@@@    @@@@&                                                                          " << endl;
	cout << "                   ,@@@@@@% @@@@@   @@/                                                                  " << endl;
	cout << "                     @@@@@@@@@@@@@@@  @@@@%&@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@.                             " << endl;
	cout << "                       @@@@@@@@@@@@@@@( &@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@                           " << endl;
	cout << "                          @@@@@@@@@@@@@@@ .@@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                           " << endl;
	cout << "                         (  @@@@@@@@@@@@@@@@ @@@@@ @@@@@@@@@@@@@@@@@@@@@@&   %@                          " << endl;
	cout << "                           @@@ @@@@@@@@@@@@@@@,@@@@@, &&@@@@@@@@@@@@@           %                        " << endl;
	cout << "                            @@&&@@%&@@@%%%%@@@%&@@&&@&@  *&&@@&&&                                        " << endl;
	cout << "                              *@@%&@@@&@&&@&@@&@@@@@@@@@@.      &                                        " << endl;
	cout << "                                 @@@@@@@@@@@@@@@@@@@@@@@@@@@                                             " << endl;
	cout << "                            *@@@   ,@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@#@@@@                          " << endl;
	cout << "                            %@@@@@#   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@/                         " << endl;
	cout << "                            @@@@@@@@@,  *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&@@@@/@#                        " << endl;
	cout << "                            @@@@@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@  *@@  (                      " << endl;
	cout << "                            & @@@@@@@@@@@@@  *@@@@@@@@@@@@@@@@@@@@@@@           @@                       " << endl;
	cout << "                            @@@ @@@@@@@@@@@     @@@@@@@@@@@@@@    @@@              @                     " << endl;
	cout << "                            @@@@@@%@@@@@@@      @@@@@@@@@@@@   &/                     @                  " << endl;
	cout << "                            @@@@@@@@%@@@/@*     @@@@@@@@@@@@@@    @                     *                " << endl;
	cout << "                           /@@@@@@@@@@@         @@@@@@@@@  @@                                            " << endl;
	cout << "                           @@@@@@@@@@@          @@@@@@@@@@*            ,                                 " << endl;
	cout << "                           ,@@@@@@@@             %@@@@@@@(                                               " << endl;
	cout << "                              @@@@@@@           @@@,@@@@@@                                               " << endl;
	cout << "                                .#    @(        &@@@@&    @@                                             " << endl;
	cout << "                                         @                   &                                           " << endl;
	cout << "                                                                                                         " << endl;
	cout << endl;
}

//   Displays a positive sonar scan result.
void dispSonarScan()
{
	cout << "  	                                                                               " << endl;
	cout << "                                   (@@@@@@@@@@@@@(                                " << endl;
	cout << "                           @@%@@@@@@@@@@@@@@@@@@@@@@@@@%%@                        " << endl;
	cout << "                      (@@@@@@@            @            @@@@@@@                    " << endl;
	cout << "                   @@@@@@                 @                 @@@@@@                " << endl;
	cout << "                @@@@@                     @                   ##@@@@@             " << endl;
	cout << "              @@@#.                     #@@@(               ######&@@@@           " << endl;
	cout << "            @@@@               @@@@@@@@@@@@@@@@@@@@@@@    %##########@@@@         " << endl;
	cout << "          @@@@             @@@@@@@        @        @@@@@@@####@@@@#####@@@@       " << endl;
	cout << "         @@@#           /@@@@@            @            @@@@@##########%#@@@@      " << endl;
	cout << "       @@@@           @@@@@               @          #####@@@@@###########@@@&    " << endl;
	cout << "      @@@@           @@@@                 @        #####(###@@@@###########@@%#   " << endl;
	cout << "      @@@          @@@@             .@@@@@@@@@@@ ,#####(######@@@%########(#%@@   " << endl;
	cout << "     @@@@          @@@            @@@@@   @   @@@@@#####@@@@###@@@####@@@###@@@@  " << endl;
	cout << "     @@@          @@@.          @@@@      @   #/#@@@@##########&@@@###@@@&###@@@  " << endl;
	cout << "    @@@@         *@@@          @@@@       @ ######@@@@##########@@@##########@@@/ " << endl;
	cout << "    @@@@@@@@@@@@@@@@%@@@@@@@@@@@@@@@@@@@@@(@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ " << endl;
	cout << "    @@@@         ,@@@          @@@@       @       @@@@          @@@          @@@/ " << endl;
	cout << "     @@@          @@@.          @@@@      @      @@@@          %@@@          @@@  " << endl;
	cout << "     @@@@          @@@            @@@@@.  @  (@@@@@            @@@          @@@@  " << endl;
	cout << "      @@@.         #@@@              @@@@@@@@@@@              @@@.          @@@   " << endl;
	cout << "      @@@@           @@@@                 @                 @@@@           @&&,   " << endl;
	cout << "       @@@@           @@@@@               @               @@@@&           @@@(    " << endl;
	cout << "         @@@@           .@@@@@            @            @@@@@            @@@@      " << endl;
	cout << "          @@@@             @@@@@@@        @        @@@@@@%             @@@@       " << endl;
	cout << "            @@@@               #@@@@@@@@@@@@@@@@@@@@@/               @@@@         " << endl;
	cout << "              @@@@(                      #@(                      @#@@@           " << endl;
	cout << "                @@@@@                     @                    .@@@@@             " << endl;
	cout << "                   @@@@@@                 @                 @@@@@@                " << endl;
	cout << "                       @@@@@@@,           @           #@%@@@@@                    " << endl;
	cout << "                           &@%%%@@@@@@@@@@@@@@@@@@@&@&@%@(                        " << endl;
	cout << "                                    @@@@@@@@@@@@@                                 " << endl;
	cout << "  " << endl;
}

//   Displays a positive Recon Plane scan.
void dispReconScan()
{
	cout << "                                             /*                                     " << endl;
	cout << "                                           #%%%%#                                   " << endl;
	cout << "                                         ,%%%%%%%%                                  " << endl;
	cout << "                                        %%%%%%%%%%%#                                " << endl;
	cout << "                                      #%%%%%%%%%%%%%%                               " << endl;
	cout << "                                    .%%%%%%%%%%%%%%%%%*                             " << endl;
	cout << "                                   %%%%%%%%%# *%%%%%%%%%                            " << endl;
	cout << "                                 /%%%%%%%%%     #%%%%%%%%,                          " << endl;
	cout << "                                %%%%%%%%%/        %%%%%%%%%                         " << endl;
	cout << "                              %%%%%%%%%%           #%%%%%%%%.                       " << endl;
	cout << "                            ,%%%%%%%%%     @@@@@@    %%%%%%%%%                      " << endl;
	cout << "                           %%%%%%%%%#     @@@@@@@@    #%%%%%%%%                     " << endl;
	cout << "                         #%%%%%%%%%       @@@@@@@,     .%%%%%%%%#                   " << endl;
	cout << "                       .%%%%%%%%%*        (@@@@@@        #%%%%%%%%                  " << endl;
	cout << "                      #%%%%%%%%%          .@@@@@@         .%%%%%%%%/                " << endl;
	cout << "                    *%%%%%%%%%.            @@@@@@           #%%%%%%%%               " << endl;
	cout << "                   %%%%%%%%%#              @@@@@,             %%%%%%%%*             " << endl;
	cout << "                 #%%%%%%%%%                (@@@@               %%%%%%%%%            " << endl;
	cout << "               ,%%%%%%%%%*                   (,                 .%%%%%%%%,          " << endl;
	cout << "              %%%%%%%%%#                                          #%%%%%%%%         " << endl;
	cout << "            (%%%%%%%%%.                   (@@@@@@                  .%%%%%%%%.       " << endl;
	cout << "          .%%%%%%%%%(                     @@@@@@@%                   #%%%%%%%#      " << endl;
	cout << "         %%%%%%%%%%                        ,@@@&                      .%%%%%%%%.    " << endl;
	cout << "       *%%%%%%%%%%%(                                                   %%%%%%%%%#   " << endl;
	cout << "      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  " << endl;
	cout << "    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%(" << endl;
	cout << "     %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "    " << endl;
}

//   Displays transitional characters.
void dispTransition()
{
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

//   Displays the Title Screen.
void dispTitle()
{
	cout << "\n\n\n" << endl;
	cout << "                                      ... .                                                        " << endl;
	cout << "                                      ,$..D.                       ..                              " << endl;
	cout << "                                     .,D,87N=.                    .N.                 ..           " << endl;
	cout << "                              D,MD. .,? .7D~NN.   ..  .+.:.    .:.DD,               .OND           " << endl;
	cout << "                           ..~N~ZNN....DN~~~~ND..8M.N...,,N.    M.ND?            ..~7.$ZO          " << endl;
	cout << "                            .N. I=~ND. .ID:~~~ID..7D~:+.DO~N .MM7DMI..          ,.8. D....         " << endl;
	cout << "                             .ODN~~~:NN...ND~~~~D=..DM~O.=D~ND$M$$$M         .,.....NM. $..        " << endl;
	cout << "                               . NN$~~~D=...N:~~~DD...N$~D.D~N~Z~M$$D       .,.ONDDNDDNZ,.,        " << endl;
	cout << "                                  .ND8~~:N.. ZD~~~$D.. .D:~~:,~~MM:=        ..$. .ODDDNMNDZ.       " << endl;
	cout << "                                     8NO~~+N...DZ~~:D. .N::~~~~~~~:$       . Z.  .DD    . ~.       " << endl;
	cout << "                                      .+N$~~OZ. .D~~~DMM87+?I?N+~~~~.     ..O.  ..D     ...        " << endl;
	cout << "                            .D?,....    .+DN~~M.. OO~~MN$$8$7DD?ID~D.    . ,.   .NN,  .D  .        " << endl;
	cout << "                             DN???+8NDM.. .,DI~~N..$D~~.D$$$$$$$$D+..   ..,. .. .D.=  .. 8         " << endl;
	cout << "                             MDN+????????+MDN8N,~~N$$ZN:~N7$$$$$$$$N.. . .  .~..DN.D   ...         " << endl;
	cout << "                             7DDDI??????????????MM:8~~~$:~N~~NO$$$D$$N.  . .N..~N..~ .:.           " << endl;
	cout << "                             ,DDDD+??????78+???????++O8~~N:~~~~~ZN$$$N,.. .N ..DD. . ...Z          " << endl;
	cout << "                             .NNDDD??????~=????????????$~~~~~~:M~~~D$+.~~~~N .7NM . .~...          " << endl;
	cout << "                             .NZ?DDN???DN+:?,???????????DI?ND,:~~~~~~D.NNN~:. DD. + .. $           " << endl;
	cout << "                             .DDD??NN???8~~~8????????????MD7???OD,~~~~N~:NDN ND  .=.  .            " << endl;
	cout << "                             .DD8ONNDD????????????????????N??8D??I$D::?~~~N.,ND  ...:.~.           " << endl;
	cout << "                             ..DDDDDDDD?????????????????????DM??+DIIIN?D:~$.DD.. ...  .            " << endl;
	cout << "                              .8DDDDDD???????????????????????+M??++D?II?D.=DN   O.7  .            " << endl;
	cout << "                                 .NDDDDD?????????????????????????+$?I?NDZ??DD . .. ..D.            " << endl;
	cout << "                                  .ZDDDDO???????????????????????????????7NO?OI. . ~ ..             " << endl;
	cout << "                                    .DDDD?????????????????????????????????$NN?N.I ..8.             " << endl;
	cout << "                                     .NDDZ?????????????????????????????????+N7NO,,..               " << endl;
	cout << "                                       DDD????????????????????????????????????DIZ. ,               " << endl;
	cout << "                                    ....NDZ??+DN8ODN8??????????????????????????MN   .              " << endl;
	cout << "                                   ..DI7DDN8N$$$$DMDDDDN????????????????????????+NI                " << endl;
	cout << "                                .8ND7$ON$$D7$$$$N7$$$NMNNDDNDNO+?N8???????????????D                " << endl;
	cout << "                                .INNNNN7$$7$$$$$$8$$D$$$$$$ND$$7$$NDDNNMO?????????D                " << endl;
	cout << "                               .D$$$$O8$$$$$$DO$$$$$7$$$$$$$$$$$$$$$7$$$8DDN8D???N.                " << endl;
	cout << "                                .N8$$$$$$$$$$$$$$$$$$$$$D7$$$$$7O$$$$$$$$$$$$8D$?D.                " << endl;
	cout << "                                  .DN$$$$$$M$$$8N8$$$$$$$$$$$$$$$$$$7$7O7$$$$$$$DNM..              " << endl;
	cout << "                                    .7NN7$$$$$$$$$$$$$$$7N$N$$$$$$DD7$$$$$$$$$$$$$$8NN             " << endl;
	cout << "                                     ....MDDO7$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$7ZNDM....              " << endl;
	cout << "                                           .. IMDDDNZ7$$$$$$$$$$7$$8NNDNDNI ...                    " << endl;
	cout << "                                                  ...   ..   ..... .... .         .                \n" << endl;
	cout << "       oooooooooo      o   ooooooooooo ooooooooooo ooooo       ooooooooooo  oooooooo8 ooooo ooooo ooooo oooooooooo  " << endl;
	cout << "        888    888    888  88  888  88 88  888  88  888         888    88  888         888   888   888   888    888 " << endl;
	cout << "        888oooo88    8  88     888         888      888         888ooo8     888oooooo  888ooo888   888   888oooo88  " << endl;
	cout << "        888    888  8oooo88    888         888      888      o  888    oo          888 888   888   888   888        " << endl;
	cout << "       o888ooo888 o88o  o888o o888o       o888o    o888ooooo88 o888ooo8888 o88oooo888 o888o o888o o888o o888o       \n\n" << endl;
	
}

//   Displays the Main Menu.
void dispMainMenuGraphic()
{
	cout << "                                                7M                                                                " << endl;
	cout << "                                                ZM                MM                                              " << endl;
	cout << "                                                ZM               .MMM M                                           " << endl;
	cout << "                                                 M                MM  M                                           " << endl;
	cout << "                                                 M              MMMMM =                                           " << endl;
	cout << "                                               =ZM            +MMOMMM                                             " << endl;
	cout << "                                               MMM    . :    M+M.MMMM =                                           " << endl;
	cout << "                                             MMMMM    Z I   M?MM MMMMM8                                           " << endl;
	cout << "                                         . M:MMMMM:   8ZOZM. M M MMMMMMMMMMM                                      " << endl;
	cout << "                                          M MMMMMMMM MMMMMMMMMMMMMMMMMMMMMMMMMM                                   " << endl;
	cout << "                                   MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM            MMMMIM~          I.OMZ  " << endl;
	cout << "                                 MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM  MMM   $MMM???IMZ7MMMMMMMMMMMM  " << endl;
	cout << "                     MMMMMMMM.  MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM    " << endl;
	cout << "               MMMMOMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM     " << endl;
	cout << "               MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM       " << endl;
	cout << "                MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM        " << endl;
	cout << "                MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM         \n" << endl;
	cout << "               oooo     oooo            o88                   oooo     oooo                                  " << endl;
	cout << "                8888o   888   ooooooo   oooo  oo oooooo        8888o   888  ooooooooo8 oo oooooo oooo  oooo  " << endl;
	cout << "                88 888o8 88   ooooo888   888   888   888       88 888o8 88 888oooooo8   888   888 888   888  " << endl;
	cout << "                88  888  88 888    888   888   888   888       88  888  88 888          888   888 888   888  " << endl;
	cout << "               o88o  8  o88o 88ooo88 8o o888o o888o o888o     o88o  8  o88o  88oooo888 o888o o888o 888o88 8o " << endl;
	cout << "           =====================================================================================================\n" << endl; 
	cout << "                                                1. Start a New Game\n" << endl;
	cout << "                                                2. Load a Saved Game\n" << endl;
	cout << "                                                3. Ship Configuration Editor\n" << endl;
	cout << "                                                4. Credits\n" << endl;
	cout << "                                                5. Quit\n" << endl;
}

//   Displays a big number 3. Used with the battle start graphic.
void dispBig3()
{
	dispTransition();
	dispTransition();
	cout << "                                                        ooooooo   " << endl;
	cout << "                                                      o88    888o " << endl;
	cout << "                                                          88888o  " << endl;
	cout << "                                                      88o    o888 " << endl;
	cout << "                                                        88ooo88   " << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

//   Displays a big number 2. Used with the battle start graphic.
void dispBig2()
{
	dispTransition();
	dispTransition();
	cout << "                                                        ooooooo   " << endl;
	cout << "                                                      o88     888 " << endl;
	cout << "                                                            o888  " << endl;
	cout << "                                                         o888   o " << endl;
	cout << "                                                      o8888oooo88 " << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

//   Displays a big number 1. Used with the battle start graphic.
void dispBig1()
{
	dispTransition();
	dispTransition();
	cout << "                                                           oo  " << endl;
	cout << "                                                         o888  " << endl;
	cout << "                                                          888  " << endl;
	cout << "                                                          888  " << endl;
	cout << "                                                         o888o " << endl;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

//   Displays the battle start graphic.
void dispBattleStartGraphic()
{             
	dispTransition();
	dispTransition();
	cout << "                                                                                                                             " << endl;
	cout << "                                                                                                                             " << endl;
	cout << "               @@.                                                                                          /@@              " << endl;
	cout << "                @@@@@@@@                                                                              @@@@@@@@               " << endl;
	cout << "                 @@@  @@@@@@@@*                                                                #@@@@@@@@  @@@                " << endl;
	cout << "                  @@@       %@@@@@@@@                                                    @@@@@@@@*       @@@                 " << endl;
	cout << "                   @@@             @@@@                                                @@@@             @@@                  " << endl;
	cout << "                    @@@              @@@@%                                          @@@@@              @@@                   " << endl;
	cout << "                     @@@                @@@@                                      @@@@                @@@                    " << endl;
	cout << "                     /@@@                 @@@@                                  @@@@                 @@@.                    " << endl;
	cout << "                      &@@@                  @@@@&                            @@@@&                  @@@,                     " << endl;
	cout << "                        @@@@@                  @@@@                        @@@@                  @@@@@                       " << endl;
	cout << "                           @@@@                  @@@@                    @@@@                 *@@@@                          " << endl;
	cout << "                              @@@@                 @@@@&              @@@@&                 @@@@                             " << endl;
	cout << "                                @@@@@                 @@@@          @@@@                 @@@@@                               " << endl;
	cout << "                                   @@@@*                @@@@      @@@@                #@@@@                                  " << endl;
	cout << "                                      @@@%                @@@@#@@@@&                @@@@                                     " << endl;
	cout << "                                        @@@@@                @@@@                @@@@@                                       " << endl;
	cout << "                                           @@@@,           @@@@               &@@@@                                          " << endl;
	cout << "                                              @@@@      @@@@@               @@@@                                             " << endl;
	cout << "                                                @@@@@ @@@@               @@@@&                                               " << endl;
	cout << "                                                   @@@@@              @@@@@                                                  " << endl;
	cout << "                                                 @@@@@              @@@@@@@@#                                                " << endl;
	cout << "                                               @@@@              @@@@#     @@@@                                              " << endl;
	cout << "                                             @@@@             @@@@@          @@@@                                            " << endl;
	cout << "                                          @@@@&             @@@@@@             @@@@&                                         " << endl;
	cout << "                            @@@@@@      @@@@             @@@@/  &@@@@             @@%@      @@@@@@                           " << endl;
	cout << "                          @@@&  @@@@@@@@@@            @@@@@        @@@@@            @%@@@@@@@@  @@@@                         " << endl;
	cout << "                            @@@@    @@@@@&          @@@@              @@@@          @@@@@@    @@@@                           " << endl;
	cout << "                              @@@@#     @%@@@    @@@@*                  %@@@@    @@@@@     @@@@@                             " << endl;
	cout << "                                 @@@@      @@@@@@@@                        @%@@@@@@      @@@@                                " << endl;
	cout << "                              @@@@#@@@@#    @@@@                              @@@&    @@@@@@@@@&                             " << endl;
	cout << "                            @@@@      @@@@    @@@*                          &@@@    @@@@      @@@@                           " << endl;
	cout << "                         .@@@@      @@@@@@@@%  @@@@                        @@@&  @@@@@@@@@      @@@@                         " << endl;
	cout << "                       .@@@@     @@@@@     @@@@  @@@                      @@@  @@@@     @@@@#     @@@#                       " << endl;
	cout << "                     @@@@      @@@@          @@@@@@                        @@@@@@          @@@@     (@@@@                    " << endl;
	cout << "                 @@@@@@@    @@@@.                                                            /@@#@    @@@@@@@                " << endl;
	cout << "               @@@@   @@@@@@@@                                                                  @@@@@@@@   @@@@              " << endl;
	cout << "              @@@      @@@@                                                                        @@@@      @@@             " << endl;
	cout << "               @@@@   @@@@                                                                          @@@@   @@@@              " << endl;
	cout << "                 @@@@@@@                                                                              @@@@@@@                " << endl;
	cout << "                                                                                                                             " << endl;
	cout << "                                                                                                                             " << endl;
	cout << "                          oooooooooo      o   ooooooooooo ooooooooooo ooooo       ooooooooooo oo  " << endl;
	cout << "                           888    888    888  88  888  88 88  888  88  888         888    88 8888 " << endl;
	cout << "                           888oooo88    8  88     888         888      888         888ooo8   8888 " << endl;
	cout << "                           888    888  8oooo88    888         888      888      o  888    oo  88  " << endl;
	cout << "                          o888ooo888 o88o  o888o o888o       o888o    o888ooooo88 o888ooo8888 oo  " << endl;
	cout << endl;
}

//   Displays the Menu for starting a new game.
void dispCreateGameMenuHotseat()
{
	cout << "\n                                    -------------------------------------" << endl;
	cout << "                                    ---          Hotseat Mode         ---" << endl;
	cout << "                                    -------------------------------------\n" << endl;
	cout << "                                            1. Normal Battle\n" << endl;
	cout << "                                            2. Advanced Battle\n" << endl;
	cout << "                                            3. Blitz Battle\n" << endl;
	cout << "                                            4. Back\n" << endl;
}

//   Displays the Menu for connectivity mode selection.
void dispConnModeMenu()
{
	cout << "\n                                    =========================================" << endl;
	cout << "                                    ===          Start a New Game         ===" << endl;
	cout << "                                    =========================================\n" << endl;
	cout << "                                            1. Hotseat Mode\n" << endl;
	cout << "                                            2. Online Mode\n" << endl;
	cout << "                                            3. Versus CPU Mode\n" << endl;
	cout << "                                            4. Back\n" << endl;
}

//   Displays the victory screen, using the Players' names as the Captain Names.
void dispVictory(string winner_, string loser_)
{
	cout << "\n\n\n" << endl;
	cout << "                                        ...............                                           ..  .  .        " << endl;
	cout << "                                     ....=I???????????I..                                           .....          " << endl;
	cout << "                                   ...??????????????????..                                           ...           " << endl;
	cout << "                                   ..I???????????????????..                                           ..           " << endl;
	cout << "                                   .+???????I=++?????????I..                                         .. .         " << endl;
	cout << "                                   .I?????..:I???.???????I..                                         ....      " << endl;
	cout << "                                   . ????I.??????????????I..                                         .I+.       " << endl;
	cout << "                                  ....:....?      ??????I...                                        .77I..         " << endl;
	cout << "                                ...??..???I?       ??I.....                                        . IIII...   " << endl;
	cout << "                               ...??I.???? 7I      I???I..                                        . IIIII:...   " << endl;
	cout << "                               ..=???I??           ??????.                                      .. IIIII.. ..   " << endl;
	cout << "                               ..I?????           ?????? .                                     .: IIII.. 7  .." << endl;
	cout << "                               ..+??????7       ????,....                                     .=7III..+ +++ ..." << endl;
	cout << "                               ...????7          ?????..                                     .?7III.. +++++ 7.." << endl;
	cout << "                                ..???             ???I..                                    . III .7++++++++ ..." << endl;
	cout << "                                 ..??             ???I..                                   . III..++++++++++ I.." << endl;
	cout << "                                  ..?             I??..                                   . III..++++...++++? ..." << endl;
	cout << "                                   ..?7       I????? ..                                  .7II,.?+++++,.++++++ +.." << endl;
	cout << "                                  ....II     ???I:....                                  .III..+++++++:.++++++I .." << endl;
	cout << "                                ...????77   ??I.....                                  ..III..++++++++,:+++++++ ..." << endl;
	cout << "                              ...??          ??I...                                  .+II..?+++++++++.++++++++I .." << endl;
	cout << "                             .. ??            ????=..                .  ..          .?II..++++++...?+.?+?.. ++?...." << endl;
	cout << "                             ..??              ?????..                .... .       .?II..+++++++=...?.++...+++..+..." << endl;
	cout << "                             ..??            7??????=.     .. ...      ....       .7II.=++++++++++:+......++..,++I.." << endl;
	cout << "                             ..????????      I??????I.       ...       ....      .7II.+++++++++++++++++++?+..++++ .." << endl;
	cout << "                        .......+.......I7       ????..       ...        ...     .II?.?++++++++++++++++++++..+++++ .." << endl;
	cout << "                      .???????..I?????????       ??I.         ..        . .    .II..+++++++++++++++++++++..++++++7 .." << endl;
	cout << "                     .+?????I..????              ?I.         . .        . .   .II..+++++++++++++++++++++,.+++++++ ..." << endl;
	cout << "                    ..???????.I??                I.          .  ..............II..+++++++++++++++++++++:.++++++++..." << endl;
	cout << "                    .,??????=.??7         ..?           .,......   .  77777 .II..+++++++++++++++++++++,.++++++++...." << endl;
	cout << "                   ..,??????=.I???7      .?   .....    .77777..777 7777777:.II..+++++++++++++++++++++ .++++++++:..." << endl;
	cout << "                   ...?????=...=???     .I77777    I,....?7+..77,77777777,.II.,++++++++++++++++++++++.+++++++++..." << endl;
	cout << "                  .. I????=.?????I     .777777,.7777.=7777.: ........I77.=II.=+++++++++++++++++++++=.+++++++++..." << endl;
	cout << "                  ..I??7??=,?I  7     ....777..7777.=7777.++..+++++++++.+II.+++++++++++++++++++++++.+++++++++...." << endl;
	cout << "                  ..I?7  ??,?I         I........+7.+7777.++..+++++++++.?II.++++++++++++++++++++++?.+++++++++...." << endl;
	cout << "                  ..I??    ???7   II        ?.....+++++.++.=+++++++++.III.++++++++++++++++++++++,.+++++++++...." << endl;
	cout << "                   ,.I??    77I  .. =.... 7     .+++++=++.++++++++++.III.++++++++++++++++++++++..+++++++++=..." << endl;
	cout << "                      I I      I.?7777777 ?.....++++++++.++++++++++.III.+++++++++++++++++++++?..++++++++++..." << endl;
	cout << "                              ..77I7777.77777=.++++:+++++++++++++ .II..?     7?++++++++?++++.. +++++++++..........?????????????I=....." << endl;
	cout << "                    IIIIII+......... :.I7777:.777I+7+ +++++++77+..+77III,..,:::::?7I77.......: ......,........,++.......????...?,....." << endl;
	cout << "                I7?7IIII7I:=7IIIIII7.II..IIIII+.....=   7?... ..:7=. 7.::II+, ??:......7IIII7I,+++++++=,....,+++++++++,:: ==.........." << endl;
	cout << "                ..........=?......,,:: IIII7+,.IIIIII.....IIIII+I?I7  .7:.. +7I I I+II?III   IIIIIIIIIIIII?+,...:=++= ,.....,IIIIII..:" << endl;
	cout << "                             II7+IIIIII             IIIIIII   II=:....... I         III         IIII=......+= ::,..... 7IIIIII+.....:?" << endl;
	cout << "                                                                                              III=.IIIIIIIIIIIIII????????????I+....:?I\n\n\n" << endl;
	cout << "                   Captain " << loser_ << "'s fleet was forced to mount a retreat, paddling away with the wreckage of their pride.\n" << endl;
	cout << "                   The fleet of Captain " << winner_ << " reveled in their victory over their enemies.\n\n\n\n" << endl;
	cout << "              ____    ____  __    ______ .___________.  ______   .______     ____    ____  __" << endl;
	cout << "              \\   \\  /   / |  |  /      ||           | /  __  \\  |   _  \\    \\   \\  /   / |  |" << endl;
	cout << "               \\   \\/   /  |  | |  ,----'`---|  |----`|  |  |  | |  |_)  |    \\   \\/   /  |  | " << endl;
	cout << "                \\      /   |  | |  |         |  |     |  |  |  | |      /      \\_    _/   |  |" << endl;
	cout << "                 \\    /    |  | |  `----.    |  |     |  `--'  | |  |\\  \\----.   |  |     |__| " << endl;
	cout << "                  \\__/     |__|  \\______|    |__|      \\______/  | _| `._____|   |__|     (__)\n\n" << endl;
	cout << "                   Congratulations Captain " << winner_ << ", you won!\n\n" << endl;


}

//   Displays the surrender screen, using the Players' names as the Captain Names.
void dispSurrender(string winner_, string loser_)
{
	cout << "\n\n\n" << endl;
    cout << "                                                MMMZ                                                                " << endl;
    cout << "                                                MMMMM                                                               " << endl;
    cout << "                                                 MMMMM.                                                             " << endl;
    cout << "                                            MM.   MMMMM8                                                            " << endl;
    cout << "                                          MM  MM.  .MMMMM                                                           " << endl;
    cout << "                                         MM .. ?M$   MMMMM      .                                                   " << endl;
    cout << "                                        MM      .MM   MMMMM.      I        M                                        " << endl;
    cout << "                                    .  MM        .MM   MMMMM .    .Z        M.                                      " << endl;
    cout << "                                      ,M.        . .M   MMMMMO     .N        M,                                     " << endl;
    cout << "                                    . M..           .MM  MMMMMM      M.       MM         . .                        " << endl;
    cout << "                                     MM               MM  MMMMMM      M        NM..       M                         " << endl;
    cout << "                                    DM..               MM  MMMMMM      M.       IM       . M                        " << endl;
    cout << "                  MMMMMMMMM,.  .  .MM                   MM  MMMMMM.     M         D.        ..                      " << endl;
    cout << "                MMM.    .MMMMMMMMMMMI                    8M  MMMMMM     .M         M                                " << endl;
    cout << "                .MM   .     .OMMMM                        MM  MMMMMM    . M        .O                               " << endl;
    cout << "                  MM                                       MM .MMMMMM      M                                        " << endl;
    cout << "                   MM                                      ?M7 .MMMMMM .    D                                       " << endl;
    cout << "                    M=                                      MM..,MMMMM,     ...                                     " << endl;
    cout << "                     M=                                     ,MM   MMMMM                                             " << endl;
    cout << "                      M.                                    .MM   .MMMMM                                            " << endl;
    cout << "                      MM .                               MMMMMMZ    MMMMM                                           " << endl;
    cout << "                      MM.                               MMMMMMMM    MMMMMM                                          " << endl;
    cout << "                    .  MM  .                           MMM8.   .     MMMMM8.                                        " << endl;
    cout << "                       MM                             MMZ ..          MMMMM        .                  M             " << endl;
    cout << "                       MM.                            M=               MMMMM      MMM        ..      ..M            " << endl;
    cout << "                      8MM          .   .            .MM                MMMMMM. . MM,:M.        .M       M           " << endl;
    cout << "                      MM~          MMMMMMM        .=MM.                .MMMMMM  MM,:,,M.         M.      M.      M  " << endl;
    cout << "                      MM   .      MM .MMMMMMM,   IMMM                  . MMMMM7MM:,,,:MM:ZMM       M    .. M     .MN" << endl;
    cout << "                      MM         MM .  MMMMMMMMMMMMM   .                 MMMMMMM?,:,,:,MM,,M,      O    .  M.    .M " << endl;
    cout << "                    .MM .      .MM       MMMMMMMMMM                 ..MMMMMMMMM~,:,,:,,MM,,,M   .  M      ,         " << endl;
    cout << "                     MM.      .MM         MMMMMMM                    MMMMMM:,:,:,:,:,,,MM,,,MM     M     .          " << endl;
    cout << "                    MMM   .  MMM             . .                   ..M~:,:,:,,,,:,:,,,MMM,,:MM    .                 " << endl;
    cout << "                    MM . MMMMMMM .                           .     .MM:,:,:,,,,,,::,:MMMM,,:MM   .M        .        " << endl;
    cout << "                   MM  MMMMMMMD                 . .        M       MM,,,:,,,::MMMMMMMMMM,,MMMM.                     " << endl;
    cout << "                  .MM MMMMMMM.                     M      N.     .MMM,:,:,,,,::MMMMMNN,:MMMNMM,                     " << endl;
    cout << "                   MMMMM...                       MM      M       MM,,:,:,,:,::,MM$,,~MMM+::,MM                     " << endl;
    cout << "                   MMM                           .M      M      .MMM:,:,:,,,:,,:OMMMM~:,:,:,MMO                     " << endl;
    cout << "                   MM                           .MM     M       .MM,,,:,:,,,:,:,,MM:,,:,,,,OMM                      " << endl;
    cout << "                 . MM.                           M      M        MMMI,::,,::,,,,:,MMM:,,,$MMM  .                    " << endl;
    cout << "                  .MM                           MM   . M          MMM$,:,,,,::,,,,MMMMMMMMMM8,                      " << endl;
    cout << "                . . .                           M, .    ..M.      .IMM~,,,:,,:,,:,MM,,,,,,,,MM.                     " << endl;
    cout << "                                                MM        .N.       MMM,,,:,:,,,,,MM,,,,::?MMM                      " << endl;
    cout << "                                                   N                 MMM:,,,:,:,:,MMMMMMMMMMM                       " << endl;
    cout << "                                                    ~               .MMMO,,:,:,,,:M+MMMMMMMM,                       " << endl;
    cout << "                                                                      MMM:,,:,,:,N,,:MMMMMMM                        " << endl;
    cout << "                                                                      MMMM,,,:,:,,,:,,MMMMMMM                       " << endl;
    cout << "                                                                        MMM,,:,,,,:,,MMMMMMMMM                       " << endl;
    cout << "                                                                       .MMM::,::,,:,MMM   MMMMM                      " << endl;
    cout << "                                                             .         . MM~,,,:,,,:M    .MMMMM,                     " << endl;
    cout << "                                                                        .MMM,,,,,:,:M      ~MMM                      " << endl;
    cout << "                                                             .           ,MM,,:,:,,$M       .                        " << endl;
    cout << "                                                                          MM,,,,:,,MM                                " << endl;
    cout << "                                                              .           MM,,:,:,,MM                                " << endl;
    cout << "                                                                          MM,,.....                                  \n\n\n" << endl;
	cout << "                   Captain " << loser_ << " lost the will to fight after witnessing the fall of their crew.\n" << endl;
	cout << "                   Their attacks were no match for " << winner_ << "'s strategical and tactical prowess.\n\n\n\n" << endl;
	cout << "              ____    ____  __    ______ .___________.  ______   .______     ____    ____  __" << endl;
	cout << "              \\   \\  /   / |  |  /      ||           | /  __  \\  |   _  \\    \\   \\  /   / |  |" << endl;
	cout << "               \\   \\/   /  |  | |  ,----'`---|  |----`|  |  |  | |  |_)  |    \\   \\/   /  |  | " << endl;
	cout << "                \\      /   |  | |  |         |  |     |  |  |  | |      /      \\_    _/   |  |" << endl;
	cout << "                 \\    /    |  | |  `----.    |  |     |  `--'  | |  |\\  \\----.   |  |     |__| " << endl;
	cout << "                  \\__/     |__|  \\______|    |__|      \\______/  | _| `._____|   |__|     (__)\n\n" << endl;
	cout << "                   Congratulations, Captain " << winner_ << "! You won!\n\n" << endl;
}

//   Loads Custom Configurations from the file "shipconfig.dat".
void loadCustomConfigs()
{
	cout << "Entered loadCustomConfigs()" << endl;
}