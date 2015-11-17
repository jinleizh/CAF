#ifndef _CAF_GUARD_H_
#define _CAF_GUARD_H_

namespace CAF
{
	template<class LockerType>
	class CAF_Guard
	{
	public:
		CAF_Guard(const LockerType* mutex) : _locker(mutex)
		{
			if (NULL != _locker)
			{
				if (0 == _locker->lock())
				{
					_locked = true;
				}
			}
		}

		bool isLocked() const
		{
			return _locked;
		}

		//²»¼Ì³Ð
		~CAF_Guard() 
		{
			if (NULL != _locker)
			{
				if (0 == _locker->unlock())
				{
					_locked = false;
				}
			}
		};

	private:
		LockerType* _locker;
		volatile bool _locked;
	};
}

#endif
