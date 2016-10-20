/******************************************************************************/
/** Mutex:                                                                   **/
/**     Mutex provides a simple and portable mutexing mechanism              **/
/**                                                                          **/
/******************************************************************************/
namespace simplex{
    struct mutexImpl;

    class mutex {
        public:
            mutex();
            ~mutex();
            void lock();
            void unlock();
        private:
            mutexImpl* impl;
    };
};