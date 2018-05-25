#include "maze.h"
#include <unistd.h> //getopt
#include <cstdlib> //atoi
#include <fstream>


void printHelp();   //Skriver ut hjälptext

bool validateArg(char* optarg);

int main(int argc, char* argv[])
{    
    Maze maze;
    
    std::string filename;
    bool writeToFile = false;
    
    int arg;
    while ((arg = getopt(argc, argv, "hvs: c: r: o:")) != -1)
    {
        if(arg == 'v')    std::cout << "Version 1.0" << std::endl;
        if(arg == 'h')
        { 
            printHelp();    
            return EXIT_SUCCESS;   
        }
        if(arg == 's')
        {
            if(validateArg(optarg))
            {
                size_t size = atoi(optarg);

                maze.cols = size;
                maze.rows = size;
            } 
            else 
            {
                std::cout << "Felaktigt argument: --size måste vara en integer." << std::endl;
                return EXIT_FAILURE;  
            }
        }
        if(arg == 'c')  
        {
            if(validateArg(optarg))
            {
                size_t size = atoi(optarg);
                if(size % 2 != 1)   size++;

                maze.cols = size;
            } 
            else 
            {
                std::cout << "Felaktigt argument: --columns måste vara en integer." << std::endl;
                return EXIT_FAILURE; 
            } 
        }
        if(arg == 'r')  
        {
            if(validateArg(optarg))
            {
                size_t size = atoi(optarg);
                if(size % 2 != 1)   size++;

                maze.rows = size;
            }   
            else    
            {
                std::cout << "Felaktigt argument: --rows måste vara en integer." << std::endl;
                return EXIT_FAILURE;
            }
        }
        if(arg == 'o')  
        {
            writeToFile = true;
            filename = std::string(optarg);
        }
        if(arg == '?')  
        {
            std::cout << "Felaktigt argument" << std::endl;
            return EXIT_FAILURE;
        }
    }
    maze.generateMaze();

    if(writeToFile)
    {
        std::ofstream output(filename.c_str());
        output << maze << std::endl;
    }
    else    std::cout << maze << std::endl;
    
    return EXIT_SUCCESS;
}

void printHelp()    //Skriver ut hjälptext
{
    std::cout << std::endl;
    std::cout << "\t--version  | -v.      Skriver ut versionsnummer." << std::endl;
    std::cout << "\t--help     | -h.      Skriver ut detta." << std::endl;
    std::cout << "\t(--size    | -s)N.    Skapa en labyrint med storleken N. Defaultvärde: 10." << std::endl;
    std::cout << "\t(--columns | -c)W.    Skapa en labyrint med bredden W.   Defaultvärde: 10." << std::endl;
    std::cout << "\t(--rows    | -r)H.    Skapa en labyrint med höjden N.    Defaultvärde: 10." << std::endl;
    std::cout << "\t(--input   | -i)file. Använd filen file som indata." << std::endl;
    std::cout << "\t(--output  | -o)file. Använd filen file för utdata. Annars cout." << std::endl;
    std::cout << "\t--check    | -b.      Skriver ut endast \"Solution found\" om en lösning finnes, annars \"Solution not found\"." << std::endl;
    std::cout << std::endl;
}

bool validateArg(char* optarg)
{
    std::string temp(optarg);   //Gör om char* till string
    
    for(int i = 0; i < temp.size(); i++)    //Loopa igenom samtliga
        if(!isdigit(temp[i]))   return false;   //Returnera false om något som inte är en siffra hittas

    return true;    //Om den tar sig igenom hela loopen är samtliga elemenet integers
}