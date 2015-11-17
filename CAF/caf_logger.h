#ifndef _CAF_LOGGER_H_
#define _CAF_LOGGER_H_

#include "caf_exception.h"
#include "caf_autoptr.h"
#include "caf_shareable.h"

namespace CAF
{
	/*!
	 * \class CAF_Logger_Exception
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
	 * \date 十一月 2015
	 *
	 * Contact: user@company.com
	 *
	 */
	class CAF_Logger_Exception : public CAF_Exception
	{
	public:
		CAF_Logger_Exception(const string& buffer) : CAF_Exception(buffer) {}
		CAF_Logger_Exception(const string& buffer, int err) : CAF_Exception(buffer, err) {}
		~CAF_Logger_Exception() throw() {};
	};

	/*!
	 * \class Logger
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
	 * \date 十一月 2015
	 *
	 * Contact: user@company.com
	 *
	 */
	class Logger : public CAF_Shareable
	{
	public:
		Logger();
		~Logger();

		void error();
		void debug();
		void warn();
		void info();
	};

	typedef CAF_AutoPtr<Logger> LoggerPtr;
}

#endif

