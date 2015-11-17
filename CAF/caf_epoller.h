#ifndef _CAF_EPOLLER_H_
#define _CAF_EPOLLER_H_

#include <sys/epoll.h>

namespace CAF
{
	//epoll操作封装
	class CAF_Epoller
	{
	public:
		enum EpollMode
		{
			EPOLL_MODE_ET,
			EPOLL_MODE_LT,
		};

	public:
		CAF_Epoller(bool isEt = true);
		~CAF_Epoller();

		//创建epoll句柄
		void create(int32_t max_connections);
		
		//注册事件
		void add(int32_t fd, long long data, uint32_t events);

		//修改事件
		void mod(int32_t fd, long long data, uint32_t events);

		//删除事件
		void del(int32_t fd, long long data, uint32_t events);

		int32_t wait(int32_t millsecond);

		//
		struct epoll_event& get(int i)
		{
			return _pevs[i];
		}

	protected:
		void ctrl(int32_t fd, long long data, uint32_t event, int op);

	private:
		int32_t _epoll_fd;
		int32_t _max_connections;
		struct epoll_event *_pevs;
		bool _et;
	};
}

#endif