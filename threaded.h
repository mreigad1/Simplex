/******************************************************************************/
/** Threaded:                                                                **/
/**     Threaded presents an abstract class to be implemented by children    **/
/**     classes to present an easy interface for threading classes           **/
/******************************************************************************/
namespace simplex{
    struct threadedImpl;

    class threaded {

        public:

            /*****************************************************************/
            /* Threaded object constructor with parameters                   */
            /* @param stack_size is the size in bytes to allocate for        */
            /*        thread stack                                           */
            /* @param delay_ms is the number of milliseconds to wait after   */
            /*        startWorker() invocation before periodically executing */
            /* @param frequency is the maximum number of times per second    */
            /*        the classes worker method should execute               */
            /*****************************************************************/
            threaded(size_t stack_size, double delay_ms, double frequency);

            /*****************************************************************/
            /* Threaded object default constructor will allocate undefined   */
            /*     implementation default stack size with no delay and       */
            /*     continuous execution of worker task                       */
            /*****************************************************************/
            threaded();

            /*****************************************************************/
            /* Threaded object destructor                                    */
            /*****************************************************************/
            ~threaded();

            /*****************************************************************/
            /* startWorker method will start worker thread                   */
            /* NOTE: this will not block on delay                            */
            /*****************************************************************/
            void startWorker();

            /*****************************************************************/
            /* stopWorker will notify worker thread to terminate and join    */
            /* NOTE: to join thread waitOnWorker must be called              */
            /*****************************************************************/
            void stopWorker();

            /*****************************************************************/
            /* waitOnWorker will block parent thread on this child thread    */
            /*     until childThread is joined                               */
            /*****************************************************************/
            void waitOnWorker();

        protected:

            /*****************************************************************/
            /* worker is pure virtual method to be run periodically by       */
            /*     child class                                               */
            /*****************************************************************/
            virtual void worker() = 0;

        private:

            /*****************************************************************/
            /* launchWorker provides auxilary interface for threads          */
            /* to be launched and managed by implementation                  */
            /*****************************************************************/
            static void launchWorker(void* p);

            /*****************************************************************/
            /* data member pointer to implementation of thread type          */
            /*****************************************************************/
            threadedImpl* impl;
    };
};