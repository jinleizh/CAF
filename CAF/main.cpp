#include "caf_application.h"
#include "caf_common.h"

using namespace CAF;

int main()
{
	Application g_app;
	
	g_app.init();
	g_app.start();
	g_app.stop();

	std::cout << "success" << std::endl;
	system("pause");

	return 0;
}