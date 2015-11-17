#include "caf_exception.h"

namespace CAF
{
	CAF_Exception::CAF_Exception(const string& buffer) : _buffer(buffer), _code(0)
	{

	}

	CAF_Exception::CAF_Exception(const string& buffer, int err) : _buffer(buffer), _code(err)
	{

	}

	CAF_Exception::~CAF_Exception() throw ()
	{
	}

	const char* CAF_Exception::what() const throw()
	{
		return _buffer.c_str();
	}

	void CAF_Exception::getBackTrace()
	{
		/*
		void *tmpArray[64];
		int nSize = backtrace(tmpArray, 64);
		char **symbols = backtrace_symbols(tmpArray, nSize);

		for (int i = 0; i < nSize; i++)
		{
			_buffer += symbols[i];
			_buffer += "\n";
		}

		free(symbols);
		*/
	}
}