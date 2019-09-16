#include <iostream>
#include <array>
#include <vector>
#include <string>


std::vector<std::string> load_color_vecs(std::array<std::string, 2> peg_array)
 {
     std::vector<std::string> color_vec;
     for(int i=0; i<2; i++)
         {
             color_vec.push_back(peg_array.at(i));
         }
     return color_vec;
 }

void print_2d_vector(std::vector<std::vector<std::string>> color_vec_2d)
{
    for (unsigned int i=0; i<color_vec_2d.size(); i++)
    {
        for (unsigned int j=0; j<color_vec_2d.at(i).size(); j++)
        {
            std::cout << color_vec_2d.at(i).at(j) << " ";
        }
        std::cout << std::endl;
    }
}
        

int main()
{
	//Create a 2D array of std::string type with 3 rows and 2 columns and initialze
    std::array<std::array<std::string, 2>, 3> peg_array {{{"blue","white"},{"green","white"},{"green","white"}}};
    //Create 3 vectors of type std::string
    std::vector<std::string> color_vec1, color_vec2, color_vec3;
    //Call load_color_vecs function to read values from peg_array and store to each vector appropriately
    color_vec1 = load_color_vecs(peg_array.at(0));
    color_vec2 = load_color_vecs(peg_array.at(1));
    color_vec3 = load_color_vecs(peg_array.at(2));
    //Prompt the user to enter the colors of the missing pegs
    std::cout << "Enter color of missing pegs using the picture of the peg tray starting from top row to bottom row. Enter color1, color2 and color3 on the same line with spaces: "<< std::endl;
    //Store user entered colors into string variables
    std::string missing_color1, missing_color2, missing_color3;
    std::cin >> missing_color1 >> missing_color2 >> missing_color3;
    //Insert missing colored pegs into appropriate spots in the vectors
    color_vec1.push_back(missing_color1);
    color_vec2.insert(color_vec2.begin(), missing_color2);
    color_vec3.insert(color_vec3.begin()+1, missing_color3);
    //Display the elements of each vector
    std::cout << "Vector 1: " << color_vec1.at(0) << "  " << color_vec1.at(1) << "  " << color_vec1.at(2) << std::endl;
    std::cout << "Vector 2: " << color_vec2.at(0) << "  " << color_vec2.at(1) << "  " << color_vec2.at(2) << std::endl;
    std::cout << "Vector 3: " << color_vec3.at(0) << "  " << color_vec3.at(1) << "  " << color_vec3.at(2) << std::endl;
    //Create a 2D vector of std::string type of 3 rows and 3 columns
    std::vector<std::vector<std::string>> color_vec_2d {{{color_vec1},{color_vec2},{color_vec3}}};
    //Display size of the 2D vector
    std::cout <<"Size of 2D vector is "<< color_vec_2d[0].size()*color_vec_2d.size()<< " (" << color_vec_2d[0].size() <<"x" << color_vec_2d.size() << ")" << std::endl;
    std::cout<<"The final 2D vector is: "<< std::endl;
    //Call function to read and display 2D vector  
    print_2d_vector(color_vec_2d);
    return 0;
}
