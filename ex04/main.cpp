#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string file = av[1];
        std::ifstream filename(file);
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string line;
        std::ofstream file_replace(file + ".replace");
        if (!filename)
        {
            std::cout << "File not found" << std::endl;
            return 1;
        }
        while (std::getline(filename, line))
        {
            size_t pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos) {
                line.replace(pos, s1.length(), s2);
                pos += s2.length(); 
            }
            file_replace << line << std::endl;
        }
    }
    else
        std::cout << "Wrong Arguments" << std::endl;
}
