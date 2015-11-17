#ifndef _CAF_ERROR_H_
#define _CAF_ERROR_H_

#define CAFGetLastError() errno
#define CAFSocketGetLastError() errno

namespace CAF
{
	enum 
	{
		S_CAF_SUCCESS,
		E_CAF_NULL_POINTER = -10000,
		E_CAF_TIMEOUT,
		E_CAF_SYSERROR,
	};

	//char* getCAFLastError(int32_t errorcode, char* buf, int32_t buf_len);
}

#endif
