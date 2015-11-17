#include "caf_epoller.h"

namespace CAF
{
	CAF_Epoller::CAF_Epoller(bool isEt) : _et(isEt)
	{
		_max_connections = 0;
		_epoll_fd = -1;
		_pevs = NULL;
	}

	CAF_Epoller::~CAF_Epoller()
	{
		if (NULL != _pevs)
		{
			delete[] _pevs;
			_pevs = NULL;
		}
		
		//使用完epoll后，要关闭epoll_create时创建的fd, 否则fd泄漏.
		if(_epoll_fd > 0)
		{
			close(_epoll_fd);
		}
	}

	void CAF_Epoller::ctrl(int32_t fd, long long data, uint32_t events, int op)
	{
		struct epoll_event ev;
		ev.data.u64 = data;
		if (_et)
		{
			ev.events = events | EPOLLET;
		}
		else
		{
			ev.events = events;
		}

		epoll_ctl(_epoll_fd, op, fd, &ev);
	}

	void CAF_Epoller::create(int max_connections)
	{
		_max_connections = max_connections;
		_epoll_fd = epoll_create(_max_connections + 1);
		if (_pevs != NULL)
		{
			delete[] _pevs;
		}

		_pevs = new epoll_event[_max_connections + 1];
	}
	
	void CAF_Epoller::add(int32_t fd, long long data, uint32_t events)
	{
		ctrl(fd, data, events, EPOLL_CTL_ADD);
	}

	void CAF_Epoller::mod(int32_t fd, long long data, uint32_t events)
	{
		ctrl(fd, data, events, EPOLL_CTL_MOD);
	}

	void CAF_Epoller::del(int32_t fd, long long data, uint32_t events)
	{
		ctrl(fd, data, events, EPOLL_CTL_DEL);
	}

	void CAF_Epoller::wait(int millseconds)
	{
		return epoll_wait(_epoll_fd, _pevs, _max_connections + 1, millseconds);
	}
}