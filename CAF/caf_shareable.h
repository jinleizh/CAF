#ifndef _CAF_SHAREABLE_H_
#define _CAF_SHAREABLE_H_

#include "caf_mutex.h"
#include "caf_guard.h"

namespace CAF
{
	class CAF_Shareable
	{
	public:
		//被继承
		virtual ~CAF_Shareable();

		void incRef();
		int32_t decRef();
		int32_t getCount() const;
		
	protected:
		//禁止显式构造, 可通过子类构造
		CAF_Shareable();

	private:
		int _count;
		CAF_Mutex _mutex;
	
	private:
		//禁用
		CAF_Shareable(const CAF_Shareable&);
		CAF_Shareable& operator=(const CAF_Shareable&);
	};
}

#endif //
