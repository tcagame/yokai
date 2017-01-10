#include "Application.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "Game.h"

void main ( ) {
	TaskPtr drawer = DrawerPtr( new Drawer( "Resources" ) );
	TaskPtr keyboard = KeyboardPtr( new Keyboard ); 
	TaskPtr game = GamePtr( new Game );

	ApplicationPtr app = Application::getInstance( );
	app->setWindowSize( 1280, 720 );

	app->addTask( Drawer::getTag( ), drawer );
	app->addTask( Keyboard::getTag( ), keyboard );
	app->addTask( Game::getTag( ), game );
}