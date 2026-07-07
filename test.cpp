#include<iostream>
#include<thread>
#include<fstream>
#include<sstream>  // 必须加
using namespace std;

string getTid()
{
    auto tid = this_thread::get_id();
    stringstream ss;
    ss << tid;
    return ss.str();
}

void task()
{
    ofstream log("testdemo/logs/test.log", ios::app);
    if (!log.is_open())
    {
        cout << "打开日志失败" << endl;
        return;
    }
    string tidStr = getTid();
    string msg = "hello git";
    cout << "线程[" << tidStr << "] " << msg << endl;
    log << "log 线程[" << tidStr << "] " << msg << endl;
    log.close();
}

int main()
{
    thread t1(task);
    thread t2(task);
    t1.join();
    t2.join();
    return 0;
}


