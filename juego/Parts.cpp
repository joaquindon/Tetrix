#include "Parts.hpp"

Parts::Parts()
{
    parts = 
    {
        {{1,1},
         {1,1}},

        {{0,0,0,0,0},
         {0,1,1,0,0},
         {0,0,1,1,0},
         {0,0,0,0,0},
         {0,0,0,0,0}},

        {{0,0,0,0,0},
         {0,0,1,1,0},
         {0,1,1,0,0},
         {0,0,0,0,0},
         {0,0,0,0,0}},

        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,0,1,0,0},
         {0,1,1,0,0},
         {0,0,0,0,0}},

        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,0,1,0,0},
         {0,0,1,1,0},
         {0,0,0,0,0}},

        {{0,0,0,0,0},
         {0,0,1,0,0},
         {0,0,1,1,0},
         {0,0,1,0,0},
         {0,0,0,0,0}},

        {{0,0,1,0},
         {0,0,1,0},
         {0,0,1,0},
         {0,0,1,0}},

    };
}

std::vector<std::vector<bool>> Parts::ConsultPart(int ind)
{
    return parts[ind];
}

void Parts::rotateParts(int ind)
{
    std::vector<std::vector<bool>> vAux = parts[ind];
    int indJ = 0, indI = 0;
    int size = (int)parts[ind].size();

    for (int i = 0; i < size; i++)
    {
        for(int j = (size - 1); j >= 0; j--)
        {
            parts[ind][indI][indJ] = vAux[j][i];
            
        }

        indI++;
        indJ = 0;
    }
}

void Parts::deRotateParts(int ind)
{
    std::vector<std::vector<bool>> vAux = parts[ind];
    int indJ = 0, indI = 0;
    int size = (int)parts[ind].size();

    for (int i = (size -1); i >= 0; i--)
    {
        for(int j = 0; j < size; j++)
        {
            parts[ind][indI][indJ] = vAux[j][i];
            
        }

        indI++;
        indJ = 0;
    }
}
        