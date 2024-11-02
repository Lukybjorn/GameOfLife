#include <iostream>
#include <SFML/Graphics.hpp>

struct WindowData {

    unsigned int width = 1920;
    unsigned int hight = 1020;
    unsigned int fps = 60;

    bool resized = false;

    void print_size() const {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Space))
        {
            std::cout << "Width: " << width << ", Hight: " << hight << std::endl;
        }
    }
};

int main() {
    sf::Font arial;
    if (!arial.loadFromFile("C:/Windows/Fonts/times.ttf")) return 1;

    WindowData win_data;
    win_data.width = 800;
    win_data.hight = 600;

    sf::RenderWindow window(sf::VideoMode(win_data.width, win_data.hight), "Test window");
    window.setFramerateLimit(win_data.fps);

    while (window.isOpen()) {

        // Start of the event loop
        sf::Event event;

        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            switch (event.type) {
                //Close event
                case sf::Event::Closed:
                    window.close();
                break;

                //Resize event - set it's new parameters in win_data
                case sf::Event::Resized:
                    win_data.width = event.size.width;
                win_data.hight = event.size.height;
                break;

                //Mouse moved inside the window - set it's location in mouse_dat
                case sf::Event::MouseMoved:
                    std::cout << "Mouse moved" << std::endl;
                break;

                //Mouse Button pressed - set the data of the specific button to true
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "Mouse Left" << std::endl;
                    }
                    else if (event.mouseButton.button == sf::Mouse::Right) {
                        std::cout << "Mouse Right" << std::endl;
                    }
                    else if (event.mouseButton.button == sf::Mouse::Middle) {
                        std::cout << "Mouse Wheel" << std::endl;
                    }
                break;

                //Mouse Button pressed - set the data of the specific button to false
                case sf::Event::MouseButtonReleased:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        std::cout << "Mouse Left" << std::endl;
                    }
                    else if (event.mouseButton.button == sf::Mouse::Right) {
                        std::cout << "Mouse Right" << std::endl;
                    }
                    else if (event.mouseButton.button == sf::Mouse::Middle) {
                        std::cout << "Mouse Wheel" << std::endl;
                    }
                break;

                default:
                    break;
            }

            //Start of the display procedure
            window.clear(sf::Color::White);
            window.display();
        }
    }
    return 0;
}
