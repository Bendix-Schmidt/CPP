/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschmidt <bschmidt@student.42.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:58:04 by bschmidt          #+#    #+#             */
/*   Updated: 2024/11/04 17:28:04 by bschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int    copy_and_replace(std::string& filename, std::string& str1, std::string& str2)
{
     std::ifstream  inFile(filename.c_str());
    if (!inFile)
    {
        std::cerr << "Error: Bad inputfile. Doesn´t exist or can´t be opened" << std::endl;
        return (3);
    }

    std::string     outfile_name = filename + ".replace";
    std::ofstream   outFile(outfile_name.c_str());
    if (!outFile)
    {
        std::cerr << "Error: Could not create the output-file." << std::endl;
        return (4);
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        size_t  pos = 0;
        while ((pos = line.find(str1, pos)) != std::string::npos)
        {
            line.erase(pos, str1.length());
            line.insert(pos, str2);
            pos += str2.length();
        }
        outFile << line << '\n';
    }
    inFile.close();
    outFile.close();
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Wrong input: Use like this: " << argv[0] 
        << "filename, string1, string2" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string str1 = argv[2];
    std::string str2 = argv[3];
    
    if (str1.empty())
    {
        std::cerr << "Error: string1 can´t be empty." << std::endl;
        return (2);
    }
    return (copy_and_replace(filename, str1, str2));
}