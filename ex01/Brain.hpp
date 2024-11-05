#pragma once

#include <iostream>

# define RED_COLOR "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN_COLOR "\x1b[32;01m"
# define BLUE_COLOR "\x1b[34;01m"
# define PURPLE_COLOR "\x1b[38;2;178;58;238;01m"
# define WHITE_COLOR "\x1b[38;2;255;255;255;01m"

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string &idea);

};
