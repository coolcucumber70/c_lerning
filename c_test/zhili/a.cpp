class Worker : public QObject
{
    Q_OBJECT
public:
    Worker(){}
public slots:
    void emitsig()
    {
        emit sig();
    }
signals:
    void sig();
};

class Thread : public QThread
{
    Q_OBJECT
public：
    Thread(QObject* parent=0):QThread(parent)
    {
    }

    void fun()
    {
        qDebug() << "Thread::fun threadID: " << QThread::currentThreadId();
    }
public slots:
    void slotFun()
    {
        qDebug() << "Thread::slotFun threadID: " << QThread::currentThreadId();
    }
signals:
    void sig();
protected:
    void run()
    {
        QThread::sleep(5);
        qDebug() <<"Thread::run threadID: " << currentThreadId();
        fun();
        slotFun();
        exec();
        qDebug() << "Thread:: exit"；
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Thread thread;
    Worker work;
    QObject::connect(&work, SIGNAL(sig()), &thread, SLOT(slotFun()));
    thread.start();

    qDebug() << "Main threadID: " << QThread::currentThreadId();
    thread.fun();
    thread.slotFun();

    qDebug() << "before signal. threadID: " <<  QThread::currentThreadId();
    work.emitsig();
    qDebug() << "after signal. threadID: " <<  QThread::currentThreadId();

    return a.exec();
}