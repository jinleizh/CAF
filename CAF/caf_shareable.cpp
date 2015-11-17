#include "caf_shareable.h"

namespace CAF
{
	//初始计数为0
	CAF_Shareable::CAF_Shareable() : _count(0)
	{}

	CAF_Shareable::~CAF_Shareable()
	{
		//不需要做任何事, 类成员都是栈上分配的
	}

	void CAF_Shareable::incRef()
	{
		CAF_Guard<CAF_Mutex> locker(&_mutex);
		++_count;
	}

	int32_t CAF_Shareable::decRef()
	{
		CAF_Guard<CAF_Mutex> locker(&_mutex);
		if(_count > 0)
		{ 
			--_count;
		}
		return _count;
	}

	int32_t CAF_Shareable::getCount() const
	{
		CAF_Guard<CAF_Mutex> locker(&_mutex);
		return _count;
	}
}