#include<iostream>
#include<vector>
#include<string>
#include"levenshtein_distance.h"

int main()
{
    std::vector<std::string> dictionary
    {
        "apple",
        "apparently",
        "appears",
        "appreciate"
    };
    int choice;
    int willContinue;
    do
    {
    std::cout << "Choose a index from the list.\n";
    std::cout << "1. Compare 2 strings using user input.\n";
    std::cout << "2. Compare a string with in-built dictionary using default tolerance.\n";
    std::cout << "3. Compare a string with in-built dictionary using custom tolerance.\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter a choice: ";

    std::cin >> choice;

    switch (choice)
    {
    case 1:
    {
        std::string userInput1;
        std::string userInput2;
        std::cout << "Enter the first string: ";
        std::cin >> userInput1;
        std::cout << "Enter the second string: ";
        std::cin >> userInput2;
        int distance = calculateLevenshteinDistance(userInput1, userInput2);
        std::cout << "Levenshtein distannce between " << userInput1 << " and " << userInput2 << " is " << distance << ".";
        break;
    }
    case 2:
    {
        std::string userInput;
        std::cout << "Enter a string: ";
        std::cin >> userInput;
        std::vector<std::string> suggestions;
        int tolerance = 2;

        for(auto word : dictionary)
        {
            int dist = calculateLevenshteinDistance(word, userInput);

            if(dist <= tolerance)
            {
                suggestions.push_back(word);
            }
        }

        std::cout << "User Input :" << userInput;
        if(suggestions.size() > 0)
        {
            std::cout << "Did you mean? ";
            for(auto word : suggestions)
            {
                std::cout << word << " ";
            }
        }
        break;
    }
    case 3:
    {
        std::string userInput;
        std::cout << "Enter a string: ";
        std::cin >> userInput;
        std::vector<std::string> suggestions;
        int tolerance;
        std::cout << "Enter the tolerance level: ";
        std::cin >> tolerance;

        for(auto word : dictionary)
        {
            int dist = calculateLevenshteinDistance(word, userInput);

            if(dist <= tolerance)
            {
                suggestions.push_back(word);
            }
        }

        std::cout << "User Input :" << userInput;
        if(suggestions.size() > 0)
        {
            std::cout << "Did you mean? ";
            for(auto word : suggestions)
            {
                std::cout << word << " ";
            }
        }
        break;
    }
    case 4:
        break;
    default:
        std::cout << "Bad Choice! Try Again.";
        break;
    }
    if(choice == 4)
        break;
    
    std::cout << "\n\n";
    std::cout << "Do you wish to continue? \n1. Yes \n2. No \n";
    std::cin >> willContinue;
    std::cout << "\n";
    } while(willContinue == 1);

    std::cout << "Thank you for playting.\n";

    return 0;
}