#ifndef _CAF_SINGLETON_H_
#define _CAF_SINGLETON_H_

namespace CAF {
		template <class T>
		class SingleTon
		{
		public:
			typedef T instance_type;
			typedef volatile T volatile_type;

			static T* getInstance()
			{
				if (NULL == _pInstance)
				{
					if (_bDestroyed)
					{
						_bDestroyed = false;
					}

					_pInstance = new T;
				}

				return (T*)_pInstance;
			}

			//必然要被继承
			virtual ~SingleTon() {};

		protected:
			static volatile T* _pInstance;
			static bool _bDestroyed;
			SingleTon() {};
			SingleTon(const SingleTon&);

			template<class U>
			SingleTon(const SingleTon<U>&);

			SingleTon& operator=(const SingleTon&);

			template<class U>
			SingleTon& operator=(const SingleTon<U>&);

			static void destroyInstance()
			{
				if (!_bDestroyed)
				{
					delete _pInstance;
					_pInstance = NULL;
					_bDestroyed = true;
				}
			}
		};

		template<class T>
		bool SingleTon<T>::_bDestroyed = false;

		template<class T>
		volatile T* SingleTon<T>::_pInstance = NULL;
}

#endif
