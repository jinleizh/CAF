template<typename T>
class CAutoPtr {
  public:
    typedef T elementType;
    
    //const指针无法赋值给非常量指针
    CAutoPtr(T* p = 0) {
      _ptr = p;
      if(_ptr) {
        _ptr->incRef(); 
      }
    }
    
    template<typename U>
    CAutoPtr(constr CAutoPtr<U>& r) {
      _ptr = r._ptr;
      if(_ptr) {
        _ptr->incRef();
      }
    }
    
    CAutoPtr(const CAutoPtr& r) {
      _ptr = r._ptr;
      if(_ptr) {
        _ptr->incRef();
      }
    }
    
    ~CAutoPtr() {
      if(_ptr) {
        _ptr->decRef();
      }
    }
    
    CAutoPtr& operator=(T* p) {
      if(_ptr != p) {
        if(p) {
          p->incRef();
        }
        
        T* tmp = _ptr;
        _ptr = p;
        
        if(tmp) {
          tmp->decRef();
        }
      }
      
      return *this;
    }
    
    template<typename U>
    CAutoPtr& operator=(const CAutoPtr<U>& r) {
      if(_ptr != r._ptr) {
        if(r._ptr) {
          r._ptr->incRef();
        }
        
        T* tmp = _ptr;
        _ptr = r._ptr;
        
        if(tmp) {
          tmp->decRef();
        }
      }
      
      return *this;
    }
    
    CAutoPtr& operator=(const CAutoPtr& r) {
      if(_ptr != r._ptr) {
        if(r._ptr) {
          r._ptr->incRef();
        }
        
        T* tmp = _ptr;
        _ptr = r._ptr;
        
        if(tmp) {
          tmp->decRef();
        }
      }
      
      return *this;
    }
    
    T* get() const {
      return _ptr;
    }
    
    T* operator->() const {
      if(!_ptr) throw NullException() ;
      return _ptr;
    }
    
    T operator*() const {
      if(!ptr) throw NULLException();
      return *_ptr;
    }
    
    operator bool() const {
      return _ptr ? true : false;
    }
    
    void swap(CAutoPtr& r) {
      std::swap(_ptr, r._ptr);
    }
    
  private:
    T* _ptr;
};
