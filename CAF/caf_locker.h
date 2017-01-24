#ifndef _LOCKER_H_
#define _LOCKER_H_

/**
 * 锁模版类
 * -- 使用方式：构造函数中加锁, 析构函数中解锁
 * -- 优点: 先构造后使用，可以保证线程安全和避免死锁
 *
 * 
 */
template<typename T>
class TLock {
        public:
                TLock(const T& mutex) : _mutex(mutex) {
                        _mutex.lock();
                        _acquired = true;
                }

                ~TLock() {
                        if(_acquired) {
                                _mutex.unlock();
                                _acquired = false;
                        }
                }

                void acquire() const {
                        if(_acquired) {
                                throw exception("LockException");
                        }

                        _mutex.lock();
                        _acquired = true;
                }

                bool tryAcquire() const {
                        return _mutex.tryLock();
                }

                void release() const {
                        if(_acquired) {
                                _mutex.unlock();
                                _acquired = false;
                        } else {
                                throw exception("LockException");
                        }
                }

                bool acquired() {
                        return _acquired;
                }


        private:
                TLock(const TLock&);
                TLock& operator=(const TLock&);

        private:
                const T& _mutex;

                //由于使用时需要先构造锁对象，多个线程访问时，会阻塞在构造函数内，此时线程安全，_acquired不需要用volatie保证可见性
                mutable bool _acquired;
};


#endif
