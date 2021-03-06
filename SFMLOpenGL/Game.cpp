#include <Game.h>
#include <gl/GL.h> 
#include <gl/GLU.h>

int currentTriangle = 0;

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	//Added Part 2
	glClearColor(0.0f, 100.0f, 0.0f, 0.0f); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	std::cout << "Pres Q,W,E,R,T,Y,U,I,J to change triangle" << std::endl;
	std::cout << "Press Up and Down on the arrow keys to rotate" << std::endl;
	std::cout << "Press Left and Right to translate the triangle" << std::endl;
	std::cout << "Press C and V to change the Scale of the Triangle" << std::endl;
	std::cout << "Press A to return the identity triangle i.e reset the triangle" << std::endl;

	isRunning = true;
}

void Game::update()
{
	//cout << "Update up" << endl;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		currentTriangle = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		currentTriangle = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		currentTriangle = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		currentTriangle = 4;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		currentTriangle = 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
	{
		currentTriangle = 6;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
	{
		currentTriangle = 7;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
	{
		currentTriangle = 8;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
	{
		currentTriangle = 9;
	}
	
	//Rotation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		glRotatef(0.1, 0.0f, 0.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		glRotatef(-0.1, 0.0f, 0.0f, 1.0f);
	}

	
	//Translation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		glTranslatef(0.01f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		glTranslatef(-0.01f, 0.0f, 0.0f);
	}

	//Scale
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	{
		glScalef(1.01f,  1.01f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
	{
		glScalef(0.99f, 0.99f, 1.0f);
	}

	//Identity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		glLoadIdentity();
	}
}

void Game::draw()
{
	if (currentTriangle == 0)
	{
		//Initial Triangle
		//cout << "Draw up" << endl;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
		glBegin(GL_TRIANGLES); 
		{ 
			glVertex3f(0.0, 2.0, -5.0); 
			glVertex3f(-2.0, -2.0, -5.0); 
			glVertex3f(2.0, -2.0, -5.0); 
		} 
		glEnd();
	}

	if (currentTriangle == 1)
	{
		//GL Points
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_POINTS);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	if (currentTriangle == 2)
	{
		//Lines
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_LINES);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	if (currentTriangle == 3)
	{
		//Line Strip
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_LINE_STRIP);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	if (currentTriangle == 4)
	{
		//Line Loop
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_LINE_LOOP);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	if (currentTriangle == 5)
	{
		//Strip
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_TRIANGLE_STRIP);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}
	
	if (currentTriangle == 6)
	{
		//Fan
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
		}
		glEnd();
	}

	if (currentTriangle == 7)
	{
		//GL_QUADS
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_QUADS);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(-2, -4.0, -5.0);
		}
		glEnd();
	}

	if (currentTriangle == 8)
	{
		//Quad Strip
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_QUAD_STRIP);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(-2, -4.0, -5.0);
		}
		glEnd();
	}

	if (currentTriangle == 9)
	{
		//Poly
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//cout << "Draw up" << endl;
		glBegin(GL_POLYGON);
		{
			glVertex3f(0.0, 2.0, -5.0);
			glVertex3f(-2.0, -2.0, -5.0);
			glVertex3f(2.0, -2.0, -5.0);
			glVertex3f(-2, -4.0, -5.0);
			glVertex3f(4, -4.0, -5.0);
			glVertex3f(6, -8.0, -5.0);
		}
		glEnd();
	}
	

	window.display();


}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}

