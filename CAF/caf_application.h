#ifndef _CAF_APPLICATION_H_
#define _CAF_APPLICATION_H_

namespace CAF
{
	/*!
	 * \class classname
	 *
	 * \ingroup GroupName
	 *
	 * \brief
	 *
	 * TODO: long description
	 *
	 * \note
	 *
	 * \author Admin
	 *
	 * \version 1.0
	 *
	 * \date Ê®Ò»ÔÂ 2015
	 *
	 * Contact: user@company.com
	 *
	 */
	class Application
	{
	public:
		Application();
		~Application();

		//************************************
		// Method:    init
		// FullName:  Application::init
		// Access:    public 
		// Returns:   void
		// Qualifier:
		//************************************
		void init();

		//************************************
		// Method:    start
		// FullName:  Application::start
		// Access:    public 
		// Returns:   void
		// Qualifier:
		//************************************
		void start();

		//************************************
		// Method:    stop
		// FullName:  Application::stop
		// Access:    public 
		// Returns:   void
		// Qualifier:
		//************************************
		void stop();

		//************************************
		// Method:    reload
		// FullName:  Application::reload
		// Access:    public 
		// Returns:   void
		// Qualifier:
		//************************************
		void reload();
	};
}
#endif