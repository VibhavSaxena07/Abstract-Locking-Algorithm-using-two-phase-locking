#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;


std::mutex mtx1;          // mutex for critical region/

class MyClass
{
    static std::mutex mx;
public:
    int id;
    MyClass(int id) : id(id) {}
    
    std::mutex m;
    
    
};
void send_mail(int xxx)
{
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
}
void unlockme(MyClass &u1,MyClass &u2,MyClass &u3,MyClass &u4,MyClass &u5, int x)
{
    static std::mutex io_mutex;
    std::lock_guard<std::mutex> lk(io_mutex);
    std::cout << "\nThread " << x << " is unlocking \n";
    std::cout << u1.id << "," << u2.id << "," << u3.id << "," << u4.id <<  " and " << u5.id << " are waiting for locks" <<std::endl;
    
    u1.m.unlock();
    std::cout << u1.id <<" IS UNLOCKED" << std::endl;
    u2.m.unlock();
    std::cout << u2.id <<" IS UNLOCKED" << std::endl;
    u3.m.unlock();
    std::cout << u3.id <<" IS UNLOCKED" << std::endl;
    u4.m.unlock();
    std::cout << u4.id <<" IS UNLOCKED" << std::endl;
    u5.m.unlock();
    std::cout << u5.id <<" IS UNLOCKED" << std::endl;
    send_mail(x);
   
    ;
}

void Lock(MyClass &k1, MyClass &k2, MyClass &k3, MyClass &k4, MyClass &k5, int x)//, MyClass &idx)
{
    
    static std::mutex io_mutex;
    std::lock_guard<std::mutex> lk(io_mutex);
    std::cout << "\nThread " << x << " is trying to lock \n";
    std::cout << k1.id << "," << k2.id << "," << k3.id << "," << k4.id <<  " and " << k5.id << " are waiting for locks" <<std::endl;

    std::lock(k1.m, k2.m, k3.m,k4.m,k5.m);
  

    
    std::cout << "Thread " << x << " Acquiring the lock \n";
    std::cout<< "Key 1(" << k1.id <<") got the lock \n";
    std::cout<< "Key 2(" << k2.id <<") got the lock \n";
    std::cout<< "Key 3(" << k3.id <<") got the lock \n";
    std::cout<< "Key 4(" << k4.id <<") got the lock \n";
    std::cout<< "Key 5(" << k5.id <<") got the lock \n";
    std::cout << k1.id << "," << k2.id <<","<< k3.id << "," << k4.id << "  and  "<< k5.id << "  got locks " << std::endl;
    std::cout<<"GOT ALL LOCKS!!  \n";
    send_mail(x);
    unlockme(k1,k2,k3,k4,k5,x);
    
    
    
    
}



int main ()
{
    
    int arraylist[5][5];
    
    arraylist[0][0] = 1;
    arraylist[0][1] = 14;
    arraylist[0][2] = 23;
    arraylist[0][3] = 42;
    arraylist[0][4] = 31;
    arraylist[1][0] = 2;
    arraylist[1][1] = 15;
    arraylist[1][2] = 24;
    arraylist[1][3] = 14;
    arraylist[1][4] = 92;
    arraylist[2][0] = 3;
    arraylist[2][1] = 16;
    arraylist[2][2] = 25;
    arraylist[2][3] = 44;
    arraylist[2][4] = 23;
    arraylist[3][0] = 4;
    arraylist[3][1] = 17;
    arraylist[3][2] = 26;
    arraylist[3][3] = 45;
    arraylist[3][4] = 32;
    arraylist[4][0] = 76;
    arraylist[4][1] = 7;
    arraylist[4][2] = 34;
    arraylist[4][3] = 72;
    arraylist[4][4] = 94;
    
    MyClass Key1(arraylist[0][0]),Key2(arraylist[0][1]),Key3(arraylist[0][2]),Key4(arraylist[0][3]),Key5(arraylist[0][4]), Key6(arraylist[1][0]),Key7(arraylist[1][1]),Key8(arraylist[1][2]),Key9(arraylist[1][3]),Key10(arraylist[1][4]),Key11(arraylist[2][0]),Key12(arraylist[2][1]),Key13(arraylist[2][2]),Key14(arraylist[2][3]),Key15(arraylist[2][4]),Key16(arraylist[3][0]),Key17(arraylist[3][1]),Key18(arraylist[3][2]),Key19(arraylist[3][3]),Key20(arraylist[3][4]),Key21(arraylist[4][0]),Key22(arraylist[4][1]),Key23(arraylist[4][2]),Key24(arraylist[4][3]),Key25(arraylist[4][4]);
    
    std::thread t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
    
    t1 = std::thread(Lock, std::ref(Key1), std::ref(Key2), std::ref(Key3), std::ref(Key4), std::ref(Key5), 1);
    t2 = std::thread(Lock, std::ref(Key6), std::ref(Key7), std::ref(Key8), std::ref(Key9), std::ref(Key10), 2);
    t3 = std::thread(Lock, std::ref(Key11), std::ref(Key12), std::ref(Key13), std::ref(Key14), std::ref(Key15), 3);
    t4 = std::thread(Lock, std::ref(Key16), std::ref(Key17), std::ref(Key18), std::ref(Key19), std::ref(Key20), 4);
    t5 = std::thread(Lock, std::ref(Key21), std::ref(Key22), std::ref(Key23), std::ref(Key24), std::ref(Key25), 5);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    
    
    return 0;
}