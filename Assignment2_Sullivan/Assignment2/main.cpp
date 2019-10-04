#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> mazeVector;

void ReadTextFile(){
    std::ifstream inFile;
    //should find way to determine relative path so maze.txt can be found no matter what
    std::string textFile = "maze.txt";
    inFile.open(textFile);
    if (!inFile) {
        std::cout << "Unable to open file...make sure \"maze.txt\" is contained in working directory" << std::endl;
        exit(1); // terminate with error
    }
    else{
        std::string line;
        while (getline(inFile,line)){
            mazeVector.push_back(line);
        }
    }
    inFile.close();
    return;
}


std::vector<unsigned int> GetCoordinates(){
    unsigned int start_x, start_y, goal_x, goal_y;
    
    bool startBad = true;
    do {
        std::cout << "Enter starting coordinates (e.g. start_x start_y):"<<std::endl;
        std::cin >> start_x >> start_y;
        start_y = 30 -start_y;
        if(!std::cin.fail()){
            if ( start_x>mazeVector[0].length() || start_y>mazeVector.size() ) {
            std::cout << "Starting coordinates out of maze boundary... try again" << std::endl;
            continue;
            }
            if (mazeVector[start_y].at(start_x) == '#'){
                std::cout << "Start position is occupied by maze obstacle... try again" << std::endl;
                continue;
            }
            startBad = false;
        }
        else{
            std::cin.clear(); //This corrects the stream.
            std::cin.ignore(); //This skips the left over stream data.
            std::cout << "Please enter an Integer only." << std::endl;
        }
    }
    while (startBad);
    
    bool goalBad = true;
    do {
        std::cout << "Enter goal coordinates (e.g. goal_x goal_y):"<<std::endl;
        std::cin >> goal_x >> goal_y;
        goal_y = 30 - goal_y;
        if(!std::cin.fail()){
            if ( goal_x>mazeVector[0].length() || goal_y>mazeVector.size() ) {
            std::cout << "Goal coordinates out of maze boundary... try again" << std::endl;
            continue;
            }
            if (mazeVector[goal_y].at(goal_x) == '#'){
                std::cout << "Goal position is occupied by maze obstacle... try again" << std::endl;
                continue;
            }
            goalBad = false;
        }
        else{
            std::cin.clear(); //This corrects the stream.
            std::cin.ignore(); //This skips the left over stream data.
            std::cout << "Please enter an Integer only." << std::endl;
        }
    }
    while (goalBad);
    
    std::vector<unsigned int> coordinatesVector {start_x, start_y, goal_x, goal_y};
    return coordinatesVector;
}

bool FindPath(unsigned int x, unsigned int y) {
    if ( x>mazeVector[0].length() || y>mazeVector.size() ) {
        return false;
    }
    if ( mazeVector[y].at(x) == 'G' ) {
        return true;
    }
    if ( mazeVector[y].at(x) == '#' ) {
        return false;
    }
    if ( mazeVector[y].at(x) == '+' ) {
        return false;
    }
    if ( mazeVector[y].at(x) == 'X' ) {
        return false;
    }
    if ( mazeVector[y].at(x) == ' ' ) {
        mazeVector[y].at(x) = '+';
    }
    
    std::cout << x << " " << 30-y << std::endl;
    //Look/Go North
    if ( FindPath(x, (y-1)) ) {
        return true;
    }
    //Look/Go East
    if ( FindPath((x+1), y) ) {
        return true;
    }
    //Look/Go South
    if ( FindPath(x, (y+1)) ) {
        return true;
    }
    //Look/Go West
    if ( FindPath((x-1), y) ) {
        return true;
    }
    mazeVector[y].at(x) = 'X';
    return false;
}

void DisplayMaze() {
    for (std::string line: mazeVector) {
        std::size_t location = line.find('X');
        while( location != std::string::npos ) {
            // Replace this occurrence of Sub String
            line.replace(location, 1, " ");
            // Get the next occurrence from the current position
            location =line.find('X', location + 1);
        }
        std::cout << line << std::endl;
    }
}

int main()
{
    //Read in maze.txt and store to vector of strings
    ReadTextFile();
    
    //Prompt user to enter starting coordinates and goal coordinates
	std::vector<unsigned int> coordinatesVector {GetCoordinates()};
    
    //store start and goal coordinates
    unsigned int start_x {coordinatesVector[0]}, start_y {coordinatesVector[1]}, goal_x {coordinatesVector[2]}, goal_y {coordinatesVector[3]};
    
    //Draw S and G at start and goal coordinates in maze.txt
    mazeVector[goal_y].at(goal_x) = 'G';
    mazeVector[start_y].at(start_x) = 'S';
    
    //call FindPath() function
    FindPath(start_x, start_y);
    
    //Display maze with solution
    DisplayMaze();
    
	return 0;
}