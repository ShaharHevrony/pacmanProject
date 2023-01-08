//
// Created by Shahar Hevrony on 03/01/2023.
//

#include "createLevel.h"
#include "resourcesManager.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include <string> 
#include <sstream>



CreateLevel::CreateLevel(sf::RenderWindow& window): m_window(&window), m_board(1){
    // getRowAndCol();

}

void CreateLevel::run() {


    for (int index = 0; index < OBJECT; index++) {
        sf::Sprite tempSpr;
        sf::Texture* tempText = m_board.getTexture(index);
        tempSpr.setTexture(*tempText);
        if (index < 2) {
            tempSpr.setPosition(OBJ_COL, OBJ_ROW + index * SPACE_SIZE);
        }
        else if (index < 4) {
            tempSpr.setPosition(OBJ_COL + 120, OBJ_ROW + (index - 2) * SPACE_SIZE);
        }
        else if (index < 6) {
            tempSpr.setPosition(OBJ_COL + 120 * 2, OBJ_ROW + (index - 4) * SPACE_SIZE);
        }
        else if (index < 8) {
            tempSpr.setPosition(OBJ_COL + 120 * 3, OBJ_ROW + (index - 6) * SPACE_SIZE);
        }
        else {
            tempSpr.setPosition(OBJ_COL + 120 * 4, OBJ_ROW + (index - 8) * SPACE_SIZE);
        }
        tempSpr.setScale(OBJ_SCALE_SIZE, OBJ_SCALE_SIZE);
        m_menu.push_back(tempSpr);
    }

    int tempRow = 0;
    int tempCol = 0;


    //while the window is open
    while (m_window->isOpen()){
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("levelBackground.png")) {
            //Error loading image
        }
        sf::Sprite backgroundSprite(backgroundTexture);
        backgroundSprite.setScale(0.4,0.4);
        backgroundSprite.setColor(sf::Color::White);
        m_window->draw(backgroundSprite);
        print(tempRow, tempCol);
        m_window->display();

        if (auto event = sf::Event{}; m_window->waitEvent(event)){
            switch (event.type) {
                case sf::Event::Closed: {
                    m_window->close();
                    break;
                }
                    //if the user clicks on the window
                case sf::Event::MouseButtonReleased: {
                    handleMouseButton(event.mouseButton);
                    break;
                }
                case sf::Event::MouseMoved: {
                    m_inBounds = handleMouseMoved(tempRow, tempCol);
                }
            }
        }
    }
}

void CreateLevel::print(int row, int col) {

    sf::Font font;
    font.loadFromFile("HappyMonkey.ttf");
    sf::Text text("Menu", font, MENU_TEXT_SIZE);
    text.setFillColor(sf::Color(500, 160, 28));
    text.setOutlineThickness(2);
    text.setOutlineColor(sf::Color(600, 100, 28));
    text.setPosition(1300, 40);

    for (int i = 0; i < m_board.getRow(); i++) {
        for (int j = 0; j < m_board.getCol(); j++) {
            m_window->draw(m_board.getRectangle(i, j));
        }
    }
    if (m_inBounds) {
        sf::RectangleShape rectangle = m_board.getRectangle(row, col);
        rectangle.setOutlineThickness(2);
        rectangle.setOutlineColor(sf::Color::Black);
        m_window->draw(rectangle);
    }
    //loop that draw the menu
    for (int i = 0; i < OBJECT; i++) {
        m_window->draw(m_menu[i]);
    }

    std::vector<std::vector<Object>> obj = m_board.getObj();
    float tileSize = m_board.getTile();
    tileSize /= TILE_SIZE;
    //draw the sprite
    for (int row = 0; row < obj.size(); row++) {
        for (int col = 0; col < obj[row].size(); col++) {
            auto sprite = obj[row][col].getSprite();
            sprite.setScale(tileSize, tileSize);
            sprite.setPosition(obj[row][col].getPosition());
            m_window->draw(sprite);
        }
    }
    m_inBounds = false;
    m_window->draw(text);

}

//function that handel the case in a mouse button
void CreateLevel::handleMouseButton(sf::Event::MouseButtonEvent& event) {
    //get the location of the click
    auto location = m_window->mapPixelToCoords({ event.x, event.y });
    //loop that go on the object in the menu and check if the user cklik on one of them
    for (int index = 0; index < OBJECT; index++){
        //if the user click on the object in undex place
        if (m_menu[index].getGlobalBounds().contains(m_window->mapPixelToCoords({event.x, event.y}))) {
            m_currObj = index;
            switch (index){
                //if click on eraser
                case eraser:{
                    //function that make the object bigger
                    outLine(index);
                    break;
                }
                    //if click on restart
                case restart:{
                    //function that make the object bigger
                    outLine(index);
                    std::cout << "Enter a row and col numbers:" << std::endl;
                    std::cin >> m_rowCurr >> m_colCurr;
                    m_board.setRow(m_rowCurr);
                    m_board.setCol(m_colCurr);
                    //go from the beninge of the controller
                    m_board.createBoard();
                    //restart pacmen count to zero
                    m_board.setCountPac();
                    return;
                    break;
                }
                    //if click on save
                case save:{
                    //function that make the object bigger
                    outLine(index);
                    if (isValid()) {
                        saveLevel();
                    }
                    break;

                }
                default:{
                    //if click of any of the other objects
                    m_menu[m_currObj].setScale(0.03, 0.03);
                    //function that make the object bigger
                    outLine(index);
                    break;
                }
            }
            m_currObj = index;
        }
        //function that handel the object the user choose
        m_board.handleObj(m_currObj, event, *m_window);
    }
}

//function that make the object that beeen selected bigger
void CreateLevel::outLine(int index) {
    for (int index = 0; index < 10; index++) {
        m_menu[index].setScale(OBJ_SCALE_SIZE, OBJ_SCALE_SIZE);
    }
    m_menu[index].setScale(OBJ_SCALE_SIZE + 0.01, OBJ_SCALE_SIZE + 0.01);
}

//function that check if the board is valid befor saving him
bool CreateLevel::isValid() {
    if (m_board.getPacmanCount() != 1 && m_board.getDoorCount() != m_board.getKeyCount()) {
        std::cout << "You need to have one pacman and the same number of doors and keys on the board to save"
                  << std::endl;
        return false;
    } else if (m_board.getPacmanCount() != 1) {
        std::cout << "You need to have one pacman on the board to save" << std::endl;
        return false;
    } else if (m_board.getDoorCount() != m_board.getKeyCount()) {
        std::cout << "You need to have the same number of doors and keys on the board to save"
                  << std::endl;
        return false;
    }
    return true;
}

void CreateLevel::saveLevel() {
    std::ofstream boardFile;

    if (std::filesystem::exists("Board.txt")){
        // removing the file
        std::error_code ec;
        std::filesystem::remove("Board.txt", ec);
    }
    boardFile.open("Board.txt");
    if (boardFile.is_open()) {
        boardFile << m_board.getRow() << ' ' << m_board.getCol() << std::endl;
        char c;
        for (int i = 0; i < m_board.getRow(); i++) {
            for (int j = 0; j < m_board.getCol(); j++) {
                c = m_board.getTileObj(i, j).getType();
                boardFile << c;
            }

            boardFile << '\n';
        }
    }
    boardFile.close();
}

bool CreateLevel::handleMouseMoved(int& row, int& col) const{
    sf::Vector2f location = (sf::Vector2f)sf::Mouse::getPosition(*m_window);
    for (row = 0; row < m_board.getRow(); row++) {
        for (col = 0; col < m_board.getCol(); col++) {
            if (m_board.getRectangle(row, col).getGlobalBounds().contains(location)) {
                return true;
            }
        }
    }
    return false;
}
/*
void CreateLevel::getRowAndCol() {
 
    m_window->clear();

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("levelBackground.png")) {
        //Error loading image
    }
    sf::Sprite backgroundSprite(backgroundTexture);
    backgroundSprite.setScale(0.5, 0.5);
    backgroundSprite.setColor(sf::Color::White);
    m_window->draw(backgroundSprite);


    sf::Font font;
    font.loadFromFile("HappyMonkey.ttf");
    sf::Text enter("Enter a row and col numbers:", font, 100);
    enter.setFillColor(sf::Color(0, 0, 0));
    enter.setPosition(50, 50);
    enter.setFont(font);
    m_window->draw(enter);
    m_window->display();


    // Set up a font and a text object to display the numbers
    font.loadFromFile("HappyMonkey.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);



    // Run the program as long as the window is open
    while (m_window->isOpen())
    {
        // Check for input from the user
        sf::Event event;
        while (m_window->pollEvent(event))
        {
            // Close the window if the user presses the "x" button
            if (event.type == sf::Event::Closed)
                m_window->close();

             // Get the two numbers from the user if they press the space bar
            if (event.type == sf::Event::KeyPressed && event.type != sf::Keyboard::Enter)
            {
                sf::Text numbers;
                std::string line;
        
                    line += sf::Keyboard::Key();
                    numbers.setString(line);
                    numbers.setFillColor(sf::Color(255, 253, 208));
                    numbers.setPosition(60, 50);
                    numbers.setFont(font);
                
                std::stringstream input;
                input << line;
                input >> m_rowCurr >> m_colCurr;

                m_board.setRow(m_rowCurr);
                m_board.setCol(m_colCurr);
            }
        }

        // Update the text to display the numbers
        text.setString("Num1: " + std::to_string(m_rowCurr) + "\nNum2: " + std::to_string(m_colCurr));

        // Clear the window and draw the text
        m_window->draw(text);
        m_window->display();
    }

        
}
    /*
    sf::Text numbers;
    std::string line;
    sf::Event event;

    // Get input from the user
    if (event.type == sf::Event::TextEntered)
    {
        // Get the character that the user entered
        int input = event.text.unicode;

        // Append the character to the text object
        numbers.setString(numbers.getString() + input);
    }
    m_window->clear();
    m_window->draw(enter);
    m_window->draw(numbers);

   

     m_colCurr = 
}
    sf::Text numbers;
    std::string line;
    sf::Event event;
    while (event.type != sf::Keyboard::Enter){
        line += sf::Keyboard::Key();
        numbers.setString(line);
        numbers.setFillColor(sf::Color(255, 253, 208));
        numbers.setPosition(60, 50);
        numbers.setFont(font);
        m_window->clear();
        m_window->draw(enter);
        m_window->draw(numbers);
    }
    std::stringstream input;
    input << line;
    input >> m_rowCurr >> m_colCurr;

    m_board.setRow(m_rowCurr);
    m_board.setCol(m_colCurr);
}
*/

