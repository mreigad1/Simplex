/******************************************************************************/
/** Mutex:                                                                   **/
/**     Mutex provides a simple and portable mutexing mechanism              **/
/**                                                                          **/
/******************************************************************************/

#include <pthread.h>

namespace simplex{

    struct mutexImpl{
        pthread_mutex_t m;
        bool locked;

        mutexImpl() {
        	locked = false;
        	pthread_mutex_init(&m, NULL);
        }

        ~mutexImpl() {
        	if (true == locked) {
        		pthread_mutex_lock();
        	}
        	pthread_mutex_destroy(&m);
        }
    };

    mutex::mutex() : impl(NULL) {
		impl = new mutexImpl;
    }

    mutex::~mutex() {
    	if (impl) {
    		delete impl;
    	}
    	impl = NULL;
    }

    void mutex::lock() {
    	pthread_mutex_lock(&impl->m);
    }

    void mutex::unlock() {
    	pthread_mutex_unlock(&impl->m);
    }

};