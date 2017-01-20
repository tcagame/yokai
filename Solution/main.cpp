#include "Application.h"
#include "Drawer.h"
#include "Sound.h"
#include "Keyboard.h"
#include "Game.h"
#include "Device.h"

void main ( ) {
	TaskPtr drawer = DrawerPtr( new Drawer( "Resources" ) );
	TaskPtr sound = SoundPtr( new Sound( "Sound" ) );
	TaskPtr game = GamePtr( new Game );
	TaskPtr keyboard = KeyboardPtr( new Keyboard ); 
	TaskPtr device = DevicePtr( new Device );

	ApplicationPtr app = Application::getInstance( );
	app->setWindowSize( 1280, 720 );

	app->addTask( Drawer::getTag( ), drawer );
	app->addTask( Sound::getTag( ), sound );
	app->addTask( Game::getTag( ), game );
	app->addTask( Keyboard::getTag( ), keyboard );
	app->addTask( Device::getTag( ), device );
}