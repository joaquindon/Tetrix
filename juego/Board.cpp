#include "Board.hpp"

void Board::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            target.draw(boardShapes[i][j], state);
        }
    }
}

Board::Board() 
{
    memset(board, 0, sizeof(board));
    for(int i = 0; i < 20; i++)
    {
        for(int j=0; j < 10; j++)
        {
            boardShapes[i][j]=sf::RectangleShape (sf::Vector2f(20,20));
            boardShapes[i][j].setPosition(j*20,i*20);
            boardShapes[i][j].setFillColor (sf::Color(50,50,50));
            boardShapes[i][j].setOutlineThickness(2);
            boardShapes[i][j].setOutlineColor (sf::Color(0,0,0));
        }
    }
}
void Board::UpdateBoardColors()
{
	for(int i = 0; i < 20; i++)
    {
		for(int j = 0; j < 10; j++)
        {
			switch(board[i][j])
            {
				case 0: 
                    boardShapes[i][j].setFillColor(sf::Color(50,50,50));
                    break;
				case 1: 
                    boardShapes[i][j].setFillColor(sf::Color(255,166,0));
                    break;
				case 2: 
                    boardShapes[i][j].setFillColor(sf::Color(245,152,245));
                    break;
				case 3: 
                    boardShapes[i][j].setFillColor(sf::Color(51,204,153));
                    break;
				case 4:
                    boardShapes[i][j].setFillColor(sf::Color(255,110,110));
                    break;
				case 5: 
                    boardShapes[i][j].setFillColor(sf::Color(255,204,77));
                    break;
				case 6: 
                    boardShapes[i][j].setFillColor(sf::Color(166,166,255));
                    break;
				case 7: 
                    boardShapes[i][j].setFillColor(sf::Color(138,194,247));
                    break;
                default:
                    boardShapes[i][j].setFillColor(newPartColor);
                    break;
			}
		}
	}
}

bool Board::InstallParts()
{
    srand(time(NULL));
    this->indNewPart = rand() % 7;
    std::vector<std::vector<bool>> part = this->parts.ConsultPart(this->indNewPart);
    
    int size = (int) part.size();

    indX = 5 - (size/2);
    indY = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (part[i][j])
            {
                if (board[i][j + indX] > 0)
                {
                    return false;
                }
                board[i][j + indX] = -1;
                
            }   
        }
    }
    
    int color = 1 + (rand() % 7);
    indColorNewPart = color;

    switch (color)
    {
        case 1: 
            newPartColor = sf::Color(255,166,0);
            break;
        case 2: 
            newPartColor = sf::Color(245,152,245);
            break;
        case 3: 
            newPartColor = sf::Color(51,204,153);
            break;
        case 4:
            newPartColor = sf::Color(255,110,110);
            break;
        case 5: 
            newPartColor = sf::Color(255,204,77);
            break;
        case 6: 
            newPartColor = sf::Color(166,166,255);
            break;
        case 7: 
            newPartColor = sf::Color(138,194,247);
            break;
    }
    return true;
}

bool Board::UpdateBoard(){
	bool limit = 0;
	int aux;
	
	if(timer >= timerLimit)
    {
		aux = 0;
		for(int i = 18; i >= 0; i--)
        {
			for(int j = 0; j < 10; j++)
            {
				if(board[i][j] == -1 &&
                    board[i + 1][j] <= 0)
                {
					aux++;
				}
			}
		}
		
		if(aux == 4)
        {
			indY++;
			for(int i = 18; i >= 0; i--)
            {
				for(int j = 0; j < 10; j++)
                {
					if(board[i][j] == -1)
                    {
						board[i][j] = 0;
						board[i + 1][j] = -1;
					}
				}
			}			
		}else
        {
			for(int i = 19; i >= 0; i--)
            {
				for(int j = 0; j < 10; j++)
                {
					if(board[i][j] == -1)
                    {
                        board[i][j] = indColorNewPart;   
                    } 
				}
			}
			limit = 1;	
		}
		
		timer=0;
	}
	
	timer++;
	return limit;
}