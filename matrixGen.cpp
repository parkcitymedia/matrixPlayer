  /*
  // initialize random seed
  srand(time(NULL));

  int worldSize, worldSizeCap;
  worldSize = 2;     //initial value
  worldSizeCap = 16; // default world size cap

  // specify world size
  cout << "world size: ";
  cin >> worldSize;

  // generate world
  if (worldSize > worldSizeCap)
  { // check if world size is bigger than 16
      cout << "world size can be no larger than " << to_string(worldSizeCap);
  }
  else
  {
      // generate world of size worldSize
      cout << "generating world of size [" << to_string(worldSize) << "] with ["
  << worldSize * worldSize * worldSize << "] elements...\n"; int
  world[worldSize][worldSize][worldSize]; for (int xpos = 0; xpos < worldSize;
  xpos++)
      {
          for (int ypos = 0; ypos < worldSize; ypos++)
          {
              for (int zpos = 0; zpos < worldSize; zpos++)
              {
                  world[xpos][ypos][zpos] = rand() % 4;
                  cout << "world[" << to_string(xpos) << "," << to_string(ypos)
  << "," << to_string(zpos) << "]: " << to_string(world[xpos][ypos][zpos]) <<
  "\n";
              }
          }
      }
  }
  */