#ifndef _CAF_TIME_H_
#define _CAF_TIME_H_

namespace CAF
{
	class CAFTime
	{
	public:
		CAFTime() {};
		~CAFTime() {};

		static uint64_t getTimeStamp();
		static uint64_t getTimeStampMs();
		static uint64_t getTimeStampUs();
		static uint32_t getAbsTimeSpec(struct timespec *ts, int32_t millseconds);
	};
}

#endif
