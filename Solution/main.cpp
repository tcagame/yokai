#include "Application.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "Game.h"

void main ( ) {
	TaskPtr drawer = DrawerPtr( new Drawer( "Resources" ) );
	TaskPtr game = GamePtr( new Game );
	TaskPtr keyboard = KeyboardPtr( new Keyboard ); 

	ApplicationPtr app = Application::getInstance( );
	app->setWindowSize( 1280, 720 );

	app->addTask( Drawer::getTag( ), drawer );
	app->addTask( Game::getTag( ), game );
	app->addTask( Keyboard::getTag( ), keyboard );
}