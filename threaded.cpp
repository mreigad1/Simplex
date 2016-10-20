/******************************************************************************/
/** Threaded:                                                                **/
/**     Threaded presents an abstract class to be implemented by children    **/
/**     classes to present an easy interface for threading classes           **/
/******************************************************************************/

#include <pthread.h>
#include <unistd.h>

namespace simplex{

    const int ms_per_second = 1000;
    const int us_per_ms = 1000;
    const int us_per_second = us_per_ms * ms_per_second;

    struct threadedImpl {
        pthread_t thread;
        pthread_attr_t attr;

        threadedImpl() {

        }

        ~threadedImpl() {

        }
    };

    threaded::threaded() {
        impl = new threadedImpl;
    }

    threaded::threaded(size_t stack_size, double delay_ms, double frequency) {
        impl = new threadedImpl;
    }

    ~threaded::threaded() {
        if (impl) {
            delete impl;
        }
        impl = NULL;
    }

    void threaded::startWorker() {

    }

    void threaded::stopWorker() {

    }

    void threaded::waitOnWorker() {

    }

    void threaded::launchWorker(void* p) {
        threaded* threadedObj = (threaded*) p;

    }

};