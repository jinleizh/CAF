#ifndef _CAF_EXCEPTION_H_
#define _CAF_EXCEPTION_H_

#include <stdexcept>

#ifdef IN_LINUX
#include <execinfo.h>
#endif // IN_LINUX

#include <cerrno>
#include <string.h>
using namespace std;

namespace CAF
{
	class CAF_Exception : public exception
	{
	public:
		explicit CAF_Exception(const string& buffer);
		CAF_Exception(const string& buffer, int err);

		virtual ~CAF_Exception() throw();

		virtual const char* what() const throw();

		int getErrCode() 
		{
			return _code;
		}

	private:
		void getBackTrace();

	private:
		string _buffer;
		int _code;
	};
}

#endif
