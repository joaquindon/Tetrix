#include <iostream>
#include <vector>

class Parts
{
    private:
        std::vector<std::vector<std::vector<bool>>> parts;
    public:
        Parts();
        std::vector<std::vector<bool>> ConsultPart(int ind);
        void rotateParts(int ind);
        void deRotateParts(int ind);
        
};