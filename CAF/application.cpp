#include "caf_application.h"
#include "caf_log_manager.h"

namespace CAF
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::start()
	{
	}

	void Application::stop()
	{}

	void Application::reload()
	{}

	void Application::init()
	{	
		LogManager::getInstance()->init();
	}
}


