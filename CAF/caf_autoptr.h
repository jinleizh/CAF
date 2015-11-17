#ifndef _CAF_AUTOPTR_H_
#define _CAF_AUTOPTR_H_

namespace CAF
{ 
	/*
		智能指针类, 智能指针类析构时触发资源回收，被管理的资源指针需实现计数
		T 必须继承自CAF_Shareable
	*/
	template<class T>
	class CAF_AutoPtr
	{
	public:
		CAF_AutoPtr(const T* ptr = NULL) : _pElem(ptr)
		{
			if (!_pElem)
			{
				pElem->incRef();
			}
		}

		/*
			c++类的成员函数可以直接访问类对象的私有变量, 但必须是同一个类
		*/
		CAF_AutoPtr(const CAF_AutoPtr& other) : _pElem(other._pElem)
		{
			if (!_pElem)
			{
				_pElem->incRef();
			}
		}
		
		/*
			参数other与当前类不相同,故这里无法直接访问other的私有变量
		*/
		template<class U>
		CAF_AutoPtr(const CAF_AutoPtr<U>& other) : _pElem(NULL)
		{
			_pElem = other.get();
			if (!_pElem)
			{
				_pElem->incRef();
			}
		}

		//不被继承
		~CAF_AutoPtr()
		{
			if (!_pElem)
			{
				if (0 == _pElem->decRef())
				{
					delete _pElem;
					_pElem = NULL;
				}
			}
		}

		CAF_AutoPtr& operator=(const CAF_AutoPtr& r)
		{
			if (_pElem != r._pElem)
			{
				if (!r._pElem)
				{
					r._pElem->incRef();
				}

				if (!_pElem)
				{
					if(0 == _pElem->decRef())
					{
						delete _pElem;
						_pElem = NULL;
					}
				}

				_pElem = r._pElem;
			}
			
			return *this;
		}

		template<class U>
		CAF_AutoPtr& operator=(const CAF_AutoPtr<U>& r) {};
	
		T* operator->() const
		{
			return _pElem;
		}

		CAF_AutoPtr& operator*() const 
		{
			return *_pElem;
		}

		T* get() const
		{
			return _pElem;
		}

		bool isValid() const
		{
			return _pElem ? true : false;
		}
	private:
		T* _pElem;
	};
}

#endif
