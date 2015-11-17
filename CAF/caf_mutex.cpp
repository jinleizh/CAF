#include "caf_mutex.h"

namespace CAF
{
	CAF_Mutex::CAF_Mutex()
	{
		int32_t ret = 0;
		pthread_mutexattr_t attr;
		ret = pthread_mutexattr_init(&attr);
		if (0 != ret)
		{
			ret = pthread_mutex_init(&_mutex, NULL);
		}
		else
		{
			ret = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
			ret = pthread_mutex_init(&_mutex, &attr);
			pthread_mutexattr_destroy(&attr);
		}
	}

	CAF_Mutex::~CAF_Mutex()
	{
		pthread_mutex_destroy(&_mutex);
	}

	int32_t CAF_Mutex::lock(uint32_t millseconds)
	{
		if (NULL == _mutex)
		{
			return E_CAF_NULL_POINTER;
		}

		int32_t ret = 0;
		if (millseconds == CAF_MUTEX_LOCK_WAIT_INFINITE)
		{
			ret = pthread_mutex_lock(&_mutex);
		}
		else
		{
			struct timespec ts = {0, 0};
			CAFTime::getAbsTimeSpec(&ts, millseconds);
			ret = pthread_mutex_timedlock(&_mutex, &ts);
		}

		if (0 != ret)
		{
			int32_t e = CAFGetLastError();
			if(ETIMEDOUT == e)
			{
				return E_CAF_TIMEOUT;
			}
			else
			{
				return E_CAF_SYSERROR;
			}
		}

		return 0;
	}

	int32_t CAF_Mutex::tryLock()
	{
		int32_t ret = 0;
		ret = pthread_mutex_trylock(&_mutex);
		return (0 == ret) ? 0 : E_CAF_SYSERROR;
	}

	int32_t CAF_Mutex::unlock()
	{
		int32_t ret = 0;
		ret = pthread_mutex_unlock(&_mutex);
		return (0 == ret) ? 0 : E_CAF_SYSERROR;
	}
}